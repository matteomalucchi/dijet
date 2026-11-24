// Purpose: Draw Multijet results to do sanity checks
//          Compare various pT bins and MPF, DB (HDM), data vs MC
#include "TFile.h"
#include "TProfile.h"
#include "TLine.h"
#include <map>
#include <string>

#include "../tdrstyle_mod22.C"

string version = "v35a";

void drawMultijets(string epoch="2022CD", string version="v31");

void drawMultijet() {

  // v30: with L2L3Res
  /*
  drawMultijets("2022CD","v30");
  drawMultijets("2022E","v30");
  drawMultijets("2022FG","v30");
  drawMultijets("2023BCv123","v30");
  drawMultijets("2023Cv4","v30");
  drawMultijets("2023D","v30");

  // v31: no L2L3Res
  drawMultijets("2022CD","v31");
  drawMultijets("2022E","v31");
  drawMultijets("2022FG","v31");
  drawMultijets("2023BCv123","v31");
  drawMultijets("2023Cv4","v31");
  drawMultijets("2023D","v31");
*/
  drawMultijets("2022CD",version);
  drawMultijets("2022E",version);
  drawMultijets("2022FG",version);
  drawMultijets("2023BCv123",version);
  drawMultijets("2023Cv4",version);
  drawMultijets("2023D",version);

  drawMultijets("Run3",version);
}


void drawMultijets(string epoch, string version) {

  setTDRStyle();
  TDirectory *curdir = gDirectory;

  // Load requested data file
  const char *ce = epoch.c_str();
  const char *cv = version.c_str();
  TFile *fd = new TFile(Form("../files/jmenano_data_cmb_%s_JME_%s.root",ce,cv));
  assert(fd && !fd->IsZombie());

  // Find matching MC
  map<string,const char*> mc;
  mc["2022C"] = "Summer22MG1";
  mc["2022CD"] = "Summer22MG1";
  mc["2022E"] = (version=="v30" ? "Summer22MG1" : "Summer22EEMG1");
  mc["2022FG"] = (version=="v30" ? "Summer22MG1" : "Summer22EEMG1");
  mc["2023BCv123"] = "Summer22MG1";
  mc["2023Cv4"] = "Summer22MG1";
  mc["2023D"] = "Summer22MG1";
  mc["Run3"] = "Summer22MG1";
  const char *cm = mc[ce];
  TFile *fm = new TFile(Form("../files/jmenano_mc_out_%s_%s.root",cm,cv));
  assert(fm && !fm->IsZombie());
  // Print the file name
  cout << "Data: " << fd->GetName() << endl;


  // List results to be plotted
  string vd[] = {"pm0l","pm0a","pm0r", "pm2l","pm2a","pm2r"};
  const int nvd = sizeof(vd)/sizeof(vd[0]);

  // Set plotting styles (color, marker, line style) for results
  map<string,int> color;
  color["pm0l"] = kRed;
  color["pm2l"] = kRed;
  color["pm0a"] = kGreen+2;
  color["pm2a"] = kGreen+2;
  color["pm0r"] = kBlue;
  color["pm2r"] = kBlue;
  map<string,int> marker;
  marker["pm0l"] = kFullTriangleDown; 
  marker["pm0a"] = kFullDiamond;
  marker["pm0r"] = kFullTriangleUp;
  marker["pm2l"] = kOpenTriangleDown;
  marker["pm2a"] = kOpenDiamond;
  marker["pm2r"] = kOpenTriangleUp;
  map<string,int> style;
  style["pm0l"] = kSolid;
  style["pm0a"] = kSolid;
  style["pm0r"] = kSolid;
  style["pm2l"] = kDotted;
  style["pm2a"] = kDotted;
  style["pm2r"] = kDotted;
  map<string,const char*> label;
  label["pm0l"] = "MPF lead";
  label["pm2l"] = "DB lead";
  label["pm0a"] = "MPF avg.";
  label["pm2a"] = "DB avg.";
  label["pm0r"] = "MPF recoil";
  label["pm2r"] = "DB recoil";
  
  // Set header (integrated luminosity) for data
  map<string,const char*> title;
  title["2022C"] = "2022C";
  title["2022CD"] = "2022CD";
  title["2022E"] = "2022E";
  title["2022FG"] = "2022FG";
  title["2023BCv123"] = "2023BCv123";
  title["2023Cv4"] = "2023Cv4";
  title["2023D"] = "2023D";

  // Debug msg
  cout << "Drawing hists for " << ce << endl;

  // Create canvas for plots
  double ptmin = 114;
  double ptmax = 2100;
  TH1D *hu = tdrHist("hu","Multijet #LTp_{T,lead}#GT / #LTp_{T,recoil}#GT",
		     0.85,1.30,"#LTp_{T,lead}#GT (GeV)",ptmin,ptmax);
  TH1D *hd = tdrHist("hd","Data / MC",
		     0.90,1.10,"#LTp_{T,lead}#GT (GeV)",ptmin,ptmax);
  TLine *l = new TLine();
  lumi_136TeV = title[ce];
  TCanvas *c1 = tdrDiCanvas("c1",hu,hd,8,11);//,kSquare);
  c1->cd(1);
  gPad->SetLogx();
  l->DrawLine(ptmin,1,ptmax,1);

  TLegend *legd = tdrLeg(0.60,0.90-0.05*nvd,0.90,0.90);
  TLegend *legm = tdrLeg(0.60,0.88-0.05*nvd,0.90,0.88);
  
  c1->cd(2);
  gPad->SetLogx();
  l->DrawLine(ptmin,1,ptmax,1);

  // Plot results
  for (int i = 0; i != nvd; ++i) {
    const char *ch = vd[i].c_str();

    cout << "Drawing " << ch << endl;

    c1->cd(1);
    TProfile *pm = (TProfile*)fm->Get(Form("HLT_MC/Multijet/%s",ch)); assert(pm);
    pm->GetXaxis()->SetRangeUser(ptmin,ptmax);
    cout << "Drawing first profile" << endl;
    tdrDraw(pm,"HIST",marker[ch],color[ch],style[ch],-1,kNone);

    cout << "Drawing second profile" << endl;
    TProfile *p = (TProfile*)fd->Get(Form("Multijet/%s",ch)); assert(p);
    p->GetXaxis()->SetRangeUser(ptmin,ptmax);
    tdrDraw(p,"Pz",marker[ch],color[ch],kSolid);

    legd->AddEntry(p,label[ch],"PE");
    legm->AddEntry(pm,"","L");

    cout << "Drawing ratio plot" << endl;
    c1->cd(2);
    TH1D *hr = (TH1D*)p->Clone("hr");
    TH1D *hm = (TH1D*)pm->ProjectionX("hm");
    hr->Divide(hm);
    tdrDraw(hr,"Pz",marker[ch],color[ch],kSolid);
  }

  c1->SaveAs(Form("../pdf/drawMultijet/drawMultijet_%s_%s.pdf",ce,cv));
} // drawMultijet
