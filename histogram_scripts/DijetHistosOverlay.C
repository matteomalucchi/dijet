// Purpose: overlay DijetHistos with DESY results
#include "TFile.h"
#include "../tdrstyle_mod22.C"
#include "TGraphErrors.h"
#include "TKey.h"
#include "TLatex.h"
#include "TLine.h"
#include "TH2D.h"
#include "TH3D.h"
#include "TProfile2D.h"
#include "TGraph.h"
#include "TF1.h"
#include <string>
#include <fstream>

bool debug = false;
bool useMPF = true;//false; // MPF instead of HDM
bool addZjetJER = false;
bool addZjetJES = false;//true;
bool addColorJES = true; // pT,tag + pT,probe
bool addColorJES2 = true;//true; // DB + MPF

int findBin(TH2D *h2, double x, double *xnew = 0);
void addBins(TH1D *h1to, TH2D *h2from, int i1, int i2,
	     TH1D *h1count, TH2D *h2count);
void rebin(TH1D *h1, TH1D *h1n, TH1D *h1old, TH1D *h1nold);

void DijetHistosOverlays(string obs, string data, string spt = "PtAVP",
//void DijetHistosOverlays(string obs, string data, string spt = "PtTag",
//void DijetHistosOverlays(string obs, string data, string spt = "PtProbe",
//void DijetHistosOverlays(string obs, string data, string spt = "PtAve",
			 bool data3=false); // MPF (MPF, mpf2, mpfN, mpfU) results
void DijetHistosOverlayPtBins(string obs); // pT,tag vs pT,probe (vs pT,avp)
void DijetHistosOverlayPt(string fdt, string fmc, string fmc2, string era);  // pT spectrum / counts
void DijetHistosOverlayJER(string sdt, string smc, string era); // JER+JER SF
void DijetHistosOverlayJES(string sdt, string smc, string era); // JES+L2RES

struct JER {
  double eta, deta;
  double n0_dt, s_dt, c_dt, d_dt, npu_dt;
  double n0_mc, s_mc, c_mc, d_mc, npu_mc;
};

struct JES {
  double eta, deta;
  double p0, p1;
  //double p0_dt, p1_dt;
  //double p0_mc, p1_mc;
};

void DijetHistosOverlay() {

  /*
  DijetHistosOverlays("MPF","data");
  DijetHistosOverlays("mpf2","data");
  DijetHistosOverlays("mpfN","data");
  DijetHistosOverlays("mpfU","data");

  DijetHistosOverlays("MPF","mc");
  DijetHistosOverlays("mpf2","mc");
  DijetHistosOverlays("mpfN","mc");
  DijetHistosOverlays("mpfU","mc");

  //DijetHistosOverlays("MPF","mc");
  //DijetHistosOverlays("mpf2","mc");
  //DijetHistosOverlays("MPF","data");
  //DijetHistosOverlays("mpf2","data");

  //DijetHistosOverlays("mpf2","data",true);
  //DijetHistosOverlays("MPF","data",true);
  //DijetHistosOverlays("mpfU","data",true);

  DijetHistosOverlayPtBins("mpfU");
  DijetHistosOverlayPtBins("mpfN");
  DijetHistosOverlayPtBins("mpf2");
  DijetHistosOverlayPtBins("MPF");
  */
  
  // Before MC JER SF
  /*
  DijetHistosOverlayJER("haddfiles/jmenano_data_cmb_UL2016APV_v26c.root",
  			"../rootfiles/jmenano_mc_cmb_UL2016APVMG_v26.root",
  			"UL2016APV_ZB_v26c");
  DijetHistosOverlayJER("haddfiles/jmenano_data_cmb_UL2016GH_v26c.root",
  			"../rootfiles/jmenano_mc_cmb_UL2016MG_v26.root",
  			"UL2016GH_ZB_v26c");
  DijetHistosOverlayJER("haddfiles/jmenano_data_cmb_UL2017_v26.root",
  			"../rootfiles/jmenano_mc_cmb_UL2017MG_v26.root",
  			"UL2017_ZB_v26c");
  DijetHistosOverlayJER("haddfiles/jmenano_data_cmb_UL2018_v26c.root",
  			"../rootfiles/jmenano_mc_cmb_UL2018MG_v26.root",
  			"UL2018_ZB_v26c");
  DijetHistosOverlayJER("haddfiles/jmenano_data_cmb_Run2_v26c.root",
  			"haddfiles/jmenano_mc_cmb_Run2_v26.root",
  			"Run2_ZB_v26c");
  */
  //DijetHistosOverlayJES("haddfiles/jmenano_data_cmb_UL2017_v26.root",
  //			"../rootfiles/jmenano_mc_cmb_UL2017MG_v26.root",
  //			"UL2017_ZB_v26c");

  // After MC JER SF
  /*
  DijetHistosOverlayJER("haddfiles/jmenano_data_cmb_UL2016APV_v26c.root",
  			"../rootfiles/jmenano_mc_cmb_UL2016APVMG_v27.root",
  			"UL2016APV_ZB_v27");
  DijetHistosOverlayJER("haddfiles/jmenano_data_cmb_UL2016GH_v26c.root",
  			"../rootfiles/jmenano_mc_cmb_UL2016MG_v27.root",
  			"UL2016GH_ZB_v27");
  DijetHistosOverlayJER("haddfiles/jmenano_data_cmb_UL2017_v26.root",
  			"../rootfiles/jmenano_mc_cmb_UL2017MG_v27.root",
  			"UL2017_ZB_v27");
  DijetHistosOverlayJER("haddfiles/jmenano_data_cmb_UL2018_v26c.root",
  			"../rootfiles/jmenano_mc_cmb_UL2018MG_v27.root",
  			"UL2018_ZB_v27");
  DijetHistosOverlayJER("haddfiles/jmenano_data_cmb_Run2_v26c.root",
  			"haddfiles/jmenano_mc_cmb_Run2_v27.root",
  			"Run2_ZB_v27");
  */

  /*
  DijetHistosOverlayJES("haddfiles/jmenano_data_cmb_Run2_v26c.root",
  			"haddfiles/jmenano_mc_cmb_Run2_v26.root",
  			"Run2_ZB_v26"); // before JER SF
  DijetHistosOverlayJES("haddfiles/jmenano_data_cmb_Run2_v26c.root",
  			"haddfiles/jmenano_mc_cmb_Run2_v27.root",
  			"Run2_ZB_v27"); // After JER SF
  */

  //DijetHistosOverlayJES("../jecsys3/../rootfiles/Iita_20230814/jmenano_data_cmb_2022C_v1.root","../rootfiles/jmenano_mc_cmb_UL2018MG_v26.root","2022C_v1_vs_UL18_v26"); // before JER SF

  // Run3 (v29->v34b)
  DijetHistosOverlayJES("../files/jmenano_data_cmb_2022CD_JME_v34b.root","../files/jmenano_mc_cmb_Summer22MG_v34b.root","2022CD_v34b");
  DijetHistosOverlayJES("../files/jmenano_data_cmb_2022E_JME_v34b.root","../files/jmenano_mc_cmb_Summer22MG_v34b.root","2022E_v34b"); // tbd: 22EE
  DijetHistosOverlayJES("../files/jmenano_data_cmb_2022FG_JME_v34b.root","../files/jmenano_mc_cmb_Summer22MG_v34b.root","2022FG_v34b"); // tbd: 22EE
  DijetHistosOverlayJES("../files/jmenano_data_cmb_2023BCv123_JME_v34b.root","../files/jmenano_mc_cmb_Summer22MG_v34b.root","2023BCv123_v34b"); // tbd: 23
  DijetHistosOverlayJES("../files/jmenano_data_cmb_2023Cv4_JME_v34b.root","../files/jmenano_mc_cmb_Summer22MG_v34b.root","2023Cv4_v34b"); // tbd: 23
  DijetHistosOverlayJES("../files/jmenano_data_cmb_2023D_JME_v34b.root","../files/jmenano_mc_cmb_Summer22MG_v34b.root","2023D_v34b"); // tbd: 23

  
  //DijetHistosOverlayJES("haddfiles/jmenano_data_cmb_UL2017_v26.root",
  //			"../files/jmenano_mc_cmb_UL2017MG_v27.root",
  //			"UL2017_ZB_v27");
} // DijetHistosOverlay

