#include "CondFormats/JetMETObjects/interface/JetIdHelper.h"
#include <cmath>
#include <TString.h>
#include <iostream>

// Internal storage for computed jetId values
//static std::vector<int> Jet_jetId_internal;
static std::vector<UChar_t> Jet_jetId_internal;

bool JetId_PassTight(float Jet_eta, float Jet_neHEF, float Jet_neEmEF, float Jet_chHEF, uint8_t Jet_chMultiplicity, uint8_t Jet_neMultiplicity){
    bool passTight = false;

    if (fabs(Jet_eta) <= 2.6){
        passTight  = Jet_neHEF < 0.99f;
        passTight &= Jet_neEmEF < 0.9f;
        passTight &= (Jet_chMultiplicity + Jet_neMultiplicity) > 1;
        passTight &= Jet_chHEF > 0.01f;
        passTight &= Jet_chMultiplicity > 0;
    }
    else if (fabs(Jet_eta) > 2.6 && fabs(Jet_eta) <= 2.7){
        passTight  = Jet_neHEF < 0.90f;
        passTight &= Jet_neEmEF < 0.99f;
    }
    else if (fabs(Jet_eta) > 2.7 && fabs(Jet_eta) <= 3.0){
        passTight = Jet_neHEF < 0.99f;
    }
    else if (fabs(Jet_eta) > 3.0){
        passTight  = Jet_neMultiplicity >= 2;
        passTight &= Jet_neEmEF < 0.4f;
    }

    return passTight;
}

bool JetId_PassTightLepVeto(float Jet_eta, float Jet_neHEF, float Jet_neEmEF, float Jet_chHEF, uint8_t Jet_chMultiplicity, uint8_t Jet_neMultiplicity, float Jet_muEF, float Jet_chEmEF){
    bool passTight = JetId_PassTight(Jet_eta, Jet_neHEF, Jet_neEmEF, Jet_chHEF, Jet_chMultiplicity, Jet_neMultiplicity);

    bool passTightLepVeto = false;
    if (fabs(Jet_eta) <= 2.7) {
        passTightLepVeto  = passTight;
        passTightLepVeto &= Jet_muEF < 0.8f;
        passTightLepVeto &= Jet_chEmEF < 0.8f;
    } else {
        passTightLepVeto = passTight;
    }

    return passTightLepVeto;
}

const std::vector<UChar_t>& InitJetId(
//const std::vector<int>& InitJetId(
    const std::string& dataset,
    int nJet,
    const Float_t Jet_eta[],
    const Float_t Jet_neHEF[],
    const Float_t Jet_neEmEF[],
    const Float_t Jet_chHEF[],
    const UChar_t Jet_chMultiplicity[], // (Puppi-weighted) Number of charged particles in the jet
    const UChar_t Jet_neMultiplicity[], // (Puppi-weighted) Number of neutral particles in the jet
    const Float_t Jet_muEF[],
    const Float_t Jet_chEmEF[],
    const UChar_t Jet_jetId[]
){
    bool isNanoAODv15 = (TString(dataset.c_str()).Contains("Winter25") || TString(dataset.c_str()).Contains("Summer24") || TString(dataset.c_str()).Contains("2024") || TString(dataset.c_str()).Contains("2025"));
    /* Check for different files.
    if (isNanoAODv15)
    {
      std::cout << "The file you're using is NANOODV15. Otherwise update this line" << std::endl;
    }
    */

    Jet_jetId_internal.clear();
    Jet_jetId_internal.reserve(nJet);

    if (isNanoAODv15) {
        for (int i = 0; i < nJet; ++i) {
            bool pass = JetId_PassTightLepVeto(
                Jet_eta[i],
                Jet_neHEF[i],
                Jet_neEmEF[i],
                Jet_chHEF[i],
                Jet_chMultiplicity[i],
                Jet_neMultiplicity[i],
                Jet_muEF[i],
                Jet_chEmEF[i]
            );

            Jet_jetId_internal.push_back(pass ? 6 : 0); // 6 for tightLepVeto?, 2 for tight. 
        }
    } else {
        for (int i = 0; i < nJet; ++i) {
            Jet_jetId_internal.push_back(Jet_jetId[i]);
        }
    }

    return Jet_jetId_internal;
}
