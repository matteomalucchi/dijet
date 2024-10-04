// Purpose: Combine output from DijetHistosFill for different triggers
// Author:  Mikko Voutilainen, 17-Mar-2022
#include "TFile.h"
#include "TKey.h"
#include "TDirectory.h"
#include "TH1D.h"
#include "TH2D.h"
#include "TProfile2D.h"
#include <iostream>

string version = "mc_truth_below15_2022_pnetregneutrino";

int debug = 1; // 1=trg, 2=dir, 3=all
void loopOverDirectories(TDirectory *dir, TDirectory *outdir,
			 string trg, string folder);
//void mergeDijet(TDirectory *dir, TDirectory *dout);
bool copyBin(string trg, string folder, string histo, double pt, double eta);

void DijetHistosCombines(string file = "rootfiles/"+version+"/jmenano_data_out.root");

void DijetHistosCombine() {

  // DijetHistosCombines("../rootfiles/"+version+"/jmenano_data_out_2023D_JME_"+version+".root");
  // DijetHistosCombines("../rootfiles/"+version+"/jmenano_data_out_2023Cv4_JME_"+version+".root");
  // DijetHistosCombines("../rootfiles/"+version+"/jmenano_data_out_2023Cv123_JME_"+version+".root");
  // DijetHistosCombines("../rootfiles/"+version+"/jmenano_mc_out_QCD_"+version+".root");
  // DijetHistosCombines("../rootfiles/"+version+"/jmenano_mc_out_QCD-BPix_"+version+".root");


  DijetHistosCombines("../rootfiles/"+version+"/jmenano_data_out_2022C_JME_"+version+".root");
  DijetHistosCombines("../rootfiles/"+version+"/jmenano_data_out_2022D_JME_"+version+".root");
  DijetHistosCombines("../rootfiles/"+version+"/jmenano_data_out_2022CD_JME_"+version+".root");
  DijetHistosCombines("../rootfiles/"+version+"/jmenano_data_out_2022E_JME_"+version+".root");
  DijetHistosCombines("../rootfiles/"+version+"/jmenano_data_out_2022F_JME_"+version+".root");
  DijetHistosCombines("../rootfiles/"+version+"/jmenano_data_out_2022G_JME_"+version+".root");
  DijetHistosCombines("../rootfiles/"+version+"/jmenano_mc_out_2022QCD_"+version+".root");
  DijetHistosCombines("../rootfiles/"+version+"/jmenano_mc_out_2022EEQCD_"+version+".root");




  //DijetHistosCombines("../rootfiles/"+version+"/jmenano_data_out_2022FG_JME_"+version+".root");

  // DijetHistosCombines("../rootfiles/v38_Summer23MG_NoL2L3Res_Off_reweight_jets_test2/jmenano_data_out_2023D_ZB_v38_Summer23MG_NoL2L3Res_Off_reweight_jets_test2.root");
  // DijetHistosCombines("../rootfiles/v38_Summer23MG_NoL2L3Res_Off_reweight_jets_test2/jmenano_data_out_2023Cv4_ZB_v38_Summer23MG_NoL2L3Res_Off_reweight_jets_test2.root");
  // DijetHistosCombines("../rootfiles/v38_Summer23MG_NoL2L3Res_Off_reweight_jets_test2/jmenano_data_out_2023Cv123_ZB_v38_Summer23MG_NoL2L3Res_Off_reweight_jets_test2.root");
  // DijetHistosCombines("../rootfiles/v38_Summer23MG_NoL2L3Res_Off_reweight_jets_test2/jmenano_mc_out_Summer23MG_v38_Summer23MG_NoL2L3Res_Off_reweight_jets_test2.root");
  // DijetHistosCombines("../rootfiles/v38_Summer23MG_NoL2L3Res_Off_reweight_jets_test2/jmenano_mc_out_Summer23MGBPix_v38_Summer23MG_NoL2L3Res_Off_reweight_jets_test2.root");


  //DijetHistosCombines("../rootfiles/"+version+"/jmenano_data_out_2023BCv123_JME_"+version+".root");
  //DijetHistosCombines("../rootfiles/"+version+"/jmenano_data_out_2023Cv4_JME_"+version+".root");
  //DijetHistosCombines("../rootfiles/"+version+"/jmenano_data_out_2023D_JME_"+version+".root");

  //DijetHistosCombines("/media/storage/nestorma/dijet/rootfiles/v36_Summer23MG_test/jmenano_mc_out_Summer23MGBPix_test_"+version+".root");
  //DijetHistosCombines("/media/storage/nestorma/dijet/rootfiles/v36_Summer23DT_NoL2L3Res/jmenano_data_out_2023Cv123_JME_v36_Summer23DT_NoL2L3Res.root");
  //DijetHistosCombines("/media/storage/nestorma/dijet/rootfiles/v36_Summer23DT_NoL2L3Res_Winter/jmenano_data_out_2023Cv4_JME_v36_Summer23DT_NoL2L3Res.root");
  //DijetHistosCombines("/media/storage/nestorma/dijet/rootfiles/v36_Summer23DT_NoL2L3Res_Winter/jmenano_data_out_2023D_JME_v36_Summer23DT_NoL2L3Res.root");
  //DijetHistosCombines("/media/storage/nestorma/dijet/rootfiles/"+version+"/jmenano_data_out_2023Cv123_JME_"+version+".root");
  //DijetHistosCombines("/media/storage/nestorma/dijet/rootfiles/"+version+"/jmenano_data_out_2023Cv4_JME_"+version+".root");
  //DijetHistosCombines("/media/storage/nestorma/dijet/rootfiles/"+version+"/jmenano_data_out_2023D_JME_"+version+".root");
  //DijetHistosCombines("/media/storage/nestorma/dijet/rootfiles/"+version+"/");



  //DijetHistosCombines("/media/storage/nestorma/dijet/rootfiles/v36_Summer23MG_L2Res_v1/jmenano_data_out_2023Cv123_JME_"+version+".root");
  //DijetHistosCombines("/media/storage/nestorma/dijet/rootfiles/v36_Summer23MG_L2Res_v1/jmenano_data_out_2023Cv4_JME_"+version+".root");
  //DijetHistosCombines("/media/storage/nestorma/dijet/rootfiles/v36_Summer23MG_L2Res_v1/jmenano_data_out_2023D_JME_"+version+".root");
  //DijetHistosCombines("/media/storage/nestorma/dijet/rootfiles/v36_Summer23DT_NoL2L3Res_Winter/jmenano_mc_out_Summer23MGBPix_v36_Summer23DT_NoL2L3Res.root");
  // Really slow on this after all the others, rerun separately (then sec)
//  DijetHistosCombines("../rootfiles/"+version+"/jmenano_mc_out_Summer22EEMG_"+version+".root");
// DijetHistosCombines("../rootfiles/"+version+"/jmenano_mc_out_Summer22MG_"+version+".root");
  //DijetHistosCombines("/media/storage/nestorma/dijet/rootfiles/"+version+"/jmenano_mc_out_Summer23MG_"+version+".root");
  //DijetHistosCombines("/media/storage/nestorma/dijet/rootfiles/"+version+"/jmenano_mc_out_Summer23MGBPix_"+version+".root");
  //DijetHistosCombines("/media/storage/nestorma/dijet/rootfiles/"+version+"/jmenano_mc_out_Summer23MGBPix_test_"+version+".root");
  //DijetHistosCombines("/media/storage/nestorma/dijet/rootfiles/"+version+"/jmenano_mc_out_Summer23MG_test_"+version+".root");
  // DijetHistosCombines("/media/storage/nestorma/dijet/rootfiles/"+version+"/jmenano_mc_out_Summer23MG_"+version+".root");
  //DijetHistosCombines("/media/storage/nestorma/dijet/rootfiles/"+version+"/jmenano_mc_out_Summer23MGBPix_"+version+".root");

  /*
  DijetHistosCombines("rootfiles/"+version+"/jmenano_data_out_v22ul16.root");
  DijetHistosCombines("rootfiles/"+version+"/jmenano_mc_out_v22ul16flatmc.root");
  DijetHistosCombines("rootfiles/"+version+"/jmenano_mc_out_v22ul16mg.root");
  */
  //DijetHistosCombines("rootfiles/"+version+"/jmenano_mc_out_v23ul16flat.root");
  //DijetHistosCombines("rootfiles/"+version+"/jmenano_mc_out_v23ul16mg.root");

  // Before JER SF for MC
  /*
  DijetHistosCombines("haddfiles/jmenano_data_out_UL2016APV_v26c.root");
  DijetHistosCombines("rootfiles/"+version+"/jmenano_mc_out_UL2016APVMG_v26.root");
  DijetHistosCombines("haddfiles/jmenano_data_out_UL2016GH_v26c.root");
  DijetHistosCombines("rootfiles/"+version+"/jmenano_mc_out_UL2016MG_v26.root");
  DijetHistosCombines("haddfiles/jmenano_data_out_UL2017_v26.root");
  DijetHistosCombines("rootfiles/"+version+"/jmenano_mc_out_UL2017MG_v26.root");
  DijetHistosCombines("haddfiles/jmenano_data_out_UL2018_v26c.root");
  DijetHistosCombines("rootfiles/"+version+"/jmenano_mc_out_UL2018MG_v26.root");
  */


  // This one is taking a while. Why? CPU ~100%, mem up to >3 GB
  //DijetHistosCombines("haddfiles/jmenano_data_out_Run2_v26c.root");
  //DijetHistosCombines("haddfiles/jmenano_mc_out_Run2_v26.root");
  /*
  // After JER SF for MC
  DijetHistosCombines("rootfiles/"+version+"/jmenano_mc_out_UL2016APVMG_v27.root");
  DijetHistosCombines("rootfiles/"+version+"/jmenano_mc_out_UL2016MG_v27.root");
  DijetHistosCombines("rootfiles/"+version+"/jmenano_mc_out_UL2017MG_v27.root");
  DijetHistosCombines("rootfiles/"+version+"/jmenano_mc_out_UL2018MG_v27.root");
  DijetHistosCombines("haddfiles/jmenano_mc_out_Run2_v27.root");
  */

  // New Run3 files from Iita and Mikael
  // Iita_20230814/*_v1.root -> Iita_20230824_jetveto/*_JME_v1.root
  /*
  // 2022
  DijetHistosCombines("../jecsys3/rootfiles/"+version+"Iita_20230824_jetveto/jmenano_data_out_2022C_JME_v1.root");
  DijetHistosCombines("../jecsys3/rootfiles/"+version+"Iita_20230824_jetveto/jmenano_data_out_2022D_JME_v1.root");
  DijetHistosCombines("../jecsys3/rootfiles/"+version+"Iita_20230824_jetveto/jmenano_data_out_2022E_JME_v1.root");
  DijetHistosCombines("../jecsys3/rootfiles/"+version+"Iita_20230824_jetveto/jmenano_data_out_2022F_JME_v1.root");
  DijetHistosCombines("../jecsys3/rootfiles/"+version+"Iita_20230824_jetveto/jmenano_data_out_2022G_JME_v1.root");
  // 2023
  DijetHistosCombines("../jecsys3/rootfiles/"+version+"Iita_20230824_jetveto/nano_data_out_2023B_JME_v1.root");
  DijetHistosCombines("../jecsys3/rootfiles/"+version+"Iita_20230824_jetveto/nano_data_out_2023Cv123_JME_v1.root");
  DijetHistosCombines("../jecsys3/rootfiles/"+version+"Iita_20230824_jetveto/nano_data_out_2023BCv123_JME_v1.root");
  DijetHistosCombines("../jecsys3/rootfiles/"+version+"Iita_20230824_jetveto/nano_data_out_2023Cv4_JME_v1.root");
  */
  //DijetHistosCombines("../jecsys3/rootfiles/"+version+"Iita_20230824_jetveto/nano_data_out_2023D_JME_v1.root");
  //DijetHistosCombines("../jecsys3/rootfiles/"+version+"Iita_20230824_jetveto/jmenano_mc_out_Summer22_v1.root");
  //DijetHistosCombines("../jecsys3/rootfiles/"+version+"Iita_20230824_jetveto/jmenano_mc_out_Summer22EE_v1.root");
  // Main combos (after checking stability for L2Res)
  //DijetHistosCombines("../jecsys3/rootfiles/"+version+"Iita_20230824_jetveto/jmenano_data_out_2022CD_JME_v1.root");
  //DijetHistosCombines("../jecsys3/rootfiles/"+version+"Iita_20230824_jetveto/jmenano_data_out_2022FG_JME_v1.root");
  //DijetHistosCombines("../jecsys3/rootfiles/"+version+"Iita_20230824_jetveto/jmenano_data_out_2022EFG_JME_v1.root");
  //DijetHistosCombines("../jecsys3/rootfiles/"+version+"Iita_20230824_jetveto/nano_data_out_2023Cv4D_JME_v1.root");
  //DijetHistosCombines("../jecsys3/rootfiles/"+version+"Iita_20230824_jetveto/nano_data_out_2022BCv123_JME_v1.root");
  //
  //DijetHistosCombines("../jecsys3/rootfiles/"+version+"Iita_20230824_jetveto/jmenano_data_out_2223_JME_v1.root");
  //DijetHistosCombines("../jecsys3/rootfiles/"+version+"Iita_20230824_jetveto/jmenano_mc_out_Summer22Both_v1.root");

} // DijetHistosCombine