void DijetHistosOverlays(string obs, string data, string spt,
			 bool data3) {

  setTDRStyle();
  TDirectory *curdir = gDirectory;

  TLatex *tex = new TLatex();
  tex->SetNDC(); tex->SetTextSize(0.045*1.5);
  TLine *l = new TLine();

  string s = Form("_%s_%s",data.c_str(),obs.c_str());
  const char *c = s.c_str();
  const char *cpt = spt.c_str();

  TFile *f1(0), *f12(0), *f13(0);
  if (data=="data") f1 = new TFile("../files/jmenano_data_cmb_v22ul16.root","READ");
  if (data=="mc") f1 = new TFile("../files/jmenano_mc_cmb_v23ul16mg.root","READ");
  //if (data=="mc") f1 = new TFile("../files/jmenano_mc_cmb_v23ul16flat.root","READ");
  //if (data=="data") f1 = new TFile("../files/jmenano_data_cmb_v21ul16.root","READ");
  //if (data=="mc") f1 = new TFile("../files/jmenano_mc_cmb_v20ul16flatmc.root","READ");
  //if (data=="data") f1 = new TFile("../files/jmenano_data_cmb.root","READ");
  //if (data=="mc") f1 = new TFile("../files/jmenano_mc_cmb.root","READ");

  if (data3) {
    f1 = new TFile("../files/dijet2_a_dijet_cmb.root","READ");
    f12 = new TFile("../files/dijet2_b_asymm_cmb.root","READ");
    f13 = new TFile("../files/dijet2_c_allgood_cmb.root","READ");
    assert(f12 && !f12->IsZombie());
    assert(f13 && !f13->IsZombie());
  }
  assert(f1 && !f1->IsZombie());

  TProfile2D *p2(0), *p22(0), *p23(0);
  TH2D *h2n(0), *h2n2(0), *h2n3(0);
  if (spt=="PtAVP" || spt=="PtAve") {
    /*
      if (obs=="MPF") p2 = (TProfile2D*)f1->Get("Dijet/p2m0ab");
      if (obs=="mpf2") p2 = (TProfile2D*)f1->Get("Dijet/p2m2ab");
      if (obs=="mpfN") p2 = (TProfile2D*)f1->Get("Dijet/p2mnab");
      if (obs=="mpfU") p2 = (TProfile2D*)f1->Get("Dijet/p2muab");
    */
    if (obs=="MPF") p2 = (TProfile2D*)f1->Get("Dijet2/p2m0");
    if (obs=="mpf2") p2 = (TProfile2D*)f1->Get("Dijet2/p2m2");
    if (obs=="mpfN") p2 = (TProfile2D*)f1->Get("Dijet2/p2mn");
    if (obs=="mpfU") p2 = (TProfile2D*)f1->Get("Dijet2/p2mu");
    h2n = (TH2D*)f1->Get("Dijet2/h2pteta"); assert(h2n); // Dijet2
  }
  if (spt=="PtTag") {
    if (obs=="MPF") p2 = (TProfile2D*)f1->Get("Dijet2/p2m0tc");
    if (obs=="mpf2") p2 = (TProfile2D*)f1->Get("Dijet2/p2m2tc");
    if (obs=="mpfN") p2 = (TProfile2D*)f1->Get("Dijet2/p2mntc");
    if (obs=="mpfU") p2 = (TProfile2D*)f1->Get("Dijet2/p2mutc");
    h2n = (TH2D*)f1->Get("Dijet2/h2ptetatc"); assert(h2n); // Dijet2
  }
  if (spt=="PtProbe") {
    if (obs=="MPF") p2 = (TProfile2D*)f1->Get("Dijet2/p2m0pf");
    if (obs=="mpf2") p2 = (TProfile2D*)f1->Get("Dijet2/p2m2pf");
    if (obs=="mpfN") p2 = (TProfile2D*)f1->Get("Dijet2/p2mnpf");
    if (obs=="mpfU") p2 = (TProfile2D*)f1->Get("Dijet2/p2mupf");
    h2n = (TH2D*)f1->Get("Dijet2/h2ptetatc"); assert(h2n); // Dijet2
  }      
  assert(p2);
  assert(h2n);
  //TH2D *h2 = p2->ProjectionXY(Form("h2%s",c));
  //TH2D *h2n = (TH2D*)f1->Get("Dijet/h2pteta_aball"); assert(h2n); // Dijet
  //h2n = (TH2D*)f1->Get("Dijet2/h2pteta"); assert(h2n); // Dijet2
  
  if (data3) {
    p22 = (TProfile2D*)f12->Get(Form("Dijet2/%s",p2->GetName())); assert(p22);
    p23 = (TProfile2D*)f13->Get(Form("Dijet2/%s",p2->GetName())); assert(p23);
    h2n2 = (TH2D*)f12->Get("Dijet2/h2pteta"); assert(h2n2);
    h2n3 = (TH2D*)f13->Get("Dijet2/h2pteta"); assert(h2n3);
  }
  
  
  // TFile *f2 = new TFile("../jecsys2020/../files/CombinationFiles-Run2016FGH-3.root","READ");
  //TFile *f2 = new TFile(Form("../files/CombinationFiles-Run2016FGH-%s.root",cpt),"READ");
  TFile *f2 = new TFile(Form("../files/CombinationFiles-Run2016FGH-%s.root",spt=="PtAve" ? "PtAVP" : cpt),"READ");
  assert(f2 && !f2->IsZombie());

  f2->cd(data.c_str());//"data");
  TDirectory *d2 = gDirectory;

  curdir->cd();

  TCanvas *c1 = new TCanvas(Form("c1%s",c),Form("c1%s",c),1200,600);
  c1->Divide(6,3,0,0);

  TCanvas *c2 = new TCanvas(Form("c2%s",c),Form("c2%s",c),1200,600);
  c2->Divide(6,3,0,0);

  int neta(0);
  TIter next(d2->GetListOfKeys());
  while (TKey *key = (TKey*)next()) {

    // Recurse directory structure
    if (!(string(key->GetClassName())=="TDirectoryFile")) continue;
    if (debug) cout << key->GetName() << "->";
    TDirectory *d2s = (TDirectory*)key->ReadObj();
    d2s->cd();
    
    int ietamin, ietamax;
    sscanf(key->GetName(),"eta_%d_%d",&ietamin,&ietamax);

    c1->cd(++neta);
    gPad->SetLogx();

    TH1D *h = tdrHist(Form("h%s_%d",c,neta),Form("%s (%s)",obs.c_str(),data.c_str()),0.98,1.07,"p_{T,avp} (GeV)");
    if (spt=="PtAVP") {
      if (obs=="MPF" || obs=="mpf2") {
	if (neta>=1)  h->GetYaxis()->SetRangeUser(0.97,1.07);
	//if (neta>=7)  h->GetYaxis()->SetRangeUser(0.98,1.08);
	if (neta>=7)  h->GetYaxis()->SetRangeUser(0.90,1.10);
	if (neta>=13) h->GetYaxis()->SetRangeUser(0.80,1.25);
      }
      if (obs=="mpfN" || obs=="mpfU") {
	if (neta>=1) h->GetYaxis()->SetRangeUser(-0.03,0.05);
	if (neta>=7) h->GetYaxis()->SetRangeUser(-0.05,0.15);
	if (neta>=13) h->GetYaxis()->SetRangeUser(-0.05,0.25);
      }
    }
    if (spt=="PtTag" || spt=="PtProbe" || spt=="PtAve") {
      if (obs=="MPF" || obs=="mpf2") {
	if (neta>=1)  h->GetYaxis()->SetRangeUser(0.6,1.4);
	if (neta>=7)  h->GetYaxis()->SetRangeUser(0.6,1.4);
	if (neta>=13) h->GetYaxis()->SetRangeUser(0.6,1.4);
      }
      if (obs=="mpfN" || obs=="mpfU") {
	if (neta>=1) h->GetYaxis()->SetRangeUser(-0.3,0.3);
	if (neta>=7) h->GetYaxis()->SetRangeUser(-0.3,0.3);
	if (neta>=13) h->GetYaxis()->SetRangeUser(-0.3,0.3);
      }
      if (spt=="PtTag") h->SetXTitle("p_{T,tag} (GeV)");
      if (spt=="PtProbe") h->SetXTitle("p_{T,probe} (GeV)");
      if (spt=="PtAve") h->SetXTitle("p_{T,avp} (GeV)");
    }

    TH1D *h1c = (TH1D*)d2s->Get(Form("%s_RawNEvents_a100",data.c_str()));
    assert(h1c);
    TGraphErrors *g0(0);
    if (obs=="MPF") g0 = (TGraphErrors*)d2s->Get("mpfchs_dijet_a100");
    if (obs=="mpf2") g0 = (TGraphErrors*)d2s->Get("mpfchs2_dijet_a100");
    if (obs=="mpfN") g0 = (TGraphErrors*)d2s->Get("mpfchsN_dijet_a100");
    if (obs=="mpfU") g0 = (TGraphErrors*)d2s->Get("mpfchsU_dijet_a100");
    assert(g0);

    h->Draw();
    l->DrawLine(15,1,3500,1);
    //g0->SetLineWidth(2);
    g0->SetLineColor(kRed);
    g0->SetMarkerColor(kRed);
    g0->Draw("SAMEPz");

    double etamin;
    int i1m = findBin(p2, -0.1*ietamin);
    int i1p = findBin(p2, +0.1*ietamin, &etamin);

    double etamax;
    int i2m = findBin(p2, -0.1*ietamax);
    int i2p = findBin(p2, +0.1*ietamax, &etamax);

    //int nbins = (i2p-i1p) + (i1m-i2m); // Dijet
    int nbins = (i2p-i1p); // Dijet2

    //TH1D *h0m = p2->ProjectionY(Form("h0m_%d",neta),i2m,i1m-1);
    //TH1D *h0p = p2->ProjectionY(Form("h0p_%d",neta),i1p,i2p-1);
    //TH1D *h0 = (TH1D*)h0m->Clone(Form("h0_%d",neta));
    //h0->Add(h0p);
    //h0->Scale(1./nbins);
    //h0->Draw("SAME");
						
    TH1D *h0 = p2->ProjectionY(Form("h0m%s_%d",c,neta),-1,-1);
    TH1D *h1 = (TH1D*)h0->Clone(Form("h1%s_%d",c,neta)); h1->Reset();
    TH1D *h1n = (TH1D*)h0->Clone(Form("h1n%s_%d",c,neta)); h1n->Reset();
    //addBins(h1,p2,i2m,i1m-1,h1n,h2n); // Dijet only
    addBins(h1,p2,i1p,i2p-1,h1n,h2n); // Dijet2+Dijet
    h1->SetLineColor(kGreen+2);
    //h1->Draw("SAMEH");

    //doublx xr[] = {15, 21, 28, 37, 49,
    //		     59, 86, 110, 132, 170, 204, 236, 279, 302, 373, 460, 575,
    //		     638, 737, 846, 967, 1101, 1248,
    //               1410, 1588, 1784, 2000, 2238, 2500, 2787, 3103};
    //double xb[] = {59, 85, 104, 170, 236, 302, 370, 460, 575, 1000, 2000};
    double xb[] = {15,28, 59, 86, 110, 170, 236, 302, 373, 460, 575,
		   1000, 2000, 3103};
    double nb = sizeof(xb)/sizeof(xb[0])-1;
    //double xf[] = {59, 86, 110, 132, 204, 279, 373};
    double xf[] = {59, 86, 110, 132, 204, 279, 373,  460, 575,
		   1000, 2000, 3103};
    int nf = sizeof(xf)/sizeof(xf[0])-1;
    double *x = (etamin>2.8 ? xf : xb);
    int n = (etamin>2.8 ? nf : nb);
    TH1D *h1old = h1;
    TH1D *h1nold = h1n;
    h1 = new TH1D(Form("h1new%s_%d",c,neta),"",n,x);
    h1n = new TH1D(Form("h1nnew%s_%d",c,neta),"",n,x);
    rebin(h1,h1n,h1old,h1nold);
    h1->SetLineColor(kGreen+2);
    h1->SetMarkerStyle(kNone);
    h1->Draw("SAMEH");

    if (data3) {
      TH1D *h12 = p22->ProjectionY(Form("h12_%s_%d",c,neta),i1p,i2p-1);//-1,-1);
      TH1D *h13 = p23->ProjectionY(Form("h13_%s_%d",c,neta),i1p,i2p-1);//-1,-1);
      h12->SetLineColor(kBlue);
      h12->SetLineStyle(kDotted);
      h12->Draw("SAMEH");
      h13->SetLineColor(kRed);
      h13->Draw("SAMEH");
    }

    tex->DrawLatex(0.60,0.92,Form("eta_%02d_%02d (%d)",ietamin,ietamax,nbins));
    tex->DrawLatex(0.60,0.86,Form("%1.3f<|#eta|<%1.3f",etamin,etamax));

    if (neta==1 || neta%6==0) {
      TLegend *leg = tdrLeg(0.60,0.83-2*0.06,0.90,0.83);
      leg->SetTextSize(0.045*1.5);
      leg->AddEntry(g0,"DESY mini","PLE");
      leg->AddEntry(h1,"JME nano","PLE");
    }	      

    // Jet counts
    c2->cd(neta);
    gPad->SetLogx();
    gPad->SetLogy();

    TH1D *h2 = tdrHist(Form("h2%s_%d",c,neta),Form("%s (%s)","Counts",data.c_str()),0.5,1e7,"p_{T,avp} (GeV)");    

    h2->Draw();
    h1c->SetMarkerColor(kRed);
    h1c->SetLineColor(kRed);
    if (etamin<1.3) h1c->Scale(2.);
    h1c->Draw("SAMEH");
    h1n->SetMarkerStyle(kNone);
    h1n->SetLineColor(kGreen+2);
    h1n->Draw("SAMEHE");

    tex->DrawLatex(0.60,0.92,Form("eta_%02d_%02d (%d)",ietamin,ietamax,nbins));
    tex->DrawLatex(0.60,0.86,Form("%1.3f<|#eta|<%1.3f",etamin,etamax));

    gPad->RedrawAxis();

  } // while tkey

  c1->SaveAs(Form("pdf/DijetHistosOverlay_%s_%s_%s_%s.pdf","2016GH",
		  data.c_str(),obs.c_str(),cpt));
  c2->SaveAs(Form("pdf/DijetHistosOverlay_%s_%s_%s_%s.pdf","2016GH",
		  data.c_str(),"counts",cpt));
} // DijetHistosOverlay


