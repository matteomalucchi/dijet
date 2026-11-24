// Purpose: Draw tag-and-probe and direct matching results for reco-reco match
#include "TFile.h"
#include "TProfile.h"
#include "TGraphErrors.h"
#include "TF1.h"
#include "TMultiGraph.h"

#include "tdrstyle_mod22.C"

bool patchJES = false;

TGraphErrors *tagandprobe(TProfile *pt, TProfile *pa, TProfile *pb,
			  TProfile *pd) {

  TGraphErrors *g = new TGraphErrors(0);
  for (int i = 1; i != pa->GetNbinsX()+1; ++i) {
    //double x = pa->GetBinContent(i) * pa->GetBinCenter(i); // <A/tag>*<tag>~<A>
    double x = pt->GetBinContent(i); // <A>
    double ex = pt->GetBinError(i); // d<A>
    if (pa->GetBinContent(i)!=0 && pb->GetBinContent(i)!=0) {
      double y = pb->GetBinContent(i) / pa->GetBinContent(i);
      double ey = 2*pd->GetBinError(i); // x2?
      //double ex = pa->GetBinError(i) * pa->GetBinCenter(i);
      int n = g->GetN();
      g->SetPoint(n, x, y);
      g->SetPointError(n, ex, ey);
    }
  } // for i
  return g;
} // tagandprobe

TGraphErrors *directmatch(TProfile *pt, TProfile *p, bool invert = false) {

  TGraphErrors *g = new TGraphErrors(0);
  for (int i = 1; i != p->GetNbinsX()+1; ++i) {
    //double x = p->GetBinCenter(i); // <A>, or <B>
    //if (invert) x = p->GetBinContent(i) * x; // <A/B>*<B>~<A>
    double x = pt->GetBinCenter(i); // <A>
    double ex = pt->GetBinError(i); // d<A>
    if (p->GetBinContent(i)!=0) {
      double y = p->GetBinContent(i); // <A/B> or <B/A>
      if (invert) y = 1./y; // 1/<A/B>~<B>/<A>
      double ey = p->GetBinError(i);
      //double ex = p->GetBinError(i) * x;
      int n = g->GetN();
      g->SetPoint(n, x, y);
      g->SetPointError(n, ex, ey);
    }
  } // for i
  return g;
} // directmatch

TGraphErrors *directaverage(TProfile *pt, TProfile *p) {

  TGraphErrors *g = new TGraphErrors(0);
  for (int i = 1; i != p->GetNbinsX()+1; ++i) {
    if (p->GetBinContent(i)!=0) {

      //double x = p->GetBinCenter(i); // 0.5*(B+A)
      double y = p->GetBinContent(i); // (B-A)/(B+A)
      // 2x  = B+A
      // 2xy = B-A
      // => 2B = 2x+2xy, 2A = 2x-2xy
      // B/A = (x+xy)/(x-xy) = (1+y)/(1-y)

      //x = x-x*y; // <A>
      double x = pt->GetBinContent(i); // <A>
      double ex = p->GetBinContent(i); // d<A>
      y = (1+y)/(1-y);  // <B>/<A>
      double ey = 2*p->GetBinError(i); // x2?
      //double ex = p->GetBinError(i) * x;
      int n = g->GetN();
      g->SetPoint(n, x, y);
      g->SetPointError(n, ex, ey);
    }
  } // for i
  return g;
} // directmatch

bool scaleData = true;
void scaleGraph(TGraphErrors *g, double scale) {
  for (int i = 0; i != g->GetN(); ++i) {
    g->SetPoint(i, g->GetX()[i], g->GetY()[i]*scale);
  }
}

void fixJES(TGraphErrors *g, TProfile *pjesa, TProfile *pjesb) {
  for (int i = 0; i != g->GetN(); ++i) {
    double pta = g->GetX()[i];
    double ptb = pta * g->GetY()[i];
    double jesa = pjesa->Interpolate(pta);
    double jesb = pjesb->Interpolate(ptb);
    g->SetPoint(i, pta*jesa/jesb, g->GetY()[i]*(jesb/jesa));
  }
}

