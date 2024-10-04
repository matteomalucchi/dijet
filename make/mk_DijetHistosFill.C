// Purpose: Fill dijet analysis histograms
// Author:  mikko.voutilainen@cern.ch
// Created: June 6, 2021

// #include "../CondFormats/JetMETObjects/src/Utilities.cc"
#include "../CondFormats/JetMETObjects/interface/JetCorrectorParameters.h"
#include "../CondFormats/JetMETObjects/interface/SimpleJetCorrector.h"
#include "../CondFormats/JetMETObjects/interface/FactorizedJetCorrector.h"

#include "../CondFormats/JetMETObjects/interface/SimpleJetCorrectionUncertainty.h"
#include "../CondFormats/JetMETObjects/interface/JetCorrectionUncertainty.h"

#include "../CondFormats/JetMETObjects/interface/JetResolutionObject.h"
#include "../JetMETCorrections/Modules/interface/JetResolution.h"

#include "../interface/DijetHistosFill.h"

#include "TSystem.h"

#include <fstream>
#include <string>
#include <iostream>
#include <stdlib.h>

#include <unistd.h>

// For hostname
# include <limits.h>

char hostname[_POSIX_HOST_NAME_MAX];

#include <unordered_set>

// #define GPU
// #define LOCAL

#ifdef LOCAL
// Compile these libraries into *.so first with root -l -b -q mk_CondFormats.C
// (works for 6.18.04?)
/*
R__LOAD_LIBRARY(CondFormats/JetMETObjects/src/JetCorrectorParameters.cc+)
R__LOAD_LIBRARY(CondFormats/JetMETObjects/src/SimpleJetCorrector.cc+)
R__LOAD_LIBRARY(CondFormats/JetMETObjects/src/FactorizedJetCorrector.cc+)

R__LOAD_LIBRARY(CondFormats/JetMETObjects/src/SimpleJetCorrectionUncertainty.cc+)
R__LOAD_LIBRARY(CondFormats/JetMETObjects/src/JetCorrectionUncertainty.cc+)
*/
//R__LOAD_LIBRARY(DijetHistosFill.C+g)
// As in jetphys/mk2_histosFill.C:
R__LOAD_LIBRARY(CondFormats/JetMETObjects/src/JetCorrectorParameters_cc)
R__LOAD_LIBRARY(CondFormats/JetMETObjects/src/SimpleJetCorrector_cc)
R__LOAD_LIBRARY(CondFormats/JetMETObjects/src/FactorizedJetCorrector_cc)

R__LOAD_LIBRARY(CondFormats/JetMETObjects/src/SimpleJetCorrectionUncertainty_cc)
R__LOAD_LIBRARY(CondFormats/JetMETObjects/src/JetCorrectionUncertainty_cc)
//
R__LOAD_LIBRARY(CondFormats/JetMETObjects/src/JetResolutionObject_cc)
R__LOAD_LIBRARY(JetMETCorrections/Modules/src/JetResolution_cc)
//
R__LOAD_LIBRARY(src/DijetHistosFill_C)
#else
// (works for 6.26/10)
R__LOAD_LIBRARY(src/DijetHistosFill_C.so)
#endif

