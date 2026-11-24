// Compare 19Dec2023 vs 22Sep2023
// Only load a few branches (event ID, jet pt, eta, phi)
#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
//#include "ROOT/RVec.hxx"
//#include "ROOT/RVec.hxx"
//#include "c++/v1/vector"

#include "TH1D.h"
#include "TH2D.h"
#include "TH3D.h"
#include "TProfile.h"
#include "TProfile2D.h"
#include "TCanvas.h"
#include "TStyle.h"
#include "TLatex.h"
#include "TLegend.h"
#include "TLine.h"
#include "TMath.h"
#include "TStopwatch.h"

#include "CondFormats/JetMETObjects/interface/FactorizedJetCorrector.h"
#include "CondFormats/JetMETObjects/interface/JetCorrectorParameters.h"

#include "tools.h"
#include "tdrstyle_mod22.C"

#include <iostream>
#include <map>

using namespace std;
using namespace tools;

bool patchJESA = true;
bool patchJESB = false;

bool partialB = true; // faster for partialB
bool OneRun = false;//true; //for fast testing
bool doPFComposition = true;

class evtid {
private:
  UInt_t run_;//, ls_;
  ULong64_t evt_;
public :
  //evtid() : run_(0), ls_(0), evt_(0) {}
 evtid() : run_(0), evt_(0) {}
//evtid(UInt_t run, UInt_t ls, ULong64_t evt) : run_(run), ls_(ls), evt_(evt) {}
 evtid(UInt_t run, ULong64_t evt) : run_(run), evt_(evt) {}
  bool operator()(evtid const& a, evtid const& b) const {
    if (a.run_ < b.run_) return true;
    if (a.run_ > b.run_) return false;
    //if (a.ls_  < b.ls_)  return true;
    //if (a.ls_  > b.ls_)  return false;
    return (a.evt_ < b.evt_);
  }
  UInt_t run() const { return run_; }
  //UInt_t lbn() const { return ls_; }
  ULong64_t evt() const { return evt_; }
};

std::map<int, std::map<int, int> > _json;
bool LoadJSON(string json) {
  cout << "Processing LoadJSON() with " + json << endl << flush;
  ifstream file(json, ios::in);
  if (!file.is_open()) { assert(false); return false; }
  char c;
  string s, s2, s3;
  char s1[256];
  int rn(0), ls1(0), ls2(0), nrun(0), nls(0);
  file.get(c);
  if (c!='{') return false;
  while (file >> s and sscanf(s.c_str(),"\"%d\":",&rn)==1) {
    //if (_gh_debug) PrintInfo(Form("\"%d\": ",rn),true);

    while (file.get(c) and c==' ') {};
    //if (_gh_debug) { PrintInfo(Form("%c",c),true); assert(c=='['); }
    ++nrun;

    bool endrun = false;
    while (!endrun and file >> s >> s2 and (sscanf((s+s2).c_str(),"[%d,%d]%s",&ls1,&ls2,s1)==3 or (file >> s3 and sscanf((s+s2+s3).c_str(),"[%d,%d]%s",&ls1,&ls2,s1)==3))) {

      s2 = s1;
      if (s2=="]") { file >> s3; s2 += s3; }

      //if (_gh_debug) PrintInfo(Form("[%d,%d,'%s']",ls1,ls2,s1),true);

      for (int ls = ls1; ls != ls2+1; ++ls) {
        _json[rn][ls] = 1;
        ++nls;
      }

      endrun = (s2=="]," || s2=="]}");
      //if (_gh_debug and !endrun and s2!=",") { PrintInfo(string("s1: ")+s2,true); assert(s2==","); }
    } // while ls
    //if (_gh_debug) PrintInfo("",true);

    if (s2=="]}") continue;
    //else if (_gh_debug and s2!="],") PrintInfo(string("s2: ")+s2,true);
    assert(s2=="],");
  } // while run
  //if (s2!="]}") { PrintInfo(string("s3: ")+s2,true); return false; }
  if (s2!="]}") { return false; }

  cout << "Called LoadJSON() with " << json << endl;
  cout << Form("Loaded %d good runs and %d good lumi sections\n",nrun,nls);
  return true;
} // LoadJSON


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


// Factorized from DijetHistosFill logic for now and only 2022/2023 data
FactorizedJetCorrector *selectJECEra(string dataset) {

  FactorizedJetCorrector *jec(0);
  // 2022
  //  Align JECs with
  //  https://indico.cern.ch/event/1335203/#7-update-on-l2res-for-2022-rer
  if (dataset == "2022C" || dataset== "2022D") {
    jec = getFJC("", "Summer22Run3_V1_MC_L2Relative",
                 "Summer22-22Sep2023_Run2022CD_V3_DATA_L2L3Residual");
  }
  if (dataset == "2022E") {
    jec = getFJC("", "Summer22EEVetoRun3_V1_MC_L2Relative",
                 "Summer22EE-22Sep2023_Run2022E_V3_DATA_L2L3Residual");
  }
  if (dataset == "2022F") {
    jec = getFJC("", "Summer22EEVetoRun3_V1_MC_L2Relative",
                 "Summer22EEPrompt22_Run2022F_V3_DATA_L2L3Residual");
  }
  if (dataset == "2022G") {
    jec = getFJC("", "Summer22EEVetoRun3_V1_MC_L2Relative",
                 "Summer22EEPrompt22_Run2022G_V3_DATA_L2L3Residual");
  }

  // 2023
  if (dataset == "2023Cv123") {
    jec = getFJC("", "Summer22Run3_V1_MC_L2Relative",
		 "Summer22Prompt23_Run2023Cv123_V3_DATA_L2L3Residual");
  }
  if (dataset == "2023Cv4") {
    jec = getFJC("", "Summer22Run3_V1_MC_L2Relative",
                 "Summer22Prompt23_Run2023Cv4_V3_DATA_L2L3Residual");
  }
  if (dataset == "2023C") {
    // quick fix in order to process Dec19 Run C which is not split. Use v123
    jec = getFJC("", "Summer22Run3_V1_MC_L2Relative",
                 "Summer22Prompt23_Run2023Cv123_V3_DATA_L2L3Residual");
  }

  if (dataset == "2023D") {
    jec = getFJC("",
                 "Summer22Run3_V1_MC_L2Relative",
                 "Summer22Prompt23_Run2023D_V3_DATA_L2L3Residual");
  }

  assert(jec);
  return jec;
}

// Get jet veto map
TH2D *getJVM(string dataset) {

  TFile *fjv(0);
  if (dataset == "2022C" || dataset == "2022D") {
    fjv = new TFile("files/jetveto2022CD.root", "READ");
  }
  if (dataset == "2022E" || dataset == "2022F" || dataset == "2022G") {
    fjv = new TFile("files/jetveto2022EFG.root", "READ");
  }
  if (dataset == "2023C" || dataset == "2023Cv123" || dataset == "2023Cv4") {
    fjv = new TFile("files/jetveto2023BC.root", "READ");
  }
  if (dataset == "2023D") {
    fjv = new TFile("files/jetveto2023D.root", "READ");
  }
  assert(fjv);
  
  TH2D *h2jv(0);
  h2jv = (TH2D*)fjv->Get("jetvetomap");
  
  assert(h2jv);
  return h2jv;
}


