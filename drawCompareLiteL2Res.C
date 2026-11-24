// Purpose: Draw compareLite.root results for 2D folder
#include "TFile.h"
#include "TProfile2D.h"

#include "tdrstyle_mod22.C"

void drawCompareLiteL2Res_runs(string run);

TFile *_fout(0);
void drawCompareLiteL2Res() {

  TDirectory *curdir = gDirectory;
  _fout = new TFile("files/compareLiteEras.root","UPDATE");
  curdir->cd();
  
  drawCompareLiteL2Res_runs("2022C");
  drawCompareLiteL2Res_runs("2022D");
  drawCompareLiteL2Res_runs("2022CD");

  drawCompareLiteL2Res_runs("2022E");
  //drawCompareLiteL2Res_runs("2022F");
  drawCompareLiteL2Res_runs("2022G");
  //drawCompareLiteL2Res_runs("2022FG");

  drawCompareLiteL2Res_runs("2023Cv123");
  drawCompareLiteL2Res_runs("2023Cv4");
  drawCompareLiteL2Res_runs("2023D");

  _fout->Write();
  _fout->Close();
}

void drawCompareLiteL2Res_runs(string run) {

  setTDRStyle();
  TDirectory *curdir = gDirectory;

  const char *cr = run.c_str();
  //TFile *f = new TFile("files/compareLite_2022D_Henning_v2.root","READ");
  TFile *f = new TFile(Form("rootfiles/Henning_v2/compareLite_%s.root",cr),"READ");
  //TFile *f = new TFile("files/compareLite_2023D_withJESReapplied.root","READ");
  assert(f && !f->IsZombie());

  // For L2Res compareLiteEras.root
  TProfile *p = (TProfile*)f->Get("pd_tp"); assert(p);
  //TProfile *pa = (TProfile*)f->Get("pa_tp"); assert(pa);
  //TProfile *pb = (TProfile*)f->Get("pb_tp"); assert(pb);
  //TProfile2D *p2a = (TProfile2D*)f->Get("2D/p2a_tp"); assert(p2a);
  //TProfile2D *p2b = (TProfile2D*)f->Get("2D/p2b_tp"); assert(p2b);

  
  TProfile2D *p2 = (TProfile2D*)f->Get("2D/p2d_tp"); assert(p2);
  //TProfile2D *p2 = (TProfile2D*)f->Get("2D/p2d_dm"); assert(p2);

  TH1D *h = tdrHist("h","#eta",-5.2,5.2,"p_{T} (GeV)",49.,3500.);
  lumi_136TeV = cr;//"2022D";
  extraText = "Private";
  TCanvas *c1 = tdrCanvas("c1",h,8,0,kSquare);
  c1->SetLeftMargin(0.10);
  c1->SetRightMargin(0.25);
  h->GetYaxis()->SetTitleOffset(0.7);
  
  c1->SetLogx();
  p2->Draw("COLZ SAME");
  p2->GetZaxis()->SetRangeUser(-0.025+1e-4,0.025-1e-4);
  p2->GetZaxis()->SetTitleOffset(1.7);
  p2->GetZaxis()->SetTitle("(p_{T,B}-p_{T,A})/p_{T,tag}");
  gPad->RedrawAxis();
  gPad->Update();

  c1->SaveAs(Form("pdf/drawCompareLiteL2Res/drawCompareLiteL2Res_TP_%s.pdf",cr));
  //c1->SaveAs("pdf/drawCompareLiteL2Res_TP_2022D.pdf");
  //c1->SaveAs("pdf/drawCompareLiteL2Res_DM_2022D.pdf");
  //c1->SaveAs("pdf/drawCompareLiteL2Res_2023C.pdf");

  
  int ix1 = p2->GetXaxis()->FindBin(49.);//638.);
  int ix2 = p2->GetXaxis()->FindBin(3500.);//790.-1);
  TProfile *p1 = p2->ProfileY("p1",ix1,ix2);//,-1,-1);
  p1->Scale(100.);
  
  int jx1 = p2->GetXaxis()->FindBin(638.);
  int jx2 = p2->GetXaxis()->FindBin(790.-1);
  TProfile *p1h = p2->ProfileY("p1h",jx1,jx2);
  p1h->Scale(100.);
  
  int kx1 = p2->GetXaxis()->FindBin(49.);
  int kx2 = p2->GetXaxis()->FindBin(84.-1);
  TProfile *p1l = p2->ProfileY("p1l",kx1,kx2);
  p1l->Scale(100.);

  TLine *l = new TLine();
  l->SetLineStyle(kDashed);
  l->SetLineColor(kGray+1);

  TH1D *h2 = tdrHist("h2","#LT22Sep#GT / #LT19Dec#GT (%)",-0.013*100,0.023*100,
		     "#eta",-5.2,5.2);
  lumi_136TeV = "2022D";
  extraText = "Private";
  TCanvas *c2 = tdrCanvas("c2",h2,8,0,kSquare);

  tdrDraw(p1,"PHz",kFullCircle,kBlack);
  tdrDraw(p1l,"Pz",kOpenSquare,kBlue);
  tdrDraw(p1h,"Pz",kOpenCircle,kRed);

  TLegend *leg2 = tdrLeg(0.66,0.90-0.04*3,0.92,0.90);
  leg2->SetTextSize(0.04);
  leg2->AddEntry(p1,"49-3500 GeV","PFLE");
  leg2->AddEntry(p1h,"638-790 GeV","PLE");
  leg2->AddEntry(p1l,"49-84 GeV","PLE");
  
  l->DrawLine(-5.2,0,5.2,0);
  l->DrawLine(-1.3,-1.5,-1.3,2.5);
  l->DrawLine(+1.3,-1.5,+1.3,2.5);

  gPad->RedrawAxis();
  c2->SaveAs(Form("pdf/drawCompareLiteL2Res/drawCompareLiteL2Res_TP_vsEta_%s.pdf",cr));
  //c2->SaveAs("pdf/drawCompareLiteL2Res_TP_vsEta_2022D.pdf");

  if (_fout) {
    _fout->cd();
    //p->Write(Form("p1_%s",cr),TObject::kOverwrite);
    //p2->Write(Form("p2_%s",cr),TObject::kOverwrite);
    p->Write(Form("1D_22Sep_minus_19Dec_over_tag_%s",cr),TObject::kOverwrite);
    p2->Write(Form("2D_22Sep_minus_19Dec_over_tag_%s",cr),TObject::kOverwrite);
    curdir->cd();
  }
} // drawCompareLiteL2Res