void drawCompareLiteHLT(string run = "2022F_ZB_v2") {

  setTDRStyle();
  TDirectory *curdir = gDirectory;

  const char *crun = run.c_str();
  TFile *f = new TFile(Form("files/compareLiteHLT_%s.root",crun),"READ");
  assert(f && !f->IsZombie());

  string sA = "22Sep2023";;
  string sB = "HLT";
  const char *cA = sA.c_str();
  const char *cB = sB.c_str();
  
  double xmin = 15;//600;
  double xmax = 1000;//4000;//3500;
  double ymin = 0.90;
  double ymax = 1.35;
  
  // Background canvas
  TH1D *h = tdrHist("h","#LTp_{T}(B)#GT / #LTp_{T}(A)#GT", ymin,ymax,
		    "#LTp_{T}(A)#GT (GeV)",xmin,xmax);
  lumi_136TeV = run.c_str();
  extraText = "Private";
  TCanvas *c1 = tdrCanvas("c1",h,8,11,kSquare);
  gPad->SetLogx();
  
  // Tag-and-probe
  TProfile *pta_tp = (TProfile*)f->Get("pta_tp"); assert(pta_tp);
  TProfile *pa_tp = (TProfile*)f->Get("pa_tp"); assert(pa_tp);
  TProfile *pb_tp = (TProfile*)f->Get("pb_tp"); assert(pb_tp);
  TProfile *pd_tp = (TProfile*)f->Get("pd_tp"); assert(pd_tp);
  TGraphErrors *g = tagandprobe(pta_tp,pa_tp,pb_tp,pd_tp);

  // Direct match
  TProfile *pta_dm = (TProfile*)f->Get("pta_dm"); assert(pta_dm);
  TProfile *pa_dm = (TProfile*)f->Get("pa_dm"); assert(pa_dm);
  TGraphErrors *ga = directmatch(pta_dm,pa_dm);
  TProfile *ptb_dm = (TProfile*)f->Get("ptb_dm"); assert(ptb_dm);
  TProfile *pb_dm = (TProfile*)f->Get("pb_dm"); assert(pb_dm);
  TGraphErrors *gb = directmatch(ptb_dm,pb_dm,true);
  TProfile *ptd_dm = (TProfile*)f->Get("ptd_dm"); assert(ptd_dm);
  TProfile *pd_dm = (TProfile*)f->Get("pd_dm"); assert(pd_dm);
  TGraphErrors *gd = directaverage(ptd_dm,pd_dm);

  // JES fix
  if (patchJES) {
    TProfile *pjesa = (TProfile*)f->Get("pjesa_dm"); assert(pjesa);
    TProfile *pjesb = (TProfile*)f->Get("pjesb_dm"); assert(pjesb);

    fixJES(g, pjesa, pjesb);
    fixJES(ga, pjesa, pjesb);
  }
  
  TLine *l = new TLine();
  l->SetLineStyle(kDashed);
  l->SetLineColor(kGray+1);
  l->DrawLine(xmin,1,xmax,1);
  l->SetLineStyle(kDotted);
  l->DrawLine(40,ymin,40,ymax);

  TLatex *t = new TLatex(); t->SetNDC(); t->SetTextSize(0.045);
  t->DrawLatex(0.75,0.60,"|#eta| < 1.3");
  t->DrawLatex(0.50,0.22,Form("B: %s",cB));
  t->DrawLatex(0.50,0.17,Form("A: %s",cA));

  tdrDraw(ga,"Pz",kOpenTriangleUp,kBlue);
  tdrDraw(gd,"Pz",kOpenDiamond,kGreen+2);
  tdrDraw(gb,"Pz",kOpenTriangleDown,kRed);
  tdrDraw(g,"Pz",kFullCircle,kBlack);

  // SPRH -3% variation
  //if (!fhh) fhh = new TF1("fhh","[p0]+[p1]*pow(x/[p2],[p3])/(1+pow(x/[p2],[p3]))*(1-pow(x/[p2],-[p3]))",15,4500);
  //fhh->SetParameters(-0.7938, -0.5798, 396.1, 1.412);

  double fitxmin = 40;
  TF1 *f1 = new TF1("f1","[0]+[1]*0.01*(-0.798-0.5798*pow(x/396.1,1.412)/(1+pow(x/396.1,1.412))*(1-pow(x/396.1,-1.412)))+[2]/x",40,600);
  f1->SetParameters(0,0,0);
  TF1 *f2 = new TF1("f2","[0]+[1]*0.01*(-0.798-0.5798*pow(x/396.1,1.412)/(1+pow(x/396.1,1.412))*(1-pow(x/396.1,-1.412)))+[2]/x",40,600);
  f2->SetParameters(0,0,0);
  
  TMultiGraph *mg = new TMultiGraph();
  mg->Add(g);
  mg->Add(gd);

  f1->SetLineColor(kBlack);
  f1->SetLineWidth(2);
  f1->SetParameters(1.08,-0.05);
  //mg->Fit(f1,"RN");
  g->Fit(f1,"RN");
  f1->Draw("SAME");

  f2->SetLineColor(kGreen+2);
  f2->SetLineWidth(2);
  f2->SetParameters(1.08,-0.05);
  //mg->Fit(f2,"RN");
  gd->Fit(f2,"RN");
  f2->Draw("SAME");
  
  TLegend *leg = new TLegend(0.40,0.90-0.05*4,0.65,0.90, "", "brNDC");
  leg->SetBorderSize(0); leg->SetFillStyle(kNone); leg->SetTextSize(0.045);
  leg->AddEntry(g, "Tag-and-probe", "PLE");
  leg->AddEntry(ga, "Direct match vs A", "PLE");
  leg->AddEntry(gd, "Direct match vs (A+B)/2", "PLe");
  leg->AddEntry(gb, "Direct match vs B", "PLE");
  leg->Draw();

  c1->SaveAs(Form("pdf/drawCompareLiteHLT/drawCompareLiteHLT_%s_vs_%s_TnP_%s.pdf",cB,cA,crun));
} // drawTnP