void DijetHistosOverlayPtBins(string obs) {

  setTDRStyle();
  TDirectory *curdir = gDirectory;

  TLatex *tex = new TLatex();
  tex->SetNDC(); tex->SetTextSize(0.045*1.5);
  TLine *l = new TLine();

  const char *co = obs.c_str();
  const char *cera = "2016GH";

  TFile *f1(0), *f1m(0), *f1p(0);
  f1 = new TFile("../files/jmenano_data_cmb_v22ul16.root","READ");
  assert(f1 && !f1->IsZombie());
  f1m = new TFile("../files/jmenano_mc_cmb_v23ul16mg.root","READ");
  assert(f1m && !f1m->IsZombie());
  //f1p = new TFile("../files/jmenano_mc_cmb_v23ul16flat.root","READ");
  //assert(f1p && !f1p->IsZombie());

  TProfile2D *p2a(0), *p2t(0), *p2p(0);
  TProfile2D *p2am(0), *p2tm(0), *p2pm(0);
  //TProfile2D *p2ap(0), *p2tp(0), *p2pp(0);
  //TH2D *h2na(0), *h2nt(0), *h2np(0);

  map<string,string> mh;
  mh["MPF"] = "Dijet2/p2m0";
  mh["mpf2"] = "Dijet2/p2m2";
  mh["mpfN"] = "Dijet2/p2mn";
  mh["mpfU"] = "Dijet2/p2mu";

  const char *ch = mh[obs].c_str();
  p2a = (TProfile2D*)f1->Get(Form("%s",ch));   assert(p2a);
  p2t = (TProfile2D*)f1->Get(Form("%stc",ch)); assert(p2t);
  p2p = (TProfile2D*)f1->Get(Form("%spf",ch)); assert(p2p);

  p2am = (TProfile2D*)f1m->Get(Form("%s",ch));   assert(p2am);
  p2tm = (TProfile2D*)f1m->Get(Form("%stc",ch)); assert(p2tm);
  p2pm = (TProfile2D*)f1m->Get(Form("%spf",ch)); assert(p2pm);

  //p2ap = (TProfile2D*)f1p->Get(Form("%s",ch));   assert(p2ap);
  //p2tp = (TProfile2D*)f1p->Get(Form("%stc",ch)); assert(p2tp);
  //p2pp = (TProfile2D*)f1p->Get(Form("%spf",ch)); assert(p2pp);

  curdir->cd();

  TCanvas *c1 = new TCanvas(Form("c1%s",co),Form("c1%s",co),1200,600);
  c1->Divide(6,3,0,0);

  TCanvas *c2 = new TCanvas(Form("c2%s",co),Form("c2%s",co),1200,600);
  c2->Divide(6,3,0,0);

  for (int ieta = 1; ieta != p2a->GetNbinsX()+1; ++ieta) {
    
    c1->cd(ieta);
    gPad->SetLogx();
    
    TH1D *h = tdrHist(Form("h%s_%d",co,ieta),co,0.6,1.5);
    /*
    if (obs=="MPF")  h->GetYaxis()->SetRangeUser(0.8,1.4);
    if (obs=="mpf2") h->GetYaxis()->SetRangeUser(0.5,1.6);
    if (obs=="mpfN") h->GetYaxis()->SetRangeUser(-0.25,0.5);
    if (obs=="mpfU") h->GetYaxis()->SetRangeUser(-0.1,0.2);
    */
    // Common ranges
    if (obs=="MPF" || obs=="mpf2")  h->GetYaxis()->SetRangeUser(0.5,1.6);
    //if (obs=="mpfN" || obs=="mpfU") h->GetYaxis()->SetRangeUser(-0.25,0.5);
    if (obs=="mpfN" || obs=="mpfU") h->GetYaxis()->SetRangeUser(-0.5,0.6);
    h->Draw();

    l->SetLineStyle(kDotted);
    l->SetLineStyle(kGray+1);
    double ymin = h->GetMaximum();//GetYaxis()->GetXmin();
    double ymax = h->GetMinimum();//GetYaxis()->GetXmax();
    l->DrawLine(59,ymin,59,ymax);
    double etamin = p2a->GetXaxis()->GetBinLowEdge(ieta);
    double etamax = p2a->GetXaxis()->GetBinLowEdge(ieta+1);
    double ptmax = 0.5*6500/cosh(etamin);
    l->DrawLine(ptmax,ymin,ptmax,ymax);

    l->SetLineStyle(kDotted);
    l->SetLineStyle(kGray);
    double ptmax2 = 0.7*6500/cosh(etamin);
    l->DrawLine(ptmax2,ymin,ptmax2,ymax);

    l->SetLineStyle(kSolid);
    l->SetLineColor(kBlack);
    l->DrawLine(15,1,3500,1);
    
    TH1D *ha = p2a->ProjectionY(Form("ha%s_%d",co,ieta),ieta,ieta);
    TH1D *ht = p2t->ProjectionY(Form("ht%s_%d",co,ieta),ieta,ieta);
    TH1D *hp = p2p->ProjectionY(Form("hp%s_%d",co,ieta),ieta,ieta);

    TH1D *ham = p2am->ProjectionY(Form("ham%s_%d",co,ieta),ieta,ieta);
    TH1D *htm = p2tm->ProjectionY(Form("htm%s_%d",co,ieta),ieta,ieta);
    TH1D *hpm = p2pm->ProjectionY(Form("hpm%s_%d",co,ieta),ieta,ieta);

    //TH1D *hap = p2ap->ProjectionY(Form("hap%s_%d",co,ieta),ieta,ieta);
    //TH1D *htp = p2tp->ProjectionY(Form("htp%s_%d",co,ieta),ieta,ieta);
    //TH1D *hpp = p2pp->ProjectionY(Form("hpp%s_%d",co,ieta),ieta,ieta);
    
    //tdrDraw(htp,"HIST",kNone,kBlue+1,kDotted,-1,kNone);
    //tdrDraw(hpp,"HIST",kNone,kRed+1,kDotted,-1,kNone);
    //tdrDraw(hap,"HIST",kNone,kGreen+3,kDotted,-1,kNone);

    tdrDraw(htm,"HE",kNone,kBlue,kSolid,-1,kNone);
    tdrDraw(hpm,"HE",kNone,kRed,kSolid,-1,kNone);
    tdrDraw(ham,"HE",kNone,kGreen+2,kSolid,-1,kNone);

    tdrDraw(ht,"Pz",kFullDiamond,kBlue,kNone,-1,kNone);
    tdrDraw(hp,"Pz",kFullDiamond,kRed,kNone,-1,kNone);
    tdrDraw(ha,"Pz",kFullDiamond,kGreen+2,kNone,-1,kNone);
    
    //ht->SetMarkerSize(0.7);
    //hp->SetMarkerSize(0.7);
    //ha->SetMarkerSize(0.7);

    tex->DrawLatex(0.55,0.92,Form("%1.3f<|#eta|<%1.3f",etamin,etamax));

    if (ieta==2 || ieta%6==0) {
      TLegend *leg = tdrLeg(0.55,0.90-3*0.075,0.85,0.90);
      leg->SetTextSize(0.045*1.5);
      leg->AddEntry(ht,"PtTag","PLE");
      leg->AddEntry(ha,"PtAVP","PLE");
      leg->AddEntry(hp,"PtProbe","PLE");
    }
    if (ieta==1 || ieta%6==5) {
      //TLegend *leg = tdrLeg(0.55,0.90-3*0.075,0.85,0.90);
      TLegend *leg = tdrLeg(0.55,0.90-2*0.075,0.85,0.90);
      leg->SetTextSize(0.045*1.5);
      leg->AddEntry(ha,"Data","PLE");
      leg->AddEntry(ham,"MadGraph","PLE");
      //leg->AddEntry(hap,"Pythia8","PL");
    }


    c2->cd(ieta);
    gPad->SetLogx();

    TH1D *h2 = tdrHist(Form("h2%s_%d",co,ieta),Form("Data-MC (%s)",co),-0.1,0.1);
    /*
    if (obs=="MPF")  h2->GetYaxis()->SetRangeUser(-0.05,0.10);
    if (obs=="mpf2") h2->GetYaxis()->SetRangeUser(-0.15,0.15);
    if (obs=="mpfN") h2->GetYaxis()->SetRangeUser(-0.15,0.15);
    if (obs=="mpfU") h2->GetYaxis()->SetRangeUser(-0.05,0.05);
    */
    // Common range
    h2->GetYaxis()->SetRangeUser(-0.15,0.15);
    h2->Draw();

    double ymin2 = h2->GetMaximum();
    double ymax2 = h2->GetMinimum();
    l->SetLineStyle(kDotted);
    l->SetLineStyle(kGray+1);
    l->DrawLine(59,ymin2,59,ymax2);
    l->DrawLine(ptmax,ymin2,ptmax,ymax2);
    l->SetLineStyle(kGray);
    l->DrawLine(ptmax2,ymin2,ptmax2,ymax2);
    //l->SetLineStyle(kSolid);
    //l->SetLineColor(kBlack);
    //l->DrawLine(15,0,3500,0);

    //TH1D *hapr = (TH1D*)ha->Clone(Form("hapr%s_%d",co,ieta));
    //TH1D *htpr = (TH1D*)ht->Clone(Form("htpr%s_%d",co,ieta));
    //TH1D *hppr = (TH1D*)hp->Clone(Form("hppr%s_%d",co,ieta));

    //hapr->Add(hap,-1);
    //htpr->Add(htp,-1);
    //hppr->Add(hpp,-1);

    //htpr->GetXaxis()->SetRangeUser(59,ptmax2);
    //hppr->GetXaxis()->SetRangeUser(59,ptmax2);
    //hapr->GetXaxis()->SetRangeUser(59,ptmax2);

    // HISTP loses the histograms, so drwa HIST once at the back first
    //tdrDraw(htpr,"HIST",kOpenDiamond,kBlue+1,kDotted,-1,kNone);
    //tdrDraw(hppr,"HIST",kOpenDiamond,kRed+1,kDotted,-1,kNone);
    //tdrDraw(hapr,"HIST",kOpenDiamond,kGreen+3,kDotted,-1,kNone);

    //tdrDraw(htpr,"HISTP",kOpenDiamond,kBlue+1,kDotted,-1,kNone);
    //tdrDraw(hppr,"HISTP",kOpenDiamond,kRed+1,kDotted,-1,kNone);
    //tdrDraw(hapr,"HISTP",kOpenDiamond,kGreen+3,kDotted,-1,kNone);
    
    TH1D *har = (TH1D*)ha->Clone(Form("har%s_%d",co,ieta));
    TH1D *htr = (TH1D*)ht->Clone(Form("htr%s_%d",co,ieta));
    TH1D *hpr = (TH1D*)hp->Clone(Form("hpr%s_%d",co,ieta));

    har->Add(ham,-1);
    htr->Add(htm,-1);
    hpr->Add(hpm,-1);

    htr->GetXaxis()->SetRangeUser(59,ptmax2);
    hpr->GetXaxis()->SetRangeUser(59,ptmax2);
    har->GetXaxis()->SetRangeUser(59,ptmax2);

    tdrDraw(htr,"HEPz",kFullDiamond,kBlue,kSolid,-1,kNone);
    tdrDraw(hpr,"HEPz",kFullDiamond,kRed,kSolid,-1,kNone);
    tdrDraw(har,"HEPz",kFullDiamond,kGreen+2,kSolid,-1,kNone);

    tex->DrawLatex(0.55,0.92,Form("%1.3f<|#eta|<%1.3f",etamin,etamax));

    if (ieta==2 || ieta%6==0) {
      TLegend *leg = tdrLeg(0.55,0.90-3*0.075,0.85,0.90);
      leg->SetTextSize(0.045*1.5);
      leg->AddEntry(htr,"PtTag","PLE");
      leg->AddEntry(har,"PtAVP","PLE");
      leg->AddEntry(hpr,"PtProbe","PLE");
    }
    if (ieta==1 || ieta%6==5) {
      //TLegend *leg = tdrLeg(0.55,0.90-2*0.075,0.85,0.90);
      TLegend *leg = tdrLeg(0.55,0.90-1*0.075,0.85,0.90);
      leg->SetTextSize(0.045*1.5);
      leg->AddEntry(har,"MadGraph","PLE");
      //leg->AddEntry(hapr,"Pythia8","PL");
    }
  } // for ieta

  c1->SaveAs(Form("pdf/DijetHistosOverlayPtBins_%s_%s.pdf",cera,co));
  c2->SaveAs(Form("pdf/DijetHistosOverlayPtBins_%s_%s_ratio.pdf",cera,co));
} // DijetHistosOverLayPtBins

