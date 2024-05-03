#define DijetHistosFill_cxx
#include "../interface/DijetHistosFill.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

#include "TLorentzVector.h"
#include "TH2D.h"
#include "TProfile.h"
#include "TProfile2D.h"
#include "TStopwatch.h"

#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
// #include <utility>
#include <random>
#include <sstream>
#include <unordered_map>
#include <array>
#include <string_view>

#define PNET_REG

// Recalculate JECs
bool redoJEC = true;

// MC triggers (slow) or not (faster)
bool doMCtrigOnly = true;

// JER smearing (JER SF)
bool smearJets = true;
bool useJERSFvsPt = true; // new file format
int smearNMax = 3;
std::uint32_t _seed;
std::mt19937 _mersennetwister;

// Do PU reweighting
bool reweightPU = true;

// Activate modules
bool doJetveto = true; // eta-phi maps
bool doMCtruth = true;
bool doIncjet = true;   // inclusive jets
bool doDijet = true;    // dijet selection
bool doDijet2 = true;   // dijet selection (DESY style)
bool doMultijet = true; // multijet selection

// Core additions
bool doPFComposition = true; // jetveto / incjet / dijet / multijet
bool doDijetJER = true;


// Additional variants and controls
bool doJetvetoVariants = false;
bool doMultijetControl = true;
bool doMultijet2Drecoil = true;
bool doDijet2NM = false; // true;
bool doJetID = false;    // add JetID class

bool debug = false;      // general debug
bool debugevent = false; // per-event debug

// Maximum asymmetry of 2/3 corresponds to x2 ratio of tag and probe
// Permit ~0.7 extra scaling to allow for HF L3Res
const double maxa = 10; // no cut with 10

// List of MC IOVs
std::set<std::string> mcIOV = {"Summer22",
                               "Summer22Flat", "Summer22EE", "Summer22EEFlat",
                               "Summer23", "Summer23Flat", "Summer23MG",
                               "Summer23BPIXFlat", "Summer23BPIXMG", "2023BCv123",
                               "2023BCv123_ZB", "2023Cv4", "2023Cv4_ZB", "2023D", "2023D_ZB",
                               "Summer22MG", "Summer22EEMG", "Summer22MG1", "Summer22MG2",
                               "Summer22EEMG1", "Summer22EEMG2", "Summer22EEMG3", "Summer22EEMG4"};

// UTILITIES
double DELTAPHI(double phi1, double phi2)
{
  double dphi = fabs(phi1 - phi2);
  return (dphi <= TMath::Pi() ? dphi : TMath::TwoPi() - dphi);
}
double DELTAR(double phi1, double phi2, double eta1, double eta2)
{
  return sqrt(pow(DELTAPHI(phi1, phi2), 2) + pow(eta1 - eta2, 2));
}



constexpr const char lumibyls2022C[] = "luminosityscripts/csvfiles/lumibyls2022C.csv";
constexpr const char lumibyls2022D[] = "luminosityscripts/csvfiles/lumibyls2022D.csv";
constexpr const char lumibyls2022E[] = "luminosityscripts/csvfiles/lumibyls2022E.csv";
constexpr const char lumibyls2022F[] = "luminosityscripts/csvfiles/lumibyls2022F.csv";
constexpr const char lumibyls2022G[] = "luminosityscripts/csvfiles/lumibyls2022G.csv";
constexpr const char lumibyls2023B[] = "luminosityscripts/csvfiles/lumibyls2023AB.csv";
constexpr const char lumibyls2023C4[] = "luminosityscripts/csvfiles/lumibyls2023C4.csv";
constexpr const char lumibyls2023C123[] = "luminosityscripts/csvfiles/lumibyls2023C123.csv";
constexpr const char lumibyls2023ABC[] = "luminosityscripts/csvfiles/lumibyls2023ABC.csv";
constexpr const char lumibyls2023D[] = "luminosityscripts/csvfiles/lumibyls2023D.csv";

constexpr std::array<std::pair<const char*, const char*>, 19> lumifiles = {{
    {"2022C", lumibyls2022C},
    {"2022C_ZB", lumibyls2022C},
    {"2022D", lumibyls2022D},
    {"2022D_ZB", lumibyls2022D},
    {"2022E", lumibyls2022E},
    {"2022E_ZB", lumibyls2022E},
    {"2022F", lumibyls2022F},
    {"2022F_ZB", lumibyls2022F},
    {"2022G", lumibyls2022G},
    {"2022G_ZB", lumibyls2022G},
    {"2023B", lumibyls2023B},
    {"2023B_ZB", lumibyls2023B},
    {"2023Cv4", lumibyls2023C4},
    {"2023Cv4_ZB", lumibyls2023C4},
    {"2023Cv123", lumibyls2023C123},
    {"2023BCv123", lumibyls2023ABC},
    {"20223Cv123_ZB", lumibyls2023C123},
    {"2023D", lumibyls2023D},
    {"2023D_ZB", lumibyls2023D},
}}; // NOT CORRECT FOR 2023BCv123!!!! TEMP. FIX WHILE LUMI IS STILL NOT IN USE

constexpr const char *getLumifile(const char* dataset, std::size_t index = 0)
{
    if (index >= lumifiles.size())
        return nullptr; // Dataset not found

    if (std::strcmp(lumifiles[index].first, dataset) == 0)
        return lumifiles[index].second;

    return getLumifile(dataset, index + 1);
}



// Hardcoded pT, eta thresholds for each trigger
// used in e.g. jetvetoHistos
struct range
{
  double ptmin;
  double ptmax;
  double absetamin;
  double absetamax;
};
std::map<std::string, struct range> mt;

// CLASS DEFINITIONS
class mctruthHistos
{
public:
  TH2D *h2pteta, *h2pteta_gen, *h2pteta_rec;
  TProfile2D *p2jes, *p2jsf, *p2r, *p2effz, *p2eff, *p2pur;
};

class jetvetoHistos
{
public:
  // Basic information about the trigger
  string trg;
  int trgpt;
  double ptmin, ptmax, absetamin, absetamax;

  // Jet counts
  TH2D *h2pteta_all, *h2pteta_sel, *h2phieta;
  TH2D *h2ptaeta_all, *h2ptaeta_sel, *h2phieta_ave;
  TH2D *h2ptteta_all, *h2ptteta_sel, *h2phieta_tag;

  // Balancing
  TProfile2D *p2asymm;

  // (Optional) composition plots
  TProfile2D *p2chf, *p2nhf, *p2nef;
  TProfile2D *p2chftp, *p2nhftp, *p2neftp;
};

class incjetHistos
{
public:
  // Basic information about the trigger
  string trg;
  int trgpt;
  double ptmin, ptmax, absetamin, absetamax;

  static const int ny = 10;
  TH2D *h2pteta_all;
  TH2D *h2pteta_sel;
  TH2D *h2pteta;
  TH1D *hpt13;
  TH1D *vpt[ny];

  // Control plots for pileup
  TH2D *h2jtvht, *h2jtoht;

  // (Optional) composition plots
  TProfile2D *p2pt, *p2rho, *p2chf, *p2nef, *p2nhf, *p2cef, *p2muf;
  TProfile *ppt13, *prho13, *pchf13, *pnef13, *pnhf13, *pcef13, *pmuf13;
};

class dijetHistos
{
public:
  // Basic information about the trigger
  string trg;
  int trgpt;
  double ptmin, ptmax, absetamin, absetamax;

  TH2D *h2pteta_aball, *h2pteta_absel;
  TH2D *h2pteta_adall, *h2pteta_adsel;
  TH2D *h2pteta_tcall, *h2pteta_tcsel;
  TH2D *h2pteta_pfall, *h2pteta_pfsel;
  TProfile2D *p2resab, *p2resad, *p2restc, *p2respf; // JEC L2L3Res for undoing
  TProfile2D *p2m0, *p2m0x, *p2m2, *p2m2x;           // JER MPFX, DBX methods
  TProfile2D *p2m0ab, *p2m2ab, *p2mnab, *p2muab;     // pT,avp (bisector)
  TProfile2D *p2m0ad, *p2m2ad, *p2mnad, *p2muad;     // pT,ave (dijet axis)
  TProfile2D *p2m0tc, *p2m2tc, *p2mntc, *p2mutc;     // pT,tag (central)
  TProfile2D *p2m0pf, *p2m2pf, *p2mnpf, *p2mupf;     // pt,probe (forward)

  // (Optional) composition plots
  TProfile2D *p2pt, *p2rho, *p2chf, *p2nef, *p2nhf, *p2cef, *p2muf;      // probe,avp
  TProfile *ppt13, *prho13, *pchf13, *pnef13, *pnhf13, *pcef13, *pmuf13; // tag
};

class dijetHistos2
{
public:
  // Basic information about the trigger
  string trg;
  int trgpt;
  double ptmin, ptmax, absetamin, absetamax;

  TH2D *h2pteta;
  TProfile2D *p2res, *p2m0, *p2m2, *p2mn, *p2mu;
  TProfile2D *p2m0x, *p2m2x;

  // Extra for FSR studies
  TProfile2D *p2mnu, *p2mnx, *p2mux, *p2mnux;
  TH2D *h2ptetatc, *h2ptetapf;
  TProfile2D *p2restc, *p2m0tc, *p2m2tc, *p2mntc, *p2mutc; // pT,tag (central)
  TProfile2D *p2respf, *p2m0pf, *p2m2pf, *p2mnpf, *p2mupf; // pT,probe (forward)

  // Smearing controls
  TProfile2D *p2jsf, *p2jsftc, *p2jsfpf;
};

class multijetHistos
{
public:
  // Basic information about the trigger
  string trg;
  int trgpt;
  double ptmin, ptmax, absetamin, absetamax;

  TProfile *ptleada, *ptleadm, *ptleadl, *ptleadr;
  TProfile *pcrecoila, *pcrecoilm, *pcrecoill, *pcrecoilr;
  TH1D *hpta_all, *hptm_all, *hptl_all, *hptr_all;
  TH1D *hpta_sel, *hptm_sel, *hptl_sel, *hptr_sel;
  TProfile *presa, *presm, *presl, *presr;
  TProfile *pm0a, *pm2a, *pmna, *pmua; // *pmoa; // pT,avp3
  TProfile *pm0m, *pm2m, *pmnm, *pmum; // *pmom; // pT,ave
  TProfile *pm0l, *pm2l, *pmnl, *pmul; //*pmol; // pT,tag
  TProfile *pm0r, *pm2r, *pmnr, *pmur; // *pmor; // pT,probe

  // (Optional) 2D recoils
  TH2D *h2recoila, *h2recoilm, *h2recoill, *h2recoilr;

  // (Optional) composition plots
  TProfile *ppt13, *prho13, *pchf13, *pnef13, *pnhf13, *pcef13, *pmuf13; // lead pT,avp
  TProfile *ppt25, *prho25, *pchf25, *pnef25, *pnhf25, *pcef25, *pmuf25; // recoil,pT,avp

  // (Optional) Controls
  TH2D *h2m0a;
  TH2D *h2m2a;
  TH1D *hcosdphi;
};

class lumiHistos
{
public:
  string trg;
  int trgpt;
  float lumsum, lumsum2, lum, lum2; // lum is recorded, lum2 delivered
  TH1D *htrglumi, *htrgpu, *hnpv, *hnpvgood;
};


// Helper function to retrieve FactorizedJetCorrector
FactorizedJetCorrector *getFJC(string l1 = "", string l2 = "", string res = "",
                               string path = "")
{

  // Set default jet algo
  if (l1 != "" && !(TString(l1.c_str()).Contains("_AK")))
    l1 += "_AK4PFPuppi";
  if (l2 != "" && !(TString(l2.c_str()).Contains("_AK")))
    l2 += "_AK4PFPuppi";
  if (res != "" && !(TString(res.c_str()).Contains("_AK")))
    res += "_AK4PFPuppi";

  // Set default path
  if (path == "")
    path = "CondFormats/JetMETObjects/data";
  const char *cd = path.c_str();
  const char *cl1 = l1.c_str();
  const char *cl2 = l2.c_str();
  const char *cres = res.c_str();
  string s("");

  vector<JetCorrectorParameters> v;
  if (l1 != "")
  {
    s = Form("%s/%s.txt", cd, cl1);
    cout << s << endl
         << flush;
    JetCorrectorParameters *pl1 = new JetCorrectorParameters(s);
    v.push_back(*pl1);
  }
  if (l2 != "")
  {
    s = Form("%s/%s.txt", cd, cl2);
    cout << s << endl
         << flush;
    JetCorrectorParameters *pl2 = new JetCorrectorParameters(s);
    v.push_back(*pl2);
  }
  if (res != "")
  {
    s = Form("%s/%s.txt", cd, cres);
    cout << s << endl
         << flush;
    JetCorrectorParameters *pres = new JetCorrectorParameters(s);
    v.push_back(*pres);
  }
  FactorizedJetCorrector *jec = new FactorizedJetCorrector(v);

  return jec;
} // getFJC