void DijetHistosCombines(string file) {

  cout << "DijetHistosCombines(\"" << file << "\")" << endl;
  TDirectory *curdir = gDirectory;

  // Open input and output files
  TFile *fin = new TFile(file.c_str(),"READ");
  assert(fin && !fin->IsZombie());

  TString t = file.c_str();
  t.ReplaceAll("_out","_cmb");
  string file2 = t.Data();
  assert(file2!=file);
  cout << "                 => \"" << file2 << endl;

  TFile *fout = new TFile(file2.c_str(),"RECREATE");
  assert(fout && !fout->IsZombie());


  // Retrieve listing of available triggers from input file
  TH1D *htrg = (TH1D*)fin->Get("htrg");
  assert(htrg);

  // Enter first folder and prepare folders+histograms for output file
  fin->cd(htrg->GetXaxis()->GetBinLabel(1));
  //fin->cd("HLT_PFJet450");
  TDirectory *dir = gDirectory;
  if (debug>0) cout << "Initialize with " << dir->GetName() << endl << flush;
  loopOverDirectories(dir,fout,"none","");

  // Then copy stuff over
  for (int i = 1; i != htrg->GetNbinsX()+1; ++i) {

    string trg = htrg->GetXaxis()->GetBinLabel(i);
    fin->cd(trg.c_str());
    dir = gDirectory;
    if (debug>0) cout << "Process " << trg << " in "
		      << dir->GetName() << endl << flush;
    loopOverDirectories(dir,fout,trg.c_str(),"");
  }

  //mergeDijet(fin, fout);

  fout->Write();
} // DijetHistosCombines