// Overlay jet pT spectra
void DijetHistosOverlayPt(string fdt, string fmc, string fmc2, string era) {

  setTDRStyle();
  TDirectory *curdir = gDirectory;

  const char *cera = era.c_str();
  
  TFile *f1(0), *f1m(0), *f1p(0);
  f1 = new TFile(fdt.c_str(),"READ");
  assert(f1 && !f1->IsZombie());
  f1m = new TFile(fmc.c_str(),"READ");
  assert(f1m && !f1m->IsZombie());
  f1p = (fmc2!=0 ? new TFile(fmc2.c_str(),"READ") : 0);
  assert(f1p && !f1p->IsZombie());  
  
} // DijetHistosOverlayPT

// Overlay JER and JER SF
void DijetHistosOverlayJER(string fdt, string fmc, string era) {

  setTDRStyle();
  TDirectory *curdir = gDirectory;

  TLatex *tex = new TLatex();
  tex->SetNDC(); tex->SetTextSize(0.045*1.5);
  TLine *l = new TLine();

  const char *co = "";
  const char *cera = era.c_str();
  bool isZB = TString(cera).Contains("_ZB");
  
  TFile *f1(0), *f1m(0), *f1p(0);
  f1 = new TFile(fdt.c_str(),"READ");
  assert(f1 && !f1->IsZombie());
  f1m = new TFile(fmc.c_str(),"READ");
  assert(f1m && !f1m->IsZombie());  

  curdir->cd();

  TH2D *h2jer(0), *h2jerm(0), *h2jerp(0);
  h2jer = (TH2D*)f1->Get("Dijet2/h2jer"); assert(h2jer);
  h2jerm = (TH2D*)f1m->Get("Dijet2/h2jer"); assert(h2jerm);
  TH2D *h2n(0), *h2nm(0), *h2np(0);
  h2n = (TH2D*)f1->Get("Dijet2/h2n"); assert(h2n);
  h2nm = (TH2D*)f1m->Get("Dijet2/h2n"); assert(h2nm);

  
  TCanvas *c1 = new TCanvas(Form("c1%s",co),Form("c1%s",co),1200,600);
  c1->Divide(6,3,0,0);

  TCanvas *c2 = new TCanvas(Form("c2%s",co),Form("c2%s",co),1200,600);
  c2->Divide(6,3,0,0);

  const double vy[] = {15, 30, 60, 120, 240, 480, 1000,  2000, 4000, 6500};
  const int ny = sizeof(vy)/sizeof(vy[0])-1;
  vector<double> vx(h2jer->GetNbinsX()+1);
  for (int i = 1; i != h2jer->GetNbinsX()+2; ++i) {
    vx[i-1] = h2jer->GetXaxis()->GetBinLowEdge(i);
  }
  int nx = vx.size()-1;
  TH2D *h2jerf = new TH2D("h2jerf",";#eta;JER",nx,&vx[0],ny,vy);
  TH2D *h2jersf = new TH2D("h2jersf",";#eta;JER SF",nx,&vx[0],ny,vy);
  
  const int neta = h2jer->GetNbinsX();
  vector<JER> vjer(neta);

  for (int ieta = 1; ieta != h2jer->GetNbinsX()+1; ++ieta) {
    
    c1->cd(ieta);
    gPad->SetLogx();

    TH1D *h = tdrHist(Form("h%s_%d",co,ieta),"",0.,0.3);
    h->Draw();

    // Add fits on top
    double ptmin = (isZB ? 30. : 59.);
    double etamin = h2jer->GetXaxis()->GetBinLowEdge(ieta);
    double etamax = h2jer->GetXaxis()->GetBinLowEdge(ieta+1);
    double fitptmax2 = min(1784.,0.55*6500./cosh(etamin));
    int jmax2 = h2jer->GetYaxis()->FindBin(fitptmax2);
    fitptmax2 = h2jer->GetYaxis()->GetBinLowEdge(jmax2);
    double fitptmax1 = max(132.,0.45*6500./cosh(etamin));
    int jmax1 = h2jer->GetYaxis()->FindBin(fitptmax1);
    fitptmax1 = h2jer->GetYaxis()->GetBinLowEdge(jmax1);
    double fitptmax =  (fabs(etamin)>=2.9 ? fitptmax1 : fitptmax2);

    l->SetLineStyle(kDotted);
    double ymin = h->GetMaximum();
    double ymax = h->GetMinimum();
    l->DrawLine(ptmin,ymin,ptmin,ymax);
    double ptmax = fitptmax;
    double ptmax1 = fitptmax1;
    l->DrawLine(ptmax,ymin,ptmax,ymax);
    double ptmax2 = fitptmax2;
    l->DrawLine(ptmax2,ymin,ptmax2,ymax);

    l->SetLineStyle(kSolid);
    l->SetLineColor(kBlack);
    l->DrawLine(15,1,3500,1);
    
    TH1D *h1jer = h2jer->ProjectionY(Form("h1jer%s_%d",co,ieta),ieta,ieta);
    TH1D *h1jerm = h2jerm->ProjectionY(Form("h1jerm%s_%d",co,ieta),ieta,ieta);

    h1jer->SetMarkerSize(0.7);
    h1jerm->SetMarkerSize(0.7);
    
    tdrDraw(h1jerm,"Pz",kOpenCircle,kBlue,kSolid,-1,kNone);
    tdrDraw(h1jer,"Pz",kFullCircle,kGreen+2,kSolid,-1,kNone);
    
    tex->DrawLatex(0.55,0.92,Form("%1.3f<|#eta|<%1.3f",etamin,etamax));

    if (ieta==1 || ieta%6==0) {
      TLegend *leg = tdrLeg(0.55,0.90-2*0.075,0.85,0.90);
      leg->SetTextSize(0.045*1.5);
      leg->AddEntry(h1jer,"Data","PLE");
      leg->AddEntry(h1jerm,"MadGraph","PLE");
    }

    bool fixN0to0 = false;
    double fitptmin = (isZB ? 30. : 15.);
    TF1 *fjer = new TF1(Form("fjer%d",ieta),
			"sqrt([0]*fabs([0])/(x*x)+[4]*[4]/(x*x)+"
			"[1]*[1]*pow(x,[3])+[2]*[2])",
			fitptmin,fitptmax);
    TF1 *fjerm = new TF1(Form("fjerm%d",ieta),
			 "sqrt([0]*fabs([0])/(x*x)+[4]*[4]/(x*x)+"
			 "[1]*[1]*pow(x,[3])+[2]*[2])",
			 fitptmin,fitptmax);

    double ptrcm = h2nm->GetYaxis()->GetBinCenter(1);
    double rcm = h2nm->GetBinContent(ieta, 1) * ptrcm;
    fjerm->SetParameters(0,1,0.04,-1,rcm);
    if (!fixN0to0) fjerm->SetParLimits(0,-2,+2);
    if (fixN0to0)  fjerm->FixParameter(0,0);
    fjerm->SetParLimits(1,0.5,1.5);
    fjerm->SetParLimits(2,0.02,0.25);
    fjerm->SetParLimits(3,-1.25,-0.75);
    fjerm->FixParameter(4,rcm);
    if (fabs(etamin)>2.6) {
      fjerm->FixParameter(0,0.);
      fjerm->FixParameter(3,-1);
    }    
    h1jerm->Fit(fjerm,"QRN");
    fjerm->SetRange(15,3500);

    double ptrc = h2n->GetYaxis()->GetBinCenter(1);
    double rcdt = h2n->GetBinContent(ieta, 1) * ptrc;
    fjer->SetParameters(fjerm->GetParameter(0),fjerm->GetParameter(1),
			fjerm->GetParameter(2),fjerm->GetParameter(3),
			max(rcdt,rcm));
    fjer->FixParameter(0,fjerm->GetParameter(0));
    fjer->SetParLimits(1,fjerm->GetParameter(1),1.5);
    fjer->SetParLimits(2,fjerm->GetParameter(2),0.25);
    fjer->SetParLimits(3,fjerm->GetParameter(3),-0.75);
    fjer->FixParameter(4,max(rcdt,rcm));
    if (fabs(etamin)>2.6) {
      //fjer->FixParameter(0,0.);
      //fjer->FixParameter(3,-1);
      fjer->FixParameter(3,fjerm->GetParameter(3));
    }
    if (fabs(etamin)>3.4) {
      fjer->FixParameter(2, fjerm->GetParameter(2));
    }
    h1jer->Fit(fjer,"QRN");
    fjer->SetRange(15,3500);

    fjerm->SetLineColor(kBlue);
    fjerm->Draw("SAME");
    fjer->SetLineColor(kGreen+2);
    fjer->Draw("SAME");
    
    c2->cd(ieta);
    gPad->SetLogx();

    TH1D *h2 = tdrHist(Form("h2%s_%d",co,ieta),"Data/MC",0.8,2.0);
    h2->Draw();

    double ptmin2 = (isZB ? 15. : 59.);
    double ymin2 = h2->GetMinimum();
    double ymax2 = h2->GetMaximum()-0.25;
    l->SetLineStyle(kDotted);
    l->SetLineColor(kBlack);
    l->DrawLine(ptmin,ymin2,ptmin,ymax2);
    l->DrawLine(ptmax,ymin2,ptmax,ymax2);
    l->DrawLine(ptmax2,ymin2,ptmax2,ymax2);
    l->SetLineStyle(kSolid);
    l->DrawLine(15,1,3500,1);

    TH1D *h1jerr = (TH1D*)h1jer->Clone(Form("h1jerr%s_%d",co,ieta));

    h1jerr->Divide(h1jerm);

    h1jerr->GetXaxis()->SetRangeUser(ptmin2,fitptmax);
    h1jerr->SetMarkerSize(0.7);
    
    tdrDraw(h1jerr,"Pz",kFullCircle,kGreen+2,kSolid,-1,kNone);

    tex->DrawLatex(0.55,0.92,Form("%1.3f<|#eta|<%1.3f",etamin,etamax));

    if (ieta==1 || ieta%6==0) {
      TLegend *leg = tdrLeg(0.55,0.90-1*0.075,0.85,0.90);
      leg->SetTextSize(0.045*1.5);
      leg->AddEntry(h1jerr,"MadGraph","PLE");
    }

    TF1 *fjerr = new TF1(Form("fjerr%d",ieta),
			 "sqrt([0]*fabs([0])/(x*x)+[4]*[4]/(x*x)+"
			 "[1]*[1]*pow(x,[3])+[2]*[2])/"
			 "sqrt([5]*fabs([5])/(x*x)+[9]*[9]/(x*x)+"
			 "[6]*[6]*pow(x,[8])+[7]*[7])",
			 15,3500);
    fjerr->SetParameters(fjer->GetParameter(0),fjer->GetParameter(1),
			 fjer->GetParameter(2),fjer->GetParameter(3),
			 fjer->GetParameter(4),
			 fjerm->GetParameter(0),fjerm->GetParameter(1),
			 fjerm->GetParameter(2),fjerm->GetParameter(3),
			 fjerm->GetParameter(4));
    fjerr->SetLineColor(kBlack);
    fjerr->SetLineWidth(2);
    fjerr->Draw("SAME");
    
    for (int ipt = 1; ipt != h2jerf->GetNbinsY()+1; ++ipt) {
      double etamin = h2jerf->GetXaxis()->GetBinLowEdge(ieta);
      double etamax = h2jerf->GetXaxis()->GetBinLowEdge(ieta+1);
      double absetamin = min(fabs(etamin),fabs(etamax));
      double pt = h2jerf->GetYaxis()->GetBinLowEdge(ipt);
      if (cosh(absetamin)*pt < 6500.) {
	h2jerf->SetBinContent(ieta, ipt, fjer->Eval(pt));
	h2jersf->SetBinContent(ieta, ipt, fjerr->Eval(pt));
      }
    } // for ipt

    // Copy results for text file
    JER jer;
    jer.eta = h2jerf->GetXaxis()->GetBinCenter(ieta);
    jer.deta = 0.5*h2jerf->GetXaxis()->GetBinWidth(ieta);
    //"sqrt([0]*fabs([0])/(x*x)+[4]*[4]/(x*x)+[1]*[1]*pow(x,[3])+[2]*[2])/"
    //"sqrt([5]*fabs([5])/(x*x)+[9]*[9]/(x*x)+[6]*[6]*pow(x,[8])+[7]*[7])",
    jer.n0_dt  = fjerr->GetParameter(0);
    jer.s_dt   = fjerr->GetParameter(1);
    jer.c_dt   = fjerr->GetParameter(2);
    jer.d_dt   = fjerr->GetParameter(3);
    jer.npu_dt = fjerr->GetParameter(4);
    //
    jer.n0_mc  = fjerr->GetParameter(5);
    jer.s_mc   = fjerr->GetParameter(6);
    jer.c_mc   = fjerr->GetParameter(7);
    jer.d_mc   = fjerr->GetParameter(8);
    jer.npu_mc = fjerr->GetParameter(9);
    //
    vjer[ieta-1] = jer;
  } // for ieta

  c1->SaveAs(Form("pdf/DijetHistosOverlayJER_%s.pdf",cera));
  c2->SaveAs(Form("pdf/DijetHistosOverlayJER_%s_ratio.pdf",cera));

  if (true) { // JER and JERSF vs eta

    int color[ny] = {kGray+1, kMagenta+1, kBlue, kCyan+2, kGreen+2,
		     kYellow+2, kOrange+1, kRed, kBlack};
      
    TH1D *h = tdrHist("h","JER in data",0,0.60,"|#eta|",0.0,5.191);
    TH1D *hd = tdrHist("hd","Scale factor",0.95,1.75,"|#eta|",0.0,5.191);

    TString tera = era.c_str();
    if (tera.Contains("UL2016APV")) lumi_13TeV = "2016early, 19.7 fb^{-1}";
    if (tera.Contains("UL2016BCDEF")) lumi_13TeV = "2016BCDEF, 19.7 fb^{-1}";
    if (tera.Contains("UL2016GH")) lumi_13TeV = "2016late, 16.8 fb^{-1}";
    if (tera.Contains("UL2017")) lumi_13TeV = "2017, 41.5 fb^{-1}";
    if (tera.Contains("UL2018")) lumi_13TeV = "2018, 59.9 fb^{-1}";
    if (tera.Contains("Run2")) lumi_13TeV = "Run2, 137.9 fb^{-1}";

    TCanvas *c3 = tdrDiCanvas("c3",h,hd,4,11);

    c3->cd(1);

    l->SetLineStyle(kDotted);
    l->DrawLine(1.3,0,1.3,0.45);
    l->DrawLine(2.5,0,2.5,0.50);
    l->DrawLine(3.139,0,3.139,0.58);
    
    TLegend *leg = tdrLeg(0.70,0.89-ny*0.035,0.95,0.89);
    leg->SetTextSize(0.04);

    for (int ipt = 1; ipt != h2jerf->GetNbinsY()+1; ++ipt) {
      TH1D *h1jerf = h2jerf->ProjectionX(Form("h1jerf_%d",ipt),ipt,ipt);
      tdrDraw(h1jerf,"HIST][",kNone,color[ipt-1],kSolid,-1,kNone);

      int pt = h2jerf->GetYaxis()->GetBinLowEdge(ipt);
      leg->AddEntry(h1jerf,Form("%d GeV",pt),"L");
    }
    
    c3->cd(2);
    
    l->SetLineStyle(kDashed);
    l->DrawLine(0,1,5.191,1);
    l->SetLineStyle(kDotted);
    l->DrawLine(1.3,0.95,1.3,1.55);
    l->DrawLine(2.5,0.95,2.5,1.55);
    l->DrawLine(3.139,0.95,3.139,1.55);
    
    for (int ipt = 1; ipt != h2jersf->GetNbinsY()+1; ++ipt) {
      TH1D *h1jersf = h2jersf->ProjectionX(Form("h1jersf_%d",ipt),ipt,ipt);
      tdrDraw(h1jersf,"HIST][",kNone,color[ipt-1],kSolid,-1,kNone);
    }

    c3->SaveAs(Form("pdf/DijetHistosOverlayJER_%s_JERvsEta.pdf",cera));
  } // JER+JERSF

  // Overlay Z+jet JER. Next stage would be to add it to fit as well
  if (addZjetJER) {

    TFile *fz(0), *fzm(0);
    //if (tera.Contains("UL2016APV")) rho = 14.06;
    //if (tera.Contains("UL2016BCDEF")) rho = 14.06;
    //if (tera.Contains("UL2017")) rho = 21.72;
    //if (tera.Contains("UL2018")) rho = 20.68;
    //if (tera.Contains("Run2")) rho = 19.59;
    TString tera = era.c_str();
    const int nx = 14;
    const double vsf[4][nx] =
      {{1.0910, 1.1084, 1.0833, 1.0684, 1.0556, 1.0155, 0.9889,
	1.0213, 1.0084, 1.1146, 1.1637, 1.1994, 1.2023, 1.0063}, // S20UL16APVV3
       {1.0993, 1.1228, 1.1000, 1.0881, 1.0761, 1.0452, 1.0670,
	1.0352, 1.0471, 1.1365, 1.2011, 1.1662, 1.1599, 1.0672}, // S20UL16V3
       {1.1082, 1.1285, 1.0916, 1.1352, 1.2116, 1.0637, 1.0489,
	1.1170, 1.1952, 1.0792, 1.3141, 1.4113, 1.2679, 1.0378}, // S19UL17V3
       {1.1436, 1.1538, 1.1481, 1.1304, 1.1590, 1.1628, 1.1423,
	1.1479, 1.1360, 1.1911, 1.2919, 1.3851, 1.2670, 1.0367}};// S19UL18V2
    const double vx[nx+1] =
      {0.000, 0.522, 0.783, 1.131, 1.305, 1.740, 1.930, 
       2.043, 2.322, 2.500, 2.650, 2.853, 2.964, 3.139, 5.191};
    TH1D *hsf = new TH1D(Form("hsf_%s",era.c_str()),";|#eta|;SF",nx,vx);

    int ksf(-1);
    if (tera.Contains("UL2016APV")) {
      fz = new TFile("../jecsys2020/rootfiles/jerSF_Zjet_UL2016APV_data.root",
		     "READ");
      fzm = new TFile("../jecsys2020/rootfiles/jerSF_Zjet_UL2016APV_mc.root",
		      "READ");
      ksf = 0;
    }
    if (tera.Contains("UL2016GH")) {
      fz = new TFile("../jecsys2020/rootfiles/jerSF_Zjet_UL2016GH_data.root",
		     "READ");
      fzm = new TFile("../jecsys2020/rootfiles/jerSF_Zjet_UL2016GH_mc.root",
		      "READ");
      ksf = 1;
    }
    if (tera.Contains("UL2017")) {
      fz = new TFile("../jecsys2020/rootfiles/jerSF_Zjet_UL2017_data.root",
		     "READ");
      fzm = new TFile("../jecsys2020/rootfiles/jerSF_Zjet_UL2017_mc.root",
		      "READ");
      ksf = 2;
    }
    if (tera.Contains("UL2018") || tera.Contains("Run2")) {
      fz = new TFile("../jecsys2020/rootfiles/jerSF_Zjet_UL2018_data.root",
		     "READ");
      fzm = new TFile("../jecsys2020/rootfiles/jerSF_Zjet_UL2018_mc.root",
		      "READ");
      ksf = 3;
    }
    assert(fz && !fz->IsZombie());
    assert(fzm && !fzm->IsZombie());
    assert(ksf>=0);
    for (int i = 0; i != nx; ++i) {
      if (ksf>=0) hsf->SetBinContent(i+1, vsf[ksf][i]);
    }

    TH2D *h2z = (TH2D*)fz->Get("h2jer"); assert(h2z);
    TH2D *h2zm = (TH2D*)fzm->Get("h2jer"); assert(h2zm);

    for (int i = 1; i != h2jer->GetNbinsX()+1; ++i) {
      double eta = h2jer->GetXaxis()->GetBinCenter(i);
      int j = h2z->GetXaxis()->FindBin(eta);
      TH1D *h1z = h2z->ProjectionY(Form("h1z_%d",i),j,j);
      TH1D *h1zm = h2zm->ProjectionY(Form("h1zm_%d",i),j,j);

      int k = hsf->FindBin(fabs(eta));
      double sf = hsf->GetBinContent(k);
      h1zm->Scale(1./sf);

      TH1D *h1zr = (TH1D*)h1z->Clone(Form("h1zr_%d",i));
      h1zr->Divide(h1zm);

      c1->cd(i);
      tdrDraw(h1z,"Pz",kFullCircle,kRed); h1z->SetMarkerSize(0.7);
      tdrDraw(h1zm,"Pz",kOpenCircle,kRed); h1zm->SetMarkerSize(0.7);

      c2->cd(i);
      tdrDraw(h1zr,"Pz",kFullCircle,kRed); h1zr->SetMarkerSize(0.7);
    }
    
    c1->SaveAs(Form("pdf/DijetHistosOverlayJER_wZjet_%s.pdf",cera));    
    c2->SaveAs(Form("pdf/DijetHistosOverlayJER_wZjet_%s_ratio.pdf",cera));    
  } // addZJet

  if (true) {

    // Produce output text file (FactorizedJetCorrecter Style
    ofstream txt(Form("pdf/jerSF/Summer20%s_JRV3_MC_SF_AK4PFchs.txt",cera));
    txt << "{1 JetEta 2 JetPt Rho "
	<< "sqrt(max([0]*fabs([0])/(x*x)+[4]*[4]/(x*x)+"
	<< "[1]*[1]*pow(x,[3])+[2]*[2],0.))/"
	<< "sqrt(max([5]*fabs([5])/(x*x)+[9]*[9]/(x*x)+"
	<< "[6]*[6]*pow(x,[8])+[7]*[7],0.))"
	<< " Correction L2Relative}" << endl;

    // Rho from HLT_PFJet500,550/Incjet/PFComposition/prho13->at(1000 GeV)
    double rho = 19.59; // Run2
    TString tera = era.c_str();
    if (tera.Contains("UL2016APV")) rho = 14.06;
    if (tera.Contains("UL2016BCDEF")) rho = 14.06;
    if (tera.Contains("UL2016GH")) rho = 16.55;
    if (tera.Contains("UL2017")) rho = 21.72;
    if (tera.Contains("UL2018")) rho = 20.68;
    if (tera.Contains("Run2")) rho = 19.59;

    for (int i = neta-1; i != -1; --i) {
      JER &jer = vjer[i];
      txt << Form("%6.3f %6.3f %2d %2d %4d %2d %2d"
		  " %6.2f %5.3f %6.4f %5.3f %4.2f"
		  " %6.2f %5.3f %6.4f %5.3f %4.2f\n",//  %5.2f\n",
		  -jer.eta-jer.deta, -jer.eta+jer.deta, 14, 8, 6500, 0, 120,
		  jer.n0_dt, jer.s_dt, jer.c_dt, jer.d_dt, jer.npu_dt,
		  jer.n0_mc, jer.s_mc, jer.c_mc, jer.d_mc, jer.npu_mc);//, rho);
    } // for i in -neta
    for (int i = 0; i != neta; ++i) {
      JER &jer = vjer[i];
      txt << Form("%6.3f %6.3f %2d %2d %4d %2d %2d"
		  " %6.2f %5.3f %6.4f %5.3f %4.2f"
		  " %6.2f %5.3f %6.4f %5.3f %4.2f\n",//  %5.2f\n",
		  +jer.eta-jer.deta, +jer.eta+jer.deta, 14, 8, 6500, 0, 120,
		  jer.n0_dt, jer.s_dt, jer.c_dt, jer.d_dt, jer.npu_dt,
		  jer.n0_mc, jer.s_mc, jer.c_mc, jer.d_mc, jer.npu_mc);//, rho);
    } // for i in +neta
  } // produce text file
			      
} // DijetHistosOverLayJER