void DijetHistosFill::Loop()
{
  //   In a ROOT session, you can do:
  //      root> .L DijetHistosFill.C
  //      root> DijetHistosFill t
  //      root> t.GetEntry(12); // Fill t data members with entry number 12
  //      root> t.Show();       // Show values of entry 12
  //      root> t.Show(16);     // Read and show values of entry 16
  //      root> t.Loop();       // Loop on all entries
  //

  //     This is the loop skeleton where:
  //    jentry is the global entry number in the chain
  //    ientry is the entry number in the current Tree
  //  Note that the argument to GetEntry must be:
  //    jentry for TChain::GetEntry
  //    ientry for TTree::GetEntry and TBranch::GetEntry
  //
  //       To read only selected branches, Insert statements like:
  // METHOD1:
  //    fChain->SetBranchStatus("*",0);  // disable all branches
  //    fChain->SetBranchStatus("branchname",1);  // activate branchname
  // METHOD2: replace line
  //    fChain->GetEntry(jentry);       //read all branches
  // by  b_branchname->GetEntry(ientry); //read only this branch
  if (fChain == 0)
    return;

  // ROOT.EnableImplicitMT(); // From Nico on Skype, to parallelize processing

  TStopwatch fulltime, laptime;
  fulltime.Start();
  TDatime bgn;
  TDatime start_time;
  start_time.Set();
  int nlap(0);

  fChain->SetBranchStatus("*", 0);

  // if (debug)
  cout << "Setting branch status for "
       << (isMC ? (isMG ? "MC (MG)" : "MC (Flat)") : (isZB ? "DATA (ZB)" : "DATA"))
       << " and " << (isRun2 ? "Run2" : "Run3")
       << " (isRun2=" << isRun2 << ", isRun3=" << isRun3 << ")"
       << endl
       << flush;

  if (isMC)
    fChain->SetBranchStatus("genWeight", 1);
  if (isMC)
    fChain->SetBranchStatus("Generator_binvar", 1); // pThat in Pythia8
  if (isMC && !(isMG && isRun3))
    fChain->SetBranchStatus("Pileup_pthatmax", 1);

  if (isMC && reweightPU)
  {
    fChain->SetBranchStatus("Pileup_nTrueInt", 1);
    fChain->SetBranchStatus("Pileup_nPU", 1);
  }

  if (isMC && (smearJets || doMCtruth))
  {
    cout << "Adding branches for GenJets ("
         << (smearJets ? " smearJets" : "")
         << (doMCtruth ? " doMCtruth" : "") << ")" << endl;
    fChain->SetBranchStatus("Jet_genJetIdx", 1);
    fChain->SetBranchStatus("nGenJet", 1);
    fChain->SetBranchStatus("GenJet_pt", 1);
    fChain->SetBranchStatus("GenJet_eta", 1);
    fChain->SetBranchStatus("GenJet_phi", 1);
    fChain->SetBranchStatus("GenJet_mass", 1);

    if (doMCtruth)
    {
      fChain->SetBranchStatus("GenVtx_z", 1);
      fChain->SetBranchStatus("PV_z", 1);
    }

    // At the value of _seed: the old question - should the seed of a rng be random itself?
    // Here we prefer stability, but the user can vary the seed if necessary. Moreover, https://xkcd.com/221/
    _seed = 4;
    _mersennetwister = std::mt19937(_seed);
  }

  if (isMG)
    fChain->SetBranchStatus("LHE_HT", 1); // HT in MadGraph

  fChain->SetBranchStatus("run", 1);
  fChain->SetBranchStatus("luminosityBlock", 1);
  fChain->SetBranchStatus("event", 1);
  // fChain->SetBranchStatus("Rho_fixedGridRhoAll",1);
  if (isRun2)
    fChain->SetBranchStatus("fixedGridRhoFastjetAll", 1);
  if (isRun3)
    fChain->SetBranchStatus("Rho_fixedGridRhoFastjetAll", 1);
  fChain->SetBranchStatus("L1_UnprefireableEvent", 1);

  // Listing of available triggers
  vector<string> vtrg = {
      "HLT_PFJet40",
      "HLT_PFJet60",
      "HLT_PFJet80",
      "HLT_PFJet140",
      "HLT_PFJet200",
      "HLT_PFJet260",
      "HLT_PFJet320",
      "HLT_PFJet400",
      "HLT_PFJet450",
      "HLT_PFJet500",
      "HLT_DiPFJetAve40",
      "HLT_DiPFJetAve60",
      "HLT_DiPFJetAve80",
      "HLT_DiPFJetAve140",
      "HLT_DiPFJetAve200",
      "HLT_DiPFJetAve260",
      "HLT_DiPFJetAve320",
      "HLT_DiPFJetAve400",
      "HLT_DiPFJetAve500",
      "HLT_DiPFJetAve60_HFJEC",
      "HLT_DiPFJetAve80_HFJEC",
      "HLT_DiPFJetAve100_HFJEC",
      "HLT_DiPFJetAve160_HFJEC",
      "HLT_DiPFJetAve220_HFJEC",
      "HLT_DiPFJetAve300_HFJEC"};

  if (isZB)
    vtrg.insert(vtrg.begin(), "HLT_ZeroBias");

  if (isRun2 > 2)
    vtrg.push_back("HLT_PFJet550");
  //}

  // vtrg.push_back("HLT_PFJetFwd15");
  // vtrg.push_back("HLT_PFJetFwd25");
  if (isRun2 > 2)
  { // && dataset!="UL2017B") {
    vtrg.push_back("HLT_PFJetFwd40");
    vtrg.push_back("HLT_PFJetFwd60");
    vtrg.push_back("HLT_PFJetFwd80");
    vtrg.push_back("HLT_PFJetFwd140");
    vtrg.push_back("HLT_PFJetFwd200");
    vtrg.push_back("HLT_PFJetFwd260");
    vtrg.push_back("HLT_PFJetFwd320");
    vtrg.push_back("HLT_PFJetFwd400");
    vtrg.push_back("HLT_PFJetFwd450");
    vtrg.push_back("HLT_PFJetFwd500");
  }

  if (doMCtrigOnly && isMC)
  {
    vtrg.clear();
    vtrg.push_back("HLT_MC");
  }
  if (isZB && !isMC)
  {
    vtrg.clear(); // no jet triggers from ZeroBias PD
    vtrg.push_back("HLT_ZeroBias");
  }

  int ntrg = vtrg.size();

  for (int i = 0; i != ntrg; ++i)
  {
    if (vtrg[i] != "HLT_MC")
      fChain->SetBranchStatus(vtrg[i].c_str(), 1);
    if (mtrg[vtrg[i]] == 0)
    {
      cout << "Missing branch info for " << vtrg[i] << endl
           << flush;
    }
    assert(mtrg[vtrg[i]] != 0);
  }

  fChain->SetBranchStatus("nJet", 1);
  fChain->SetBranchStatus("Jet_pt", 1);
  fChain->SetBranchStatus("Jet_eta", 1);
  fChain->SetBranchStatus("Jet_phi", 1);
  fChain->SetBranchStatus("Jet_mass", 1);
  fChain->SetBranchStatus("Jet_jetId", 1);

  fChain->SetBranchStatus("Jet_rawFactor", 1);

  #ifdef PNET_REG
  cout << "USING PNET REGRESSION" << endl;
  fChain->SetBranchStatus("Jet_PNetRegPtRawCorr", 1);
  fChain->SetBranchStatus("Jet_PNetRegPtRawCorrNeutrino", 1);
  #endif

  if (isRun2)
    fChain->SetBranchStatus("Jet_area", 1);

  // bool doPFComposition = true;
  if (doPFComposition)
  {
    fChain->SetBranchStatus("Jet_chHEF", 1);  // h+
    fChain->SetBranchStatus("Jet_neHEF", 1);  // h0
    fChain->SetBranchStatus("Jet_neEmEF", 1); // gamma
    fChain->SetBranchStatus("Jet_chEmEF", 1); // e
    fChain->SetBranchStatus("Jet_muEF", 1);   // mu
    // fChain->SetBranchStatus("Jet_hfEmEF",1); // HFe
    // fChain->SetBranchStatus("Jet_hfHEF",1);  // HFh
  }

  double Jet_l1rcFactor[nJetMax]; // For L1L2L3-RC type-I MET
  if (isRun2)
  {
    // raw chs PF MET
    fChain->SetBranchStatus("ChsMET_pt", 1);
    fChain->SetBranchStatus("ChsMET_phi", 1);
  }
  else
  {
    // fChain->SetBranchStatus("PuppiMET_pt",1);
    // fChain->SetBranchStatus("PuppiMET_phi",1);
    fChain->SetBranchStatus("RawPuppiMET_pt", 1);
    fChain->SetBranchStatus("RawPuppiMET_phi", 1);
  }

  fChain->SetBranchStatus("Flag_METFilters", 1);
  if (isRun3)
  {
    // https://twiki.cern.ch/twiki/bin/viewauth/CMS/MissingETOptionalFiltersRun2#Run_3_recommendations
    fChain->SetBranchStatus("Flag_goodVertices", 1);
    fChain->SetBranchStatus("Flag_globalSuperTightHalo2016Filter", 1);
    fChain->SetBranchStatus("Flag_EcalDeadCellTriggerPrimitiveFilter", 1);
    fChain->SetBranchStatus("Flag_BadPFMuonFilter", 1);
    fChain->SetBranchStatus("Flag_BadPFMuonDzFilter", 1);
    fChain->SetBranchStatus("Flag_hfNoisyHitsFilter", 1);
    fChain->SetBranchStatus("Flag_eeBadScFilter", 1);
    fChain->SetBranchStatus("Flag_ecalBadCalibFilter", 1);
  }

  // Trigger studies => TrigObjAK4 later (fixed now)
  bool doTriggerMatch = false;
  nTrigObjJMEAK4 = 0; // turn off
  if (doTriggerMatch)
  {
    // https://github.com/cms-sw/cmssw/blob/CMSSW_12_4_8/PhysicsTools/NanoAOD/python/triggerObjects_cff.py#L136-L180
    fChain->SetBranchStatus("nTrigObjJMEAK4", 1);
    fChain->SetBranchStatus("TrigObjJMEAK4_pt", 1);
    fChain->SetBranchStatus("TrigObjJMEAK4_eta", 1);
    fChain->SetBranchStatus("TrigObjJMEAK4_phi", 1);
  }

  // List reference pT and abseta thresholds for triggers
  mt["HLT_MC"] = range{10, 3000, 0, 5.2};
  mt["HLT_ZeroBias"] = range{10, 3000, 0, 5.2};

  mt["HLT_DiPFJetAve40"] = range{40, 85, 0, 5.2};
  mt["HLT_DiPFJetAve60"] = range{85, 100, 0, 5.2};
  mt["HLT_DiPFJetAve80"] = range{100, 155, 0, 5.2};
  mt["HLT_DiPFJetAve140"] = range{155, 210, 0, 5.2};
  mt["HLT_DiPFJetAve200"] = range{210, 300, 0, 5.2};
  mt["HLT_DiPFJetAve260"] = range{300, 400, 0, 5.2};
  mt["HLT_DiPFJetAve320"] = range{400, 500, 0, 5.2};
  mt["HLT_DiPFJetAve400"] = range{500, 600, 0, 5.2};
  mt["HLT_DiPFJetAve500"] = range{600, 6500, 0, 5.2};

  // 2.65, 2.853, 2.964, 3.139, 3.314, 3.489, 3.664, 3.839, 4.013, 4.191,
  double fwdeta = 3.139;  // was 2.853. 80% (100%) on negative (positive) side
  double fwdeta0 = 2.964; // 2.853; // 40 and 260 up
  mt["HLT_DiPFJetAve60_HFJEC"] = range{85, 100, fwdeta, 5.2};
  mt["HLT_DiPFJetAve80_HFJEC"] = range{100, 125, fwdeta, 5.2};
  mt["HLT_DiPFJetAve100_HFJEC"] = range{125, 180, fwdeta, 5.2};
  mt["HLT_DiPFJetAve160_HFJEC"] = range{180, 250, fwdeta, 5.2};
  mt["HLT_DiPFJetAve220_HFJEC"] = range{250, 350, fwdeta0, 5.2};
  mt["HLT_DiPFJetAve300_HFJEC"] = range{350, 6500, fwdeta0, 5.2};

  mt["HLT_PFJet40"] = range{40, 85, 0, 5.2};
  mt["HLT_PFJet60"] = range{85, 100, 0, 5.2};
  mt["HLT_PFJet80"] = range{100, 155, 0, 5.2};
  mt["HLT_PFJet140"] = range{155, 210, 0, 5.2};
  mt["HLT_PFJet200"] = range{210, 300, 0, 5.2};
  mt["HLT_PFJet260"] = range{300, 400, 0, 5.2};
  mt["HLT_PFJet320"] = range{400, 500, 0, 5.2};
  mt["HLT_PFJet400"] = range{500, 600, 0, 5.2};
  mt["HLT_PFJet450"] = range{500, 600, 0, 5.2};
  mt["HLT_PFJet500"] = range{600, 6500, 0, 5.2};
  mt["HLT_PFJet550"] = range{700, 6500, 0, 5.2};

  mt["HLT_PFJetFwd40"] = range{40, 85, fwdeta0, 5.2};
  mt["HLT_PFJetFwd60"] = range{85, 100, fwdeta, 5.2};
  mt["HLT_PFJetFwd80"] = range{100, 155, fwdeta, 5.2};
  mt["HLT_PFJetFwd140"] = range{155, 210, fwdeta, 5.2};
  mt["HLT_PFJetFwd200"] = range{210, 300, fwdeta0, 5.2};
  mt["HLT_PFJetFwd260"] = range{300, 400, fwdeta0, 5.2};
  mt["HLT_PFJetFwd320"] = range{400, 500, fwdeta0, 5.2};
  mt["HLT_PFJetFwd400"] = range{500, 600, fwdeta0, 5.2};
  mt["HLT_PFJetFwd450"] = range{500, 600, fwdeta0, 5.2}; // x
  mt["HLT_PFJetFwd500"] = range{600, 6500, fwdeta0, 5.2};



  if (debug)
    cout << "Setting up JEC corrector" << endl
         << flush;

  // Redo JEC
  // NB: could implement time dependence as in jetphys/IOV.h
  FactorizedJetCorrector *jec(0), *jecl1rc(0), *jersfvspt(0);
  string jerpath(""), jerpathsf("");
  // jec = getFJC("","Winter22Run3_V1_MC_L2Relative","","");
  // if (isRun2==0) {
  // jec = getFJC("","Winter22Run3_V1_MC_L2Relative",
  //		  isMC ? "":"Winter22Run3_RunC_V2_DATA_L2L3Residual_AK4PFPuppi");
  // }
  //  2016APV (BCD, EF)

  TH1D *pileupRatio = new TH1D("puRatio", "PURatio;;Ratio", 99, 0, 100);

  if (dataset == "UL2016APVMG")
  {
    jec = getFJC("Summer19UL16APV_V7_MC_L1FastJet_AK4PFchs",
                 "Summer19UL16APV_V7_MC_L2Relative_AK4PFchs", "");
    jecl1rc = getFJC("Summer19UL16APV_V7_MC_L1RC_AK4PFchs", "", "");
    jerpath = "JRDatabase/textFiles/Summer20UL16APV_JRV3_MC/Summer20UL16APV_JRV3_MC_PtResolution_AK4PFchs.txt";
    jerpathsf = "JRDatabase/textFiles/Summer20UL16APV_JRV3_MC/Summer20UL16APV_JRV3_MC_SF_AK4PFchs.txt";
    jersfvspt = getFJC("", "Summer20UL2016APV_ZB_v26c_JRV3_MC_SF_AK4PFchs", "");
  }
  if (dataset == "UL2016BCD" || dataset == "UL2016BCD_ZB")
  {
    jec = getFJC("Summer19UL16APV_RunBCD_V7_DATA_L1FastJet_AK4PFchs",
                 "Summer19UL16APV_RunBCD_V7_DATA_L2Relative_AK4PFchs",
                 "Summer19UL16APV_RunBCD_V7_DATA_L2L3Residual_AK4PFchs");
    jecl1rc = getFJC("Summer19UL16APV_RunBCD_V7_DATA_L1RC_AK4PFchs", "", "");
  }
  if (dataset == "UL2016EF" || dataset == "UL2016EF_ZB")
  {
    jec = getFJC("Summer19UL16APV_RunEF_V7_DATA_L1FastJet_AK4PFchs",
                 "Summer19UL16APV_RunEF_V7_DATA_L2Relative_AK4PFchs",
                 "Summer19UL16APV_RunEF_V7_DATA_L2L3Residual_AK4PFchs");
    jecl1rc = getFJC("Summer19UL16APV_RunEF_V7_DATA_L1RC_AK4PFchs", "", "");
  }
  // 2016 non-APV (GH)
  if (dataset == "UL2016MG" || dataset == "UL2016Flat")
  {
    jec = getFJC("Summer19UL16_V7_MC_L1FastJet_AK4PFchs",
                 "Summer19UL16_V7_MC_L2Relative_AK4PFchs", "");
    jecl1rc = getFJC("Summer19UL16_V7_MC_L1RC_AK4PFchs", "", "");
    // jec = getFJC("Summer20UL16_V1_MC_L1FastJet_AK4PFchs",
    //		  "Summer20UL16_V1_MC_L2Relative_AK4PFchs","");
    // jecl1rc = getFJC("Summer20UL16_V1_MC_L1RC_AK4PFchs","","");
    jerpath = "JRDatabase/textFiles/Summer20UL16_JRV3_MC/Summer20UL16_JRV3_MC_PtResolution_AK4PFchs.txt";
    jerpathsf = "JRDatabase/textFiles/Summer20UL16_JRV3_MC/Summer20UL16_JRV3_MC_SF_AK4PFchs.txt";
    jersfvspt = getFJC("", "Summer20UL2016GH_ZB_v26c_JRV3_MC_SF_AK4PFchs", "");
  }
  if (dataset == "UL2016GH" || dataset == "UL2016GH_ZB")
  {
    jec = getFJC("Summer19UL16_RunFGH_V7_DATA_L1FastJet_AK4PFchs",
                 "Summer19UL16_RunFGH_V7_DATA_L2Relative_AK4PFchs",
                 "Summer19UL16_RunFGH_V7_DATA_L2L3Residual_AK4PFchs");
    jecl1rc = getFJC("Summer19UL16_RunFGH_V7_DATA_L1RC_AK4PFchs", "", "");
    // jec = getFJC("Summer20UL16_RunGH_V1_DATA_L1FastJet_AK4PFchs",
    //"Summer20UL16_RunGH_V1_DATA_L2Relative_AK4PFchs",
    //"Summer20UL16_RunGH_V1_DATA_L2L3Residual_AK4PFchs");
    //"Summer19UL16_RunFGH_V7_DATA_L2L3Residual_AK4PFchs");
    // jecl1rc = getFJC("Summer20UL16_RunGH_V1_DATA_L1RC_AK4PFchs","","");
  }
  // 2017
  if (dataset == "UL2017MG")
  {
    jec = getFJC("Summer19UL17_V6_MC_L1FastJet_AK4PFchs",
                 "Summer19UL17_V6_MC_L2Relative_AK4PFchs", "");
    jecl1rc = getFJC("Summer19UL17_V6_MC_L1RC_AK4PFchs", "", "");
    jerpath = "JRDatabase/textFiles/Summer19UL17_JRV3_MC/Summer19UL17_JRV3_MC_PtResolution_AK4PFchs.txt";
    jerpathsf = "JRDatabase/textFiles/Summer19UL17_JRV3_MC/Summer19UL17_JRV3_MC_SF_AK4PFchs.txt";
    jersfvspt = getFJC("", "Summer20UL2017_ZB_v26c_JRV3_MC_SF_AK4PFchs", "");
  }
  if (dataset == "UL2017B" || dataset == "UL2017B_ZB")
  {
    jec = getFJC("Summer19UL17_RunB_V6_DATA_L1FastJet_AK4PFchs",
                 "Summer19UL17_RunB_V6_DATA_L2Relative_AK4PFchs",
                 "Summer19UL17_RunB_V6_DATA_L2L3Residual_AK4PFchs");
    jecl1rc = getFJC("Summer19UL17_RunB_V6_DATA_L1RC_AK4PFchs", "", "");
  }
  if (dataset == "UL2017C" || dataset == "UL2017C_ZB")
  {
    jec = getFJC("Summer19UL17_RunC_V6_DATA_L1FastJet_AK4PFchs",
                 "Summer19UL17_RunC_V6_DATA_L2Relative_AK4PFchs",
                 "Summer19UL17_RunC_V6_DATA_L2L3Residual_AK4PFchs");
    jecl1rc = getFJC("Summer19UL17_RunC_V6_DATA_L1RC_AK4PFchs", "", "");
  }
  if (dataset == "UL2017D" || dataset == "UL2017D_ZB")
  {
    jec = getFJC("Summer19UL17_RunD_V6_DATA_L1FastJet_AK4PFchs",
                 "Summer19UL17_RunD_V6_DATA_L2Relative_AK4PFchs",
                 "Summer19UL17_RunD_V6_DATA_L2L3Residual_AK4PFchs");
    jecl1rc = getFJC("Summer19UL17_RunD_V6_DATA_L1RC_AK4PFchs", "", "");
  }
  if (dataset == "UL2017E" || dataset == "UL2017E_ZB")
  {
    jec = getFJC("Summer19UL17_RunE_V6_DATA_L1FastJet_AK4PFchs",
                 "Summer19UL17_RunE_V6_DATA_L2Relative_AK4PFchs",
                 "Summer19UL17_RunE_V6_DATA_L2L3Residual_AK4PFchs");
    jecl1rc = getFJC("Summer19UL17_RunE_V6_DATA_L1RC_AK4PFchs", "", "");
  }
  if (dataset == "UL2017F" || dataset == "UL2017F_ZB")
  {
    jec = getFJC("Summer19UL17_RunF_V6_DATA_L1FastJet_AK4PFchs",
                 "Summer19UL17_RunF_V6_DATA_L2Relative_AK4PFchs",
                 "Summer19UL17_RunF_V6_DATA_L2L3Residual_AK4PFchs");
    jecl1rc = getFJC("Summer19UL17_RunF_V6_DATA_L1RC_AK4PFchs", "", "");
  }
  // 2018
  if (dataset == "UL2018MG")
  {
    jec = getFJC("Summer19UL18_V5_MC_L1FastJet_AK4PFchs",
                 "Summer19UL18_V5_MC_L2Relative_AK4PFchs", "");
    jecl1rc = getFJC("Summer19UL18_V5_MC_L1RC_AK4PFchs", "", "");
    jerpath = "JRDatabase/textFiles/Summer19UL18_JRV2_MC/Summer19UL18_JRV2_MC_PtResolution_AK4PFchs.txt";
    jerpathsf = "JRDatabase/textFiles/Summer19UL18_JRV2_MC/Summer19UL18_JRV2_MC_SF_AK4PFchs.txt";
    jersfvspt = getFJC("", "Summer20UL2018_ZB_v26c_JRV3_MC_SF_AK4PFchs", "");
  }
  if (dataset == "UL2018A" || dataset == "UL2018A_ZB")
  {
    jec = getFJC("Summer19UL18_RunA_V5_DATA_L1FastJet_AK4PFchs",
                 "Summer19UL18_RunA_V5_DATA_L2Relative_AK4PFchs",
                 "Summer19UL18_RunA_V5_DATA_L2L3Residual_AK4PFchs");
    jecl1rc = getFJC("Summer19UL18_RunA_V5_DATA_L1RC_AK4PFchs", "", "");
  }
  if (dataset == "UL2018B" || dataset == "UL2018B_ZB")
  {
    jec = getFJC("Summer19UL18_RunB_V5_DATA_L1FastJet_AK4PFchs",
                 "Summer19UL18_RunB_V5_DATA_L2Relative_AK4PFchs",
                 "Summer19UL18_RunB_V5_DATA_L2L3Residual_AK4PFchs");
    jecl1rc = getFJC("Summer19UL18_RunB_V5_DATA_L1RC_AK4PFchs", "", "");
  }
  if (dataset == "UL2018C" || dataset == "UL2018C_ZB")
  {
    jec = getFJC("Summer19UL18_RunC_V5_DATA_L1FastJet_AK4PFchs",
                 "Summer19UL18_RunC_V5_DATA_L2Relative_AK4PFchs",
                 "Summer19UL18_RunC_V5_DATA_L2L3Residual_AK4PFchs");
    jecl1rc = getFJC("Summer19UL18_RunC_V5_DATA_L1RC_AK4PFchs", "", "");
  }
  if (dataset == "UL2018D" || dataset == "UL2018D_ZB" ||
      dataset == "UL2018D1" || dataset == "UL2018D2")
  {
    jec = getFJC("Summer19UL18_RunD_V5_DATA_L1FastJet_AK4PFchs",
                 "Summer19UL18_RunD_V5_DATA_L2Relative_AK4PFchs",
                 "Summer19UL18_RunD_V5_DATA_L2L3Residual_AK4PFchs");
    jecl1rc = getFJC("Summer19UL18_RunD_V5_DATA_L1RC_AK4PFchs", "", "");
  }

  // 2022
  //  Align JECs with
  //  https://indico.cern.ch/event/1335203/#7-update-on-l2res-for-2022-rer
  if (dataset == "2022C" || dataset == "2022C_ZB")
  {
    jec = getFJC("",                                       // Winter22Run3_RunC_V2_DATA_L1FastJet_AK4PFPuppi",
                                                           //"Winter22Run3_RunC_V2_DATA_L2Relative_AK4PFPuppi",
                 "Summer22Run3_V1_MC_L2Relative_AK4PUPPI", // Mikel
                                                           // v33 and prev "Summer22_RunCD_V2_MPF_L2Residual_AK4PFPuppi");
                 // "Run22CD-22Sep2023_DATA_L2L3Residual_AK4PFPuppi"
                 "Summer22-22Sep2023_Run2022CD_V3_DATA_L2L3Residual_AK4PFPuppi");
    //"");//"Winter22Run3_RunC_V2_DATA_L2L3Residual_AK4PFPuppi");
  }
  if (dataset == "2022D" || dataset == "2022D_ZB")
  {
    jec = getFJC("",                                       // Winter22Run3_RunD_V2_DATA_L1FastJet_AK4PFPuppi",
                                                           //"Winter22Run3_RunD_V2_DATA_L2Relative_AK4PFPuppi",
                 "Summer22Run3_V1_MC_L2Relative_AK4PUPPI", // Mikel
                                                           // v33 and prev "Summer22_RunCD_V2_MPF_L2Residual_AK4PFPuppi");
                 //"Run22CD-22Sep2023_DATA_L2L3Residual_AK4PFPuppi"
                 "Summer22-22Sep2023_Run2022CD_V3_DATA_L2L3Residual_AK4PFPuppi");
    //"");//"Winter22Run3_RunD_V2_DATA_L2L3Residual_AK4PFPuppi");
  }
  if (dataset == "2022E" || dataset == "2022E_ZB")
  {
    jec = getFJC("",                                             // Summer22EEPrompt22_RunF_V1_DATA_L1FastJet_AK4PFPuppi",
                                                                 //"Summer22EEPrompt22_RunF_V1_DATA_L2Relative_AK4PFPuppi",
                 "Summer22EEVetoRun3_V1_MC_L2Relative_AK4PUPPI", // Mikel
                                                                 // v33 and prev "Summer22EE_RunE_V2_MPF_L2Residual_AK4PFPuppi");
                 // "Run22E-22Sep2023_DATA_L2L3Residual_AK4PFPuppi"
                 "Summer22EE-22Sep2023_Run2022E_V3_DATA_L2L3Residual_AK4PFPuppi");
    //"Summer22EEPrompt22_RunE_V2_L2Residual_AK4PFPuppi");
    //"");//"Summer22EEPrompt22_RunF_V1_DATA_L2L3Residual_AK4PFPuppi");
  }
  // if (dataset=="2022F" || dataset=="2022F_ZB") {
  if (TString(dataset.c_str()).Contains("2022F"))
  {
    jec = getFJC("",                                             // Summer22EEPrompt22_RunF_V1_DATA_L1FastJet_AK4PFPuppi",
                                                                 //"Summer22EEPrompt22_RunF_V1_DATA_L2Relative_AK4PFPuppi",
                 "Summer22EEVetoRun3_V1_MC_L2Relative_AK4PUPPI", // Mikel
                                                                 //"Summer22EEPrompt22_RunF_V2_L2Residual_AK4PFPuppi"
                 // "Run22F-Prompt_DATA_L2L3Residual_AK4PFPuppi"
                 "Summer22EEPrompt22_Run2022F_V3_DATA_L2L3Residual_AK4PFPuppi");
    //"");//"Summer22EEPrompt22_RunF_V1_DATA_L2L3Residual_AK4PFPuppi");
  }
  if (dataset == "2022G" || dataset == "2022G_ZB")
  {
    jec = getFJC("",                                             // Summer22EEPrompt22_RunG_V1_DATA_L1FastJet_AK4PFPuppi",
                                                                 //"Summer22EEPrompt22_RunG_V1_DATA_L2Relative_AK4PFPuppi",
                 "Summer22EEVetoRun3_V1_MC_L2Relative_AK4PUPPI", // Mikel
                                                                 // "Summer22EEPrompt22_RunG_V2_L2Residual_AK4PFPuppi"
                 // "Run22G-Prompt_DATA_L2L3Residual_AK4PFPuppi"
                 "Summer22EEPrompt22_Run2022G_V3_DATA_L2L3Residual_AK4PFPuppi");
    //"");//"Summer22EEPrompt22_RunG_V1_DATA_L2L3Residual_AK4PFPuppi");
  }

  // 22/23 MC
  if (dataset == "Summer22" ||
      dataset == "Summer22Flat" ||
      TString(dataset.c_str()).Contains("Summer22MG"))
  {
    jec = getFJC("",                                       // Winter22Run3_V2_MC_L1FastJet_AK4PFPuppi",
                                                           //"Winter22Run3_V2_MC_L2Relative_AK4PFPuppi",
                 "Summer22Run3_V1_MC_L2Relative_AK4PUPPI", // Mikel
                 "");                                      // Winter22Run3_V2_MC_L2L3Residual_AK4PFPuppi");
    jerpath = "CondFormats/JetMETObjects/data/Summer22_V1_NSCP_MC_PtResolution_ak4puppi.txt";
    jerpathsf = "CondFormats/JetMETObjects/data/Summer22EERun3_V1_MC_SF_AK4PFPuppi.txt"; // Same as Summer22EE, is ok
    useJERSFvsPt = false;
  }
  if (dataset == "Summer22EE" ||
      dataset == "Summer22EEFlat" ||
      TString(dataset.c_str()).Contains("Summer22EEMG"))
  {
    jec = getFJC("",                                             // Summer22EEPrompt22_V1_MC_L1FastJet_AK4PFPuppi",
                                                                 //"Summer22EEPrompt22_V1_MC_L2Relative_AK4PFPuppi",
                 "Summer22EEVetoRun3_V1_MC_L2Relative_AK4PUPPI", // Mikel
                 "");                                            // Summer22EEPrompt22_V1_MC_L2L3Residual_AK4PFPuppi");
    jerpath = "CondFormats/JetMETObjects/data/Summer22EEVetoRun3_V1_NSCP_MC_PtResolution_ak4puppi.txt";
    jerpathsf = "CondFormats/JetMETObjects/data/Summer22EERun3_V1_MC_SF_AK4PFPuppi.txt";
    useJERSFvsPt = false;
  }
  if (dataset == "Summer23" ||
      dataset == "Summer23Flat" || dataset == "Summer23MG" ||
      dataset == "Summer23BPIXFlat" || dataset == "Summer23BPIXMG" || TString(dataset.c_str()).Contains("Summer23"))
  {
    if (TString(dataset.c_str()).Contains("Summer23MGBPix")) {
      jec = getFJC("",
                  "Summer23BPixRun3_V3_MC_L2Relative_AK4PUPPI",
                  "");
    } else {
      jec = getFJC("",
                  "Summer23Run3_V1_MC_L2Relative_AK4PUPPI",
                  "");
    }
    //jec = getFJC("", // Winter23Prompt23_V2_MC_L1FastJet_AK4PFPuppi",
    //             "Winter23Prompt23_V2_MC_L2Relative_AK4PFPuppi",
    //             "");                                                                                   // Winter23Prompt23_V2_MC_L2L3Residual_AK4PFPuppi");
    jerpath = "CondFormats/JetMETObjects/data/Summer22EEVetoRun3_V1_NSCP_MC_PtResolution_ak4puppi.txt"; // Same as Summer22EE, until updated
    jerpathsf = "CondFormats/JetMETObjects/data/Summer22EERun3_V1_MC_SF_AK4PFPuppi.txt";                // Same as Summer22EE, until updated
    useJERSFvsPt = false;

    if (reweightPU)
    {
      if (TString(dataset.c_str()).Contains("Summer23MGBPix")) {
        TFile f("luminosityscripts/PUWeights/Summer23BPix_PUWeight.root");
        pileupRatio = (TH1D *)f.Get("pileup");
        pileupRatio->SetDirectory(0);
        // Print mean, min weight, max weight
        cout << "Pileup ratio mean = " << pileupRatio->GetMean() << endl;
        cout << "Pileup ratio min = " << pileupRatio->GetMinimum() << endl;
        cout << "Pileup ratio max = " << pileupRatio->GetMaximum() << endl;

      } else {
        TFile f("luminosityscripts/PUWeights/Summer23_PUWeight.root");
        pileupRatio = (TH1D *)f.Get("pileup");
        pileupRatio->SetDirectory(0);
        // Print mean, min weight, max weight
        cout << "Pileup ratio mean = " << pileupRatio->GetMean() << endl;
        cout << "Pileup ratio min = " << pileupRatio->GetMinimum() << endl;
        cout << "Pileup ratio max = " << pileupRatio->GetMaximum() << endl;

      }
    }
  }

  // 2023
  // if (dataset=="2023B" || dataset=="2023B_ZB") {
  // jec = getFJC("Winter23Prompt23_RunC_V2_DATA_L1FastJet_AK4PFPuppi",
  //		  "Winter23Prompt23_RunC_V2_DATA_L2Relative_AK4PFPuppi",
  //		  "Winter23Prompt23_RunC_V2_DATA_L2L3Residual_AK4PFPuppi");
  // }

  if (dataset == "2023B" || dataset == "2023B_ZB" || dataset == "2023BCv123" ||
      dataset == "2023BCv123_ZB" || dataset == "2023Cv123" || dataset == "2023Cv123_ZB")
  {
    jec = getFJC("",                                                               // Winter23Prompt23_RunC_V2_DATA_L1FastJet_AK4PFPuppi",
                                                                                   //"Winter23Prompt23_RunC_V2_DATA_L2Relative_AK4PFPuppi",
                 "Summer23Run3_V1_MC_L2Relative_AK4PUPPI",                         // Mikel
                                                                                   // "Run23C123-Prompt_DATA_L2L3Residual_AK4PFPuppi"
                 "Summer23Prompt23_Run2023Cv123_V1_DATA_L2L3Residual_AK4PFPuppi"); //"Winter23Prompt23_RunC_V2_DATA_L2L3Residual_AK4PFPuppi");
  }

  if (dataset == "2023Cv4" || dataset == "2023Cv4_ZB")
  {
    jec = getFJC("",                                                             // Winter23Prompt23_RunC_V2_DATA_L1FastJet_AK4PFPuppi",
                                                                                 //"Winter23Prompt23_RunC_V2_DATA_L2Relative_AK4PFPuppi",
                 "Summer23Run3_V1_MC_L2Relative_AK4PUPPI",                       // Mikel
                                                                                 //"Run23C4-Prompt_DATA_L2L3Residual_AK4PFPuppi"
                 "Summer23Prompt23_Run2023Cv4_V1_DATA_L2L3Residual_AK4PFPuppi"); //"Winter23Prompt23_RunC_V2_DATA_L2L3Residual_AK4PFPuppi");
  }

  if (dataset == "2023D" || dataset == "2023D_ZB")
  {
    jec = getFJC("",                                                           // Winter23Prompt23_RunC_V2_DATA_L1FastJet_AK4PFPuppi",
                                                                               //"Winter23Prompt23_RunC_V2_DATA_L2Relative_AK4PFPuppi",
                 "Summer23BPixRun3_V3_MC_L2Relative_AK4PUPPI",                     // Mikel
                                                                               //"Run23D-Prompt_DATA_L2L3Residual_AK4PFPuppi"
                 "Summer23Prompt23_Run2023D_V1_DATA_L2L3Residual_AK4PFPuppi"); //"Winter23Prompt23_RunC_V2_DATA_L2L3Residual_AK4PFPuppi");
  }

  if ((isRun2 && (!jec || !jecl1rc)) || (isRun3 && !jec))
    cout << "Missing files for " << dataset << endl
         << flush;
  assert(jec);
  // assert(jecl1rc);

  if (debug)
    cout << "Setting up JER smearing" << endl
         << flush;

  // Smear JER
  // NB: could implement time dependence as in jetphys/IOV.h
  JME::JetResolution *jer(0);
  JME::JetResolutionScaleFactor *jersf(0);
  if (isMC && smearJets)
  {
    cout << jerpath << endl
         << flush;
    if (!useJERSFvsPt)
      cout << jerpathsf << endl
           << flush;
    if (jerpath == "" || (jerpathsf == "" && !useJERSFvsPt))
      cout << "Missing JER file paths for " << dataset << endl
           << flush;
    assert(jerpath != "");
    assert(jerpathsf != "" || useJERSFvsPt);
    assert(jersfvspt || !useJERSFvsPt);
    jer = new JME::JetResolution(jerpath.c_str());
    if (!useJERSFvsPt)
      jersf = new JME::JetResolutionScaleFactor(jerpathsf.c_str());
    if (!jer || (!jersf && !useJERSFvsPt) || (!jersfvspt && useJERSFvsPt))
      cout << "Missing JER files for " << dataset << endl
           << flush;
  }

  TLorentzVector p4rawmet, p4t1met, p4mht, p4l1rc, p4dj;
  // TLorentzVector p4, p4s, p4mht, p4mht2, p4mhtc, p4mhtc3, p4t, p4p;
  TLorentzVector p4, /*p4raw,*/ p4g, p4s, p4t, p4p;
  TLorentzVector p4lead, p4recoil; //, p4other;
  TLorentzVector p4leadRES, p4recoilRES;
  TLorentzVector p4b3, p4b3r, p4b3l, p4m;
  TLorentzVector p4b, p4bt, p4bp, p4bx, p4d, p4dx;
  TLorentzVector p4c, p4cx, p4f, p4fx, p4l, p4r;
  TLorentzVector p4m0, p4m2, p4mn, p4mu; //, p4mo;
  TLorentzVector p4m3, p4mn3, p4mu3;
  TLorentzVector p4corrjets, p4rcjets, p4rawjets;
  TFile *fout = new TFile(Form("rootfiles/%s/jmenano_%s_out_%s_%s.root",
                               version.c_str(),
                               isMC ? "mc" : "data",
                               dataset.c_str(), version.c_str()),
                          "RECREATE");

  // Monitor trigger rates
  TH1D *htrg = new TH1D("htrg", "Triggers;Trigger;N_{events}",
                        vtrg.size(), 0, vtrg.size());
  for (int i = 1; i != htrg->GetNbinsX() + 1; ++i)
  {
    htrg->GetXaxis()->SetBinLabel(i, vtrg[i - 1].c_str());
  }

  // trigger vs lumi
  TH2D *h_trgvslumi = new TH2D("h_trgvslumi", "Triggers;Trigger;Lumi",
                        vtrg.size(), 0, vtrg.size(), 100, 0, 1);
  for (int i = 1; i != h_trgvslumi->GetNbinsX() + 1; ++i)
  {
    h_trgvslumi->GetXaxis()->SetBinLabel(i, vtrg[i - 1].c_str());
  }

  // trigger vs pu
  TH2D *h_trgvspu = new TH2D("h_trgvspu", "Triggers;Trigger;PU",
                        vtrg.size(), 0, vtrg.size(), 100, 0, 100);
  for (int i = 1; i != h_trgvspu->GetNbinsX() + 1; ++i)
  {
    h_trgvspu->GetXaxis()->SetBinLabel(i, vtrg[i - 1].c_str());
  }

  if (debug)
    cout << "Setting up histograms" << endl
         << flush;

  // Setup HT bin weighting and monitoring
  TH1D *hxsec(0), *hnevt(0), *hnwgt(0), *hLHE_HT(0), *hLHE_HTw(0), *hHT(0), *hHT_Now(0), *hHT_MCw(0), *hHT_w(0);
  double vht2[] = {0, 25, 50, 100, 200, 300, 500, 700, 1000, 1500, 2000, 13800};
  const int nht2 = sizeof(vht2) / sizeof(vht2[0]) - 1;
  double vht3[] = {0, 40, 70, 100, 200, 400, 600, 800, 1000, 1200, 1500, 2000,
                   13800};
  const int nht3 = sizeof(vht3) / sizeof(vht3[0]) - 1;
  const double *vht = (isRun3 ? &vht3[0] : &vht2[0]);
  const int nht = (isRun3 ? nht3 : nht2);
  int nMG(0), sumwMG(0);
  if (isMG)
  {

    hxsec = new TH1D("hxsec", ";H_{T} (GeV);pb", nht, vht);
    hnevt = new TH1D("hnevt", ";H_{T} (GeV);N_{evt}", nht, vht);
    hnwgt = new TH1D("hnwgt", ";H_{T} (GeV);Sum of weights", nht, vht);
    hLHE_HT = new TH1D("hLHE_HT", ";H_{T} (GeV);N_{evt} (unweighted)", nht, vht);
    hLHE_HTw = new TH1D("hLHE_HTw", ";H_{T} (GeV);N_{evt} (weighted)", nht, vht);
    hHT = new TH1D("hHT", ";H_{T} (GeV);N_{evt} (weighted)", 2490, 10, 2500);
    hHT_Now = new TH1D("hHT_Now", ";H_{T} (GeV);N_{evt} (unweighted)", 2490, 10, 2500);
    hHT_MCw = new TH1D("hHT_MCw", ";H_{T} (GeV);N_{evt} (MC weight event)", 2490, 10, 2500);
    hHT_w = new TH1D("hHT_w", ";genWeight;N_{evt} (genWeight)", 2490, 10, 2500);

    // Reference number of events, retrieved manually with
    // TChain c("Events"); c.AddFile("<path to files>/*.root"); c.GetEntries();
    // Also re-calculated this code before event loop when needed
    int vnevt2[nht2] = {0, 0, 11197186, 23002929, 17512439, 16405924, 14359110,
                        13473185, 4365993, 2944561, 1836165};
    // int vnevt3[nht3] = {0, 9929, 26573, 16411, 10495, 8260, 7929, 10082, 14390, 6548, 6250}; // Summer22MG, local files
    int vnevt3[nht3] = {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}; // Summer22MG, local files
    int vnwgt3[nht3] = {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}; // Summer22MG, local files
    const int *vnevt = (isRun3 ? &vnevt3[0] : &vnevt2[0]);
    const int *vnwgt = (isRun3 ? &vnwgt3[0] : &vnevt2[0]);
    for (int i = 0; i != nht; ++i)
    {
      hnevt->SetBinContent(i + 1, vnevt[i]);
      hnwgt->SetBinContent(i + 1, vnwgt[i]);
      nMG += vnevt[i];
      sumwMG += vnwgt[i];
    }
    cout << "Loaded Hefaistos MadGraph event numbers ("
         << nMG << ")" << endl
         << flush;

    // xsec from jetphys/settings.h_template
    double vxsec2[nht2] = {0, 0, 246300000. * 23700000. / 28060000., 23700000,
                           1547000, 322600, 29980, 6334, 1088, 99.11, 20.23};
    // Run3 xsec from Mikel Mendizabal, MatterMost 16 Oct 2023
    // SUMMER22
    //double vxsec3[nht3] =
    //    {0, 3.136e+08,
    //     5.883e+07, // 5.807e+07 * 3478241.4 / 5305581.5, // HT 70to100
    //     2.520e+07, 1.936e+06, 9.728e+04,
    //     1.323e+04, // 3.044e+04, //HT 60to800
    //     3.027e+03, 8.883e+02, 3.834e+02, 1.253e+02, 2.629e+01};

    // SUMMER23, Fikri MatterMost 22.2.2024
    double vxsec3[nht3] =
        {0, 3.131e+08,
         5.892e+07,
         2.532e+07, 1.964e+06, 9.690e+04,
         1.360e+04,
         3.052e+03, 8.929e+02, 3.863e+02, 1.267e+02, 2.665e+01};
    const double *vxsec = (isRun3 ? &vxsec3[0] : &vxsec2[0]);
    for (int i = 0; i != nht; ++i)
    {
      hxsec->SetBinContent(i + 1, vxsec[i]);
    }
  } // isMG

  // Inclusive jets pT binning
  double vpti[] =
      {1, 5, 6, 8, 10, 12, 15, 18, 21, 24, 28, 32, 37, 43, 49, 56, 64, 74, 84,
       97, 114, 133, 153, 174, 196, 220, 245, 272, 300, 330, 362, 395, 430, 468,
       507, 548, 592, 638, 686, 737, 790, 846, 905, 967, 1032, 1101, 1172, 1248,
       1327, 1410, 1497, 1588, 1684, 1784, 1890, 2000, 2116, 2238, 2366, 2500,
       2640, 2787, 2941, 3103, 3273, 3450, 3637, 3832, 4037, 4252, 4477, 4713,
       4961, 5220, 5492, 5777, 6076, 6389, 6717, 7000};
  double npti = sizeof(vpti) / sizeof(vpti[0]) - 1;
  // L2Res pT binning (central+forward hybrid)
  double vptd[] =
      //{59.,85.,104.,170.,236., 302., 370., 460., 575.}; // central
      //{86., 110., 132., 204., 279., 373.} // forward
      {10, 15, 21, 28, 37, 49,
       59, 86, 110, 132, 170, 204, 236, 279, 302, 373, 460, 575,
       638, 737, 846, 967, 1101, 1248,
       1410, 1588, 1784, 2000, 2238, 2500, 2787, 3103, 3450, 4037, 5220};
  double nptd = sizeof(vptd) / sizeof(vptd[0]) - 1;
  // L3Res (gamma+jet) pT binning adapted and extended
  const double vpt[] = {10, 15, 20, 25, 30, 35,
                        40, 50, 60, 70, 85, 100, 125, 155, 180, 210, 250, 300,
                        350, 400, 500, 600, 800, 1000, 1200, 1500,
                        1800, 2100, 2400, 2700, 3000, 3500, 4000, 5000};
  const int npt = sizeof(vpt) / sizeof(vpt[0]) - 1;

  // Regular L2Relative eta binning
  double vx[] =
      {-5.191,
       -4.889, -4.716, -4.538, -4.363, -4.191, -4.013, -3.839, -3.664, -3.489,
       -3.314, -3.139, -2.964, -2.853, -2.65, -2.5, -2.322, -2.172, -2.043,
       -1.93, -1.83, -1.74, -1.653, -1.566, -1.479, -1.392, -1.305, -1.218,
       -1.131, -1.044, -0.957, -0.879, -0.783, -0.696, -0.609, -0.522, -0.435,
       -0.348, -0.261, -0.174, -0.087, 0, 0.087, 0.174, 0.261, 0.348, 0.435,
       0.522, 0.609, 0.696, 0.783, 0.879, 0.957, 1.044, 1.131, 1.218, 1.305,
       1.392, 1.479, 1.566, 1.653, 1.74, 1.83, 1.93, 2.043, 2.172, 2.322, 2.5,
       2.65, 2.853, 2.964, 3.139, 3.314, 3.489, 3.664, 3.839, 4.013, 4.191,
       4.363, 4.538, 4.716, 4.889, 5.191};
  const int nx = sizeof(vx) / sizeof(vx[0]) - 1;
  // Current L2Res |eta| binning from Jindrich
  // https://indico.cern.ch/event/1263476/contributions/5311425/attachments/2612023/4513129/L2Res+HDM-March15.pdf
  double vxd[] =
      //{0, 0.261, 0.522, 0.783, 1.044, 1.305, 1.479, 1.653, 1.93, 2.172, 2.322, 2.5, 2.65, 2.853, 2.964, 3.139, 3.489, 3.839, 5.191};
      // Newer L2Res |eta| binning from Mikel
      // https://indico.cern.ch/event/1335203/#7-update-on-l2res-for-2022-rer
      {0., 0.261, 0.522, 0.783, 1.044, 1.305, 1.479, 1.653, 1.93, 2.172, 2.322, 2.5, 2.65, 2.853, 2.964, 3.139, 3.314, 3.489, 3.839, 4.013, 4.583, 5.191};
  const int nxd = sizeof(vxd) / sizeof(vxd[0]) - 1;

  const int ny = 800;
  double vy[ny + 1];
  for (int i = 0; i != ny + 1; ++i)
    vy[i] = -3. + (+5. + 3.) / ny * i;
  const int nz = 400;
  double vz[nz + 1];
  for (int i = 0; i != nz + 1; ++i)
    vz[i] = -1. + (+3. + 1.) / nz * i;

  // Extras for JMENANO
  TH2D *h2mhtvsmet = new TH2D("h2mhtvsmet", "MHT vs MET;MET;MHT",
                              500, 0, 500, 500, 0, 500);
  TH2D *h2dphi = new TH2D("h2dphi", "#Delta#phi vs #eta;#eta;#Delta#phi",
                          nx, vx, 126, -TMath::TwoPi(), +TMath::TwoPi());

  // L2Res profiles for HDM method
  // coding: m0=MPF, m2=DB, mn=n-jet, mu=uncl. (observable)
  //         a=PtAve, t=PtTag, p=PtProbe (binning)
  //         b=bisector, c=central(tag), f=forward(probe) (projection axis)
  fout->mkdir("Refs");
  fout->cd("Refs");
  TH1D *hnjet = new TH1D("hnjet", "hnjet", 500, 0, 500);

  /*
  // PF composition plots
  // Copy L2Res histograms for multiple pT bins
  const double vpt[] = {15, 20, 25, 30, 35,
      40, 50, 60, 70, 85, 100, 125, 155, 180, 210, 250, 300,
      350, 400, 500, 600, 800, 1000, 1200, 1500,
      1800, 2100, 2400, 2700, 3000};
  const int npt = sizeof(vpt)/sizeof(vpt[0])-1;

  TH1D *hptbins = new TH1D("hptbins",";p_{T} (GeV);N_{events}",npt,vpt);

  TProfile *pjes = new TProfile("pjes","JES",nx,vx);
  TProfile *pres = new TProfile("pres","RES",nx,vx);
  TProfile *pdjes = new TProfile("pdjes","#DELTAJES",nx,vx);
  TProfile *pjes13 = new TProfile("pjes13","JES",npt,vpt);
  TProfile *pres13 = new TProfile("pres13","RES",npt,vpt);
  TProfile *pdjes13 = new TProfile("pdjes13","#DELTAJES",npt,vpt);

  TProfile *pchf = new TProfile("pchf","CHF",nx,vx);
  TProfile *pnhf = new TProfile("pnhf","NHF",nx,vx);
  TProfile *pnef = new TProfile("pnef","NEF",nx,vx);
  TProfile *pcef = new TProfile("pcef","CEF",nx,vx);
  TProfile *pmuf = new TProfile("pmuf","MUF",nx,vx);
  TProfile *phef = new TProfile("phfhf","HEF",nx,vx);
  TProfile *phhf = new TProfile("phfef","HHF",nx,vx);

  TProfile *pchf13 = new TProfile("pchf13","CHF",npt,vpt);
  TProfile *pnhf13 = new TProfile("pnhf13","NHF",npt,vpt);
  TProfile *pnef13 = new TProfile("pnef13","NEF",npt,vpt);
  TProfile *pcef13 = new TProfile("pcef13","CEF",npt,vpt);
  TProfile *pmuf13 = new TProfile("pmuf13","MUF",npt,vpt);

  TH1D *hmjj2 = new TH1D("hmjj2","Dijet mass, 2-lead",1000,0,1000);
  TH1D *hmjj213 = new TH1D("hmjj213","Dijet mass, |#DeltaEta|<1.3, 2-lead",
           1000,0,1000);
  */
  fout->cd();

  if (debug)
    cout << "Load JSON (or not)" << endl
         << flush;

  bool doJSON = (true && !isMC);
  if (doJSON)
  {
    // if (!LoadJSON()) {
    // cout << "Issues loading the JSON file; aborting..." << endl << flush;
    // exit(0);
    // }

    // Load JSON files
    if (TString(dataset.c_str()).Contains("2016"))
      LoadJSON("rootfiles/Cert_271036-284044_13TeV_Legacy2016_Collisions16_JSON.txt");
    if (TString(dataset.c_str()).Contains("2017"))
      LoadJSON("rootfiles/Cert_294927-306462_13TeV_UL2017_Collisions17_GoldenJSON.txt");
    if (TString(dataset.c_str()).Contains("2018"))
      LoadJSON("rootfiles/Cert_314472-325175_13TeV_Legacy2018_Collisions18_JSON.txt");
    if (TString(dataset.c_str()).Contains("2022"))
      LoadJSON("rootfiles/Cert_Collisions2022_355100_362760_Golden.json");
    if (TString(dataset.c_str()).Contains("2023"))
      LoadJSON("rootfiles/Cert_Collisions2023_366442_370790_Golden.json");
  }
  int _nbadevts_json(0);

  bool doTrigger = true; //(true && !isMC);
  int _nbadevts_trg(0);
  int _nbadevts_fwdtrg(0);
  int _ngoodevts(0);

  // Listing of runs and LS
  int nrun(0), nls(0), nevt(0);
  map<int, map<int, int>> mrunls;

  map<string, mctruthHistos *> mhmc;
  map<string, jetvetoHistos *> mhjv;
  map<string, incjetHistos *> mhij;
  map<string, dijetHistos *> mhdj;
  map<string, dijetHistos2 *> mhdj2;
  map<string, multijetHistos *> mhmj;
  map<string, lumiHistos *> mhlumi;

  bool dolumi = false;
  if (dolumi)
    LoadLumi();

  for (int itrg = 0; itrg != ntrg; ++itrg)
  {

    if (debug)
      cout << "Trigger " << vtrg[itrg] << endl
           << flush;

    fout->mkdir(vtrg[itrg].c_str());
    fout->cd(vtrg[itrg].c_str());
    TDirectory *dout = gDirectory;

    // Figure out trigger pT threshold from the name
    int trgpt(-1), nfound(0);
    if (nfound != 1)
    {
      nfound = (vtrg[itrg] == "HLT_ZeroBias" || vtrg[itrg] == "HLT_MC" ? 1 : 0);
      trgpt = 0;
    }
    if (nfound != 1)
      nfound = sscanf(vtrg[itrg].c_str(), "HLT_PFJet%d", &trgpt);
    if (nfound != 1)
      nfound = sscanf(vtrg[itrg].c_str(), "HLT_PFJetFwd%d", &trgpt);
    if (nfound != 1)
      nfound = sscanf(vtrg[itrg].c_str(), "HLT_DiPFJetAve%d", &trgpt);
    if (nfound != 1)
      nfound = sscanf(vtrg[itrg].c_str(), "HLT_DiPFJetAve%d_HFJEC", &trgpt);
    if (!(nfound == 1 && trgpt != -1))
    {
      cout << "trigger " << vtrg[itrg] << ": nfound=" << nfound
           << ", trgpt = " << trgpt << endl
           << flush;
    }
    assert(nfound == 1);
    assert(trgpt != -1);

    if (isMC && doMCtruth && vtrg[itrg] == "HLT_MC")
    {

      if (debug)
        cout << "Setup MC truth" << endl
             << flush;

      dout->mkdir("MCtruth");
      dout->cd("MCtruth");

      mctruthHistos *h = new mctruthHistos();

      string &t = vtrg[itrg];
      mhmc[t] = h;
      // h->trg = t;
      // h->trgpt = trgpt;

      // struct range &r  = mt[t];
      // h->ptmin = r.ptmin;
      // h->ptmax = r.ptmax;
      // h->absetamin = r.absetamin;
      // h->absetamax = r.absetamax;

      h->h2pteta = new TH2D("h2pteta", ";|#eta_{jet}|;p_{T,gen} (GeV);"
                                       "N_{events}",
                            nxd, vxd, nptd, vptd);
      h->h2pteta_gen = new TH2D("h2pteta_gen", ";|#eta_{gen}|;p_{T,gen} (GeV);"
                                               "N_{events}",
                                nxd, vxd, nptd, vptd);
      h->h2pteta_rec = new TH2D("h2pteta_rec", ";|#eta_{jet}|;p_{T,jet} (GeV);"
                                               "N_{events}",
                                nxd, vxd, nptd, vptd);
      h->p2jes = new TProfile2D("p2jes", ";|#eta_{jet}|;p_{T,gen} (GeV);"
                                         "JES(jet)",
                                nxd, vxd, nptd, vptd);
      h->p2jsf = new TProfile2D("p2jsf", ";|#eta_{jet}|;p_{T,gen} (GeV);"
                                         "JERSF(jet)",
                                nxd, vxd, nptd, vptd);
      h->p2r = new TProfile2D("p2r", ";|#eta_{jet}|;p_{T,gen} (GeV);"
                                     "p_{T,jet}/p_{T,gen}",
                              nxd, vxd, nptd, vptd);
      h->p2effz = new TProfile2D("p2effz", ";|#eta_{gen}|;p_{T,gen} (GeV);"
                                           "Vertex efficiency",
                                 nxd, vxd, nptd, vptd);
      h->p2eff = new TProfile2D("p2eff", ";|#eta_{gen}|;p_{T,gen} (GeV);"
                                         "Efficiency",
                                nxd, vxd, nptd, vptd);
      h->p2pur = new TProfile2D("p2pur", ";|#eta_{jet}|;p_{T,jet} (GeV);"
                                         "Purity",
                                nxd, vxd, nptd, vptd);
    } // isMC && doMCtruth

    // Jet veto per trigger
    if (doJetveto)
    {
      if (debug)
        cout << "Setup doJetveto " << trgpt << endl
             << flush;

      dout->mkdir("Jetveto");
      dout->cd("Jetveto");

      jetvetoHistos *h = new jetvetoHistos();

      string &t = vtrg[itrg];
      mhjv[t] = h;
      h->trg = t;
      h->trgpt = trgpt;

      struct range &r = mt[t];
      h->ptmin = r.ptmin;
      h->ptmax = r.ptmax;
      h->absetamin = r.absetamin;
      h->absetamax = r.absetamax;

      // Plots with inclusive jet selection
      h->h2pteta_all = new TH2D("h2pteta_all", ";#eta;p_{T} (GeV);N_{jet}",
                                nx, vx, npti, vpti);
      h->h2pteta_sel = new TH2D("h2pteta_sel", ";#eta;p_{T} (GeV);N_{jet}",
                                nx, vx, npti, vpti);
      h->h2phieta = new TH2D("h2phieta", ";#eta;#phi;N_{jet}",
                             nx, vx, 72, -TMath::Pi(), +TMath::Pi());

      if (doPFComposition)
      {
        h->p2chf = new TProfile2D("p2chf", ";#eta;#phi;CHF (DM)",
                                  nx, vx, 72, -TMath::Pi(), +TMath::Pi());
        h->p2nef = new TProfile2D("p2nef", ";#eta;#phi;NEF (DM)",
                                  nx, vx, 72, -TMath::Pi(), +TMath::Pi());
        h->p2nhf = new TProfile2D("p2nhf", ";#eta;#phi;NHF (DM)",
                                  nx, vx, 72, -TMath::Pi(), +TMath::Pi());
      }

      // Plots with dijet selection, pTave bins
      if (doJetvetoVariants)
      {
        h->h2ptaeta_all = new TH2D("h2ptaeta_all", ";#eta;p_{T} (GeV);"
                                                   "N_{jet}",
                                   nx, vx, npti, vpti);
        h->h2ptaeta_sel = new TH2D("h2ptaeta_sel", ";#eta;p_{T} (GeV);"
                                                   "N_{jet}",
                                   nx, vx, npti, vpti);
      }
      h->h2phieta_ave = new TH2D("h2phieta_ave", ";#eta;#phi;N_{jet}",
                                 nx, vx, 72, -TMath::Pi(), +TMath::Pi());
      h->p2asymm = new TProfile2D("p2asymm", ";#eta;#phi;Asymmetry",
                                  nx, vx, 72, -TMath::Pi(), +TMath::Pi());

      if (doJetvetoVariants)
      {
        // Plots with dijet selection, pTtag bins
        h->h2ptteta_all = new TH2D("h2ptteta_all", ";#eta;p_{T} (GeV);N_{jet}",
                                   nx, vx, npti, vpti);
        h->h2ptteta_sel = new TH2D("h2ptteta_sel", ";#eta;p_{T} (GeV);N_{jet}",
                                   nx, vx, npti, vpti);
        h->h2phieta_tag = new TH2D("h2phieta_tag", ";#eta;#phi;N_{jet}",
                                   nx, vx, 72, -TMath::Pi(), +TMath::Pi());

        if (doPFComposition)
        {

          h->p2chftp = new TProfile2D("p2chftp", ";#eta;#phi;CHF (TP)",
                                      nx, vx, 72, -TMath::Pi(), +TMath::Pi());
          h->p2neftp = new TProfile2D("p2neftp", ";#eta;#phi;NEF (TP)",
                                      nx, vx, 72, -TMath::Pi(), +TMath::Pi());
          h->p2nhftp = new TProfile2D("p2nhftp", ";#eta;#phi;NHF (TP)",
                                      nx, vx, 72, -TMath::Pi(), +TMath::Pi());
        }
      }
    } // doJetVeto

    // Inclusive jet per trigger
    if (doIncjet)
    {
      if (debug)
        cout << "Setup doIncjet " << trgpt << endl
             << flush;

      dout->mkdir("Incjet");
      dout->cd("Incjet");

      incjetHistos *h = new incjetHistos();

      string &t = vtrg[itrg];
      mhij[t] = h;
      h->trg = t;
      h->trgpt = trgpt;

      struct range &r = mt[t];
      h->ptmin = r.ptmin;
      h->ptmax = r.ptmax;
      h->absetamin = r.absetamin;
      h->absetamax = r.absetamax;

      h->h2pteta_all = new TH2D("h2pteta_all", ";#eta;p_{T} (GeV);N_{jet}",
                                nx, vx, npti, vpti);
      h->h2pteta_sel = new TH2D("h2pteta_sel", ";#eta;p_{T} (GeV);N_{jet}",
                                nx, vx, npti, vpti);
      h->h2pteta = new TH2D("h2pteta", ";#eta;p_{T} (GeV);N_{jet}",
                            nx, vx, npti, vpti);

      // For pileup cleaning checks
      if (isMG)
      {
        h->h2jtvht = new TH2D("h2jtvht", ";H_{T} (GeV);2*Jet[0]",
                              npti, vpti, npti, vpti);
        h->h2jtoht = new TH2D("h2jtoht", ";H_{T} (GeV);2*Jet[0]/HT",
                              npti, vpti, 200, 0., 10.);
      }

      h->hpt13 = new TH1D("hpt13", ";p_{T,jet} (GeV)", npti, vpti);
      for (int iy = 0; iy != h->ny; ++iy)
      {
        h->vpt[iy] = new TH1D(Form("hpt%02d", 5 * (iy + 1)), ";p_{T} (GeV);"
                                                             "N_{jet}",
                              npti, vpti);
      } // for iy

      if (doPFComposition)
      {

        dout->mkdir("Incjet/PFcomposition");
        dout->cd("Incjet/PFcomposition");

        h->p2pt = new TProfile2D("p2pt", ";#eta;p_{T,jet} (GeV);"
                                         "p_{T,jet}",
                                 nx, vx, npt, vpt);
        h->p2rho = new TProfile2D("p2rho", ";#eta;p_{T,jet} (GeV);"
                                           "#rho",
                                  nx, vx, npt, vpt);
        h->p2chf = new TProfile2D("p2chf", ";#eta;p_{T,jet} (GeV);"
                                           "CHF",
                                  nx, vx, npt, vpt);
        h->p2nhf = new TProfile2D("p2nhf", ";#eta;p_{T,jet} (GeV);"
                                           "NHF",
                                  nx, vx, npt, vpt);
        h->p2nef = new TProfile2D("p2nef", ";#eta;p_{T,jet} (GeV);"
                                           "NEF",
                                  nx, vx, npt, vpt);
        h->p2cef = new TProfile2D("p2cef", ";#eta;p_{T,jet} (GeV);"
                                           "CEF",
                                  nx, vx, npt, vpt);
        h->p2muf = new TProfile2D("p2muf", ";#eta;p_{T,jet} (GeV);"
                                           "MUF",
                                  nx, vx, npt, vpt);

        h->ppt13 = new TProfile("ppt13", ";#eta;p_{T,jet} (GeV);"
                                         "p_{T,jet}",
                                npt, vpt);
        h->prho13 = new TProfile("prho13", ";#eta;p_{T,jet} (GeV);"
                                           "#rho",
                                 npt, vpt);
        h->pchf13 = new TProfile("pchf13", ";#eta;p_{T,jet} (GeV);"
                                           "CHF",
                                 npt, vpt);
        h->pnhf13 = new TProfile("pnhf13", ";#eta;p_{T,jet} (GeV);"
                                           "NHF",
                                 npt, vpt);
        h->pnef13 = new TProfile("pnef13", ";#eta;p_{T,jet} (GeV);"
                                           "NEF",
                                 npt, vpt);
        h->pcef13 = new TProfile("pcef13", ";#eta;p_{T,jet} (GeV);"
                                           "CEF",
                                 npt, vpt);
        h->pmuf13 = new TProfile("pmuf13", ";#eta;p_{T,jet} (GeV);"
                                           "MUF",
                                 npt, vpt);
      }
    } // incjet

    // Dijet per trigger
    if (doDijet)
    {
      if (debug)
        cout << "Setup doDijet " << trgpt << endl
             << flush;

      dout->mkdir("Dijet");
      dout->cd("Dijet");

      dijetHistos *h = new dijetHistos();

      string &t = vtrg[itrg];
      mhdj[t] = h;
      h->trg = t;
      h->trgpt = trgpt;

      struct range &r = mt[t];
      h->ptmin = r.ptmin;
      h->ptmax = r.ptmax;
      h->absetamin = r.absetamin;
      h->absetamax = r.absetamax;

      // Counting of events, and JEC L2L3Res for undoing
      h->h2pteta_aball = new TH2D("h2pteta_aball", ";#eta;p_{T,avp} (GeV);"
                                                   "N_{events}",
                                  nx, vx, npt, vpt);
      h->h2pteta_absel = new TH2D("h2pteta_absel", ";#eta;p_{T,avp} (GeV);"
                                                   "N_{events}",
                                  nx, vx, npt, vpt);
      h->p2resab = new TProfile2D("p2resab", ";#eta;p_{T,avp} (GeV);"
                                             "JES(probe)/JES(tag)",
                                  nx, vx, npt, vpt);

      // MPF decomposition for HDM method
      h->p2m0ab = new TProfile2D("p2m0ab", ";#eta;p_{T,avp} (GeV);MPF0",
                                 nx, vx, npt, vpt);
      h->p2m2ab = new TProfile2D("p2m2ab", ";#eta;p_{T,avp} (GeV);MPF2",
                                 nx, vx, npt, vpt);
      h->p2mnab = new TProfile2D("p2mnab", ";#eta;p_{T,avp} (GeV);MPFn",
                                 nx, vx, npt, vpt);
      h->p2muab = new TProfile2D("p2muab", ";#eta;p_{T,avp} (GeV);MPFu",
                                 nx, vx, npt, vpt);

      // Variants with different binnings and with error on the mean
      h->h2pteta_adall = new TH2D("h2pteta_adall", ";#eta;p_{T,ave} (GeV);"
                                                   "N_{events}",
                                  nx, vx, npt, vpt);
      h->h2pteta_adsel = new TH2D("h2pteta_adsel", ";#eta;p_{T,ave} (GeV);"
                                                   "N_{events}",
                                  nx, vx, npt, vpt);
      h->p2resad = new TProfile2D("p2resad", ";#eta;p_{T,ave} (GeV);"
                                             "JES(probe)/JES(tag)",
                                  nx, vx, npt, vpt);

      // MPF decomposition for HDM method
      h->p2m0ad = new TProfile2D("p2m0ad", ";#eta;p_{T,ave} (GeV);MPF0",
                                 nx, vx, npt, vpt);
      h->p2m2ad = new TProfile2D("p2m2ad", ";#eta;p_{T,ave} (GeV);MPF2",
                                 nx, vx, npt, vpt);
      h->p2mnad = new TProfile2D("p2mnad", ";#eta;p_{T,ave} (GeV);MPFn",
                                 nx, vx, npt, vpt);
      h->p2muad = new TProfile2D("p2muad", ";#eta;p_{T,ave} (GeV);MPFu",
                                 nx, vx, npt, vpt);

      h->h2pteta_tcall = new TH2D("h2pteta_tcall", ";#eta;p_{T,ave} (GeV);"
                                                   "N_{events}",
                                  nx, vx, npt, vpt);
      h->h2pteta_tcsel = new TH2D("h2pteta_tcsel", ";#eta;p_{T,ave} (GeV);"
                                                   "N_{events}",
                                  nx, vx, npt, vpt);
      h->p2restc = new TProfile2D("p2restc", ";#eta;p_{T,ave} (GeV);"
                                             "JES(probe)/JES(tag)",
                                  nx, vx, npt, vpt);

      h->p2m0tc = new TProfile2D("p2m0tc", ";#eta;p_{T,tag} (GeV);MPF0",
                                 nx, vx, npt, vpt);
      h->p2m2tc = new TProfile2D("p2m2tc", ";#eta;p_{T,tag} (GeV);MPF2",
                                 nx, vx, npt, vpt);
      h->p2mntc = new TProfile2D("p2mntc", ";#eta;p_{T,tag} (GeV);MPFn",
                                 nx, vx, npt, vpt);
      h->p2mutc = new TProfile2D("p2mutc", ";#eta;p_{T,tag} (GeV);MPFu",
                                 nx, vx, npt, vpt);

      h->h2pteta_pfall = new TH2D("h2pteta_pfall", ";#eta;p_{T,ave} (GeV);"
                                                   "N_{events}",
                                  nx, vx, npt, vpt);
      h->h2pteta_pfsel = new TH2D("h2pteta_pfsel", ";#eta;p_{T,ave} (GeV);"
                                                   "N_{events}",
                                  nx, vx, npt, vpt);
      h->p2respf = new TProfile2D("p2respf", ";#eta;p_{T,ave} (GeV);"
                                             "JES(probe)/JES(tag)",
                                  nx, vx, npt, vpt);

      h->p2m0pf = new TProfile2D("p2m0pf", ";#eta;p_{T,probe} (GeV);MPF0",
                                 nx, vx, npt, vpt);
      h->p2m2pf = new TProfile2D("p2m2pf", ";#eta;p_{T,probe} (GeV);MPF2",
                                 nx, vx, npt, vpt);
      h->p2mnpf = new TProfile2D("p2mnpf", ";#eta;p_{T,probe} (GeV);MPFn",
                                 nx, vx, npt, vpt);
      h->p2mupf = new TProfile2D("p2mupf", ";#eta;p_{T,probe} (GeV);MPFu",
                                 nx, vx, npt, vpt);

      if (doDijetJER)
      {
        dout->mkdir("Dijet/JER");
        dout->cd("Dijet/JER");

        // Basic profiles with RMS as error ("S") for JER studies
        h->p2m0 = new TProfile2D("p2m0", ";#eta;p_{T,avp} (GeV);"
                                         "MPF0 (MPF)",
                                 nx, vx, npt, vpt, "S");
        h->p2m0x = new TProfile2D("p2m0x", ";#eta;p_{T,avp} (GeV);"
                                           "MPFX0 (MPFX)",
                                  nx, vx, npt, vpt, "S");
        h->p2m2 = new TProfile2D("p2m2", ";#eta;p_{T,avp} (GeV);"
                                         "MPF2 (DB)",
                                 nx, vx, npt, vpt, "S");
        h->p2m2x = new TProfile2D("p2m2x", ";#eta;p_{T,avp} (GeV);"
                                           "MPF2 (DBX)",
                                  nx, vx, npt, vpt, "S");
      }

      if (doPFComposition)
      {

        dout->mkdir("Dijet/PFcomposition");
        dout->cd("Dijet/PFcomposition");

        h->p2pt = new TProfile2D("p2pt", ";#eta;p_{T,avp} (GeV);"
                                         "p_{T,probe}",
                                 nx, vx, npt, vpt);
        h->p2rho = new TProfile2D("p2rho", ";#eta;p_{T,avp} (GeV);"
                                           "#rho",
                                  nx, vx, npt, vpt);
        h->p2chf = new TProfile2D("p2chf", ";#eta;p_{T,avp} (GeV);"
                                           "CHF",
                                  nx, vx, npt, vpt);
        h->p2nhf = new TProfile2D("p2nhf", ";#eta;p_{T,avp} (GeV);"
                                           "NHF",
                                  nx, vx, npt, vpt);
        h->p2nef = new TProfile2D("p2nef", ";#eta;p_{T,avp} (GeV);"
                                           "NEF",
                                  nx, vx, npt, vpt);
        h->p2cef = new TProfile2D("p2cef", ";#eta;p_{T,avp} (GeV);"
                                           "CEF",
                                  nx, vx, npt, vpt);
        h->p2muf = new TProfile2D("p2muf", ";#eta;p_{T,avp} (GeV);"
                                           "MUF",
                                  nx, vx, npt, vpt);

        h->ppt13 = new TProfile("ppt13", ";#eta;p_{T,avp} (GeV);"
                                         "p_{T,tag}",
                                npt, vpt);
        h->prho13 = new TProfile("prho13", ";#eta;p_{T,avp} (GeV);"
                                           "#rho",
                                 npt, vpt);
        h->pchf13 = new TProfile("pchf13", ";#eta;p_{T,avp} (GeV);"
                                           "CHF",
                                 npt, vpt);
        h->pnhf13 = new TProfile("pnhf13", ";#eta;p_{T,avp} (GeV);"
                                           "NHF",
                                 npt, vpt);
        h->pnef13 = new TProfile("pnef13", ";#eta;p_{T,avp} (GeV);"
                                           "NEF",
                                 npt, vpt);
        h->pcef13 = new TProfile("pcef13", ";#eta;p_{T,avp} (GeV);"
                                           "CEF",
                                 npt, vpt);
        h->pmuf13 = new TProfile("pmuf13", ";#eta;p_{T,avp} (GeV);"
                                           "MUF",
                                 npt, vpt);
      }

    } // doDijet

    if (doDijet2)
    {
      if (debug)
        cout << "Setup doDijet2 " << trgpt << endl
             << flush;

      dout->mkdir("Dijet2");
      dout->cd("Dijet2");

      dijetHistos2 *h = new dijetHistos2();

      string &t = vtrg[itrg];
      mhdj2[t] = h;
      h->trg = t;
      h->trgpt = trgpt;

      struct range &r = mt[t];
      h->ptmin = r.ptmin;
      h->ptmax = r.ptmax;
      h->absetamin = r.absetamin;
      h->absetamax = r.absetamax;

      // Counting of events, and JEC L2L3Res+JERSF for undoing
      h->h2pteta = new TH2D("h2pteta", ";#eta;p_{T,avp} (GeV);"
                                       "N_{events}",
                            nxd, vxd, nptd, vptd);
      h->p2res = new TProfile2D("p2res", ";#eta;p_{T,avp} (GeV);"
                                         "JES(probe)/JES(tag)",
                                nxd, vxd, nptd, vptd);
      h->p2jsf = new TProfile2D("p2jsf", ";#eta;p_{T,avp} (GeV);"
                                         "JERSF(probe)/JERSF(tag)",
                                nxd, vxd, nptd, vptd);

      // MPF decomposition for HDM method
      h->p2m0 = new TProfile2D("p2m0", ";#eta;p_{T,avp} (GeV);MPF0",
                               nxd, vxd, nptd, vptd);
      h->p2m2 = new TProfile2D("p2m2", ";#eta;p_{T,avp} (GeV);MPF2",
                               nxd, vxd, nptd, vptd);
      h->p2mn = new TProfile2D("p2mn", ";#eta;p_{T,avp} (GeV);MPFn",
                               nxd, vxd, nptd, vptd);
      h->p2mu = new TProfile2D("p2mu", ";#eta;p_{T,avp} (GeV);MPFu",
                               nxd, vxd, nptd, vptd);

      h->p2m0x = new TProfile2D("p2m0x", ";#eta;p_{T,avp} (GeV);"
                                         "MPF0X (MPFX)",
                                nxd, vxd, nptd, vptd, "S");
      h->p2m2x = new TProfile2D("p2m2x", ";#eta;p_{T,avp} (GeV);"
                                         "MPF2X (DBX)",
                                nxd, vxd, nptd, vptd, "S");

      // Extra for FRS studies
      h->p2mnu = new TProfile2D("p2mnu", ";#eta;p_{T,avp} (GeV);MPFnu",
                                nxd, vxd, nptd, vptd);
      h->p2mnx = new TProfile2D("p2mnx", ";#eta;p_{T,avp} (GeV);"
                                         "MPFNX",
                                nxd, vxd, nptd, vptd, "S");
      h->p2mux = new TProfile2D("p2mux", ";#eta;p_{T,avp} (GeV);"
                                         "MPFUX",
                                nxd, vxd, nptd, vptd, "S");
      h->p2mnux = new TProfile2D("p2mnux", ";#eta;p_{T,avp} (GeV);"
                                           "MPFNUX",
                                 nxd, vxd, nptd, vptd, "S");

      h->h2ptetatc = new TH2D("h2ptetatc", ";#eta;p_{T,tag} (GeV);"
                                           "N_{events}",
                              nxd, vxd, nptd, vptd);
      h->p2restc = new TProfile2D("p2restc", ";#eta;p_{T,tag} (GeV);"
                                             "JES(probe)/JES(tag)",
                                  nxd, vxd, nptd, vptd);
      h->p2jsftc = new TProfile2D("p2jsftc ", ";#eta;p_{T,tag} (GeV);"
                                              "JERSF(probe)/JERSF(tag)",
                                  nxd, vxd, nptd, vptd);
      h->p2m0tc = new TProfile2D("p2m0tc", ";#eta;p_{T,tag} (GeV);MPF0",
                                 nxd, vxd, nptd, vptd);
      h->p2m2tc = new TProfile2D("p2m2tc", ";#eta;p_{T,tag} (GeV);MPF2",
                                 nxd, vxd, nptd, vptd);
      h->p2mntc = new TProfile2D("p2mntc", ";#eta;p_{T,tag} (GeV);MPFn",
                                 nxd, vxd, nptd, vptd);
      h->p2mutc = new TProfile2D("p2mutc", ";#eta;p_{T,tag} (GeV);MPFu",
                                 nxd, vxd, nptd, vptd);

      h->h2ptetapf = new TH2D("h2ptetapf", ";#eta;p_{T,probe} (GeV);"
                                           "N_{events}",
                              nxd, vxd, nptd, vptd);
      h->p2respf = new TProfile2D("p2respf", ";#eta;p_{T,probe} (GeV);"
                                             "JES(probe)/JES(tag)",
                                  nxd, vxd, nptd, vptd);
      h->p2jsfpf = new TProfile2D("p2jsfpf", ";#eta;p_{T,probe} (GeV);"
                                             "JERSF(probe)/JERSF(tag)",
                                  nxd, vxd, nptd, vptd);
      h->p2m0pf = new TProfile2D("p2m0pf", ";#eta;p_{T,probe} (GeV);MPF0",
                                 nxd, vxd, nptd, vptd);
      h->p2m2pf = new TProfile2D("p2m2pf", ";#eta;p_{T,probe} (GeV);MPF2",
                                 nxd, vxd, nptd, vptd);
      h->p2mnpf = new TProfile2D("p2mnpf", ";#eta;p_{T,probe} (GeV);MPFn",
                                 nxd, vxd, nptd, vptd);
      h->p2mupf = new TProfile2D("p2mupf", ";#eta;p_{T,probe} (GeV);MPFu",
                                 nxd, vxd, nptd, vptd);

      if (doDijet2NM)
      {
        assert(false);
        // separate TProfile2D for NM=1, NM=2, NM=3+ (no JetID if has NM>1)
      }
    } // doDijet2

    // Multijet per trigger
    if (doMultijet)
    {

      if (debug)
        cout << "Setup doMultijet " << trgpt << endl
             << flush;

      dout->mkdir("Multijet");
      dout->cd("Multijet");

      multijetHistos *h = new multijetHistos();

      string &t = vtrg[itrg];
      mhmj[t] = h;
      h->trg = t;
      h->trgpt = trgpt;

      struct range &r = mt[t];
      h->ptmin = r.ptmin;
      h->ptmax = r.ptmax;
      h->absetamin = r.absetamin;
      h->absetamax = r.absetamax;

      h->hpta_all = new TH1D("hpta_all", "", npti, vpti);
      h->hpta_sel = new TH1D("hpta_sel", "", npti, vpti);
      h->presa = new TProfile("presa", "", npti, vpti);
      h->ptleada = new TProfile("ptleada", "", npti, vpti);
      h->pcrecoila = new TProfile("pcrecoila", "", npti, vpti);

      h->pm0a = new TProfile("pm0a", "", npti, vpti);
      h->pm2a = new TProfile("pm2a", "", npti, vpti);
      h->pmna = new TProfile("pmna", "", npti, vpti);
      h->pmua = new TProfile("pmua", "", npti, vpti);

      h->hptm_all = new TH1D("hptm_all", "", npti, vpti);
      h->hptm_sel = new TH1D("hptm_sel", "", npti, vpti);
      h->presm = new TProfile("presm", "", npti, vpti);
      h->ptleadm = new TProfile("ptleadm", "", npti, vpti);
      h->pcrecoilm = new TProfile("pcrecoilm", "", npti, vpti);

      h->pm0m = new TProfile("pm0m", "", npti, vpti);
      h->pm2m = new TProfile("pm2m", "", npti, vpti);
      h->pmnm = new TProfile("pmnm", "", npti, vpti);
      h->pmum = new TProfile("pmum", "", npti, vpti);

      h->hptl_all = new TH1D("hptl_all", "", npti, vpti);
      h->hptl_sel = new TH1D("hptl_sel", "", npti, vpti);
      h->presl = new TProfile("presl", "", npti, vpti);
      h->ptleadl = new TProfile("ptleadl", "", npti, vpti);
      h->pcrecoill = new TProfile("pcrecoill", "", npti, vpti);

      h->pm0l = new TProfile("pm0l", "", npti, vpti);
      h->pm2l = new TProfile("pm2l", "", npti, vpti);
      h->pmnl = new TProfile("pmnl", "", npti, vpti);
      h->pmul = new TProfile("pmul", "", npti, vpti);

      h->hptr_all = new TH1D("hptr_all", "", npti, vpti);
      h->hptr_sel = new TH1D("hptr_sel", "", npti, vpti);
      h->presr = new TProfile("presr", "", npti, vpti);
      h->ptleadr = new TProfile("ptleadr", "", npti, vpti);
      h->pcrecoilr = new TProfile("pcrecoilr", "", npti, vpti);

      h->pm0r = new TProfile("pm0r", "", npti, vpti);
      h->pm2r = new TProfile("pm2r", "", npti, vpti);
      h->pmnr = new TProfile("pmnr", "", npti, vpti);
      h->pmur = new TProfile("pmur", "", npti, vpti);

      if (doMultijetControl)
      {
        h->h2m0a = new TH2D("h2m0a", "", npti, vpti, 200, -1, 3);
        h->h2m2a = new TH2D("h2m2a", "", npti, vpti, 200, -1, 3);
        h->hcosdphi = new TH1D("hcosdphi", "", 102, -1.01, 1.01);
      }
      if (doMultijet2Drecoil)
      {
        dout->mkdir("Multijet/2Drecoil");
        dout->cd("Multijet/2Drecoil");
        h->h2recoila = new TH2D("h2recoila", "", npti, vpti, npti, vpti);
        h->h2recoilm = new TH2D("h2recoilm", "", npti, vpti, npti, vpti);
        h->h2recoill = new TH2D("h2recoill", "", npti, vpti, npti, vpti);
        h->h2recoilr = new TH2D("h2recoilr", "", npti, vpti, npti, vpti);
      }
      if (doPFComposition)
      {
        dout->mkdir("Multijet/PFcomposition");
        dout->cd("Multijet/PFcomposition");

        h->ppt13 = new TProfile("ppt13", ";#eta;p_{T,avp} (GeV);"
                                         "p_{T,lead}",
                                npti, vpti);
        h->prho13 = new TProfile("prho13", ";#eta;p_{T,avp} (GeV);"
                                           "#rho",
                                 npti, vpti);
        h->pchf13 = new TProfile("pchf13", ";#eta;p_{T,avp} (GeV);"
                                           "CHF",
                                 npti, vpti);
        h->pnhf13 = new TProfile("pnhf13", ";#eta;p_{T,avp} (GeV);"
                                           "NHF",
                                 npti, vpti);
        h->pnef13 = new TProfile("pnef13", ";#eta;p_{T,avp} (GeV);"
                                           "NEF",
                                 npti, vpti);
        h->pcef13 = new TProfile("pcef13", ";#eta;p_{T,avp} (GeV);"
                                           "CEF",
                                 npti, vpti);
        h->pmuf13 = new TProfile("pmuf13", ";#eta;p_{T,avp} (GeV);"
                                           "MUF",
                                 npti, vpti);

        h->ppt25 = new TProfile("ppt25", ";#eta;p_{T,avp} (GeV);"
                                         "p_{T,recoil}",
                                npti, vpti);
        h->prho25 = new TProfile("prho25", ";#eta;p_{T,avp} (GeV);"
                                           "#rho",
                                 npti, vpti);
        h->pchf25 = new TProfile("pchf25", ";#eta;p_{T,avp} (GeV);"
                                           "CHF",
                                 npti, vpti);
        h->pnhf25 = new TProfile("pnhf25", ";#eta;p_{T,avp} (GeV);"
                                           "NHF",
                                 npti, vpti);
        h->pnef25 = new TProfile("pnef25", ";#eta;p_{T,avp} (GeV);"
                                           "NEF",
                                 npti, vpti);
        h->pcef25 = new TProfile("pcef25", ";#eta;p_{T,avp} (GeV);"
                                           "CEF",
                                 npti, vpti);
        h->pmuf25 = new TProfile("pmuf25", ";#eta;p_{T,avp} (GeV);"
                                           "MUF",
                                 npti, vpti);
      }

    } // doMultijet

    // Lumi per trigger
    if (dolumi)
    {
      dout->mkdir("LumiInfo");
      dout->cd("LumiInfo");

      lumiHistos *h = new lumiHistos();

      string &t = vtrg[itrg];
      mhlumi[t] = h;

      h->trg = t;
      h->trgpt = trgpt;

      h->lum = 0.0;
      h->lum2 = 0.0;

      h->lumsum = 0.0;
      h->lumsum2 = 0.0;
      h->htrglumi = new TH1D("htrglumi", "", 100, 0, 1);
      h->htrgpu = new TH1D("htrgpu", "", 100, 0, 100);
      h->hnpv = new TH1D("hnpv", "", 100, 0, 100);
      h->hnpvgood = new TH1D("hnpvgood", "", 100, 0, 100);
    }

  } // for itrg

  if (debugevent)
    cout << "Load jet veto maps" << endl
         << flush;

  // Load veto maps
  // JECDatabase/jet_veto_maps/Summer19UL16_V0/hotjets-UL16.root
  // JECDatabase/jet_veto_maps/Summer19UL17_V2/hotjets-UL17_v2.root
  // JECDatabase/jet_veto_maps/Summer19UL18_V1/hotjets-UL18.root
  TFile *fjv(0);
  if (isRun2 == 1 || isRun2 == 2) // TString(ds.c_str()).Contains("2016"))
    fjv = new TFile("rootfiles/hotjets-UL16.root", "READ");
  if (isRun2 == 3) // TString(ds.c_str()).Contains("2017"))
    fjv = new TFile("rootfiles/hotjets-UL17_v2.root", "READ");
  if (isRun2 == 4) // TString(ds.c_str()).Contains("2018"))
    fjv = new TFile("rootfiles/hotjets-UL18.root", "READ");
  if (dataset == "2022C" || dataset == "2022D" || dataset == "2022C_ZB" ||
      dataset == "2022D_ZB" || dataset == "Summer22" ||
      dataset == "Summer22Flat" ||
      TString(dataset.c_str()).Contains("Summer22MG"))
    fjv = new TFile("rootfiles/jetveto2022CD.root", "READ");
  if (dataset == "2022E" || dataset == "2022F" || dataset == "2022G" ||
      dataset == "2022F1" || dataset == "2022F2" ||
      dataset == "2022E_ZB" || dataset == "2022F_ZB" || dataset == "2022G_ZB" ||
      dataset == "Summer22EE" ||
      dataset == "Summer22EEFlat" ||
      TString(dataset.c_str()).Contains("Summer22EEMG"))
    fjv = new TFile("rootfiles/jetveto2022EFG.root", "READ");
  if (dataset == "2023B" || dataset == "2023C" || dataset == "2023BCv123" ||
      dataset == "2023Cv123" || dataset == "2023Cv4" ||
      dataset == "2023B_ZB" || dataset == "2023C_ZB" || dataset == "2023BCv123_ZB" ||
      dataset == "2023Cv123_ZB" || dataset == "2023Cv4_ZB" ||
      (TString(dataset.c_str()).Contains("Summer23MG") && ! TString(dataset.c_str()).Contains("MGBPix")))
    fjv = new TFile("rootfiles/jetveto2023BC.root", "READ");
  if (dataset == "2023D" || dataset == "2023D_ZB" ||
      TString(dataset.c_str()).Contains("Summer23MGBPix"))
    fjv = new TFile("rootfiles/jetveto2023D.root", "READ");
  assert(fjv);

  // Veto lists for different years (NB: extra MC map for UL16):
  // h2hot_ul16_plus_hbm2_hbp12_qie11 + h2hot_mc (for UL16)
  // h2hot_ul17_plus_hep17_plus_hbpw89 (UL17)
  // h2hot_ul18_plus_hem1516_and_hbp2m1 (UL18)
  TH2D *h2jv(0);
  if (isRun2 == 1 || isRun2 == 2)
  { // TString(ds.c_str()).Contains("2016")) {
    h2jv = (TH2D *)fjv->Get("h2hot_ul16_plus_hbm2_hbp12_qie11");
    assert(h2jv);
    TH2D *h2mc = (TH2D *)fjv->Get("h2hot_mc");
    assert(h2mc);
    h2jv->Add(h2mc);
  }
  if (isRun2 == 3) // TString(ds.c_str()).Contains("2017"))
    h2jv = (TH2D *)fjv->Get("h2hot_ul17_plus_hep17_plus_hbpw89");
  if (isRun2 == 4) // TString(ds.c_str()).Contains("2018"))
    h2jv = (TH2D *)fjv->Get("h2hot_ul18_plus_hem1516_and_hbp2m1");
  if (dataset == "2022C" || dataset == "2022D" || dataset == "2022C_ZB" ||
      dataset == "2022D_ZB" || dataset == "Summer22" ||
      dataset == "Summer22Flat" ||
      TString(dataset.c_str()).Contains("Summer22MG"))
    h2jv = (TH2D *)fjv->Get("jetvetomap");
  if (dataset == "2022E" || dataset == "2022F" || dataset == "2022G" ||
      dataset == "2022F1" || dataset == "2022F2" ||
      dataset == "2022E_ZB" || dataset == "2022F_ZB" || dataset == "2022G_ZB" ||
      dataset == "Summer22EE" ||
      dataset == "Summer22EEFlat" ||
      TString(dataset.c_str()).Contains("Summer22EEMG"))
    h2jv = (TH2D *)fjv->Get("jetvetomap");
  if (dataset == "2023B" || dataset == "2023C" || dataset == "2023BCv123" ||
      dataset == "2023Cv123" || dataset == "2023Cv4" ||
      dataset == "2023B_ZB" || dataset == "2023C_ZB" || dataset == "2023BCv123_ZB" ||
      dataset == "2023Cv123_ZB" || dataset == "2023Cv4_ZB" ||
      (TString(dataset.c_str()).Contains("Summer23MG") && ! TString(dataset.c_str()).Contains("MGBPix")))
    h2jv = (TH2D *)fjv->Get("jetvetomap");
  if (dataset == "2023D" || dataset == "2023D_ZB" ||
      TString(dataset.c_str()).Contains("Summer23MGBPix"))
    h2jv = (TH2D *)fjv->Get("jetvetomap");
  assert(h2jv);

  // Long64_t nentries = fChain->GetEntriesFast();
  Long64_t nentries = fChain->GetEntries(); // Long startup time
  cout << "Loaded " << nentries << " entries" << endl
       << flush;

  if (isMG && nentries != nMG)
  {
    cout << "Nentries = " << nentries << ", expected nMG = " << nMG << endl
         << flush;
    // assert(false);
    cout << "Recalculate HT bin counts prior to starting."
         << " This will take a few minutes" << endl;
    hnevt->Reset();
    hnwgt->Reset();
    for (Long64_t jentry = 0; jentry < nentries; jentry++)
    {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0)
        break;
      b_LHE_HT->GetEntry(ientry);    // read only this branch
      b_genWeight->GetEntry(ientry); // also this if MG
      double w = genWeight;
      hnevt->Fill(LHE_HT);
      hnwgt->Fill(LHE_HT, w);
      if (jentry % 1000000 == 0)
        cout << "." << flush;
      if (jentry % 50000000 == 0 && jentry != 0)
        cout << "\nn=" << jentry << endl
             << flush;
    } // for jentry
    nMG = nentries;
    cout << "\nProcessed " << nMG << " entries" << endl
         << flush;
    cout << Form("int vnevt[%d] = ", hnevt->GetNbinsX());
    for (int i = 1; i != hnevt->GetNbinsX() + 1; ++i)
    {
      cout << Form("%s%d", (i == 1 ? "{" : ", "), int(hnevt->GetBinContent(i) + 0.5));
    }
    cout << "}; // " << dataset << endl
         << flush;
    cout << Form("double vnwgt[%d] = ", hnwgt->GetNbinsX());
    for (int i = 1; i != hnwgt->GetNbinsX() + 1; ++i)
    {
      cout << Form("%s%1.4g", (i == 1 ? "{" : ", "), hnwgt->GetBinContent(i));
    }
    cout << "}; // " << dataset << endl
         << flush;
  } // isMC && nentries!=nMG

  // For trigger matching studies
  // const int kMaxTrigJet = 3;
  // Float_t Jet_hltPt[kMaxTrigJet];
  // Float_t Jet_hltPtClose[kMaxTrigJet];
  // Float_t Jet_hltPtNear[kMaxTrigJet];
  // Float_t Jet_hltPtMax[kMaxTrigJet];
  Float_t Jet_RES[nJetMax];
  Float_t Jet_deltaJES[nJetMax];
  Float_t Jet_CF[nJetMax];
  Float_t Jet_genDR[nJetMax];
  // Float_t Jet_smearFactor[nJetMax];

  Long64_t nbytes = 0, nb = 0;
  for (Long64_t jentry = 0; jentry < nentries; jentry++)
  {
    Long64_t ientry = LoadTree(jentry);
    if (ientry < 0)
      break;

    if (jentry % 100000 == 0)
      cout << "." << flush;
    if (jentry % 5000000 == 0)
      cout << "n=" << jentry << endl
           << flush;

    if (jentry == 100000 || jentry == 1000000 || jentry == 1000000 ||
        (jentry % 1000000 == 0 && jentry < 10000000) ||
        (jentry % 10000000 == 0) || jentry == nentries - 1)
    {
      if (jentry == 0)
      {
        laptime.Start();
      }
      if (nentries != 0)
      {
        double events_per_second = (double)jentry / fulltime.RealTime(); // Calculate events per second
        cout << Form("\nProcessed %lld events (%1.1f%%) in %1.0f sec. "
                     "(%1.0f sec. for last %d)",
                     jentry, 100. * jentry / nentries, fulltime.RealTime(),
                     laptime.RealTime(), nlap);
	cout << Form("\nEvents per second: %1.2f", events_per_second); // Print events per second
      }
      if (jentry != 0 && nlap != 0)
      {
        cout << Form("\nEstimated runtime:  %1.0f sec. "
                     " (%1.0f sec. for last %d)\n",
                     1. * nentries / jentry * fulltime.RealTime(),
                     1. * nentries / nlap * laptime.RealTime(), nlap)
             << flush;
        // Nestor
        //
        TDatime estimated_completion_time;
        estimated_completion_time.Set(start_time.Convert() + (1. * nentries / jentry * fulltime.RealTime()));
        // Format and print the estimated completion time
        cout << "Estimated full runtime: " << estimated_completion_time.AsSQLString() << endl;
        //
        laptime.Reset();
        nlap = 0;
      }
      if (jentry == 0)
        fulltime.Reset(); // Leave out initialization time
      fulltime.Continue();
      laptime.Continue();
    }
    if (jentry % 10000 == 0)
      cout << "." << flush;
    ++nlap;

    if (debugevent)
      cout << "Read run+LS branches for JSON " << endl
           << flush;

    // Clean code from bad lumisections using JSON file
    if (doJSON)
    {
      if (debugevent)
        cout << "doJSON: Read in branches" << endl
             << flush;

      b_run->GetEntry(ientry);
      b_luminosityBlock->GetEntry(ientry);

      // Does the run/LS pass the latest JSON selection?
      if (_json[run][luminosityBlock] == 0)
      {
        ++_nbadevts_json;
        continue;
      }

      // Separate 2023Cv123 and 2023Cv4
      if (((dataset == "2023Cv123") && (run >= 367765) ) || ((dataset == "2023Cv123") && (run >= 367765))) {
        continue;
      }
      if ((dataset == "2023Cv4") && (run < 367765)) {
        continue;
      }
    } // doJSON



    if (debugevent)
      cout << "Read in entry" << endl
           << flush;

    // Read rest of the event before trigger decision
    nb = fChain->GetEntry(jentry);
    nbytes += nb;
    // if (Cut(ientry) < 0) continue;

    double w = (isMC ? genWeight : 1.);
    if (isMG)
    {

      int iht = hxsec->FindBin(LHE_HT);
      // Check that iht is equal to HT_bin_idx
      if (iht != HT_bin_idx)
      {
        cout << "LHE_HT = " << LHE_HT << " is not in the bin " << HT_bin_idx << " for " << _filename << endl << flush;
        cout << "Using bin based on filename instead." << endl << flush;
        iht = HT_bin_idx;
      }

      double xsec = hxsec->GetBinContent(iht);
      double nevt = (isRun3 ? hnwgt->GetBinContent(iht) : hnevt->GetBinContent(iht));
      double wht = (nevt ? xsec / nevt : 1);
      w *= wht;
      if (w > 10000){
        cout << "WARNING: w = " << w << " for " << _filename << endl << flush;
      }
      hLHE_HT->Fill(LHE_HT);     // cross-check hnevt afterwards
      hLHE_HTw->Fill(LHE_HT, w); // cross-check hnwgt afterwards
      hHT->Fill(LHE_HT, w);      // cross-check HT spectrum smoothness afterwards
      hHT_Now->Fill(LHE_HT);
      hHT_MCw->Fill(LHE_HT, genWeight);
      hHT_w->Fill(genWeight);
    }
    double rho = Rho_fixedGridRhoFastjetAll;

    bool doPtHatFilter = true;
    if (doPtHatFilter && isMC)
    {
      if (isMG && !isRun3 && 2. * Pileup_pthatmax > LHE_HT)
        continue;
      if (isMG && isRun3 && 2. * Jet_pt[0] / LHE_HT > 2.5 / pow(LHE_HT / 40., 2) + 1.5)
        continue; // Run3 MG patch for missing Pileup_pthatmax
      if (!isMG && Pileup_pthatmax > Generator_binvar)
        continue;
    }

    if (debugevent)
      cout << "Keep track of run+LS" << endl
           << flush;

    if (mrunls.find(run) == mrunls.end())
      ++nrun;
    if (mrunls[run].find(luminosityBlock) == mrunls[run].end())
      ++nls;
    ++nevt;
    // THIS HAS BEEN MOVED TO LUMI CALCULATION
    // mrunls[run][luminosityBlock] = 1;

    // Check that MET filters are all true
    bool pass_METfilter = (isRun3 &&
                           Flag_goodVertices &&
                           Flag_globalSuperTightHalo2016Filter &&
                           Flag_EcalDeadCellTriggerPrimitiveFilter &&
                           Flag_BadPFMuonFilter &&
                           Flag_BadPFMuonDzFilter &&
                           Flag_hfNoisyHitsFilter &&
                           Flag_eeBadScFilter &&
                           Flag_ecalBadCalibFilter);

    // Check if any triggers fired and make histogram of them
    if (doTrigger)
    {

      if (debugevent)
        cout << "Check trigger" << endl
             << flush;

      bool fired = false;
      for (int i = 0; i != ntrg; ++i)
      {
        fired = (fired || (*mtrg[vtrg[i]]));
        if (*mtrg[vtrg[i]])
          htrg->Fill(i);
      }
      if (!fired)
      {
        ++_nbadevts_trg;
        continue;
      }
    } // doTrigger
    ++_ngoodevts;

    if (debugevent)
      cout << "Redo JEC" << endl
           << flush;

    // Redo JEC right after event cuts but before anything else
    // Do not re-sort (for now)
    bool allJetsGood(true);
    int njet = nJet;
    for (int i = 0; i != njet; ++i)
    {


      #ifdef PNET_REG
      Jet_PNetRegPtRawCorrTotal = Jet_PNetRegPtRawCorr[i]*Jet_PNetRegPtCorrNeutrino[i];
      #else
      Jet_PNetRegPtRawCorrTotal = 1.;
      #endif
      if i==0{
      cout << "src Jet_PNetRegPtRawCorrTotal = " << Jet_PNetRegPtRawCorrTotal << endl;
      }

      if (redoJEC)
      {
        double rawJetPt = Jet_pt[i] * (1.0 - Jet_rawFactor[i])* Jet_PNetRegPtRawCorrTotal;
        double rawJetMass = Jet_mass[i] * (1.0 - Jet_rawFactor[i]);


        jec->setJetPt(rawJetPt);
        jec->setJetEta(Jet_eta[i]);
        jec->setJetPhi(Jet_phi[i]);
        if (isRun2)
        {
          jec->setJetA(Jet_area[i]);
          jec->setRho(Rho_fixedGridRhoFastjetAll);
          jecl1rc->setJetPt(rawJetPt);
          jecl1rc->setJetEta(Jet_eta[i]);
          jecl1rc->setJetA(Jet_area[i]);
          jecl1rc->setRho(Rho_fixedGridRhoFastjetAll);
        }
        // double corr = jec->getCorrection();
        vector<float> v = jec->getSubCorrections();
        double corr = v.back();
        double res = (v.size() > 1 ? v[v.size() - 1] / v[v.size() - 2] : 1.);
        Jet_RES[i] = 1. / res;
        Jet_deltaJES[i] = (1. / corr) / (1.0 - Jet_rawFactor[i]);
        Jet_pt[i] = corr * rawJetPt;
        Jet_mass[i] = corr * rawJetMass;
        Jet_rawFactor[i] = (1.0 - (1.0 / corr));
        // pt*(1-l1rcFactor)=ptl1rc => l1rcFactor = 1 - ptl1rc/pt
        Jet_l1rcFactor[i] = (isRun2 ? (1.0 - jecl1rc->getCorrection() / corr) : Jet_rawFactor[i]);
      }
      else
      {
        Jet_RES[i] = 1.;
        Jet_deltaJES[i] = 1.;
        Jet_l1rcFactor[i] = Jet_rawFactor[i];
        #ifdef PNET_REG
        Jet_pt[i] = Jet_pt[i] * (1.0 - Jet_rawFactor[i])* Jet_PNetRegPtRawCorrTotal; //??
        #endif
      }

      if (true)
      { // check jet veto
        int i1 = h2jv->GetXaxis()->FindBin(Jet_eta[i]);
        int j1 = h2jv->GetYaxis()->FindBin(Jet_phi[i]);
        Jet_jetveto[i] = (h2jv->GetBinContent(i1, j1) > 0);
      } // jet veto
      else
        Jet_jetveto[i] = false;

      // Fail allJetsGood flag if any jet of pT>15 is not good
      if (!(Jet_jetId[i] >= 4 && !Jet_jetveto[i]) && Jet_pt[i] > 15.)
        allJetsGood = false;
      // NB: should move this after smearing. Separate loop for type-I MET?
    } // for njet

    // Apply JER smearing to MC immediately after JEC. Don't change order.
    // Need after JEC to ensure mean is at 1, but ideally should recalculate
    // JEC with smeared reco pT for consistency
    // Jet_smearFactor[i] = 0.;
    // Safety reset that works for data as well
    for (int i = 0; i != njet; ++i)
    {
      Jet_CF[i] = 1.;
    } // reset Jet_CF

    if (isMC && reweightPU)
    {
      assert(pileupRatio);
      // Get the bin
      int ibin = pileupRatio->FindBin(Pileup_nTrueInt);
      double pileup_weight = pileupRatio->GetBinContent(ibin);
      w *= pileup_weight;
    }

    if (isMC && smearJets)
    {

      for (int i = 0; i != njet; ++i)
      {

        Jet_CF[i] = 1.;
        if (i < smearNMax)
        {

          // Retrieve genJet and calculate dR
          double dR(999);
          p4.SetPtEtaPhiM(Jet_pt[i], Jet_eta[i], Jet_phi[i], Jet_mass[i]);

          if (Jet_genJetIdx[i] >= 0 )// && Jet_genJetIdx[i] < nGenJet)
          {
            int j = Jet_genJetIdx[i];
            p4g.SetPtEtaPhiM(GenJet_pt[j], GenJet_eta[j], GenJet_phi[j],
                             GenJet_mass[j]);
            dR = p4g.DeltaR(p4);
          }
          else
            p4g.SetPtEtaPhiM(0, 0, 0, 0);

          // Rename variables to keep naming as in jetphys/IOV.h.
          double jPt = Jet_pt[i];
          double jEta = Jet_eta[i];
          double rho = Rho_fixedGridRhoFastjetAll;
          double jE = p4.E();
          double jPtGen = p4g.Pt();
          // Set constants
          double MIN_JET_ENERGY = 0.01; // TBD

          // Some problems with the code below:
          // 1) JER should us primarily genPt, secondary recoPt
          // 2) relDpt  should evaluate vs genPt to avoid <1/x> != 1/<x> bias
          // 3) For (JME)NANO, should also check DR of genJet
          // Probably small impact except for the last, which I add

          // The method presented here can be found in https://twiki.cern.ch/twiki/bin/viewauth/CMS/JetResolution
          // and the corresponding code in https://github.com/cms-sw/cmssw/blob/CMSSW_8_0_25/PhysicsTools/PatUtils/interface/SmearedJetProducerT.h
          assert(jer);
          double Reso = jer->getResolution({{JME::Binning::JetPt, jPt}, {JME::Binning::JetEta, jEta}, {JME::Binning::Rho, rho}});
          double SF(1);
          if (useJERSFvsPt && jersfvspt)
          {
            jersfvspt->setJetEta(jEta);
            jersfvspt->setJetPt(jPt);
            jersfvspt->setRho(rho);
            SF = jersfvspt->getCorrection();
          }
          else if (!useJERSFvsPt && jersf)
          {
            SF = jersf->getScaleFactor({{JME::Binning::JetEta, jEta}, {JME::Binning::Rho, rho}}, Variation::NOMINAL);
          }
          else
          {
            cout << "No JER SF available" << endl << flush;
            assert(false);
          }

          // Case 0: by default the JER correction factor is equal to 1
          double CF = 1.;
          // We see if the gen jet meets our requirements
          bool condPt = (jPtGen > MIN_JET_ENERGY && dR < 0.2);
          double relDPt = condPt ? (jPt - jPtGen) / jPt : 0.0;
          bool condPtReso = fabs(relDPt) < 3 * Reso;
          if (condPt and condPtReso)
          {
            // Case 1: we have a "good" gen jet matched to the reco jet (indicated by positive gen jet pt)
            CF += (SF - 1.) * relDPt;
          }
          else if (SF > 1)
          {
            // Case 2: we don't have a gen jet. Smear jet pt using a random gaussian variation
            double sigma = Reso * std::sqrt(SF * SF - 1);
            std::normal_distribution<> d(0, sigma);
            CF += d(_mersennetwister);
          }

          // Negative or too small smearFactor. Safety precautions.
          double CFLimit = MIN_JET_ENERGY / jE;
          if (CF < CFLimit)
            CF = CFLimit;

          double origPt = Jet_pt[i];
          double origJetMass = Jet_mass[i];
          Jet_pt[i] = CF * origPt;
          Jet_mass[i] = CF * origJetMass;
          Jet_CF[i] = CF;
          // Jet_smearFactor[i] = (1.0 - 1.0/CF);

          // type-I calculation is done later and propagates JER SF
          // (needs to have unsmeard p4lr1c, fully smeared p4)
        } // i<smearNMax
      }   // for njet
    }     // JER smearing

    // Calculate MC truth right after JEC and smearing to test closure
    if (isMC && doMCtruth)
    {

      mctruthHistos *h = mhmc["HLT_MC"];

      // First, map reco->gen so can quickly invert gen->reco
      // Also reset dR
      map<int, int> genToReco;
      for (int i = 0; i != njet; ++i)
      {
        if (Jet_genJetIdx[i] >= 0)
        {
          genToReco[Jet_genJetIdx[i]] = i;
        }
        Jet_genDR[i] = 999.;
        h->h2pteta_rec->Fill(fabs(Jet_eta[i]), Jet_pt[i], w);
      } // for i

      // Then loop over genjets and also update dr
      for (Int_t j = 0; j != nGenJet; ++j)
      {

        p4g.SetPtEtaPhiM(GenJet_pt[j], GenJet_eta[j], GenJet_phi[j],
                         GenJet_mass[j]);
        double dR(999);
        int i(-1);
        if (genToReco.find(j) != genToReco.end())
        {
          i = genToReco[j];
          p4.SetPtEtaPhiM(Jet_pt[i], Jet_eta[i], Jet_phi[i], Jet_mass[i]);
          dR = p4g.DeltaR(p4);
          Jet_genDR[i] = dR;
        }
        else
          p4.SetPtEtaPhiM(0, 0, 0, 0);

        h->h2pteta_gen->Fill(fabs(p4g.Eta()), p4g.Pt(), w);
        bool hasMatchVtx = (fabs(PV_z - GenVtx_z) < 0.2);
        bool hasMatchJet = (dR < 0.2 && p4g.Pt() > 0 && p4.Pt() > 0);
        if (hasMatchVtx && hasMatchJet)
        {
          h->h2pteta->Fill(fabs(p4.Eta()), p4g.Pt(), w);
          h->p2jes->Fill(fabs(p4.Eta()), p4g.Pt(), (1. - Jet_rawFactor[i]), w);
          h->p2jsf->Fill(fabs(p4.Eta()), p4g.Pt(),
                         smearJets ? Jet_CF[i] : 1, w);
          h->p2r->Fill(fabs(p4.Eta()), p4g.Pt(), p4.Pt() / p4g.Pt(), w);
        }
        h->p2effz->Fill(fabs(p4g.Eta()), p4g.Pt(), hasMatchVtx ? 1 : 0, w);
        if (hasMatchVtx)
          h->p2eff->Fill(fabs(p4g.Eta()), p4g.Pt(), hasMatchJet ? 1 : 0, w);
      } // for j

      // Finally check fake rates
      for (int i = 0; i != njet; ++i)
      {
        bool hasMatchVtx = (fabs(PV_z - GenVtx_z) < 0.2);
        bool hasMatchJet = (Jet_genDR[i] < 0.2);
        if (hasMatchVtx)
          h->p2pur->Fill(fabs(Jet_eta[i]), Jet_pt[i], hasMatchJet ? 1 : 0);
      } // for i

    } // isMC && doMCtruth

    if (debugevent)
      cout << "Sum four-vectors for MHT" << endl
           << flush;

    // int njet3 = 0;
    // int njetn = 0;

    // Reset MET vectors
    if (isRun2)
    {
      p4rawmet.SetPtEtaPhiM(ChsMET_pt, 0, ChsMET_phi, 0);
      p4t1met.SetPtEtaPhiM(ChsMET_pt, 0, ChsMET_phi, 0);
      p4m0.SetPtEtaPhiM(ChsMET_pt, 0, ChsMET_phi, 0);
    }
    else
    {
      p4rawmet.SetPtEtaPhiM(RawPuppiMET_pt, 0, RawPuppiMET_phi, 0);
      p4t1met.SetPtEtaPhiM(RawPuppiMET_pt, 0, RawPuppiMET_phi, 0);
      p4m0.SetPtEtaPhiM(RawPuppiMET_pt, 0, RawPuppiMET_phi, 0);
      // p4rawmet.SetPtEtaPhiM(PuppiMET_pt,0,PuppiMET_phi,0);
      // p4t1met.SetPtEtaPhiM(PuppiMET_pt,0,PuppiMET_phi,0);
      // p4m0.SetPtEtaPhiM(PuppiMET_pt,0,PuppiMET_phi,0);
    }
    p4mht.SetPtEtaPhiM(0, 0, 0, 0);

    // Reset dijet vectors
    p4m2.SetPtEtaPhiM(0, 0, 0, 0);
    p4mn.SetPtEtaPhiM(0, 0, 0, 0);
    p4mu.SetPtEtaPhiM(0, 0, 0, 0);

    // Reset multijet vectors
    // bool ismultijet = (njet>=3); // multijet pre-setting
    p4lead.SetPtEtaPhiM(0, 0, 0, 0);
    p4recoil.SetPtEtaPhiM(0, 0, 0, 0);
    p4m3.SetPtEtaPhiM(0, 0, 0, 0);
    p4mn3.SetPtEtaPhiM(0, 0, 0, 0);
    p4mu3.SetPtEtaPhiM(0, 0, 0, 0);
    p4leadRES.SetPtEtaPhiM(0, 0, 0, 0);
    p4recoilRES.SetPtEtaPhiM(0, 0, 0, 0);
    int nlead(0);
    int nrecoil(0);
    bool multijet_vetonear(false);
    bool multijet_vetofwd(false);

    for (int i = 0; i != njet; ++i)
    {

      // p4 is fully corrected and smeared
      p4.SetPtEtaPhiM(Jet_pt[i], Jet_eta[i], Jet_phi[i], Jet_mass[i]);
      // p4raw.SetPtEtaPhiM(Jet_pt[i]*(1.0-Jet_rawFactor[i]), Jet_eta[i],
      //		   Jet_phi[i], Jet_mass[i]*(1.0-Jet_rawFactor[i]));
      // p4l1rc.SetPtEtaPhiM(Jet_pt[i]*(1.0-Jet_l1rcFactor[i]), Jet_eta[i],
      //		    Jet_phi[i], Jet_mass[i]*(1.0-Jet_l1rcFactor[i]));
      //  p4l1rc is before corrections and smearing
      p4l1rc.SetPtEtaPhiM(Jet_pt[i] / (smearJets && Jet_CF[i] ? Jet_CF[i] : 1) * (1.0 - Jet_l1rcFactor[i]),
                          Jet_eta[i], Jet_phi[i],
                          Jet_mass[i] / (smearJets && Jet_CF[i] ? Jet_CF[i] : 1) * (1.0 - Jet_l1rcFactor[i]));

      // Jet veto maps
      if (doJetveto)
      {

        for (int itrg = 0; itrg != ntrg; ++itrg)
        {
          string &trg = vtrg[itrg];
          if (!(*mtrg[trg]))
            continue;

          jetvetoHistos *h = mhjv[trg];
          assert(h);
          double abseta = fabs(p4.Eta());
          double pt = p4.Pt();

          h->h2pteta_all->Fill(p4.Eta(), p4.Pt(), w);
          // Debug
          if (Jet_jetId[i] >= 4 && pass_METfilter > 0 &&
              pt >= h->ptmin && pt < h->ptmax &&
              abseta >= h->absetamin && abseta < h->absetamax)
          {

            h->h2pteta_sel->Fill(p4.Eta(), p4.Pt(), w);
            h->h2phieta->Fill(p4.Eta(), p4.Phi(), w);
            if (doPFComposition)
            {
              h->p2chf->Fill(p4.Eta(), p4.Phi(), Jet_chHEF[i], w);
              h->p2nef->Fill(p4.Eta(), p4.Phi(), Jet_neEmEF[i], w);
              h->p2nhf->Fill(p4.Eta(), p4.Phi(), Jet_neHEF[i], w);
            }
          }
        }
      } // doJetveto

      // Inclusive jets
      if (doIncjet)
      {
        for (int itrg = 0; itrg != ntrg; ++itrg)
        {

          string &trg = vtrg[itrg];
          if (!(*mtrg[trg]))
            continue;

          incjetHistos *h = mhij[trg];

          h->h2pteta_all->Fill(p4.Eta(), p4.Pt(), w);
          if (Jet_jetId[i] >= 4 && !Jet_jetveto[i] && pass_METfilter > 0)
          {

            h->h2pteta->Fill(p4.Eta(), p4.Pt(), w);

            if (isMG && i == 0)
            {
              h->h2jtvht->Fill(LHE_HT, 2 * p4.Pt(), w);
              h->h2jtoht->Fill(LHE_HT, 2 * p4.Pt() / LHE_HT, w);
            }

            if (p4.Pt() >= h->ptmin && p4.Pt() < h->ptmax &&
                fabs(p4.Rapidity()) > h->absetamin &&
                fabs(p4.Rapidity()) < h->absetamax)

              h->h2pteta_sel->Fill(p4.Eta(), p4.Pt(), w);

            if (fabs(p4.Rapidity()) < 1.3)
              h->hpt13->Fill(p4.Pt(), w);
            int iy = int(fabs(p4.Rapidity()) / 0.5);
            if (iy < h->ny)
              h->vpt[iy]->Fill(p4.Pt(), w);

            if (doPFComposition)
            {
              double eta = p4.Eta();
              double pt = p4.Pt();
              h->p2pt->Fill(eta, pt, Jet_pt[i], w);
              h->p2rho->Fill(eta, pt, rho, w);
              h->p2chf->Fill(eta, pt, Jet_chHEF[i], w);
              h->p2nhf->Fill(eta, pt, Jet_neHEF[i], w);
              h->p2nef->Fill(eta, pt, Jet_neEmEF[i], w);
              h->p2cef->Fill(eta, pt, Jet_chEmEF[i], w);
              h->p2muf->Fill(eta, pt, Jet_muEF[i], w);

              if (fabs(eta) < 1.3)
              {
                h->ppt13->Fill(pt, Jet_pt[i], w);
                h->prho13->Fill(pt, rho, w);
                h->pchf13->Fill(pt, Jet_chHEF[i], w);
                h->pnhf13->Fill(pt, Jet_neHEF[i], w);
                h->pnef13->Fill(pt, Jet_neEmEF[i], w);
                h->pcef13->Fill(pt, Jet_chEmEF[i], w);
                h->pmuf13->Fill(pt, Jet_muEF[i], w);
              }
            } // doPFcomposition
          }   // JetID+METfilter
        }     // for itrg
      }       // doIncJet

      // Calculate type-I MET (L1L2L3-RC) and MHT
      if (p4.Pt() > 15.)
      {
        p4mht -= p4;
        p4t1met += p4l1rc - p4; // same as (+raw-rcoff) -corr,
        p4m0 += p4l1rc - p4;    // same as (+raw-rcoff) -corr
      }

      // L2Res HDM (dijet)
      if (i < 2 && p4.Pt() > 15.)
      { // two leading jets
        p4m2 -= p4;
      }
      else if (p4.Pt() > 15.)
      {
        p4mn -= p4;
      }

      // L3Res HDM (multijet)
      if (i == 0 && p4.Pt() > 30.)
      { // leading jet
        p4lead += p4;
        p4m3 -= p4;
        p4leadRES += Jet_RES[i] * p4;
        ++nlead;
      }
      else if (i > 0 && p4.Pt() > 30. && fabs(p4.Eta()) < 2.5 &&
               DELTAPHI(p4.Phi(), p4lead.Phi()) > 1.0)
      { // recoil jets
        p4recoil += p4;
        p4m3 -= p4;
        p4recoilRES += Jet_RES[i] * p4;
        ++nrecoil;
      }
      else if (p4.Pt() > 15.)
      { // all other jets
        p4mn3 -= p4;
      }

      // Veto nearby jets for multijet topology
      if (i > 0 && p4.Pt() > 30. && fabs(p4.Eta()) < 2.5 &&
          DELTAPHI(p4.Phi(), p4lead.Phi()) <= 1.0)
        multijet_vetonear = true;

      // Veto forward jets for multijet topology
      if (i > 0 && p4.Pt() > 30. && fabs(p4.Eta()) >= 2.5)
        multijet_vetofwd = true;

    } // for i in njet

    // Calculate unclustered MET from the remainders
    // met = -j2 -jn -ju = m2 + mn + mu => mu = met -m2 -mn
    p4mu = p4m0 - p4m2 - p4mn;
    p4mu3 = p4m0 - p4m3 - p4mn3;

    // Also check recoil phi for multijet selection
    double ptrecoil = p4recoil.Pt();
    double dphirecoil = DELTAPHI(p4lead.Phi(), p4recoil.Phi());
    // Use tightLepVeto for JetID
    bool ismultijet =
        (nlead == 1 && nrecoil >= 2 && !multijet_vetonear && !multijet_vetofwd &&
         fabs(dphirecoil - TMath::Pi()) < 0.3 && pass_METfilter > 0 &&
         Jet_pt[0] > 30. && fabs(Jet_eta[0]) < 1.3 && Jet_jetId[0] >= 4 &&
         Jet_pt[1] > 30. && fabs(Jet_eta[1]) < 2.5 && Jet_jetId[1] >= 4 &&
         Jet_pt[2] > 30. && fabs(Jet_eta[2]) < 2.5 && Jet_jetId[2] >= 4 &&
         !Jet_jetveto[0] && !Jet_jetveto[1] && !Jet_jetveto[2] &&
         Jet_pt[1] < 0.6 * ptrecoil && Jet_pt[2] < 0.6 * ptrecoil);

    // Calculate Crecoil
    double logCrecoil(0);
    double ptavp3(0);
    if (ismultijet && doMultijet)
    {

      // Proper bisector axis (equal angles to each jet)
      p4b3.SetPtEtaPhiM(0, 0, 0, 0);
      p4b3r.SetPtEtaPhiM(1, 0, p4recoil.Phi(), 0);
      p4b3l.SetPtEtaPhiM(1, 0, p4lead.Phi(), 0);
      p4b3 += p4b3r;
      p4b3 -= p4b3l;
      p4b3.SetPtEtaPhiM(p4b3.Pt(), 0., p4b3.Phi(), 0.);
      p4b3 *= 1. / p4b3.Pt();

      // Average projection pT to bisector axis, pT,avp
      // as explained in JME-21-001 (HDM method: bisector extension)
      ptavp3 = 0.5 * (p4recoil.Vect().Dot(p4b3.Vect()) -
                      p4lead.Vect().Dot(p4b3.Vect()));

      double ptlead = p4lead.Pt();
      double ptave = 0.5 * (ptlead + ptrecoil);
      for (int i = 0; i != njet; ++i)
      {

        // Crecoil = exp(sum_i F_i log(f_i)), where
        // f_i = pT,i / pTrecoil, F_i = f_i cos(Delta phi(i,recoil))
        // To do this before calculating pTrecoil, we could do
        // sum_i pT,i * cos(Delta phi(i,-lead))* log(pT,i / pT,lead)
        // which should for practical purposes be the same
        // Maybe safer here as originally defined, just careful with selection

        // Make sure selection here matches the one above for p4recoil
        p4.SetPtEtaPhiM(Jet_pt[i], Jet_eta[i], Jet_phi[i], Jet_mass[i]);
        if (i > 0 && p4.Pt() > 30. && fabs(p4.Eta()) < 2.5 &&
            DELTAPHI(p4.Phi(), p4lead.Phi()) > 1.0)
        {
          double pti = p4.Pt();
          double fi = pti / ptrecoil;
          double Fi = fi * cos(DELTAPHI(p4.Phi(), p4recoil.Phi()));
          logCrecoil += Fi * log(fi);

          if (doMultijet2Drecoil)
          {

            for (int itrg = 0; itrg != ntrg; ++itrg)
            {

              string &trg = vtrg[itrg];
              if (!(*mtrg[trg]))
                continue;

              multijetHistos *h = mhmj[trg];

              // Assumption is that sum_i F_i = 1, but should check?
              h->h2recoila->Fill(ptavp3, pti, w * Fi);
              h->h2recoilm->Fill(ptave, pti, w * Fi);
              h->h2recoill->Fill(ptlead, pti, w * Fi);
              h->h2recoilr->Fill(ptrecoil, pti, w * Fi);

              if (doPFComposition)
              {
                h->ppt25->Fill(ptavp3, Jet_pt[i], w * Fi);
                h->prho25->Fill(ptavp3, rho, w * Fi);
                h->pchf25->Fill(ptavp3, Jet_chHEF[i], w * Fi);
                h->pnhf25->Fill(ptavp3, Jet_neHEF[i], w * Fi);
                h->pnef25->Fill(ptavp3, Jet_neEmEF[i], w * Fi);
                h->pcef25->Fill(ptavp3, Jet_chEmEF[i], w * Fi);
                h->pmuf25->Fill(ptavp3, Jet_muEF[i], w * Fi);
              } // doPFcomposition

            } // for itrg
          }   // doMultijet2Drecoil
        }     // good recoil jet
      }       // for i in injet
    }         // doMultijet
    double Crecoil = exp(logCrecoil);

    hnjet->Fill(njet, w);

    // Dijet pre-selection
    if (njet >= 2)
    {

      if (debugevent)
        cout << "Dijet analysis" << endl
             << flush;

      // Both leading jets act as tag and probe in turn
      for (int itag = 0; itag != 2; ++itag)
      {

        // Tag and probe jet selection
        int iprobe = (itag == 0 ? 1 : 0);
        p4t.SetPtEtaPhiM(Jet_pt[itag], Jet_eta[itag], Jet_phi[itag],
                         Jet_mass[itag]);
        p4p.SetPtEtaPhiM(Jet_pt[iprobe], Jet_eta[iprobe], Jet_phi[iprobe],
                         Jet_mass[iprobe]);

        // Dijet observables
        double eta = p4p.Eta();
        double pttag = p4t.Pt();
        double ptprobe = p4p.Pt();
        double ptave = 0.5 * (pttag + ptprobe);
        double asymm = (ptprobe - pttag) / ptave;

        double dphi = DELTAPHI(p4t.Phi(), p4p.Phi());
        double dr = p4t.DeltaR(p4p);

        // Proper bisector axis (equal angles to each jet)
        p4b.SetPtEtaPhiM(0, 0, 0, 0);
        p4bt.SetPtEtaPhiM(1, 0, p4t.Phi(), 0);
        p4bp.SetPtEtaPhiM(1, 0, p4p.Phi(), 0);
        p4b += p4bt;
        p4b -= p4bp;
        p4b.SetPtEtaPhiM(p4b.Pt(), 0., p4b.Phi(), 0.);
        p4b *= 1. / p4b.Pt();
        p4bx.SetPtEtaPhiM(p4b.Pt(), 0., p4b.Phi() + 0.5 * TMath::Pi(), 0.);

        // Average projection pT to bisector axis, pT,avp
        // as explained in JME-21-001 (HDM method: bisector extension)
        double ptavp2 = 0.5 * (p4t.Vect().Dot(p4b.Vect()) -
                               p4p.Vect().Dot(p4b.Vect()));

        double m0b = 1 + (p4m0.Vect().Dot(p4b.Vect())) / ptavp2;
        double m2b = 1 + (p4m2.Vect().Dot(p4b.Vect())) / ptavp2;
        double mnb = 0 + (p4mn.Vect().Dot(p4b.Vect())) / ptavp2;
        double mub = 0 + (p4mu.Vect().Dot(p4b.Vect())) / ptavp2;
        // double mob = 0 + (p4mo.Vect().Dot(p4b.Vect()))/ptavp;

        double m0bx = 1 + (p4m0.Vect().Dot(p4bx.Vect())) / ptavp2;
        double m2bx = 1 + (p4m2.Vect().Dot(p4bx.Vect())) / ptavp2;

        // Extras
        double cu = 1. / 0.92;
        double mnub = 0 + ((p4mn + cu * p4mu).Vect().Dot(p4b.Vect())) / ptavp2;
        double mnbx = 0 + (p4mn.Vect().Dot(p4bx.Vect())) / ptavp2;
        double mubx = 0 + (p4mu.Vect().Dot(p4bx.Vect())) / ptavp2;
        double mnubx = 0 + ((p4mn + cu * p4mu).Vect().Dot(p4bx.Vect())) / ptavp2;

        // bisector axis => dijet axis really (not equal angles)
        p4d.SetPtEtaPhiM(0, 0, 0, 0);
        p4d += p4t;
        p4d -= p4p;
        p4d.SetPtEtaPhiM(p4d.Pt(), 0., p4d.Phi(), 0.);
        p4d *= 1. / p4d.Pt();
        p4dx.SetPtEtaPhiM(p4d.Pt(), 0., p4d.Phi() + 0.5 * TMath::Pi(), 0.);

        double m0d = 1 + (p4m0.Vect().Dot(p4d.Vect())) / ptave;
        double m2d = 1 + (p4m2.Vect().Dot(p4d.Vect())) / ptave;
        double mnd = 0 + (p4mn.Vect().Dot(p4d.Vect())) / ptave;
        double mud = 0 + (p4mu.Vect().Dot(p4d.Vect())) / ptave;
        // double mod = 0 + (p4mo.Vect().Dot(p4d.Vect()))/ptave;

        double m0dx = 1 + (p4m0.Vect().Dot(p4dx.Vect())) / ptave;
        double m2dx = 1 + (p4m2.Vect().Dot(p4dx.Vect())) / ptave;

        // central axis + pttag norm&binning
        p4c.SetPtEtaPhiM(0, 0, 0, 0);
        p4c += p4t;
        p4c.SetPtEtaPhiM(p4c.Pt(), 0., p4c.Phi(), 0.);
        p4c *= 1. / p4c.Pt();
        p4cx.SetPtEtaPhiM(p4c.Pt(), 0., p4c.Phi() + 0.5 * TMath::Pi(), 0.);

        double m0c = 1 + (p4m0.Vect().Dot(p4c.Vect())) / pttag;
        double m2c = 1 + (p4m2.Vect().Dot(p4c.Vect())) / pttag;
        double mnc = 0 + (p4mn.Vect().Dot(p4c.Vect())) / pttag;
        double muc = 0 + (p4mu.Vect().Dot(p4c.Vect())) / pttag;
        // double moc = 0 + (p4mo.Vect().Dot(p4c.Vect()))/pttag;

        double m0cx = 1 + (p4m0.Vect().Dot(p4cx.Vect())) / pttag;
        double m2cx = 1 + (p4m2.Vect().Dot(p4cx.Vect())) / pttag;

        // forward axis ("backwards" to tag hemisphere) + ptprobe norm&binning
        p4f.SetPtEtaPhiM(0, 0, 0, 0);
        p4f -= p4p;
        p4f.SetPtEtaPhiM(p4f.Pt(), 0., p4f.Phi(), 0.);
        p4f *= 1. / p4f.Pt();
        p4fx.SetPtEtaPhiM(p4f.Pt(), 0., p4f.Phi() + 0.5 * TMath::Pi(), 0.);

        double m0f = 1 + (p4m0.Vect().Dot(p4f.Vect())) / ptprobe;
        double m2f = 1 + (p4m2.Vect().Dot(p4f.Vect())) / ptprobe;
        double mnf = 0 + (p4mn.Vect().Dot(p4f.Vect())) / ptprobe;
        double muf = 0 + (p4mu.Vect().Dot(p4f.Vect())) / ptprobe;
        // double mof = 0 + (p4mo.Vect().Dot(p4f.Vect()))/ptprobe;

        double m0fx = 1 + (p4m0.Vect().Dot(p4fx.Vect())) / ptprobe;
        double m2fx = 1 + (p4m2.Vect().Dot(p4fx.Vect())) / ptprobe;

        // Dijet mass
        p4dj = p4t;
        p4dj += p4p;
        double mjj = p4dj.M();
        double deta = fabs(p4p.Eta() - p4t.Eta());

        bool isdijet = (fabs(p4t.Eta()) < 1.3 && dphi > 2.7 &&
                        fabs(asymm) < maxa && //!
                        p4t.Pt() > 15. && Jet_jetId[itag] >= 4 &&
                        p4p.Pt() > 15. && Jet_jetId[iprobe] >= 4 &&
                        !Jet_jetveto[itag] && !Jet_jetveto[iprobe] && //!
                        pass_METfilter > 0);
        // DESY selection. Note tighter asymmetry cut and allJetsGood
        bool isdijet2 = (fabs(p4t.Eta()) < 1.3 && dphi > 2.7 &&
                         fabs((pttag - ptprobe) / (pttag + ptprobe)) < 0.7 && //!
                         // fabs(asymm)<maxa && //!
                         p4t.Pt() > 15. && Jet_jetId[itag] >= 4 &&
                         p4p.Pt() > 15. && Jet_jetId[iprobe] >= 4 &&
                         //! Jet_jetveto[itag] && !Jet_jetveto[iprobe] && //!
                         allJetsGood && //!
                         pass_METfilter > 0);

        for (int itrg = 0; itrg != ntrg; ++itrg)
        {

          if (debugevent)
            cout << "Check trigger #" << itrg << " for dijet "
                 << endl
                 << flush;

          string &trg = vtrg[itrg];
          if (!(*mtrg[trg]))
            continue;

          if (doJetveto && isdijet)
          {

            jetvetoHistos *h = mhjv[trg];

            if (doJetvetoVariants)
              h->h2ptaeta_all->Fill(eta, ptave, w);
            if (ptave >= h->ptmin && ptave < h->ptmax &&
                fabs(eta) >= h->absetamin && fabs(eta) < h->absetamax)
            {
              if (doJetvetoVariants)
                h->h2ptaeta_sel->Fill(eta, ptave, w);
              h->p2asymm->Fill(eta, p4p.Phi(), asymm, w);
              h->h2phieta_ave->Fill(eta, p4p.Phi(), w);
            }

            if (doJetvetoVariants)
            {
              if (doPFComposition && fabs(p4t.Eta()) < 1.3)
              {
                h->h2ptteta_all->Fill(eta, ptave, w);
                if (pttag >= h->ptmin && pttag < h->ptmax)
                {
                  h->h2ptteta_sel->Fill(eta, pttag, w);
                  h->h2phieta_tag->Fill(eta, p4.Phi(), w);
                  h->p2chftp->Fill(eta, p4p.Phi(), Jet_chHEF[iprobe], w);
                  h->p2nhftp->Fill(eta, p4p.Phi(), Jet_neHEF[iprobe], w);
                  h->p2neftp->Fill(eta, p4p.Phi(), Jet_neEmEF[iprobe], w);
                }
              }
            }
          } // doJetveto

          if (doDijet && isdijet)
          {

            dijetHistos *h = mhdj[trg];
            double res = Jet_RES[iprobe] / Jet_RES[itag];

            h->h2pteta_aball->Fill(eta, ptavp2, w);
            h->h2pteta_adall->Fill(eta, ptave, w);
            h->h2pteta_tcall->Fill(eta, pttag, w);
            h->h2pteta_pfall->Fill(eta, ptprobe, w);

            // Bisector (proper)
            if (ptavp2 >= h->ptmin && ptavp2 < h->ptmax &&
                fabs(eta) >= h->absetamin && fabs(eta) < h->absetamax)
            {
              h->h2pteta_absel->Fill(eta, ptavp2, w);
            }
            { // Bisector (proper)
              if (doDijetJER)
              {
                h->p2m0->Fill(eta, ptavp2, m0b, w);
                h->p2m0x->Fill(eta, ptavp2, m0bx, w);
                h->p2m2->Fill(eta, ptavp2, m2b, w);
                h->p2m2x->Fill(eta, ptavp2, m2bx, w);
              }
              if (doPFComposition)
              {
                h->p2pt->Fill(eta, ptavp2, Jet_pt[iprobe], w);
                h->p2rho->Fill(eta, ptavp2, rho, w);
                h->p2chf->Fill(eta, ptavp2, Jet_chHEF[iprobe], w);
                h->p2nhf->Fill(eta, ptavp2, Jet_neHEF[iprobe], w);
                h->p2nef->Fill(eta, ptavp2, Jet_neEmEF[iprobe], w);
                h->p2cef->Fill(eta, ptavp2, Jet_chEmEF[iprobe], w);
                h->p2muf->Fill(eta, ptavp2, Jet_muEF[iprobe], w);

                h->ppt13->Fill(ptavp2, Jet_pt[itag], w);
                h->prho13->Fill(ptavp2, rho, w);
                h->pchf13->Fill(ptavp2, Jet_chHEF[itag], w);
                h->pnhf13->Fill(ptavp2, Jet_neHEF[itag], w);
                h->pnef13->Fill(ptavp2, Jet_neEmEF[itag], w);
                h->pcef13->Fill(ptavp2, Jet_chEmEF[itag], w);
                h->pmuf13->Fill(ptavp2, Jet_muEF[itag], w);
              }

              h->p2resab->Fill(eta, ptavp2, res, w);
              h->p2m0ab->Fill(eta, ptavp2, m0b, w);
              h->p2m2ab->Fill(eta, ptavp2, m2b, w);
              h->p2mnab->Fill(eta, ptavp2, mnb, w);
              h->p2muab->Fill(eta, ptavp2, mub, w);
            }
            // Dijet axis
            if (ptave >= h->ptmin && ptave < h->ptmax &&
                fabs(eta) >= h->absetamin && fabs(eta) < h->absetamax)
            {
              h->h2pteta_adsel->Fill(eta, ptave, w);
            }
            { // Dijet axis
              h->p2resad->Fill(eta, ptave, res, w);
              h->p2m0ad->Fill(eta, ptave, m0d, w);
              h->p2m2ad->Fill(eta, ptave, m2d, w);
              h->p2mnad->Fill(eta, ptave, mnd, w);
              h->p2muad->Fill(eta, ptave, mud, w);
            }
            // Tag jet axis
            if (pttag >= h->ptmin && pttag < h->ptmax)
            {
              h->h2pteta_tcsel->Fill(eta, pttag, w);
            }
            // Tag jet axis
            {
              h->p2restc->Fill(eta, pttag, res, w);
              h->p2m0tc->Fill(eta, pttag, m0c, w);
              h->p2m2tc->Fill(eta, pttag, m2c, w);
              h->p2mntc->Fill(eta, pttag, mnc, w);
              h->p2mutc->Fill(eta, pttag, muc, w);
            }
            // Probe jet axis
            if (ptprobe >= h->ptmin && ptprobe < h->ptmax)
            {
              h->h2pteta_pfsel->Fill(eta, ptprobe, w);
            }
            // Probe jet axis
            {
              h->p2respf->Fill(eta, ptprobe, res, w);
              h->p2m0pf->Fill(eta, ptprobe, m0f, w);
              h->p2m2pf->Fill(eta, ptprobe, m2f, w);
              h->p2mnpf->Fill(eta, ptprobe, mnf, w);
              h->p2mupf->Fill(eta, ptprobe, muf, w);
            }
          } // doDijet

          if (doDijet2 && isdijet2)
          {

            dijetHistos2 *h = mhdj2[trg];
            double res = Jet_RES[iprobe] / Jet_RES[itag];
            double jsf = (smearJets && Jet_CF[itag] > 0 ? Jet_CF[iprobe] / Jet_CF[itag] : 1);

            double abseta = fabs(eta);
            h->h2pteta->Fill(abseta, ptavp2, w);

            h->p2res->Fill(abseta, ptavp2, res, w);
            h->p2jsf->Fill(abseta, ptavp2, jsf, w);
            h->p2m0->Fill(abseta, ptavp2, m0b, w);
            h->p2m2->Fill(abseta, ptavp2, m2b, w);
            h->p2mn->Fill(abseta, ptavp2, mnb, w);
            h->p2mu->Fill(abseta, ptavp2, mub, w);

            h->p2m0x->Fill(abseta, ptavp2, m0bx, w);
            h->p2m2x->Fill(abseta, ptavp2, m2bx, w);

            // Extras for FSR studies
            h->p2mnu->Fill(abseta, ptavp2, mnub, w);
            h->p2mnx->Fill(abseta, ptavp2, mnbx, w);
            h->p2mux->Fill(abseta, ptavp2, mubx, w);
            h->p2mnux->Fill(abseta, ptavp2, mnubx, w);

            h->h2ptetatc->Fill(abseta, pttag, w);
            h->p2restc->Fill(abseta, pttag, res, w);
            h->p2jsftc->Fill(abseta, pttag, jsf, w);
            h->p2m0tc->Fill(abseta, pttag, m0c, w);
            h->p2m2tc->Fill(abseta, pttag, m2c, w);
            h->p2mntc->Fill(abseta, pttag, mnc, w);
            h->p2mutc->Fill(abseta, pttag, muc, w);

            h->h2ptetapf->Fill(abseta, ptprobe, w);
            h->p2respf->Fill(abseta, ptprobe, res, w);
            h->p2jsfpf->Fill(abseta, ptprobe, jsf, w);
            h->p2m0pf->Fill(abseta, ptprobe, m0f, w);
            h->p2m2pf->Fill(abseta, ptprobe, m2f, w);
            h->p2mnpf->Fill(abseta, ptprobe, mnf, w);
            h->p2mupf->Fill(abseta, ptprobe, muf, w);
          } // doDijet2

        } // for itrg

        // Dijet without deltaphi cut
        if (fabs(p4t.Eta() < 1.3) && fabs(asymm) < maxa)
        {

          if (ptave >= 40)
          {
            h2dphi->Fill(p4p.Eta(), dphi, w);
          }
        }
      } // for itag
    }   // njet>=2

    // Multijet selection
    if (ismultijet && doMultijet)
    {

      if (debugevent)
        cout << "Analyze multijet" << endl
             << flush;

      // pTave binning
      double ptlead = p4lead.Pt();
      double ptrecoil = p4recoil.Pt();
      double ptave = 0.5 * (ptlead + ptrecoil);
      // double ptavp3 defined earlier, as is p4b3

      // Projection to transverse plane (is this necessary?)
      p4m0.SetPtEtaPhiM(p4m0.Pt(), 0., p4m0.Phi(), 0.);
      p4m3.SetPtEtaPhiM(p4m3.Pt(), 0., p4m3.Phi(), 0.);
      p4mn3.SetPtEtaPhiM(p4mn3.Pt(), 0., p4mn3.Phi(), 0.);

      // Bisector axis p4b3 defined earlier (equal angles)
      double m0b = 1 + (p4m0.Vect().Dot(p4b3.Vect())) / ptave;
      double m3b = 1 + (p4m3.Vect().Dot(p4b3.Vect())) / ptave;
      double mnb = 0 + (p4mn3.Vect().Dot(p4b3.Vect())) / ptave;
      double mub = 0 + (p4mu3.Vect().Dot(p4b3.Vect())) / ptave;

      // Dijet axis (not equal angles)
      p4m.SetPtEtaPhiM(0, 0, 0, 0);
      p4m -= p4lead;
      p4m += p4recoil;
      p4m.SetPtEtaPhiM(p4m.Pt(), 0., p4m.Phi(), 0.);
      p4m *= 1. / p4m.Pt();

      double m0m = 1 + (p4m0.Vect().Dot(p4m.Vect())) / ptave;
      double m3m = 1 + (p4m3.Vect().Dot(p4m.Vect())) / ptave;
      double mnm = 0 + (p4mn3.Vect().Dot(p4m.Vect())) / ptave;
      double mum = 0 + (p4mu3.Vect().Dot(p4m.Vect())) / ptave;

      p4l.SetPtEtaPhiM(0, 0, 0, 0);
      p4l -= p4lead;
      p4l.SetPtEtaPhiM(p4l.Pt(), 0., p4l.Phi(), 0.);
      p4l *= 1. / p4l.Pt();

      double m0l = 1 + (p4m0.Vect().Dot(p4l.Vect())) / ptlead;
      double m3l = 1 + (p4m3.Vect().Dot(p4l.Vect())) / ptlead;
      double mnl = 0 + (p4mn3.Vect().Dot(p4l.Vect())) / ptlead;
      double mul = 0 + (p4mu3.Vect().Dot(p4l.Vect())) / ptlead;

      p4r.SetPtEtaPhiM(0, 0, 0, 0);
      p4r += p4recoil;
      p4r.SetPtEtaPhiM(p4r.Pt(), 0., p4r.Phi(), 0.);
      p4r *= 1. / p4r.Pt();

      double m0r = 1 + (p4m0.Vect().Dot(p4r.Vect())) / ptrecoil;
      double m3r = 1 + (p4m3.Vect().Dot(p4r.Vect())) / ptrecoil;
      double mnr = 0 + (p4mn3.Vect().Dot(p4r.Vect())) / ptrecoil;
      double mur = 0 + (p4mu3.Vect().Dot(p4r.Vect())) / ptrecoil;

      for (int itrg = 0; itrg != ntrg; ++itrg)
      {

        string &trg = vtrg[itrg];
        if (!(*mtrg[trg]))
          continue;

        multijetHistos *h = mhmj[trg];

        h->hpta_all->Fill(ptavp3, w);
        h->hptm_all->Fill(ptave, w);
        h->hptl_all->Fill(ptlead, w);
        h->hptr_all->Fill(ptrecoil, w);

        if (ptavp3 >= h->ptmin && ptavp3 < h->ptmax)
          h->hpta_sel->Fill(ptavp3, w);
        if (ptave >= h->ptmin && ptave < h->ptmax)
          h->hptm_sel->Fill(ptave, w);
        if (ptlead >= h->ptmin && ptlead < h->ptmax)
          h->hptl_sel->Fill(ptlead, w);
        if (ptrecoil >= h->ptmin && ptrecoil < h->ptmax)
          h->hptr_sel->Fill(ptrecoil, w);

        double res = (p4leadRES.Pt() / p4recoilRES.Pt()) /
                     (p4lead.Pt() / p4recoil.Pt());
        h->presa->Fill(ptavp3, res, w);
        h->presm->Fill(ptave, res, w);
        h->presl->Fill(ptlead, res, w);
        h->presr->Fill(ptrecoil, res, w);

        h->ptleada->Fill(ptavp3, ptlead, w);
        h->ptleadm->Fill(ptave, ptlead, w);
        h->ptleadl->Fill(ptlead, ptlead, w);
        h->ptleadr->Fill(ptrecoil, ptlead, w);

        h->pcrecoila->Fill(ptavp3, Crecoil, w);
        h->pcrecoilm->Fill(ptave, Crecoil, w);
        h->pcrecoill->Fill(ptlead, Crecoil, w);
        h->pcrecoilr->Fill(ptrecoil, Crecoil, w);

        h->pm0a->Fill(ptavp3, m0b, w);
        h->pm2a->Fill(ptavp3, m3b, w);
        h->pmna->Fill(ptavp3, mnb, w);
        h->pmua->Fill(ptavp3, mub, w);

        h->pm0m->Fill(ptave, m0m, w);
        h->pm2m->Fill(ptave, m3m, w);
        h->pmnm->Fill(ptave, mnm, w);
        h->pmum->Fill(ptave, mum, w);

        h->pm0l->Fill(ptlead, m0l, w);
        h->pm2l->Fill(ptlead, m3l, w);
        h->pmnl->Fill(ptlead, mnl, w);
        h->pmul->Fill(ptlead, mul, w);

        h->pm0r->Fill(ptrecoil, m0r, w);
        h->pm2r->Fill(ptrecoil, m3r, w);
        h->pmnr->Fill(ptrecoil, mnr, w);
        h->pmur->Fill(ptrecoil, mur, w);

        if (doMultijetControl)
        {
          h->h2m0a->Fill(ptavp3, m0b, w);
          h->h2m2a->Fill(ptavp3, m3b, w);
          if (ptave > 1.25 * h->trgpt)
            h->hcosdphi->Fill(cos(DELTAPHI(p4lead.Phi(), p4recoil.Phi())), w);
        }

        if (doPFComposition)
        {
          h->ppt13->Fill(ptavp3, Jet_pt[0], w);
          h->prho13->Fill(ptavp3, rho, w);
          h->pchf13->Fill(ptavp3, Jet_chHEF[0], w);
          h->pnhf13->Fill(ptavp3, Jet_neHEF[0], w);
          h->pnef13->Fill(ptavp3, Jet_neEmEF[0], w);
          h->pcef13->Fill(ptavp3, Jet_chEmEF[0], w);
          h->pmuf13->Fill(ptavp3, Jet_muEF[0], w);
        } // doPFcomposition

      } // for itrg
    }   // ismultijet

    // Lumi
    if (dolumi && mrunls[run][luminosityBlock] == 0)
    {
      // DOES THIS WORK FOR ALL THE TRIGGERS?
      // WHAT IS THE INFORMATION WE'RE INTERESTED IN?
      for (int itrg = 0; itrg != ntrg; ++itrg)
      {

        string &trg = vtrg[itrg];
        if (!(*mtrg[trg]))
          continue;

        lumiHistos *h = mhlumi[trg];
        float trpu = _avgpu[run][luminosityBlock];

        if (debugevent)
        {
          cout << "Analyze lumi" << endl
               << flush;
        }
        float lum = _lums[run][luminosityBlock];
        float lum2 = _lums2[run][luminosityBlock];
        h->lum += lum; // /prescale
        h->lum2 += lum2; // /prescale
        // TODO:
        // PRESCALE INFORMATION
        /*
        double prescale(0);
        auto ip = _prescales[h->trigname].find(run);
        if (ip==_prescales[h->trigname].end()) {
          PrintInfo(Form("No prescale info for trigger %s in run %d!",h->trigname.c_str(),run));
          assert(false);
        } else {
          prescale = ip->second;
          if (prescale==0) {
            PrintInfo(Form("Prescale zero for trigger %s in run %d!",h->trigname.c_str(),run));
            prescale = 1.;
            assert(false);
          }
        }
        */

        h->htrglumi->Fill(lum, w); //  / prescale
        h->htrgpu->Fill(trpu, w);
        h->hnpv->Fill(PV_npvs, w);
        h->hnpvgood->Fill(PV_npvsGood, w);

        h_trgvslumi->Fill(itrg, lum, w);
        h_trgvspu->Fill(itrg, trpu, w);
      }
      mrunls[run][luminosityBlock] = 1;
    } // doLumi

    h2mhtvsmet->Fill(p4t1met.Pt(), p4mht.Pt(), w);
  } // for jentry
  cout << endl
       << flush;

  cout << "Finished looping over " << nevt << " of which " << _ngoodevts
       << " passed trigger. Start writing file." << endl
       << flush;
  fout->Write();
  fout->Close();
  cout << "File written and closed." << endl
       << flush;

  if (doJSON)
    cout << Form("Found %d bad events according to new JSON (events cut)", _nbadevts_json) << endl;
  if (doTrigger)
  {
    cout << Form("Found %d bad events according to trigger bits (events cut)", _nbadevts_trg) << endl;
    cout << Form("Found %d bad events not in fwd trigger phase space (events cut)", _nbadevts_fwdtrg) << endl;
  }

  cout << "Processed " << nrun << " runs, "
       << nls << " luminosity blocks and " << nevt << " events" << endl;
  cout << "Saving these to file rootfiles/jmenano.json for brilcalc" << endl;

  ofstream fjson(Form("rootfiles/%s/jmenano_%s_%s.json",
                      version.c_str(),
                      dataset.c_str(), version.c_str()));
  fjson << "{" << endl;
  for (map<int, map<int, int>>::iterator it = mrunls.begin();
       it != mrunls.end(); ++it)
  {

    int run = it->first;
    int ls_prev(0), ls(0), ok(0);
    bool firstblock(true), newblock(true);

    if (it != mrunls.begin())
      fjson << "," << endl;
    fjson << "  \"" << run << "\": [";
    for (map<int, int>::iterator jt = it->second.begin();
         jt != it->second.end(); ++jt)
    {

      ok = jt->second;
      if (ok)
      {
        ls_prev = ls;
        ls = jt->first;
      }
      else
        continue;

      newblock = (firstblock || (ls - ls_prev > 1));
      if (newblock && ok)
      {
        if (firstblock)
        {
          fjson << "[" << ls << ", ";
          firstblock = false;
        }
        else
        {
          fjson << ls_prev << "], [" << ls << ", ";
        }
      }
    } // for jt
    fjson << ls << "]]";
  } // for it
  fjson << "}" << endl;

  cout << Form("Analyzed %d events", _ngoodevts) << endl;
  cout << "Saving these to " << fout->GetName() << " for drawJMENANO.C" << endl;



  // h2mhtvsmet->Draw("COLZ");
} // Loop()

