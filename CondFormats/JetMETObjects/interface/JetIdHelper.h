#ifndef JETIDHELPER_H
#define JETIDHELPER_H

#include <vector>
#include <string>

const std::vector<UChar_t>& InitJetId(
    const std::string& dataset,
    int nJet,
    const Float_t Jet_eta[],
    const Float_t Jet_neHEF[],
    const Float_t Jet_neEmEF[],
    const Float_t Jet_chHEF[],
    const UChar_t Jet_chMultiplicity[],
    const UChar_t Jet_neMultiplicity[],
    const Float_t Jet_muEF[],
    const Float_t Jet_chEmEF[],
    const UChar_t Jet_jetId[] // From NanoAODv14; ignored if NanoAODv15
);

#endif // JETIDHELPER_H