void drawCompareLiteHLT_IOVs() {

  setTDRStyle();
  TDirectory *curdir = gDirectory;

  string sA = "22Sep2023";
  string sB = "HLT";
  const char *cA = sA.c_str();
  const char *cB = sB.c_str();
  
  double xmin = 15;//600;
  double xmax = 4000;//3500;

  TFile *fout = new TFile(Form("files/compareLite_%s_vs_%s.root",
			       sB.c_str(),sA.c_str()), "RECREATE");
  
  TFile *f2 = new TFile("../l1tau/compareLite/HB_SiPM_down_1M.root","READ"); // hbsipm
  assert(f2 && !f2->IsZombie());
  TH1D *h2 = (TH1D*)f2->Get("RjetPuppi_sipmNonlinDn"); assert(h2);

  // Add +1.5%
  TH1D *h2p = (TH1D*)h2->Clone("h2p");
  for (int i = 1; i != h2p->GetNbinsX()+1; ++i) {
    if (h2p->GetBinContent(i)!=0)
      h2p->SetBinContent(i, h2->GetBinContent(i)+0.015);
  }

  //TFile *f3 = new TFile("../jecsys3/rootfiles/MC_Run3Summer22_PFCutVariation.root","READ"); // MC
  TFile *f3 = new TFile("../jecsys3/rootfiles/DATA_PromptReco-Run2022G-JetMET_PFCutVariation.root","READ"); // DATA
  assert(f3 && !f3->IsZombie());
  //TH1D *h3 = (TH1D*)f3->Get("RjetPuppi_hcalPFCutsUp"); assert(h3); // MC
  TH1D *h3 = (TH1D*)f3->Get("Rjet"); assert(h3); // DATA
  //name["hhpfc"] = "Puppi_hcalPFCutsUp";

  TH1D *h2p3 = (TH1D*)h2p->Clone("h2p3");
  for (int i = 1; i != h2p->GetNbinsX()+1; ++i) {
    h2p3->SetBinContent(i,h2p->GetBinContent(i) *
			h3->Interpolate(h2p->GetBinCenter(i)));
  }
  
  // Fit function from jecsys3/globalFitSettings.h (+1.5%)
  // Run3 wrong SiPM non-linearity corrections for data (1M variant)
  // {"hbsipm","Rjet","-17.81+log(x)*(15.9+log(x)*(-4.719+log(x)*(0.3464+log(x)*(0.08054+log(x)*(-0.01553+log(x)*0.0007183)))))"},
  TF1 *f1s = new TF1("f1s","1.015 + 0.01*(-17.81+log(x)*(15.9+log(x)*(-4.719+log(x)*(0.3464+log(x)*(0.08054+log(x)*(-0.01553+log(x)*0.0007183))))))",600,4000);
  
  // Background canvas
  TH1D *h = tdrHist("h","#LTp_{T}(B)#GT / #LTp_{T}(A)#GT",// 0.92,1.07,
		    //0.92,1.10,
		    0.92,1.20,
		    "#LTp_{T}(A)#GT (GeV)",xmin,xmax);
  
  lumi_136TeV = "Run3 ";
  extraText = "Private";
  TCanvas *c1 = tdrCanvas("c1",h,8,11,kSquare);
  gPad->SetLogx();

  TLine *l = new TLine();
  l->SetLineStyle(kDashed);
  l->SetLineColor(kGray+1);
  l->DrawLine(xmin,1,xmax,1);

  TLatex *t = new TLatex(); t->SetNDC(); t->SetTextSize(0.040);
  t->DrawLatex(0.19,0.75,"|#eta| < 1.3");
  t->DrawLatex(0.50,0.24,Form("B: %s",cB));
  t->DrawLatex(0.50,0.20,Form("A: %s",cA));
  t->DrawLatex(0.50,0.16,"Direct match vs (A+B)/2");

  string viov[] = {"2022CD", "2022E", "2022FG",
		   "2022F", "2022G",
  		   "2023Cv123", "2023Cv4", "2023D", "Run3"};
  const int niov = sizeof(viov)/sizeof(viov[0]);

  map<string, int> marker;
  marker["2022CD"] = kOpenSquare;
  marker["2022E"] = kOpenSquare;
  marker["2022FG"] = kOpenSquare;
  marker["2022F"] = kOpenSquare;
  marker["2022G"] = kOpenSquare;
  marker["2023Cv123"] = kOpenCircle;
  marker["2023Cv4"] = kOpenCircle;
  marker["2023D"] = kOpenCircle;
  marker["Run3"] = kFullDiamond;

  map<string, int> color;
  color["2022CD"] = kGreen+2;
  color["2022E"] = kCyan+2;
  color["2022FG"] = kRed;
  color["2022F"] = kRed+1;
  color["2022G"] = kRed+2;
  color["2023Cv123"] = kOrange+2;
  color["2023Cv4"] = kBlue;
  color["2023D"] = kMagenta+2;
  color["Run3"] = kBlack;

  map<string, double> scale;
  scale["2022CD"] = 1./1.025;
  scale["2022E"] = 1.;
  scale["2022FG"] = 1./1.065;
  scale["2022F"] = 1./1.060;
  scale["2022G"] = 1./1.070;
  scale["2023Cv123"] = 1./1.025;
  scale["2023Cv4"] = 1.;
  scale["2023D"] = 1.005;
  scale["Run3"] = 1./1.025;
  
  map<string, const char*> legend;
  if (scaleData) {
    legend["2022CD"] = "2022CD+2.5%";
    legend["2022E"] = "2022E";
    legend["2022FG"] = "2022FG+6.5%";
    legend["2022F"] = "2022F+6.0%";
    legend["2022G"] = "2022G+7.0%";
    legend["2023Cv123"] = "2023Cv123+2.5%";//+6.0% (not updated)";
    legend["2023Cv4"] = "2023Cv4";
    legend["2023D"] = "2023D-0.5%";
    legend["Run3"] = "Run3+2.5%";
  }
  else {
    legend["2022CD"] = "2022CD";
    legend["2022E"] = "2022E";
    legend["2022FG"] = "2022FG";
    legend["2022F"] = "2022F";
    legend["2022G"] = "2022G";
    legend["2023Cv123"] = "2023Cv123";
    legend["2023Cv4"] = "2023Cv4";
    legend["2023D"] = "2023D";
    legend["Run3"] = "Run3";
  }
    
  map<string, const char*> file;
  file["2022CD"] = "2022CD_v2";
  file["2022E"] = "2022E_v2";
  file["2022FG"] = "2022FG_v2";
  file["2022F"] = "2022F_v2";
  file["2022G"] = "2022G_v2";
  file["2023Cv123"] = "2023Cv123_v2";
  file["2023Cv4"] = "2023Cv4_v2";
  file["2023D"] = "2023D_v2";
  file["Run3"] = "Run3_v2";

  //TLegend *leg = tdrLeg(0.40,0.90-0.042*(niov+1),0.65,0.90);
  TLegend *leg(0);
  if (scaleData)
    leg = tdrLeg(0.32,0.90-0.035*(niov+0),0.57,0.90);
  else
    leg = tdrLeg(0.35,0.90-0.035*(niov+0),0.60,0.90);

  leg->SetTextSize(0.040);

  TLegend *leg2 = tdrLeg(0.60,0.90-0.035*(3),0.85,0.90);
  leg2->SetTextSize(0.040);
  
  tdrDraw(h2p,"Pz",kFullCircle,kGreen+1);
  tdrDraw(h3,"Pz",kFullCircle,kGreen+2); h3->SetMarkerSize(0.9); // hhpfc
  tdrDraw(h2p3,"Pz",kFullCircle,kGreen+3); h2p3->SetMarkerSize(0.8);
  f1s->SetLineColor(kGreen+2);
  f1s->SetLineWidth(2);
  f1s->Draw("SAME");
  //leg->AddEntry(h2p,"MC prediction + 1.5%","PLE");
  leg2->AddEntry(h2p,"MC SiPM + 1.5%","PLE");
  leg2->AddEntry(h3,"22G HcalPFcuts","PLE");
  leg2->AddEntry(h2p3,"Both","PLE");
  h2p->SetLineWidth(2);
  h3->SetLineWidth(2);
  h2p3->SetLineWidth(2);
  
  // Draw direcct match results
  TGraphErrors *grun3(0);
  for (int iov = 0; iov != niov; ++iov) {

    string run = viov[iov];
    const char *crun = run.c_str();
    const char *cfile = file[run];
    TFile *f = new TFile(Form("files/compareLite_%s.root",cfile),"READ");
    assert(f && !f->IsZombie());

    // Direct match
    TProfile *ptd_dm = (TProfile*)f->Get("ptd_dm"); assert(ptd_dm);
    TProfile *pd_dm = (TProfile*)f->Get("pd_dm"); assert(pd_dm);
    TGraphErrors *g = directaverage(ptd_dm,pd_dm);
    if (scaleData) scaleGraph(g,scale[run]);

    TProfile *pjesa = (TProfile*)f->Get("pjesa_dm"); assert(pjesa);
    TProfile *pjesb = (TProfile*)f->Get("pjesb_dm"); assert(pjesb);
    fixJES(g, pjesa, pjesb);
    
    tdrDraw(g,"Pz",marker[crun],color[crun]);
    leg->AddEntry(g, legend[crun], "PLE");
    
    if (run=="Run3") {
      grun3 = g;
      g->SetLineWidth(2);
    }

    if (true) { // Save output after some cleaning
      fout->cd();
      g = (TGraphErrors*)g->Clone(Form("djes_%s",crun));
      for (int i = g->GetN()-1; i != -1; --i) {
	if (g->GetY()[i]<0.9) g->RemovePoint(i);
      }
      g->Write(Form("djes_%s",crun));
      curdir->cd();
    }
  }
  
  // SPRH -3% variation
  TF1 *f1 = new TF1("f1","[0]+[1]*0.01*(-0.798-0.5798*pow(x/396.1,1.412)/(1+pow(x/396.1,1.412))*(1-pow(x/396.1,-1.412)))+[2]*-0.1*x/3000.",600,3300);
  f1->SetParameters(1,1,1);
  f1->SetRange(600,4000);
  
  f1->SetLineColor(kBlack);
  f1->SetLineWidth(2);
  f1->SetParameters(1.08,-0.05);
  grun3->Fit(f1,"RN");
  f1->Draw("SAME");

  if (scaleData)
    c1->SaveAs(Form("pdf/drawCompareLiteHLT/drawCompareLiteHLT_%s_vs_%s_IOVs_scaled.pdf",cB,cA));
  else
    c1->SaveAs(Form("pdf/drawCompareLiteHLT/drawCompareLiteHLT_%s_vs_%s_IOVs.pdf",cB,cA));
  fout->Close();
} //drawCompareLiteHLT_IOVs