void loopOverDirectories(TDirectory *dir, TDirectory *outdir,
			 string trg, string folder) {

  TIter next(dir->GetListOfKeys());
  while (TKey *key = (TKey*)next()) {

    // Recurse directory structure
    if (string(key->GetClassName())=="TDirectoryFile") {
      if (debug>1) cout << key->GetName() << "->";
      TDirectory *subdir = (TDirectory*)key->ReadObj();

      if (!outdir->FindObject(subdir->GetName()))
	outdir->mkdir(subdir->GetName());
      outdir->cd(subdir->GetName());
      TDirectory *suboutdir = gDirectory;

      loopOverDirectories(subdir, suboutdir,
			  trg=="" ? key->GetName() : trg,
			  trg=="" ? "" : (folder=="" ? key->GetName():folder));
    }
    // Create histograms, if not yet there
    else {

      TObject *obj = key->ReadObj();

      if (obj->InheritsFrom("TProfile2D")) {
	TProfile2D *p2 = (TProfile2D*)obj;

	/*
	// Collapse to TH2D until can figure out how to copy bins of TProfile2D
	// This unfortunately makes rebinning later trickier
	TH2D *h2o = (TH2D*)outdir->FindObject(key->GetName());
	if (!h2o) {
	  outdir->cd();
	  h2o = p2->ProjectionXY(key->GetName());
	  h2o->Reset();
	}

	for (int binx = 1; binx != p2->GetNbinsX()+1; ++binx) {
	  for (int biny = 1; biny != p2->GetNbinsY()+1; ++biny) {
	    int ibin = p2->GetBin(binx, biny);
	    if (copyBin(trg, folder, key->GetName(),
			h2o->GetYaxis()->GetBinCenter(biny),
			h2o->GetXaxis()->GetBinCenter(binx))) {
	      if (folder=="Jetveto") {
		h2o->SetBinContent(ibin, h2o->GetBinContent(ibin)+
				   p2->GetBinContent(ibin));
		h2o->SetBinError(ibin, sqrt(pow(h2o->GetBinError(ibin),2)+
					    pow(p2->GetBinError(ibin),2)));
	      }
	      else {
		assert(h2o->GetBinContent(ibin)==0);
		h2o->SetBinContent(ibin, p2->GetBinContent(ibin));
		h2o->SetBinError(ibin, p2->GetBinError(ibin));
	      }
	    }
	  } // for biny
	} // for biny
	*/

	TProfile2D *p2o = (TProfile2D*)outdir->FindObject(key->GetName());
	if (!p2o) {
	  outdir->cd();
	  p2o = (TProfile2D*)p2->Clone(key->GetName());
	  p2o->Reset();
	}

	// profile keeps track of sumw, sumwz, sumwz2, sumw2
	// sumw=fArray, sumwz=fBinEntries.fArray,
	// sumwz2 = fBinSumw2.fArray, sumw2 = fSum2.fArray

	// GetBinContent = sumwz/sumw

	// https://root-forum.cern.ch/t/copy-entries-of-tprofile/11828
	for (int binx = 1; binx != p2->GetNbinsX()+1; ++binx) {
	  for (int biny = 1; biny != p2->GetNbinsY()+1; ++biny) {
	    int ibin = p2->GetBin(binx, biny);
	    if (copyBin(trg, folder, key->GetName(),
			p2o->GetYaxis()->GetBinCenter(biny),
			p2o->GetXaxis()->GetBinCenter(binx))) {
	      if (folder=="Jetveto") {

		p2o->SetEntries(p2o->GetEntries()+p2->GetEntries());
		(*p2o)[ibin] = (*p2)[ibin] + (*p2o)[ibin];
		(*p2o->GetSumw2())[ibin] = (*p2->GetSumw2())[ibin] +
		  (*p2o->GetSumw2())[ibin];
		p2o->SetBinEntries(ibin, p2->GetBinEntries(ibin) +
				   p2o->GetBinEntries(ibin));
		// copy (if needed) bin sum of weight square
		if ( p2->GetBinSumw2()->fN > ibin ) {
		  //p2o->Sumw2();
		  (*p2o->GetBinSumw2())[ibin] = (*p2->GetBinSumw2())[ibin] +
		    (*p2o->GetBinSumw2())[ibin];
		}
	      }	// Jetveto
	      else {
		p2o->SetEntries(p2o->GetEntries()+p2->GetEntries());
		(*p2o)[ibin] = (*p2)[ibin]; // copy bin y values
		(*p2o->GetSumw2())[ibin] = (*p2->GetSumw2())[ibin]; // copy y*y
		p2o->SetBinEntries(ibin, p2->GetBinEntries(ibin));  // entries
		// copy (if needed) bin sum of weight square
		if ( p2->GetBinSumw2()->fN > ibin ) {
		  //p2o->Sumw2();
		  (*p2o->GetBinSumw2())[ibin] = (*p2->GetBinSumw2())[ibin];
		}
	      } // !Jetveto
	    } // copyBin
	  } // for biny
	} // for biny

      } // TProfile2D
      else if (obj->InheritsFrom("TH2D")) {
	TH2D *h2 = (TH2D*)obj;
	TH2D *h2o = (TH2D*)outdir->FindObject(key->GetName());
	if (!h2o) {
	  outdir->cd();
	  h2o = (TH2D*)h2->Clone(key->GetName());
	  h2o->Reset();
	}
	for (int binx = 1; binx != h2->GetNbinsX()+1; ++binx) {
	  for (int biny = 1; biny != h2->GetNbinsY()+1; ++biny) {
	    int ibin = h2->GetBin(binx, biny);
	    string hist = key->GetName();
	    double cpBin =
	      ((folder=="Multijet" && (hist=="h2recoila"||hist=="h2recoilm"||
				       hist=="h2recoill" ||hist=="h2recoilr")) ?
	       copyBin(trg, folder, key->GetName(),
		       h2o->GetXaxis()->GetBinCenter(binx), 0.) :
	       copyBin(trg, folder, key->GetName(),
		       h2o->GetYaxis()->GetBinCenter(biny),
		       h2o->GetXaxis()->GetBinCenter(binx)));
	    if (cpBin) {
	      if (folder=="Jetveto") {
		h2o->SetBinContent(ibin, h2o->GetBinContent(ibin)+
				   h2->GetBinContent(ibin));
		h2o->SetBinError(ibin, sqrt(pow(h2o->GetBinError(ibin),2)+
					    pow(h2->GetBinError(ibin),2)));
	      }
	      else {
		h2o->SetBinContent(ibin, h2->GetBinContent(ibin));
		h2o->SetBinError(ibin, h2->GetBinError(ibin));
	      }
	    }
	  } // for biny
	} // for binx
      } // TH2D
      else if (obj->InheritsFrom("TProfile")) {
	TProfile *p = (TProfile*)obj;

	TProfile *po = (TProfile*)outdir->FindObject(key->GetName());
	if (!po) {
	  outdir->cd();
	  po = (TProfile*)p->Clone(key->GetName());
	  po->Reset();
	}

	// https://root-forum.cern.ch/t/copy-entries-of-tprofile/11828
	for (int ibin = 1; ibin != p->GetNbinsX()+1; ++ibin) {
	  if (copyBin(trg, folder, key->GetName(),
		      po->GetBinCenter(ibin),0.)) {
	    (*po)[ibin] = (*p)[ibin]; // copy bin y values
	    (*po->GetSumw2())[ibin] = (*p->GetSumw2())[ibin]; // copy bin y*y
	    po->SetBinEntries(ibin, p->GetBinEntries(ibin));  // copy entries
	    // copy (if needed) bin sum of weight square
	    if ( p->GetBinSumw2()->fN > ibin ) {
	      //po->Sumw2(); // already copied when cloning
	      (*po->GetBinSumw2())[ibin] = (*p->GetBinSumw2())[ibin];
	    }
	  }
	} // for ibin
      } // TProfile
      else if (obj->InheritsFrom("TH1D")) {
	TH1D *h = (TH1D*)obj;
	TH1D *ho = (TH1D*)outdir->FindObject(key->GetName());
	if (!ho) {
	  outdir->cd();
	  ho = (TH1D*)h->Clone(key->GetName());
	  ho->Reset();
	}
	for (int ibin = 1; ibin != h->GetNbinsX()+1; ++ibin) {
	  int ieta(0);
	  if (folder=="Incjet") sscanf(key->GetName(),"hpt%d",&ieta);
	  if (copyBin(trg, folder, key->GetName(),
		      ho->GetBinCenter(ibin),0.1*ieta)) {
	    ho->SetBinContent(ibin, h->GetBinContent(ibin));
	    ho->SetBinError(ibin, h->GetBinError(ibin));
	  }
	} // for ibin
      } // TH1D

      if (debug>2) cout << endl << "  " << key->GetName();
    }
  }
  if (debug>1) cout << endl;
} // loopOverDirectories

