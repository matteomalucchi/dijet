// Run this script to compile CondFormats libraries. After this can easily run
// root -l -b -q mk_GamHistosFill.C
// using R__LOAD_LIBRARY to load *.so
{

  // For JEC
  gROOT->ProcessLine(".L CondFormats/JetMETObjects/src/Utilities.cc+");
  gROOT->ProcessLine(".L CondFormats/JetMETObjects/src/JetCorrectorParameters.cc+");
  gROOT->ProcessLine(".L CondFormats/JetMETObjects/src/SimpleJetCorrector.cc+");
  gROOT->ProcessLine(".L CondFormats/JetMETObjects/src/FactorizedJetCorrector.cc+");

  gROOT->ProcessLine(".L CondFormats/JetMETObjects/src/SimpleJetCorrectionUncertainty.cc+");
  gROOT->ProcessLine(".L CondFormats/JetMETObjects/src/JetCorrectionUncertainty.cc+");

  // For JER
  gROOT->ProcessLine(".L CondFormats/JetMETObjects/src/JetResolutionObject.cc+");
  gROOT->ProcessLine(".L JetMETCorrections/Modules/src/JetResolution.cc+");

  // For Dijet coded
  gROOT->ProcessLine(".L src/DijetHistosFill.C+g");
}