// Overlay JES and L2Res
void DijetHistosOverlayJES(string fdt, string fmc, string era) {

  setTDRStyle();
  TDirectory *curdir = gDirectory;

  TLatex *tex = new TLatex();
  tex->SetNDC(); tex->SetTextSize(0.045*1.5);
  TLine *l = new TLine();

  const char *co = "";
  const char *cera = era.c_str();
  bool isZB = TString(cera).Contains("_ZB");
  
  TFile *f1(0), *f1m(0), *f1p(0);
  f1 = new TFile(fdt.c_str(),"READ");
  assert(f1 && !f1->IsZombie());
  f1m = new TFile(fmc.c_str(),"READ");
  assert(f1m && !f1m->IsZombie());  

  curdir->cd();

  TH2D *h2jes(0), *h2jesm(0);
  if (useMPF) {
    h2jes = (TH2D*)f1->Get("Dijet2/h2mpf");
    h2jesm = (TH2D*)f1m->Get("Dijet2/h2mpf");
  }
  else {
    h2jes = (TH2D*)f1->Get("Dijet2/h2jes");
    h2jesm = (TH2D*)f1m->Get("Dijet2/h2jes");
  }
  assert(h2jes);
  assert(h2jesm);
  
  TCanvas *c1 = new TCanvas(Form("c1%s",co),Form("c1%s",co),1200,600);
  c1->Divide(6,3,0,0);

  TCanvas *c2 = new TCanvas(Form("c2%s",co),Form("c2%s",co),1200,600);
  c2->Divide(6,3,0,0);

  const double vy[] = {15, 30, 60, 120, 240, 480, 1000,  2000, 4000, 6500};
  const int ny = sizeof(vy)/sizeof(vy[0])-1;
  vector<double> vx(h2jes->GetNbinsX()+1);
  for (int i = 1; i != h2jes->GetNbinsX()+2; ++i) {
    vx[i-1] = h2jes->GetXaxis()->GetBinLowEdge(i);
  }
  int nx = vx.size()-1;
  TH2D *h2jesf = new TH2D("h2jesf",";#eta;JES",nx,&vx[0],ny,vy);
  TH2D *h2jessf = new TH2D("h2jessf",";#eta;JES SF",nx,&vx[0],ny,vy);
  
  const int neta = h2jes->GetNbinsX();
  vector<JES> vjes(neta);

  for (int ieta = 1; ieta != h2jes->GetNbinsX()+1; ++ieta) {
    
    c1->cd(ieta);
    gPad->SetLogx();

    double etamin = h2jes->GetXaxis()->GetBinLowEdge(ieta);
    double etamax = h2jes->GetXaxis()->GetBinLowEdge(ieta+1);

    TH1D *h = tdrHist(Form("h%s_%d",co,ieta),"",0.85,1.3);//0.92,1.12);
    if (addColorJES) { h->GetYaxis()->SetRangeUser(0.5,1.75); } // Run3
    if (addColorJES2) {
      if (etamin<1.4)
	h->GetYaxis()->SetRangeUser(0.50,1.75);
      if (etamin>1.4 && etamin <2.6)
	h->GetYaxis()->SetRangeUser(0.30,2.0);
      if (etamin>2.6)
	h->GetYaxis()->SetRangeUser(0.0,2.50);
    }
    h->Draw();

    // Add fits on top
    double ptmin = (isZB ? 30. : 59.);
    double fitptmax2 = min(1784.,0.55*6500./cosh(etamin));
    int jmax2 = h2jes->GetYaxis()->FindBin(fitptmax2);
    fitptmax2 = h2jes->GetYaxis()->GetBinLowEdge(jmax2);
    double fitptmax1 = max(132.,0.45*6500./cosh(etamin));
    int jmax1 = h2jes->GetYaxis()->FindBin(fitptmax1);
    fitptmax1 = h2jes->GetYaxis()->GetBinLowEdge(jmax1);
    double fitptmax =  (fabs(etamin)>=2.9 ? fitptmax1 : fitptmax2);
    double fitptmin = (isZB ? 30. : 15.);

    l->SetLineStyle(kDotted);
    double ymin = h->GetMaximum();
    double ymax = h->GetMinimum();
    l->DrawLine(ptmin,ymin,ptmin,ymax);
    double ptmax = fitptmax;
    double ptmax1 = fitptmax1;
    l->DrawLine(ptmax,ymin,ptmax,ymax);
    double ptmax2 = fitptmax2;
    l->DrawLine(ptmax2,ymin,ptmax2,ymax);

    l->SetLineStyle(kSolid);
    l->SetLineColor(kBlack);
    l->DrawLine(15,1,3500,1);
    
    TH1D *h1jes = h2jes->ProjectionY(Form("h1jes%s_%d",co,ieta),ieta,ieta);
    TH1D *h1jesm = h2jesm->ProjectionY(Form("h1jesm%s_%d",co,ieta),ieta,ieta);

    h1jes->SetMarkerSize(0.7);
    h1jesm->SetMarkerSize(0.7);
    
    //tdrDraw(h1jesm,"Pz",kOpenCircle,kBlue,kSolid,-1,kNone);
    tdrDraw(h1jesm,"Pz",kOpenCircle,kGreen+3,kSolid,-1,kNone);
    tdrDraw(h1jes,"Pz",kFullCircle,kGreen+2,kSolid,-1,kNone);
    
    tex->DrawLatex(0.55,0.92,Form("%1.3f<|#eta|<%1.3f",etamin,etamax));

    if (ieta==1 || ieta%6==0) {
      TLegend *leg = tdrLeg(0.55,0.90-2*0.075,0.85,0.90);
      leg->SetTextSize(0.045*1.5);
      leg->AddEntry(h1jes,"Data","PLE");
      leg->AddEntry(h1jesm,"MadGraph","PLE");
    }

    TF1 *fjes = new TF1(Form("fjes%d",ieta),"[0]+log(x)*([1]+log(x)*[2])",
			fitptmin,fitptmax);
    TF1 *fjesm = new TF1(Form("fjesm%d",ieta),"[0]+log(x)*([1]+log(x)*[2])",
			 fitptmin,fitptmax);

    fjes->SetParameters(1,0,0);
    h1jes->Fit(fjes,"QRN");
    fjes->SetRange(15,3500);

    fjesm->SetParameters(1,0,0);
    h1jesm->Fit(fjesm,"QRN");
    fjesm->SetRange(15,3500);

    //fjesm->SetLineColor(kGreen+3);//kBlue);
    fjesm->SetLineColor(kGray+2);//kBlue);
    fjesm->Draw("SAME");
    //fjes->SetLineColor(kGreen+2);
    fjes->SetLineColor(kBlack);
    fjes->Draw("SAME");
    
    c2->cd(ieta);
    gPad->SetLogx();

    //TH1D *h2 = tdrHist(Form("h2%s_%d",co,ieta),"Data/MC",0.96,1.11);
    TH1D *h2 = tdrHist(Form("h2%s_%d",co,ieta),"Data/MC",0.92,1.12);
    if (addColorJES)  { h2->GetYaxis()->SetRangeUser(0.80,1.30); } // Run3
    if (addColorJES2) {
      if (etamin<1.4)
	h2->GetYaxis()->SetRangeUser(0.80,1.30);
      if (etamin>1.4 && etamin <2.6)
	h2->GetYaxis()->SetRangeUser(0.70,1.45);
      if (etamin>2.6)
	h2->GetYaxis()->SetRangeUser(0.60,1.60);
    }
    h2->Draw();

    double ptmin2 = (isZB ? 15. : 59.);
    double ymin2 = h2->GetMinimum();
    double ymax2 = h2->GetMaximum();
    l->SetLineStyle(kDotted);
    l->SetLineColor(kBlack);
    l->DrawLine(ptmin,ymin2,ptmin,ymax2);
    l->DrawLine(ptmax,ymin2,ptmax,ymax2);
    l->DrawLine(ptmax2,ymin2,ptmax2,ymax2);
    l->SetLineStyle(kSolid);
    l->DrawLine(15,1,3500,1);

    TH1D *h1jesr = (TH1D*)h1jes->Clone(Form("h1jesr%s_%d",co,ieta));

    h1jesr->Divide(h1jesm);

    h1jesr->GetXaxis()->SetRangeUser(ptmin2,fitptmax);
    h1jesr->SetMarkerSize(0.7);
    
    tdrDraw(h1jesr,"Pz",kFullCircle,kGreen+2,kSolid,-1,kNone);

    tex->DrawLatex(0.55,0.92,Form("%1.3f<|#eta|<%1.3f",etamin,etamax));

    if (ieta==1 || ieta%6==0) {
      TLegend *leg = tdrLeg(0.55,0.90-1*0.075,0.85,0.90);
      leg->SetTextSize(0.045*1.5);
      leg->AddEntry(h1jesr,"MadGraph","PLE");
    }

    TF1 *fjes2r = new TF1(Form("fjer2r%d",ieta),
			  "([0]+log(x)*([1]+log(x)*[2]))/"
			 "([3]+log(x)*([4]+log(x)*[5]))",15,3000);
    fjes2r->SetParameters(fjes->GetParameter(0),fjes->GetParameter(1),
			  fjes->GetParameter(2),
			  fjesm->GetParameter(0),fjesm->GetParameter(1),
			  fjesm->GetParameter(2));
    fjes2r->SetLineColor(kBlack);
    fjes2r->SetLineWidth(2);
    fjes2r->SetLineStyle(kDotted);
    //fjes2r->Draw("SAME");

    TF1 *fjesr = new TF1(Form("fjesr%d",ieta),"[0]+log(x)*([1]+log(x)*[2])",
			 fitptmin,fitptmax);
    //fjesr->SetLineColor(kGreen+2);
    fjesr->SetLineColor(kBlack);

    fjesr->SetParameters(1,0,0);
    h1jesr->Fit(fjesr,"QRN");
    fjesr->SetRange(15,3500);
    fjesr->Draw("SAME");
    
    for (int ipt = 1; ipt != h2jesf->GetNbinsY()+1; ++ipt) {
      double etamin = h2jesf->GetXaxis()->GetBinLowEdge(ieta);
      double etamax = h2jesf->GetXaxis()->GetBinLowEdge(ieta+1);
      double absetamin = min(fabs(etamin),fabs(etamax));
      double pt = h2jesf->GetYaxis()->GetBinLowEdge(ipt);
      if (cosh(absetamin)*pt < 6500.) {
	h2jesf->SetBinContent(ieta, ipt, fjes->Eval(pt));
	h2jessf->SetBinContent(ieta, ipt, fjesr->Eval(pt));
      }
    } // for ipt

    // Copy results for text file
    JES jes;
    jes.eta = h2jesf->GetXaxis()->GetBinCenter(ieta);
    jes.deta = 0.5*h2jesf->GetXaxis()->GetBinWidth(ieta);
    jes.p0  = fjesr->GetParameter(0);
    jes.p1   = fjesr->GetParameter(1);
    //
    //jes.p0_dt  = fjesr->GetParameter(0);
    //jes.p1_dt   = fjesr->GetParameter(1);
    //
    //jes.p0_mc  = fjerr->GetParameter(2);
    //jes.p1_mc   = fjerr->GetParameter(3);
    //
    vjes[ieta-1] = jes;
  } // for ieta

  const char *cmpf = (useMPF ? "_MPF" : "");
  c1->SaveAs(Form("pdf/DijetHistosOverlayJES_%s%s.pdf",cera,cmpf));
  c2->SaveAs(Form("pdf/DijetHistosOverlayJES_%s_ratio%s.pdf",cera,cmpf));

  if (true) { // JES and L2Res vs eta

    int color[ny] = {kGray+1, kMagenta+1, kBlue, kCyan+2, kGreen+2,
		     kYellow+2, kOrange+1, kRed, kBlack};
      
    TH1D *h = tdrHist("h","MPF in data",0.96,1.26,"|#eta|",0.0,5.191);
    TH1D *hd = tdrHist("hd","Data/MC",0.96,1.11,"|#eta|",0.0,5.191);

    TString tera = era.c_str();
    if (tera.Contains("UL2016APV")) lumi_13TeV = "2016early, 19.7 fb^{-1}";
    if (tera.Contains("UL2016BCDEF")) lumi_13TeV = "2016BCDEF, 19.7 fb^{-1}";
    if (tera.Contains("UL2016GH")) lumi_13TeV = "2016late, 16.8 fb^{-1}";
    if (tera.Contains("UL2017")) lumi_13TeV = "2017, 41.5 fb^{-1}";
    if (tera.Contains("UL2018")) lumi_13TeV = "2018, 59.9 fb^{-1}";
    if (tera.Contains("Run2")) lumi_13TeV = "Run2, 137.9 fb^{-1}";

    TCanvas *c3 = tdrDiCanvas("c3",h,hd,4,11);

    c3->cd(1);

    l->SetLineStyle(kDotted);
    double ymin3 = h->GetMinimum();
    double ymax3 = h->GetMaximum();
    l->DrawLine(0,1,5.191,1);
    l->DrawLine(1.3,ymin3,1.3,ymax3-0.05);
    l->DrawLine(2.5,ymin3,2.5,ymax3);
    l->DrawLine(3.139,ymin3,3.139,ymax3);
    
    TLegend *leg = tdrLeg(0.70,0.89-ny*0.035,0.95,0.89);
    leg->SetTextSize(0.04);

    for (int ipt = 1; ipt != h2jesf->GetNbinsY()+1; ++ipt) {
      TH1D *h1jesf = h2jesf->ProjectionX(Form("h1jerf_%d",ipt),ipt,ipt);
      tdrDraw(h1jesf,"HIST][",kNone,color[ipt-1],kSolid,-1,kNone);

      int pt = h2jesf->GetYaxis()->GetBinLowEdge(ipt);
      leg->AddEntry(h1jesf,Form("%d GeV",pt),"L");
    }
    
    c3->cd(2);
    
    double ymin3d = hd->GetMinimum();
    double ymax3d = hd->GetMaximum();
    l->SetLineStyle(kDashed);
    l->DrawLine(0,1,5.191,1);
    l->SetLineStyle(kDotted);
    l->DrawLine(1.3,ymin3d,1.3,ymax3d);
    l->DrawLine(2.5,ymin3d,2.5,ymax3d);
    l->DrawLine(3.139,ymin3d,3.139,ymax3d);
    
    for (int ipt = 1; ipt != h2jessf->GetNbinsY()+1; ++ipt) {
      TH1D *h1jessf = h2jessf->ProjectionX(Form("h1jessf_%d",ipt),ipt,ipt);
      tdrDraw(h1jessf,"HIST][",kNone,color[ipt-1],kSolid,-1,kNone);
    }

    c3->SaveAs(Form("pdf/DijetHistosOverlayJES_%s_JESvsEta.pdf",cera));
  } // JES+L2Res

  // Overlay pT,tag and pT,ave bins, and MPF+DB
  if (addColorJES) {

    TH2D *h2jespf(0), *h2jespfm(0);
    if (useMPF) {
      h2jespf = (TH2D*)f1->Get("Dijet2/h2mpfpf");
      h2jespfm = (TH2D*)f1m->Get("Dijet2/h2mpfpf");
    }
    else {
      h2jespf = (TH2D*)f1->Get("Dijet2/h2jespf");
      h2jespfm = (TH2D*)f1m->Get("Dijet2/h2jespf");
    }
    assert(h2jespf);
    assert(h2jespfm);
    
    TH2D *h2jestc(0), *h2jestcm(0);
    if (useMPF) {
      h2jestc = (TH2D*)f1->Get("Dijet2/h2mpftc");
      h2jestcm = (TH2D*)f1m->Get("Dijet2/h2mpftc");
    }
    else {
      h2jestc = (TH2D*)f1->Get("Dijet2/h2jestc");
      h2jestcm = (TH2D*)f1m->Get("Dijet2/h2jestc");
    }
    assert(h2jestc);
    assert(h2jestcm);
 
    for (int ieta = 1; ieta != h2jes->GetNbinsX()+1; ++ieta) {

      TH1D *h1jespf = h2jespf->ProjectionY(Form("h1jespf%s_%d",co,ieta),
					   ieta,ieta);
      TH1D *h1jespfm = h2jespfm->ProjectionY(Form("h1jespfm%s_%d",co,ieta),
					     ieta,ieta);
      TH1D *h1jestc = h2jestc->ProjectionY(Form("h1jestc%s_%d",co,ieta),
					   ieta,ieta);
      TH1D *h1jestcm = h2jestcm->ProjectionY(Form("h1jestcm%s_%d",co,ieta),
					     ieta,ieta);
      c1->cd(ieta);

      //h1jespf->SetMarkerSize(0.7);
      //h1jespfm->SetMarkerSize(0.7);
      //h1jestc->SetMarkerSize(0.7);
      //h1jestcm->SetMarkerSize(0.7);

      tdrDraw(h1jestcm,"Pz",kOpenDiamond,kBlue,kSolid,-1,kNone);
      tdrDraw(h1jestc,"Pz",kFullDiamond,kBlue,kSolid,-1,kNone);
      tdrDraw(h1jespfm,"Pz",kOpenDiamond,kRed,kSolid,-1,kNone);
      tdrDraw(h1jespf,"Pz",kFullDiamond,kRed,kSolid,-1,kNone);

      c2->cd(ieta);

      TH1D *h1jespfr = (TH1D*)h1jespf->Clone(Form("h1jespfr%s_%d",co,ieta));
      h1jespfr->Divide(h1jespfm);
      TH1D *h1jestcr = (TH1D*)h1jestc->Clone(Form("h1jestcr%s_%d",co,ieta));
      h1jestcr->Divide(h1jestcm);

      tdrDraw(h1jestcr,"Pz",kFullDiamond,kBlue,kSolid,-1,kNone);
      tdrDraw(h1jespfr,"Pz",kFullDiamond,kRed,kSolid,-1,kNone);
    } // for ieta

    c1->SaveAs(Form("pdf/DijetHistosOverlayJES_wColor_%s%s.pdf",cera,cmpf));    
    c2->SaveAs(Form("pdf/DijetHistosOverlayJES_wColor_%s_ratio%s.pdf",cera,cmpf)); 
  } // addColorJES

    // Overlay pT,tag and pT,ave bins, and MPF+DB
  if (addColorJES2) {

    TH2D *h2dbab(0), *h2dbabm(0);
    h2dbab = (TH2D*)f1->Get("Dijet2/h2db"); assert(h2dbab);
    h2dbabm = (TH2D*)f1m->Get("Dijet2/h2db"); assert(h2dbabm);
    TH2D *h2dbpf(0), *h2dbpfm(0);
    h2dbpf = (TH2D*)f1->Get("Dijet2/h2dbpf"); assert(h2dbpf);
    h2dbpfm = (TH2D*)f1m->Get("Dijet2/h2dbpf"); assert(h2dbpf);
    TH2D *h2dbtc(0), *h2dbtcm(0);
    h2dbtc = (TH2D*)f1->Get("Dijet2/h2dbtc"); assert(h2dbtc);
    h2dbtcm = (TH2D*)f1m->Get("Dijet2/h2dbtc"); assert(h2dbtc);

    TH2D *h2mpfab(0), *h2mpfabm(0);
    h2mpfab = (TH2D*)f1->Get("Dijet2/h2mpf"); assert(h2mpfab);
    h2mpfabm = (TH2D*)f1m->Get("Dijet2/h2mpf"); assert(h2mpfabm);
    TH2D *h2mpfpf(0), *h2mpfpfm(0);
    h2mpfpf = (TH2D*)f1->Get("Dijet2/h2mpfpf"); assert(h2mpfpf);
    h2mpfpfm = (TH2D*)f1m->Get("Dijet2/h2mpfpf"); assert(h2mpfpf);
    TH2D *h2mpftc(0), *h2mpftcm(0);
    h2mpftc = (TH2D*)f1->Get("Dijet2/h2mpftc"); assert(h2mpftc);
    h2mpftcm = (TH2D*)f1m->Get("Dijet2/h2mpftc"); assert(h2mpftc);

    for (int ieta = 1; ieta != h2jes->GetNbinsX()+1; ++ieta) {

      int i = ieta;
      TH1D *h1dbab = h2dbab->ProjectionY(Form("h1dbab%s_%d",co,i),i,i);
      TH1D *h1dbabm = h2dbabm->ProjectionY(Form("h1dbabm%s_%d",co,i),i,i);
      TH1D *h1dbpf = h2dbpf->ProjectionY(Form("h1dbpf%s_%d",co,i),i,i);
      TH1D *h1dbpfm = h2dbpfm->ProjectionY(Form("h1dbpfm%s_%d",co,i),i,i);
      TH1D *h1dbtc = h2dbtc->ProjectionY(Form("h1dbtc%s_%d",co,i),i,i);
      TH1D *h1dbtcm = h2dbtcm->ProjectionY(Form("h1dbtcm%s_%d",co,i),i,i);

      TH1D *h1mpfab = h2mpfab->ProjectionY(Form("h1mpfab%s_%d",co,i),i,i);
      TH1D *h1mpfabm = h2mpfabm->ProjectionY(Form("h1mpfabm%s_%d",co,i),i,i);
      TH1D *h1mpfpf = h2mpfpf->ProjectionY(Form("h1mpfpf%s_%d",co,i),i,i);
      TH1D *h1mpfpfm = h2mpfpfm->ProjectionY(Form("h1mpfpfm%s_%d",co,i),i,i);
      TH1D *h1mpftc = h2mpftc->ProjectionY(Form("h1mpftc%s_%d",co,i),i,i);
      TH1D *h1mpftcm = h2mpftcm->ProjectionY(Form("h1mpftcm%s_%d",co,i),i,i);
      
      c1->cd(ieta);

      tdrDraw(h1dbabm,"HIST",kNone,kGreen+3,kDashed,-1,kNone);
      tdrDraw(h1dbab,"HIST",kNone,kGreen+3,kSolid,-1,kNone);
      tdrDraw(h1dbtcm,"HIST",kNone,kBlue+1,kDashed,-1,kNone);
      tdrDraw(h1dbtc,"HIST",kNone,kBlue+1,kSolid,-1,kNone);
      tdrDraw(h1dbpfm,"HIST",kNone,kRed+1,kDashed,-1,kNone);
      tdrDraw(h1dbpf,"HIST",kNone,kRed+1,kSolid,-1,kNone);

      tdrDraw(h1mpfabm,"Pz",kNone,kGreen+2,kDashed,-1,kNone);
      tdrDraw(h1mpfab,"Pz",kNone,kGreen+2,kSolid,-1,kNone);
      tdrDraw(h1mpftcm,"Pz",kNone,kBlue,kDashed,-1,kNone);
      tdrDraw(h1mpftc,"Pz",kNone,kBlue,kSolid,-1,kNone);
      tdrDraw(h1mpfpfm,"Pz",kNone,kRed,kDashed,-1,kNone);
      tdrDraw(h1mpfpf,"Pz",kNone,kRed,kSolid,-1,kNone);

      
      c2->cd(ieta);
      
      TH1D *h1dbabr = (TH1D*)h1dbab->Clone(Form("h1dbabr%s_%d",co,ieta));
      h1dbabr->Divide(h1dbabm);
      TH1D *h1dbpfr = (TH1D*)h1dbpf->Clone(Form("h1dbpfr%s_%d",co,ieta));
      h1dbpfr->Divide(h1dbpfm);
      TH1D *h1dbtcr = (TH1D*)h1dbtc->Clone(Form("h1dbtcr%s_%d",co,ieta));
      h1dbtcr->Divide(h1dbtcm);

      TH1D *h1mpfabr = (TH1D*)h1mpfab->Clone(Form("h1mpfabr%s_%d",co,ieta));
      h1mpfabr->Divide(h1mpfabm);
      TH1D *h1mpfpfr = (TH1D*)h1mpfpf->Clone(Form("h1mpfpfr%s_%d",co,ieta));
      h1mpfpfr->Divide(h1mpfpfm);
      TH1D *h1mpftcr = (TH1D*)h1mpftc->Clone(Form("h1mpftcr%s_%d",co,ieta));
      h1mpftcr->Divide(h1mpftcm);

      tdrDraw(h1dbabr,"HIST",kNone,kGreen+3,kSolid,-1,kNone);
      tdrDraw(h1dbtcr,"HIST",kNone,kBlue+1,kSolid,-1,kNone);
      tdrDraw(h1dbpfr,"HIST",kNone,kRed+1,kSolid,-1,kNone);

      tdrDraw(h1mpfabr,"Pz",kNone,kGreen+2,kSolid,-1,kNone);
      tdrDraw(h1mpftcr,"Pz",kNone,kBlue,kSolid,-1,kNone);
      tdrDraw(h1mpfpfr,"PZ",kNone,kRed,kSolid,-1,kNone);

    } // for ieta

    c1->SaveAs(Form("pdf/DijetHistosOverlayJES_wColor2_%s%s.pdf",cera,cmpf));
    c2->SaveAs(Form("pdf/DijetHistosOverlayJES_wColor2_%s_ratio%s.pdf",
		    cera,cmpf)); 
  } // addColorJES2 

  // Overlay Z+jet JER. Next stage would be to add it to fit as well
  // => update to Z+jet JES
  if (addZjetJES) {

    TFile *fz(0);
    TString tera = era.c_str();
    if (tera.Contains("UL2016APV")) {
      fz = new TFile("../jecsys2020/rootfiles/jme_bplusZ_2016ULAPV_Zmm_sync_v53.root","READ");
    }
    if (tera.Contains("UL2016GH")) {
    }
    if (tera.Contains("UL2017")) { // || tera.Contains("Run2")) {
      fz = new TFile("../jecsys2020/rootfiles/jme_bplusZ_2017UL_Zmm_sync_v53.root","READ");
    }
    if (tera.Contains("UL2018")) { 
    }
    if (tera.Contains("Run2")) {
      fz = new TFile("../jecsys2020/rootfiles/jme_bplusZ_Run2_Zmm_sync_v53.root","READ");
    }
    assert (fz && !fz->IsZombie()); {
      
      TH3D *h3z = (TH3D*)fz->Get("data/h3D_Zpt_RMPF_eta_alpha100"); assert(h3z);
      TH3D *h3zm = (TH3D*)fz->Get("mc/h3D_Zpt_RMPF_eta_alpha100"); assert(h3zm);

      h3z->RebinX(2);
      h3zm->RebinX(2);

      // Flatten 3D histo to a profile in (x=eta)-(y=pT) plane
      TProfile2D *p2z  = h3z->Project3DProfile("xz");  p2z->SetName("p2z");
      TProfile2D *p2zm  = h3zm->Project3DProfile("xz");  p2zm->SetName("p2zm");
      
      for (int i = 1; i != h2jes->GetNbinsX()+1; ++i) {
	
	double eta = h2jes->GetXaxis()->GetBinCenter(i);
	int j = p2z->GetXaxis()->FindBin(eta);
	TH1D *h1z = p2z->ProjectionY(Form("h1z_%d",i),j,j);
	TH1D *h1zm = p2zm->ProjectionY(Form("h1zm_%d",i),j,j);
	
	TH1D *h1zr = (TH1D*)h1z->Clone(Form("h1zr_%d",i));
	h1zr->Divide(h1zm);
	
	c1->cd(i);
	tdrDraw(h1z,"Pz",kFullStar,kMagenta+1); h1z->SetMarkerSize(0.8);//0.7);
	tdrDraw(h1zm,"Pz",kOpenStar,kMagenta+1); h1zm->SetMarkerSize(1.0);//0.7);
	
	c2->cd(i);
	tdrDraw(h1zr,"Pz",kFullStar,kMagenta); h1zr->SetMarkerSize(1.0);//0.7);
      }
      
      c1->SaveAs(Form("pdf/DijetHistosOverlayJES_wZjet_%s%s.pdf",cera,cmpf)); 
      c2->SaveAs(Form("pdf/DijetHistosOverlayJES_wZjet_%s_ratio%s.pdf",
		      cera,cmpf)); 
    } // Z+jet file available
  } // addZJetJES

  if (false) { // text file later

    // Produce output text file (FactorizedJetCorrecter Style
    ofstream txt(Form("pdf/jerSF/Summer20%s_L2Residual_AK4PFchs.txt",cera));
    txt << "{1 JetEta 2 JetPt Rho "
	<< "sqrt(max([0]*fabs([0])/(x*x)+[4]*[4]/(x*x)+"
	<< "[1]*[1]*pow(x,[3])+[2]*[2],0.))/"
	<< "sqrt(max([5]*fabs([5])/(x*x)+[9]*[9]/(x*x)+"
	<< "[6]*[6]*pow(x,[8])+[7]*[7],0.))"
	<< " Correction L2Relative}" << endl;

    // Rho from HLT_PFJet500,550/Incjet/PFComposition/prho13->at(1000 GeV)
    double rho = 19.59; // Run2
    TString tera = era.c_str();
    if (tera.Contains("UL2016APV")) rho = 14.06;
    if (tera.Contains("UL2016BCDEF")) rho = 14.06;
    if (tera.Contains("UL2016GH")) rho = 16.55;
    if (tera.Contains("UL2017")) rho = 21.72;
    if (tera.Contains("UL2018")) rho = 20.68;
    if (tera.Contains("Run2")) rho = 19.59;

    for (int i = neta-1; i != -1; --i) {
      JES &jes = vjes[i];
      txt << Form("%6.3f %6.3f %2d %2d %4d"
		  " %6.2f %5.3f\n",
		  -jes.eta-jes.deta, -jes.eta+jes.deta, 4, 8, 6500,
		  jes.p0, jes.p1);
    } // for i in -neta
    for (int i = 0; i != neta; ++i) {
      JES &jes = vjes[i];
      txt << Form("%6.3f %6.3f %2d %2d %4d"
		  " %6.2f %5.3f\n",
		  +jes.eta-jes.deta, +jes.eta+jes.deta, 14, 8, 6500,
		  jes.p0, jes.p1);
    } // for i in +neta
  } // produce text file
			      
} // DijetHistosOverLayJES