// Code originally from jetphys/HistosFill.C
void DijetHistosFill::PrintInfo(string info, bool printcout)
{
  //*ferr << info << endl << flush;
  if (printcout)
    cout << info << endl
         << flush;
}

// Load luminosity information
// TODO:
// Currently no good runs are defined
bool DijetHistosFill::LoadLumi()
{
  // For calculating luminosity on the fly based on .csv file and take only events with non-zero luminosity

  const char *lumifile = getLumifile(dataset.c_str());

  PrintInfo(string("Processing LoadLumi() with ") + lumifile + "...", true);

  // Check lumi against the list of good runs
  const int a_goodruns[] = {};
  const int ngoodruns = sizeof(a_goodruns) / sizeof(a_goodruns[0]);
  set<int> goodruns;
  if (ngoodruns > 0)
  { // This is an old remnant
    for (int runidx = 0; runidx != ngoodruns; ++runidx)
      goodruns.insert(a_goodruns[runidx]);

    for (auto runit = goodruns.begin(); runit != goodruns.end(); ++runit)
      cout << *runit << ", ";
    cout << endl;
  }
  set<pair<int, int>> nolums;

  ifstream f(lumifile, ios::in);
  if (!f.is_open())
    return false;
  float secLS = 2.3310e+01;
  string s;
  int rn, fill, ls, ifoo;
  float del, rec, avgpu, energy;
  char sfoo[512];
  bool getsuccess1 = static_cast<bool>(getline(f, s, '\n'));
  if (!getsuccess1)
    return false;
  PrintInfo(string("\nstring: ") + s + " !", true);

  // HOX: the lumi file format has been changing. Change the conditions when needed.
  if (s != "#Data tag : 23v1 , Norm tag: None")
    return false;

  bool getsuccess2 = static_cast<bool>(getline(f, s, '\n'));
  if (!getsuccess2)
    return false;
  PrintInfo(string("\nstring: ") + s + " !", true);
  if (s != "#run:fill,ls,time,beamstatus,E(GeV),delivered(/ub),recorded(/ub),avgpu,source")
    return false;

  int nls(0);
  double lumsum(0);
  double lumsum_good(0);
  double lumsum_json(0);
  bool skip(false);
  while (getline(f, s, '\n'))
  {
    // Skip if not STABLE BEAMS or wrong number of arguments
    // STABLE BEAMS alts: ADJUST, BEAM DUMP, FLAT TOP, INJECTION PHYSICS BEAM, N/A, RAMP DOWN, SETUP, SQUEEZE
    if (sscanf(s.c_str(), "%d:%d,%d:%d,%d/%d/%d %d:%d:%d,STABLE BEAMS,%f,%f,%f,%f,%s",
               &rn, &fill, &ls, &ifoo, &ifoo, &ifoo, &ifoo, &ifoo, &ifoo, &ifoo, &energy, &del, &rec, &avgpu, sfoo) != 15)
      skip = true;

    if (debugevent)
      PrintInfo(Form("Run %d ls %d lumi %f/pb", rn, ls, rec * 1e-6), true);

    if (skip)
    { // The user should know if this happens, since we can choose to use only STABLE BEAMS
      if (skip)
        PrintInfo(string("Skipping line (effects the recorded lumi):\n") + s, true);
      skip = false;
      continue;
    }

    if (_lums[rn][ls] != 0)
      return false;
    if (_avgpu[rn][ls] != 0)
      return false;
    // lumiCalc.py returns lumi in units of mub-1 (=>nb-1=>pb-1)
    double lum = rec * 1e-6;
    double lum2 = del * 1e-6;
    if (lum == 0 and goodruns.find(rn) != goodruns.end() and (_json[rn][ls] == 1)) // The second condition had !jp::dojson or
      nolums.insert(pair<int, int>(rn, ls));

    _avgpu[rn][ls] = avgpu * 69000. / 80000.; // brilcalc --minBiasXsec patch
    _lums[rn][ls] = lum;
    _lums2[rn][ls] = lum2;
    lumsum += lum;
    if (goodruns.find(rn) != goodruns.end()) // Apr 17
      lumsum_good += lum;
    if ((_json[rn][ls]))
      lumsum_json += lum;
    ++nls;
    if (nls > 100000000)
      return false;
  }

  PrintInfo(Form("Called LoadLumi() with %s:\nLoaded %lu runs with %d lumi sections containing %f"
                 " pb-1 of data,\n of which %f pb-1 is in good runs (%f%%)\nThis corresponds to %f"
                 " hours of data-taking\nThe JSON file contains %f pb-1 (%f%%)",
                 lumifile, _lums.size(), nls, lumsum, lumsum_good,
                 100. * lumsum_good / lumsum, nls * secLS / 3600, lumsum_json, 100. * lumsum_json / lumsum),
            true);

  // Report any empty lumi section
  if (nolums.size() != 0)
  {
    PrintInfo(Form("Warning, found %lu non-normalizable LS:", nolums.size()), true);
    for (auto lumit = nolums.begin(); lumit != nolums.end(); ++lumit)
    {
      cout << " [" << lumit->first << "," << lumit->second;
      auto lumit2 = lumit;
      ++lumit2;
      if (lumit2->first != lumit->first or lumit2->second != lumit->second + 1)
        cout << "]";
      else
      {
        for (int lumadd = 0; lumit2 != nolums.end() and lumit2->first == lumit->first and
                             lumit2->second == lumit->second + lumadd + 1;
             ++lumadd, ++lumit2)
        {
        };
        lumit = --lumit2;
        cout << "-" << lumit->second << "]";
      }
    } // for lumit
    cout << endl;
  } // nolums

  cout << endl;
  return true;
} // LoadLumi