void mk_DijetHistosFill(string dataset = "X", string version = "vX", int nFilesMax = 9999) {

  // Get JMENANO from either location:
  // - lxplus:/eos/cms/store/group/phys_jetmet/JMENanoRun3/v2p1/JetMET
  // - Hefaistos:/media/DATA/JME_NANO_DATA

  // Datasets, these can be taken out of the code and put in a file etc.
  std::unordered_set<std::string> MC_datasets = {"UL2016APVMG",
     "UL2016MG", "UL2016Flat",
     "UL2017MG", "UL2018MG",
     "Summer22Flat", "Summer22MG",
     "Summer22MG1", "Summer22MG2",
     "Summer22EEFlat", "Summer22EEMG",
     "Summer22EEMG1", "Summer22EEMG2",
     "Summer22EEMG3", "Summer22EEMG4",
     "Summer23MG_1", "Summer23MG_2", "Summer23MG_3", "Summer23MG_4","Summer23MG_5","Summer23MG_6", "Summer23MG",
     "Summer23MGBPix_1", "Summer23MGBPix_2", "Summer23MGBPix_3", "Summer23MGBPix_4", "Summer23MGBPix",
     "Summer23MG_test", "Summer23MGBPix_test",
     "Summer23MG_new_1", "Summer23MG_new_2", "Summer23MG_new_3", "Summer23MG_new_4"
     };

  std::unordered_set<std::string> DT_datasets = {"UL2016BCD",
  "UL2016EF", "UL2016GH", "UL2017B", "UL2017C", "UL2017D",
  "UL2017E", "UL2017F", "UL2018A", "UL2018B", "UL2018C",
  "UL2018D1", "UL2018D2", "UL2016BCD_ZB", "UL2016EF_ZB",
  "UL2016GH_ZB", "UL2017B_ZB", "UL2017C_ZB", "UL2017D_ZB",
  "UL2017E_ZB", "UL2017F_ZB", "UL2018A_ZB", "UL2018B_ZB",
  "UL2018C_ZB", "UL2018D_ZB", "2022C", "2022D", "2022E",
  "2022F", "2022G", "2022F1", "2022F2", "2023BCv123", "2023B", "2023Cv123", "2023Cv123_ZB","2023Cv4",
  "2023D", "2022C_ZB", "2022D_ZB", "2022E_ZB", "2022F_ZB", "2022G_ZB",
  "2023BCv123_ZB", "2023Cv4_ZB", "2023D_ZB"
  };

  // Check if dataset is supported
  if (DT_datasets.find(dataset)==DT_datasets.end() &&
      MC_datasets.find(dataset)==MC_datasets.end() &&
      TString(dataset.c_str()).Contains("Summer2")==false){
    cout << "Dataset " << dataset << " not supported" << endl << flush;
    cout << "Supported datasets are:" << endl;
    for (auto it=DT_datasets.begin(); it!=DT_datasets.end(); ++it) {
      cout << *it << endl;
    }
    for (auto it=MC_datasets.begin(); it!=MC_datasets.end(); ++it) {
      cout << *it << endl;
    }

  } else{
    cout << "Dataset " << dataset << " is supported" << endl << flush;
  }


  // Settings
  // Check if dataset is data or MC
  bool addData = (DT_datasets.find(dataset)!=DT_datasets.end());
  bool addMC = (MC_datasets.find(dataset)!=MC_datasets.end()) || TString(dataset.c_str()).Contains("Summer2");

  // Maybe also
  // assert(addData || addMC);

  //cout << "Clean old shared objects and link files" << endl << flush;
  //gSystem->Exec("rm *.d");
  //gSystem->Exec("rm *.so");
  //gSystem->Exec("rm *.pcm");

  string path = gSystem->pwd();

  gSystem->AddIncludePath(Form("-I%s",path.c_str()));
  gSystem->AddIncludePath(Form("-I%s/CondFormats/JetMETObjects/interface",path.c_str()));

#ifdef GPU
  // Compile these libraries into *.so first with root -l -b -q mk_CondFormats.C
  // Compile .cc files in CondFormats/JetMETObjects/src
  std::set<std::string> files = {"Utilities.cc", "JetCorrectorParameters.cc", "SimpleJetCorrector.cc", "FactorizedJetCorrector.cc",
  "SimpleJetCorrectionUncertainty.cc", "JetCorrectionUncertainty.cc", "JetResolutionObject.cc"};

  for (auto it=files.begin(); it!=files.end(); ++it) {
    gROOT->ProcessLine(Form(".L CondFormats/JetMETObjects/src/%s+",it->c_str()));
  }

  // Also JetResolution.cc from JetMETCorrections
  gROOT->ProcessLine(".L JetMETCorrections/Modules/src/JetResolution.cc+");

  cout << "Load library in GPU mode" << endl << flush;
  gROOT->ProcessLine(".L src/DijetHistosFill.C+g");
#endif

  TChain *c = new TChain("Events");

  // Automatically figure out where we are running the job
  // runGPU if hostname is dx6-flafo-02 (Hefaistos)
  gethostname(hostname, _POSIX_HOST_NAME_MAX);

  bool runGPU = (hostname==string("dx6-flafo-02"));
  bool runLocal = (path=="/Users/voutila/Dropbox/Cern/dijet" ||
		   path=="/Users/manvouti/Dropbox/Cern/dijet"); // is this necessary? Always running in the dijet folder anyway?
  if (!runLocal) assert(runGPU);

  if (addData) {
    ifstream fin(runLocal ? Form("input_files/dataFiles_local_%s.txt",dataset.c_str()) :
		 Form("input_files/dataFiles_%s.txt",dataset.c_str()), ios::in);
    string filename;
    cout << "Chaining data files:" << endl << flush;
    int nFiles(0);
    while (fin >> filename && nFiles<nFilesMax) {
      ++nFiles;
      c->AddFile(filename.c_str());
    }
    cout << "Chained " << nFiles <<  " files" << endl << flush;

    // bool isZB = (dataset=="UL2017B_ZB" || dataset=="UL2017C_ZB" || dataset=="UL2017D_ZB" ||
    //		 dataset=="UL2017E_ZB" || dataset=="UL2017F_ZB");
    // => decide internally from dataset.Contains("_ZB")

    DijetHistosFill filler(c,0,dataset,version);
    filler.Loop();
  }

  if (addMC) {
    ifstream fin(runLocal ? Form("input_files/mcFiles_local_%s.txt",dataset.c_str()) :
		 Form("input_files/mcFiles_%s.txt",dataset.c_str()), ios::in);
    string filename;
    cout << "Chaining MC files:" << endl << flush;
    int nFiles(0);
    while (fin >> filename && nFiles<nFilesMax) {
      ++nFiles;
      c->AddFile(filename.c_str());
    }
    cout << "Chained " << nFiles <<  " files" << endl << flush;

    bool isMG = (dataset.find("MG") != std::string::npos); //(dataset=="UL2016APVMG" || dataset=="UL2016MG" ||
		 // dataset=="UL2017MG" || dataset=="UL2018MG" ||
		 // dataset=="Summer22MG" ||
		 // dataset=="Summer22MG1" || dataset=="Summer22MG2" ||
		 // dataset=="Summer22EEMG" ||
		 // dataset=="Summer22EEMG1" || dataset=="Summer22EEMG2" ||
		 // dataset=="Summer22EEMG3" || dataset=="Summer22EEMG4");

    DijetHistosFill filler(c, isMG ? 2 : 1, dataset,version);
    filler.Loop();
  }

  std::cout << "Done" << std::endl;

}
