// Purpose: Draw stability of multijet results vs pT over time
//          Compare data and MC for response etc.
//          Copied from gamjet/drawPhotonJetVsPtVsIOV.C
#include "TFile.h"
#include "TH1D.h"
#include "TProfile.h"
#include "TLine.h"

#include "../tdrstyle_mod22.C"

bool addMPFu2n = true;
bool addG1toMPF = false;
bool addG12toMPF = false;
string id = "v35a";
bool drawFullIOVList = false;//true;

// Forward declaration of call
void drawMultijetVsPtVsIOVs(string so, string var, string name,
			    double y1, double y2, double z1, double z2,
			    bool doDiff = false);

// Multiple calls to draw function
void drawMultijetVsPtVsIOV() {

  drawMultijetVsPtVsIOVs("Multijet/pm0a","MPF","MPF",0.95,1.20,0.89,1.09);
  drawMultijetVsPtVsIOVs("Multijet/pm2a","DB","DB",0.95,1.20,0.89,1.09);
  drawMultijetVsPtVsIOVs("Multijet/PFcomposition/pnhf13",
			 "Multijet NHF","multijet_NHF",
			 0.0,0.4,-0.25,+0.1,true);
  drawMultijetVsPtVsIOVs("Dijet/PFcomposition/pnhf13",
			 "Dijet NHF","dijet_NHF",
			 0.0,0.4,-0.25,+0.1,true);
  drawMultijetVsPtVsIOVs("Incjet/PFcomposition/pnhf13",
			 "Inclusive jet NHF","incjet_NHF",
			 0.0,0.4,-0.25,+0.1,true);
} // drawMultijetVsPtVsIOV