// Code originally from jetphys/HistosFill.C
bool DijetHistosFill::LoadJSON(string json)
{
  PrintInfo(string("Processing LoadJSON() with ") + json + " ...", true);
  ifstream file(json, ios::in);
  if (!file.is_open())
  {
    assert(false);
    return false;
  }
  char c;
  string s, s2, s3;
  char s1[256];
  int rn(0), ls1(0), ls2(0), nrun(0), nls(0);
  file.get(c);
  if (c != '{')
    return false;
  while (file >> s and sscanf(s.c_str(), "\"%d\":", &rn) == 1)
  {
    if (_dh_debug)
      PrintInfo(Form("\"%d\": ", rn), true);

    while (file.get(c) and c == ' ')
    {
    };
    if (_dh_debug)
    {
      PrintInfo(Form("%c", c), true);
      assert(c == '[');
    }
    ++nrun;

    bool endrun = false;
    while (!endrun and file >> s >> s2 and (sscanf((s + s2).c_str(), "[%d,%d]%s", &ls1, &ls2, s1) == 3 or (file >> s3 and sscanf((s + s2 + s3).c_str(), "[%d,%d]%s", &ls1, &ls2, s1) == 3)))
    {

      s2 = s1;
      if (s2 == "]")
      {
        file >> s3;
        s2 += s3;
      }

      if (_dh_debug)
        PrintInfo(Form("[%d,%d,'%s']", ls1, ls2, s1), true);

      for (int ls = ls1; ls != ls2 + 1; ++ls)
      {
        _json[rn][ls] = 1;
        ++nls;
      }

      endrun = (s2 == "]," || s2 == "]}");
      if (_dh_debug and !endrun and s2 != ",")
      {
        PrintInfo(string("s1: ") + s2, true);
        assert(s2 == ",");
      }
    } // while ls
    if (_dh_debug)
      PrintInfo("", true);

    if (s2 == "]}")
      continue;
    else if (_dh_debug and s2 != "],")
      PrintInfo(string("s2: ") + s2, true);
    assert(s2 == "],");
  } // while run
  if (s2 != "]}")
  {
    PrintInfo(string("s3: ") + s2, true);
    return false;
  }

  PrintInfo(string("Called LoadJSON() with ") + json + ":", true);
  PrintInfo(Form("Loaded %d good runs and %d good lumi sections", nrun, nls), true);
  return true;
} // LoadJSON