int findBin(TH2D *h2, double x, double *xnew) {

    int i = h2->GetXaxis()->FindBin(x);
    double x2 = h2->GetXaxis()->GetBinLowEdge(i);
    if (fabs(h2->GetXaxis()->GetBinLowEdge(i-1)-x)<fabs(x2-x)) --i;
    if (fabs(h2->GetXaxis()->GetBinLowEdge(i+1)-x)<fabs(x2-x)) ++i;
    x2 = h2->GetXaxis()->GetBinLowEdge(i);
    if (xnew) (*xnew) = x2;
    
    return i;
} // findBin


void addBins(TH1D *h1to, TH2D *h2from, int i1, int i2,
	     TH1D *h1count, TH2D *h2count) {

  assert(h1to->GetNbinsX()==h2from->GetNbinsY());
  
  for (int j = 1; j != h1to->GetNbinsX()+1; ++j) {

    double sumw = h1count->GetBinContent(j);
    double sumwz = sumw * h1to->GetBinContent(j);
    double sumwe2 = sumw * pow(h1to->GetBinError(j),2);
    
    for (int i = i1; i != i2+1; ++i) {
      
      double w = h2count->GetBinContent(i,j);
      double wz = w * h2from->GetBinContent(i,j);
      double we2 = w * pow(h2from->GetBinError(i,j),2);
      sumw += w;
      sumwz += wz;
      sumwe2 += we2;
    } // for j
    
    h1to->SetBinContent(j, sumw ? sumwz / sumw : 0);
    h1to->SetBinError(j, sumw ? sqrt(sumwe2 / sumw) : 0);
    h1count->SetBinContent(j, sumw);
  } // for i
} // addBins

void rebin(TH1D *h1, TH1D *h1n, TH1D *h1old, TH1D *h1nold) {

  // Add bins with sum of weights
  for (int i = 1; i != h1old->GetNbinsX()+1; ++i) {
    int j = h1->FindBin(h1old->GetBinCenter(i));
    double n = h1nold->GetBinContent(i);
    h1->SetBinContent(j, h1->GetBinContent(j) + n*h1old->GetBinContent(i));
    h1->SetBinError(j, h1->GetBinError(j) + n*pow(h1old->GetBinError(i),2));
    h1n->SetBinContent(j, h1n->GetBinContent(j) + n);
    h1n->SetBinError(j, h1n->GetBinContent(j)+n*pow(h1nold->GetBinError(i),2));
  }
  for (int i = 1; i != h1->GetNbinsX()+1; ++i) {
    double n = h1n->GetBinContent(i);
    h1->SetBinContent(i, n ? h1->GetBinContent(i) / n : 0);
    h1->SetBinError(i, n ? sqrt(h1->GetBinError(i)/n) : 0);
    h1n->SetBinError(i, n ? sqrt(h1n->GetBinError(i)/n) : 0);
  }

} // rebin