void drawMultijetVsPtVsIOVs(string so, string var, string name,
			    double y1, double y2, double z1, double z2,
			    bool doDiff) {
  setTDRStyle();
  TDirectory *curdir = gDirectory;

  //string iovs[] = {"2016BCDEF","2016FGH","2017BCDEF","2018ABCD","Run2"};
  //string mcs[] = {"2016APVP8","2016P8","2017P8","2018P8","Run2P8"};
  //string iovs[] = {"2016BCDEF","2016FGH","2017BCDEF","2018ABCD"};
  //string mcs[] = {"2016APVP8","2016P8","2017P8","2018P8"};
  string iovs_long[] = {
    "2022C","2022D","2022E","2022F","2022G",
    "2023BCv123","2023Cv4","2023D"
  };
  string iovs_short[] = {
    //"2018ABCD",
    "Run3",
    //"2022CD","2022E","2022FG",
    "2022CD","2022E","2022FG",
    "2023BCv123","2023Cv4","2023D"
    //"2023BCv123","2023Cv4D"
  };

  string mcs_long[] = {
    "Summer22MG","Summer22MG","Summer22MG","Summer22MG","Summer22MG",
    "Summer22MG","Summer22MG","Summer22MG"
  };
  string mcs_short[] = {
    //"2018P8",
    "Summer22MG",
    "Summer22MG","Summer22EEMG","Summer22EEMG",//"Summer22MG",
    "Summer22MG","Summer22MG","Summer22MG"
    //"Summer22MG","Summer22MG",
  };
  const int niov_long = sizeof(iovs_long)/sizeof(iovs_long[0]);
  const int nmc_long = sizeof(mcs_long)/sizeof(mcs_long[0]);
  const int niov_short = sizeof(iovs_short)/sizeof(iovs_short[0]);
  const int nmc_short = sizeof(mcs_short)/sizeof(mcs_short[0]);

  string *iovs = (drawFullIOVList ? &iovs_long[0] : &iovs_short[0]);
  string *mcs = (drawFullIOVList ? &mcs_long[0] : &mcs_short[0]);
  const int niov = (drawFullIOVList ? niov_long : niov_short);
  const int nmc = (drawFullIOVList ? nmc_long : nmc_short);

  assert(niov==nmc);
  
  map<string,int> mcolor;
  mcolor["2016BCDEF"] = kBlue;
  mcolor["2016FGH"] = kCyan+2;
  mcolor["2017BCDEF"] = kGreen+2;
  mcolor["2018ABCD"] = kGray+2;//kRed;
  mcolor["Run2"] = kBlack;
  //
  mcolor["2022C"] = kBlue;
  mcolor["2022D"] = kCyan+1;
  mcolor["2022E"] = kCyan+2;
  mcolor["2022CD"] = kBlue;
  mcolor["2022CDE"] = kBlue;
  mcolor["2022F"] = kRed;
  mcolor["2022G"] = kOrange+2;
  mcolor["2022FG"] = kRed;
  mcolor["2023Cv123"] = kYellow+2;
  mcolor["2023BCv123"] = kYellow+2;
  mcolor["2023Cv4"] = kGreen+2;
  mcolor["2023D"] = kMagenta+2;
  mcolor["2023Cv4D"] = kGreen+2;
  mcolor["Run3"] = kBlack;

  map<string,int> mmarker;
  mmarker["2022C"] = kFullSquare;
  mmarker["2022D"] = kOpenSquare;
  mmarker["2022E"] = kOpenSquare;
  mmarker["2022CD"] = kFullSquare;
  mmarker["2022CDE"] = kFullSquare;
  mmarker["2022F"] = kFullTriangleUp;
  mmarker["2022G"] = kOpenTriangleUp;
  mmarker["2022FG"] = kFullTriangleUp;
  mmarker["2023Cv123"] = kFullCircle;
  mmarker["2023BCv123"] = kFullCircle;
  mmarker["2023Cv4"] = kFullTriangleDown;//kFullDiamond;
  mmarker["2023D"] = kOpenTriangleDown;//kOpenDiamond;
  mmarker["2023Cv4D"] = kFullTriangleDown;//kFullDiamond;
  mmarker["Run3"] = kFullSquare;

  const char *cvar = var.c_str();
  const char *cname = name.c_str();

  TH1D *h = tdrHist("h",cvar,y1,y2,"p_{T} (GeV)",97,3450);//3103);
  TH1D *h2 = tdrHist("h2","Data/MC",z1,z2,"p_{T} (GeV)",97,3450);//3103);
  lumi_13TeV = "Run2"; // 4=13 TeV
  if (id!="") lumi_136TeV = Form("Run3 %s",id.c_str()); // 8=13.6 TeV
  TCanvas *c1 = tdrDiCanvas(Form("c1_%s",cname),h,h2,8,11);
  
  double x1 = h->GetXaxis()->GetXmin();
  double x2 = h->GetXaxis()->GetXmax();

  c1->cd(1);
  TLine *l = new TLine();
  l->SetLineStyle(kDashed);
  l->DrawLine(h->GetXaxis()->GetXmin(),1,h->GetXaxis()->GetXmax(),1);
  l->DrawLine(h->GetXaxis()->GetXmin(),0,h->GetXaxis()->GetXmax(),0);
  gPad->SetLogx();

  TLegend *leg = tdrLeg(0.60,0.90-niov*0.045,0.80,0.90);

  c1->cd(2);
  gPad->SetLogx();
  l->DrawLine(h->GetXaxis()->GetXmin(),1,h->GetXaxis()->GetXmax(),1);
  l->DrawLine(h->GetXaxis()->GetXmin(),0,h->GetXaxis()->GetXmax(),0);

  for (int i = 0; i != niov; ++i) {
  
    string iov = iovs[i];
    const char *ciov = iov.c_str();
    const char *cmc = mcs[i].c_str();
    const char *cid = id.c_str();

    TFile *fd(0), *fm(0);
    if (iovs[i]=="2018ABCD") {
      //fd = new TFile(Form("files/GamHistosFill_data_%s_v20.root",ciov));
      assert(false);
    }
    else {
      fd = new TFile(Form("../files/jmenano_data_cmb_%s_JME_%s.root",ciov,cid));
    }
    assert(fd && !fd->IsZombie());
    if (iovs[i]=="2018ABCD") {
      //fm = new TFile(Form("files/GamHistosFill_mc_%s_v20.root",cmc));
      assert(false);
    }
    else {
      fm = new TFile(Form("../files/jmenano_mc_out_%s_%s.root",cmc,cid));
    }
    assert(fm && !fm->IsZombie());

    curdir->cd();
    
    //TObject *od = fd->Get(Form(so.c_str(),"DATA")); assert(od);
    //TObject *om = fm->Get(Form(so.c_str(),"MC")); assert(om);
    cout << so << endl << flush;
    TObject *od = fd->Get(so.c_str()); assert(od);
    TObject *om = fm->Get(Form("HLT_MC/%s",so.c_str())); assert(om);
    
    TH1D *hd(0), *hm(0);
    if (od->InheritsFrom("TProfile")) {
      hd = ((TProfile*)od)->ProjectionX(Form("hd_%s_%s",cvar,ciov));
      hm = ((TProfile*)om)->ProjectionX(Form("hm_%s_%s",cvar,ciov));

      if (name=="MPFn" && addMPFu2n) {
	const char *co = "resp_MpfRuchs_%s_a100_eta00_13";
	TProfile *pd = (TProfile*)fd->Get(Form(co,"DATA")); assert(pd);
	TProfile *pm = (TProfile*)fm->Get(Form(co,"MC")); assert(pm);
	hd->Add(pd,1.2);
	hm->Add(pm,1.2);
      }
      if ((name=="MPF" || name=="MPF1") && addG1toMPF) {
	const char *co = "control/pgain1vspt";
	TProfile *pd = (TProfile*)fd->Get(Form(co,"DATA")); assert(pd);
	TProfile *pm = (TProfile*)fm->Get(Form(co,"MC")); assert(pm);
	hd->Add(pd,0.02);
      }
      if ((name=="MPF" || name=="MPF1") && addG12toMPF) {
	const char *co = "control/pgain12vspt";
	TProfile *pd = (TProfile*)fd->Get(Form(co,"DATA")); assert(pd);
	TProfile *pm = (TProfile*)fm->Get(Form(co,"MC")); assert(pm);
	hd->Add(pd,0.0);
      }
    }
    else {
      hd = (TH1D*)od;
      hm = (TH1D*)om;
    }
    assert(hd);
    assert(hm);
    
    TH1D *hr = (TH1D*)hd->Clone(Form("hr_%s_%s",cvar,ciov));
    //if (name=="MPFn" || name=="MPFu" || name=="Leakage" || name=="Leakage0") {
    if (doDiff) {
      hr->Add(hm,-1);
      h2->SetYTitle("Data-MC");
    }
    else
      hr->Divide(hm);
    
    c1->cd(1);
    gPad->SetLogx();
    hm->GetXaxis()->SetRangeUser(x1,x2);
    tdrDraw(hm,"H",kNone,mcolor[iov],kSolid,-1,kNone);
    hd->GetXaxis()->SetRangeUser(x1,x2);
    tdrDraw(hd,"Pz",(mmarker[iov] ? mmarker[iov] : kFullCircle),
	    (mcolor[iov] ? mcolor[iov] : kBlack));
    
    leg->AddEntry(hd,ciov,"PLE");

    c1->cd(2);
    gPad->SetLogx();
    hr->GetXaxis()->SetRangeUser(x1,x2);
    tdrDraw(hr,"Pz",(mmarker[iov] ? mmarker[iov] : kFullCircle),
	    (mcolor[iov] ? mcolor[iov] : kBlack));
  } // for iov

  if (id!="")
      c1->SaveAs(Form("../pdf/drawMultijetVsPtVsIOVs_%s_%s.pdf",
		      name.c_str(),id.c_str()));
  else
    c1->SaveAs(Form("../pdf/drawMultijetVsPtVsIOVs_%s.pdf",name.c_str()));
} // void drawPhotonJetVsPtVsIOVs