void compareLiteHLT(string run="2023D") {

  TDirectory *curdir = gDirectory;
  setTDRStyle();
  const char *crun = run.c_str();

  cout << endl << "Processing Run" << run << endl << flush;
  cout <<         "======================" << endl << flush;

  // Book tree tA (19Dec2023)
  // Also set JSON filter
  double jesAfix(1.);
  TChain *c_tA = new TChain("Events");
  //cout << "A is 19Dec2023" << endl;
  cout << "A is 22Sep2023" << endl;
  {
    LoadJSON("files/Cert_Collisions2022_355100_362760_Golden.json");
    LoadJSON("files/Cert_Collisions2023_366442_370790_Golden.json");


    //string filename = Form("input_files/dataFiles_%s.txt.19Dec2023.%sv12", crun, OneRun==true ? "OneRun." : "");
    //string filename = Form("input_files/dataFiles_%s.txt.22Sep2023.%sv12", crun, OneRun==true ? "OneRun." : "");
    string filename = Form("input_files/dataFiles_%s_ZB.txt.22Sep2023.%sv12", crun, OneRun==true ? "OneRun." : "");
    ifstream fin(filename.c_str(), ios::in);

    //string filename = Form("input_files/dataFiles_%s.txt.19Dec2023.v12",crun);
    cout << "Chaining data files for A: " << filename << endl << flush;
    int nFiles(0);
    while (fin >> filename) {
      ++nFiles;
      c_tA->AddFile(filename.c_str());
    }
    cout << "Chained " << nFiles <<  " files" << endl << flush;
  }


  //Set up JEC; factorized from DijetHistosFill to a separate function for now  
  FactorizedJetCorrector *jec = selectJECEra(run); 
  FactorizedJetCorrector *jecb = jec; //same corrector for tree b as of now
  assert(jec);
  
  // Set up jet veto maps
  // run selection factorized from DijetHistosFill to a separate function for now
  TH2D *h2jv = getJVM(run);


  // Set branches to sort events
  // Update: skip sorting here to make code faster
  TBranch *b_run_tA, *b_lbn_tA, *b_evt_tA;
  UInt_t run_tA, lbn_tA;
  ULong64_t evt_tA;
  c_tA->SetBranchAddress("run",&run_tA,&b_run_tA);
  c_tA->SetBranchAddress("luminosityBlock",&lbn_tA,&b_lbn_tA);
  c_tA->SetBranchAddress("event",&evt_tA,&b_evt_tA);

  // Book TB tree (22Sep2023)
  TChain *c_tB = new TChain("hlt");
  //cout << "B is 22Sep2023" << endl;
  cout << "B is HLT slimmedTupleV2*.root" << endl;
  {
    string filename = Form("input_files/hltFiles_%s%s.txt", crun, OneRun==true ? ".OneRun" : "");
    ifstream fin(filename.c_str(), ios::in);
    
    cout << "Chaining data files for B: " << filename << endl << flush;
    int nFiles(0);
    while (fin >> filename) {
      ++nFiles;
      c_tB->AddFile(filename.c_str());
    }
    cout << "Chained " << nFiles <<  " files" << endl << flush;
  }

  // Set branches to sort events
  TBranch *b_run_tB, *b_lbn_tB, *b_evt_tB;
  UInt_t run_tB, lbn_tB;
  ULong64_t evt_tB;
  c_tB->SetBranchAddress("rn",&run_tB,&b_run_tB);
  c_tB->SetBranchAddress("ls",&lbn_tB,&b_lbn_tB);
  c_tB->SetBranchAddress("ev",&evt_tB,&b_evt_tB);

  cout << "Sort TB entries" << endl << flush;
  //map<evtid, pair<Long64_t, Long64_t>, evtid> mtB;
  map<evtid, Long64_t, evtid> mtB;
  Long64_t ntotB = c_tB->GetEntries();//Fast();
  cout << "..Processing " << ntotB << " entries in tree B" << endl << flush;

  //nbytes = 0, nb = 0;
  for (Long64_t jentry=0; jentry<ntotB; jentry++) {
    Long64_t ientry = c_tB->LoadTree(jentry);
    if (ientry < 0) break;
    //nb = c_tB->GetEntry(jentry);   nbytes += nb;
    b_run_tB->GetEntry(ientry);
    //b_lbn_tB->GetEntry(ientry);
    b_evt_tB->GetEntry(ientry);
    assert(run_tB);
    //assert(lbn_tB);
    assert(evt_tB);

    //mtB[evtid(run_tB, lbn_tB, evt_tB)]
    //= pair<Long64_t, Long64_t>(jentry, ientry);
    mtB[evtid(run_tB, evt_tB)] = jentry;

    if (jentry%1000000==0) cout << "." << flush;
  }
  cout << endl;
  cout << "Found " << mtB.size() << " unique entries" << endl;
  cout << endl;


  // Jet triggers
  /*
  TBranch        *b_HLT_PFJet40;
  TBranch        *b_HLT_PFJet60;
  TBranch        *b_HLT_PFJet80;
  TBranch        *b_HLT_PFJet140;
  TBranch        *b_HLT_PFJet200;
  TBranch        *b_HLT_PFJet260;
  TBranch        *b_HLT_PFJet320;
  TBranch        *b_HLT_PFJet400;
  TBranch        *b_HLT_PFJet450;
  TBranch        *b_HLT_PFJet500;
  TBranch        *b_HLT_PFJet550;
  */
  TBranch        *b_HLT_ZeroBias;
  
  // Set branches for MET filters
  TBranch          *b_Flag_goodVertices;
  TBranch          *b_Flag_globalSuperTightHalo2016Filter;
  TBranch          *b_Flag_EcalDeadCellTriggerPrimitiveFilter;
  TBranch          *b_Flag_BadPFMuonFilter;
  TBranch          *b_Flag_BadPFMuonDzFilter;
  TBranch          *b_Flag_hfNoisyHitsFilter;
  TBranch          *b_Flag_eeBadScFilter;
  TBranch          *b_Flag_ecalBadCalibFilter;
  
  // Set common branches needed from both trees
  TBranch *b_njt_tA, *b_njt_tB;
  TBranch *b_jtpt_tA, *b_jtpt_tB;
  TBranch *b_jteta_tA, *b_jteta_tB;
  TBranch *b_jtphi_tA, *b_jtphi_tB;
  TBranch *b_jtA_tA, *b_jtA_tB;
  TBranch *b_jtid_tA, *b_jtid_tB;
  TBranch *b_jtjes_tA, *b_jtjes_tB;
  TBranch *b_rho_tA, *b_rho_tB;
  TBranch *b_jtchHEF_tA,  *b_jtchHEF_tB;
  TBranch *b_jtneHEF_tA,  *b_jtneHEF_tB;
  TBranch *b_jtneEmEF_tA, *b_jtneEmEF_tB;
  TBranch *b_jtchEmEF_tA, *b_jtchEmEF_tB;
  TBranch *b_jtmuEF_tA,   *b_jtmuEF_tB;
  

  // Set unique branches needed from tree A

  // Jet triggers
  /*
  Bool_t          HLT_PFJet40;
  Bool_t          HLT_PFJet60;
  Bool_t          HLT_PFJet80;
  Bool_t          HLT_PFJet140;
  Bool_t          HLT_PFJet200;
  Bool_t          HLT_PFJet260;
  Bool_t          HLT_PFJet320;
  Bool_t          HLT_PFJet400;
  Bool_t          HLT_PFJet450;
  Bool_t          HLT_PFJet500;
  Bool_t          HLT_PFJet550;
  */
  Bool_t          HLT_ZeroBias;
  
  // Set MET filters
  Bool_t          Flag_goodVertices;
  Bool_t          Flag_globalSuperTightHalo2016Filter;
  Bool_t          Flag_EcalDeadCellTriggerPrimitiveFilter;
  Bool_t          Flag_BadPFMuonFilter;
  Bool_t          Flag_BadPFMuonDzFilter;
  Bool_t          Flag_hfNoisyHitsFilter;
  Bool_t          Flag_eeBadScFilter;
  Bool_t          Flag_ecalBadCalibFilter;

  // Set common branches needed from both trees
  Float_t rho_tA, rho_tB;
  Int_t njt_tA, njt_tB;
  //Int_t npv_tA(0), npv_tB(0);
  //
  const int njt = 100;
  Float_t jtpt_tA[njt], jtpt_tB[njt];
  Float_t jteta_tA[njt], jteta_tB[njt];
  Float_t jtphi_tA[njt], jtphi_tB[njt];
  Float_t jtA_tA[njt], jtA_tB[njt];
  UChar_t jtid_tA[njt], jtid_tB[njt];
  Float_t jtjes_tA[njt], jtjes_tB[njt];

  // PF composition
  Float_t jtchHEF_tA[njt], jtchHEF_tB[njt];
  Float_t jtneHEF_tA[njt], jtneHEF_tB[njt];
  Float_t jtneEmEF_tA[njt], jtneEmEF_tB[njt];
  Float_t jtchEmEF_tA[njt], jtchEmEF_tB[njt];
  Float_t jtmuEF_tA[njt], jtmuEF_tB[njt];
    
  // Book tree A common branches
  c_tA->SetBranchAddress("Rho_fixedGridRhoFastjetAll",&rho_tA,&b_rho_tA);
  c_tA->SetBranchAddress("nJet",&njt_tA,&b_njt_tA);
  c_tA->SetBranchAddress("Jet_pt",jtpt_tA,&b_jtpt_tA);
  c_tA->SetBranchAddress("Jet_eta",jteta_tA,&b_jteta_tA);
  c_tA->SetBranchAddress("Jet_phi",jtphi_tA,&b_jtphi_tA);
  c_tA->SetBranchAddress("Jet_area",jtA_tA,&b_jtA_tA);
  c_tA->SetBranchAddress("Jet_jetId",jtid_tA,&b_jtid_tA);
  c_tA->SetBranchAddress("Jet_rawFactor",jtjes_tA,&b_jtjes_tA);

  c_tA->SetBranchAddress("Jet_chHEF",  jtchHEF_tA,  &b_jtchHEF_tA );  // h+
  c_tA->SetBranchAddress("Jet_neHEF",  jtneHEF_tA,  &b_jtneHEF_tA );  // h0
  c_tA->SetBranchAddress("Jet_neEmEF", jtneEmEF_tA, &b_jtneEmEF_tA); // gamma
  c_tA->SetBranchAddress("Jet_chEmEF", jtchEmEF_tA, &b_jtchEmEF_tA); // e
  c_tA->SetBranchAddress("Jet_muEF",   jtmuEF_tA,   &b_jtmuEF_tA  );   // mu

  // Jet triggers
  /*
  c_tA->SetBranchAddress("HLT_PFJet40", &HLT_PFJet40, &b_HLT_PFJet40);
  c_tA->SetBranchAddress("HLT_PFJet60", &HLT_PFJet60, &b_HLT_PFJet60);
  c_tA->SetBranchAddress("HLT_PFJet80", &HLT_PFJet80, &b_HLT_PFJet80);
  c_tA->SetBranchAddress("HLT_PFJet140", &HLT_PFJet140, &b_HLT_PFJet140);
  c_tA->SetBranchAddress("HLT_PFJet200", &HLT_PFJet200, &b_HLT_PFJet200);
  c_tA->SetBranchAddress("HLT_PFJet260", &HLT_PFJet260, &b_HLT_PFJet260);
  c_tA->SetBranchAddress("HLT_PFJet320", &HLT_PFJet320, &b_HLT_PFJet320);
  c_tA->SetBranchAddress("HLT_PFJet400", &HLT_PFJet400, &b_HLT_PFJet400);
  c_tA->SetBranchAddress("HLT_PFJet450", &HLT_PFJet450, &b_HLT_PFJet450);
  c_tA->SetBranchAddress("HLT_PFJet500", &HLT_PFJet500, &b_HLT_PFJet500);
  */
  c_tA->SetBranchAddress("HLT_ZeroBias", &HLT_ZeroBias, &b_HLT_ZeroBias);
  
  // MET filters
  c_tA->SetBranchAddress("Flag_goodVertices", &Flag_goodVertices, &b_Flag_goodVertices);
  c_tA->SetBranchAddress("Flag_globalSuperTightHalo2016Filter", &Flag_globalSuperTightHalo2016Filter, &b_Flag_globalSuperTightHalo2016Filter);
  c_tA->SetBranchAddress("Flag_EcalDeadCellTriggerPrimitiveFilter", &Flag_EcalDeadCellTriggerPrimitiveFilter, &b_Flag_EcalDeadCellTriggerPrimitiveFilter);
  c_tA->SetBranchAddress("Flag_BadPFMuonFilter", &Flag_BadPFMuonFilter, &b_Flag_BadPFMuonFilter);
  c_tA->SetBranchAddress("Flag_BadPFMuonDzFilter", &Flag_BadPFMuonDzFilter, &b_Flag_BadPFMuonDzFilter);
  c_tA->SetBranchAddress("Flag_hfNoisyHitsFilter", &Flag_hfNoisyHitsFilter, &b_Flag_hfNoisyHitsFilter);
  c_tA->SetBranchAddress("Flag_eeBadScFilter", &Flag_eeBadScFilter, &b_Flag_eeBadScFilter);
  c_tA->SetBranchAddress("Flag_ecalBadCalibFilter", &Flag_ecalBadCalibFilter, &b_Flag_ecalBadCalibFilter);
  
  // Book tree B unique branches
  c_tB->SetBranchAddress("rho",&rho_tB,&b_rho_tB);
  c_tB->SetBranchAddress("nj",&njt_tB,&b_njt_tB);
  c_tB->SetBranchAddress("jet_pt",jtpt_tB,&b_jtpt_tB);
  c_tB->SetBranchAddress("jet_eta",jteta_tB,&b_jteta_tB);
  c_tB->SetBranchAddress("jet_phi",jtphi_tB,&b_jtphi_tB);
  c_tB->SetBranchAddress("jet_area",jtA_tB,&b_jtA_tB);
  //c_tB->SetBranchAddress("jet_id",jtid_tB,&b_jtid_tB);
  c_tB->SetBranchAddress("jet_jec",jtjes_tB,&b_jtjes_tB);

  c_tB->SetBranchAddress("jet_chf", jtchHEF_tB,  &b_jtchHEF_tB );  // h+
  c_tB->SetBranchAddress("jet_nhf", jtneHEF_tB,  &b_jtneHEF_tB );  // h0
  c_tB->SetBranchAddress("jet_nef", jtneEmEF_tB, &b_jtneEmEF_tB); // gamma
  c_tB->SetBranchAddress("jet_elf", jtchEmEF_tB, &b_jtchEmEF_tB); // e
  c_tB->SetBranchAddress("jet_muf", jtmuEF_tB,   &b_jtmuEF_tB  );   // mu

  
  const int nsample = 1;//100; // 0.5h
  //const int nsample2 = 1;//100;
  const float frac = 1;//0.01;
  cout << "Pairing TA and TB" << endl << flush;
  cout << "Sampling 1/"<<nsample<<" of events" << endl << flush;
  //cout << "Sampling 1/"<<nsample2<<" of prescaled triggers (to be double-checked)" << endl << flush;
  cout << "Keeping first "<<frac*100<<"% of events" << endl << flush;

  // Speed up processing by selecting only used branches for tree A
  c_tA->SetBranchStatus("*",0);  // disable all branches

  // Activate tree A unique branches
  //c_tA->SetBranchStatus("Flag_Run3",1);
  c_tA->SetBranchStatus("run",1);
  c_tA->SetBranchStatus("luminosityBlock",1);
  c_tA->SetBranchStatus("event",1);

  // Jet triggers
  /*
  c_tA->SetBranchStatus("HLT_PFJet40",1);
  c_tA->SetBranchStatus("HLT_PFJet60",1);
  c_tA->SetBranchStatus("HLT_PFJet80",1);
  c_tA->SetBranchStatus("HLT_PFJet140",1);
  c_tA->SetBranchStatus("HLT_PFJet200",1);
  c_tA->SetBranchStatus("HLT_PFJet260",1);
  c_tA->SetBranchStatus("HLT_PFJet320",1);
  c_tA->SetBranchStatus("HLT_PFJet400",1);
  c_tA->SetBranchStatus("HLT_PFJet450",1);
  c_tA->SetBranchStatus("HLT_PFJet500",1);
  */
  c_tA->SetBranchStatus("HLT_ZeroBias",1);
  
  // MET Filters
  c_tA->SetBranchStatus("Flag_goodVertices", 1);
  c_tA->SetBranchStatus("Flag_globalSuperTightHalo2016Filter", 1);
  c_tA->SetBranchStatus("Flag_EcalDeadCellTriggerPrimitiveFilter", 1);
  c_tA->SetBranchStatus("Flag_BadPFMuonFilter", 1);
  c_tA->SetBranchStatus("Flag_BadPFMuonDzFilter", 1);
  c_tA->SetBranchStatus("Flag_hfNoisyHitsFilter", 1);
  c_tA->SetBranchStatus("Flag_eeBadScFilter", 1);
  c_tA->SetBranchStatus("Flag_ecalBadCalibFilter", 1);
  
  // Activate tree A common branches
  c_tA->SetBranchStatus("nJet",1);
  c_tA->SetBranchStatus("Jet_pt",1);
  c_tA->SetBranchStatus("Jet_eta",1);
  c_tA->SetBranchStatus("Jet_phi",1);
  c_tA->SetBranchStatus("Jet_area",1);
  c_tA->SetBranchStatus("Jet_jetId",1);
  c_tA->SetBranchStatus("Jet_rawFactor",1);
  c_tA->SetBranchStatus("Rho_fixedGridRhoFastjetAll", 1);

  // Speed up processing by selecting only used branches for tree B
  c_tB->SetBranchStatus("*",0);  // disable all branches

  // Activate tree B common branches
  c_tB->SetBranchStatus("nj",1);
  c_tB->SetBranchStatus("jet_pt",1);
  c_tB->SetBranchStatus("jet_eta",1);
  c_tB->SetBranchStatus("jet_phi",1);
  c_tB->SetBranchStatus("jet_area",1);
  //c_tB->SetBranchStatus("jet_id",1);
  c_tB->SetBranchStatus("jet_jec",1);
  c_tB->SetBranchStatus("rho", 1);



  if (doPFComposition)
  {
    c_tA->SetBranchStatus("Jet_chHEF", 1);  // h+
    c_tA->SetBranchStatus("Jet_neHEF", 1);  // h0
    c_tA->SetBranchStatus("Jet_neEmEF", 1); // gamma
    c_tA->SetBranchStatus("Jet_chEmEF", 1); // e
    c_tA->SetBranchStatus("Jet_muEF", 1);   // mu
    c_tB->SetBranchStatus("jet_chf", 1);  // h+
    c_tB->SetBranchStatus("jet_nhf", 1);  // h0
    c_tB->SetBranchStatus("jet_nef", 1); // gamma
    c_tB->SetBranchStatus("jet_elf", 1); // e
    c_tB->SetBranchStatus("jet_muf", 1);   // mu
  }

  
  // Results of interest
  // pT binning from JEC?
  /*
  double vx[] =
    {10, 12, 15, 18, 21, 24, 28, 32, 37, 43, 49, 56, 64, 74, 84,
     97, 114, 133, 153, 174, 196, 220, 245, 272, 300, 330, 362, 395, 430, 468,
     507, 548, 592, //638, 686, 737, 790, 846, 905, 967,
     //1032, 1101, 1172, 1248, 1327, 1410, 1497, 1588, 1684, 1784, 1890, 2000,
     //2116, 2238, 2366, 2500, 2640, 2787, 2941, 3103, 3273, 3450};
     638, 790, 967, 1172, 1410, 1684, 2000, 2500, 3000, 3500,
     4000, 4500, 5000, 6000};
  int nx = sizeof(vx)/sizeof(vx[0])-1;
  */
  /*
  double vxw[] =
      {10, 15, 21, 28, 37, 49, 64, 84, 114, 153, 196, 245, 300, 395, 468,
     548, 638, 790, 967, 1172, 1410, 1684, 2000, 2500, 3450};
  int nxw = sizeof(vxw)/sizeof(vxw[0])-1;
  */
  double vx[] =
    {10, 15, 21, 28, 37, 49, 64, 84, 114, 153, 196, 245, 300, 395, 468,
     548, 638, 790, 967, 1172, 1410, 1684, 2000, 2500, 3000, 3500,
     4000, 4500, 5000, 6000};
  int nx = sizeof(vx)/sizeof(vx[0])-1;

  // Regular L2Relative eta binning
  double vy[] =
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
  const int ny = sizeof(vy) / sizeof(vy[0]) - 1;
  
  // Open file for outputting results
  TFile *f = new TFile(Form("files/compareLiteHLT_%s.root",run.c_str()),
		       "RECREATE");
  f->mkdir("2D");
  f->mkdir("PF");

  // stub PF composition plots
  f->cd("PF");
  TProfile *pchHEFa_tp = new TProfile("pchHEFa_tp",";p_{T,tag};chHEF_{A}",nx,vx);
  TProfile *pchHEFb_tp = new TProfile("pchHEFb_tp",";p_{T,tag};chHEF_{B}",nx,vx);
  TProfile *pchHEabAbsDiff_tp = new TProfile("pchHEabAbsDiff_tp",";p_{T,tag};(p_{T,raw,A}*chHEF_{A})-(p_{T,raw,B}*chHEF_{B})",nx,vx);
  TProfile *pchHEabAbsDiffn_tp = new TProfile("pchHEabAbsDiffn_tp",";p_{T,tag};((p_{T,raw,A}*chHEF_{A})-(p_{T,raw,B}*chHEF_{B}))/p_{T,tag}",nx,vx);
  TProfile *pneHEFa_tp = new TProfile("pneHEFa_tp",";p_{T,tag};neHEF_{A}",nx,vx);
  TProfile *pneHEFb_tp = new TProfile("pneHEFb_tp",";p_{T,tag};neHEF_{B}",nx,vx);
  TProfile *pneHEabAbsDiff_tp = new TProfile("pneHEabAbsDiff_tp",";p_{T,tag};(p_{T,raw,A}*neHEF_{A})-(p_{T,raw,B}*neHEF_{B})",nx,vx);
  TProfile *pneHEabAbsDiffn_tp = new TProfile("pneHEabAbsDiffn_tp",";p_{T,tag};((p_{T,raw,A}*neHEF_{A})-(p_{T,raw,B}*neHEF_{B}))/p_{T,tag}",nx,vx);
  TProfile *pneEmEFa_tp = new TProfile("pneEmEFa_tp",";p_{T,tag};neEmEF_{A}",nx,vx);
  TProfile *pneEmEFb_tp = new TProfile("pneEmEFb_tp",";p_{T,tag};neEmEF_{B}",nx,vx);
  TProfile *pneEmEabAbsDiff_tp = new TProfile("pneEmEabAbsDiff_tp",";p_{T,tag};(p_{T,raw,A}*neEmEF_{A})-(p_{T,raw,B}*neEmEF_{B})",nx,vx);
  TProfile *pneEmEabAbsDiffn_tp = new TProfile("pneEmEabAbsDiffn_tp",";p_{T,tag};((p_{T,raw,A}*neEmEF_{A})-(p_{T,raw,B}*neEmEF_{B}))/p_{T,tag}",nx,vx);

  
  TProfile2D *p2chHEFa_tp = new TProfile2D("p2chHEFa_tp",";p_{T,tag};#eta_{A};chHEF_{A}",nx,vx,ny,vy);
  TProfile2D *p2chHEFb_tp = new TProfile2D("p2chHEFb_tp",";p_{T,tag};#eta_{A};chHEF_{B}",nx,vx,ny,vy);
  TProfile2D *p2chHEabAbsDiff_tp = new TProfile2D("p2chHEabAbsDiff_tp",";p_{T,tag};#eta_{A};(p_{T,raw,A}*chHEF_{A})-(p_{T,raw,B}*chHEF_{B})",nx,vx,ny,vy);
  TProfile2D *p2chHEabAbsDiffn_tp = new TProfile2D("p2chHEabAbsDiffn_tp",";p_{T,tag};#eta_{A};((p_{T,raw,A}*chHEF_{A})-(p_{T,raw,B}*chHEF_{B}))/p_{T,tag}",nx,vx,ny,vy);
  TProfile2D *p2neHEFa_tp = new TProfile2D("p2neHEFa_tp",";p_{T,tag};#eta_{A};neHEF_{A}",nx,vx,ny,vy);
  TProfile2D *p2neHEFb_tp = new TProfile2D("p2neHEFb_tp",";p_{T,tag};#eta_{A};neHEF_{B}",nx,vx,ny,vy);
  TProfile2D *p2neHEabAbsDiff_tp = new TProfile2D("p2neHEabAbsDiff_tp",";p_{T,tag};#eta_{A};(p_{T,raw,A}*neHEF_{A})-(p_{T,raw,B}*neHEF_{B})",nx,vx,ny,vy);
  TProfile2D *p2neHEabAbsDiffn_tp = new TProfile2D("p2neHEabAbsDiffn_tp",";p_{T,tag};#eta_{A};((p_{T,raw,A}*neHEF_{A})-(p_{T,raw,B}*neHEF_{B}))/p_{T,tag}",nx,vx,ny,vy);
  TProfile2D *p2neEmEFa_tp = new TProfile2D("p2neEmEFa_tp",";p_{T,tag};#eta_{A};neEmEF_{A}",nx,vx,ny,vy);
  TProfile2D *p2neEmEFb_tp = new TProfile2D("p2neEmEFb_tp",";p_{T,tag};#eta_{A};neEmEF_{B}",nx,vx,ny,vy);
  TProfile2D *p2neEmEabAbsDiff_tp = new TProfile2D("p2neEmEabAbsDiff_tp",";p_{T,tag};#eta_{A};(p_{T,raw,A}*neEmEF_{A})-(p_{T,raw,B}*neEmEF_{B})",nx,vx,ny,vy);
  TProfile2D *p2neEmEabAbsDiffn_tp = new TProfile2D("p2neEmEabAbsDiffn_tp",";p_{T,tag};#eta_{A};((p_{T,raw,A}*neEmEF_{A})-(p_{T,raw,B}*neEmEF_{B}))/p_{T,tag}",nx,vx,ny,vy);



  // Tag-and-probe method
  f->cd();
  TProfile *pta_tp = new TProfile("pta_tp",";p_{T,tag};p_{T,A}",nx,vx);
  TProfile *pa_tp = new TProfile("pa_tp",";p_{T,tag};p_{T,A}/p_{T,tag}",nx,vx);
  TProfile *pb_tp = new TProfile("pb_tp",";p_{T,tag};p_{T,B}/p_{T,tag}",nx,vx);
  TProfile *pd_tp = new TProfile("pd_tp",";p_{T,tag};"
				 "(p_{T,B}-p_{T,A})/p_{T,tag}",nx,vx);
  TH2D *h2a_tp =new TH2D("h2a_tp",";p_{T,tag};p_{T,A}/p_{T,tag}",nx,vx,400,-1,3);
  TH2D *h2b_tp =new TH2D("h2b_tp",";p_{T,tag};p_{T,B}/p_{T,tag}",nx,vx,400,-1,3);
  TH2D *h2d_tp =new TH2D("h2d_tp",";p_{T,tag};"
			 "0.5*(p_{T,B}-p_{T,A})/p_{T,tag}",nx,vx,600,-3,3);

  f->cd("2D");
  TProfile2D *p2ta_tp = new TProfile2D("p2ta_tp",";p_{T,tag};#eta_{A};p_{T,A}",
				       nx,vx,ny,vy);
  TProfile2D *p2a_tp = new TProfile2D("p2a_tp",";p_{T,tag};#eta_{A};"
				      "p_{T,A}/p_{T,tag};",nx,vx,ny,vy);
  TProfile2D *p2b_tp = new TProfile2D("p2b_tp",";p_{T,tag};#eta_{A};"
				      "p_{T,B}/p_{T,tag};",nx,vx,ny,vy);
  TProfile2D *p2d_tp = new TProfile2D("p2d_tp",";p_{T,tag};#eta_{A};"
				      "(p_{T,B}-p_{T,A})/p_{T,tag};",
				      nx,vx,ny,vy);
  
  // Direct match method in two variants
  f->cd();
  TProfile *pjesa_dm = new TProfile("pjesa_dm",";p_{T,A};JES(A)",nx,vx);
  TProfile *pjesb_dm = new TProfile("pjesb_dm",";p_{T,B};JES(B)",nx,vx);
  TProfile *pta_dm = new TProfile("pta_dm",";p_{T,A};p_{T,A}",nx,vx);
  TProfile *pa_dm = new TProfile("pa_dm",";p_{T,A};p_{T,B}/p_{T,A}",nx,vx);
  TProfile *ptb_dm = new TProfile("ptb_dm",";p_{T,B};p_{T,A}",nx,vx);
  TProfile *pb_dm = new TProfile("pb_dm",";p_{T,B};p_{T,A}/p_{T,B}",nx,vx);
  TProfile *ptd_dm = new TProfile("ptd_dm",";(p_{T,B}+p_{T,A})/2;"
				  "p_{T,A}",nx,vx);
  TProfile *pd_dm = new TProfile("pd_dm",";(p_{T,B}+p_{T,A})/2;"
				 "(p_{T,B}-p_{T,A})/(p_{T,B}+p_{T,A})",nx,vx);
  TH2D *h2a_dm = new TH2D("h2a_dm",";p_{T,A};p_{T,B}/p_{T,A}",nx,vx,400,-1,3);
  TH2D *h2b_dm = new TH2D("h2b_dm",";p_{T,B};p_{T,A}/p_{T,B}",nx,vx,400,-1,3);
  TH2D *h2d_dm = new TH2D("h2d_dm",";(p_{T,B}+p_{T,A})/2;"
			  "(p_{T,B}-p_{T,A})/(p_{T,B}+p_{T,A})",nx,vx,600,-3,3);

  f->cd("2D");
  TProfile2D *p2jesa_dm = new TProfile2D("p2jesa_dm",";p_{T,A};#eta_{A};JES(A)",
					 nx,vx,ny,vy);
  TProfile2D *p2jesb_dm = new TProfile2D("p2jesb_dm",";p_{T,B};#eta_{A};JES(B)",
					 nx,vx,ny,vy);
  TProfile2D *p2ta_dm = new TProfile2D("p2ta_dm",";p_{T,A};#eta_{A};p_{T,A}",
				       nx,vx,ny,vy);
  TProfile2D *p2a_dm = new TProfile2D("p2a_dm",";p_{T,A};#eta_{A};"
				      "p_{T,B}/p_{T,A}",nx,vx,ny,vy);
  TProfile2D *p2tb_dm = new TProfile2D("p2tb_dm",";p_{T,B};#eta_{A};p_{T,A}",
				       nx,vx,ny,vy);
  TProfile2D *p2b_dm = new TProfile2D("p2b_dm",";p_{T,B};#eta_{A};"
				      "p_{T,A}/p_{T,B}",nx,vx,ny,vy);
  TProfile2D *p2td_dm = new TProfile2D("p2td_dm",";(p_{T,B}+p_{T,A})/2;"
				       "#eta_{A};p_{T,A}",nx,vx,ny,vy);
  TProfile2D *p2d_dm = new TProfile2D("p2d_dm",";(p_{T,B}+p_{T,A})/2;#eta_{A};"
				      "(p_{T,B}-p_{T,A})/(p_{T,B}+p_{T,A})",
				      nx,vx,ny,vy);

  curdir->cd();
  
  int nev = 0;
  //int npre = 0;
  int ngood = 0;
  int njetveto(0);
  int nmatch = 0;
  int failsAtoB = 0;

  // Looping events in order of event number (possible slow_
  //for (map<Long64_t,Long64_t>::const_iterator it = mAtoB.begin();
  //   it != mAtoB.end(); ++it) {

  // Loop tree A in order of entries and skip entries missing in tree B
  // as consecutive reading of tree A should be (much?) faster
  Long64_t ntotA = c_tA->GetEntries();//Fast();
  cout << "..Processing " << ntotA << " entries in tree A to match in tree B"
       << endl << flush;

  TStopwatch t, tlap;
  t.Start();
  tlap.Start();
  int nlap = 25000000; // 25M

  for (Long64_t jentrytA = 0; jentrytA < ntotA; jentrytA++) {

    if (++nev%100000==0) cout << "." << flush;
    if (nev%nsample!=0) continue;
    if (nev>frac*ntotA) continue;

    // ETA estimate based on all events so far
    if (nev==100 || nev==10000 || nev==100000 || nev==1000000 || nev==5000000 ||
	(nev>5000000 && nev%25000000==0)) {
      cout << endl
	   << Form("Processed %ld events (%1.1f%%) in %1.0f sec. ETA:",
		   (long int)nev, 100.*nev/ntotA,
		   t.RealTime()) << endl;
      TDatime now; now.Set(now.Convert()+t.RealTime()*(ntotA-nev)/nev);
      now.Print();
      t.Continue();
    }
    // ETA estimate based on last 25M events
    if (nev>5000000 && nev%25000000==0) {
      cout << endl
	   << Form("Last lap %ld events (%1.1f%%) in %1.0f sec. ETA:",
		   (long int)nlap, 100.*nlap/ntotA,
		   tlap.RealTime()) << endl;
      TDatime now; now.Set(now.Convert()+tlap.RealTime()*(ntotA-nev)/nlap);
      now.Print();
      tlap.Reset();
      tlap.Continue();
    }

    // Load matching entries
    //Long64_t jentrytA = it->first;
    //Long64_t jentrytB = it->second;

    // Load entry from tree A
    //if (jentrytA<0 || jentrytA>=ntotA) continue;
    Long64_t ientrytA = c_tA->LoadTree(jentrytA);
    if (ientrytA < 0) break;

    // Sample prescaled triggers before reading full tree
    //bool keeppre((++npre)%nsample2==0);
    //if (!keeppre) {
    //b_HLT_PFJet500->GetEntry(ientrytA);
    //if (!HLT_PFJet500) continue;
    //}

    // Read full tree
    if (partialB) {
      b_run_tA->GetEntry(ientrytA);
      b_evt_tA->GetEntry(ientrytA);
    }
    else
      c_tA->GetEntry(jentrytA);

    // Find matching entry in tree B
    Long64_t jentrytB = mtB[evtid(run_tA, evt_tA)];
    if (jentrytB==0) {
      if (++failsAtoB<10) {
	cout << "\nFor tA("<<run_tA<<","<<evt_tA<<";"<<lbn_tA
	     <<"), did not find a matching entry in tB" << endl;
      }
      continue;
    }
    if (partialB)
      c_tA->GetEntry(jentrytA);

    // Load entry from tree B
    //if (jentrytB<0 || jentrytB>=ntotB) continue;
    Long64_t ientrytB = c_tB->LoadTree(jentrytB);
    if (ientrytB < 0) break;
    c_tB->GetEntry(jentrytB);

    // MET filters
    bool flag_tA =
      (Flag_goodVertices ||
       Flag_globalSuperTightHalo2016Filter ||
       Flag_EcalDeadCellTriggerPrimitiveFilter ||
       Flag_BadPFMuonFilter ||
       Flag_BadPFMuonDzFilter ||
       Flag_hfNoisyHitsFilter ||
       Flag_eeBadScFilter ||
       Flag_ecalBadCalibFilter);
    
    bool pass_veto = true;
    if (true) { // jet veto
      for (int i = 0; i != min(2,int(njt_tA)); ++i) {
	double phi = jtphi_tA[i];
	double eta = jteta_tA[i];
	int i1 = h2jv->GetXaxis()->FindBin(eta);
	int j1 = h2jv->GetYaxis()->FindBin(phi);
	if (h2jv->GetBinContent(i1,j1)>0) {
	  pass_veto = false;
	}
    }
    }     // jet veto
    if (pass_veto)++njetveto;
    else continue;

      

    // Does the run/LS pass the latest JSON selection?
    if (_json[run_tA][lbn_tA]==0) {
      continue;
    }
    else
      ++ngood;

    //double rhoA = rho_tA;
    //double rhoB = rho_tB;
    //cout << rhoA << "; " << rhoB <<endl;;

    // Redo JEC for tree A and treeB
    if (patchJESA) {

      for (int i = 0; i != njt_tA; ++i) {

	// Calculate new JEC
	double rawpt = jtpt_tA[i] * (1-jtjes_tA[i]);
	//double rawmass = jtmass_tA[i] * (1-jtjes_tA[i]);
	jec->setJetPt(rawpt);
	jec->setJetEta(jteta_tA[i]);
	jec->setJetA(jtA_tA[i]);
	jec->setRho(rho_tA);
	//vector<float> v = jec->getSubCorrections();
	//double corr = v.back();
	double corr = jec->getCorrection();

	// Apply corrections to original branches so downstream code stays same
	jtpt_tA[i] = corr * rawpt;
	//jtmass_tA[i] = corr * rawmass;
	jtjes_tA[i] = (1.0 - 1.0/corr);
      } // for njt_tA
    } // redoJES_A

    // Patch missing or differently defined variables
    for (int i = 0; i != njt_tB; ++i) {
      //jtjes_tB[i] = 0;
      jtjes_tB[i] = 1-1/jtjes_tB[i]; // jes=1-rawFactor=1/jec
      //jtA_tB[i] = 0.5;
      jtid_tB[i] = 4;
      //rho_tB = rho_tA;
    } // for i
      
    if (patchJESB) {

      for (int i = 0; i != njt_tB; ++i) {

	// Calculate new JEC
	double rawpt = jtpt_tB[i] * (1-jtjes_tB[i]);
	//double rawmass = jtmass_tB[i] * (1-jtjes_tB[i]);
	jec->setJetPt(rawpt);
	jec->setJetEta(jteta_tB[i]);
	jec->setJetA(jtA_tB[i]);
	jec->setRho(rho_tB);
	//vector<float> v = jec->getSubCorrections();
	//double corr = v.back();
	double corr = jec->getCorrection();

	// Apply corrections to original branches so downstream code stays same
	jtpt_tB[i] = corr * rawpt;
	//jtmass_tB[i] = corr * rawmass;
	jtjes_tB[i] = (1.0 - 1.0/corr);
      } // for njt_tB
    } // redoJES_B
    
    // Loop over two leading jets to find probe pairs
    for (int i = 0; i != min(2,int(njt_tA)); ++i) {

      
      double pt = jtpt_tA[i];
      double jes = (1-jtjes_tA[i]);
      double rawpt = pt * jes; 
      double eta = jteta_tA[i];
      double phi = jtphi_tA[i];
      bool idtightA = (jtid_tA[i]>=4);

      double chHEF = jtchHEF_tA[i];
      double chHE = chHEF*rawpt;
      double neHEF = jtneHEF_tA[i];
      double neHE = neHEF*rawpt;
      double neEmEF = jtneEmEF_tA[i];
      double neEmE = neEmEF*rawpt;

      bool hasmatch = false;
      for (int j = 0; j != min(2,int(njt_tB)) && !hasmatch; ++j) {
	
	double ptB = jtpt_tB[j];
	double jesB = (1-jtjes_tB[j]);
	double rawptB = ptB * jesB;
	double etaB = jteta_tB[j];
	double phiB = jtphi_tB[j];
	bool idtightB = (jtid_tB[j]>=4);
	
	double chHEFB = jtchHEF_tB[i];
	double chHEB = chHEFB*rawptB;
	double neHEFB = jtneHEF_tB[i];
	double neHEB = neHEFB*rawptB;
	double neEmEFB = jtneEmEF_tB[i];
	double neEmEB = neEmEFB*rawptB;

	// Match probe jets with deltaR<R/cone2
	double dr = tools::oplus(delta_eta(eta,etaB),delta_phi(phi,phiB));
	if (dr < 0.20) {

	  ++nmatch;
	  hasmatch = true;
	  double ptave = 0.5 * (ptB + pt);

	  // Tag selection
	  bool istp(false);
	  bool istagtrig(false);
	  double pttag(0);
	  if (i<2 && j<2 && njt_tA>1 && njt_tB>1) {

	    // Tag is the other one of the two leading jets
	    int k = (i==0 ? 1 : 0);
	    int l = (j==0 ? 1 : 0);
	    
	    double pttagA = jtpt_tA[k];
	    double pttagB = jtpt_tB[l];
	    pttag = 0.5 * (pttagA+pttagB);

	    double phiTA = jtphi_tA[k];
	    double phiTB = jtphi_tB[l];
	    double dphiTA = delta_phi(phiTA,phi);
	    double dphiTB = delta_phi(phiTB,phiB);
	    double dphitag = 0.5*(dphiTA + dphiTB);

	    double etaTA = jteta_tA[k];
	    double etaTB = jteta_tB[l];
	    double etatag = 0.5*(etaTA + etaTB);

	    double pt3A = (njt_tA>2 ? jtpt_tA[2] : 0);
	    double pt3B = (njt_tB>2 ? jtpt_tB[2] : 0);
	    double alphaTA = pt3A / pttagA;
	    double alphaTB = pt3B / pttagB;
	    double alphatag = (alphaTA>0 && alphaTB>0 ?
			       0.5*(alphaTA+alphaTB) : max(alphaTA,alphaTB));

	    bool trigger = (HLT_ZeroBias && pttagB>40.);
	    /*
	    bool trigger =
	      ((HLT_PFJet500 && pttag>638) ||
	       (keeppre && 
		((HLT_PFJet450 && pttag>548) ||
		 (HLT_PFJet400 && pttag>468) ||
		 (HLT_PFJet320 && pttag>395) ||
		 (HLT_PFJet260 && pttag>300) ||
		 (HLT_PFJet200 && pttag>245) ||
		 (HLT_PFJet140 && pttag>196) ||
		 (HLT_PFJet80  && pttag>114) ||
		 (HLT_PFJet60  && pttag>84) ||
		 (HLT_PFJet40  && pttag>10)))
	       );
	    */
	    //{10,15, 21, 28, 37, 49, 64, 84, 114, 153, 196, 245, 300, 395, 468,
	    //548, 638, 790, 967, 1172, 1410, 1684, 2000, 2500, 3000, 3500,
	    //4000, 4500, 5000, 6000};
	    //
	    //{10, 12, 15, 18, 21, 24, 28, 32, 37, 43, 49, 56, 64, 74, 84,
	    //97, 114, 133, 153, 174, 196, 220, 245, 272, 300, 330, 362, 395,
	    //430, 468, 507, 548, 592,
	    //638, 790, 967, 1172, 1410, 1684, 2000, 2500, 3000, 3500,
	    //4000, 4500, 5000, 6000};
	    istp = (dphitag>2.7 && alphatag<0.3 && fabs(etatag)<1.3 &&
		    pt/pttag<1.35 && ptB/pttag<1.35 &&
		    pt/pttag>0.45 && ptB/pttag>0.45 && trigger);
	    istagtrig = trigger;
	  } // tag selection

	  // Direct match probe trigger selections
	  bool trigD = (HLT_ZeroBias && istagtrig);
	  /*
	  bool trigD =
	    ((HLT_PFJet500 && ptave>638) ||
	     (keeppre &&
	      ((HLT_PFJet450 && ptave>548) ||
	       (HLT_PFJet400 && ptave>468) ||
	       (HLT_PFJet320 && ptave>395) ||
	       (HLT_PFJet260 && ptave>300) ||
	       (HLT_PFJet200 && ptave>245) ||
	       (HLT_PFJet140 && ptave>196) ||
	       (HLT_PFJet80  && ptave>114) ||
	       (HLT_PFJet60  && ptave>84) ||
	       (HLT_PFJet40  && ptave>10)))
	     );
	  */
	  bool trigB = (HLT_ZeroBias && (ptB>40. || istagtrig));
	  /*
	  bool trigB =
	    ((HLT_PFJet500 && ptB>638) ||
	     (keeppre &&
	      ((HLT_PFJet450 && ptB>548) ||
	       (HLT_PFJet400 && ptB>468) ||
	       (HLT_PFJet320 && ptB>395) ||
	       (HLT_PFJet260 && ptB>300) ||
	       (HLT_PFJet200 && ptB>245) ||
	       (HLT_PFJet140 && ptB>196) ||
	       (HLT_PFJet80  && ptB>114) ||
	       (HLT_PFJet60  && ptB>84) ||
	       (HLT_PFJet40  && ptB>10)))
	      );
	  */
	  bool trigA = (HLT_ZeroBias && istagtrig);
	  /*
	  bool trigA =
	    ((HLT_PFJet500 && pt>638) ||
	     (keeppre &&
	      ((HLT_PFJet450 && pt>548) ||
	       (HLT_PFJet400 && pt>468) ||
	       (HLT_PFJet320 && pt>395) ||
	       (HLT_PFJet260 && pt>300) ||
	       (HLT_PFJet200 && pt>245) ||
	       (HLT_PFJet140 && pt>196) ||
	       (HLT_PFJet80  && pt>114) ||
	       (HLT_PFJet60  && pt>84) ||
	       (HLT_PFJet40  && pt>10)))
	     );
	  */

	  // Look at good probe jets in barrel in good events
	  if (//fabs(eta)<1.3 && fabs(etaB)<1.3 &&
	      idtightA && idtightB &&
	      flag_tA && //flag_tB &&
	      pt > 0.5*ptB && ptB > 0.5*pt
	    //dr < 0.10) {
	    ) {

	    // Tag-and-probe method
	    if (istp) {
	      
	      // 1D variants
	      if (fabs(eta)<1.3 && fabs(etaB)<1.3) {
		pta_tp->Fill(pttag, pt);
		pa_tp->Fill(pttag, pt / pttag);
		pb_tp->Fill(pttag, ptB / pttag);
		pd_tp->Fill(pttag, 0.5*(ptB-pt) / pttag);
		
		h2a_tp->Fill(pttag, pt / pttag);
		h2b_tp->Fill(pttag, ptB / pttag);
		h2d_tp->Fill(pttag, 0.5*(ptB-pt) / pttag);
	      }
		
	      // 2D variants
	      p2ta_tp->Fill(pttag, eta, pt);
	      p2a_tp->Fill(pttag, eta, pt / pttag);
	      p2b_tp->Fill(pttag, eta, ptB / pttag);
	      p2d_tp->Fill(pttag, eta, 0.5*(ptB-pt) / pttag);

	      if(doPFComposition){
		if (fabs(eta)<1.3 && fabs(etaB)<1.3) {
		  pchHEFa_tp->Fill(pttag,chHEF);
		  pchHEFb_tp->Fill(pttag,chHEFB);
		  pchHEabAbsDiff_tp->Fill(pttag,chHE-chHEB);
		  pchHEabAbsDiffn_tp->Fill(pttag,(chHE-chHEB)/pttag);
		  pneHEFa_tp->Fill(pttag,neHEF);
		  pneHEFb_tp->Fill(pttag,neHEFB);
		  pneHEabAbsDiff_tp->Fill(pttag,neHE-neHEB);
		  pneHEabAbsDiffn_tp->Fill(pttag,(neHE-neHEB)/pttag);
		  pneEmEFa_tp->Fill(pttag,neEmEF);
		  pneEmEFb_tp->Fill(pttag,neEmEFB);
		  pneEmEabAbsDiff_tp->Fill(pttag,neEmE-neEmEB);
		  pneEmEabAbsDiffn_tp->Fill(pttag,(neEmE-neEmEB)/pttag);
		}

		p2chHEFa_tp->Fill(pttag,eta, chHEF);
		p2chHEFb_tp->Fill(pttag, eta, chHEFB);
		p2chHEabAbsDiff_tp->Fill(pttag, eta, chHE-chHEB);
		p2chHEabAbsDiffn_tp->Fill(pttag, eta, (chHE-chHEB)/pttag);
		p2neHEFa_tp->Fill(pttag,eta, neHEF);
		p2neHEFb_tp->Fill(pttag, eta, neHEFB);
		p2neHEabAbsDiff_tp->Fill(pttag, eta, neHE-neHEB);
		p2neHEabAbsDiffn_tp->Fill(pttag, eta, (neHE-neHEB)/pttag);
		p2neEmEFa_tp->Fill(pttag,eta, neEmEF);
		p2neEmEFb_tp->Fill(pttag, eta, neEmEFB);
		p2neEmEabAbsDiff_tp->Fill(pttag, eta, neEmE-neEmEB);
		p2neEmEabAbsDiffn_tp->Fill(pttag, eta, (neEmE-neEmEB)/pttag);
		  
	      }
	      
	    } //istp

	    // Direct matching method
	    // 1D variants
	    if (fabs(eta)<1.3 && fabs(etaB)<1.3) {
	      if (trigA) pjesa_dm->Fill(pt, jes);
	      if (trigB) pjesb_dm->Fill(ptB, jesB);
	      
	      if (trigA) pta_dm->Fill(pt, pt);
	      if (trigA) pa_dm->Fill(pt, ptB / pt);
	      if (trigB) ptb_dm->Fill(ptB, pt);
	      if (trigB) pb_dm->Fill(ptB, pt / ptB);
	      if (trigD) ptd_dm->Fill(ptave, pt);
	      if (trigD) pd_dm->Fill(ptave, 0.5*(ptB-pt) / ptave);
	      
	      if (trigA) h2a_dm->Fill(pt, ptB / pt);
	      if (trigB) h2b_dm->Fill(ptB, pt / ptB);
	      if (trigD) h2d_dm->Fill(ptave, 0.5*(ptB-pt) / ptave);
	    }
	    
	    // 2D variants
	    if (trigA) p2jesa_dm->Fill(pt, eta, jes);
	    if (trigB) p2jesb_dm->Fill(ptB, eta, jesB);
	      
	    if (trigA) p2ta_dm->Fill(pt, eta, pt);
	    if (trigA) p2a_dm->Fill(pt, eta, ptB / pt);
	    if (trigB) p2tb_dm->Fill(ptB, eta, pt);
	    if (trigB) p2b_dm->Fill(ptB, eta, pt / ptB);
	    if (trigD) p2td_dm->Fill(ptave, eta, pt);
	    if (trigD) p2d_dm->Fill(ptave, eta, 0.5*(ptB-pt) / ptave);
	  } // good barrel probe
	} // dr match
      } // for j
    } // for i
  } // for events
  cout << endl << "Found " << nev << " matching events" << endl;
    //<< " of which " << nj << " had same number of jets" << endl;
      cout << " of which " << njetveto << " passed jet veto map enforced to (up to) two leading jets" << endl;
      cout << " of which " << ngood << " passed JSON selection" << endl;
  cout << "Found " << nmatch << " matching jets in these events" << endl;
    
  cout << "Output stored to " << f->GetName() << endl;
  f->Write();
  f->Close();

  t.Stop();
  cout << "Processing used " << t.CpuTime() << "s CPU time ("
       << t.CpuTime()/3600. << "h)" << endl;
  cout << "Processing used " << t.RealTime() << "s real time ("
       << t.RealTime()/3600. << "h)" << endl;
  cout << endl << endl;
  cout << "Processing ended at: ";
  TDatime now; now.Print();
  
}
