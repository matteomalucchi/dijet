// Purpose: make plots for MPFX introduction talk
#include "TFile.h"
#include "TProfile2D.h"
#include "TF1.h"
#include "TLine.h"
#include "TGraphErrors.h"
#include "TGraphAsymmErrors.h"

#include "../jecsys2020/tdrstyle_mod15.C"

#include "CondFormats/JetMETObjects/interface/JetResolutionObject.h"
#include "JetMETCorrections/Modules/interface/JetResolution.h"

#include <iostream>
#include <cstdio>
#include <map>
#include <string>
using namespace std;

void MPFXIntro() {

  setTDRStyle();
  TDirectory *curdir = gDirectory;
  
  // Smear JER
  // NB: could implement time dependence as in jetphys/IOV.h
  //JME::JetResolution *jer(0);
  //JME::JetResolutionScaleFactor *jersf(0);
  //string jerpath = "JRDatabase/textFiles/Summer20UL16_JRV3_MC/Summer20UL16_JRV3_MC_PtResolution_AK4PFchs.txt";
  //string jerpathsf = "JRDatabase/textFiles/Summer20UL16_JRV3_MC/Summer20UL16_JRV3_MC_SF_AK4PFchs.txt";
  //jer = new JME::JetResolution(jerpath.c_str());
  //jersf = new JME::JetResolutionScaleFactor(jerpathsf.c_str());  

  // File containing MC truth averaged over mu
  TFile *ft = new TFile("../JERCProtoLab/Summer20UL16/MC_JER_avg_mu/JER_MCtruth_avg_mu_UL16.root","READ");
  assert(ft && !ft->IsZombie());

  bool isMC = true;
  
  lumi_13TeV = "UL2016 MadGraph MC";
  TFile *fm = new TFile("files/jmenano_mc_cmb_v22ul16mg.root","READ");
  if (!isMC) {
    lumi_13TeV = "UL2016GH, 16.8 fb^{-1}";
    fm = new TFile("files/jmenano_data_cmb_v22ul16.root","READ");
  }
  assert(fm && !fm->IsZombie());

  curdir->cd();

  // Reference MC truth
  TGraphErrors *gt(0);
  gt = (TGraphErrors*)ft->Get("ak4pfchsl1l2l3/RelResVsJetPt_JetEta0.261to0.522_Mu0to60");
  assert(gt);
  gt = (TGraphErrors*)gt->Clone("gt");

  // Dijet MPF
  TH2D *h2m2s = (TH2D*)fm->Get("Dijet2/h2m2s"); assert(h2m2s);
  int ieta = h2m2s->GetXaxis()->FindBin(0.3);
  double etamin = h2m2s->GetXaxis()->GetBinLowEdge(ieta);
  double etamax = h2m2s->GetXaxis()->GetBinLowEdge(ieta+1);
  TH1D *h1m2s = h2m2s->ProjectionY("h1m2s",ieta,ieta);
  TH2D *h2m2xs = (TH2D*)fm->Get("Dijet2/h2m2xs"); assert(h2m2s);
  TH1D *h1m2xs = h2m2xs->ProjectionY("h1m2xs",ieta,ieta);
  TH2D *h2bal = (TH2D*)fm->Get("Dijet2/h2bal"); assert(h2m2s);
  TH1D *h1bal = h2bal->ProjectionY("h1bal",ieta,ieta);
  TH2D *h2mos = (TH2D*)fm->Get("Dijet2/h2mos"); assert(h2mos);
  TH1D *h1mos = h2mos->ProjectionY("h1mos",ieta,ieta);
  TH2D *h2moxs = (TH2D*)fm->Get("Dijet2/h2moxs"); assert(h2moxs);
  TH1D *h1moxs = h2moxs->ProjectionY("h1moxs",ieta,ieta);
  TH2D *h2fsr = (TH2D*)fm->Get("Dijet2/h2fsr"); assert(h2fsr);
  TH1D *h1fsr = h2fsr->ProjectionY("h1fsr",ieta,ieta);
  TH2D *h2jrb = (TH2D*)fm->Get("Dijet2/h2jrb"); assert(h2jrb);
  TH1D *h1jrb = h2jrb->ProjectionY("h1jrb",ieta,ieta);
  TH2D *h2m0s = (TH2D*)fm->Get("Dijet2/h2m0s"); assert(h2m0s);
  TH1D *h1m0s = h2m0s->ProjectionY("h1m0s",ieta,ieta);
  TH2D *h2m0xs = (TH2D*)fm->Get("Dijet2/h2m0xs"); assert(h2m0xs);
  TH1D *h1m0xs = h2m0xs->ProjectionY("h1m0xs",ieta,ieta);
  TH2D *h2mpfx = (TH2D*)fm->Get("Dijet2/h2mpfx"); assert(h2mpfx);
  TH1D *h1mpfx = h2mpfx->ProjectionY("h1mpfx",ieta,ieta);
  TH2D *h2n = (TH2D*)fm->Get("Dijet2/h2n"); assert(h2n);
  TH1D *h1n = h2n->ProjectionY("h1n",ieta,ieta);
  TH2D *h2jer = (TH2D*)fm->Get("Dijet2/h2jer"); assert(h2jer);
  TH1D *h1jer = h2jer->ProjectionY("h1jer",ieta,ieta);
  
  
  TH1D *h = tdrHist("h","Resolution",0,0.35);
  TLatex *tex = new TLatex();
  tex->SetNDC(); tex->SetTextSize(0.045);
  
  // Range settings
  h1m2s->GetXaxis()->SetRangeUser(15,2000);
  h1m2xs->GetXaxis()->SetRangeUser(15,2000);
  h1bal->GetXaxis()->SetRangeUser(15,2000);
  h1mos->GetXaxis()->SetRangeUser(15,2000);
  h1moxs->GetXaxis()->SetRangeUser(15,2000);
  h1fsr->GetXaxis()->SetRangeUser(15,2000);
  h1m0s->GetXaxis()->SetRangeUser(15,2500);
  h1m0xs->GetXaxis()->SetRangeUser(15,2500);
  h1mpfx->GetXaxis()->SetRangeUser(15,2500);
  h1jer->GetXaxis()->SetRangeUser(15,2500);
  
  extraText = "Private";

  // First step: only MPF2
  TCanvas *c1 = tdrCanvas("c1",h,4,11,kSquare);
  gPad->SetLogx();

  gt->GetListOfFunctions()->Delete();
  tdrDraw(gt,"samePlz",kNone,kBlack,kSolid);
  tdrDraw(h1m2s,"samePlz",kFullTriangleUp,kRed,kSolid);

  TLegend *leg = tdrLeg(0.50,0.90-2*0.05,0.80,0.90);
  leg->AddEntry(h1m2s,"MPF2","PLE");
  leg->AddEntry(gt,"MC truth","L");


  tex->DrawLatex(0.20,0.17,Form("%1.3f #leq |#eta| < %1.3f",etamin,etamax));
  c1->SaveAs("pdf/MPFXIntro/MPFXIntro_step1.pdf");
    

  // Step 2: add MPF2X
  TCanvas *c2 = tdrCanvas("c2",h,4,11,kSquare);
  gPad->SetLogx();

  tdrDraw(gt,"samePlz",kNone,kBlack,kSolid);
  tdrDraw(h1m2s,"samePlz",kOpenTriangleUp,kRed,kSolid);
  tdrDraw(h1m2xs,"samePlz",kFullTriangleDown,kBlue,kSolid);

  TLegend *leg2 = tdrLeg(0.50,0.90-3*0.05,0.80,0.90);
  leg2->AddEntry(h1m2s,"MPF2","PLE");
  leg2->AddEntry(h1m2xs,"MPF2X","PLE");
  leg2->AddEntry(gt,"MC truth","L");

  tex->DrawLatex(0.20,0.17,Form("%1.3f #leq |#eta| < %1.3f",etamin,etamax));
  c2->SaveAs("pdf/MPFXIntro/MPFXIntro_step2.pdf");
  

  // Step 3: add BAL=MPF2-MPF2X, shade the two
  TCanvas *c3 = tdrCanvas("c3",h,4,11,kSquare);
  gPad->SetLogx();

  tdrDraw(gt,"samePlz",kNone,kBlack,kSolid);
  tdrDraw(h1m2s,"samePlz",kOpenTriangleUp,kRed-9,kSolid);
  tdrDraw(h1m2xs,"samePlz",kOpenTriangleDown,kBlue-9,kSolid);
  tdrDraw(h1bal,"samePlz",kFullStar,kMagenta+2,kSolid);

  TLegend *leg3 = tdrLeg(0.50,0.90-4*0.05,0.80,0.90);
  leg3->AddEntry(h1bal,"B=MPF2(-)MPF2X","PLE");
  leg3->AddEntry(h1m2s,"MPF2","PLE");
  leg3->AddEntry(h1m2xs,"MPF2X","PLE");
  leg3->AddEntry(gt,"MC truth","L");

  tex->DrawLatex(0.20,0.17,Form("%1.3f #leq |#eta| < %1.3f",etamin,etamax));
  c3->SaveAs("pdf/MPFXIntro/MPFXIntro_step3.pdf");

  
  // Step 4: Just show BAL
  TCanvas *c4 = tdrCanvas("c4",h,4,11,kSquare);
  gPad->SetLogx();

  tdrDraw(gt,"samePlz",kNone,kBlack,kSolid);
  tdrDraw(h1bal,"samePlz",kFullStar,kMagenta+2,kSolid);

  TLegend *leg4 = tdrLeg(0.50,0.90-2*0.05,0.80,0.90);
  leg4->AddEntry(h1bal,"B=MPF2(-)MPF2X","PLE");
  leg4->AddEntry(gt,"MC truth","L");

  tex->DrawLatex(0.20,0.17,Form("%1.3f #leq |#eta| < %1.3f",etamin,etamax));
  c4->SaveAs("pdf/MPFXIntro/MPFXIntro_step4.pdf");

  
  // Step 5: Add MO
  TCanvas *c5 = tdrCanvas("c5",h,4,11,kSquare);
  gPad->SetLogx();

  tdrDraw(gt,"samePlz",kNone,kBlack,kSolid);
  tdrDraw(h1bal,"samePlz",kOpenStar,kMagenta+2,kSolid);
  tdrDraw(h1mos,"samePlz",kFullDiamond,kRed,kSolid);

  TLegend *leg5 = tdrLeg(0.50,0.90-3*0.05,0.80,0.90);
  leg5->AddEntry(h1bal,"B=MPF2(-)MPF2X","PLE");
  leg5->AddEntry(h1mos,"MPFO","PLE");
  leg5->AddEntry(gt,"MC truth","L");

  tex->DrawLatex(0.20,0.17,Form("%1.3f #leq |#eta| < %1.3f",etamin,etamax));
  c5->SaveAs("pdf/MPFXIntro/MPFXIntro_step5.pdf");

    
  // Step 6: Add MOX
  TCanvas *c6 = tdrCanvas("c6",h,4,11,kSquare);
  gPad->SetLogx();

  tdrDraw(gt,"samePlz",kNone,kBlack,kSolid);
  tdrDraw(h1bal,"samePlz",kOpenStar,kMagenta+2,kSolid);
  tdrDraw(h1mos,"samePlz",kFullDiamond,kRed,kSolid);
  tdrDraw(h1moxs,"samePlz",kFullDiamond,kYellow+2,kSolid);

  TLegend *leg6 = tdrLeg(0.50,0.90-4*0.05,0.80,0.90);
  leg6->AddEntry(h1bal,"B=MPF2(-)MPF2X","PLE");
  leg6->AddEntry(h1mos,"MPFO","PLE");
  leg6->AddEntry(h1moxs,"MPFOX","PLE");
  leg6->AddEntry(gt,"MC truth","L");

  tex->DrawLatex(0.20,0.17,Form("%1.3f #leq |#eta| < %1.3f",etamin,etamax));
  c6->SaveAs("pdf/MPFXIntro/MPFXIntro_step6.pdf");


  // Step 7: Add MOX
  TCanvas *c7 = tdrCanvas("c7",h,4,11,kSquare);
  gPad->SetLogx();

  tdrDraw(gt,"samePlz",kNone,kBlack,kSolid);
  tdrDraw(h1bal,"samePlz",kOpenStar,kMagenta+2,kSolid);
  tdrDraw(h1mos,"samePlz",kOpenDiamond,kRed-9,kSolid);
  tdrDraw(h1moxs,"samePlz",kOpenDiamond,kYellow+2,kSolid);
  h1moxs->SetFillColorAlpha(kYellow+1,0.5);
  tdrDraw(h1fsr,"samePlz",kFullDiamond,kOrange+2,kSolid);

  TLegend *leg7 = tdrLeg(0.50,0.90-5*0.05,0.80,0.90);
  leg7->AddEntry(h1bal,"B=MPF2(-)MPF2X","PLE");
  leg7->AddEntry(h1fsr,"F=MPFO(-)MPFOX","PLE");
  leg7->AddEntry(h1mos,"MPFO","PLE");
  leg7->AddEntry(h1moxs,"MPFOX","PLE");
  leg7->AddEntry(gt,"MC truth","L");

  tex->DrawLatex(0.20,0.17,Form("%1.3f #leq |#eta| < %1.3f",etamin,etamax));
  c7->SaveAs("pdf/MPFXIntro/MPFXIntro_step7.pdf");

  
  // Step 8: Add ISR=MP2X again
  TCanvas *c8 = tdrCanvas("c8",h,4,11,kSquare);
  gPad->SetLogx();

  tdrDraw(gt,"samePlz",kNone,kBlack,kSolid);
  tdrDraw(h1bal,"samePlz",kOpenStar,kMagenta+2,kSolid);
  tdrDraw(h1fsr,"samePlz",kFullDiamond,kOrange+2,kSolid);
  tdrDraw(h1m2xs,"samePlz",kFullDiamond,kBlue,kSolid);

  TLegend *leg8 = tdrLeg(0.50,0.90-4*0.05,0.80,0.90);
  leg8->AddEntry(h1bal,"B=MPF2(-)MPF2X","PLE");
  leg8->AddEntry(h1fsr,"F=MPFO(-)MPFOX","PLE");
  leg8->AddEntry(h1m2xs,"I=MPF2X","PLE");
  leg8->AddEntry(gt,"MC truth","L");

  tex->DrawLatex(0.20,0.17,Form("%1.3f #leq |#eta| < %1.3f",etamin,etamax));
  c8->SaveAs("pdf/MPFXIntro/MPFXIntro_step8.pdf");


  // Step 9: Remove ISR=MP2X
  TCanvas *c9 = tdrCanvas("c9",h,4,11,kSquare);
  gPad->SetLogx();

  tdrDraw(gt,"samePlz",kNone,kBlack,kSolid);
  tdrDraw(h1bal,"samePlz",kFullStar,kMagenta+2,kSolid);
  tdrDraw(h1fsr,"samePlz",kFullDiamond,kOrange+2,kSolid);

  TLegend *leg9 = tdrLeg(0.50,0.90-3*0.05,0.80,0.90);
  leg9->AddEntry(h1bal,"B=MPF2(-)MPF2X","PLE");
  leg9->AddEntry(h1fsr,"F=MPFO(-)MPFOX","PLE");
  leg9->AddEntry(gt,"MC truth","L");

  tex->DrawLatex(0.20,0.17,Form("%1.3f #leq |#eta| < %1.3f",etamin,etamax));
  c9->SaveAs("pdf/MPFXIntro/MPFXIntro_step9.pdf");

  
  // Step 10: Calculate JERB = B(-)F
  TCanvas *c10 = tdrCanvas("c10",h,4,11,kSquare);
  gPad->SetLogx();

  tdrDraw(gt,"samePlz",kNone,kBlack,kSolid);
  tdrDraw(h1bal,"samePlz",kOpenStar,kMagenta+2-9,kSolid);
  tdrDraw(h1fsr,"samePlz",kOpenDiamond,kOrange+2-9,kSolid);
  tdrDraw(h1jrb,"samePlz",kFullSquare,kGreen+2,kSolid);

  TLegend *leg10 = tdrLeg(0.50,0.90-4*0.05,0.80,0.90);
  leg10->AddEntry(h1jrb,"JRB=B(-)F","PLE");
  leg10->AddEntry(h1bal,"B=MPF2(-)MPF2X","PLE");
  leg10->AddEntry(h1fsr,"F=MPFO(-)MPFOX","PLE");
  leg10->AddEntry(gt,"MC truth","L");

  tex->DrawLatex(0.20,0.17,Form("%1.3f #leq |#eta| < %1.3f",etamin,etamax));
  c10->SaveAs("pdf/MPFXIntro/MPFXIntro_step10.pdf");

  
  // Step 11: Compare MPF2 and JERB
  TCanvas *c11 = tdrCanvas("c11",h,4,11,kSquare);
  gPad->SetLogx();

  tdrDraw(gt,"samePlz",kNone,kBlack,kSolid);
  tdrDraw(h1m2s,"samePlz",kFullTriangleUp,kRed,kSolid);
  tdrDraw(h1jrb,"samePlz",kFullSquare,kGreen+2,kSolid);

  TLegend *leg11 = tdrLeg(0.50,0.90-3*0.05,0.80,0.90);
  leg11->AddEntry(h1m2s,"MPF2","PLE");
  leg11->AddEntry(h1jrb,"JRB=B(-)F","PLE");
  leg11->AddEntry(gt,"MC truth","L");

  tex->DrawLatex(0.20,0.17,Form("%1.3f #leq |#eta| < %1.3f",etamin,etamax));
  c11->SaveAs("pdf/MPFXIntro/MPFXIntro_step11.pdf");


  // Step 12: Compare MPF2 and MPF
  TCanvas *c12 = tdrCanvas("c12",h,4,11,kSquare);
  gPad->SetLogx();

  tdrDraw(gt,"samePlz",kNone,kBlack,kSolid);
  tdrDraw(h1m2s,"samePlz",kOpenTriangleUp,kRed,kSolid);
  tdrDraw(h1jrb,"samePlz",kOpenSquare,kGreen+2,kSolid);
  tdrDraw(h1m0s,"samePlz",kFullCircle,kRed,kSolid);

  TLegend *leg12 = tdrLeg(0.50,0.90-4*0.05,0.80,0.90);
  leg12->AddEntry(h1m0s,"MPF","PLE");
  leg12->AddEntry(h1m2s,"MPF2","PLE");
  leg12->AddEntry(h1jrb,"JRB=B(-)F","PLE");
  leg12->AddEntry(gt,"MC truth","L");

  tex->DrawLatex(0.20,0.17,Form("%1.3f #leq |#eta| < %1.3f",etamin,etamax));
  c12->SaveAs("pdf/MPFXIntro/MPFXIntro_step12.pdf");


  // Step 13: Add MPFX
  TCanvas *c13 = tdrCanvas("c13",h,4,11,kSquare);
  gPad->SetLogx();

  tdrDraw(gt,"samePlz",kNone,kBlack,kSolid);
  tdrDraw(h1m2s,"samePlz",kOpenTriangleUp,kRed,kSolid);
  tdrDraw(h1jrb,"samePlz",kOpenSquare,kGreen+2,kSolid);
  tdrDraw(h1m0s,"samePlz",kFullCircle,kRed,kSolid);
  tdrDraw(h1m0xs,"samePlz",kFullCircle,kBlue,kSolid);

  TLegend *leg13 = tdrLeg(0.50,0.90-5*0.05,0.80,0.90);
  leg13->AddEntry(h1m0s,"MPF","PLE");
  leg13->AddEntry(h1m0xs,"MPFX","PLE");
  leg13->AddEntry(h1m2s,"MPF2","PLE");
  leg13->AddEntry(h1jrb,"JRB=B(-)F","PLE");
  leg13->AddEntry(gt,"MC truth","L");

  tex->DrawLatex(0.20,0.17,Form("%1.3f #leq |#eta| < %1.3f",etamin,etamax));
  c13->SaveAs("pdf/MPFXIntro/MPFXIntro_step13.pdf");

  
  // Step 14: Only MPF+MPFX
  TCanvas *c14 = tdrCanvas("c14",h,4,11,kSquare);
  gPad->SetLogx();

  tdrDraw(gt,"samePlz",kNone,kBlack,kSolid);
  tdrDraw(h1m0s,"samePlz",kFullCircle,kRed,kSolid);
  tdrDraw(h1m0xs,"samePlz",kFullCircle,kBlue,kSolid);

  TLegend *leg14 = tdrLeg(0.50,0.90-3*0.05,0.80,0.90);
  leg14->AddEntry(h1m0s,"MPF","PLE");
  leg14->AddEntry(h1m0xs,"MPFX","PLE");
  leg14->AddEntry(gt,"MC truth","L");

  tex->DrawLatex(0.20,0.17,Form("%1.3f #leq |#eta| < %1.3f",etamin,etamax));
  c14->SaveAs("pdf/MPFXIntro/MPFXIntro_step14.pdf");

  
  // Step 15: Add JERA=MPF(-)MPFX
  TCanvas *c15 = tdrCanvas("c15",h,4,11,kSquare);
  gPad->SetLogx();

  tdrDraw(gt,"samePlz",kNone,kBlack,kSolid);
  tdrDraw(h1m0s,"samePlz",kOpenCircle,kRed-9,kSolid);
  tdrDraw(h1m0xs,"samePlz",kOpenCircle,kBlue-9,kSolid);
  tdrDraw(h1mpfx,"samePlz",kFullCircle,kGreen+2,kSolid);

  TLegend *leg15 = tdrLeg(0.50,0.90-4*0.05,0.80,0.90);
  leg15->AddEntry(h1mpfx,"JRA=MPF(-)MPFX","PLE");
  leg15->AddEntry(h1m0s,"MPF","PLE");
  leg15->AddEntry(h1m0xs,"MPFX","PLE");
  leg15->AddEntry(gt,"MC truth","L");

  tex->DrawLatex(0.20,0.17,Form("%1.3f #leq |#eta| < %1.3f",etamin,etamax));
  c15->SaveAs("pdf/MPFXIntro/MPFXIntro_step15.pdf");

  
  // Step 16: Only JERA=MPF(-)MPFX
  TCanvas *c16 = tdrCanvas("c16",h,4,11,kSquare);
  gPad->SetLogx();

  tdrDraw(gt,"samePlz",kNone,kBlack,kSolid);
  tdrDraw(h1mpfx,"samePlz",kFullCircle,kGreen+2,kSolid);

  TLegend *leg16 = tdrLeg(0.50,0.90-2*0.05,0.80,0.90);
  leg16->AddEntry(h1mpfx,"JRA=MPF(-)MPFX","PLE");
  leg16->AddEntry(gt,"MC truth","L");

  tex->DrawLatex(0.20,0.17,Form("%1.3f #leq |#eta| < %1.3f",etamin,etamax));
  c16->SaveAs("pdf/MPFXIntro/MPFXIntro_step16.pdf");


  // Step 17: Add JERB
  TCanvas *c17 = tdrCanvas("c17",h,4,11,kSquare);
  gPad->SetLogx();

  tdrDraw(gt,"samePlz",kNone,kBlack,kSolid);
  tdrDraw(h1mpfx,"samePlz",kFullCircle,kGreen+2,kSolid);
  tdrDraw(h1jrb,"samePlz",kOpenSquare,kGreen+2,kSolid);

  TLegend *leg17 = tdrLeg(0.50,0.90-3*0.05,0.80,0.90);
  leg17->AddEntry(h1mpfx,"JRA=MPF(-)MPFX","PLE");
  leg17->AddEntry(h1jrb,"JRB=B(-)F","PLE");
  leg17->AddEntry(gt,"MC truth","L");

  tex->DrawLatex(0.20,0.17,Form("%1.3f #leq |#eta| < %1.3f",etamin,etamax));
  c17->SaveAs("pdf/MPFXIntro/MPFXIntro_step17.pdf");

  
  // Step 17b: Add Noise, remove JRB
  TCanvas *c17b = tdrCanvas("c17b",h,4,11,kSquare);
  gPad->SetLogx();

  tdrDraw(gt,"samePlz",kNone,kBlack,kSolid);
  tdrDraw(h1mpfx,"samePlz",kOpenCircle,kGreen+2,kSolid);
  tdrDraw(h1n,"samePz",kFullDiamond,kRed,kSolid,-1,kNone,0);

  TLegend *leg17b = tdrLeg(0.50,0.90-3*0.05,0.80,0.90);
  leg17b->AddEntry(h1mpfx,"JRA=MPF(-)MPFX","PLE");
  leg17b->AddEntry(h1n,"RC noise","PLE");
  leg17b->AddEntry(gt,"MC truth","L");

  tex->DrawLatex(0.20,0.17,Form("%1.3f #leq |#eta| < %1.3f",etamin,etamax));
  c17b->SaveAs("pdf/MPFXIntro/MPFXIntro_step17b.pdf");


  // Step 17c: replace JRA with JER=JRA(+)N
  TCanvas *c17c = tdrCanvas("c17c",h,4,11,kSquare);
  gPad->SetLogx();

  tdrDraw(gt,"samePlz",kNone,kBlack,kSolid);
  tdrDraw(h1mpfx,"samePlz",kOpenCircle,kGreen+2,kSolid);
  tdrDraw(h1n,"samePz",kOpenDiamond,kRed,kSolid,-1,kNone,0);
  tdrDraw(h1jer,"samePlz",kFullCircle,kGreen+2,kSolid);
  
  TLegend *leg17c = tdrLeg(0.50,0.90-4*0.05,0.80,0.90);
  leg17c->AddEntry(h1jer,"JER=JRA(+)RC","PLE");
  leg17c->AddEntry(h1mpfx,"JRA=MPF(-)MPFX","PLE");
  leg17c->AddEntry(h1n,"RC noise","PLE");
  leg17c->AddEntry(gt,"MC truth","L");

  tex->DrawLatex(0.20,0.17,Form("%1.3f #leq |#eta| < %1.3f",etamin,etamax));
  c17c->SaveAs("pdf/MPFXIntro/MPFXIntro_step17c.pdf");

  // Step 17d: Drop h1n, MPFX, add JRBN
  TCanvas *c17d = tdrCanvas("c17d",h,4,11,kSquare);
  gPad->SetLogx();

  tdrDraw(gt,"samePlz",kNone,kBlack,kSolid);
  tdrDraw(h1jer,"samePlz",kFullCircle,kGreen+2,kSolid);
  tdrDraw(h1jrb,"samePlz",kOpenSquare,kGreen+2,kSolid);
  
  TLegend *leg17d = tdrLeg(0.50,0.90-3*0.05,0.80,0.90);
  leg17d->AddEntry(h1jer,"JER=MPFX(+)RC","PLE");
  leg17d->AddEntry(h1jrb,"JRB=B(-)F","PLE");
  leg17d->AddEntry(gt,"MC truth","L");

  tex->DrawLatex(0.20,0.17,Form("%1.3f #leq |#eta| < %1.3f",etamin,etamax));
  c17d->SaveAs("pdf/MPFXIntro/MPFXIntro_step17d.pdf");
  
  // Step 18: Add MPF2 and MPFX
  TCanvas *c18 = tdrCanvas("c18",h,4,11,kSquare);
  gPad->SetLogx();

  tdrDraw(gt,"samePlz",kNone,kBlack,kSolid);
  tdrDraw(h1m0s,"samePlz",kOpenCircle,kRed,kSolid);
  tdrDraw(h1m2s,"samePlz",kOpenDiamond,kRed,kSolid);
  tdrDraw(h1jer,"samePlz",kFullCircle,kGreen+2,kSolid);
  tdrDraw(h1jrb,"samePlz",kOpenSquare,kGreen+2,kSolid);

  TLegend *leg18 = tdrLeg(0.50,0.90-5*0.05,0.80,0.90);
  leg18->AddEntry(h1m0s,"MPF","PLE");
  leg18->AddEntry(h1m2s,"MPF2","PLE");
  leg18->AddEntry(h1jer,"JER=JRA(+)RC","PLE");
  leg18->AddEntry(h1jrb,"JER=B(-)F(-)I","PLE");
  leg18->AddEntry(gt,"MC truth","L");

  tex->DrawLatex(0.20,0.17,Form("%1.3f #leq |#eta| < %1.3f",etamin,etamax));
  c18->SaveAs("pdf/MPFXIntro/MPFXIntro_step18.pdf");

  ////////////////////////////////////////////////////////////////////////
  // Compare to other results
  ////////////////////////////////////////////////////////////////////////

  // Dijet alpha extrapolation
  TFile *fa = new TFile("files/dijet_balance_UL18_Summer19UL18_V5_AK4CHS.root","READ");
  assert(fa && !fa->IsZombie());

  TFile *fz = new TFile("files/zjet_balance_UL2018_jetpt_nominal_small.root","READ");
  assert(fz && !fz->IsZombie());

  TGraphAsymmErrors *ga(0), *gz(0);
  ga = (TGraphAsymmErrors*)fa->Get(isMC ? "dijet_balance_jer_MC_0p261_0p522_FE_nominal" : "dijet_balance_jer_Data_0p261_0p522_FE_nominal");
  assert(ga);
  gz = (TGraphAsymmErrors*)fz->Get(isMC ? "mc" : "data");
  assert(gz);

  
  // Step 19: Compare MPFX to dijet alpha extrapolation
  TCanvas *c19 = tdrCanvas("c19",h,4,11,kSquare);
  gPad->SetLogx();

  tdrDraw(gt,"samePlz",kNone,kBlack,kSolid);
  tdrDraw(h1jer,"samePlz",kFullCircle,kGreen+2,kSolid);
  tdrDraw(ga,"samePz",kFullStar,kBlack,kSolid);

  TLegend *leg19 = tdrLeg(0.50,0.90-3*0.05,0.80,0.90);
  leg19->AddEntry(h1jer,"MPFX(+)RC","PLE");
  leg19->AddEntry(ga,"Dijet UL18 #alpha-extr.","PLE");
  leg19->AddEntry(gt,"MC truth","L");

  tex->DrawLatex(0.20,0.17,Form("%1.3f #leq |#eta| < %1.3f",etamin,etamax));
  c19->SaveAs("pdf/MPFXIntro/MPFXIntro_step19.pdf");

  // Step 20: Add Z+jet
  TCanvas *c20 = tdrCanvas("c20",h,4,11,kSquare);
  gPad->SetLogx();

  tdrDraw(gt,"samePlz",kNone,kBlack,kSolid);
  tdrDraw(h1jer,"samePlz",kFullCircle,kGreen+2,kSolid);
  tdrDraw(ga,"samePz",kFullStar,kBlack,kSolid);
  tdrDraw(gz,"samePz",kFullStar,kRed,kSolid);

  TLegend *leg20 = tdrLeg(0.50,0.90-4*0.05,0.80,0.90);
  leg20->AddEntry(h1jer,"MPFX(+)RC","PLE");
  leg20->AddEntry(ga,"Dijet UL18 #alpha-extr.","PLE");
  leg20->AddEntry(gz,"Z+jet UL18 #alpha-extr.","PLE");
  leg20->AddEntry(gt,"MC truth","L");

  tex->DrawLatex(0.20,0.17,Form("%1.3f #leq |#eta| < %1.3f",etamin,etamax));
  c20->SaveAs("pdf/MPFXIntro/MPFXIntro_step20.pdf");
} // MPFXIntro