struct range {
  int ptmin;
  int ptmax;
  double absetamin;
  double absetamax;
};
std::map<std::string, struct range> md;
std::map<std::string, struct range> md2;
std::map<std::string, struct range> md2tc;
std::map<std::string, struct range> md2pf;
std::map<std::string, struct range> mj;
std::map<std::string, struct range> mi;

bool copyBin(string trg, string folder, string hist, double pt, double eta) {

  //cout << "trg:"<<trg<<" folder:"<<folder<<" hist:"<<hist
  //   << " pt:"<<pt<<" eta:"<<eta<<endl;

  // Setup triggers only once
  if (md.find("HLT_ZeroBias")==md.end()) {

    double fwdeta = 3.139; // was 2.853. 80% (100%) on negative (positive) side
    double fwdeta0 = 2.964;//2.853; // 40 and 260 up
    double fwdetad = 2.853;

    // Dijet thresholds
    md["HLT_ZeroBias"]      = range{15,  40,  0, 5.2};
    md["HLT_MC"]            = range{15,6500,  0, 5.2};

    md["HLT_DiPFJetAve40"]  = range{40,  85,  0, 5.2};
    md["HLT_DiPFJetAve60"]  = range{85,  100, 0, fwdeta};
    md["HLT_DiPFJetAve80"]  = range{100, 155, 0, fwdeta};
    md["HLT_DiPFJetAve140"] = range{155, 250, 0, fwdeta};
    md["HLT_DiPFJetAve200"] = range{250, 300, 0, fwdeta0}; // 210->250
    md["HLT_DiPFJetAve260"] = range{300, 400, 0, fwdeta0};
    md["HLT_DiPFJetAve320"] = range{400, 500, 0, fwdeta0};
    md["HLT_DiPFJetAve400"] = range{500, 600, 0, fwdeta0};
    md["HLT_DiPFJetAve500"] = range{600,3000, 0, fwdeta0};

    md["HLT_DiPFJetAve60_HFJEC"]  = range{85,  100, fwdeta, 5.2};
    md["HLT_DiPFJetAve80_HFJEC"]  = range{100, 125, fwdeta, 5.2};
    md["HLT_DiPFJetAve100_HFJEC"] = range{125, 180, fwdeta, 5.2};
    md["HLT_DiPFJetAve160_HFJEC"] = range{180, 250, fwdeta, 5.2};
    md["HLT_DiPFJetAve220_HFJEC"] = range{250, 350, fwdeta0, 5.2};
    md["HLT_DiPFJetAve300_HFJEC"] = range{350,3000, fwdeta0, 5.2};

    // https://indico.cern.ch/event/1263476/contributions/5311425/attachments/2612023/4513129/L2Res+HDM-March15.pdf
    md2["HLT_ZeroBias"]      = range{15,  59,  0, 5.2};
    md2["HLT_MC"]            = range{15,6500,  0, 5.2};

    md2["HLT_DiPFJetAve40"]  = range{59,  86,  0, 5.2};
    md2["HLT_DiPFJetAve60"]  = range{86,  110, 0, fwdetad};
    md2["HLT_DiPFJetAve80"]  = range{110, 170, 0, fwdetad};
    md2["HLT_DiPFJetAve140"] = range{170, 236, 0, fwdetad};
    md2["HLT_DiPFJetAve200"] = range{236, 302, 0, fwdetad};
    md2["HLT_DiPFJetAve260"] = range{302, 373, 0, fwdetad};
    md2["HLT_DiPFJetAve320"] = range{373, 460, 0, fwdetad};
    md2["HLT_DiPFJetAve400"] = range{460, 575, 0, fwdetad};
    md2["HLT_DiPFJetAve500"] = range{575,6500, 0, fwdetad};

    md2["HLT_DiPFJetAve60_HFJEC"]  = range{86,  110, fwdetad, 5.2};
    md2["HLT_DiPFJetAve80_HFJEC"]  = range{110, 132, fwdetad, 5.2};
    md2["HLT_DiPFJetAve100_HFJEC"] = range{132, 204, fwdetad, 5.2};
    md2["HLT_DiPFJetAve160_HFJEC"] = range{204, 279, fwdetad, 5.2};
    md2["HLT_DiPFJetAve220_HFJEC"] = range{279, 373, fwdetad, 5.2};
    md2["HLT_DiPFJetAve300_HFJEC"] = range{373,3000, fwdetad, 5.2};

    md2pf["HLT_ZeroBias"] = range{15,  59,  0, 5.2};
    md2pf["HLT_MC"]       = range{15,6500,  0, 5.2};
    md2pf["HLT_PFJet40"]  = range{59,  86,  0, 5.2};
    md2pf["HLT_PFJet60"]  = range{86,  110, 0, 5.2};//fwdetad};
    md2pf["HLT_PFJet80"]  = range{110, 170, 0, 5.2};//fwdetad};
    md2pf["HLT_PFJet140"] = range{170, 236, 0, 5.2};//fwdetad};
    md2pf["HLT_PFJet200"] = range{236, 302, 0, 5.2};//fwdetad};
    md2pf["HLT_PFJet260"] = range{302, 373, 0, 5.2};//fwdetad};
    md2pf["HLT_PFJet320"] = range{373, 460, 0, 5.2};//fwdetad};
    md2pf["HLT_PFJet400"] = range{460, 575, 0, 5.2};//fwdetad};
    md2pf["HLT_PFJet500"] = range{575,6500, 0, 5.2};//fwdetad};

    md2tc["HLT_ZeroBias"] = range{15,  59,  0, 5.2};
    md2tc["HLT_MC"]       = range{15,6500,  0, 5.2};
    md2tc["HLT_PFJet40"]  = range{59,  86,  0, 5.2};
    md2tc["HLT_PFJet60"]  = range{86,  110, 0, 5.2};//fwdetad};
    md2tc["HLT_PFJet80"]  = range{110, 170, 0, 5.2};//fwdetad};
    md2tc["HLT_PFJet140"] = range{170, 236, 0, 5.2};//fwdetad};
    md2tc["HLT_PFJet200"] = range{236, 302, 0, 5.2};//fwdetad};
    md2tc["HLT_PFJet260"] = range{302, 373, 0, 5.2};//fwdetad};
    md2tc["HLT_PFJet320"] = range{373, 460, 0, 5.2};//fwdetad};
    md2tc["HLT_PFJet400"] = range{460, 575, 0, 5.2};//fwdetad};
    md2tc["HLT_PFJet500"] = range{575,6500, 0, 5.2};//fwdetad};

    // Multijet or dijet tag/probe thresholds
    mj["HLT_PFJet40"]  = range{40,  85,  0, fwdeta0};
    mj["HLT_PFJet60"]  = range{85,  100, 0, fwdeta};
    mj["HLT_PFJet80"]  = range{100, 155, 0, fwdeta};
    mj["HLT_PFJet140"] = range{155, 210, 0, fwdeta};
    mj["HLT_PFJet200"] = range{210, 300, 0, fwdeta0};
    mj["HLT_PFJet260"] = range{300, 400, 0, fwdeta0};
    mj["HLT_PFJet320"] = range{400, 500, 0, fwdeta0};
    mj["HLT_PFJet400"] = range{500, 600, 0, fwdeta0};
    mj["HLT_PFJet450"] = range{500, 600, 0, fwdeta0};
    mj["HLT_PFJet500"] = range{600,3000, 0, fwdeta0};
    //mj["HLT_PFJet500"] = range{600, 700, 0, fwdeta0};
    //mj["HLT_PFJet550"] = range{700,3000, 0, fwdeta0};

    mj["HLT_PFJetFwd40"]  = range{40,  85,  fwdeta0, 5.2};
    mj["HLT_PFJetFwd60"]  = range{85,  100, fwdeta, 5.2};
    mj["HLT_PFJetFwd80"]  = range{100, 155, fwdeta, 5.2};
    mj["HLT_PFJetFwd140"] = range{155, 210, fwdeta, 5.2};
    mj["HLT_PFJetFwd200"] = range{210, 300, fwdeta0, 5.2};
    mj["HLT_PFJetFwd260"] = range{300, 400, fwdeta0, 5.2};
    mj["HLT_PFJetFwd320"] = range{400, 500, fwdeta0, 5.2};
    mj["HLT_PFJetFwd400"] = range{500, 600, fwdeta0, 5.2};
    mj["HLT_PFJetFwd450"] = range{500, 600, fwdeta0, 5.2};
    mj["HLT_PFJetFwd500"] = range{600,3000, fwdeta0, 5.2};

    mi["HLT_ZeroBias"] = range{10,  49,  0, 5.2};
    mi["HLT_MC"]       = range{15,6500,  0, 5.2};
    /*
    mi["HLT_PFJet40"]  = range{49,  84,  0, 5.2};
    mi["HLT_PFJet60"]  = range{84,  114, 0, 5.2};
    mi["HLT_PFJet80"]  = range{114, 196, 0, 5.2};
    mi["HLT_PFJet140"] = range{196, 272, 0, 5.2};
    mi["HLT_PFJet200"] = range{272, 330, 0, 5.2};
    mi["HLT_PFJet260"] = range{330, 395, 0, 5.2};
    mi["HLT_PFJet320"] = range{395, 468, 0, 5.2};
    mi["HLT_PFJet400"] = range{468, 548, 0, 5.2};
    mi["HLT_PFJet450"] = range{548, 686, 0, 5.2};
    mi["HLT_PFJet500"] = range{686,6500, 0, 5.2};
    */

    mi["HLT_PFJet40"]  = range{49,  84,  0, fwdeta0};
    mi["HLT_PFJet60"]  = range{84,  114, 0, fwdeta};
    mi["HLT_PFJet80"]  = range{114, 196, 0, fwdeta};
    mi["HLT_PFJet140"] = range{196, 272, 0, fwdeta};
    mi["HLT_PFJet200"] = range{272, 330, 0, fwdeta0};
    mi["HLT_PFJet260"] = range{330, 395, 0, fwdeta0};
    mi["HLT_PFJet320"] = range{395, 468, 0, fwdeta0};
    mi["HLT_PFJet400"] = range{468, 548, 0, fwdeta0};
    mi["HLT_PFJet450"] = range{548, 686, 0, fwdeta0};
    mi["HLT_PFJet500"] = range{686,6500, 0, fwdeta0};
    //mi["HLT_PFJet550"] = range{700,3000, 0, fwdeta0};

    mi["HLT_PFJetFwd40"]  = range{49,  84,  fwdeta0, 5.2};
    mi["HLT_PFJetFwd60"]  = range{84,  114, fwdeta, 5.2};
    mi["HLT_PFJetFwd80"]  = range{114, 196, fwdeta, 5.2};
    mi["HLT_PFJetFwd140"] = range{196, 272, fwdeta, 5.2};
    mi["HLT_PFJetFwd200"] = range{272, 330, fwdeta0, 5.2};
    mi["HLT_PFJetFwd260"] = range{330, 395, fwdeta0, 5.2};
    mi["HLT_PFJetFwd320"] = range{395, 468, fwdeta0, 5.2};
    mi["HLT_PFJetFwd400"] = range{468, 548, fwdeta0, 5.2};
    mi["HLT_PFJetFwd450"] = range{548, 686, fwdeta0, 5.2};
    mi["HLT_PFJetFwd500"] = range{686,6500, fwdeta0, 5.2};
  }

  bool tcHist = (folder=="Dijet2" && (hist=="h2ptetatc" || hist=="p2restc" ||
				      hist=="p2m0tc" || hist=="p2m2tc" ||
				      hist=="p2mntc" || hist=="p2mutc"));
  bool pfHist = (folder=="Dijet2" && (hist=="h2ptetapf" || hist=="p2respf" ||
				      hist=="p2m0pf" || hist=="p2m2pf" ||
				      hist=="p2mnpf" || hist=="p2mupf"));

  if (folder=="Jetveto" && (hist=="p2chf" || hist=="p2nhf" || hist=="p2nef" ||
			    hist=="p2asymm" || hist=="h2phieta" ||
			    hist=="h2phieta_ave"))
    return true;
  if (folder=="Jetveto" &&
      mi.find(trg)!=mi.end() &&
      pt >= mi[trg].ptmin && pt < mi[trg].ptmax &&
      fabs(eta) >= mi[trg].absetamin && fabs(eta) < mi[trg].absetamax)
    return true;
  if (folder=="Incjet" &&
      mi.find(trg)!=mi.end() &&
      pt >= mi[trg].ptmin && pt < mi[trg].ptmax &&
      fabs(eta) >= mi[trg].absetamin && fabs(eta) < mi[trg].absetamax)
    return true;
  if (folder=="Dijet" &&
      md.find(trg)!=md.end() &&
      pt >= md[trg].ptmin && pt < md[trg].ptmax &&
      fabs(eta) >= md[trg].absetamin && fabs(eta) < md[trg].absetamax)
    return true;
  if (folder=="Dijet2") {

    if (tcHist) { // pT,tag binning
      if (md2tc.find(trg)!=md2tc.end() &&
	  pt >= md2tc[trg].ptmin && pt < md2tc[trg].ptmax &&
	  fabs(eta) >= md2tc[trg].absetamin && fabs(eta) < md2tc[trg].absetamax)
	return true;
    }
    else if (pfHist) { // pT,probe binning
      if (md2pf.find(trg)!=md2pf.end() &&
	  pt >= md2pf[trg].ptmin && pt < md2pf[trg].ptmax &&
	  fabs(eta) >= md2pf[trg].absetamin && fabs(eta) < md2pf[trg].absetamax)
	return true;
    }
    else { // pT,AVP or pT,ave binning
      if (md2.find(trg)!=md2.end() &&
	  pt >= md2[trg].ptmin && pt < md2[trg].ptmax &&
	  fabs(eta) >= md2[trg].absetamin && fabs(eta) < md2[trg].absetamax)
	return true;
    }
  } // Dijet2
  // 20% higher thresholds for multijet recoil binning
  if (folder=="Multijet") {
    double k(1);
    if (hist=="hptr_all" || hist=="hptr_sel" || hist=="presr" ||
	hist=="pcrecoilr" || hist=="pm0r" || hist=="pm2r" ||
	hist=="pmnr" || hist=="pmur") k = 1.15;
    if (mi.find(trg)!=mi.end() &&
	pt >= k*mi[trg].ptmin && pt < k*mi[trg].ptmax &&
	fabs(eta) >= mi[trg].absetamin && fabs(eta) < mi[trg].absetamax)
    return true;
  }

  // else
  return false;
   //if (trg=="HLT_PFJet450" && pt>500 && pt<6500 && fabs(eta)<3.0) return true;
}