/*
bool DijetHistosFill::LoadJSON()
{
    // Get the JSON files from here:
    // - /eos/user/c/cmsdqm/www/CAF/certification/Collisions22/

    // Golden 1.44/fb
    // string json = "rootfiles/Cert_Collisions2022_355100_356615_Golden.json";
    // Golden JSON, 4.86/fb
    //string json = "rootfiles/Cert_Collisions2022_355100_357550_Golden..json";
    // Golden JSON, 7.67/fb
    //string json = "rootfiles/Cert_Collisions2022_355100_357900_Golden.json";
    // Golden JSON BCDEF, 9.71/fb
    //string json = "rootfiles/Cert_Collisions2022_355100_359812_Golden.json";
    // Golden JSON BCDEF, 14.6/fb
    string json = "rootfiles/Cert_Collisions2022_355100_360491_Golden.json";
    // Golden JSON RunB, 0.0846/fb
    //string json = "rootfiles/Cert_Collisions2022_eraB_355100_355769_Golden.json";
    // Golden JSON RunC, 4.84/fb
    //string json = "rootfiles/Cert_Collisions2022_eraC_355862_357482_Golden.json"
    // Golden JSON RunD, 2.74/fb
    //string json = "rootfiles/Cert_Collisions2022_eraD_357538_357900_Golden.json";
    if (isRun2==1 || isRun2==2)
      json="rootfiles/Cert_271036-284044_13TeV_Legacy2016_Collisions16_JSON.txt";
    if (isRun2==3)
      json="rootfiles/Cert_294927-306462_13TeV_UL2017_Collisions17_GoldenJSON.txt";
    if (isRun2==4)
      json="rootfiles/Cert_314472-325175_13TeV_Legacy2018_Collisions18_JSON.txt";

    if (TString(dataset.c_str()).Contains("2022"))
      json = "rootfiles/Cert_Collisions2022_355100_362760_Golden.json";
    if (TString(dataset.c_str()).Contains("2023"))
      json = "rootfiles/Cert_Collisions2023_366442_370790_Golden.json";

  cout << "Processing LoadJSON() with " + json + " ..." << flush;
  ifstream file(json, ios::in);
  if (!file.is_open()) return false;
  char c;
  string s, s2;
  char s1[256];
  int rn(0), ls1(0), ls2(0), nrun(0), nls(0);
  file.get(c);
  if (c!='{') return false;
  while (file >> s and sscanf(s.c_str(),"\"%d\":",&rn)==1) {
    if (debug) cout << Form("\"%d\": ",rn);

    while (file.get(c) and c==' ') {};
    if (debug) { cout << Form("%c",c) << flush; assert(c=='['); }
    ++nrun;

    bool endrun = false;
    while (!endrun and file >> s >> s2 and sscanf((s+s2).c_str(),"[%d,%d]%s",&ls1,&ls2,s1)==3) {
      if (debug) cout << Form("[%d,%d,%s]",ls1,ls2,s1);

      for (int ls = ls1; ls != ls2+1; ++ls) {
        _json[rn][ls] = 1;
        ++nls;
      }

      s2 = s1;
      endrun = (s2=="]," || s2=="]}");
      if (debug and !endrun and s2!=",") { cout << string("s1: ")+s2 << endl << flush; assert(s2==","); }
    } // while ls
    if (debug) cout << endl;

    if (s2=="]}") continue;
    else if (debug and s2!="],") cout << string("s2: ")+s2 << endl << flush;
    assert(s2=="],");
  } // while run
  //if (s2!="]}") { PrintInfo(string("s3: ")+s2,true); return false; }
  if (s2!="]}") { cout <<  string("s3: ")+s2 << endl; return false; }

  cout << string("\nCalled LoadJSON() with ") + json + ":" << endl;
  cout << Form("Loaded %d good runs and %d good lumi sections",nrun,nls) << endl;
  return true;
} // LoadJSON
*/
/*
bool HistosFill::LoadPUProfiles()
{
  string datafile = ""// jp::pudtpath + (do80 ? "80mb/" : "/") + jp::run + "/pileup_DT.root";
  // string mcfile   = jp::pumcpath + "/pileup_";
  // mcfile += ".root";

  PrintInfo(Form("Processing LoadPUProfiles() using %s and %s ...",datafile.c_str(),mcfile.c_str()),true);

  TDirectory *curdir = gDirectory;
  // Load pile-up files and hists from them
  TFile *f_pudist = new TFile(datafile.c_str(), "READ");
  if (!f_pudist or f_pudist->IsZombie()) { PrintInfo(string("Unable to read PU data file")+datafile,true); return false; }
  // TFile *fpumc = new TFile(mcfile.c_str(),"READ");
  // if (!fpumc or fpumc->IsZombie()) { PrintInfo(string("Unable to read PU MC file")+mcfile,true); return false; }


  // For MC, load the pileup distribution
  _pumc = dynamic_cast<TH1D*>(fpumc->Get("pileupmc")->Clone("pumchelp"));
  if (!_pumc) return false;
  double maxmcpu = _pumc->GetMaximum();
  _pumc->Scale(1.0/maxmcpu);
  int lomclim = _pumc->FindFirstBinAbove(0.01);
  int upmclim = _pumc->FindLastBinAbove (0.01);
  int maxmcbin = _pumc->FindFirstBinAbove(0.999);
  PrintInfo(Form("Maximum bin: %d for MC",maxmcbin),true);
  PrintInfo(Form("Hazardous pu below & above: %f, %f",_pumc->GetBinLowEdge(lomclim),_pumc->GetBinLowEdge(upmclim+1)),true);
  int nbinsmc = _pumc->GetNbinsX();
  int kmc = _pumc->FindBin(33); // Check that pu=33 occurs at the same place as for data


  // For data, load each trigger separately

  for (auto &t : vtrg) {
    TH1D *tmpPU0 = dynamic_cast<TH1D*>(f_pudist->Get(t));
    if (!tmpPU0) {
      PrintInfo(Form("The trigger %s was not found in the DT pileup file!",t),true);
      return false;
    }
    TH1D *tmpPU = dynamic_cast<TH1D*>(tmpPU0->Clone(Form("pu%s",t)));
    int nbinsdt = tmpPU->GetNbinsX();
    int kdt = tmpPU->FindBin(33); // Why bin 33?
    if (kdt!=kmc or nbinsdt!=nbinsmc) {
      PrintInfo("The pileup histogram dt vs mc binning or range do not match (dt left mc right):",true);
      PrintInfo(Form(" Bins: dt:%d mc:%d",nbinsdt,nbinsmc),true);
      PrintInfo(Form(" Pu=33 bin: dt:%d mc:%d",kdt,kmc),true);
      return false;
    }
    double maxdtpu = tmpPU->GetMaximum();
    int lodtlim    = tmpPU->FindFirstBinAbove(maxdtpu/100.0);
    int updtlim    = tmpPU->FindLastBinAbove (maxdtpu/100.0);
    int maxdtbin   = tmpPU->FindFirstBinAbove(0.999*maxdtpu);

    for (int bin = 0; bin < lomclim; ++bin) tmpPU->SetBinContent(bin,0.0); // Set fore-tail to zero
    for (int bin = upmclim+1; bin <= nbinsdt; ++bin) tmpPU->SetBinContent(bin,0.0); // Set aft-tail to zero

    PrintInfo(Form("Maximum bin: %d for DT trg %s",maxdtbin,t),true);
    PrintInfo(Form("Hazardous pu below & above: %f, %f",tmpPU->GetBinLowEdge(lodtlim),tmpPU->GetBinLowEdge(updtlim+1)),true);
    tmpPU->Divide(_pumc);
    // if (do80) _pudist80[t] = tmpPU;
    _pudist[t] = tmpPU;
  }
  PrintInfo("Finished processing pileup histos!",true);

  curdir->cd();
  return true;
} // LoadPUProfiles
*/
