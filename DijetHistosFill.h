//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Thu Aug 18 13:39:49 2022 by ROOT version 6.26/02
// from TChain Events/
//////////////////////////////////////////////////////////

#ifndef DijetHistosFill_h
#define DijetHistosFill_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>


#include "../CondFormats/JetMETObjects/interface/FactorizedJetCorrector.h"
#include "../CondFormats/JetMETObjects/interface/JetCorrectorParameters.h"
#include "../CondFormats/JetMETObjects/interface/JetCorrectionUncertainty.h"

#include "../CondFormats/JetMETObjects/interface/JetResolutionObject.h"
#include "../JetMETCorrections/Modules/interface/JetResolution.h"

#include <iostream>
#include <cstdio>
#include <map>
#include <string>
using namespace std;

// Header file for the classes stored in the TTree if any.

class DijetHistosFill {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   int             isMC;     // data=0, PythiaPtFlat=1, MadGraphHT=2
   bool            isMG;     // isMC==2
   bool            isZB;
   int             isRun2;   // 2016apv=1, 2016gh=2, 2017=3, 2018=4
   bool            isRun3;
   string          dataset;
   string          version;
   static const bool _dh_debug = false;
   static const bool debugFiles = true;
   string          _filename; // file name for debugging purposes

   map<int, map<int, int> > _json;
   map<int, map<int, float> > _lums;
   map<int, map<int, float> > _lums2;
   map<int, map<int, float> > _avgpu;

   Bool_t HLT_MC = kTRUE;
   Bool_t Jet_jetveto[100];



// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   UInt_t          run;
   UInt_t          luminosityBlock;
   ULong64_t       event;
  //UInt_t          bunchCrossing;
   Float_t         HTXS_Higgs_pt;
   Float_t         HTXS_Higgs_y;
   Int_t           HTXS_stage1_1_cat_pTjet25GeV;
   Int_t           HTXS_stage1_1_cat_pTjet30GeV;
   Int_t           HTXS_stage1_1_fine_cat_pTjet25GeV;
   Int_t           HTXS_stage1_1_fine_cat_pTjet30GeV;
   Int_t           HTXS_stage1_2_cat_pTjet25GeV;
   Int_t           HTXS_stage1_2_cat_pTjet30GeV;
   Int_t           HTXS_stage1_2_fine_cat_pTjet25GeV;
   Int_t           HTXS_stage1_2_fine_cat_pTjet30GeV;
   Int_t           HTXS_stage_0;
   Int_t           HTXS_stage_1_pTjet25;
   Int_t           HTXS_stage_1_pTjet30;
   UChar_t         HTXS_njets25;
   UChar_t         HTXS_njets30;
  //Float_t         BeamSpot_sigmaZ;
  //Float_t         BeamSpot_sigmaZError;
  //Float_t         BeamSpot_z;
  //Float_t         BeamSpot_zError;
  //Char_t          BeamSpot_type;
  //Float_t         btagWeight_CSVV2;
  //Float_t         btagWeight_DeepCSVB;
   Float_t         CaloMET_phi;
   Float_t         CaloMET_pt;
   Float_t         CaloMET_sumEt;
   Float_t         ChsMET_phi;
   Float_t         ChsMET_pt;
   Float_t         ChsMET_sumEt;
   UInt_t          nCorrT1METJet;
   Float_t         CorrT1METJet_area[24];   //[nCorrT1METJet]
   Float_t         CorrT1METJet_eta[24];   //[nCorrT1METJet]
   Float_t         CorrT1METJet_muonSubtrFactor[24];   //[nCorrT1METJet]
   Float_t         CorrT1METJet_phi[24];   //[nCorrT1METJet]
   Float_t         CorrT1METJet_rawPt[24];   //[nCorrT1METJet]
   Float_t         DeepMETResolutionTune_phi;
   Float_t         DeepMETResolutionTune_pt;
   Float_t         DeepMETResponseTune_phi;
   Float_t         DeepMETResponseTune_pt;
   UInt_t          nElectron;
   Float_t         Electron_deltaEtaSC[7];   //[nElectron]
   Float_t         Electron_dr03EcalRecHitSumEt[7];   //[nElectron]
   Float_t         Electron_dr03HcalDepth1TowerSumEt[7];   //[nElectron]
   Float_t         Electron_dr03TkSumPt[7];   //[nElectron]
   Float_t         Electron_dr03TkSumPtHEEP[7];   //[nElectron]
   Float_t         Electron_dxy[7];   //[nElectron]
   Float_t         Electron_dxyErr[7];   //[nElectron]
   Float_t         Electron_dz[7];   //[nElectron]
   Float_t         Electron_dzErr[7];   //[nElectron]
   Float_t         Electron_eInvMinusPInv[7];   //[nElectron]
   Float_t         Electron_energyErr[7];   //[nElectron]
   Float_t         Electron_eta[7];   //[nElectron]
   Float_t         Electron_hoe[7];   //[nElectron]
   Float_t         Electron_ip3d[7];   //[nElectron]
   Float_t         Electron_jetPtRelv2[7];   //[nElectron]
   Float_t         Electron_jetRelIso[7];   //[nElectron]
   Float_t         Electron_mass[7];   //[nElectron]
   Float_t         Electron_miniPFRelIso_all[7];   //[nElectron]
   Float_t         Electron_miniPFRelIso_chg[7];   //[nElectron]
  //Float_t         Electron_mvaHZZIso[7];   //[nElectron]
  //Float_t         Electron_mvaIso[7];   //[nElectron]
  //Float_t         Electron_mvaNoIso[7];   //[nElectron]
   Float_t         Electron_pfRelIso03_all[7];   //[nElectron]
   Float_t         Electron_pfRelIso03_chg[7];   //[nElectron]
   Float_t         Electron_phi[7];   //[nElectron]
   Float_t         Electron_pt[7];   //[nElectron]
   Float_t         Electron_r9[7];   //[nElectron]
   Float_t         Electron_scEtOverPt[7];   //[nElectron]
   Float_t         Electron_sieie[7];   //[nElectron]
   Float_t         Electron_sip3d[7];   //[nElectron]
   Float_t         Electron_mvaTTH[7];   //[nElectron]
   Int_t           Electron_charge[7];   //[nElectron]
   Int_t           Electron_cutBased[7];   //[nElectron]
   Int_t           Electron_jetIdx[7];   //[nElectron]
   Int_t           Electron_pdgId[7];   //[nElectron]
   Int_t           Electron_photonIdx[7];   //[nElectron]
   Int_t           Electron_tightCharge[7];   //[nElectron]
   Int_t           Electron_vidNestedWPBitmap[7];   //[nElectron]
   Int_t           Electron_vidNestedWPBitmapHEEP[7];   //[nElectron]
   Int_t           Electron_fsrPhotonIdx[7];   //[nElectron]
   Bool_t          Electron_convVeto[7];   //[nElectron]
   Bool_t          Electron_cutBased_HEEP[7];   //[nElectron]
   Bool_t          Electron_isPFcand[7];   //[nElectron]
   UChar_t         Electron_jetNDauCharged[7];   //[nElectron]
   UChar_t         Electron_lostHits[7];   //[nElectron]
  //Bool_t          Electron_mvaIso_WP80[7];   //[nElectron]
  //Bool_t          Electron_mvaIso_WP90[7];   //[nElectron]
  //Bool_t          Electron_mvaIso_WPL[7];   //[nElectron]
  //Bool_t          Electron_mvaNoIso_WP80[7];   //[nElectron]
  //Bool_t          Electron_mvaNoIso_WP90[7];   //[nElectron]
  //Bool_t          Electron_mvaNoIso_WPL[7];   //[nElectron]
   UChar_t         Electron_seedGain[7];   //[nElectron]

   UInt_t          nFsrPhoton;
   Float_t         FsrPhoton_dROverEt2[5];   //[nFsrPhoton]
   Float_t         FsrPhoton_eta[5];   //[nFsrPhoton]
   Float_t         FsrPhoton_phi[5];   //[nFsrPhoton]
   Float_t         FsrPhoton_pt[5];   //[nFsrPhoton]
   Float_t         FsrPhoton_relIso03[5];   //[nFsrPhoton]
  //Int_t           FsrPhoton_electronIdx[5];   //[nFsrPhoton]
   Int_t           FsrPhoton_muonIdx[5];   //[nFsrPhoton]
   UInt_t          nGenJetAK8;
   Float_t         GenJetAK8_eta[9];   //[nGenJetAK8]
   Float_t         GenJetAK8_mass[9];   //[nGenJetAK8]
   Float_t         GenJetAK8_phi[9];   //[nGenJetAK8]
   Float_t         GenJetAK8_pt[9];   //[nGenJetAK8]
  //UChar_t         GenJetAK8_nConstituents[9];   //[nGenJetAK8]
  static const int nGenJetMax = 100; // was 76
   UInt_t          nGenJet;
   Float_t         GenJet_eta[nGenJetMax];   //[nGenJet]
   Float_t         GenJet_mass[nGenJetMax];   //[nGenJet]
   Float_t         GenJet_phi[nGenJetMax];   //[nGenJet]
   Float_t         GenJet_pt[nGenJetMax];   //[nGenJet]
  //UChar_t         GenJet_nConstituents[nGenJetMax];   //[nGenJet]
   UInt_t          nGenPart;
   Float_t         GenPart_eta[245];   //[nGenPart]
   Float_t         GenPart_mass[245];   //[nGenPart]
   Float_t         GenPart_phi[245];   //[nGenPart]
   Float_t         GenPart_pt[245];   //[nGenPart]
   Int_t           GenPart_genPartIdxMother[245];   //[nGenPart]
   Int_t           GenPart_pdgId[245];   //[nGenPart]
   Int_t           GenPart_status[245];   //[nGenPart]
   Int_t           GenPart_statusFlags[245];   //[nGenPart]
  //UInt_t          nGenProton;
  //Float_t         GenProton_px[13];   //[nGenProton]
  //Float_t         GenProton_py[13];   //[nGenProton]
  //Float_t         GenProton_pz[13];   //[nGenProton]
  //Float_t         GenProton_vz[13];   //[nGenProton]
  //Bool_t          GenProton_isPU[13];   //[nGenProton]
   UInt_t          nSubGenJetAK8;
   Float_t         SubGenJetAK8_eta[16];   //[nSubGenJetAK8]
   Float_t         SubGenJetAK8_mass[16];   //[nSubGenJetAK8]
   Float_t         SubGenJetAK8_phi[16];   //[nSubGenJetAK8]
   Float_t         SubGenJetAK8_pt[16];   //[nSubGenJetAK8]
   Float_t         Generator_binvar;
   Float_t         LHE_HT; // added by hand
   Float_t         Generator_scalePDF;
   Float_t         Generator_weight;
   Float_t         Generator_x1;
   Float_t         Generator_x2;
   Float_t         Generator_xpdf1;
   Float_t         Generator_xpdf2;
   Int_t           Generator_id1;
   Int_t           Generator_id2;
   Float_t         GenVtx_x;
   Float_t         GenVtx_y;
   Float_t         GenVtx_z;
   UInt_t          nGenVisTau;
   Float_t         GenVisTau_eta[2];   //[nGenVisTau]
   Float_t         GenVisTau_mass[2];   //[nGenVisTau]
   Float_t         GenVisTau_phi[2];   //[nGenVisTau]
   Float_t         GenVisTau_pt[2];   //[nGenVisTau]
   Int_t           GenVisTau_charge[2];   //[nGenVisTau]
   Int_t           GenVisTau_genPartIdxMother[2];   //[nGenVisTau]
   Int_t           GenVisTau_status[2];   //[nGenVisTau]
   Float_t         genWeight;
   UInt_t          nPSWeight;
   Float_t         PSWeight[44];   //[nPSWeight]
   UInt_t          nIsoTrack;
   Float_t         IsoTrack_dxy[38];   //[nIsoTrack]
   Float_t         IsoTrack_dz[38];   //[nIsoTrack]
   Float_t         IsoTrack_eta[38];   //[nIsoTrack]
   Float_t         IsoTrack_pfRelIso03_all[38];   //[nIsoTrack]
   Float_t         IsoTrack_pfRelIso03_chg[38];   //[nIsoTrack]
   Float_t         IsoTrack_phi[38];   //[nIsoTrack]
   Float_t         IsoTrack_pt[38];   //[nIsoTrack]
   Float_t         IsoTrack_miniPFRelIso_all[38];   //[nIsoTrack]
   Float_t         IsoTrack_miniPFRelIso_chg[38];   //[nIsoTrack]
   Int_t           IsoTrack_charge[38];   //[nIsoTrack]
   Int_t           IsoTrack_fromPV[38];   //[nIsoTrack]
   Int_t           IsoTrack_pdgId[38];   //[nIsoTrack]
   Bool_t          IsoTrack_isHighPurityTrack[38];   //[nIsoTrack]
   Bool_t          IsoTrack_isPFcand[38];   //[nIsoTrack]
   Bool_t          IsoTrack_isFromLostTrack[38];   //[nIsoTrack]

  //UInt_t          nGenJetAK8ForJEC;
  //Float_t         GenJetAK8ForJEC_eta[45];   //[nGenJetAK8ForJEC]
  //Float_t         GenJetAK8ForJEC_mass[45];   //[nGenJetAK8ForJEC]
  //Float_t         GenJetAK8ForJEC_phi[45];   //[nGenJetAK8ForJEC]
  //Float_t         GenJetAK8ForJEC_pt[45];   //[nGenJetAK8ForJEC]
  //UChar_t         GenJetAK8ForJEC_nConstituents[45];   //[nGenJetAK8ForJEC]

   static const int nJetMax = 100;
   UInt_t          nJet;
   Float_t         Jet_area[nJetMax];   //[nJet]
   //   Float_t         Jet_btagCSVV2[nJetMax];   //[nJet]
   //   Float_t         Jet_btagDeepB[nJetMax];   //[nJet]
   //   Float_t         Jet_btagDeepCvB[nJetMax];   //[nJet]
   //   Float_t         Jet_btagDeepCvL[nJetMax];   //[nJet]
   //   Float_t         Jet_btagDeepFlavB[nJetMax];   //[nJet]
   Float_t         Jet_btagDeepFlavCvB[nJetMax];   //[nJet]
   Float_t         Jet_btagDeepFlavCvL[nJetMax];   //[nJet]
   //   Float_t         Jet_btagDeepFlavG[nJetMax];   //[nJet]
   Float_t         Jet_btagDeepFlavQG[nJetMax];   //[nJet]
   //   Float_t         Jet_btagDeepFlavUDS[nJetMax];   //[nJet]
   Float_t         Jet_chEmEF[nJetMax];   //[nJet]
   Float_t         Jet_chHEF[nJetMax];   //[nJet]
   Float_t         Jet_eta[nJetMax];   //[nJet]
   //   Float_t         Jet_hfEmEF[nJetMax];   //[nJet]
   Float_t         Jet_hfHEF[nJetMax];   //[nJet]
   Float_t         Jet_hfsigmaEtaEta[nJetMax];   //[nJet]
   Float_t         Jet_hfsigmaPhiPhi[nJetMax];   //[nJet]
   Float_t         Jet_mass[nJetMax];   //[nJet]
   Float_t         Jet_muEF[nJetMax];   //[nJet]
   Float_t         Jet_muonSubtrFactor[nJetMax];   //[nJet]
   Float_t         Jet_neEmEF[nJetMax];   //[nJet]
   Float_t         Jet_neHEF[nJetMax];   //[nJet]
   //   Float_t         Jet_particleNetAK4_B[nJetMax];   //[nJet]
   //   Float_t         Jet_particleNetAK4_CvsB[nJetMax];   //[nJet]
   //   Float_t         Jet_particleNetAK4_CvsL[nJetMax];   //[nJet]
   //   Float_t         Jet_particleNetAK4_QvsG[nJetMax];   //[nJet]
   //   Float_t         Jet_particleNetAK4_puIdDisc[nJetMax];   //[nJet]
   Float_t         Jet_phi[nJetMax];   //[nJet]
   Float_t         Jet_pt[nJetMax];   //[nJet]
   //   Float_t         Jet_puId_beta[nJetMax];   //[nJet]
   //   Float_t         Jet_puId_dR2Mean[nJetMax];   //[nJet]
   //   Float_t         Jet_puId_frac01[nJetMax];   //[nJet]
   //   Float_t         Jet_puId_frac02[nJetMax];   //[nJet]
   //   Float_t         Jet_puId_frac03[nJetMax];   //[nJet]
   //   Float_t         Jet_puId_frac04[nJetMax];   //[nJet]
   //   Float_t         Jet_puId_jetR[nJetMax];   //[nJet]
   //   Float_t         Jet_puId_jetRchg[nJetMax];   //[nJet]
   //   Float_t         Jet_puId_majW[nJetMax];   //[nJet]
   //   Float_t         Jet_puId_minW[nJetMax];   //[nJet]
   //   Float_t         Jet_puId_ptD[nJetMax];   //[nJet]
   //   Float_t         Jet_puId_pull[nJetMax];   //[nJet]
   //   Float_t         Jet_qgl_axis2[nJetMax];   //[nJet]
   //   Float_t         Jet_qgl_ptD[nJetMax];   //[nJet]
   Float_t         Jet_rawFactor[nJetMax];   //[nJet]
   Float_t         PNetRegPtRawCorr[nJetMax];   //[nJet]
   Float_t         PNetRegPtRawCorrNeutrino[nJetMax];   //[nJet]
   Int_t           Jet_electronIdx1[nJetMax];   //[nJet]
   Int_t           Jet_electronIdx2[nJetMax];   //[nJet]
   Int_t           Jet_hfadjacentEtaStripsSize[nJetMax];   //[nJet]
   Int_t           Jet_hfcentralEtaStripSize[nJetMax];   //[nJet]
  // Int_t           Jet_jetId[nJetMax];   //[nJet] // NanoV10,11
   UChar_t         Jet_jetId[nJetMax];   //[nJet] // NanoV12
   Int_t           Jet_muonIdx1[nJetMax];   //[nJet]
   Int_t           Jet_muonIdx2[nJetMax];   //[nJet]
   Int_t           Jet_nConstChHads[nJetMax];   //[nJet]
   Int_t           Jet_nConstElecs[nJetMax];   //[nJet]
   Int_t           Jet_nConstHFEMs[nJetMax];   //[nJet]
   Int_t           Jet_nConstHFHads[nJetMax];   //[nJet]
   Int_t           Jet_nConstMuons[nJetMax];   //[nJet]
   Int_t           Jet_nConstNeuHads[nJetMax];   //[nJet]
   Int_t           Jet_nConstPhotons[nJetMax];   //[nJet]
   Int_t           Jet_nElectrons[nJetMax];   //[nJet]
   Int_t           Jet_nMuons[nJetMax];   //[nJet]
   //   Int_t           Jet_puId_nCharged[nJetMax];   //[nJet]
   //   Int_t           Jet_qgl_mult[nJetMax];   //[nJet]
   UChar_t         Jet_nConstituents[nJetMax];   //[nJet]
   UInt_t          nJetCHS;
   Float_t         JetCHS_area[88];   //[nJetCHS]
   Float_t         JetCHS_btagCSVV2[88];   //[nJetCHS]
   Float_t         JetCHS_btagDeepB[88];   //[nJetCHS]
   Float_t         JetCHS_btagDeepCvB[88];   //[nJetCHS]
   Float_t         JetCHS_btagDeepCvL[88];   //[nJetCHS]
   Float_t         JetCHS_btagDeepFlavB[88];   //[nJetCHS]
   Float_t         JetCHS_btagDeepFlavCvB[88];   //[nJetCHS]
   Float_t         JetCHS_btagDeepFlavCvL[88];   //[nJetCHS]
   Float_t         JetCHS_btagDeepFlavG[88];   //[nJetCHS]
   Float_t         JetCHS_btagDeepFlavQG[88];   //[nJetCHS]
   Float_t         JetCHS_btagDeepFlavUDS[88];   //[nJetCHS]
   Float_t         JetCHS_chEmEF[88];   //[nJetCHS]
   Float_t         JetCHS_chFPV0EF[88];   //[nJetCHS]
   Float_t         JetCHS_chFPV1EF[88];   //[nJetCHS]
   Float_t         JetCHS_chFPV2EF[88];   //[nJetCHS]
   Float_t         JetCHS_chFPV3EF[88];   //[nJetCHS]
   Float_t         JetCHS_chHEF[88];   //[nJetCHS]
   Float_t         JetCHS_eta[88];   //[nJetCHS]
   Float_t         JetCHS_hfEmEF[88];   //[nJetCHS]
   Float_t         JetCHS_hfHEF[88];   //[nJetCHS]
   Float_t         JetCHS_hfsigmaEtaEta[88];   //[nJetCHS]
   Float_t         JetCHS_hfsigmaPhiPhi[88];   //[nJetCHS]
   Float_t         JetCHS_mass[88];   //[nJetCHS]
   Float_t         JetCHS_muEF[88];   //[nJetCHS]
   Float_t         JetCHS_muonSubtrFactor[88];   //[nJetCHS]
   Float_t         JetCHS_neEmEF[88];   //[nJetCHS]
   Float_t         JetCHS_neHEF[88];   //[nJetCHS]
   Float_t         JetCHS_particleNetAK4_B[88];   //[nJetCHS]
   Float_t         JetCHS_particleNetAK4_CvsB[88];   //[nJetCHS]
   Float_t         JetCHS_particleNetAK4_CvsL[88];   //[nJetCHS]
   Float_t         JetCHS_particleNetAK4_QvsG[88];   //[nJetCHS]
   Float_t         JetCHS_particleNetAK4_puIdDisc[88];   //[nJetCHS]
   Float_t         JetCHS_phi[88];   //[nJetCHS]
   Float_t         JetCHS_pt[88];   //[nJetCHS]
   Float_t         JetCHS_puIdDisc[88];   //[nJetCHS]
   Float_t         JetCHS_puId_beta[88];   //[nJetCHS]
   Float_t         JetCHS_puId_dR2Mean[88];   //[nJetCHS]
   Float_t         JetCHS_puId_frac01[88];   //[nJetCHS]
   Float_t         JetCHS_puId_frac02[88];   //[nJetCHS]
   Float_t         JetCHS_puId_frac03[88];   //[nJetCHS]
   Float_t         JetCHS_puId_frac04[88];   //[nJetCHS]
   Float_t         JetCHS_puId_jetR[88];   //[nJetCHS]
   Float_t         JetCHS_puId_jetRchg[88];   //[nJetCHS]
   Float_t         JetCHS_puId_majW[88];   //[nJetCHS]
   Float_t         JetCHS_puId_minW[88];   //[nJetCHS]
   Float_t         JetCHS_puId_ptD[88];   //[nJetCHS]
   Float_t         JetCHS_puId_pull[88];   //[nJetCHS]
   Float_t         JetCHS_qgl[88];   //[nJetCHS]
   Float_t         JetCHS_qgl_axis2[88];   //[nJetCHS]
   Float_t         JetCHS_qgl_ptD[88];   //[nJetCHS]
   Float_t         JetCHS_rawFactor[88];   //[nJetCHS]
   Int_t           JetCHS_electronIdx1[88];   //[nJetCHS]
   Int_t           JetCHS_electronIdx2[88];   //[nJetCHS]
   Int_t           JetCHS_hfadjacentEtaStripsSize[88];   //[nJetCHS]
   Int_t           JetCHS_hfcentralEtaStripSize[88];   //[nJetCHS]
   Int_t           JetCHS_jetId[88];   //[nJetCHS]
   Int_t           JetCHS_muonIdx1[88];   //[nJetCHS]
   Int_t           JetCHS_muonIdx2[88];   //[nJetCHS]
   Int_t           JetCHS_nConstChHads[88];   //[nJetCHS]
   Int_t           JetCHS_nConstElecs[88];   //[nJetCHS]
   Int_t           JetCHS_nConstHFEMs[88];   //[nJetCHS]
   Int_t           JetCHS_nConstHFHads[88];   //[nJetCHS]
   Int_t           JetCHS_nConstMuons[88];   //[nJetCHS]
   Int_t           JetCHS_nConstNeuHads[88];   //[nJetCHS]
   Int_t           JetCHS_nConstPhotons[88];   //[nJetCHS]
   Int_t           JetCHS_nElectrons[88];   //[nJetCHS]
   Int_t           JetCHS_nMuons[88];   //[nJetCHS]
   Int_t           JetCHS_puId[88];   //[nJetCHS]
   Int_t           JetCHS_puId_nCharged[88];   //[nJetCHS]
   Int_t           JetCHS_qgl_mult[88];   //[nJetCHS]
   UChar_t         JetCHS_nConstituents[88];   //[nJetCHS]
   //   Float_t         L1PreFiringWeight_Dn;
   //   Float_t         L1PreFiringWeight_ECAL_Dn;
   //   Float_t         L1PreFiringWeight_ECAL_Nom;
   //   Float_t         L1PreFiringWeight_ECAL_Up;
   //   Float_t         L1PreFiringWeight_Muon_Nom;
   //   Float_t         L1PreFiringWeight_Muon_StatDn;
   //   Float_t         L1PreFiringWeight_Muon_StatUp;
   //   Float_t         L1PreFiringWeight_Muon_SystDn;
   //   Float_t         L1PreFiringWeight_Muon_SystUp;
   //   Float_t         L1PreFiringWeight_Nom;
   //   Float_t         L1PreFiringWeight_Up;
   UInt_t          nLowPtElectron;
   Float_t         LowPtElectron_ID[11];   //[nLowPtElectron]
   Float_t         LowPtElectron_convVtxRadius[11];   //[nLowPtElectron]
   Float_t         LowPtElectron_deltaEtaSC[11];   //[nLowPtElectron]
   Float_t         LowPtElectron_dxy[11];   //[nLowPtElectron]
   Float_t         LowPtElectron_dxyErr[11];   //[nLowPtElectron]
   Float_t         LowPtElectron_dz[11];   //[nLowPtElectron]
   Float_t         LowPtElectron_dzErr[11];   //[nLowPtElectron]
   Float_t         LowPtElectron_eInvMinusPInv[11];   //[nLowPtElectron]
   Float_t         LowPtElectron_energyErr[11];   //[nLowPtElectron]
   Float_t         LowPtElectron_eta[11];   //[nLowPtElectron]
   Float_t         LowPtElectron_hoe[11];   //[nLowPtElectron]
   Float_t         LowPtElectron_mass[11];   //[nLowPtElectron]
   Float_t         LowPtElectron_miniPFRelIso_all[11];   //[nLowPtElectron]
   Float_t         LowPtElectron_miniPFRelIso_chg[11];   //[nLowPtElectron]
   Float_t         LowPtElectron_phi[11];   //[nLowPtElectron]
   Float_t         LowPtElectron_pt[11];   //[nLowPtElectron]
   Float_t         LowPtElectron_ptbiased[11];   //[nLowPtElectron]
   Float_t         LowPtElectron_r9[11];   //[nLowPtElectron]
   Float_t         LowPtElectron_scEtOverPt[11];   //[nLowPtElectron]
   Float_t         LowPtElectron_sieie[11];   //[nLowPtElectron]
   Float_t         LowPtElectron_unbiased[11];   //[nLowPtElectron]
   Int_t           LowPtElectron_charge[11];   //[nLowPtElectron]
   Int_t           LowPtElectron_convWP[11];   //[nLowPtElectron]
  //Int_t           LowPtElectron_electronIdx[11];   //[nLowPtElectron]
   Int_t           LowPtElectron_pdgId[11];   //[nLowPtElectron]
   Bool_t          LowPtElectron_convVeto[11];   //[nLowPtElectron]
   UChar_t         LowPtElectron_lostHits[11];   //[nLowPtElectron]
   Float_t         GenMET_phi;
   Float_t         GenMET_pt;
   Float_t         MET_MetUnclustEnUpDeltaX;
   Float_t         MET_MetUnclustEnUpDeltaY;
   Float_t         MET_covXX;
   Float_t         MET_covXY;
   Float_t         MET_covYY;
   Float_t         MET_phi;
   Float_t         MET_pt;
   Float_t         MET_significance;
   Float_t         MET_sumEt;
   Float_t         MET_sumPtUnclustered;
   UInt_t          nMuon;
   Float_t         Muon_dxy[58];   //[nMuon]
   Float_t         Muon_dxyErr[58];   //[nMuon]
   Float_t         Muon_dxybs[58];   //[nMuon]
   Float_t         Muon_dz[58];   //[nMuon]
   Float_t         Muon_dzErr[58];   //[nMuon]
   Float_t         Muon_eta[58];   //[nMuon]
   Float_t         Muon_ip3d[58];   //[nMuon]
   Float_t         Muon_jetPtRelv2[58];   //[nMuon]
   Float_t         Muon_jetRelIso[58];   //[nMuon]
   Float_t         Muon_mass[58];   //[nMuon]
   Float_t         Muon_miniPFRelIso_all[58];   //[nMuon]
   Float_t         Muon_miniPFRelIso_chg[58];   //[nMuon]
   Float_t         Muon_pfRelIso03_all[58];   //[nMuon]
   Float_t         Muon_pfRelIso03_chg[58];   //[nMuon]
   Float_t         Muon_pfRelIso04_all[58];   //[nMuon]
   Float_t         Muon_phi[58];   //[nMuon]
   Float_t         Muon_pt[58];   //[nMuon]
   Float_t         Muon_ptErr[58];   //[nMuon]
   Float_t         Muon_segmentComp[58];   //[nMuon]
   Float_t         Muon_sip3d[58];   //[nMuon]
   Float_t         Muon_softMva[58];   //[nMuon]
   Float_t         Muon_tkRelIso[58];   //[nMuon]
   Float_t         Muon_tunepRelPt[58];   //[nMuon]
   Float_t         Muon_mvaLowPt[58];   //[nMuon]
   Float_t         Muon_mvaTTH[58];   //[nMuon]
   Int_t           Muon_charge[58];   //[nMuon]
   Int_t           Muon_jetIdx[58];   //[nMuon]
   Int_t           Muon_nStations[58];   //[nMuon]
   Int_t           Muon_nTrackerLayers[58];   //[nMuon]
   Int_t           Muon_pdgId[58];   //[nMuon]
   Int_t           Muon_tightCharge[58];   //[nMuon]
   Int_t           Muon_fsrPhotonIdx[58];   //[nMuon]
   UChar_t         Muon_highPtId[58];   //[nMuon]
   Bool_t          Muon_highPurity[58];   //[nMuon]
   Bool_t          Muon_inTimeMuon[58];   //[nMuon]
   Bool_t          Muon_isGlobal[58];   //[nMuon]
   Bool_t          Muon_isPFcand[58];   //[nMuon]
   Bool_t          Muon_isStandalone[58];   //[nMuon]
   Bool_t          Muon_isTracker[58];   //[nMuon]
   UChar_t         Muon_jetNDauCharged[58];   //[nMuon]
   Bool_t          Muon_looseId[58];   //[nMuon]
   Bool_t          Muon_mediumId[58];   //[nMuon]
   Bool_t          Muon_mediumPromptId[58];   //[nMuon]
   UChar_t         Muon_miniIsoId[58];   //[nMuon]
   UChar_t         Muon_multiIsoId[58];   //[nMuon]
   //   UChar_t         Muon_mvaId[58];   //[nMuon]
   //   UChar_t         Muon_mvaLowPtId[58];   //[nMuon]
   UChar_t         Muon_pfIsoId[58];   //[nMuon]
   UChar_t         Muon_puppiIsoId[58];   //[nMuon]
   Bool_t          Muon_softId[58];   //[nMuon]
   Bool_t          Muon_softMvaId[58];   //[nMuon]
   Bool_t          Muon_tightId[58];   //[nMuon]
   UChar_t         Muon_tkIsoId[58];   //[nMuon]
   Bool_t          Muon_triggerIdLoose[58];   //[nMuon]
   UInt_t          nPhoton;
   //   Float_t         Photon_dEscaleDown[8];   //[nPhoton]
   //   Float_t         Photon_dEscaleUp[8];   //[nPhoton]
   //   Float_t         Photon_dEsigmaDown[8];   //[nPhoton]
   //   Float_t         Photon_dEsigmaUp[8];   //[nPhoton]
   //   Float_t         Photon_eCorr[8];   //[nPhoton]
   Float_t         Photon_energyErr[8];   //[nPhoton]
  //Float_t         Photon_energyRaw[8];   //[nPhoton]
  //Float_t         Photon_esEffSigmaRR[8];   //[nPhoton]
  //Float_t         Photon_esEnergyOverRawE[8];   //[nPhoton]
   Float_t         Photon_eta[8];   //[nPhoton]
  //Float_t         Photon_etaWidth[8];   //[nPhoton]
  //Float_t         Photon_haloTaggerMVAVal[8];   //[nPhoton]
   Float_t         Photon_hoe[8];   //[nPhoton]
   Float_t         Photon_mvaID[8];   //[nPhoton]
  //Float_t         Photon_pfChargedIsoPFPV[8];   //[nPhoton]
  //Float_t         Photon_pfChargedIsoWorstVtx[8];   //[nPhoton]
  //Float_t         Photon_pfPhoIso03[8];   //[nPhoton]
   //   Float_t         Photon_pfRelIso03_all[8];   //[nPhoton]
   //   Float_t         Photon_pfRelIso03_chg[8];   //[nPhoton]
   Float_t         Photon_phi[8];   //[nPhoton]
  //Float_t         Photon_phiWidth[8];   //[nPhoton]
   Float_t         Photon_pt[8];   //[nPhoton]
   Float_t         Photon_r9[8];   //[nPhoton]
  //Float_t         Photon_s4[8];   //[nPhoton]
   Float_t         Photon_sieie[8];   //[nPhoton]
  //Float_t         Photon_sieip[8];   //[nPhoton]
  //Float_t         Photon_sipip[8];   //[nPhoton]
  //Float_t         Photon_x_calo[8];   //[nPhoton]
  //Float_t         Photon_y_calo[8];   //[nPhoton]
  //Float_t         Photon_z_calo[8];   //[nPhoton]
   Int_t           Photon_cutBased[8];   //[nPhoton]
   //   Int_t           Photon_cutBased_Fall17V1Bitmap[8];   //[nPhoton]
   Int_t           Photon_electronIdx[8];   //[nPhoton]
   Int_t           Photon_jetIdx[8];   //[nPhoton]
   Int_t           Photon_vidNestedWPBitmap[8];   //[nPhoton]
   Bool_t          Photon_electronVeto[8];   //[nPhoton]
   Bool_t          Photon_isScEtaEB[8];   //[nPhoton]
   Bool_t          Photon_isScEtaEE[8];   //[nPhoton]
   Bool_t          Photon_mvaID_WP80[8];   //[nPhoton]
   Bool_t          Photon_mvaID_WP90[8];   //[nPhoton]
   Bool_t          Photon_pixelSeed[8];   //[nPhoton]
   UChar_t         Photon_seedGain[8];   //[nPhoton]
   Float_t         Pileup_nTrueInt;
   Float_t         Pileup_pudensity;
   Float_t         Pileup_gpudensity;
   Float_t         Pileup_pthatmax;
   Int_t           Pileup_nPU;
   Int_t           Pileup_sumEOOT;
   Int_t           Pileup_sumLOOT;
   Float_t         PuppiMET_phi;
   Float_t         PuppiMET_phiJERDown;
   Float_t         PuppiMET_phiJERUp;
   Float_t         PuppiMET_phiJESDown;
   Float_t         PuppiMET_phiJESUp;
   Float_t         PuppiMET_phiUnclusteredDown;
   Float_t         PuppiMET_phiUnclusteredUp;
   Float_t         PuppiMET_pt;
   Float_t         PuppiMET_ptJERDown;
   Float_t         PuppiMET_ptJERUp;
   Float_t         PuppiMET_ptJESDown;
   Float_t         PuppiMET_ptJESUp;
   Float_t         PuppiMET_ptUnclusteredDown;
   Float_t         PuppiMET_ptUnclusteredUp;
   Float_t         PuppiMET_sumEt;
   Float_t         RawMET_phi;
   Float_t         RawMET_pt;
   Float_t         RawMET_sumEt;
   Float_t         RawPuppiMET_phi;
   Float_t         RawPuppiMET_pt;
   Float_t         RawPuppiMET_sumEt;
   Float_t         Rho_fixedGridRhoAll;
   Float_t         Rho_fixedGridRhoFastjetAll;
   Float_t         Rho_fixedGridRhoFastjetCentral;
   Float_t         Rho_fixedGridRhoFastjetCentralCalo;
   Float_t         Rho_fixedGridRhoFastjetCentralChargedPileUp;
   Float_t         Rho_fixedGridRhoFastjetCentralNeutral;
   UInt_t          nGenDressedLepton;
   Float_t         GenDressedLepton_eta[2];   //[nGenDressedLepton]
   Float_t         GenDressedLepton_mass[2];   //[nGenDressedLepton]
   Float_t         GenDressedLepton_phi[2];   //[nGenDressedLepton]
   Float_t         GenDressedLepton_pt[2];   //[nGenDressedLepton]
   Int_t           GenDressedLepton_pdgId[2];   //[nGenDressedLepton]
   Bool_t          GenDressedLepton_hasTauAnc[2];   //[nGenDressedLepton]
   UInt_t          nGenIsolatedPhoton;
   Float_t         GenIsolatedPhoton_eta[2];   //[nGenIsolatedPhoton]
   Float_t         GenIsolatedPhoton_mass[2];   //[nGenIsolatedPhoton]
   Float_t         GenIsolatedPhoton_phi[2];   //[nGenIsolatedPhoton]
   Float_t         GenIsolatedPhoton_pt[2];   //[nGenIsolatedPhoton]
   UInt_t          nSoftActivityJet;
   Float_t         SoftActivityJet_eta[6];   //[nSoftActivityJet]
   Float_t         SoftActivityJet_phi[6];   //[nSoftActivityJet]
   Float_t         SoftActivityJet_pt[6];   //[nSoftActivityJet]
   Float_t         SoftActivityJetHT;
   Float_t         SoftActivityJetHT10;
   Float_t         SoftActivityJetHT2;
   Float_t         SoftActivityJetHT5;
   Int_t           SoftActivityJetNjets10;
   Int_t           SoftActivityJetNjets2;
   Int_t           SoftActivityJetNjets5;
   UInt_t          nSubJet;
   //   Float_t         SubJet_btagCSVV2[16];   //[nSubJet]
   Float_t         SubJet_btagDeepB[16];   //[nSubJet]
   Float_t         SubJet_eta[16];   //[nSubJet]
   Float_t         SubJet_mass[16];   //[nSubJet]
   Float_t         SubJet_n2b1[16];   //[nSubJet]
   Float_t         SubJet_n3b1[16];   //[nSubJet]
   Float_t         SubJet_phi[16];   //[nSubJet]
   Float_t         SubJet_pt[16];   //[nSubJet]
   Float_t         SubJet_rawFactor[16];   //[nSubJet]
   Float_t         SubJet_tau1[16];   //[nSubJet]
   Float_t         SubJet_tau2[16];   //[nSubJet]
   Float_t         SubJet_tau3[16];   //[nSubJet]
   Float_t         SubJet_tau4[16];   //[nSubJet]
   UInt_t          nTau;
   Float_t         Tau_chargedIso[5];   //[nTau]
   Float_t         Tau_dxy[5];   //[nTau]
   Float_t         Tau_dz[5];   //[nTau]
   Float_t         Tau_eta[5];   //[nTau]
   Float_t         Tau_leadTkDeltaEta[5];   //[nTau]
   Float_t         Tau_leadTkDeltaPhi[5];   //[nTau]
   Float_t         Tau_leadTkPtOverTauPt[5];   //[nTau]
   Float_t         Tau_mass[5];   //[nTau]
   Float_t         Tau_neutralIso[5];   //[nTau]
   Float_t         Tau_phi[5];   //[nTau]
   Float_t         Tau_photonsOutsideSignalCone[5];   //[nTau]
   Float_t         Tau_pt[5];   //[nTau]
   Float_t         Tau_puCorr[5];   //[nTau]
  //Float_t         Tau_rawDeepTau2017v2p1VSe[5];   //[nTau]
  //Float_t         Tau_rawDeepTau2017v2p1VSjet[5];   //[nTau]
  //Float_t         Tau_rawDeepTau2017v2p1VSmu[5];   //[nTau]
  //Float_t         Tau_rawDeepTau2018v2p5VSe[5];   //[nTau]
  //Float_t         Tau_rawDeepTau2018v2p5VSjet[5];   //[nTau]
  //Float_t         Tau_rawDeepTau2018v2p5VSmu[5];   //[nTau]
   Float_t         Tau_rawIso[5];   //[nTau]
   Float_t         Tau_rawIsodR03[5];   //[nTau]
   Int_t           Tau_charge[5];   //[nTau]
   Int_t           Tau_decayMode[5];   //[nTau]
   Int_t           Tau_jetIdx[5];   //[nTau]
   Bool_t          Tau_idAntiEleDeadECal[5];   //[nTau]
   UChar_t         Tau_idAntiMu[5];   //[nTau]
   Bool_t          Tau_idDecayModeOldDMs[5];   //[nTau]
  //UChar_t         Tau_idDeepTau2017v2p1VSe[5];   //[nTau]
  //UChar_t         Tau_idDeepTau2017v2p1VSjet[5];   //[nTau]
  //UChar_t         Tau_idDeepTau2017v2p1VSmu[5];   //[nTau]
  //UChar_t         Tau_idDeepTau2018v2p5VSe[5];   //[nTau]
  //UChar_t         Tau_idDeepTau2018v2p5VSjet[5];   //[nTau]
  //UChar_t         Tau_idDeepTau2018v2p5VSmu[5];   //[nTau]
   Float_t         TkMET_phi;
   Float_t         TkMET_pt;
   Float_t         TkMET_sumEt;
   UInt_t          nTrigObjJMEAK4;
   Float_t         TrigObjJMEAK4_pt[nJetMax];   //[nTrigObjJMEAK4]
   Float_t         TrigObjJMEAK4_eta[nJetMax];   //[nTrigObjJMEAK4]
   Float_t         TrigObjJMEAK4_phi[nJetMax];   //[nTrigObjJMEAK4]
   Float_t         TrigObjJMEAK4_l1pt[nJetMax];   //[nTrigObjJMEAK4]
   Float_t         TrigObjJMEAK4_l1pt_2[nJetMax];   //[nTrigObjJMEAK4]
   Float_t         TrigObjJMEAK4_l2pt[nJetMax];   //[nTrigObjJMEAK4]
   Int_t           TrigObjJMEAK4_id[nJetMax];   //[nTrigObjJMEAK4]
   Int_t           TrigObjJMEAK4_l1iso[nJetMax];   //[nTrigObjJMEAK4]
   Int_t           TrigObjJMEAK4_l1charge[nJetMax];   //[nTrigObjJMEAK4]
   Int_t           TrigObjJMEAK4_filterBits[nJetMax];   //[nTrigObjJMEAK4]
   UInt_t          nTrigObjJMEAK8;
   Float_t         TrigObjJMEAK8_pt[nJetMax];   //[nTrigObjJMEAK8]
   Float_t         TrigObjJMEAK8_eta[nJetMax];   //[nTrigObjJMEAK8]
   Float_t         TrigObjJMEAK8_phi[nJetMax];   //[nTrigObjJMEAK8]
   Float_t         TrigObjJMEAK8_l1pt[nJetMax];   //[nTrigObjJMEAK8]
   Float_t         TrigObjJMEAK8_l1pt_2[nJetMax];   //[nTrigObjJMEAK8]
   Float_t         TrigObjJMEAK8_l2pt[nJetMax];   //[nTrigObjJMEAK8]
   Int_t           TrigObjJMEAK8_id[nJetMax];   //[nTrigObjJMEAK8]
   Int_t           TrigObjJMEAK8_l1iso[nJetMax];   //[nTrigObjJMEAK8]
   Int_t           TrigObjJMEAK8_l1charge[nJetMax];   //[nTrigObjJMEAK8]
   Int_t           TrigObjJMEAK8_filterBits[nJetMax];   //[nTrigObjJMEAK8]
   UInt_t          nTrigObj;
   Float_t         TrigObj_pt[68];   //[nTrigObj]
   Float_t         TrigObj_eta[68];   //[nTrigObj]
   Float_t         TrigObj_phi[68];   //[nTrigObj]
   Float_t         TrigObj_l1pt[68];   //[nTrigObj]
   Float_t         TrigObj_l1pt_2[68];   //[nTrigObj]
   Float_t         TrigObj_l2pt[68];   //[nTrigObj]
   Int_t           TrigObj_id[68];   //[nTrigObj]
   Int_t           TrigObj_l1iso[68];   //[nTrigObj]
   Int_t           TrigObj_l1charge[68];   //[nTrigObj]
   Int_t           TrigObj_filterBits[68];   //[nTrigObj]
   Int_t           genTtbarId;
   UInt_t          nOtherPV;
   Float_t         OtherPV_z[3];   //[nOtherPV]
  //Float_t         OtherPV_score[3];   //[nOtherPV]
   Float_t         PV_ndof;
   Float_t         PV_x;
   Float_t         PV_y;
   Float_t         PV_z;
   Float_t         PV_chi2;
   Float_t         PV_score;
   Int_t           PV_npvs;
   Int_t           PV_npvsGood;
   UInt_t          nSV;
   Float_t         SV_dlen[65];   //[nSV]
   Float_t         SV_dlenSig[65];   //[nSV]
   Float_t         SV_dxy[65];   //[nSV]
   Float_t         SV_dxySig[65];   //[nSV]
   Float_t         SV_pAngle[65];   //[nSV]
   Int_t           SV_charge[65];   //[nSV]
   Int_t           Electron_genPartIdx[7];   //[nElectron]
   UChar_t         Electron_genPartFlav[7];   //[nElectron]

   Int_t           GenJetAK8_partonFlavour[9];   //[nGenJetAK8]
   UChar_t         GenJetAK8_hadronFlavour[9];   //[nGenJetAK8]
  //Int_t           GenJetAK8ForJEC_partonFlavour[45];   //[nGenJetAK8ForJEC]
  //UChar_t         GenJetAK8ForJEC_hadronFlavour[45];   //[nGenJetAK8ForJEC]
  //Int_t           GenJet_partonFlavour[nGenJetMax];   //[nGenJet]
  //Int_t           GenJet_partonFlavour[nGenJetMax]; //[nGenJet] // NanoV10,11
   Short_t         GenJet_partonFlavour[nGenJetMax]; //[nGenJet] // NanoV12
   UChar_t         GenJet_hadronFlavour[nGenJetMax];   //[nGenJet]
   Float_t         GenVtx_t0;

   Int_t           JetCHS_genJetIdx[88];   //[nJetCHS]
   Int_t           JetCHS_hadronFlavour[88];   //[nJetCHS]
   Int_t           JetCHS_partonFlavour[88];   //[nJetCHS]

   Int_t           Jet_genJetIdx[nJetMax];   //[nJet]
  //Int_t           Jet_hadronFlavour[nJetMax];   //[nJet] // NanoV10,11
   UChar_t           Jet_hadronFlavour[nJetMax];   //[nJet] // NanoV12
  //Int_t           Jet_partonFlavour[nJetMax];   //[nJet] // NanoV10,11
   Short_t         Jet_partonFlavour[nJetMax]; //[nJet] // NanoV12
   Int_t           LowPtElectron_genPartIdx[11];   //[nLowPtElectron]
   UChar_t         LowPtElectron_genPartFlav[11];   //[nLowPtElectron]
   Int_t           Muon_genPartIdx[58];   //[nMuon]
   UChar_t         Muon_genPartFlav[58];   //[nMuon]
   Int_t           Photon_genPartIdx[8];   //[nPhoton]
   UChar_t         Photon_genPartFlav[8];   //[nPhoton]
   Float_t         MET_fiducialGenPhi;
   Float_t         MET_fiducialGenPt;
   //   UChar_t         Electron_cleanmask[7];   //[nElectron]
   //   UChar_t         Jet_cleanmask[nJetMax];   //[nJet]
  //UChar_t         LowPtElectron_cleanmask[11];   //[nLowPtElectron]
   //   UChar_t         Muon_cleanmask[58];   //[nMuon]
   //   UChar_t         Photon_cleanmask[8];   //[nPhoton]
   //   UChar_t         Tau_cleanmask[5];   //[nTau]
   Int_t           SubJet_hadronFlavour[16];   //[nSubJet]
   UChar_t         SubJet_nBHadrons[16];   //[nSubJet]
   UChar_t         SubJet_nCHadrons[16];   //[nSubJet]
   Float_t         SV_chi2[65];   //[nSV]
   Float_t         SV_eta[65];   //[nSV]
   Float_t         SV_mass[65];   //[nSV]
   Float_t         SV_ndof[65];   //[nSV]
   Float_t         SV_phi[65];   //[nSV]
   Float_t         SV_pt[65];   //[nSV]
   Float_t         SV_x[65];   //[nSV]
   Float_t         SV_y[65];   //[nSV]
   Float_t         SV_z[65];   //[nSV]
   UChar_t         SV_ntracks[65];   //[nSV]
   Int_t           Tau_genPartIdx[5];   //[nTau]
   UChar_t         Tau_genPartFlav[5];   //[nTau]
   Bool_t          L1_AlwaysTrue;
   Bool_t          L1_BPTX_AND_Ref1_VME;
   Bool_t          L1_BPTX_AND_Ref3_VME;
   Bool_t          L1_BPTX_AND_Ref4_VME;
   Bool_t          L1_BPTX_BeamGas_B1_VME;
   Bool_t          L1_BPTX_BeamGas_B2_VME;
   Bool_t          L1_BPTX_BeamGas_Ref1_VME;
   Bool_t          L1_BPTX_BeamGas_Ref2_VME;
   Bool_t          L1_BPTX_NotOR_VME;
   Bool_t          L1_BPTX_OR_Ref3_VME;
   Bool_t          L1_BPTX_OR_Ref4_VME;
   Bool_t          L1_BPTX_RefAND_VME;
   Bool_t          L1_BptxMinus;
   Bool_t          L1_BptxOR;
   Bool_t          L1_BptxPlus;
   Bool_t          L1_BptxXOR;
   Bool_t          L1_CDC_SingleMu_3_er1p2_TOP120_DPHI2p618_3p142;
   Bool_t          L1_DoubleEG8er2p5_HTT260er;
   Bool_t          L1_DoubleEG8er2p5_HTT280er;
   Bool_t          L1_DoubleEG8er2p5_HTT300er;
   Bool_t          L1_DoubleEG8er2p5_HTT320er;
   Bool_t          L1_DoubleEG8er2p5_HTT340er;
   Bool_t          L1_DoubleEG_15_10_er2p5;
   Bool_t          L1_DoubleEG_20_10_er2p5;
   Bool_t          L1_DoubleEG_22_10_er2p5;
   Bool_t          L1_DoubleEG_25_12_er2p5;
   Bool_t          L1_DoubleEG_25_14_er2p5;
   Bool_t          L1_DoubleEG_27_14_er2p5;
   Bool_t          L1_DoubleEG_LooseIso20_10_er2p5;
   Bool_t          L1_DoubleEG_LooseIso22_10_er2p5;
   Bool_t          L1_DoubleEG_LooseIso22_12_er2p5;
   Bool_t          L1_DoubleEG_LooseIso25_12_er2p5;
   Bool_t          L1_DoubleIsoTau28er2p1;
   Bool_t          L1_DoubleIsoTau28er2p1_Mass_Max80;
   Bool_t          L1_DoubleIsoTau28er2p1_Mass_Max90;
   Bool_t          L1_DoubleIsoTau30er2p1;
   Bool_t          L1_DoubleIsoTau30er2p1_Mass_Max80;
   Bool_t          L1_DoubleIsoTau30er2p1_Mass_Max90;
   Bool_t          L1_DoubleIsoTau32er2p1;
   Bool_t          L1_DoubleIsoTau34er2p1;
   Bool_t          L1_DoubleIsoTau36er2p1;
   Bool_t          L1_DoubleJet100er2p3_dEta_Max1p6;
   Bool_t          L1_DoubleJet100er2p5;
   Bool_t          L1_DoubleJet112er2p3_dEta_Max1p6;
   Bool_t          L1_DoubleJet120er2p5;
   Bool_t          L1_DoubleJet150er2p5;
   Bool_t          L1_DoubleJet30er2p5_Mass_Min150_dEta_Max1p5;
   Bool_t          L1_DoubleJet30er2p5_Mass_Min200_dEta_Max1p5;
   Bool_t          L1_DoubleJet30er2p5_Mass_Min250_dEta_Max1p5;
   Bool_t          L1_DoubleJet30er2p5_Mass_Min300_dEta_Max1p5;
   Bool_t          L1_DoubleJet30er2p5_Mass_Min330_dEta_Max1p5;
   Bool_t          L1_DoubleJet30er2p5_Mass_Min360_dEta_Max1p5;
   Bool_t          L1_DoubleJet35_Mass_Min450_IsoTau45_RmOvlp;
   Bool_t          L1_DoubleJet40er2p5;
   Bool_t          L1_DoubleJet_100_30_DoubleJet30_Mass_Min620;
   Bool_t          L1_DoubleJet_110_35_DoubleJet35_Mass_Min620;
   Bool_t          L1_DoubleJet_115_40_DoubleJet40_Mass_Min620;
   Bool_t          L1_DoubleJet_115_40_DoubleJet40_Mass_Min620_Jet60TT28;
   Bool_t          L1_DoubleJet_120_45_DoubleJet45_Mass_Min620;
   Bool_t          L1_DoubleJet_120_45_DoubleJet45_Mass_Min620_Jet60TT28;
   Bool_t          L1_DoubleJet_80_30_Mass_Min420_DoubleMu0_SQ;
   Bool_t          L1_DoubleJet_80_30_Mass_Min420_IsoTau40_RmOvlp;
   Bool_t          L1_DoubleJet_80_30_Mass_Min420_Mu8;
   Bool_t          L1_DoubleJet_90_30_DoubleJet30_Mass_Min620;
   Bool_t          L1_DoubleLooseIsoEG22er2p1;
   Bool_t          L1_DoubleLooseIsoEG24er2p1;
   Bool_t          L1_DoubleMu0;
   Bool_t          L1_DoubleMu0_Mass_Min1;
   Bool_t          L1_DoubleMu0_OQ;
   Bool_t          L1_DoubleMu0_SQ;
   Bool_t          L1_DoubleMu0_SQ_OS;
   Bool_t          L1_DoubleMu0_dR_Max1p6_Jet90er2p5_dR_Max0p8;
   Bool_t          L1_DoubleMu0er1p4_SQ_OS_dR_Max1p4;
   Bool_t          L1_DoubleMu0er1p5_SQ;
   Bool_t          L1_DoubleMu0er1p5_SQ_OS;
   Bool_t          L1_DoubleMu0er1p5_SQ_OS_dR_Max1p4;
   Bool_t          L1_DoubleMu0er1p5_SQ_dR_Max1p4;
   Bool_t          L1_DoubleMu0er2p0_SQ_OS_dR_Max1p4;
   Bool_t          L1_DoubleMu0er2p0_SQ_dR_Max1p4;
   Bool_t          L1_DoubleMu18er2p1;
   Bool_t          L1_DoubleMu3_OS_DoubleEG7p5Upsilon;
   Bool_t          L1_DoubleMu3_SQ_ETMHF50_HTT60er;
   Bool_t          L1_DoubleMu3_SQ_ETMHF50_Jet60er2p5;
   Bool_t          L1_DoubleMu3_SQ_ETMHF50_Jet60er2p5_OR_DoubleJet40er2p5;
   Bool_t          L1_DoubleMu3_SQ_ETMHF60_Jet60er2p5;
   Bool_t          L1_DoubleMu3_SQ_HTT220er;
   Bool_t          L1_DoubleMu3_SQ_HTT240er;
   Bool_t          L1_DoubleMu3_SQ_HTT260er;
   Bool_t          L1_DoubleMu3_dR_Max1p6_Jet90er2p5_dR_Max0p8;
   Bool_t          L1_DoubleMu4_SQ_EG9er2p5;
   Bool_t          L1_DoubleMu4_SQ_OS;
   Bool_t          L1_DoubleMu4_SQ_OS_dR_Max1p2;
   Bool_t          L1_DoubleMu4p5_SQ_OS;
   Bool_t          L1_DoubleMu4p5_SQ_OS_dR_Max1p2;
   Bool_t          L1_DoubleMu4p5er2p0_SQ_OS;
   Bool_t          L1_DoubleMu4p5er2p0_SQ_OS_Mass7to18;
   Bool_t          L1_DoubleMu4p5er2p0_SQ_OS_Mass_Min7;
   Bool_t          L1_DoubleMu5Upsilon_OS_DoubleEG3;
   Bool_t          L1_DoubleMu5_SQ_EG9er2p5;
   Bool_t          L1_DoubleMu8_SQ;
   Bool_t          L1_DoubleMu9_SQ;
   Bool_t          L1_DoubleMu_12_5;
   Bool_t          L1_DoubleMu_15_5_SQ;
   Bool_t          L1_DoubleMu_15_7;
   Bool_t          L1_DoubleMu_15_7_Mass_Min1;
   Bool_t          L1_DoubleMu_15_7_SQ;
   Bool_t          L1_DoubleTau70er2p1;
   Bool_t          L1_ETM120;
   Bool_t          L1_ETM150;
   Bool_t          L1_ETMHF100;
   Bool_t          L1_ETMHF100_HTT60er;
   Bool_t          L1_ETMHF110;
   Bool_t          L1_ETMHF110_HTT60er;
   Bool_t          L1_ETMHF110_HTT60er_NotSecondBunchInTrain;
   Bool_t          L1_ETMHF120;
   Bool_t          L1_ETMHF120_HTT60er;
   Bool_t          L1_ETMHF120_NotSecondBunchInTrain;
   Bool_t          L1_ETMHF130;
   Bool_t          L1_ETMHF130_HTT60er;
   Bool_t          L1_ETMHF140;
   Bool_t          L1_ETMHF150;
   Bool_t          L1_ETMHF90_HTT60er;
   Bool_t          L1_ETT1200;
   Bool_t          L1_ETT1600;
   Bool_t          L1_ETT2000;
   Bool_t          L1_FirstBunchAfterTrain;
   Bool_t          L1_FirstBunchBeforeTrain;
   Bool_t          L1_FirstBunchInTrain;
   Bool_t          L1_FirstCollisionInOrbit;
   Bool_t          L1_FirstCollisionInTrain;
   Bool_t          L1_HCAL_LaserMon_Trig;
   Bool_t          L1_HCAL_LaserMon_Veto;
   Bool_t          L1_HTT120er;
   Bool_t          L1_HTT160er;
   Bool_t          L1_HTT200er;
   Bool_t          L1_HTT255er;
   Bool_t          L1_HTT280er;
   Bool_t          L1_HTT280er_QuadJet_70_55_40_35_er2p4;
   Bool_t          L1_HTT320er;
   Bool_t          L1_HTT320er_QuadJet_70_55_40_40_er2p4;
   Bool_t          L1_HTT320er_QuadJet_80_60_er2p1_45_40_er2p3;
   Bool_t          L1_HTT320er_QuadJet_80_60_er2p1_50_45_er2p3;
   Bool_t          L1_HTT360er;
   Bool_t          L1_HTT400er;
   Bool_t          L1_HTT450er;
   Bool_t          L1_IsoEG32er2p5_Mt40;
   Bool_t          L1_IsoEG32er2p5_Mt44;
   Bool_t          L1_IsoEG32er2p5_Mt48;
   Bool_t          L1_IsoTau40er2p1_ETMHF100;
   Bool_t          L1_IsoTau40er2p1_ETMHF110;
   Bool_t          L1_IsoTau40er2p1_ETMHF80;
   Bool_t          L1_IsoTau40er2p1_ETMHF90;
   Bool_t          L1_IsolatedBunch;
   Bool_t          L1_LastBunchInTrain;
   Bool_t          L1_LastCollisionInTrain;
   Bool_t          L1_LooseIsoEG22er2p1_IsoTau26er2p1_dR_Min0p3;
   Bool_t          L1_LooseIsoEG22er2p1_Tau70er2p1_dR_Min0p3;
   Bool_t          L1_LooseIsoEG24er2p1_HTT100er;
   Bool_t          L1_LooseIsoEG24er2p1_IsoTau27er2p1_dR_Min0p3;
   Bool_t          L1_LooseIsoEG26er2p1_HTT100er;
   Bool_t          L1_LooseIsoEG26er2p1_Jet34er2p5_dR_Min0p3;
   Bool_t          L1_LooseIsoEG28er2p1_HTT100er;
   Bool_t          L1_LooseIsoEG28er2p1_Jet34er2p5_dR_Min0p3;
   Bool_t          L1_LooseIsoEG30er2p1_HTT100er;
   Bool_t          L1_LooseIsoEG30er2p1_Jet34er2p5_dR_Min0p3;
   Bool_t          L1_MinimumBiasHF0_AND_BptxAND;
   Bool_t          L1_Mu10er2p3_Jet32er2p3_dR_Max0p4_DoubleJet32er2p3_dEta_Max1p6;
   Bool_t          L1_Mu12er2p3_Jet40er2p1_dR_Max0p4_DoubleJet40er2p1_dEta_Max1p6;
   Bool_t          L1_Mu12er2p3_Jet40er2p3_dR_Max0p4_DoubleJet40er2p3_dEta_Max1p6;
   Bool_t          L1_Mu18er2p1_Tau24er2p1;
   Bool_t          L1_Mu18er2p1_Tau26er2p1;
   Bool_t          L1_Mu20_EG10er2p5;
   Bool_t          L1_Mu22er2p1_IsoTau28er2p1;
   Bool_t          L1_Mu22er2p1_IsoTau30er2p1;
   Bool_t          L1_Mu22er2p1_IsoTau32er2p1;
   Bool_t          L1_Mu22er2p1_IsoTau34er2p1;
   Bool_t          L1_Mu22er2p1_IsoTau36er2p1;
   Bool_t          L1_Mu22er2p1_IsoTau40er2p1;
   Bool_t          L1_Mu22er2p1_Tau70er2p1;
   Bool_t          L1_Mu3_Jet120er2p5_dR_Max0p4;
   Bool_t          L1_Mu3_Jet120er2p5_dR_Max0p8;
   Bool_t          L1_Mu3_Jet16er2p5_dR_Max0p4;
   Bool_t          L1_Mu3_Jet30er2p5;
   Bool_t          L1_Mu3_Jet35er2p5_dR_Max0p4;
   Bool_t          L1_Mu3_Jet60er2p5_dR_Max0p4;
   Bool_t          L1_Mu3_Jet80er2p5_dR_Max0p4;
   Bool_t          L1_Mu3er1p5_Jet100er2p5_ETMHF40;
   Bool_t          L1_Mu3er1p5_Jet100er2p5_ETMHF50;
   Bool_t          L1_Mu5_EG23er2p5;
   Bool_t          L1_Mu5_LooseIsoEG20er2p5;
   Bool_t          L1_Mu6_DoubleEG10er2p5;
   Bool_t          L1_Mu6_DoubleEG12er2p5;
   Bool_t          L1_Mu6_DoubleEG15er2p5;
   Bool_t          L1_Mu6_DoubleEG17er2p5;
   Bool_t          L1_Mu6_HTT240er;
   Bool_t          L1_Mu6_HTT250er;
   Bool_t          L1_Mu7_EG20er2p5;
   Bool_t          L1_Mu7_EG23er2p5;
   Bool_t          L1_Mu7_LooseIsoEG20er2p5;
   Bool_t          L1_Mu7_LooseIsoEG23er2p5;
   Bool_t          L1_NotBptxOR;
   Bool_t          L1_QuadJet36er2p5_IsoTau52er2p1;
   Bool_t          L1_QuadJet60er2p5;
   Bool_t          L1_QuadJet_95_75_65_20_DoubleJet_75_65_er2p5_Jet20_FWD3p0;
   Bool_t          L1_QuadMu0;
   Bool_t          L1_QuadMu0_OQ;
   Bool_t          L1_QuadMu0_SQ;
   Bool_t          L1_SecondBunchInTrain;
   Bool_t          L1_SecondLastBunchInTrain;
   Bool_t          L1_SingleEG10er2p5;
   Bool_t          L1_SingleEG15er2p5;
   Bool_t          L1_SingleEG26er2p5;
   Bool_t          L1_SingleEG28_FWD2p5;
   Bool_t          L1_SingleEG28er1p5;
   Bool_t          L1_SingleEG28er2p1;
   Bool_t          L1_SingleEG28er2p5;
   Bool_t          L1_SingleEG34er2p5;
   Bool_t          L1_SingleEG36er2p5;
   Bool_t          L1_SingleEG38er2p5;
   Bool_t          L1_SingleEG40er2p5;
   Bool_t          L1_SingleEG42er2p5;
   Bool_t          L1_SingleEG45er2p5;
   Bool_t          L1_SingleEG50;
   Bool_t          L1_SingleEG60;
   Bool_t          L1_SingleEG8er2p5;
   Bool_t          L1_SingleIsoEG24er1p5;
   Bool_t          L1_SingleIsoEG24er2p1;
   Bool_t          L1_SingleIsoEG26er1p5;
   Bool_t          L1_SingleIsoEG26er2p1;
   Bool_t          L1_SingleIsoEG26er2p5;
   Bool_t          L1_SingleIsoEG28_FWD2p5;
   Bool_t          L1_SingleIsoEG28er1p5;
   Bool_t          L1_SingleIsoEG28er2p1;
   Bool_t          L1_SingleIsoEG28er2p5;
   Bool_t          L1_SingleIsoEG30er2p1;
   Bool_t          L1_SingleIsoEG30er2p5;
   Bool_t          L1_SingleIsoEG32er2p1;
   Bool_t          L1_SingleIsoEG32er2p5;
   Bool_t          L1_SingleIsoEG34er2p5;
   Bool_t          L1_SingleJet10erHE;
   Bool_t          L1_SingleJet120;
   Bool_t          L1_SingleJet120_FWD3p0;
   Bool_t          L1_SingleJet120er2p5;
   Bool_t          L1_SingleJet12erHE;
   Bool_t          L1_SingleJet140er2p5;
   Bool_t          L1_SingleJet140er2p5_ETMHF70;
   Bool_t          L1_SingleJet140er2p5_ETMHF80;
   Bool_t          L1_SingleJet140er2p5_ETMHF90;
   Bool_t          L1_SingleJet160er2p5;
   Bool_t          L1_SingleJet180;
   Bool_t          L1_SingleJet180er2p5;
   Bool_t          L1_SingleJet200;
   Bool_t          L1_SingleJet20er2p5_NotBptxOR;
   Bool_t          L1_SingleJet20er2p5_NotBptxOR_3BX;
   Bool_t          L1_SingleJet35;
   Bool_t          L1_SingleJet35_FWD3p0;
   Bool_t          L1_SingleJet35er2p5;
   Bool_t          L1_SingleJet43er2p5_NotBptxOR_3BX;
   Bool_t          L1_SingleJet46er2p5_NotBptxOR_3BX;
   Bool_t          L1_SingleJet60;
   Bool_t          L1_SingleJet60_FWD3p0;
   Bool_t          L1_SingleJet60er2p5;
   Bool_t          L1_SingleJet8erHE;
   Bool_t          L1_SingleJet90;
   Bool_t          L1_SingleJet90_FWD3p0;
   Bool_t          L1_SingleJet90er2p5;
   Bool_t          L1_SingleLooseIsoEG26er1p5;
   Bool_t          L1_SingleLooseIsoEG26er2p5;
   Bool_t          L1_SingleLooseIsoEG28_FWD2p5;
   Bool_t          L1_SingleLooseIsoEG28er1p5;
   Bool_t          L1_SingleLooseIsoEG28er2p1;
   Bool_t          L1_SingleLooseIsoEG28er2p5;
   Bool_t          L1_SingleLooseIsoEG30er1p5;
   Bool_t          L1_SingleLooseIsoEG30er2p5;
   Bool_t          L1_SingleMu0_BMTF;
   Bool_t          L1_SingleMu0_DQ;
   Bool_t          L1_SingleMu0_EMTF;
   Bool_t          L1_SingleMu0_OMTF;
   Bool_t          L1_SingleMu10er1p5;
   Bool_t          L1_SingleMu12_DQ_BMTF;
   Bool_t          L1_SingleMu12_DQ_EMTF;
   Bool_t          L1_SingleMu12_DQ_OMTF;
   Bool_t          L1_SingleMu12er1p5;
   Bool_t          L1_SingleMu14er1p5;
   Bool_t          L1_SingleMu15_DQ;
   Bool_t          L1_SingleMu16er1p5;
   Bool_t          L1_SingleMu18;
   Bool_t          L1_SingleMu18er1p5;
   Bool_t          L1_SingleMu20;
   Bool_t          L1_SingleMu22;
   Bool_t          L1_SingleMu22_BMTF;
   Bool_t          L1_SingleMu22_EMTF;
   Bool_t          L1_SingleMu22_OMTF;
   Bool_t          L1_SingleMu25;
   Bool_t          L1_SingleMu3;
   Bool_t          L1_SingleMu5;
   Bool_t          L1_SingleMu6er1p5;
   Bool_t          L1_SingleMu7;
   Bool_t          L1_SingleMu7_DQ;
   Bool_t          L1_SingleMu7er1p5;
   Bool_t          L1_SingleMu8er1p5;
   Bool_t          L1_SingleMu9er1p5;
   Bool_t          L1_SingleMuCosmics;
   Bool_t          L1_SingleMuCosmics_BMTF;
   Bool_t          L1_SingleMuCosmics_EMTF;
   Bool_t          L1_SingleMuCosmics_OMTF;
   Bool_t          L1_SingleMuOpen;
   Bool_t          L1_SingleMuOpen_NotBptxOR;
   Bool_t          L1_SingleMuOpen_er1p1_NotBptxOR_3BX;
   Bool_t          L1_SingleMuOpen_er1p4_NotBptxOR_3BX;
   Bool_t          L1_SingleTau120er2p1;
   Bool_t          L1_SingleTau130er2p1;
   Bool_t          L1_TOTEM_1;
   Bool_t          L1_TOTEM_2;
   Bool_t          L1_TOTEM_3;
   Bool_t          L1_TOTEM_4;
   Bool_t          L1_TripleEG16er2p5;
   Bool_t          L1_TripleEG_16_12_8_er2p5;
   Bool_t          L1_TripleEG_16_15_8_er2p5;
   Bool_t          L1_TripleEG_18_17_8_er2p5;
   Bool_t          L1_TripleEG_18_18_12_er2p5;
   Bool_t          L1_TripleJet_100_80_70_DoubleJet_80_70_er2p5;
   Bool_t          L1_TripleJet_105_85_75_DoubleJet_85_75_er2p5;
   Bool_t          L1_TripleJet_95_75_65_DoubleJet_75_65_er2p5;
   Bool_t          L1_TripleMu0;
   Bool_t          L1_TripleMu0_OQ;
   Bool_t          L1_TripleMu0_SQ;
   Bool_t          L1_TripleMu3;
   Bool_t          L1_TripleMu3_SQ;
   Bool_t          L1_TripleMu_5SQ_3SQ_0OQ;
   Bool_t          L1_TripleMu_5SQ_3SQ_0OQ_DoubleMu_5_3_SQ_OS_Mass_Max9;
   Bool_t          L1_TripleMu_5SQ_3SQ_0_DoubleMu_5_3_SQ_OS_Mass_Max9;
   Bool_t          L1_TripleMu_5_3_3;
   Bool_t          L1_TripleMu_5_3_3_SQ;
   Bool_t          L1_TripleMu_5_3p5_2p5;
   Bool_t          L1_TripleMu_5_3p5_2p5_DoubleMu_5_2p5_OS_Mass_5to17;
   Bool_t          L1_TripleMu_5_3p5_2p5_OQ_DoubleMu_5_2p5_OQ_OS_Mass_5to17;
   Bool_t          L1_TripleMu_5_4_2p5_DoubleMu_5_2p5_OS_Mass_5to17;
   Bool_t          L1_TripleMu_5_5_3;
   Bool_t          L1_UnpairedBunchBptxMinus;
   Bool_t          L1_UnpairedBunchBptxPlus;
   Bool_t          L1_ZeroBias;
   Bool_t          L1_ZeroBias_copy;
   Bool_t          L1_UnprefireableEvent;
   Bool_t          Flag_HBHENoiseFilter;
   Bool_t          Flag_HBHENoiseIsoFilter;
   Bool_t          Flag_CSCTightHaloFilter;
   Bool_t          Flag_CSCTightHaloTrkMuUnvetoFilter;
   Bool_t          Flag_CSCTightHalo2015Filter;
   Bool_t          Flag_globalTightHalo2016Filter;
   Bool_t          Flag_globalSuperTightHalo2016Filter;
   Bool_t          Flag_HcalStripHaloFilter;
   Bool_t          Flag_hcalLaserEventFilter;
   Bool_t          Flag_EcalDeadCellTriggerPrimitiveFilter;
   Bool_t          Flag_EcalDeadCellBoundaryEnergyFilter;
   Bool_t          Flag_ecalBadCalibFilter;
   Bool_t          Flag_goodVertices;
   Bool_t          Flag_eeBadScFilter;
   Bool_t          Flag_ecalLaserCorrFilter;
   Bool_t          Flag_trkPOGFilters;
   Bool_t          Flag_chargedHadronTrackResolutionFilter;
   Bool_t          Flag_muonBadTrackFilter;
   Bool_t          Flag_BadChargedCandidateFilter;
   Bool_t          Flag_BadPFMuonFilter;
   Bool_t          Flag_BadPFMuonDzFilter;
   Bool_t          Flag_hfNoisyHitsFilter;
   Bool_t          Flag_BadChargedCandidateSummer16Filter;
   Bool_t          Flag_BadPFMuonSummer16Filter;
   Bool_t          Flag_trkPOG_manystripclus53X;
   Bool_t          Flag_trkPOG_toomanystripclus53X;
   Bool_t          Flag_trkPOG_logErrorTooManyClusters;
   Bool_t          Flag_METFilters;
   Bool_t          L1Reco_step;
   Bool_t          L1simulation_step;
   Bool_t          HLTriggerFirstPath;
   Bool_t          HLT_AK8PFJet360_TrimMass30;
   Bool_t          HLT_AK8PFJet380_TrimMass30;
   Bool_t          HLT_AK8PFJet400_TrimMass30;
   Bool_t          HLT_AK8PFJet420_TrimMass30;
   Bool_t          HLT_AK8PFHT750_TrimMass50;
   Bool_t          HLT_AK8PFHT800_TrimMass50;
   Bool_t          HLT_AK8PFHT850_TrimMass50;
   Bool_t          HLT_AK8PFHT900_TrimMass50;
   Bool_t          HLT_CaloJet500_NoJetID;
   Bool_t          HLT_CaloJet550_NoJetID;
   Bool_t          HLT_DoubleMu5_Upsilon_DoubleEle3_CaloIdL_TrackIdL;
   Bool_t          HLT_DoubleMu3_DoubleEle7p5_CaloIdL_TrackIdL_Upsilon;
   Bool_t          HLT_Trimuon5_3p5_2_Upsilon_Muon;
   Bool_t          HLT_TrimuonOpen_5_3p5_2_Upsilon_Muon;
   Bool_t          HLT_DoubleEle25_CaloIdL_MW;
   Bool_t          HLT_DoubleEle27_CaloIdL_MW;
   Bool_t          HLT_DoubleEle33_CaloIdL_MW;
   Bool_t          HLT_DoubleEle24_eta2p1_WPTight_Gsf;
   Bool_t          HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_DZ_PFHT350;
   Bool_t          HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_PFHT350;
   Bool_t          HLT_Ele27_Ele37_CaloIdL_MW;
   Bool_t          HLT_Mu27_Ele37_CaloIdL_MW;
   Bool_t          HLT_Mu37_Ele27_CaloIdL_MW;
   Bool_t          HLT_Mu37_TkMu27;
   Bool_t          HLT_DoubleMu4_3_Bs;
   Bool_t          HLT_DoubleMu4_3_Jpsi;
   Bool_t          HLT_DoubleMu4_JpsiTrk_Displaced;
   Bool_t          HLT_DoubleMu4_LowMassNonResonantTrk_Displaced;
   Bool_t          HLT_DoubleMu3_Trk_Tau3mu;
   Bool_t          HLT_DoubleMu3_TkMu_DsTau3Mu;
   Bool_t          HLT_DoubleMu4_PsiPrimeTrk_Displaced;
   Bool_t          HLT_DoubleMu4_Mass3p8_DZ_PFHT350;
   Bool_t          HLT_Mu3_PFJet40;
   Bool_t          HLT_Mu7p5_L2Mu2_Jpsi;
   Bool_t          HLT_Mu7p5_L2Mu2_Upsilon;
   Bool_t          HLT_Mu7p5_Track2_Jpsi;
   Bool_t          HLT_Mu7p5_Track3p5_Jpsi;
   Bool_t          HLT_Mu7p5_Track7_Jpsi;
   Bool_t          HLT_Mu7p5_Track2_Upsilon;
   Bool_t          HLT_Mu7p5_Track3p5_Upsilon;
   Bool_t          HLT_Mu7p5_Track7_Upsilon;
   Bool_t          HLT_Mu3_L1SingleMu5orSingleMu7;
   Bool_t          HLT_DoublePhoton33_CaloIdL;
   Bool_t          HLT_DoublePhoton70;
   Bool_t          HLT_DoublePhoton85;
   Bool_t          HLT_Ele20_WPTight_Gsf;
   Bool_t          HLT_Ele15_WPLoose_Gsf;
   Bool_t          HLT_Ele17_WPLoose_Gsf;
   Bool_t          HLT_Ele20_WPLoose_Gsf;
   Bool_t          HLT_Ele20_eta2p1_WPLoose_Gsf;
   Bool_t          HLT_DiEle27_WPTightCaloOnly_L1DoubleEG;
   Bool_t          HLT_Ele27_WPTight_Gsf;
   Bool_t          HLT_Ele28_WPTight_Gsf;
   Bool_t          HLT_Ele30_WPTight_Gsf;
   Bool_t          HLT_Ele32_WPTight_Gsf;
   Bool_t          HLT_Ele35_WPTight_Gsf;
   Bool_t          HLT_Ele35_WPTight_Gsf_L1EGMT;
   Bool_t          HLT_Ele38_WPTight_Gsf;
   Bool_t          HLT_Ele40_WPTight_Gsf;
   Bool_t          HLT_Ele32_WPTight_Gsf_L1DoubleEG;
   Bool_t          HLT_Ele24_eta2p1_WPTight_Gsf_LooseChargedIsoPFTau30_eta2p1_CrossL1;
   Bool_t          HLT_Ele24_eta2p1_WPTight_Gsf_LooseChargedIsoPFTauHPS30_eta2p1_CrossL1;
   Bool_t          HLT_Ele24_eta2p1_WPTight_Gsf_MediumChargedIsoPFTauHPS30_eta2p1_CrossL1;
   Bool_t          HLT_Ele24_eta2p1_WPTight_Gsf_TightChargedIsoPFTauHPS30_eta2p1_CrossL1;
   Bool_t          HLT_Ele24_eta2p1_WPTight_Gsf_LooseChargedIsoPFTauHPS30_eta2p1_TightID_CrossL1;
   Bool_t          HLT_Ele24_eta2p1_WPTight_Gsf_MediumChargedIsoPFTauHPS30_eta2p1_TightID_CrossL1;
   Bool_t          HLT_Ele24_eta2p1_WPTight_Gsf_TightChargedIsoPFTauHPS30_eta2p1_TightID_CrossL1;
   Bool_t          HLT_HT450_Beamspot;
   Bool_t          HLT_HT300_Beamspot;
   Bool_t          HLT_ZeroBias_Beamspot;
   Bool_t          HLT_IsoMu20_eta2p1_LooseChargedIsoPFTau27_eta2p1_CrossL1;
   Bool_t          HLT_IsoMu20_eta2p1_LooseChargedIsoPFTauHPS27_eta2p1_CrossL1;
   Bool_t          HLT_IsoMu20_eta2p1_MediumChargedIsoPFTauHPS27_eta2p1_CrossL1;
   Bool_t          HLT_IsoMu20_eta2p1_TightChargedIsoPFTauHPS27_eta2p1_CrossL1;
   Bool_t          HLT_IsoMu20_eta2p1_LooseChargedIsoPFTauHPS27_eta2p1_TightID_CrossL1;
   Bool_t          HLT_IsoMu20_eta2p1_MediumChargedIsoPFTauHPS27_eta2p1_TightID_CrossL1;
   Bool_t          HLT_IsoMu20_eta2p1_TightChargedIsoPFTauHPS27_eta2p1_TightID_CrossL1;
   Bool_t          HLT_IsoMu24_eta2p1_MediumChargedIsoPFTau35_Trk1_eta2p1_Reg_CrossL1;
   Bool_t          HLT_IsoMu24_eta2p1_MediumChargedIsoPFTau35_Trk1_TightID_eta2p1_Reg_CrossL1;
   Bool_t          HLT_IsoMu24_eta2p1_TightChargedIsoPFTau35_Trk1_eta2p1_Reg_CrossL1;
   Bool_t          HLT_IsoMu24_eta2p1_TightChargedIsoPFTau35_Trk1_TightID_eta2p1_Reg_CrossL1;
   Bool_t          HLT_IsoMu24_eta2p1_TightChargedIsoPFTauHPS35_Trk1_eta2p1_Reg_CrossL1;
   Bool_t          HLT_IsoMu24_eta2p1_MediumChargedIsoPFTauHPS35_Trk1_TightID_eta2p1_Reg_CrossL1;
   Bool_t          HLT_IsoMu24_eta2p1_TightChargedIsoPFTauHPS35_Trk1_TightID_eta2p1_Reg_CrossL1;
   Bool_t          HLT_IsoMu24_eta2p1_MediumChargedIsoPFTauHPS35_Trk1_eta2p1_Reg_CrossL1;
   Bool_t          HLT_IsoMu24_eta2p1_MediumChargedIsoPFTauHPS30_Trk1_eta2p1_Reg_CrossL1;
   Bool_t          HLT_IsoMu27_LooseChargedIsoPFTau20_Trk1_eta2p1_SingleL1;
   Bool_t          HLT_IsoMu27_LooseChargedIsoPFTauHPS20_Trk1_eta2p1_SingleL1;
   Bool_t          HLT_IsoMu27_MediumChargedIsoPFTauHPS20_Trk1_eta2p1_SingleL1;
   Bool_t          HLT_IsoMu27_TightChargedIsoPFTauHPS20_Trk1_eta2p1_SingleL1;
   Bool_t          HLT_IsoMu20;
   Bool_t          HLT_IsoMu24;
   Bool_t          HLT_IsoMu24_eta2p1;
   Bool_t          HLT_IsoMu27;
   Bool_t          HLT_IsoMu30;
   Bool_t          HLT_UncorrectedJetE30_NoBPTX;
   Bool_t          HLT_UncorrectedJetE30_NoBPTX3BX;
   Bool_t          HLT_UncorrectedJetE60_NoBPTX3BX;
   Bool_t          HLT_UncorrectedJetE70_NoBPTX3BX;
   Bool_t          HLT_L1SingleMu18;
   Bool_t          HLT_L1SingleMu25;
   Bool_t          HLT_L1SingleMuCosmics;
   Bool_t          HLT_L2Mu10;
   Bool_t          HLT_L2Mu10_NoVertex_NoBPTX3BX;
   Bool_t          HLT_L2Mu10_NoVertex_NoBPTX;
   Bool_t          HLT_L2Mu45_NoVertex_3Sta_NoBPTX3BX;
   Bool_t          HLT_L2Mu40_NoVertex_3Sta_NoBPTX3BX;
   Bool_t          HLT_L2Mu50;
   Bool_t          HLT_L2Mu23NoVtx_2Cha;
   Bool_t          HLT_L2Mu23NoVtx_2Cha_CosmicSeed;
   Bool_t          HLT_DoubleL2Mu30NoVtx_2Cha_CosmicSeed_Eta2p4;
   Bool_t          HLT_DoubleL2Mu30NoVtx_2Cha_Eta2p4;
   Bool_t          HLT_DoubleL2Mu50;
   Bool_t          HLT_DoubleL2Mu23NoVtx_2Cha_CosmicSeed;
   Bool_t          HLT_DoubleL2Mu23NoVtx_2Cha_CosmicSeed_NoL2Matched;
   Bool_t          HLT_DoubleL2Mu25NoVtx_2Cha_CosmicSeed;
   Bool_t          HLT_DoubleL2Mu25NoVtx_2Cha_CosmicSeed_NoL2Matched;
   Bool_t          HLT_DoubleL2Mu25NoVtx_2Cha_CosmicSeed_Eta2p4;
   Bool_t          HLT_DoubleL2Mu23NoVtx_2Cha;
   Bool_t          HLT_DoubleL2Mu23NoVtx_2Cha_NoL2Matched;
   Bool_t          HLT_DoubleL2Mu25NoVtx_2Cha;
   Bool_t          HLT_DoubleL2Mu25NoVtx_2Cha_NoL2Matched;
   Bool_t          HLT_DoubleL2Mu25NoVtx_2Cha_Eta2p4;
   Bool_t          HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL;
   Bool_t          HLT_Mu19_TrkIsoVVL_Mu9_TrkIsoVVL;
   Bool_t          HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ;
   Bool_t          HLT_Mu19_TrkIsoVVL_Mu9_TrkIsoVVL_DZ;
   Bool_t          HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass8;
   Bool_t          HLT_Mu19_TrkIsoVVL_Mu9_TrkIsoVVL_DZ_Mass8;
   Bool_t          HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8;
   Bool_t          HLT_Mu19_TrkIsoVVL_Mu9_TrkIsoVVL_DZ_Mass3p8;
   Bool_t          HLT_Mu25_TkMu0_Onia;
   Bool_t          HLT_Mu30_TkMu0_Psi;
   Bool_t          HLT_Mu30_TkMu0_Upsilon;
   Bool_t          HLT_Mu20_TkMu0_Phi;
   Bool_t          HLT_Mu25_TkMu0_Phi;
   Bool_t          HLT_Mu12;
   Bool_t          HLT_Mu15;
   Bool_t          HLT_Mu20;
   Bool_t          HLT_Mu27;
   Bool_t          HLT_Mu50;
   Bool_t          HLT_Mu55;
   Bool_t          HLT_OldMu100;
   Bool_t          HLT_TkMu100;
   Bool_t          HLT_DiPFJet15_NoCaloMatched;
   Bool_t          HLT_DiPFJet25_NoCaloMatched;
   Bool_t          HLT_DiPFJet15_FBEta3_NoCaloMatched;
   Bool_t          HLT_DiPFJet25_FBEta3_NoCaloMatched;
   Bool_t          HLT_DiPFJetAve40;
   Bool_t          HLT_DiPFJetAve60;
   Bool_t          HLT_DiPFJetAve80;
   Bool_t          HLT_DiPFJetAve140;
   Bool_t          HLT_DiPFJetAve200;
   Bool_t          HLT_DiPFJetAve260;
   Bool_t          HLT_DiPFJetAve320;
   Bool_t          HLT_DiPFJetAve400;
   Bool_t          HLT_DiPFJetAve500;
   Bool_t          HLT_DiPFJetAve15_HFJEC;
   Bool_t          HLT_DiPFJetAve25_HFJEC;
   Bool_t          HLT_DiPFJetAve35_HFJEC;
   Bool_t          HLT_DiPFJetAve60_HFJEC;
   Bool_t          HLT_DiPFJetAve80_HFJEC;
   Bool_t          HLT_DiPFJetAve100_HFJEC;
   Bool_t          HLT_DiPFJetAve160_HFJEC;
   Bool_t          HLT_DiPFJetAve220_HFJEC;
   Bool_t          HLT_DiPFJetAve300_HFJEC;
  //Bool_t          HLT_AK8PFJet15;
  //Bool_t          HLT_AK8PFJet25;
   Bool_t          HLT_AK8PFJet40;
   Bool_t          HLT_AK8PFJet60;
   Bool_t          HLT_AK8PFJet80;
   Bool_t          HLT_AK8PFJet140;
   Bool_t          HLT_AK8PFJet200;
   Bool_t          HLT_AK8PFJet260;
   Bool_t          HLT_AK8PFJet320;
   Bool_t          HLT_AK8PFJet400;
   Bool_t          HLT_AK8PFJet450;
   Bool_t          HLT_AK8PFJet500;
   Bool_t          HLT_AK8PFJet550;
  //Bool_t          HLT_PFJet15;
  //Bool_t          HLT_PFJet25;
   Bool_t          HLT_PFJet40;
   Bool_t          HLT_PFJet60;
   Bool_t          HLT_PFJet80;
   Bool_t          HLT_PFJet140;
   Bool_t          HLT_PFJet200;
   Bool_t          HLT_PFJet260;
   Bool_t          HLT_PFJet320;
   Bool_t          HLT_PFJet400;
   Bool_t          HLT_PFJet450;
   Bool_t          HLT_PFJet500;
   Bool_t          HLT_PFJet550;
   Bool_t          HLT_PFJetFwd15;
   Bool_t          HLT_PFJetFwd25;
   Bool_t          HLT_PFJetFwd40;
   Bool_t          HLT_PFJetFwd60;
   Bool_t          HLT_PFJetFwd80;
   Bool_t          HLT_PFJetFwd140;
   Bool_t          HLT_PFJetFwd200;
   Bool_t          HLT_PFJetFwd260;
   Bool_t          HLT_PFJetFwd320;
   Bool_t          HLT_PFJetFwd400;
   Bool_t          HLT_PFJetFwd450;
   Bool_t          HLT_PFJetFwd500;
   Bool_t          HLT_AK8PFJetFwd15;
   Bool_t          HLT_AK8PFJetFwd25;
   Bool_t          HLT_AK8PFJetFwd40;
   Bool_t          HLT_AK8PFJetFwd60;
   Bool_t          HLT_AK8PFJetFwd80;
   Bool_t          HLT_AK8PFJetFwd140;
   Bool_t          HLT_AK8PFJetFwd200;
   Bool_t          HLT_AK8PFJetFwd260;
   Bool_t          HLT_AK8PFJetFwd320;
   Bool_t          HLT_AK8PFJetFwd400;
   Bool_t          HLT_AK8PFJetFwd450;
   Bool_t          HLT_AK8PFJetFwd500;
   Bool_t          HLT_PFHT180;
   Bool_t          HLT_PFHT250;
   Bool_t          HLT_PFHT370;
   Bool_t          HLT_PFHT430;
   Bool_t          HLT_PFHT510;
   Bool_t          HLT_PFHT590;
   Bool_t          HLT_PFHT680;
   Bool_t          HLT_PFHT780;
   Bool_t          HLT_PFHT890;
   Bool_t          HLT_PFHT1050;
   Bool_t          HLT_PFHT500_PFMET100_PFMHT100_IDTight;
   Bool_t          HLT_PFHT500_PFMET110_PFMHT110_IDTight;
   Bool_t          HLT_PFHT700_PFMET85_PFMHT85_IDTight;
   Bool_t          HLT_PFHT700_PFMET95_PFMHT95_IDTight;
   Bool_t          HLT_PFHT800_PFMET75_PFMHT75_IDTight;
   Bool_t          HLT_PFHT800_PFMET85_PFMHT85_IDTight;
   Bool_t          HLT_PFMET110_PFMHT110_IDTight;
   Bool_t          HLT_PFMET120_PFMHT120_IDTight;
   Bool_t          HLT_PFMET130_PFMHT130_IDTight;
   Bool_t          HLT_PFMET140_PFMHT140_IDTight;
   Bool_t          HLT_PFMET100_PFMHT100_IDTight_CaloBTagDeepCSV_3p1;
   Bool_t          HLT_PFMET110_PFMHT110_IDTight_CaloBTagDeepCSV_3p1;
   Bool_t          HLT_PFMET120_PFMHT120_IDTight_CaloBTagDeepCSV_3p1;
   Bool_t          HLT_PFMET130_PFMHT130_IDTight_CaloBTagDeepCSV_3p1;
   Bool_t          HLT_PFMET140_PFMHT140_IDTight_CaloBTagDeepCSV_3p1;
   Bool_t          HLT_PFMET120_PFMHT120_IDTight_PFHT60;
   Bool_t          HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60;
   Bool_t          HLT_PFMETTypeOne120_PFMHT120_IDTight_PFHT60;
   Bool_t          HLT_PFMETTypeOne110_PFMHT110_IDTight;
   Bool_t          HLT_PFMETTypeOne120_PFMHT120_IDTight;
   Bool_t          HLT_PFMETTypeOne130_PFMHT130_IDTight;
   Bool_t          HLT_PFMETTypeOne140_PFMHT140_IDTight;
   Bool_t          HLT_PFMETNoMu110_PFMHTNoMu110_IDTight;
   Bool_t          HLT_PFMETNoMu120_PFMHTNoMu120_IDTight;
   Bool_t          HLT_PFMETNoMu130_PFMHTNoMu130_IDTight;
   Bool_t          HLT_PFMETNoMu140_PFMHTNoMu140_IDTight;
   Bool_t          HLT_MonoCentralPFJet80_PFMETNoMu110_PFMHTNoMu110_IDTight;
   Bool_t          HLT_MonoCentralPFJet80_PFMETNoMu120_PFMHTNoMu120_IDTight;
   Bool_t          HLT_MonoCentralPFJet80_PFMETNoMu130_PFMHTNoMu130_IDTight;
   Bool_t          HLT_MonoCentralPFJet80_PFMETNoMu140_PFMHTNoMu140_IDTight;
   Bool_t          HLT_L1ETMHadSeeds;
   Bool_t          HLT_CaloMHT90;
   Bool_t          HLT_CaloMET80_NotCleaned;
   Bool_t          HLT_CaloMET90_NotCleaned;
   Bool_t          HLT_CaloMET100_NotCleaned;
   Bool_t          HLT_CaloMET110_NotCleaned;
   Bool_t          HLT_CaloMET250_NotCleaned;
   Bool_t          HLT_CaloMET300_NotCleaned;
   Bool_t          HLT_CaloMET350_NotCleaned;
   Bool_t          HLT_PFMET200_NotCleaned;
   Bool_t          HLT_PFMET250_NotCleaned;
   Bool_t          HLT_PFMET300_NotCleaned;
   Bool_t          HLT_PFMET200_BeamHaloCleaned;
   Bool_t          HLT_PFMETTypeOne200_BeamHaloCleaned;
   Bool_t          HLT_MET105_IsoTrk50;
   Bool_t          HLT_MET120_IsoTrk50;
   Bool_t          HLT_SingleJet30_Mu12_SinglePFJet40;
   Bool_t          HLT_Mu12_DoublePFJets40_CaloBTagDeepCSV_p71;
   Bool_t          HLT_Mu12_DoublePFJets100_CaloBTagDeepCSV_p71;
   Bool_t          HLT_Mu12_DoublePFJets200_CaloBTagDeepCSV_p71;
   Bool_t          HLT_Mu12_DoublePFJets350_CaloBTagDeepCSV_p71;
   Bool_t          HLT_Mu12_DoublePFJets40MaxDeta1p6_DoubleCaloBTagDeepCSV_p71;
   Bool_t          HLT_Mu12_DoublePFJets54MaxDeta1p6_DoubleCaloBTagDeepCSV_p71;
   Bool_t          HLT_Mu12_DoublePFJets62MaxDeta1p6_DoubleCaloBTagDeepCSV_p71;
   Bool_t          HLT_DoublePFJets40_CaloBTagDeepCSV_p71;
   Bool_t          HLT_DoublePFJets100_CaloBTagDeepCSV_p71;
   Bool_t          HLT_DoublePFJets200_CaloBTagDeepCSV_p71;
   Bool_t          HLT_DoublePFJets350_CaloBTagDeepCSV_p71;
   Bool_t          HLT_DoublePFJets116MaxDeta1p6_DoubleCaloBTagDeepCSV_p71;
   Bool_t          HLT_DoublePFJets128MaxDeta1p6_DoubleCaloBTagDeepCSV_p71;
   Bool_t          HLT_Photon300_NoHE;
   Bool_t          HLT_Mu8_TrkIsoVVL;
   Bool_t          HLT_Mu8_DiEle12_CaloIdL_TrackIdL_DZ;
   Bool_t          HLT_Mu8_DiEle12_CaloIdL_TrackIdL;
   Bool_t          HLT_Mu8_Ele8_CaloIdM_TrackIdM_Mass8_PFHT350_DZ;
   Bool_t          HLT_Mu8_Ele8_CaloIdM_TrackIdM_Mass8_PFHT350;
   Bool_t          HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ;
   Bool_t          HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_PFDiJet30;
   Bool_t          HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_CaloDiJet30;
   Bool_t          HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_PFDiJet30_PFBtagDeepCSV_1p5;
   Bool_t          HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_CaloDiJet30_CaloBtagDeepCSV_1p5;
   Bool_t          HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL;
   Bool_t          HLT_Mu17_TrkIsoVVL;
   Bool_t          HLT_Mu19_TrkIsoVVL;
   Bool_t          HLT_BTagMu_AK4DiJet20_Mu5;
   Bool_t          HLT_BTagMu_AK4DiJet40_Mu5;
   Bool_t          HLT_BTagMu_AK4DiJet70_Mu5;
   Bool_t          HLT_BTagMu_AK4DiJet110_Mu5;
   Bool_t          HLT_BTagMu_AK4DiJet170_Mu5;
   Bool_t          HLT_BTagMu_AK4Jet300_Mu5;
   Bool_t          HLT_BTagMu_AK8DiJet170_Mu5;
   Bool_t          HLT_BTagMu_AK8Jet170_DoubleMu5;
   Bool_t          HLT_BTagMu_AK8Jet300_Mu5;
   Bool_t          HLT_BTagMu_AK4DiJet20_Mu5_noalgo;
   Bool_t          HLT_BTagMu_AK4DiJet40_Mu5_noalgo;
   Bool_t          HLT_BTagMu_AK4DiJet70_Mu5_noalgo;
   Bool_t          HLT_BTagMu_AK4DiJet110_Mu5_noalgo;
   Bool_t          HLT_BTagMu_AK4DiJet170_Mu5_noalgo;
   Bool_t          HLT_BTagMu_AK4Jet300_Mu5_noalgo;
   Bool_t          HLT_BTagMu_AK8DiJet170_Mu5_noalgo;
   Bool_t          HLT_BTagMu_AK8Jet170_DoubleMu5_noalgo;
   Bool_t          HLT_BTagMu_AK8Jet300_Mu5_noalgo;
   Bool_t          HLT_Ele15_Ele8_CaloIdL_TrackIdL_IsoVL;
   Bool_t          HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ;
   Bool_t          HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL;
   Bool_t          HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ;
   Bool_t          HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL;
   Bool_t          HLT_Mu12_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL;
   Bool_t          HLT_Mu12_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ;
   Bool_t          HLT_Mu12_DoublePhoton20;
   Bool_t          HLT_TriplePhoton_20_20_20_CaloIdLV2;
   Bool_t          HLT_TriplePhoton_20_20_20_CaloIdLV2_R9IdVL;
   Bool_t          HLT_TriplePhoton_30_30_10_CaloIdLV2;
   Bool_t          HLT_TriplePhoton_30_30_10_CaloIdLV2_R9IdVL;
   Bool_t          HLT_TriplePhoton_35_35_5_CaloIdLV2_R9IdVL;
   Bool_t          HLT_Photon20;
   Bool_t          HLT_Photon33;
   Bool_t          HLT_Photon50;
   Bool_t          HLT_Photon75;
   Bool_t          HLT_Photon90;
   Bool_t          HLT_Photon120;
   Bool_t          HLT_Photon150;
   Bool_t          HLT_Photon175;
   Bool_t          HLT_Photon200;
   Bool_t          HLT_Photon100EB_TightID_TightIso;
   Bool_t          HLT_Photon110EB_TightID_TightIso;
   Bool_t          HLT_Photon120EB_TightID_TightIso;
   Bool_t          HLT_Photon100EBHE10;
   Bool_t          HLT_Photon100EEHE10;
   Bool_t          HLT_Photon100EE_TightID_TightIso;
   Bool_t          HLT_Photon50_R9Id90_HE10_IsoM;
   Bool_t          HLT_Photon75_R9Id90_HE10_IsoM;
   Bool_t          HLT_Photon75_R9Id90_HE10_IsoM_EBOnly_CaloMJJ300_PFJetsMJJ400DEta3;
   Bool_t          HLT_Photon75_R9Id90_HE10_IsoM_EBOnly_CaloMJJ400_PFJetsMJJ600DEta3;
   Bool_t          HLT_Photon90_R9Id90_HE10_IsoM;
   Bool_t          HLT_Photon120_R9Id90_HE10_IsoM;
   Bool_t          HLT_Photon165_R9Id90_HE10_IsoM;
   Bool_t          HLT_Photon90_CaloIdL_PFHT700;
   Bool_t          HLT_Diphoton30_22_R9Id_OR_IsoCaloId_AND_HE_R9Id_Mass90;
   Bool_t          HLT_Diphoton30_22_R9Id_OR_IsoCaloId_AND_HE_R9Id_Mass95;
   Bool_t          HLT_Diphoton30PV_18PV_R9Id_AND_IsoCaloId_AND_HE_R9Id_PixelVeto_Mass55;
   Bool_t          HLT_Diphoton30PV_18PV_R9Id_AND_IsoCaloId_AND_HE_R9Id_NoPixelVeto_Mass55;
   Bool_t          HLT_Photon35_TwoProngs35;
   Bool_t          HLT_IsoMu24_TwoProngs35;
   Bool_t          HLT_Dimuon0_Jpsi_L1_NoOS;
   Bool_t          HLT_Dimuon0_Jpsi_NoVertexing_NoOS;
   Bool_t          HLT_Dimuon0_Jpsi;
   Bool_t          HLT_Dimuon0_Jpsi_NoVertexing;
   Bool_t          HLT_Dimuon0_Jpsi_L1_4R_0er1p5R;
   Bool_t          HLT_Dimuon0_Jpsi_NoVertexing_L1_4R_0er1p5R;
   Bool_t          HLT_Dimuon0_Jpsi3p5_Muon2;
   Bool_t          HLT_Dimuon0_Upsilon_L1_4p5;
   Bool_t          HLT_Dimuon0_Upsilon_L1_5;
   Bool_t          HLT_Dimuon0_Upsilon_L1_4p5NoOS;
   Bool_t          HLT_Dimuon0_Upsilon_L1_4p5er2p0;
   Bool_t          HLT_Dimuon0_Upsilon_L1_4p5er2p0M;
   Bool_t          HLT_Dimuon0_Upsilon_NoVertexing;
   Bool_t          HLT_Dimuon0_Upsilon_L1_5M;
   Bool_t          HLT_Dimuon0_LowMass_L1_0er1p5R;
   Bool_t          HLT_Dimuon0_LowMass_L1_0er1p5;
   Bool_t          HLT_Dimuon0_LowMass;
   Bool_t          HLT_Dimuon0_LowMass_L1_4;
   Bool_t          HLT_Dimuon0_LowMass_L1_4R;
   Bool_t          HLT_Dimuon0_LowMass_L1_TM530;
   Bool_t          HLT_Dimuon0_Upsilon_Muon_L1_TM0;
   Bool_t          HLT_Dimuon0_Upsilon_Muon_NoL1Mass;
   Bool_t          HLT_TripleMu_5_3_3_Mass3p8_DZ;
   Bool_t          HLT_TripleMu_10_5_5_DZ;
   Bool_t          HLT_TripleMu_12_10_5;
   Bool_t          HLT_Tau3Mu_Mu7_Mu1_TkMu1_Tau15;
   Bool_t          HLT_Tau3Mu_Mu7_Mu1_TkMu1_Tau15_Charge1;
   Bool_t          HLT_Tau3Mu_Mu7_Mu1_TkMu1_IsoTau15;
   Bool_t          HLT_Tau3Mu_Mu7_Mu1_TkMu1_IsoTau15_Charge1;
   Bool_t          HLT_DoubleMu3_DZ_PFMET50_PFMHT60;
   Bool_t          HLT_DoubleMu3_DZ_PFMET70_PFMHT70;
   Bool_t          HLT_DoubleMu3_DZ_PFMET90_PFMHT90;
   Bool_t          HLT_DoubleMu3_Trk_Tau3mu_NoL1Mass;
   Bool_t          HLT_DoubleMu4_Jpsi_Displaced;
   Bool_t          HLT_DoubleMu4_Jpsi_NoVertexing;
   Bool_t          HLT_DoubleMu4_JpsiTrkTrk_Displaced;
   Bool_t          HLT_DoubleMu43NoFiltersNoVtx;
   Bool_t          HLT_DoubleMu48NoFiltersNoVtx;
   Bool_t          HLT_Mu43NoFiltersNoVtx_Photon43_CaloIdL;
   Bool_t          HLT_Mu48NoFiltersNoVtx_Photon48_CaloIdL;
   Bool_t          HLT_Mu38NoFiltersNoVtxDisplaced_Photon38_CaloIdL;
   Bool_t          HLT_Mu43NoFiltersNoVtxDisplaced_Photon43_CaloIdL;
   Bool_t          HLT_DoubleMu33NoFiltersNoVtxDisplaced;
   Bool_t          HLT_DoubleMu40NoFiltersNoVtxDisplaced;
   Bool_t          HLT_DoubleMu20_7_Mass0to30_L1_DM4;
   Bool_t          HLT_DoubleMu20_7_Mass0to30_L1_DM4EG;
   Bool_t          HLT_HT425;
   Bool_t          HLT_HT430_DisplacedDijet40_DisplacedTrack;
   Bool_t          HLT_HT500_DisplacedDijet40_DisplacedTrack;
   Bool_t          HLT_HT430_DisplacedDijet60_DisplacedTrack;
   Bool_t          HLT_HT400_DisplacedDijet40_DisplacedTrack;
   Bool_t          HLT_HT650_DisplacedDijet60_Inclusive;
   Bool_t          HLT_HT550_DisplacedDijet60_Inclusive;
   Bool_t          HLT_DiJet110_35_Mjj650_PFMET110;
   Bool_t          HLT_DiJet110_35_Mjj650_PFMET120;
   Bool_t          HLT_DiJet110_35_Mjj650_PFMET130;
   Bool_t          HLT_TripleJet110_35_35_Mjj650_PFMET110;
   Bool_t          HLT_TripleJet110_35_35_Mjj650_PFMET120;
   Bool_t          HLT_TripleJet110_35_35_Mjj650_PFMET130;
   Bool_t          HLT_Ele30_eta2p1_WPTight_Gsf_CentralPFJet35_EleCleaned;
   Bool_t          HLT_Ele28_eta2p1_WPTight_Gsf_HT150;
   Bool_t          HLT_Ele28_HighEta_SC20_Mass55;
   Bool_t          HLT_DoubleMu20_7_Mass0to30_Photon23;
   Bool_t          HLT_Ele15_IsoVVVL_PFHT450_CaloBTagDeepCSV_4p5;
   Bool_t          HLT_Ele15_IsoVVVL_PFHT450_PFMET50;
   Bool_t          HLT_Ele15_IsoVVVL_PFHT450;
   Bool_t          HLT_Ele50_IsoVVVL_PFHT450;
   Bool_t          HLT_Ele15_IsoVVVL_PFHT600;
   Bool_t          HLT_Mu4_TrkIsoVVL_DiPFJet90_40_DEta3p5_MJJ750_HTT300_PFMETNoMu60;
   Bool_t          HLT_Mu8_TrkIsoVVL_DiPFJet40_DEta3p5_MJJ750_HTT300_PFMETNoMu60;
   Bool_t          HLT_Mu10_TrkIsoVVL_DiPFJet40_DEta3p5_MJJ750_HTT350_PFMETNoMu60;
   Bool_t          HLT_Mu15_IsoVVVL_PFHT450_CaloBTagDeepCSV_4p5;
   Bool_t          HLT_Mu15_IsoVVVL_PFHT450_PFMET50;
   Bool_t          HLT_Mu15_IsoVVVL_PFHT450;
   Bool_t          HLT_Mu50_IsoVVVL_PFHT450;
   Bool_t          HLT_Mu15_IsoVVVL_PFHT600;
   Bool_t          HLT_Mu3er1p5_PFJet100er2p5_PFMET70_PFMHT70_IDTight;
   Bool_t          HLT_Mu3er1p5_PFJet100er2p5_PFMET80_PFMHT80_IDTight;
   Bool_t          HLT_Mu3er1p5_PFJet100er2p5_PFMET90_PFMHT90_IDTight;
   Bool_t          HLT_Mu3er1p5_PFJet100er2p5_PFMET100_PFMHT100_IDTight;
   Bool_t          HLT_Mu3er1p5_PFJet100er2p5_PFMETNoMu70_PFMHTNoMu70_IDTight;
   Bool_t          HLT_Mu3er1p5_PFJet100er2p5_PFMETNoMu80_PFMHTNoMu80_IDTight;
   Bool_t          HLT_Mu3er1p5_PFJet100er2p5_PFMETNoMu90_PFMHTNoMu90_IDTight;
   Bool_t          HLT_Mu3er1p5_PFJet100er2p5_PFMETNoMu100_PFMHTNoMu100_IDTight;
   Bool_t          HLT_Dimuon10_PsiPrime_Barrel_Seagulls;
   Bool_t          HLT_Dimuon20_Jpsi_Barrel_Seagulls;
   Bool_t          HLT_Dimuon12_Upsilon_y1p4;
   Bool_t          HLT_Dimuon14_Phi_Barrel_Seagulls;
   Bool_t          HLT_Dimuon18_PsiPrime;
   Bool_t          HLT_Dimuon25_Jpsi;
   Bool_t          HLT_Dimuon18_PsiPrime_noCorrL1;
   Bool_t          HLT_Dimuon24_Upsilon_noCorrL1;
   Bool_t          HLT_Dimuon24_Phi_noCorrL1;
   Bool_t          HLT_Dimuon25_Jpsi_noCorrL1;
   Bool_t          HLT_DiMu4_Ele9_CaloIdL_TrackIdL_DZ_Mass3p8;
   Bool_t          HLT_DiMu9_Ele9_CaloIdL_TrackIdL_DZ;
   Bool_t          HLT_DiMu9_Ele9_CaloIdL_TrackIdL;
   Bool_t          HLT_DoubleIsoMu20_eta2p1;
   Bool_t          HLT_TrkMu12_DoubleTrkMu5NoFiltersNoVtx;
   Bool_t          HLT_TrkMu16_DoubleTrkMu6NoFiltersNoVtx;
   Bool_t          HLT_TrkMu17_DoubleTrkMu8NoFiltersNoVtx;
   Bool_t          HLT_Mu8;
   Bool_t          HLT_Mu17;
   Bool_t          HLT_Mu19;
   Bool_t          HLT_Mu17_Photon30_IsoCaloId;
   Bool_t          HLT_Ele8_CaloIdL_TrackIdL_IsoVL_PFJet30;
   Bool_t          HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30;
   Bool_t          HLT_Ele15_CaloIdL_TrackIdL_IsoVL_PFJet30;
   Bool_t          HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30;
   Bool_t          HLT_Ele8_CaloIdM_TrackIdM_PFJet30;
   Bool_t          HLT_Ele17_CaloIdM_TrackIdM_PFJet30;
   Bool_t          HLT_Ele23_CaloIdM_TrackIdM_PFJet30;
   Bool_t          HLT_Ele50_CaloIdVT_GsfTrkIdT_PFJet165;
   Bool_t          HLT_Ele115_CaloIdVT_GsfTrkIdT;
   Bool_t          HLT_Ele135_CaloIdVT_GsfTrkIdT;
   Bool_t          HLT_Ele145_CaloIdVT_GsfTrkIdT;
   Bool_t          HLT_Ele200_CaloIdVT_GsfTrkIdT;
   Bool_t          HLT_Ele250_CaloIdVT_GsfTrkIdT;
   Bool_t          HLT_Ele300_CaloIdVT_GsfTrkIdT;
   Bool_t          HLT_PFHT330PT30_QuadPFJet_75_60_45_40_TriplePFBTagDeepCSV_4p5;
   Bool_t          HLT_PFHT330PT30_QuadPFJet_75_60_45_40;
   Bool_t          HLT_PFHT400_SixPFJet32_DoublePFBTagDeepCSV_2p94;
   Bool_t          HLT_PFHT400_SixPFJet32;
   Bool_t          HLT_PFHT450_SixPFJet36_PFBTagDeepCSV_1p59;
   Bool_t          HLT_PFHT450_SixPFJet36;
   Bool_t          HLT_PFHT400_FivePFJet_100_100_60_30_30;
   Bool_t          HLT_PFHT400_FivePFJet_100_100_60_30_30_DoublePFBTagDeepCSV_4p5;
   Bool_t          HLT_PFHT400_FivePFJet_120_120_60_30_30_DoublePFBTagDeepCSV_4p5;
   Bool_t          HLT_PFHT350;
   Bool_t          HLT_PFHT350MinPFJet15;
   Bool_t          HLT_Photon60_R9Id90_CaloIdL_IsoL;
   Bool_t          HLT_Photon60_R9Id90_CaloIdL_IsoL_DisplacedIdL;
   Bool_t          HLT_Photon60_R9Id90_CaloIdL_IsoL_DisplacedIdL_PFHT350MinPFJet15;
   Bool_t          HLT_ECALHT800;
   Bool_t          HLT_DiSC30_18_EIso_AND_HE_Mass70;
   Bool_t          HLT_Physics;
   Bool_t          HLT_Physics_part0;
   Bool_t          HLT_Physics_part1;
   Bool_t          HLT_Physics_part2;
   Bool_t          HLT_Physics_part3;
   Bool_t          HLT_Physics_part4;
   Bool_t          HLT_Physics_part5;
   Bool_t          HLT_Physics_part6;
   Bool_t          HLT_Physics_part7;
   Bool_t          HLT_Random;
   Bool_t          HLT_ZeroBias;
   Bool_t          HLT_ZeroBias_Alignment;
   Bool_t          HLT_ZeroBias_part0;
   Bool_t          HLT_ZeroBias_part1;
   Bool_t          HLT_ZeroBias_part2;
   Bool_t          HLT_ZeroBias_part3;
   Bool_t          HLT_ZeroBias_part4;
   Bool_t          HLT_ZeroBias_part5;
   Bool_t          HLT_ZeroBias_part6;
   Bool_t          HLT_ZeroBias_part7;
   Bool_t          HLT_AK4CaloJet30;
   Bool_t          HLT_AK4CaloJet40;
   Bool_t          HLT_AK4CaloJet50;
   Bool_t          HLT_AK4CaloJet80;
   Bool_t          HLT_AK4CaloJet100;
   Bool_t          HLT_AK4CaloJet120;
   Bool_t          HLT_AK4PFJet30;
   Bool_t          HLT_AK4PFJet50;
   Bool_t          HLT_AK4PFJet80;
   Bool_t          HLT_AK4PFJet100;
   Bool_t          HLT_AK4PFJet120;
   Bool_t          HLT_SinglePhoton10_Eta3p1ForPPRef;
   Bool_t          HLT_SinglePhoton20_Eta3p1ForPPRef;
   Bool_t          HLT_SinglePhoton30_Eta3p1ForPPRef;
   Bool_t          HLT_Photon20_HoverELoose;
   Bool_t          HLT_Photon30_HoverELoose;
   Bool_t          HLT_EcalCalibration;
   Bool_t          HLT_HcalCalibration;
   Bool_t          HLT_L1UnpairedBunchBptxMinus;
   Bool_t          HLT_L1UnpairedBunchBptxPlus;
   Bool_t          HLT_L1NotBptxOR;
   Bool_t          HLT_L1_CDC_SingleMu_3_er1p2_TOP120_DPHI2p618_3p142;
   Bool_t          HLT_CDC_L2cosmic_10_er1p0;
   Bool_t          HLT_CDC_L2cosmic_5p5_er1p0;
   Bool_t          HLT_HcalNZS;
   Bool_t          HLT_HcalPhiSym;
   Bool_t          HLT_HcalIsolatedbunch;
   Bool_t          HLT_IsoTrackHB;
   Bool_t          HLT_IsoTrackHE;
   Bool_t          HLT_ZeroBias_FirstCollisionAfterAbortGap;
   Bool_t          HLT_ZeroBias_IsolatedBunches;
   Bool_t          HLT_ZeroBias_FirstCollisionInTrain;
   Bool_t          HLT_ZeroBias_LastCollisionInTrain;
   Bool_t          HLT_ZeroBias_FirstBXAfterTrain;
   Bool_t          HLT_IsoMu24_eta2p1_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr;
   Bool_t          HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr_MET90;
   Bool_t          HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr_MET100;
   Bool_t          HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr_MET110;
   Bool_t          HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr_MET120;
   Bool_t          HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr_MET130;
   Bool_t          HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr_MET140;
   Bool_t          HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr;
   Bool_t          HLT_MediumChargedIsoPFTau180HighPtRelaxedIso_Trk50_eta2p1_1pr;
   Bool_t          HLT_MediumChargedIsoPFTau180HighPtRelaxedIso_Trk50_eta2p1;
   Bool_t          HLT_MediumChargedIsoPFTau200HighPtRelaxedIso_Trk50_eta2p1;
   Bool_t          HLT_MediumChargedIsoPFTau220HighPtRelaxedIso_Trk50_eta2p1;
   Bool_t          HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL;
   Bool_t          HLT_Rsq0p35;
   Bool_t          HLT_Rsq0p40;
   Bool_t          HLT_RsqMR300_Rsq0p09_MR200;
   Bool_t          HLT_RsqMR320_Rsq0p09_MR200;
   Bool_t          HLT_RsqMR300_Rsq0p09_MR200_4jet;
   Bool_t          HLT_RsqMR320_Rsq0p09_MR200_4jet;
   Bool_t          HLT_IsoMu27_MET90;
   Bool_t          HLT_DoubleMediumChargedIsoPFTau35_Trk1_eta2p1_Reg;
   Bool_t          HLT_DoubleMediumChargedIsoPFTau35_Trk1_TightID_eta2p1_Reg;
   Bool_t          HLT_DoubleTightChargedIsoPFTau35_Trk1_eta2p1_Reg;
   Bool_t          HLT_DoubleTightChargedIsoPFTau35_Trk1_TightID_eta2p1_Reg;
   Bool_t          HLT_DoubleMediumChargedIsoPFTauHPS30_L1MaxMass_Trk1_eta2p1_Reg;
   Bool_t          HLT_DoubleTightChargedIsoPFTauHPS35_Trk1_eta2p1_Reg;
   Bool_t          HLT_DoubleMediumChargedIsoPFTauHPS35_Trk1_TightID_eta2p1_Reg;
   Bool_t          HLT_DoubleMediumChargedIsoPFTauHPS35_Trk1_eta2p1_Reg;
   Bool_t          HLT_DoubleTightChargedIsoPFTauHPS35_Trk1_TightID_eta2p1_Reg;
   Bool_t          HLT_DoubleMediumChargedIsoPFTauHPS40_Trk1_eta2p1_Reg;
   Bool_t          HLT_DoubleTightChargedIsoPFTauHPS40_Trk1_eta2p1_Reg;
   Bool_t          HLT_DoubleMediumChargedIsoPFTauHPS40_Trk1_TightID_eta2p1_Reg;
   Bool_t          HLT_DoubleTightChargedIsoPFTauHPS40_Trk1_TightID_eta2p1_Reg;
   Bool_t          HLT_VBF_DoubleLooseChargedIsoPFTau20_Trk1_eta2p1;
   Bool_t          HLT_VBF_DoubleLooseChargedIsoPFTauHPS20_Trk1_eta2p1;
   Bool_t          HLT_VBF_DoubleMediumChargedIsoPFTauHPS20_Trk1_eta2p1;
   Bool_t          HLT_VBF_DoubleTightChargedIsoPFTauHPS20_Trk1_eta2p1;
   Bool_t          HLT_Photon50_R9Id90_HE10_IsoM_EBOnly_PFJetsMJJ300DEta3_PFMET50;
   Bool_t          HLT_Photon75_R9Id90_HE10_IsoM_EBOnly_PFJetsMJJ300DEta3;
   Bool_t          HLT_Photon75_R9Id90_HE10_IsoM_EBOnly_PFJetsMJJ600DEta3;
   Bool_t          HLT_PFMET100_PFMHT100_IDTight_PFHT60;
   Bool_t          HLT_PFMETNoMu100_PFMHTNoMu100_IDTight_PFHT60;
   Bool_t          HLT_PFMETTypeOne100_PFMHT100_IDTight_PFHT60;
   Bool_t          HLT_Mu18_Mu9_SameSign;
   Bool_t          HLT_Mu18_Mu9_SameSign_DZ;
   Bool_t          HLT_Mu18_Mu9;
   Bool_t          HLT_Mu18_Mu9_DZ;
   Bool_t          HLT_Mu20_Mu10_SameSign;
   Bool_t          HLT_Mu20_Mu10_SameSign_DZ;
   Bool_t          HLT_Mu20_Mu10;
   Bool_t          HLT_Mu20_Mu10_DZ;
   Bool_t          HLT_Mu23_Mu12_SameSign;
   Bool_t          HLT_Mu23_Mu12_SameSign_DZ;
   Bool_t          HLT_Mu23_Mu12;
   Bool_t          HLT_Mu23_Mu12_DZ;
   Bool_t          HLT_DoubleMu2_Jpsi_DoubleTrk1_Phi1p05;
   Bool_t          HLT_DoubleMu2_Jpsi_DoubleTkMu0_Phi;
   Bool_t          HLT_DoubleMu3_DCA_PFMET50_PFMHT60;
   Bool_t          HLT_TripleMu_5_3_3_Mass3p8_DCA;
   Bool_t          HLT_QuadPFJet98_83_71_15_DoublePFBTagDeepCSV_1p3_7p7_VBF1;
   Bool_t          HLT_QuadPFJet103_88_75_15_DoublePFBTagDeepCSV_1p3_7p7_VBF1;
   Bool_t          HLT_QuadPFJet111_90_80_15_DoublePFBTagDeepCSV_1p3_7p7_VBF1;
   Bool_t          HLT_QuadPFJet98_83_71_15_PFBTagDeepCSV_1p3_VBF2;
   Bool_t          HLT_QuadPFJet103_88_75_15_PFBTagDeepCSV_1p3_VBF2;
   Bool_t          HLT_QuadPFJet105_88_76_15_PFBTagDeepCSV_1p3_VBF2;
   Bool_t          HLT_QuadPFJet111_90_80_15_PFBTagDeepCSV_1p3_VBF2;
   Bool_t          HLT_QuadPFJet98_83_71_15;
   Bool_t          HLT_QuadPFJet103_88_75_15;
   Bool_t          HLT_QuadPFJet105_88_76_15;
   Bool_t          HLT_QuadPFJet111_90_80_15;
   Bool_t          HLT_AK8PFJet330_TrimMass30_PFAK8BTagDeepCSV_p17;
   Bool_t          HLT_AK8PFJet330_TrimMass30_PFAK8BTagDeepCSV_p1;
   Bool_t          HLT_AK8PFJet330_TrimMass30_PFAK8BoostedDoubleB_p02;
   Bool_t          HLT_AK8PFJet330_TrimMass30_PFAK8BoostedDoubleB_np2;
   Bool_t          HLT_AK8PFJet330_TrimMass30_PFAK8BoostedDoubleB_np4;
   Bool_t          HLT_Diphoton30_18_R9IdL_AND_HE_AND_IsoCaloId_NoPixelVeto_Mass55;
   Bool_t          HLT_Diphoton30_18_R9IdL_AND_HE_AND_IsoCaloId_NoPixelVeto;
   Bool_t          HLT_Mu12_IP6_ToCSCS;
   Bool_t          HLT_Mu12_IP6_part0;
   Bool_t          HLT_Mu12_IP6_part1;
   Bool_t          HLT_Mu12_IP6_part2;
   Bool_t          HLT_Mu12_IP6_part3;
   Bool_t          HLT_Mu12_IP6_part4;
   Bool_t          HLT_Mu9_IP5_ToCSCS;
   Bool_t          HLT_Mu9_IP5_part0;
   Bool_t          HLT_Mu9_IP5_part1;
   Bool_t          HLT_Mu9_IP5_part2;
   Bool_t          HLT_Mu9_IP5_part3;
   Bool_t          HLT_Mu9_IP5_part4;
   Bool_t          HLT_Mu7_IP4_ToCSCS;
   Bool_t          HLT_Mu7_IP4_part0;
   Bool_t          HLT_Mu7_IP4_part1;
   Bool_t          HLT_Mu7_IP4_part2;
   Bool_t          HLT_Mu7_IP4_part3;
   Bool_t          HLT_Mu7_IP4_part4;
   Bool_t          HLT_Mu9_IP4_ToCSCS;
   Bool_t          HLT_Mu9_IP4_part0;
   Bool_t          HLT_Mu9_IP4_part1;
   Bool_t          HLT_Mu9_IP4_part2;
   Bool_t          HLT_Mu9_IP4_part3;
   Bool_t          HLT_Mu9_IP4_part4;
   Bool_t          HLT_Mu8_IP5_ToCSCS;
   Bool_t          HLT_Mu8_IP5_part0;
   Bool_t          HLT_Mu8_IP5_part1;
   Bool_t          HLT_Mu8_IP5_part2;
   Bool_t          HLT_Mu8_IP5_part3;
   Bool_t          HLT_Mu8_IP5_part4;
   Bool_t          HLT_Mu8_IP6_ToCSCS;
   Bool_t          HLT_Mu8_IP6_part0;
   Bool_t          HLT_Mu8_IP6_part1;
   Bool_t          HLT_Mu8_IP6_part2;
   Bool_t          HLT_Mu8_IP6_part3;
   Bool_t          HLT_Mu8_IP6_part4;
   Bool_t          HLT_Mu9_IP6_ToCSCS;
   Bool_t          HLT_Mu9_IP6_part0;
   Bool_t          HLT_Mu9_IP6_part1;
   Bool_t          HLT_Mu9_IP6_part2;
   Bool_t          HLT_Mu9_IP6_part3;
   Bool_t          HLT_Mu9_IP6_part4;
   Bool_t          HLT_Mu8_IP3_ToCSCS;
   Bool_t          HLT_Mu8_IP3_part0;
   Bool_t          HLT_Mu8_IP3_part1;
   Bool_t          HLT_Mu8_IP3_part2;
   Bool_t          HLT_Mu8_IP3_part3;
   Bool_t          HLT_Mu8_IP3_part4;
   Bool_t          HLT_Mu9_IP0_part0;
   Bool_t          HLT_Mu9_IP3_part0;
   Bool_t          HLT_QuadPFJet105_88_76_15_DoublePFBTagDeepCSV_1p3_7p7_VBF1;
   Bool_t          HLT_TrkMu6NoFiltersNoVtx;
   Bool_t          HLT_TrkMu16NoFiltersNoVtx;
   Bool_t          HLT_DoubleTrkMu_16_6_NoFiltersNoVtx;
   Bool_t          HLT_PPSMaxTracksPerArm1;
   Bool_t          HLT_PPSMaxTracksPerRP4;
   Bool_t          HLTriggerFinalPath;

   // Pointers to branches
   map<string, const Bool_t *> mtrg;

   // List of branches
   TBranch        *b_run;   //!
   TBranch        *b_luminosityBlock;   //!
   TBranch        *b_event;   //!
   TBranch        *b_bunchCrossing;   //!
   TBranch        *b_HTXS_Higgs_pt;   //!
   TBranch        *b_HTXS_Higgs_y;   //!
   TBranch        *b_HTXS_stage1_1_cat_pTjet25GeV;   //!
   TBranch        *b_HTXS_stage1_1_cat_pTjet30GeV;   //!
   TBranch        *b_HTXS_stage1_1_fine_cat_pTjet25GeV;   //!
   TBranch        *b_HTXS_stage1_1_fine_cat_pTjet30GeV;   //!
   TBranch        *b_HTXS_stage1_2_cat_pTjet25GeV;   //!
   TBranch        *b_HTXS_stage1_2_cat_pTjet30GeV;   //!
   TBranch        *b_HTXS_stage1_2_fine_cat_pTjet25GeV;   //!
   TBranch        *b_HTXS_stage1_2_fine_cat_pTjet30GeV;   //!
   TBranch        *b_HTXS_stage_0;   //!
   TBranch        *b_HTXS_stage_1_pTjet25;   //!
   TBranch        *b_HTXS_stage_1_pTjet30;   //!
   TBranch        *b_HTXS_njets25;   //!
   TBranch        *b_HTXS_njets30;   //!
  //TBranch        *b_BeamSpot_sigmaZ;   //!
  //TBranch        *b_BeamSpot_sigmaZError;   //!
  //TBranch        *b_BeamSpot_z;   //!
  //TBranch        *b_BeamSpot_zError;   //!
  //TBranch        *b_BeamSpot_type;   //!
  //TBranch        *b_btagWeight_CSVV2;   //!
  //TBranch        *b_btagWeight_DeepCSVB;   //!
   TBranch        *b_CaloMET_phi;   //!
   TBranch        *b_CaloMET_pt;   //!
   TBranch        *b_CaloMET_sumEt;   //!
   TBranch        *b_ChsMET_phi;   //!
   TBranch        *b_ChsMET_pt;   //!
   TBranch        *b_ChsMET_sumEt;   //!
   TBranch        *b_nCorrT1METJet;   //!
   TBranch        *b_CorrT1METJet_area;   //!
   TBranch        *b_CorrT1METJet_eta;   //!
   TBranch        *b_CorrT1METJet_muonSubtrFactor;   //!
   TBranch        *b_CorrT1METJet_phi;   //!
   TBranch        *b_CorrT1METJet_rawPt;   //!
   TBranch        *b_DeepMETResolutionTune_phi;   //!
   TBranch        *b_DeepMETResolutionTune_pt;   //!
   TBranch        *b_DeepMETResponseTune_phi;   //!
   TBranch        *b_DeepMETResponseTune_pt;   //!
   TBranch        *b_nElectron;   //!
   TBranch        *b_Electron_deltaEtaSC;   //!
   TBranch        *b_Electron_dr03EcalRecHitSumEt;   //!
   TBranch        *b_Electron_dr03HcalDepth1TowerSumEt;   //!
   TBranch        *b_Electron_dr03TkSumPt;   //!
   TBranch        *b_Electron_dr03TkSumPtHEEP;   //!
   TBranch        *b_Electron_dxy;   //!
   TBranch        *b_Electron_dxyErr;   //!
   TBranch        *b_Electron_dz;   //!
   TBranch        *b_Electron_dzErr;   //!
   TBranch        *b_Electron_eInvMinusPInv;   //!
   TBranch        *b_Electron_energyErr;   //!
   TBranch        *b_Electron_eta;   //!
   TBranch        *b_Electron_hoe;   //!
   TBranch        *b_Electron_ip3d;   //!
   TBranch        *b_Electron_jetPtRelv2;   //!
   TBranch        *b_Electron_jetRelIso;   //!
   TBranch        *b_Electron_mass;   //!
   TBranch        *b_Electron_miniPFRelIso_all;   //!
   TBranch        *b_Electron_miniPFRelIso_chg;   //!
  //TBranch        *b_Electron_mvaHZZIso;   //!
  //TBranch        *b_Electron_mvaIso;   //!
  //TBranch        *b_Electron_mvaNoIso;   //!
   TBranch        *b_Electron_pfRelIso03_all;   //!
   TBranch        *b_Electron_pfRelIso03_chg;   //!
   TBranch        *b_Electron_phi;   //!
   TBranch        *b_Electron_pt;   //!
   TBranch        *b_Electron_r9;   //!
   TBranch        *b_Electron_scEtOverPt;   //!
   TBranch        *b_Electron_sieie;   //!
   TBranch        *b_Electron_sip3d;   //!
   TBranch        *b_Electron_mvaTTH;   //!
   TBranch        *b_Electron_charge;   //!
   TBranch        *b_Electron_cutBased;   //!
   TBranch        *b_Electron_jetIdx;   //!
   TBranch        *b_Electron_pdgId;   //!
   TBranch        *b_Electron_photonIdx;   //!
   TBranch        *b_Electron_tightCharge;   //!
   TBranch        *b_Electron_vidNestedWPBitmap;   //!
   TBranch        *b_Electron_vidNestedWPBitmapHEEP;   //!
   TBranch        *b_Electron_fsrPhotonIdx;   //!
   TBranch        *b_Electron_convVeto;   //!
   TBranch        *b_Electron_cutBased_HEEP;   //!
   TBranch        *b_Electron_isPFcand;   //!
   TBranch        *b_Electron_jetNDauCharged;   //!
   TBranch        *b_Electron_lostHits;   //!
  //TBranch        *b_Electron_mvaIso_WP80;   //!
  //TBranch        *b_Electron_mvaIso_WP90;   //!
  //TBranch        *b_Electron_mvaIso_WPL;   //!
  //TBranch        *b_Electron_mvaNoIso_WP80;   //!
  //TBranch        *b_Electron_mvaNoIso_WP90;   //!
  //TBranch        *b_Electron_mvaNoIso_WPL;   //!
   TBranch        *b_Electron_seedGain;   //!

   TBranch        *b_nFsrPhoton;   //!
   TBranch        *b_FsrPhoton_dROverEt2;   //!
   TBranch        *b_FsrPhoton_eta;   //!
   TBranch        *b_FsrPhoton_phi;   //!
   TBranch        *b_FsrPhoton_pt;   //!
   TBranch        *b_FsrPhoton_relIso03;   //!
  //TBranch        *b_FsrPhoton_electronIdx;   //!
   TBranch        *b_FsrPhoton_muonIdx;   //!
   TBranch        *b_nGenJetAK8;   //!
   TBranch        *b_GenJetAK8_eta;   //!
   TBranch        *b_GenJetAK8_mass;   //!
   TBranch        *b_GenJetAK8_phi;   //!
   TBranch        *b_GenJetAK8_pt;   //!
  //TBranch        *b_GenJetAK8_nConstituents;   //!
   TBranch        *b_nGenJet;   //!
   TBranch        *b_GenJet_eta;   //!
   TBranch        *b_GenJet_mass;   //!
   TBranch        *b_GenJet_phi;   //!
   TBranch        *b_GenJet_pt;   //!
  //TBranch        *b_GenJet_nConstituents;   //!
   TBranch        *b_nGenPart;   //!
   TBranch        *b_GenPart_eta;   //!
   TBranch        *b_GenPart_mass;   //!
   TBranch        *b_GenPart_phi;   //!
   TBranch        *b_GenPart_pt;   //!
   TBranch        *b_GenPart_genPartIdxMother;   //!
   TBranch        *b_GenPart_pdgId;   //!
   TBranch        *b_GenPart_status;   //!
   TBranch        *b_GenPart_statusFlags;   //!
  //TBranch        *b_nGenProton;   //!
  //TBranch        *b_GenProton_px;   //!
  //TBranch        *b_GenProton_py;   //!
  //TBranch        *b_GenProton_pz;   //!
  //TBranch        *b_GenProton_vz;   //!
  //TBranch        *b_GenProton_isPU;   //!
   TBranch        *b_nSubGenJetAK8;   //!
   TBranch        *b_SubGenJetAK8_eta;   //!
   TBranch        *b_SubGenJetAK8_mass;   //!
   TBranch        *b_SubGenJetAK8_phi;   //!
   TBranch        *b_SubGenJetAK8_pt;   //!
   TBranch        *b_Generator_binvar;   //!
   TBranch        *b_LHE_HT; // added by hand
   TBranch        *b_Generator_scalePDF;   //!
   TBranch        *b_Generator_weight;   //!
   TBranch        *b_Generator_x1;   //!
   TBranch        *b_Generator_x2;   //!
   TBranch        *b_Generator_xpdf1;   //!
   TBranch        *b_Generator_xpdf2;   //!
   TBranch        *b_Generator_id1;   //!
   TBranch        *b_Generator_id2;   //!
   TBranch        *b_GenVtx_x;   //!
   TBranch        *b_GenVtx_y;   //!
   TBranch        *b_GenVtx_z;   //!
   TBranch        *b_nGenVisTau;   //!
   TBranch        *b_GenVisTau_eta;   //!
   TBranch        *b_GenVisTau_mass;   //!
   TBranch        *b_GenVisTau_phi;   //!
   TBranch        *b_GenVisTau_pt;   //!
   TBranch        *b_GenVisTau_charge;   //!
   TBranch        *b_GenVisTau_genPartIdxMother;   //!
   TBranch        *b_GenVisTau_status;   //!
   TBranch        *b_genWeight;   //!
   TBranch        *b_nPSWeight;   //!
   TBranch        *b_PSWeight;   //!
   TBranch        *b_nIsoTrack;   //!
   TBranch        *b_IsoTrack_dxy;   //!
   TBranch        *b_IsoTrack_dz;   //!
   TBranch        *b_IsoTrack_eta;   //!
   TBranch        *b_IsoTrack_pfRelIso03_all;   //!
   TBranch        *b_IsoTrack_pfRelIso03_chg;   //!
   TBranch        *b_IsoTrack_phi;   //!
   TBranch        *b_IsoTrack_pt;   //!
   TBranch        *b_IsoTrack_miniPFRelIso_all;   //!
   TBranch        *b_IsoTrack_miniPFRelIso_chg;   //!
   TBranch        *b_IsoTrack_charge;   //!
   TBranch        *b_IsoTrack_fromPV;   //!
   TBranch        *b_IsoTrack_pdgId;   //!
   TBranch        *b_IsoTrack_isHighPurityTrack;   //!
   TBranch        *b_IsoTrack_isPFcand;   //!
   TBranch        *b_IsoTrack_isFromLostTrack;   //!

  //TBranch        *b_nGenJetAK8ForJEC;   //!
  //TBranch        *b_GenJetAK8ForJEC_eta;   //!
  //TBranch        *b_GenJetAK8ForJEC_mass;   //!
  //TBranch        *b_GenJetAK8ForJEC_phi;   //!
  //TBranch        *b_GenJetAK8ForJEC_pt;   //!
  //TBranch        *b_GenJetAK8ForJEC_nConstituents;   //!

   TBranch        *b_nJet;   //!
   TBranch        *b_Jet_area;   //!
   //   TBranch        *b_Jet_btagCSVV2;   //!
   //   TBranch        *b_Jet_btagDeepB;   //!
   //   TBranch        *b_Jet_btagDeepCvB;   //!
   //   TBranch        *b_Jet_btagDeepCvL;   //!
   TBranch        *b_Jet_btagDeepFlavB;   //!
   TBranch        *b_Jet_btagDeepFlavCvB;   //!
   TBranch        *b_Jet_btagDeepFlavCvL;   //!
   //   TBranch        *b_Jet_btagDeepFlavG;   //!
   TBranch        *b_Jet_btagDeepFlavQG;   //!
   //   TBranch        *b_Jet_btagDeepFlavUDS;   //!
   TBranch        *b_Jet_chEmEF;   //!
   TBranch        *b_Jet_chHEF;   //!
   TBranch        *b_Jet_eta;   //!
   //   TBranch        *b_Jet_hfEmEF;   //!
   //   TBranch        *b_Jet_hfHEF;   //!
   TBranch        *b_Jet_hfsigmaEtaEta;   //!
   TBranch        *b_Jet_hfsigmaPhiPhi;   //!
   TBranch        *b_Jet_mass;   //!
   TBranch        *b_Jet_muEF;   //!
   TBranch        *b_Jet_muonSubtrFactor;   //!
   TBranch        *b_Jet_neEmEF;   //!
   TBranch        *b_Jet_neHEF;   //!
   //   TBranch        *b_Jet_particleNetAK4_B;   //!
   //   TBranch        *b_Jet_particleNetAK4_CvsB;   //!
   //   TBranch        *b_Jet_particleNetAK4_CvsL;   //!
   //   TBranch        *b_Jet_particleNetAK4_QvsG;   //!
   //   TBranch        *b_Jet_particleNetAK4_puIdDisc;   //!
   TBranch        *b_Jet_phi;   //!
   TBranch        *b_Jet_pt;   //!
   //   TBranch        *b_Jet_puId_beta;   //!
   //   TBranch        *b_Jet_puId_dR2Mean;   //!
   //   TBranch        *b_Jet_puId_frac01;   //!
   //   TBranch        *b_Jet_puId_frac02;   //!
   //   TBranch        *b_Jet_puId_frac03;   //!
   //   TBranch        *b_Jet_puId_frac04;   //!
   //   TBranch        *b_Jet_puId_jetR;   //!
   //   TBranch        *b_Jet_puId_jetRchg;   //!
   //   TBranch        *b_Jet_puId_majW;   //!
   //   TBranch        *b_Jet_puId_minW;   //!
   //   TBranch        *b_Jet_puId_ptD;   //!
   //   TBranch        *b_Jet_puId_pull;   //!
   //   TBranch        *b_Jet_qgl_axis2;   //!
   //   TBranch        *b_Jet_qgl_ptD;   //!
   TBranch        *b_Jet_rawFactor;   //!
   TBranch        *PNetRegPtRawCorr;   //!
   TBranch        *PNetRegPtResCorrNeutrino;   //!
   TBranch        *b_Jet_electronIdx1;   //!
   TBranch        *b_Jet_electronIdx2;   //!
   TBranch        *b_Jet_hfadjacentEtaStripsSize;   //!
   TBranch        *b_Jet_hfcentralEtaStripSize;   //!
   TBranch        *b_Jet_jetId;   //!
   TBranch        *b_Jet_muonIdx1;   //!
   TBranch        *b_Jet_muonIdx2;   //!
   //   TBranch        *b_Jet_nConstChHads;   //!
   //   TBranch        *b_Jet_nConstElecs;   //!
   //   TBranch        *b_Jet_nConstHFEMs;   //!
   //   TBranch        *b_Jet_nConstHFHads;   //!
   //   TBranch        *b_Jet_nConstMuons;   //!
   //   TBranch        *b_Jet_nConstNeuHads;   //!
   //   TBranch        *b_Jet_nConstPhotons;   //!
   TBranch        *b_Jet_nElectrons;   //!
   TBranch        *b_Jet_nMuons;   //!
   //   TBranch        *b_Jet_puId_nCharged;   //!
   //   TBranch        *b_Jet_qgl_mult;   //!
   TBranch        *b_Jet_nConstituents;   //!
   TBranch        *b_nJetCHS;   //!
   TBranch        *b_JetCHS_area;   //!
   TBranch        *b_JetCHS_btagCSVV2;   //!
   TBranch        *b_JetCHS_btagDeepB;   //!
   TBranch        *b_JetCHS_btagDeepCvB;   //!
   TBranch        *b_JetCHS_btagDeepCvL;   //!
   TBranch        *b_JetCHS_btagDeepFlavB;   //!
   TBranch        *b_JetCHS_btagDeepFlavCvB;   //!
   TBranch        *b_JetCHS_btagDeepFlavCvL;   //!
   TBranch        *b_JetCHS_btagDeepFlavG;   //!
   TBranch        *b_JetCHS_btagDeepFlavQG;   //!
   TBranch        *b_JetCHS_btagDeepFlavUDS;   //!
   TBranch        *b_JetCHS_chEmEF;   //!
   TBranch        *b_JetCHS_chFPV0EF;   //!
   TBranch        *b_JetCHS_chFPV1EF;   //!
   TBranch        *b_JetCHS_chFPV2EF;   //!
   TBranch        *b_JetCHS_chFPV3EF;   //!
   TBranch        *b_JetCHS_chHEF;   //!
   TBranch        *b_JetCHS_eta;   //!
   TBranch        *b_JetCHS_hfEmEF;   //!
   TBranch        *b_JetCHS_hfHEF;   //!
   TBranch        *b_JetCHS_hfsigmaEtaEta;   //!
   TBranch        *b_JetCHS_hfsigmaPhiPhi;   //!
   TBranch        *b_JetCHS_mass;   //!
   TBranch        *b_JetCHS_muEF;   //!
   TBranch        *b_JetCHS_muonSubtrFactor;   //!
   TBranch        *b_JetCHS_neEmEF;   //!
   TBranch        *b_JetCHS_neHEF;   //!
   TBranch        *b_JetCHS_particleNetAK4_B;   //!
   TBranch        *b_JetCHS_particleNetAK4_CvsB;   //!
   TBranch        *b_JetCHS_particleNetAK4_CvsL;   //!
   TBranch        *b_JetCHS_particleNetAK4_QvsG;   //!
   TBranch        *b_JetCHS_particleNetAK4_puIdDisc;   //!
   TBranch        *b_JetCHS_phi;   //!
   TBranch        *b_JetCHS_pt;   //!
   TBranch        *b_JetCHS_puIdDisc;   //!
   TBranch        *b_JetCHS_puId_beta;   //!
   TBranch        *b_JetCHS_puId_dR2Mean;   //!
   TBranch        *b_JetCHS_puId_frac01;   //!
   TBranch        *b_JetCHS_puId_frac02;   //!
   TBranch        *b_JetCHS_puId_frac03;   //!
   TBranch        *b_JetCHS_puId_frac04;   //!
   TBranch        *b_JetCHS_puId_jetR;   //!
   TBranch        *b_JetCHS_puId_jetRchg;   //!
   TBranch        *b_JetCHS_puId_majW;   //!
   TBranch        *b_JetCHS_puId_minW;   //!
   TBranch        *b_JetCHS_puId_ptD;   //!
   TBranch        *b_JetCHS_puId_pull;   //!
   TBranch        *b_JetCHS_qgl;   //!
   TBranch        *b_JetCHS_qgl_axis2;   //!
   TBranch        *b_JetCHS_qgl_ptD;   //!
   TBranch        *b_JetCHS_rawFactor;   //!
   TBranch        *b_JetCHS_electronIdx1;   //!
   TBranch        *b_JetCHS_electronIdx2;   //!
   TBranch        *b_JetCHS_hfadjacentEtaStripsSize;   //!
   TBranch        *b_JetCHS_hfcentralEtaStripSize;   //!
   TBranch        *b_JetCHS_jetId;   //!
   TBranch        *b_JetCHS_muonIdx1;   //!
   TBranch        *b_JetCHS_muonIdx2;   //!
   TBranch        *b_JetCHS_nConstChHads;   //!
   TBranch        *b_JetCHS_nConstElecs;   //!
   TBranch        *b_JetCHS_nConstHFEMs;   //!
   TBranch        *b_JetCHS_nConstHFHads;   //!
   TBranch        *b_JetCHS_nConstMuons;   //!
   TBranch        *b_JetCHS_nConstNeuHads;   //!
   TBranch        *b_JetCHS_nConstPhotons;   //!
   TBranch        *b_JetCHS_nElectrons;   //!
   TBranch        *b_JetCHS_nMuons;   //!
   TBranch        *b_JetCHS_puId;   //!
   TBranch        *b_JetCHS_puId_nCharged;   //!
   TBranch        *b_JetCHS_qgl_mult;   //!
   TBranch        *b_JetCHS_nConstituents;   //!
   //   TBranch        *b_L1PreFiringWeight_Dn;   //!
   //   TBranch        *b_L1PreFiringWeight_ECAL_Dn;   //!
   //   TBranch        *b_L1PreFiringWeight_ECAL_Nom;   //!
   //   TBranch        *b_L1PreFiringWeight_ECAL_Up;   //!
   //   TBranch        *b_L1PreFiringWeight_Muon_Nom;   //!
   //   TBranch        *b_L1PreFiringWeight_Muon_StatDn;   //!
   //   TBranch        *b_L1PreFiringWeight_Muon_StatUp;   //!
   //   TBranch        *b_L1PreFiringWeight_Muon_SystDn;   //!
   //   TBranch        *b_L1PreFiringWeight_Muon_SystUp;   //!
   //   TBranch        *b_L1PreFiringWeight_Nom;   //!
   //   TBranch        *b_L1PreFiringWeight_Up;   //!
   TBranch        *b_nLowPtElectron;   //!
   TBranch        *b_LowPtElectron_ID;   //!
   TBranch        *b_LowPtElectron_convVtxRadius;   //!
   TBranch        *b_LowPtElectron_deltaEtaSC;   //!
   TBranch        *b_LowPtElectron_dxy;   //!
   TBranch        *b_LowPtElectron_dxyErr;   //!
   TBranch        *b_LowPtElectron_dz;   //!
   TBranch        *b_LowPtElectron_dzErr;   //!
   TBranch        *b_LowPtElectron_eInvMinusPInv;   //!
   TBranch        *b_LowPtElectron_energyErr;   //!
   TBranch        *b_LowPtElectron_eta;   //!
   TBranch        *b_LowPtElectron_hoe;   //!
   TBranch        *b_LowPtElectron_mass;   //!
   TBranch        *b_LowPtElectron_miniPFRelIso_all;   //!
   TBranch        *b_LowPtElectron_miniPFRelIso_chg;   //!
   TBranch        *b_LowPtElectron_phi;   //!
   TBranch        *b_LowPtElectron_pt;   //!
   TBranch        *b_LowPtElectron_ptbiased;   //!
   TBranch        *b_LowPtElectron_r9;   //!
   TBranch        *b_LowPtElectron_scEtOverPt;   //!
   TBranch        *b_LowPtElectron_sieie;   //!
   TBranch        *b_LowPtElectron_unbiased;   //!
   TBranch        *b_LowPtElectron_charge;   //!
   TBranch        *b_LowPtElectron_convWP;   //!
  //TBranch        *b_LowPtElectron_electronIdx;   //!
   TBranch        *b_LowPtElectron_pdgId;   //!
   TBranch        *b_LowPtElectron_convVeto;   //!
   TBranch        *b_LowPtElectron_lostHits;   //!
   TBranch        *b_GenMET_phi;   //!
   TBranch        *b_GenMET_pt;   //!
   TBranch        *b_MET_MetUnclustEnUpDeltaX;   //!
   TBranch        *b_MET_MetUnclustEnUpDeltaY;   //!
   TBranch        *b_MET_covXX;   //!
   TBranch        *b_MET_covXY;   //!
   TBranch        *b_MET_covYY;   //!
   TBranch        *b_MET_phi;   //!
   TBranch        *b_MET_pt;   //!
   TBranch        *b_MET_significance;   //!
   TBranch        *b_MET_sumEt;   //!
   TBranch        *b_MET_sumPtUnclustered;   //!
   TBranch        *b_nMuon;   //!
   TBranch        *b_Muon_dxy;   //!
   TBranch        *b_Muon_dxyErr;   //!
   TBranch        *b_Muon_dxybs;   //!
   TBranch        *b_Muon_dz;   //!
   TBranch        *b_Muon_dzErr;   //!
   TBranch        *b_Muon_eta;   //!
   TBranch        *b_Muon_ip3d;   //!
   TBranch        *b_Muon_jetPtRelv2;   //!
   TBranch        *b_Muon_jetRelIso;   //!
   TBranch        *b_Muon_mass;   //!
   TBranch        *b_Muon_miniPFRelIso_all;   //!
   TBranch        *b_Muon_miniPFRelIso_chg;   //!
   TBranch        *b_Muon_pfRelIso03_all;   //!
   TBranch        *b_Muon_pfRelIso03_chg;   //!
   TBranch        *b_Muon_pfRelIso04_all;   //!
   TBranch        *b_Muon_phi;   //!
   TBranch        *b_Muon_pt;   //!
   TBranch        *b_Muon_ptErr;   //!
   TBranch        *b_Muon_segmentComp;   //!
   TBranch        *b_Muon_sip3d;   //!
   TBranch        *b_Muon_softMva;   //!
   TBranch        *b_Muon_tkRelIso;   //!
   TBranch        *b_Muon_tunepRelPt;   //!
   TBranch        *b_Muon_mvaLowPt;   //!
   TBranch        *b_Muon_mvaTTH;   //!
   TBranch        *b_Muon_charge;   //!
   TBranch        *b_Muon_jetIdx;   //!
   TBranch        *b_Muon_nStations;   //!
   TBranch        *b_Muon_nTrackerLayers;   //!
   TBranch        *b_Muon_pdgId;   //!
   TBranch        *b_Muon_tightCharge;   //!
   TBranch        *b_Muon_fsrPhotonIdx;   //!
   TBranch        *b_Muon_highPtId;   //!
   TBranch        *b_Muon_highPurity;   //!
   TBranch        *b_Muon_inTimeMuon;   //!
   TBranch        *b_Muon_isGlobal;   //!
   TBranch        *b_Muon_isPFcand;   //!
   TBranch        *b_Muon_isStandalone;   //!
   TBranch        *b_Muon_isTracker;   //!
   TBranch        *b_Muon_jetNDauCharged;   //!
   TBranch        *b_Muon_looseId;   //!
   TBranch        *b_Muon_mediumId;   //!
   TBranch        *b_Muon_mediumPromptId;   //!
   TBranch        *b_Muon_miniIsoId;   //!
   TBranch        *b_Muon_multiIsoId;   //!
   //   TBranch        *b_Muon_mvaId;   //!
   //   TBranch        *b_Muon_mvaLowPtId;   //!
   TBranch        *b_Muon_pfIsoId;   //!
   TBranch        *b_Muon_puppiIsoId;   //!
   TBranch        *b_Muon_softId;   //!
   TBranch        *b_Muon_softMvaId;   //!
   TBranch        *b_Muon_tightId;   //!
   TBranch        *b_Muon_tkIsoId;   //!
   TBranch        *b_Muon_triggerIdLoose;   //!
   TBranch        *b_nPhoton;   //!
   //   TBranch        *b_Photon_dEscaleDown;   //!
   //   TBranch        *b_Photon_dEscaleUp;   //!
   //   TBranch        *b_Photon_dEsigmaDown;   //!
   //   TBranch        *b_Photon_dEsigmaUp;   //!
   //   TBranch        *b_Photon_eCorr;   //!
   TBranch        *b_Photon_energyErr;   //!
  //TBranch        *b_Photon_energyRaw;   //!
  //TBranch        *b_Photon_esEffSigmaRR;   //!
  //TBranch        *b_Photon_esEnergyOverRawE;   //!
   TBranch        *b_Photon_eta;   //!
  //TBranch        *b_Photon_etaWidth;   //!
  //TBranch        *b_Photon_haloTaggerMVAVal;   //!
   TBranch        *b_Photon_hoe;   //!
   TBranch        *b_Photon_mvaID;   //!
  //TBranch        *b_Photon_pfChargedIsoPFPV;   //!
  //TBranch        *b_Photon_pfChargedIsoWorstVtx;   //!
  //TBranch        *b_Photon_pfPhoIso03;   //!
   //   TBranch        *b_Photon_pfRelIso03_all;   //!
   //   TBranch        *b_Photon_pfRelIso03_chg;   //!
   TBranch        *b_Photon_phi;   //!
  //TBranch        *b_Photon_phiWidth;   //!
   TBranch        *b_Photon_pt;   //!
   TBranch        *b_Photon_r9;   //!
  //TBranch        *b_Photon_s4;   //!
   TBranch        *b_Photon_sieie;   //!
  //TBranch        *b_Photon_sieip;   //!
  //TBranch        *b_Photon_sipip;   //!
  //TBranch        *b_Photon_x_calo;   //!
  //TBranch        *b_Photon_y_calo;   //!
  //TBranch        *b_Photon_z_calo;   //!
   TBranch        *b_Photon_cutBased;   //!
   //   TBranch        *b_Photon_cutBased_Fall17V1Bitmap;   //!
   TBranch        *b_Photon_electronIdx;   //!
   TBranch        *b_Photon_jetIdx;   //!
   TBranch        *b_Photon_vidNestedWPBitmap;   //!
   TBranch        *b_Photon_electronVeto;   //!
   TBranch        *b_Photon_isScEtaEB;   //!
   TBranch        *b_Photon_isScEtaEE;   //!
   TBranch        *b_Photon_mvaID_WP80;   //!
   TBranch        *b_Photon_mvaID_WP90;   //!
   TBranch        *b_Photon_pixelSeed;   //!
   TBranch        *b_Photon_seedGain;   //!
   TBranch        *b_Pileup_nTrueInt;   //!
   TBranch        *b_Pileup_pudensity;   //!
   TBranch        *b_Pileup_gpudensity;   //!
   TBranch        *b_Pileup_pthatmax;   //!
   TBranch        *b_Pileup_nPU;   //!
   TBranch        *b_Pileup_sumEOOT;   //!
   TBranch        *b_Pileup_sumLOOT;   //!
   TBranch        *b_PuppiMET_phi;   //!
   TBranch        *b_PuppiMET_phiJERDown;   //!
   TBranch        *b_PuppiMET_phiJERUp;   //!
   TBranch        *b_PuppiMET_phiJESDown;   //!
   TBranch        *b_PuppiMET_phiJESUp;   //!
   TBranch        *b_PuppiMET_phiUnclusteredDown;   //!
   TBranch        *b_PuppiMET_phiUnclusteredUp;   //!
   TBranch        *b_PuppiMET_pt;   //!
   TBranch        *b_PuppiMET_ptJERDown;   //!
   TBranch        *b_PuppiMET_ptJERUp;   //!
   TBranch        *b_PuppiMET_ptJESDown;   //!
   TBranch        *b_PuppiMET_ptJESUp;   //!
   TBranch        *b_PuppiMET_ptUnclusteredDown;   //!
   TBranch        *b_PuppiMET_ptUnclusteredUp;   //!
   TBranch        *b_PuppiMET_sumEt;   //!
   TBranch        *b_RawMET_phi;   //!
   TBranch        *b_RawMET_pt;   //!
   TBranch        *b_RawMET_sumEt;   //!
   TBranch        *b_RawPuppiMET_phi;   //!
   TBranch        *b_RawPuppiMET_pt;   //!
   TBranch        *b_RawPuppiMET_sumEt;   //!
   TBranch        *b_Rho_fixedGridRhoAll;   //!
   TBranch        *b_Rho_fixedGridRhoFastjetAll;   //!
   TBranch        *b_Rho_fixedGridRhoFastjetCentral;   //!
   TBranch        *b_Rho_fixedGridRhoFastjetCentralCalo;   //!
   TBranch        *b_Rho_fixedGridRhoFastjetCentralChargedPileUp;   //!
   TBranch        *b_Rho_fixedGridRhoFastjetCentralNeutral;   //!
   TBranch        *b_nGenDressedLepton;   //!
   TBranch        *b_GenDressedLepton_eta;   //!
   TBranch        *b_GenDressedLepton_mass;   //!
   TBranch        *b_GenDressedLepton_phi;   //!
   TBranch        *b_GenDressedLepton_pt;   //!
   TBranch        *b_GenDressedLepton_pdgId;   //!
   TBranch        *b_GenDressedLepton_hasTauAnc;   //!
   TBranch        *b_nGenIsolatedPhoton;   //!
   TBranch        *b_GenIsolatedPhoton_eta;   //!
   TBranch        *b_GenIsolatedPhoton_mass;   //!
   TBranch        *b_GenIsolatedPhoton_phi;   //!
   TBranch        *b_GenIsolatedPhoton_pt;   //!
   TBranch        *b_nSoftActivityJet;   //!
   TBranch        *b_SoftActivityJet_eta;   //!
   TBranch        *b_SoftActivityJet_phi;   //!
   TBranch        *b_SoftActivityJet_pt;   //!
   TBranch        *b_SoftActivityJetHT;   //!
   TBranch        *b_SoftActivityJetHT10;   //!
   TBranch        *b_SoftActivityJetHT2;   //!
   TBranch        *b_SoftActivityJetHT5;   //!
   TBranch        *b_SoftActivityJetNjets10;   //!
   TBranch        *b_SoftActivityJetNjets2;   //!
   TBranch        *b_SoftActivityJetNjets5;   //!
   TBranch        *b_nSubJet;   //!
   //   TBranch        *b_SubJet_btagCSVV2;   //!
   TBranch        *b_SubJet_btagDeepB;   //!
   TBranch        *b_SubJet_eta;   //!
   TBranch        *b_SubJet_mass;   //!
   TBranch        *b_SubJet_n2b1;   //!
   TBranch        *b_SubJet_n3b1;   //!
   TBranch        *b_SubJet_phi;   //!
   TBranch        *b_SubJet_pt;   //!
   TBranch        *b_SubJet_rawFactor;   //!
   TBranch        *b_SubJet_tau1;   //!
   TBranch        *b_SubJet_tau2;   //!
   TBranch        *b_SubJet_tau3;   //!
   TBranch        *b_SubJet_tau4;   //!
   TBranch        *b_nTau;   //!
   TBranch        *b_Tau_chargedIso;   //!
   TBranch        *b_Tau_dxy;   //!
   TBranch        *b_Tau_dz;   //!
   TBranch        *b_Tau_eta;   //!
   TBranch        *b_Tau_leadTkDeltaEta;   //!
   TBranch        *b_Tau_leadTkDeltaPhi;   //!
   TBranch        *b_Tau_leadTkPtOverTauPt;   //!
   TBranch        *b_Tau_mass;   //!
   TBranch        *b_Tau_neutralIso;   //!
   TBranch        *b_Tau_phi;   //!
   TBranch        *b_Tau_photonsOutsideSignalCone;   //!
   TBranch        *b_Tau_pt;   //!
   TBranch        *b_Tau_puCorr;   //!
  //TBranch        *b_Tau_rawDeepTau2017v2p1VSe;   //!
  //TBranch        *b_Tau_rawDeepTau2017v2p1VSjet;   //!
  //TBranch        *b_Tau_rawDeepTau2017v2p1VSmu;   //!
  //TBranch        *b_Tau_rawDeepTau2018v2p5VSe;   //!
  //TBranch        *b_Tau_rawDeepTau2018v2p5VSjet;   //!
  //TBranch        *b_Tau_rawDeepTau2018v2p5VSmu;   //!
   TBranch        *b_Tau_rawIso;   //!
   TBranch        *b_Tau_rawIsodR03;   //!
   TBranch        *b_Tau_charge;   //!
   TBranch        *b_Tau_decayMode;   //!
   TBranch        *b_Tau_jetIdx;   //!
   TBranch        *b_Tau_idAntiEleDeadECal;   //!
   TBranch        *b_Tau_idAntiMu;   //!
   TBranch        *b_Tau_idDecayModeOldDMs;   //!
  //TBranch        *b_Tau_idDeepTau2017v2p1VSe;   //!
  //TBranch        *b_Tau_idDeepTau2017v2p1VSjet;   //!
  //TBranch        *b_Tau_idDeepTau2017v2p1VSmu;   //!
  //TBranch        *b_Tau_idDeepTau2018v2p5VSe;   //!
  //TBranch        *b_Tau_idDeepTau2018v2p5VSjet;   //!
  //TBranch        *b_Tau_idDeepTau2018v2p5VSmu;   //!
   TBranch        *b_TkMET_phi;   //!
   TBranch        *b_TkMET_pt;   //!
   TBranch        *b_TkMET_sumEt;   //!
   TBranch        *b_nTrigObj;   //!
   TBranch        *b_TrigObj_pt;   //!
   TBranch        *b_TrigObj_eta;   //!
   TBranch        *b_TrigObj_phi;   //!
   TBranch        *b_TrigObj_l1pt;   //!
   TBranch        *b_TrigObj_l1pt_2;   //!
   TBranch        *b_TrigObj_l2pt;   //!
   TBranch        *b_TrigObj_id;   //!
   TBranch        *b_TrigObj_l1iso;   //!
   TBranch        *b_TrigObj_l1charge;   //!
   TBranch        *b_TrigObj_filterBits;   //!
   TBranch        *b_genTtbarId;   //!
   TBranch        *b_nOtherPV;   //!
   TBranch        *b_OtherPV_z;   //!
  //TBranch        *b_OtherPV_score;   //!
   TBranch        *b_PV_ndof;   //!
   TBranch        *b_PV_x;   //!
   TBranch        *b_PV_y;   //!
   TBranch        *b_PV_z;   //!
   TBranch        *b_PV_chi2;   //!
   TBranch        *b_PV_score;   //!
   TBranch        *b_PV_npvs;   //!
   TBranch        *b_PV_npvsGood;   //!
   TBranch        *b_nSV;   //!
   TBranch        *b_SV_dlen;   //!
   TBranch        *b_SV_dlenSig;   //!
   TBranch        *b_SV_dxy;   //!
   TBranch        *b_SV_dxySig;   //!
   TBranch        *b_SV_pAngle;   //!
   TBranch        *b_SV_charge;   //!
   TBranch        *b_Electron_genPartIdx;   //!
   TBranch        *b_Electron_genPartFlav;   //!

   TBranch        *b_GenJetAK8_partonFlavour;   //!
   TBranch        *b_GenJetAK8_hadronFlavour;   //!
  //TBranch        *b_GenJetAK8ForJEC_partonFlavour;   //!
  //TBranch        *b_GenJetAK8ForJEC_hadronFlavour;   //!
   TBranch        *b_GenJet_partonFlavour;   //!
   TBranch        *b_GenJet_hadronFlavour;   //!
   TBranch        *b_GenVtx_t0;   //!

   TBranch        *b_JetCHS_genJetIdx;   //!
   TBranch        *b_JetCHS_hadronFlavour;   //!
   TBranch        *b_JetCHS_partonFlavour;   //!

   TBranch        *b_Jet_genJetIdx;   //!
   TBranch        *b_Jet_hadronFlavour;   //!
   TBranch        *b_Jet_partonFlavour;   //!
   TBranch        *b_LowPtElectron_genPartIdx;   //!
   TBranch        *b_LowPtElectron_genPartFlav;   //!
   TBranch        *b_Muon_genPartIdx;   //!
   TBranch        *b_Muon_genPartFlav;   //!
   TBranch        *b_Photon_genPartIdx;   //!
   TBranch        *b_Photon_genPartFlav;   //!
   TBranch        *b_MET_fiducialGenPhi;   //!
   TBranch        *b_MET_fiducialGenPt;   //!
   //   TBranch        *b_Electron_cleanmask;   //!
   //   TBranch        *b_Jet_cleanmask;   //!
  //TBranch        *b_LowPtElectron_cleanmask;   //!
   //   TBranch        *b_Muon_cleanmask;   //!
   //   TBranch        *b_Photon_cleanmask;   //!
   //   TBranch        *b_Tau_cleanmask;   //!
   TBranch        *b_SubJet_hadronFlavour;   //!
   TBranch        *b_SubJet_nBHadrons;   //!
   TBranch        *b_SubJet_nCHadrons;   //!
   TBranch        *b_SV_chi2;   //!
   TBranch        *b_SV_eta;   //!
   TBranch        *b_SV_mass;   //!
   TBranch        *b_SV_ndof;   //!
   TBranch        *b_SV_phi;   //!
   TBranch        *b_SV_pt;   //!
   TBranch        *b_SV_x;   //!
   TBranch        *b_SV_y;   //!
   TBranch        *b_SV_z;   //!
   TBranch        *b_SV_ntracks;   //!
   TBranch        *b_Tau_genPartIdx;   //!
   TBranch        *b_Tau_genPartFlav;   //!
   TBranch        *b_L1_AlwaysTrue;   //!
   TBranch        *b_L1_BPTX_AND_Ref1_VME;   //!
   TBranch        *b_L1_BPTX_AND_Ref3_VME;   //!
   TBranch        *b_L1_BPTX_AND_Ref4_VME;   //!
   TBranch        *b_L1_BPTX_BeamGas_B1_VME;   //!
   TBranch        *b_L1_BPTX_BeamGas_B2_VME;   //!
   TBranch        *b_L1_BPTX_BeamGas_Ref1_VME;   //!
   TBranch        *b_L1_BPTX_BeamGas_Ref2_VME;   //!
   TBranch        *b_L1_BPTX_NotOR_VME;   //!
   TBranch        *b_L1_BPTX_OR_Ref3_VME;   //!
   TBranch        *b_L1_BPTX_OR_Ref4_VME;   //!
   TBranch        *b_L1_BPTX_RefAND_VME;   //!
   TBranch        *b_L1_BptxMinus;   //!
   TBranch        *b_L1_BptxOR;   //!
   TBranch        *b_L1_BptxPlus;   //!
   TBranch        *b_L1_BptxXOR;   //!
   TBranch        *b_L1_CDC_SingleMu_3_er1p2_TOP120_DPHI2p618_3p142;   //!
   TBranch        *b_L1_DoubleEG8er2p5_HTT260er;   //!
   TBranch        *b_L1_DoubleEG8er2p5_HTT280er;   //!
   TBranch        *b_L1_DoubleEG8er2p5_HTT300er;   //!
   TBranch        *b_L1_DoubleEG8er2p5_HTT320er;   //!
   TBranch        *b_L1_DoubleEG8er2p5_HTT340er;   //!
   TBranch        *b_L1_DoubleEG_15_10_er2p5;   //!
   TBranch        *b_L1_DoubleEG_20_10_er2p5;   //!
   TBranch        *b_L1_DoubleEG_22_10_er2p5;   //!
   TBranch        *b_L1_DoubleEG_25_12_er2p5;   //!
   TBranch        *b_L1_DoubleEG_25_14_er2p5;   //!
   TBranch        *b_L1_DoubleEG_27_14_er2p5;   //!
   TBranch        *b_L1_DoubleEG_LooseIso20_10_er2p5;   //!
   TBranch        *b_L1_DoubleEG_LooseIso22_10_er2p5;   //!
   TBranch        *b_L1_DoubleEG_LooseIso22_12_er2p5;   //!
   TBranch        *b_L1_DoubleEG_LooseIso25_12_er2p5;   //!
   TBranch        *b_L1_DoubleIsoTau28er2p1;   //!
   TBranch        *b_L1_DoubleIsoTau28er2p1_Mass_Max80;   //!
   TBranch        *b_L1_DoubleIsoTau28er2p1_Mass_Max90;   //!
   TBranch        *b_L1_DoubleIsoTau30er2p1;   //!
   TBranch        *b_L1_DoubleIsoTau30er2p1_Mass_Max80;   //!
   TBranch        *b_L1_DoubleIsoTau30er2p1_Mass_Max90;   //!
   TBranch        *b_L1_DoubleIsoTau32er2p1;   //!
   TBranch        *b_L1_DoubleIsoTau34er2p1;   //!
   TBranch        *b_L1_DoubleIsoTau36er2p1;   //!
   TBranch        *b_L1_DoubleJet100er2p3_dEta_Max1p6;   //!
   TBranch        *b_L1_DoubleJet100er2p5;   //!
   TBranch        *b_L1_DoubleJet112er2p3_dEta_Max1p6;   //!
   TBranch        *b_L1_DoubleJet120er2p5;   //!
   TBranch        *b_L1_DoubleJet150er2p5;   //!
   TBranch        *b_L1_DoubleJet30er2p5_Mass_Min150_dEta_Max1p5;   //!
   TBranch        *b_L1_DoubleJet30er2p5_Mass_Min200_dEta_Max1p5;   //!
   TBranch        *b_L1_DoubleJet30er2p5_Mass_Min250_dEta_Max1p5;   //!
   TBranch        *b_L1_DoubleJet30er2p5_Mass_Min300_dEta_Max1p5;   //!
   TBranch        *b_L1_DoubleJet30er2p5_Mass_Min330_dEta_Max1p5;   //!
   TBranch        *b_L1_DoubleJet30er2p5_Mass_Min360_dEta_Max1p5;   //!
   TBranch        *b_L1_DoubleJet35_Mass_Min450_IsoTau45_RmOvlp;   //!
   TBranch        *b_L1_DoubleJet40er2p5;   //!
   TBranch        *b_L1_DoubleJet_100_30_DoubleJet30_Mass_Min620;   //!
   TBranch        *b_L1_DoubleJet_110_35_DoubleJet35_Mass_Min620;   //!
   TBranch        *b_L1_DoubleJet_115_40_DoubleJet40_Mass_Min620;   //!
   TBranch        *b_L1_DoubleJet_115_40_DoubleJet40_Mass_Min620_Jet60TT28;   //!
   TBranch        *b_L1_DoubleJet_120_45_DoubleJet45_Mass_Min620;   //!
   TBranch        *b_L1_DoubleJet_120_45_DoubleJet45_Mass_Min620_Jet60TT28;   //!
   TBranch        *b_L1_DoubleJet_80_30_Mass_Min420_DoubleMu0_SQ;   //!
   TBranch        *b_L1_DoubleJet_80_30_Mass_Min420_IsoTau40_RmOvlp;   //!
   TBranch        *b_L1_DoubleJet_80_30_Mass_Min420_Mu8;   //!
   TBranch        *b_L1_DoubleJet_90_30_DoubleJet30_Mass_Min620;   //!
   TBranch        *b_L1_DoubleLooseIsoEG22er2p1;   //!
   TBranch        *b_L1_DoubleLooseIsoEG24er2p1;   //!
   TBranch        *b_L1_DoubleMu0;   //!
   TBranch        *b_L1_DoubleMu0_Mass_Min1;   //!
   TBranch        *b_L1_DoubleMu0_OQ;   //!
   TBranch        *b_L1_DoubleMu0_SQ;   //!
   TBranch        *b_L1_DoubleMu0_SQ_OS;   //!
   TBranch        *b_L1_DoubleMu0_dR_Max1p6_Jet90er2p5_dR_Max0p8;   //!
   TBranch        *b_L1_DoubleMu0er1p4_SQ_OS_dR_Max1p4;   //!
   TBranch        *b_L1_DoubleMu0er1p5_SQ;   //!
   TBranch        *b_L1_DoubleMu0er1p5_SQ_OS;   //!
   TBranch        *b_L1_DoubleMu0er1p5_SQ_OS_dR_Max1p4;   //!
   TBranch        *b_L1_DoubleMu0er1p5_SQ_dR_Max1p4;   //!
   TBranch        *b_L1_DoubleMu0er2p0_SQ_OS_dR_Max1p4;   //!
   TBranch        *b_L1_DoubleMu0er2p0_SQ_dR_Max1p4;   //!
   TBranch        *b_L1_DoubleMu18er2p1;   //!
   TBranch        *b_L1_DoubleMu3_OS_DoubleEG7p5Upsilon;   //!
   TBranch        *b_L1_DoubleMu3_SQ_ETMHF50_HTT60er;   //!
   TBranch        *b_L1_DoubleMu3_SQ_ETMHF50_Jet60er2p5;   //!
   TBranch        *b_L1_DoubleMu3_SQ_ETMHF50_Jet60er2p5_OR_DoubleJet40er2p5;   //!
   TBranch        *b_L1_DoubleMu3_SQ_ETMHF60_Jet60er2p5;   //!
   TBranch        *b_L1_DoubleMu3_SQ_HTT220er;   //!
   TBranch        *b_L1_DoubleMu3_SQ_HTT240er;   //!
   TBranch        *b_L1_DoubleMu3_SQ_HTT260er;   //!
   TBranch        *b_L1_DoubleMu3_dR_Max1p6_Jet90er2p5_dR_Max0p8;   //!
   TBranch        *b_L1_DoubleMu4_SQ_EG9er2p5;   //!
   TBranch        *b_L1_DoubleMu4_SQ_OS;   //!
   TBranch        *b_L1_DoubleMu4_SQ_OS_dR_Max1p2;   //!
   TBranch        *b_L1_DoubleMu4p5_SQ_OS;   //!
   TBranch        *b_L1_DoubleMu4p5_SQ_OS_dR_Max1p2;   //!
   TBranch        *b_L1_DoubleMu4p5er2p0_SQ_OS;   //!
   TBranch        *b_L1_DoubleMu4p5er2p0_SQ_OS_Mass7to18;   //!
   TBranch        *b_L1_DoubleMu4p5er2p0_SQ_OS_Mass_Min7;   //!
   TBranch        *b_L1_DoubleMu5Upsilon_OS_DoubleEG3;   //!
   TBranch        *b_L1_DoubleMu5_SQ_EG9er2p5;   //!
   TBranch        *b_L1_DoubleMu8_SQ;   //!
   TBranch        *b_L1_DoubleMu9_SQ;   //!
   TBranch        *b_L1_DoubleMu_12_5;   //!
   TBranch        *b_L1_DoubleMu_15_5_SQ;   //!
   TBranch        *b_L1_DoubleMu_15_7;   //!
   TBranch        *b_L1_DoubleMu_15_7_Mass_Min1;   //!
   TBranch        *b_L1_DoubleMu_15_7_SQ;   //!
   TBranch        *b_L1_DoubleTau70er2p1;   //!
   TBranch        *b_L1_ETM120;   //!
   TBranch        *b_L1_ETM150;   //!
   TBranch        *b_L1_ETMHF100;   //!
   TBranch        *b_L1_ETMHF100_HTT60er;   //!
   TBranch        *b_L1_ETMHF110;   //!
   TBranch        *b_L1_ETMHF110_HTT60er;   //!
   TBranch        *b_L1_ETMHF110_HTT60er_NotSecondBunchInTrain;   //!
   TBranch        *b_L1_ETMHF120;   //!
   TBranch        *b_L1_ETMHF120_HTT60er;   //!
   TBranch        *b_L1_ETMHF120_NotSecondBunchInTrain;   //!
   TBranch        *b_L1_ETMHF130;   //!
   TBranch        *b_L1_ETMHF130_HTT60er;   //!
   TBranch        *b_L1_ETMHF140;   //!
   TBranch        *b_L1_ETMHF150;   //!
   TBranch        *b_L1_ETMHF90_HTT60er;   //!
   TBranch        *b_L1_ETT1200;   //!
   TBranch        *b_L1_ETT1600;   //!
   TBranch        *b_L1_ETT2000;   //!
   TBranch        *b_L1_FirstBunchAfterTrain;   //!
   TBranch        *b_L1_FirstBunchBeforeTrain;   //!
   TBranch        *b_L1_FirstBunchInTrain;   //!
   TBranch        *b_L1_FirstCollisionInOrbit;   //!
   TBranch        *b_L1_FirstCollisionInTrain;   //!
   TBranch        *b_L1_HCAL_LaserMon_Trig;   //!
   TBranch        *b_L1_HCAL_LaserMon_Veto;   //!
   TBranch        *b_L1_HTT120er;   //!
   TBranch        *b_L1_HTT160er;   //!
   TBranch        *b_L1_HTT200er;   //!
   TBranch        *b_L1_HTT255er;   //!
   TBranch        *b_L1_HTT280er;   //!
   TBranch        *b_L1_HTT280er_QuadJet_70_55_40_35_er2p4;   //!
   TBranch        *b_L1_HTT320er;   //!
   TBranch        *b_L1_HTT320er_QuadJet_70_55_40_40_er2p4;   //!
   TBranch        *b_L1_HTT320er_QuadJet_80_60_er2p1_45_40_er2p3;   //!
   TBranch        *b_L1_HTT320er_QuadJet_80_60_er2p1_50_45_er2p3;   //!
   TBranch        *b_L1_HTT360er;   //!
   TBranch        *b_L1_HTT400er;   //!
   TBranch        *b_L1_HTT450er;   //!
   TBranch        *b_L1_IsoEG32er2p5_Mt40;   //!
   TBranch        *b_L1_IsoEG32er2p5_Mt44;   //!
   TBranch        *b_L1_IsoEG32er2p5_Mt48;   //!
   TBranch        *b_L1_IsoTau40er2p1_ETMHF100;   //!
   TBranch        *b_L1_IsoTau40er2p1_ETMHF110;   //!
   TBranch        *b_L1_IsoTau40er2p1_ETMHF80;   //!
   TBranch        *b_L1_IsoTau40er2p1_ETMHF90;   //!
   TBranch        *b_L1_IsolatedBunch;   //!
   TBranch        *b_L1_LastBunchInTrain;   //!
   TBranch        *b_L1_LastCollisionInTrain;   //!
   TBranch        *b_L1_LooseIsoEG22er2p1_IsoTau26er2p1_dR_Min0p3;   //!
   TBranch        *b_L1_LooseIsoEG22er2p1_Tau70er2p1_dR_Min0p3;   //!
   TBranch        *b_L1_LooseIsoEG24er2p1_HTT100er;   //!
   TBranch        *b_L1_LooseIsoEG24er2p1_IsoTau27er2p1_dR_Min0p3;   //!
   TBranch        *b_L1_LooseIsoEG26er2p1_HTT100er;   //!
   TBranch        *b_L1_LooseIsoEG26er2p1_Jet34er2p5_dR_Min0p3;   //!
   TBranch        *b_L1_LooseIsoEG28er2p1_HTT100er;   //!
   TBranch        *b_L1_LooseIsoEG28er2p1_Jet34er2p5_dR_Min0p3;   //!
   TBranch        *b_L1_LooseIsoEG30er2p1_HTT100er;   //!
   TBranch        *b_L1_LooseIsoEG30er2p1_Jet34er2p5_dR_Min0p3;   //!
   TBranch        *b_L1_MinimumBiasHF0_AND_BptxAND;   //!
   TBranch        *b_L1_Mu10er2p3_Jet32er2p3_dR_Max0p4_DoubleJet32er2p3_dEta_Max1p6;   //!
   TBranch        *b_L1_Mu12er2p3_Jet40er2p1_dR_Max0p4_DoubleJet40er2p1_dEta_Max1p6;   //!
   TBranch        *b_L1_Mu12er2p3_Jet40er2p3_dR_Max0p4_DoubleJet40er2p3_dEta_Max1p6;   //!
   TBranch        *b_L1_Mu18er2p1_Tau24er2p1;   //!
   TBranch        *b_L1_Mu18er2p1_Tau26er2p1;   //!
   TBranch        *b_L1_Mu20_EG10er2p5;   //!
   TBranch        *b_L1_Mu22er2p1_IsoTau28er2p1;   //!
   TBranch        *b_L1_Mu22er2p1_IsoTau30er2p1;   //!
   TBranch        *b_L1_Mu22er2p1_IsoTau32er2p1;   //!
   TBranch        *b_L1_Mu22er2p1_IsoTau34er2p1;   //!
   TBranch        *b_L1_Mu22er2p1_IsoTau36er2p1;   //!
   TBranch        *b_L1_Mu22er2p1_IsoTau40er2p1;   //!
   TBranch        *b_L1_Mu22er2p1_Tau70er2p1;   //!
   TBranch        *b_L1_Mu3_Jet120er2p5_dR_Max0p4;   //!
   TBranch        *b_L1_Mu3_Jet120er2p5_dR_Max0p8;   //!
   TBranch        *b_L1_Mu3_Jet16er2p5_dR_Max0p4;   //!
   TBranch        *b_L1_Mu3_Jet30er2p5;   //!
   TBranch        *b_L1_Mu3_Jet35er2p5_dR_Max0p4;   //!
   TBranch        *b_L1_Mu3_Jet60er2p5_dR_Max0p4;   //!
   TBranch        *b_L1_Mu3_Jet80er2p5_dR_Max0p4;   //!
   TBranch        *b_L1_Mu3er1p5_Jet100er2p5_ETMHF40;   //!
   TBranch        *b_L1_Mu3er1p5_Jet100er2p5_ETMHF50;   //!
   TBranch        *b_L1_Mu5_EG23er2p5;   //!
   TBranch        *b_L1_Mu5_LooseIsoEG20er2p5;   //!
   TBranch        *b_L1_Mu6_DoubleEG10er2p5;   //!
   TBranch        *b_L1_Mu6_DoubleEG12er2p5;   //!
   TBranch        *b_L1_Mu6_DoubleEG15er2p5;   //!
   TBranch        *b_L1_Mu6_DoubleEG17er2p5;   //!
   TBranch        *b_L1_Mu6_HTT240er;   //!
   TBranch        *b_L1_Mu6_HTT250er;   //!
   TBranch        *b_L1_Mu7_EG20er2p5;   //!
   TBranch        *b_L1_Mu7_EG23er2p5;   //!
   TBranch        *b_L1_Mu7_LooseIsoEG20er2p5;   //!
   TBranch        *b_L1_Mu7_LooseIsoEG23er2p5;   //!
   TBranch        *b_L1_NotBptxOR;   //!
   TBranch        *b_L1_QuadJet36er2p5_IsoTau52er2p1;   //!
   TBranch        *b_L1_QuadJet60er2p5;   //!
   TBranch        *b_L1_QuadJet_95_75_65_20_DoubleJet_75_65_er2p5_Jet20_FWD3p0;   //!
   TBranch        *b_L1_QuadMu0;   //!
   TBranch        *b_L1_QuadMu0_OQ;   //!
   TBranch        *b_L1_QuadMu0_SQ;   //!
   TBranch        *b_L1_SecondBunchInTrain;   //!
   TBranch        *b_L1_SecondLastBunchInTrain;   //!
   TBranch        *b_L1_SingleEG10er2p5;   //!
   TBranch        *b_L1_SingleEG15er2p5;   //!
   TBranch        *b_L1_SingleEG26er2p5;   //!
   TBranch        *b_L1_SingleEG28_FWD2p5;   //!
   TBranch        *b_L1_SingleEG28er1p5;   //!
   TBranch        *b_L1_SingleEG28er2p1;   //!
   TBranch        *b_L1_SingleEG28er2p5;   //!
   TBranch        *b_L1_SingleEG34er2p5;   //!
   TBranch        *b_L1_SingleEG36er2p5;   //!
   TBranch        *b_L1_SingleEG38er2p5;   //!
   TBranch        *b_L1_SingleEG40er2p5;   //!
   TBranch        *b_L1_SingleEG42er2p5;   //!
   TBranch        *b_L1_SingleEG45er2p5;   //!
   TBranch        *b_L1_SingleEG50;   //!
   TBranch        *b_L1_SingleEG60;   //!
   TBranch        *b_L1_SingleEG8er2p5;   //!
   TBranch        *b_L1_SingleIsoEG24er1p5;   //!
   TBranch        *b_L1_SingleIsoEG24er2p1;   //!
   TBranch        *b_L1_SingleIsoEG26er1p5;   //!
   TBranch        *b_L1_SingleIsoEG26er2p1;   //!
   TBranch        *b_L1_SingleIsoEG26er2p5;   //!
   TBranch        *b_L1_SingleIsoEG28_FWD2p5;   //!
   TBranch        *b_L1_SingleIsoEG28er1p5;   //!
   TBranch        *b_L1_SingleIsoEG28er2p1;   //!
   TBranch        *b_L1_SingleIsoEG28er2p5;   //!
   TBranch        *b_L1_SingleIsoEG30er2p1;   //!
   TBranch        *b_L1_SingleIsoEG30er2p5;   //!
   TBranch        *b_L1_SingleIsoEG32er2p1;   //!
   TBranch        *b_L1_SingleIsoEG32er2p5;   //!
   TBranch        *b_L1_SingleIsoEG34er2p5;   //!
   TBranch        *b_L1_SingleJet10erHE;   //!
   TBranch        *b_L1_SingleJet120;   //!
   TBranch        *b_L1_SingleJet120_FWD3p0;   //!
   TBranch        *b_L1_SingleJet120er2p5;   //!
   TBranch        *b_L1_SingleJet12erHE;   //!
   TBranch        *b_L1_SingleJet140er2p5;   //!
   TBranch        *b_L1_SingleJet140er2p5_ETMHF70;   //!
   TBranch        *b_L1_SingleJet140er2p5_ETMHF80;   //!
   TBranch        *b_L1_SingleJet140er2p5_ETMHF90;   //!
   TBranch        *b_L1_SingleJet160er2p5;   //!
   TBranch        *b_L1_SingleJet180;   //!
   TBranch        *b_L1_SingleJet180er2p5;   //!
   TBranch        *b_L1_SingleJet200;   //!
   TBranch        *b_L1_SingleJet20er2p5_NotBptxOR;   //!
   TBranch        *b_L1_SingleJet20er2p5_NotBptxOR_3BX;   //!
   TBranch        *b_L1_SingleJet35;   //!
   TBranch        *b_L1_SingleJet35_FWD3p0;   //!
   TBranch        *b_L1_SingleJet35er2p5;   //!
   TBranch        *b_L1_SingleJet43er2p5_NotBptxOR_3BX;   //!
   TBranch        *b_L1_SingleJet46er2p5_NotBptxOR_3BX;   //!
   TBranch        *b_L1_SingleJet60;   //!
   TBranch        *b_L1_SingleJet60_FWD3p0;   //!
   TBranch        *b_L1_SingleJet60er2p5;   //!
   TBranch        *b_L1_SingleJet8erHE;   //!
   TBranch        *b_L1_SingleJet90;   //!
   TBranch        *b_L1_SingleJet90_FWD3p0;   //!
   TBranch        *b_L1_SingleJet90er2p5;   //!
   TBranch        *b_L1_SingleLooseIsoEG26er1p5;   //!
   TBranch        *b_L1_SingleLooseIsoEG26er2p5;   //!
   TBranch        *b_L1_SingleLooseIsoEG28_FWD2p5;   //!
   TBranch        *b_L1_SingleLooseIsoEG28er1p5;   //!
   TBranch        *b_L1_SingleLooseIsoEG28er2p1;   //!
   TBranch        *b_L1_SingleLooseIsoEG28er2p5;   //!
   TBranch        *b_L1_SingleLooseIsoEG30er1p5;   //!
   TBranch        *b_L1_SingleLooseIsoEG30er2p5;   //!
   TBranch        *b_L1_SingleMu0_BMTF;   //!
   TBranch        *b_L1_SingleMu0_DQ;   //!
   TBranch        *b_L1_SingleMu0_EMTF;   //!
   TBranch        *b_L1_SingleMu0_OMTF;   //!
   TBranch        *b_L1_SingleMu10er1p5;   //!
   TBranch        *b_L1_SingleMu12_DQ_BMTF;   //!
   TBranch        *b_L1_SingleMu12_DQ_EMTF;   //!
   TBranch        *b_L1_SingleMu12_DQ_OMTF;   //!
   TBranch        *b_L1_SingleMu12er1p5;   //!
   TBranch        *b_L1_SingleMu14er1p5;   //!
   TBranch        *b_L1_SingleMu15_DQ;   //!
   TBranch        *b_L1_SingleMu16er1p5;   //!
   TBranch        *b_L1_SingleMu18;   //!
   TBranch        *b_L1_SingleMu18er1p5;   //!
   TBranch        *b_L1_SingleMu20;   //!
   TBranch        *b_L1_SingleMu22;   //!
   TBranch        *b_L1_SingleMu22_BMTF;   //!
   TBranch        *b_L1_SingleMu22_EMTF;   //!
   TBranch        *b_L1_SingleMu22_OMTF;   //!
   TBranch        *b_L1_SingleMu25;   //!
   TBranch        *b_L1_SingleMu3;   //!
   TBranch        *b_L1_SingleMu5;   //!
   TBranch        *b_L1_SingleMu6er1p5;   //!
   TBranch        *b_L1_SingleMu7;   //!
   TBranch        *b_L1_SingleMu7_DQ;   //!
   TBranch        *b_L1_SingleMu7er1p5;   //!
   TBranch        *b_L1_SingleMu8er1p5;   //!
   TBranch        *b_L1_SingleMu9er1p5;   //!
   TBranch        *b_L1_SingleMuCosmics;   //!
   TBranch        *b_L1_SingleMuCosmics_BMTF;   //!
   TBranch        *b_L1_SingleMuCosmics_EMTF;   //!
   TBranch        *b_L1_SingleMuCosmics_OMTF;   //!
   TBranch        *b_L1_SingleMuOpen;   //!
   TBranch        *b_L1_SingleMuOpen_NotBptxOR;   //!
   TBranch        *b_L1_SingleMuOpen_er1p1_NotBptxOR_3BX;   //!
   TBranch        *b_L1_SingleMuOpen_er1p4_NotBptxOR_3BX;   //!
   TBranch        *b_L1_SingleTau120er2p1;   //!
   TBranch        *b_L1_SingleTau130er2p1;   //!
   TBranch        *b_L1_TOTEM_1;   //!
   TBranch        *b_L1_TOTEM_2;   //!
   TBranch        *b_L1_TOTEM_3;   //!
   TBranch        *b_L1_TOTEM_4;   //!
   TBranch        *b_L1_TripleEG16er2p5;   //!
   TBranch        *b_L1_TripleEG_16_12_8_er2p5;   //!
   TBranch        *b_L1_TripleEG_16_15_8_er2p5;   //!
   TBranch        *b_L1_TripleEG_18_17_8_er2p5;   //!
   TBranch        *b_L1_TripleEG_18_18_12_er2p5;   //!
   TBranch        *b_L1_TripleJet_100_80_70_DoubleJet_80_70_er2p5;   //!
   TBranch        *b_L1_TripleJet_105_85_75_DoubleJet_85_75_er2p5;   //!
   TBranch        *b_L1_TripleJet_95_75_65_DoubleJet_75_65_er2p5;   //!
   TBranch        *b_L1_TripleMu0;   //!
   TBranch        *b_L1_TripleMu0_OQ;   //!
   TBranch        *b_L1_TripleMu0_SQ;   //!
   TBranch        *b_L1_TripleMu3;   //!
   TBranch        *b_L1_TripleMu3_SQ;   //!
   TBranch        *b_L1_TripleMu_5SQ_3SQ_0OQ;   //!
   TBranch        *b_L1_TripleMu_5SQ_3SQ_0OQ_DoubleMu_5_3_SQ_OS_Mass_Max9;   //!
   TBranch        *b_L1_TripleMu_5SQ_3SQ_0_DoubleMu_5_3_SQ_OS_Mass_Max9;   //!
   TBranch        *b_L1_TripleMu_5_3_3;   //!
   TBranch        *b_L1_TripleMu_5_3_3_SQ;   //!
   TBranch        *b_L1_TripleMu_5_3p5_2p5;   //!
   TBranch        *b_L1_TripleMu_5_3p5_2p5_DoubleMu_5_2p5_OS_Mass_5to17;   //!
   TBranch        *b_L1_TripleMu_5_3p5_2p5_OQ_DoubleMu_5_2p5_OQ_OS_Mass_5to17;   //!
   TBranch        *b_L1_TripleMu_5_4_2p5_DoubleMu_5_2p5_OS_Mass_5to17;   //!
   TBranch        *b_L1_TripleMu_5_5_3;   //!
   TBranch        *b_L1_UnpairedBunchBptxMinus;   //!
   TBranch        *b_L1_UnpairedBunchBptxPlus;   //!
   TBranch        *b_L1_ZeroBias;   //!
   TBranch        *b_L1_ZeroBias_copy;   //!
   TBranch        *b_L1_UnprefireableEvent;   //!
   TBranch        *b_Flag_HBHENoiseFilter;   //!
   TBranch        *b_Flag_HBHENoiseIsoFilter;   //!
   TBranch        *b_Flag_CSCTightHaloFilter;   //!
   TBranch        *b_Flag_CSCTightHaloTrkMuUnvetoFilter;   //!
   TBranch        *b_Flag_CSCTightHalo2015Filter;   //!
   TBranch        *b_Flag_globalTightHalo2016Filter;   //!
   TBranch        *b_Flag_globalSuperTightHalo2016Filter;   //!
   TBranch        *b_Flag_HcalStripHaloFilter;   //!
   TBranch        *b_Flag_hcalLaserEventFilter;   //!
   TBranch        *b_Flag_EcalDeadCellTriggerPrimitiveFilter;   //!
   TBranch        *b_Flag_EcalDeadCellBoundaryEnergyFilter;   //!
   TBranch        *b_Flag_ecalBadCalibFilter;   //!
   TBranch        *b_Flag_goodVertices;   //!
   TBranch        *b_Flag_eeBadScFilter;   //!
   TBranch        *b_Flag_ecalLaserCorrFilter;   //!
   TBranch        *b_Flag_trkPOGFilters;   //!
   TBranch        *b_Flag_chargedHadronTrackResolutionFilter;   //!
   TBranch        *b_Flag_muonBadTrackFilter;   //!
   TBranch        *b_Flag_BadChargedCandidateFilter;   //!
   TBranch        *b_Flag_BadPFMuonFilter;   //!
   TBranch        *b_Flag_BadPFMuonDzFilter;   //!
   TBranch        *b_Flag_hfNoisyHitsFilter;   //!
   TBranch        *b_Flag_BadChargedCandidateSummer16Filter;   //!
   TBranch        *b_Flag_BadPFMuonSummer16Filter;   //!
   TBranch        *b_Flag_trkPOG_manystripclus53X;   //!
   TBranch        *b_Flag_trkPOG_toomanystripclus53X;   //!
   TBranch        *b_Flag_trkPOG_logErrorTooManyClusters;   //!
   TBranch        *b_Flag_METFilters;   //!
   TBranch        *b_L1Reco_step;   //!
   TBranch        *b_L1simulation_step;   //!
   TBranch        *b_HLTriggerFirstPath;   //!
   TBranch        *b_HLT_AK8PFJet360_TrimMass30;   //!
   TBranch        *b_HLT_AK8PFJet380_TrimMass30;   //!
   TBranch        *b_HLT_AK8PFJet400_TrimMass30;   //!
   TBranch        *b_HLT_AK8PFJet420_TrimMass30;   //!
   TBranch        *b_HLT_AK8PFHT750_TrimMass50;   //!
   TBranch        *b_HLT_AK8PFHT800_TrimMass50;   //!
   TBranch        *b_HLT_AK8PFHT850_TrimMass50;   //!
   TBranch        *b_HLT_AK8PFHT900_TrimMass50;   //!
   TBranch        *b_HLT_CaloJet500_NoJetID;   //!
   TBranch        *b_HLT_CaloJet550_NoJetID;   //!
   TBranch        *b_HLT_DoubleMu5_Upsilon_DoubleEle3_CaloIdL_TrackIdL;   //!
   TBranch        *b_HLT_DoubleMu3_DoubleEle7p5_CaloIdL_TrackIdL_Upsilon;   //!
   TBranch        *b_HLT_Trimuon5_3p5_2_Upsilon_Muon;   //!
   TBranch        *b_HLT_TrimuonOpen_5_3p5_2_Upsilon_Muon;   //!
   TBranch        *b_HLT_DoubleEle25_CaloIdL_MW;   //!
   TBranch        *b_HLT_DoubleEle27_CaloIdL_MW;   //!
   TBranch        *b_HLT_DoubleEle33_CaloIdL_MW;   //!
   TBranch        *b_HLT_DoubleEle24_eta2p1_WPTight_Gsf;   //!
   TBranch        *b_HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_DZ_PFHT350;   //!
   TBranch        *b_HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_PFHT350;   //!
   TBranch        *b_HLT_Ele27_Ele37_CaloIdL_MW;   //!
   TBranch        *b_HLT_Mu27_Ele37_CaloIdL_MW;   //!
   TBranch        *b_HLT_Mu37_Ele27_CaloIdL_MW;   //!
   TBranch        *b_HLT_Mu37_TkMu27;   //!
   TBranch        *b_HLT_DoubleMu4_3_Bs;   //!
   TBranch        *b_HLT_DoubleMu4_3_Jpsi;   //!
   TBranch        *b_HLT_DoubleMu4_JpsiTrk_Displaced;   //!
   TBranch        *b_HLT_DoubleMu4_LowMassNonResonantTrk_Displaced;   //!
   TBranch        *b_HLT_DoubleMu3_Trk_Tau3mu;   //!
   TBranch        *b_HLT_DoubleMu3_TkMu_DsTau3Mu;   //!
   TBranch        *b_HLT_DoubleMu4_PsiPrimeTrk_Displaced;   //!
   TBranch        *b_HLT_DoubleMu4_Mass3p8_DZ_PFHT350;   //!
   TBranch        *b_HLT_Mu3_PFJet40;   //!
   TBranch        *b_HLT_Mu7p5_L2Mu2_Jpsi;   //!
   TBranch        *b_HLT_Mu7p5_L2Mu2_Upsilon;   //!
   TBranch        *b_HLT_Mu7p5_Track2_Jpsi;   //!
   TBranch        *b_HLT_Mu7p5_Track3p5_Jpsi;   //!
   TBranch        *b_HLT_Mu7p5_Track7_Jpsi;   //!
   TBranch        *b_HLT_Mu7p5_Track2_Upsilon;   //!
   TBranch        *b_HLT_Mu7p5_Track3p5_Upsilon;   //!
   TBranch        *b_HLT_Mu7p5_Track7_Upsilon;   //!
   TBranch        *b_HLT_Mu3_L1SingleMu5orSingleMu7;   //!
   TBranch        *b_HLT_DoublePhoton33_CaloIdL;   //!
   TBranch        *b_HLT_DoublePhoton70;   //!
   TBranch        *b_HLT_DoublePhoton85;   //!
   TBranch        *b_HLT_Ele20_WPTight_Gsf;   //!
   TBranch        *b_HLT_Ele15_WPLoose_Gsf;   //!
   TBranch        *b_HLT_Ele17_WPLoose_Gsf;   //!
   TBranch        *b_HLT_Ele20_WPLoose_Gsf;   //!
   TBranch        *b_HLT_Ele20_eta2p1_WPLoose_Gsf;   //!
   TBranch        *b_HLT_DiEle27_WPTightCaloOnly_L1DoubleEG;   //!
   TBranch        *b_HLT_Ele27_WPTight_Gsf;   //!
   TBranch        *b_HLT_Ele28_WPTight_Gsf;   //!
   TBranch        *b_HLT_Ele30_WPTight_Gsf;   //!
   TBranch        *b_HLT_Ele32_WPTight_Gsf;   //!
   TBranch        *b_HLT_Ele35_WPTight_Gsf;   //!
   TBranch        *b_HLT_Ele35_WPTight_Gsf_L1EGMT;   //!
   TBranch        *b_HLT_Ele38_WPTight_Gsf;   //!
   TBranch        *b_HLT_Ele40_WPTight_Gsf;   //!
   TBranch        *b_HLT_Ele32_WPTight_Gsf_L1DoubleEG;   //!
   TBranch        *b_HLT_Ele24_eta2p1_WPTight_Gsf_LooseChargedIsoPFTau30_eta2p1_CrossL1;   //!
   TBranch        *b_HLT_Ele24_eta2p1_WPTight_Gsf_LooseChargedIsoPFTauHPS30_eta2p1_CrossL1;   //!
   TBranch        *b_HLT_Ele24_eta2p1_WPTight_Gsf_MediumChargedIsoPFTauHPS30_eta2p1_CrossL1;   //!
   TBranch        *b_HLT_Ele24_eta2p1_WPTight_Gsf_TightChargedIsoPFTauHPS30_eta2p1_CrossL1;   //!
   TBranch        *b_HLT_Ele24_eta2p1_WPTight_Gsf_LooseChargedIsoPFTauHPS30_eta2p1_TightID_CrossL1;   //!
   TBranch        *b_HLT_Ele24_eta2p1_WPTight_Gsf_MediumChargedIsoPFTauHPS30_eta2p1_TightID_CrossL1;   //!
   TBranch        *b_HLT_Ele24_eta2p1_WPTight_Gsf_TightChargedIsoPFTauHPS30_eta2p1_TightID_CrossL1;   //!
   TBranch        *b_HLT_HT450_Beamspot;   //!
   TBranch        *b_HLT_HT300_Beamspot;   //!
   TBranch        *b_HLT_ZeroBias_Beamspot;   //!
   TBranch        *b_HLT_IsoMu20_eta2p1_LooseChargedIsoPFTau27_eta2p1_CrossL1;   //!
   TBranch        *b_HLT_IsoMu20_eta2p1_LooseChargedIsoPFTauHPS27_eta2p1_CrossL1;   //!
   TBranch        *b_HLT_IsoMu20_eta2p1_MediumChargedIsoPFTauHPS27_eta2p1_CrossL1;   //!
   TBranch        *b_HLT_IsoMu20_eta2p1_TightChargedIsoPFTauHPS27_eta2p1_CrossL1;   //!
   TBranch        *b_HLT_IsoMu20_eta2p1_LooseChargedIsoPFTauHPS27_eta2p1_TightID_CrossL1;   //!
   TBranch        *b_HLT_IsoMu20_eta2p1_MediumChargedIsoPFTauHPS27_eta2p1_TightID_CrossL1;   //!
   TBranch        *b_HLT_IsoMu20_eta2p1_TightChargedIsoPFTauHPS27_eta2p1_TightID_CrossL1;   //!
   TBranch        *b_HLT_IsoMu24_eta2p1_MediumChargedIsoPFTau35_Trk1_eta2p1_Reg_CrossL1;   //!
   TBranch        *b_HLT_IsoMu24_eta2p1_MediumChargedIsoPFTau35_Trk1_TightID_eta2p1_Reg_CrossL1;   //!
   TBranch        *b_HLT_IsoMu24_eta2p1_TightChargedIsoPFTau35_Trk1_eta2p1_Reg_CrossL1;   //!
   TBranch        *b_HLT_IsoMu24_eta2p1_TightChargedIsoPFTau35_Trk1_TightID_eta2p1_Reg_CrossL1;   //!
   TBranch        *b_HLT_IsoMu24_eta2p1_TightChargedIsoPFTauHPS35_Trk1_eta2p1_Reg_CrossL1;   //!
   TBranch        *b_HLT_IsoMu24_eta2p1_MediumChargedIsoPFTauHPS35_Trk1_TightID_eta2p1_Reg_CrossL1;   //!
   TBranch        *b_HLT_IsoMu24_eta2p1_TightChargedIsoPFTauHPS35_Trk1_TightID_eta2p1_Reg_CrossL1;   //!
   TBranch        *b_HLT_IsoMu24_eta2p1_MediumChargedIsoPFTauHPS35_Trk1_eta2p1_Reg_CrossL1;   //!
   TBranch        *b_HLT_IsoMu24_eta2p1_MediumChargedIsoPFTauHPS30_Trk1_eta2p1_Reg_CrossL1;   //!
   TBranch        *b_HLT_IsoMu27_LooseChargedIsoPFTau20_Trk1_eta2p1_SingleL1;   //!
   TBranch        *b_HLT_IsoMu27_LooseChargedIsoPFTauHPS20_Trk1_eta2p1_SingleL1;   //!
   TBranch        *b_HLT_IsoMu27_MediumChargedIsoPFTauHPS20_Trk1_eta2p1_SingleL1;   //!
   TBranch        *b_HLT_IsoMu27_TightChargedIsoPFTauHPS20_Trk1_eta2p1_SingleL1;   //!
   TBranch        *b_HLT_IsoMu20;   //!
   TBranch        *b_HLT_IsoMu24;   //!
   TBranch        *b_HLT_IsoMu24_eta2p1;   //!
   TBranch        *b_HLT_IsoMu27;   //!
   TBranch        *b_HLT_IsoMu30;   //!
   TBranch        *b_HLT_UncorrectedJetE30_NoBPTX;   //!
   TBranch        *b_HLT_UncorrectedJetE30_NoBPTX3BX;   //!
   TBranch        *b_HLT_UncorrectedJetE60_NoBPTX3BX;   //!
   TBranch        *b_HLT_UncorrectedJetE70_NoBPTX3BX;   //!
   TBranch        *b_HLT_L1SingleMu18;   //!
   TBranch        *b_HLT_L1SingleMu25;   //!
   TBranch        *b_HLT_L1SingleMuCosmics;   //!
   TBranch        *b_HLT_L2Mu10;   //!
   TBranch        *b_HLT_L2Mu10_NoVertex_NoBPTX3BX;   //!
   TBranch        *b_HLT_L2Mu10_NoVertex_NoBPTX;   //!
   TBranch        *b_HLT_L2Mu45_NoVertex_3Sta_NoBPTX3BX;   //!
   TBranch        *b_HLT_L2Mu40_NoVertex_3Sta_NoBPTX3BX;   //!
   TBranch        *b_HLT_L2Mu50;   //!
   TBranch        *b_HLT_L2Mu23NoVtx_2Cha;   //!
   TBranch        *b_HLT_L2Mu23NoVtx_2Cha_CosmicSeed;   //!
   TBranch        *b_HLT_DoubleL2Mu30NoVtx_2Cha_CosmicSeed_Eta2p4;   //!
   TBranch        *b_HLT_DoubleL2Mu30NoVtx_2Cha_Eta2p4;   //!
   TBranch        *b_HLT_DoubleL2Mu50;   //!
   TBranch        *b_HLT_DoubleL2Mu23NoVtx_2Cha_CosmicSeed;   //!
   TBranch        *b_HLT_DoubleL2Mu23NoVtx_2Cha_CosmicSeed_NoL2Matched;   //!
   TBranch        *b_HLT_DoubleL2Mu25NoVtx_2Cha_CosmicSeed;   //!
   TBranch        *b_HLT_DoubleL2Mu25NoVtx_2Cha_CosmicSeed_NoL2Matched;   //!
   TBranch        *b_HLT_DoubleL2Mu25NoVtx_2Cha_CosmicSeed_Eta2p4;   //!
   TBranch        *b_HLT_DoubleL2Mu23NoVtx_2Cha;   //!
   TBranch        *b_HLT_DoubleL2Mu23NoVtx_2Cha_NoL2Matched;   //!
   TBranch        *b_HLT_DoubleL2Mu25NoVtx_2Cha;   //!
   TBranch        *b_HLT_DoubleL2Mu25NoVtx_2Cha_NoL2Matched;   //!
   TBranch        *b_HLT_DoubleL2Mu25NoVtx_2Cha_Eta2p4;   //!
   TBranch        *b_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL;   //!
   TBranch        *b_HLT_Mu19_TrkIsoVVL_Mu9_TrkIsoVVL;   //!
   TBranch        *b_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ;   //!
   TBranch        *b_HLT_Mu19_TrkIsoVVL_Mu9_TrkIsoVVL_DZ;   //!
   TBranch        *b_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass8;   //!
   TBranch        *b_HLT_Mu19_TrkIsoVVL_Mu9_TrkIsoVVL_DZ_Mass8;   //!
   TBranch        *b_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8;   //!
   TBranch        *b_HLT_Mu19_TrkIsoVVL_Mu9_TrkIsoVVL_DZ_Mass3p8;   //!
   TBranch        *b_HLT_Mu25_TkMu0_Onia;   //!
   TBranch        *b_HLT_Mu30_TkMu0_Psi;   //!
   TBranch        *b_HLT_Mu30_TkMu0_Upsilon;   //!
   TBranch        *b_HLT_Mu20_TkMu0_Phi;   //!
   TBranch        *b_HLT_Mu25_TkMu0_Phi;   //!
   TBranch        *b_HLT_Mu12;   //!
   TBranch        *b_HLT_Mu15;   //!
   TBranch        *b_HLT_Mu20;   //!
   TBranch        *b_HLT_Mu27;   //!
   TBranch        *b_HLT_Mu50;   //!
   TBranch        *b_HLT_Mu55;   //!
   TBranch        *b_HLT_OldMu100;   //!
   TBranch        *b_HLT_TkMu100;   //!
   TBranch        *b_HLT_DiPFJet15_NoCaloMatched;   //!
   TBranch        *b_HLT_DiPFJet25_NoCaloMatched;   //!
   TBranch        *b_HLT_DiPFJet15_FBEta3_NoCaloMatched;   //!
   TBranch        *b_HLT_DiPFJet25_FBEta3_NoCaloMatched;   //!
   TBranch        *b_HLT_DiPFJetAve40;   //!
   TBranch        *b_HLT_DiPFJetAve60;   //!
   TBranch        *b_HLT_DiPFJetAve80;   //!
   TBranch        *b_HLT_DiPFJetAve140;   //!
   TBranch        *b_HLT_DiPFJetAve200;   //!
   TBranch        *b_HLT_DiPFJetAve260;   //!
   TBranch        *b_HLT_DiPFJetAve320;   //!
   TBranch        *b_HLT_DiPFJetAve400;   //!
   TBranch        *b_HLT_DiPFJetAve500;   //!
   TBranch        *b_HLT_DiPFJetAve15_HFJEC;   //!
   TBranch        *b_HLT_DiPFJetAve25_HFJEC;   //!
   TBranch        *b_HLT_DiPFJetAve35_HFJEC;   //!
   TBranch        *b_HLT_DiPFJetAve60_HFJEC;   //!
   TBranch        *b_HLT_DiPFJetAve80_HFJEC;   //!
   TBranch        *b_HLT_DiPFJetAve100_HFJEC;   //!
   TBranch        *b_HLT_DiPFJetAve160_HFJEC;   //!
   TBranch        *b_HLT_DiPFJetAve220_HFJEC;   //!
   TBranch        *b_HLT_DiPFJetAve300_HFJEC;   //!
   TBranch        *b_HLT_AK8PFJet15;   //!
   TBranch        *b_HLT_AK8PFJet25;   //!
   TBranch        *b_HLT_AK8PFJet40;   //!
   TBranch        *b_HLT_AK8PFJet60;   //!
   TBranch        *b_HLT_AK8PFJet80;   //!
   TBranch        *b_HLT_AK8PFJet140;   //!
   TBranch        *b_HLT_AK8PFJet200;   //!
   TBranch        *b_HLT_AK8PFJet260;   //!
   TBranch        *b_HLT_AK8PFJet320;   //!
   TBranch        *b_HLT_AK8PFJet400;   //!
   TBranch        *b_HLT_AK8PFJet450;   //!
   TBranch        *b_HLT_AK8PFJet500;   //!
   TBranch        *b_HLT_AK8PFJet550;   //!
  //TBranch        *b_HLT_PFJet15;   //!
  //TBranch        *b_HLT_PFJet25;   //!
   TBranch        *b_HLT_PFJet40;   //!
   TBranch        *b_HLT_PFJet60;   //!
   TBranch        *b_HLT_PFJet80;   //!
   TBranch        *b_HLT_PFJet140;   //!
   TBranch        *b_HLT_PFJet200;   //!
   TBranch        *b_HLT_PFJet260;   //!
   TBranch        *b_HLT_PFJet320;   //!
   TBranch        *b_HLT_PFJet400;   //!
   TBranch        *b_HLT_PFJet450;   //!
   TBranch        *b_HLT_PFJet500;   //!
   TBranch        *b_HLT_PFJet550;   //!
   TBranch        *b_HLT_PFJetFwd15;   //!
   TBranch        *b_HLT_PFJetFwd25;   //!
   TBranch        *b_HLT_PFJetFwd40;   //!
   TBranch        *b_HLT_PFJetFwd60;   //!
   TBranch        *b_HLT_PFJetFwd80;   //!
   TBranch        *b_HLT_PFJetFwd140;   //!
   TBranch        *b_HLT_PFJetFwd200;   //!
   TBranch        *b_HLT_PFJetFwd260;   //!
   TBranch        *b_HLT_PFJetFwd320;   //!
   TBranch        *b_HLT_PFJetFwd400;   //!
   TBranch        *b_HLT_PFJetFwd450;   //!
   TBranch        *b_HLT_PFJetFwd500;   //!
   TBranch        *b_HLT_AK8PFJetFwd15;   //!
   TBranch        *b_HLT_AK8PFJetFwd25;   //!
   TBranch        *b_HLT_AK8PFJetFwd40;   //!
   TBranch        *b_HLT_AK8PFJetFwd60;   //!
   TBranch        *b_HLT_AK8PFJetFwd80;   //!
   TBranch        *b_HLT_AK8PFJetFwd140;   //!
   TBranch        *b_HLT_AK8PFJetFwd200;   //!
   TBranch        *b_HLT_AK8PFJetFwd260;   //!
   TBranch        *b_HLT_AK8PFJetFwd320;   //!
   TBranch        *b_HLT_AK8PFJetFwd400;   //!
   TBranch        *b_HLT_AK8PFJetFwd450;   //!
   TBranch        *b_HLT_AK8PFJetFwd500;   //!
   TBranch        *b_HLT_PFHT180;   //!
   TBranch        *b_HLT_PFHT250;   //!
   TBranch        *b_HLT_PFHT370;   //!
   TBranch        *b_HLT_PFHT430;   //!
   TBranch        *b_HLT_PFHT510;   //!
   TBranch        *b_HLT_PFHT590;   //!
   TBranch        *b_HLT_PFHT680;   //!
   TBranch        *b_HLT_PFHT780;   //!
   TBranch        *b_HLT_PFHT890;   //!
   TBranch        *b_HLT_PFHT1050;   //!
   TBranch        *b_HLT_PFHT500_PFMET100_PFMHT100_IDTight;   //!
   TBranch        *b_HLT_PFHT500_PFMET110_PFMHT110_IDTight;   //!
   TBranch        *b_HLT_PFHT700_PFMET85_PFMHT85_IDTight;   //!
   TBranch        *b_HLT_PFHT700_PFMET95_PFMHT95_IDTight;   //!
   TBranch        *b_HLT_PFHT800_PFMET75_PFMHT75_IDTight;   //!
   TBranch        *b_HLT_PFHT800_PFMET85_PFMHT85_IDTight;   //!
   TBranch        *b_HLT_PFMET110_PFMHT110_IDTight;   //!
   TBranch        *b_HLT_PFMET120_PFMHT120_IDTight;   //!
   TBranch        *b_HLT_PFMET130_PFMHT130_IDTight;   //!
   TBranch        *b_HLT_PFMET140_PFMHT140_IDTight;   //!
   TBranch        *b_HLT_PFMET100_PFMHT100_IDTight_CaloBTagDeepCSV_3p1;   //!
   TBranch        *b_HLT_PFMET110_PFMHT110_IDTight_CaloBTagDeepCSV_3p1;   //!
   TBranch        *b_HLT_PFMET120_PFMHT120_IDTight_CaloBTagDeepCSV_3p1;   //!
   TBranch        *b_HLT_PFMET130_PFMHT130_IDTight_CaloBTagDeepCSV_3p1;   //!
   TBranch        *b_HLT_PFMET140_PFMHT140_IDTight_CaloBTagDeepCSV_3p1;   //!
   TBranch        *b_HLT_PFMET120_PFMHT120_IDTight_PFHT60;   //!
   TBranch        *b_HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60;   //!
   TBranch        *b_HLT_PFMETTypeOne120_PFMHT120_IDTight_PFHT60;   //!
   TBranch        *b_HLT_PFMETTypeOne110_PFMHT110_IDTight;   //!
   TBranch        *b_HLT_PFMETTypeOne120_PFMHT120_IDTight;   //!
   TBranch        *b_HLT_PFMETTypeOne130_PFMHT130_IDTight;   //!
   TBranch        *b_HLT_PFMETTypeOne140_PFMHT140_IDTight;   //!
   TBranch        *b_HLT_PFMETNoMu110_PFMHTNoMu110_IDTight;   //!
   TBranch        *b_HLT_PFMETNoMu120_PFMHTNoMu120_IDTight;   //!
   TBranch        *b_HLT_PFMETNoMu130_PFMHTNoMu130_IDTight;   //!
   TBranch        *b_HLT_PFMETNoMu140_PFMHTNoMu140_IDTight;   //!
   TBranch        *b_HLT_MonoCentralPFJet80_PFMETNoMu110_PFMHTNoMu110_IDTight;   //!
   TBranch        *b_HLT_MonoCentralPFJet80_PFMETNoMu120_PFMHTNoMu120_IDTight;   //!
   TBranch        *b_HLT_MonoCentralPFJet80_PFMETNoMu130_PFMHTNoMu130_IDTight;   //!
   TBranch        *b_HLT_MonoCentralPFJet80_PFMETNoMu140_PFMHTNoMu140_IDTight;   //!
   TBranch        *b_HLT_L1ETMHadSeeds;   //!
   TBranch        *b_HLT_CaloMHT90;   //!
   TBranch        *b_HLT_CaloMET80_NotCleaned;   //!
   TBranch        *b_HLT_CaloMET90_NotCleaned;   //!
   TBranch        *b_HLT_CaloMET100_NotCleaned;   //!
   TBranch        *b_HLT_CaloMET110_NotCleaned;   //!
   TBranch        *b_HLT_CaloMET250_NotCleaned;   //!
   TBranch        *b_HLT_CaloMET300_NotCleaned;   //!
   TBranch        *b_HLT_CaloMET350_NotCleaned;   //!
   TBranch        *b_HLT_PFMET200_NotCleaned;   //!
   TBranch        *b_HLT_PFMET250_NotCleaned;   //!
   TBranch        *b_HLT_PFMET300_NotCleaned;   //!
   TBranch        *b_HLT_PFMET200_BeamHaloCleaned;   //!
   TBranch        *b_HLT_PFMETTypeOne200_BeamHaloCleaned;   //!
   TBranch        *b_HLT_MET105_IsoTrk50;   //!
   TBranch        *b_HLT_MET120_IsoTrk50;   //!
   TBranch        *b_HLT_SingleJet30_Mu12_SinglePFJet40;   //!
   TBranch        *b_HLT_Mu12_DoublePFJets40_CaloBTagDeepCSV_p71;   //!
   TBranch        *b_HLT_Mu12_DoublePFJets100_CaloBTagDeepCSV_p71;   //!
   TBranch        *b_HLT_Mu12_DoublePFJets200_CaloBTagDeepCSV_p71;   //!
   TBranch        *b_HLT_Mu12_DoublePFJets350_CaloBTagDeepCSV_p71;   //!
   TBranch        *b_HLT_Mu12_DoublePFJets40MaxDeta1p6_DoubleCaloBTagDeepCSV_p71;   //!
   TBranch        *b_HLT_Mu12_DoublePFJets54MaxDeta1p6_DoubleCaloBTagDeepCSV_p71;   //!
   TBranch        *b_HLT_Mu12_DoublePFJets62MaxDeta1p6_DoubleCaloBTagDeepCSV_p71;   //!
   TBranch        *b_HLT_DoublePFJets40_CaloBTagDeepCSV_p71;   //!
   TBranch        *b_HLT_DoublePFJets100_CaloBTagDeepCSV_p71;   //!
   TBranch        *b_HLT_DoublePFJets200_CaloBTagDeepCSV_p71;   //!
   TBranch        *b_HLT_DoublePFJets350_CaloBTagDeepCSV_p71;   //!
   TBranch        *b_HLT_DoublePFJets116MaxDeta1p6_DoubleCaloBTagDeepCSV_p71;   //!
   TBranch        *b_HLT_DoublePFJets128MaxDeta1p6_DoubleCaloBTagDeepCSV_p71;   //!
   TBranch        *b_HLT_Photon300_NoHE;   //!
   TBranch        *b_HLT_Mu8_TrkIsoVVL;   //!
   TBranch        *b_HLT_Mu8_DiEle12_CaloIdL_TrackIdL_DZ;   //!
   TBranch        *b_HLT_Mu8_DiEle12_CaloIdL_TrackIdL;   //!
   TBranch        *b_HLT_Mu8_Ele8_CaloIdM_TrackIdM_Mass8_PFHT350_DZ;   //!
   TBranch        *b_HLT_Mu8_Ele8_CaloIdM_TrackIdM_Mass8_PFHT350;   //!
   TBranch        *b_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ;   //!
   TBranch        *b_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_PFDiJet30;   //!
   TBranch        *b_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_CaloDiJet30;   //!
   TBranch        *b_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_PFDiJet30_PFBtagDeepCSV_1p5;   //!
   TBranch        *b_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_CaloDiJet30_CaloBtagDeepCSV_1p5;   //!
   TBranch        *b_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL;   //!
   TBranch        *b_HLT_Mu17_TrkIsoVVL;   //!
   TBranch        *b_HLT_Mu19_TrkIsoVVL;   //!
   TBranch        *b_HLT_BTagMu_AK4DiJet20_Mu5;   //!
   TBranch        *b_HLT_BTagMu_AK4DiJet40_Mu5;   //!
   TBranch        *b_HLT_BTagMu_AK4DiJet70_Mu5;   //!
   TBranch        *b_HLT_BTagMu_AK4DiJet110_Mu5;   //!
   TBranch        *b_HLT_BTagMu_AK4DiJet170_Mu5;   //!
   TBranch        *b_HLT_BTagMu_AK4Jet300_Mu5;   //!
   TBranch        *b_HLT_BTagMu_AK8DiJet170_Mu5;   //!
   TBranch        *b_HLT_BTagMu_AK8Jet170_DoubleMu5;   //!
   TBranch        *b_HLT_BTagMu_AK8Jet300_Mu5;   //!
   TBranch        *b_HLT_BTagMu_AK4DiJet20_Mu5_noalgo;   //!
   TBranch        *b_HLT_BTagMu_AK4DiJet40_Mu5_noalgo;   //!
   TBranch        *b_HLT_BTagMu_AK4DiJet70_Mu5_noalgo;   //!
   TBranch        *b_HLT_BTagMu_AK4DiJet110_Mu5_noalgo;   //!
   TBranch        *b_HLT_BTagMu_AK4DiJet170_Mu5_noalgo;   //!
   TBranch        *b_HLT_BTagMu_AK4Jet300_Mu5_noalgo;   //!
   TBranch        *b_HLT_BTagMu_AK8DiJet170_Mu5_noalgo;   //!
   TBranch        *b_HLT_BTagMu_AK8Jet170_DoubleMu5_noalgo;   //!
   TBranch        *b_HLT_BTagMu_AK8Jet300_Mu5_noalgo;   //!
   TBranch        *b_HLT_Ele15_Ele8_CaloIdL_TrackIdL_IsoVL;   //!
   TBranch        *b_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ;   //!
   TBranch        *b_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL;   //!
   TBranch        *b_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ;   //!
   TBranch        *b_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL;   //!
   TBranch        *b_HLT_Mu12_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL;   //!
   TBranch        *b_HLT_Mu12_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ;   //!
   TBranch        *b_HLT_Mu12_DoublePhoton20;   //!
   TBranch        *b_HLT_TriplePhoton_20_20_20_CaloIdLV2;   //!
   TBranch        *b_HLT_TriplePhoton_20_20_20_CaloIdLV2_R9IdVL;   //!
   TBranch        *b_HLT_TriplePhoton_30_30_10_CaloIdLV2;   //!
   TBranch        *b_HLT_TriplePhoton_30_30_10_CaloIdLV2_R9IdVL;   //!
   TBranch        *b_HLT_TriplePhoton_35_35_5_CaloIdLV2_R9IdVL;   //!
   TBranch        *b_HLT_Photon20;   //!
   TBranch        *b_HLT_Photon33;   //!
   TBranch        *b_HLT_Photon50;   //!
   TBranch        *b_HLT_Photon75;   //!
   TBranch        *b_HLT_Photon90;   //!
   TBranch        *b_HLT_Photon120;   //!
   TBranch        *b_HLT_Photon150;   //!
   TBranch        *b_HLT_Photon175;   //!
   TBranch        *b_HLT_Photon200;   //!
   TBranch        *b_HLT_Photon100EB_TightID_TightIso;   //!
   TBranch        *b_HLT_Photon110EB_TightID_TightIso;   //!
   TBranch        *b_HLT_Photon120EB_TightID_TightIso;   //!
   TBranch        *b_HLT_Photon100EBHE10;   //!
   TBranch        *b_HLT_Photon100EEHE10;   //!
   TBranch        *b_HLT_Photon100EE_TightID_TightIso;   //!
   TBranch        *b_HLT_Photon50_R9Id90_HE10_IsoM;   //!
   TBranch        *b_HLT_Photon75_R9Id90_HE10_IsoM;   //!
   TBranch        *b_HLT_Photon75_R9Id90_HE10_IsoM_EBOnly_CaloMJJ300_PFJetsMJJ400DEta3;   //!
   TBranch        *b_HLT_Photon75_R9Id90_HE10_IsoM_EBOnly_CaloMJJ400_PFJetsMJJ600DEta3;   //!
   TBranch        *b_HLT_Photon90_R9Id90_HE10_IsoM;   //!
   TBranch        *b_HLT_Photon120_R9Id90_HE10_IsoM;   //!
   TBranch        *b_HLT_Photon165_R9Id90_HE10_IsoM;   //!
   TBranch        *b_HLT_Photon90_CaloIdL_PFHT700;   //!
   TBranch        *b_HLT_Diphoton30_22_R9Id_OR_IsoCaloId_AND_HE_R9Id_Mass90;   //!
   TBranch        *b_HLT_Diphoton30_22_R9Id_OR_IsoCaloId_AND_HE_R9Id_Mass95;   //!
   TBranch        *b_HLT_Diphoton30PV_18PV_R9Id_AND_IsoCaloId_AND_HE_R9Id_PixelVeto_Mass55;   //!
   TBranch        *b_HLT_Diphoton30PV_18PV_R9Id_AND_IsoCaloId_AND_HE_R9Id_NoPixelVeto_Mass55;   //!
   TBranch        *b_HLT_Photon35_TwoProngs35;   //!
   TBranch        *b_HLT_IsoMu24_TwoProngs35;   //!
   TBranch        *b_HLT_Dimuon0_Jpsi_L1_NoOS;   //!
   TBranch        *b_HLT_Dimuon0_Jpsi_NoVertexing_NoOS;   //!
   TBranch        *b_HLT_Dimuon0_Jpsi;   //!
   TBranch        *b_HLT_Dimuon0_Jpsi_NoVertexing;   //!
   TBranch        *b_HLT_Dimuon0_Jpsi_L1_4R_0er1p5R;   //!
   TBranch        *b_HLT_Dimuon0_Jpsi_NoVertexing_L1_4R_0er1p5R;   //!
   TBranch        *b_HLT_Dimuon0_Jpsi3p5_Muon2;   //!
   TBranch        *b_HLT_Dimuon0_Upsilon_L1_4p5;   //!
   TBranch        *b_HLT_Dimuon0_Upsilon_L1_5;   //!
   TBranch        *b_HLT_Dimuon0_Upsilon_L1_4p5NoOS;   //!
   TBranch        *b_HLT_Dimuon0_Upsilon_L1_4p5er2p0;   //!
   TBranch        *b_HLT_Dimuon0_Upsilon_L1_4p5er2p0M;   //!
   TBranch        *b_HLT_Dimuon0_Upsilon_NoVertexing;   //!
   TBranch        *b_HLT_Dimuon0_Upsilon_L1_5M;   //!
   TBranch        *b_HLT_Dimuon0_LowMass_L1_0er1p5R;   //!
   TBranch        *b_HLT_Dimuon0_LowMass_L1_0er1p5;   //!
   TBranch        *b_HLT_Dimuon0_LowMass;   //!
   TBranch        *b_HLT_Dimuon0_LowMass_L1_4;   //!
   TBranch        *b_HLT_Dimuon0_LowMass_L1_4R;   //!
   TBranch        *b_HLT_Dimuon0_LowMass_L1_TM530;   //!
   TBranch        *b_HLT_Dimuon0_Upsilon_Muon_L1_TM0;   //!
   TBranch        *b_HLT_Dimuon0_Upsilon_Muon_NoL1Mass;   //!
   TBranch        *b_HLT_TripleMu_5_3_3_Mass3p8_DZ;   //!
   TBranch        *b_HLT_TripleMu_10_5_5_DZ;   //!
   TBranch        *b_HLT_TripleMu_12_10_5;   //!
   TBranch        *b_HLT_Tau3Mu_Mu7_Mu1_TkMu1_Tau15;   //!
   TBranch        *b_HLT_Tau3Mu_Mu7_Mu1_TkMu1_Tau15_Charge1;   //!
   TBranch        *b_HLT_Tau3Mu_Mu7_Mu1_TkMu1_IsoTau15;   //!
   TBranch        *b_HLT_Tau3Mu_Mu7_Mu1_TkMu1_IsoTau15_Charge1;   //!
   TBranch        *b_HLT_DoubleMu3_DZ_PFMET50_PFMHT60;   //!
   TBranch        *b_HLT_DoubleMu3_DZ_PFMET70_PFMHT70;   //!
   TBranch        *b_HLT_DoubleMu3_DZ_PFMET90_PFMHT90;   //!
   TBranch        *b_HLT_DoubleMu3_Trk_Tau3mu_NoL1Mass;   //!
   TBranch        *b_HLT_DoubleMu4_Jpsi_Displaced;   //!
   TBranch        *b_HLT_DoubleMu4_Jpsi_NoVertexing;   //!
   TBranch        *b_HLT_DoubleMu4_JpsiTrkTrk_Displaced;   //!
   TBranch        *b_HLT_DoubleMu43NoFiltersNoVtx;   //!
   TBranch        *b_HLT_DoubleMu48NoFiltersNoVtx;   //!
   TBranch        *b_HLT_Mu43NoFiltersNoVtx_Photon43_CaloIdL;   //!
   TBranch        *b_HLT_Mu48NoFiltersNoVtx_Photon48_CaloIdL;   //!
   TBranch        *b_HLT_Mu38NoFiltersNoVtxDisplaced_Photon38_CaloIdL;   //!
   TBranch        *b_HLT_Mu43NoFiltersNoVtxDisplaced_Photon43_CaloIdL;   //!
   TBranch        *b_HLT_DoubleMu33NoFiltersNoVtxDisplaced;   //!
   TBranch        *b_HLT_DoubleMu40NoFiltersNoVtxDisplaced;   //!
   TBranch        *b_HLT_DoubleMu20_7_Mass0to30_L1_DM4;   //!
   TBranch        *b_HLT_DoubleMu20_7_Mass0to30_L1_DM4EG;   //!
   TBranch        *b_HLT_HT425;   //!
   TBranch        *b_HLT_HT430_DisplacedDijet40_DisplacedTrack;   //!
   TBranch        *b_HLT_HT500_DisplacedDijet40_DisplacedTrack;   //!
   TBranch        *b_HLT_HT430_DisplacedDijet60_DisplacedTrack;   //!
   TBranch        *b_HLT_HT400_DisplacedDijet40_DisplacedTrack;   //!
   TBranch        *b_HLT_HT650_DisplacedDijet60_Inclusive;   //!
   TBranch        *b_HLT_HT550_DisplacedDijet60_Inclusive;   //!
   TBranch        *b_HLT_DiJet110_35_Mjj650_PFMET110;   //!
   TBranch        *b_HLT_DiJet110_35_Mjj650_PFMET120;   //!
   TBranch        *b_HLT_DiJet110_35_Mjj650_PFMET130;   //!
   TBranch        *b_HLT_TripleJet110_35_35_Mjj650_PFMET110;   //!
   TBranch        *b_HLT_TripleJet110_35_35_Mjj650_PFMET120;   //!
   TBranch        *b_HLT_TripleJet110_35_35_Mjj650_PFMET130;   //!
   TBranch        *b_HLT_Ele30_eta2p1_WPTight_Gsf_CentralPFJet35_EleCleaned;   //!
   TBranch        *b_HLT_Ele28_eta2p1_WPTight_Gsf_HT150;   //!
   TBranch        *b_HLT_Ele28_HighEta_SC20_Mass55;   //!
   TBranch        *b_HLT_DoubleMu20_7_Mass0to30_Photon23;   //!
   TBranch        *b_HLT_Ele15_IsoVVVL_PFHT450_CaloBTagDeepCSV_4p5;   //!
   TBranch        *b_HLT_Ele15_IsoVVVL_PFHT450_PFMET50;   //!
   TBranch        *b_HLT_Ele15_IsoVVVL_PFHT450;   //!
   TBranch        *b_HLT_Ele50_IsoVVVL_PFHT450;   //!
   TBranch        *b_HLT_Ele15_IsoVVVL_PFHT600;   //!
   TBranch        *b_HLT_Mu4_TrkIsoVVL_DiPFJet90_40_DEta3p5_MJJ750_HTT300_PFMETNoMu60;   //!
   TBranch        *b_HLT_Mu8_TrkIsoVVL_DiPFJet40_DEta3p5_MJJ750_HTT300_PFMETNoMu60;   //!
   TBranch        *b_HLT_Mu10_TrkIsoVVL_DiPFJet40_DEta3p5_MJJ750_HTT350_PFMETNoMu60;   //!
   TBranch        *b_HLT_Mu15_IsoVVVL_PFHT450_CaloBTagDeepCSV_4p5;   //!
   TBranch        *b_HLT_Mu15_IsoVVVL_PFHT450_PFMET50;   //!
   TBranch        *b_HLT_Mu15_IsoVVVL_PFHT450;   //!
   TBranch        *b_HLT_Mu50_IsoVVVL_PFHT450;   //!
   TBranch        *b_HLT_Mu15_IsoVVVL_PFHT600;   //!
   TBranch        *b_HLT_Mu3er1p5_PFJet100er2p5_PFMET70_PFMHT70_IDTight;   //!
   TBranch        *b_HLT_Mu3er1p5_PFJet100er2p5_PFMET80_PFMHT80_IDTight;   //!
   TBranch        *b_HLT_Mu3er1p5_PFJet100er2p5_PFMET90_PFMHT90_IDTight;   //!
   TBranch        *b_HLT_Mu3er1p5_PFJet100er2p5_PFMET100_PFMHT100_IDTight;   //!
   TBranch        *b_HLT_Mu3er1p5_PFJet100er2p5_PFMETNoMu70_PFMHTNoMu70_IDTight;   //!
   TBranch        *b_HLT_Mu3er1p5_PFJet100er2p5_PFMETNoMu80_PFMHTNoMu80_IDTight;   //!
   TBranch        *b_HLT_Mu3er1p5_PFJet100er2p5_PFMETNoMu90_PFMHTNoMu90_IDTight;   //!
   TBranch        *b_HLT_Mu3er1p5_PFJet100er2p5_PFMETNoMu100_PFMHTNoMu100_IDTight;   //!
   TBranch        *b_HLT_Dimuon10_PsiPrime_Barrel_Seagulls;   //!
   TBranch        *b_HLT_Dimuon20_Jpsi_Barrel_Seagulls;   //!
   TBranch        *b_HLT_Dimuon12_Upsilon_y1p4;   //!
   TBranch        *b_HLT_Dimuon14_Phi_Barrel_Seagulls;   //!
   TBranch        *b_HLT_Dimuon18_PsiPrime;   //!
   TBranch        *b_HLT_Dimuon25_Jpsi;   //!
   TBranch        *b_HLT_Dimuon18_PsiPrime_noCorrL1;   //!
   TBranch        *b_HLT_Dimuon24_Upsilon_noCorrL1;   //!
   TBranch        *b_HLT_Dimuon24_Phi_noCorrL1;   //!
   TBranch        *b_HLT_Dimuon25_Jpsi_noCorrL1;   //!
   TBranch        *b_HLT_DiMu4_Ele9_CaloIdL_TrackIdL_DZ_Mass3p8;   //!
   TBranch        *b_HLT_DiMu9_Ele9_CaloIdL_TrackIdL_DZ;   //!
   TBranch        *b_HLT_DiMu9_Ele9_CaloIdL_TrackIdL;   //!
   TBranch        *b_HLT_DoubleIsoMu20_eta2p1;   //!
   TBranch        *b_HLT_TrkMu12_DoubleTrkMu5NoFiltersNoVtx;   //!
   TBranch        *b_HLT_TrkMu16_DoubleTrkMu6NoFiltersNoVtx;   //!
   TBranch        *b_HLT_TrkMu17_DoubleTrkMu8NoFiltersNoVtx;   //!
   TBranch        *b_HLT_Mu8;   //!
   TBranch        *b_HLT_Mu17;   //!
   TBranch        *b_HLT_Mu19;   //!
   TBranch        *b_HLT_Mu17_Photon30_IsoCaloId;   //!
   TBranch        *b_HLT_Ele8_CaloIdL_TrackIdL_IsoVL_PFJet30;   //!
   TBranch        *b_HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30;   //!
   TBranch        *b_HLT_Ele15_CaloIdL_TrackIdL_IsoVL_PFJet30;   //!
   TBranch        *b_HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30;   //!
   TBranch        *b_HLT_Ele8_CaloIdM_TrackIdM_PFJet30;   //!
   TBranch        *b_HLT_Ele17_CaloIdM_TrackIdM_PFJet30;   //!
   TBranch        *b_HLT_Ele23_CaloIdM_TrackIdM_PFJet30;   //!
   TBranch        *b_HLT_Ele50_CaloIdVT_GsfTrkIdT_PFJet165;   //!
   TBranch        *b_HLT_Ele115_CaloIdVT_GsfTrkIdT;   //!
   TBranch        *b_HLT_Ele135_CaloIdVT_GsfTrkIdT;   //!
   TBranch        *b_HLT_Ele145_CaloIdVT_GsfTrkIdT;   //!
   TBranch        *b_HLT_Ele200_CaloIdVT_GsfTrkIdT;   //!
   TBranch        *b_HLT_Ele250_CaloIdVT_GsfTrkIdT;   //!
   TBranch        *b_HLT_Ele300_CaloIdVT_GsfTrkIdT;   //!
   TBranch        *b_HLT_PFHT330PT30_QuadPFJet_75_60_45_40_TriplePFBTagDeepCSV_4p5;   //!
   TBranch        *b_HLT_PFHT330PT30_QuadPFJet_75_60_45_40;   //!
   TBranch        *b_HLT_PFHT400_SixPFJet32_DoublePFBTagDeepCSV_2p94;   //!
   TBranch        *b_HLT_PFHT400_SixPFJet32;   //!
   TBranch        *b_HLT_PFHT450_SixPFJet36_PFBTagDeepCSV_1p59;   //!
   TBranch        *b_HLT_PFHT450_SixPFJet36;   //!
   TBranch        *b_HLT_PFHT400_FivePFJet_100_100_60_30_30;   //!
   TBranch        *b_HLT_PFHT400_FivePFJet_100_100_60_30_30_DoublePFBTagDeepCSV_4p5;   //!
   TBranch        *b_HLT_PFHT400_FivePFJet_120_120_60_30_30_DoublePFBTagDeepCSV_4p5;   //!
   TBranch        *b_HLT_PFHT350;   //!
   TBranch        *b_HLT_PFHT350MinPFJet15;   //!
   TBranch        *b_HLT_Photon60_R9Id90_CaloIdL_IsoL;   //!
   TBranch        *b_HLT_Photon60_R9Id90_CaloIdL_IsoL_DisplacedIdL;   //!
   TBranch        *b_HLT_Photon60_R9Id90_CaloIdL_IsoL_DisplacedIdL_PFHT350MinPFJet15;   //!
   TBranch        *b_HLT_ECALHT800;   //!
   TBranch        *b_HLT_DiSC30_18_EIso_AND_HE_Mass70;   //!
   TBranch        *b_HLT_Physics;   //!
   TBranch        *b_HLT_Physics_part0;   //!
   TBranch        *b_HLT_Physics_part1;   //!
   TBranch        *b_HLT_Physics_part2;   //!
   TBranch        *b_HLT_Physics_part3;   //!
   TBranch        *b_HLT_Physics_part4;   //!
   TBranch        *b_HLT_Physics_part5;   //!
   TBranch        *b_HLT_Physics_part6;   //!
   TBranch        *b_HLT_Physics_part7;   //!
   TBranch        *b_HLT_Random;   //!
   TBranch        *b_HLT_ZeroBias;   //!
   TBranch        *b_HLT_ZeroBias_Alignment;   //!
   TBranch        *b_HLT_ZeroBias_part0;   //!
   TBranch        *b_HLT_ZeroBias_part1;   //!
   TBranch        *b_HLT_ZeroBias_part2;   //!
   TBranch        *b_HLT_ZeroBias_part3;   //!
   TBranch        *b_HLT_ZeroBias_part4;   //!
   TBranch        *b_HLT_ZeroBias_part5;   //!
   TBranch        *b_HLT_ZeroBias_part6;   //!
   TBranch        *b_HLT_ZeroBias_part7;   //!
   TBranch        *b_HLT_AK4CaloJet30;   //!
   TBranch        *b_HLT_AK4CaloJet40;   //!
   TBranch        *b_HLT_AK4CaloJet50;   //!
   TBranch        *b_HLT_AK4CaloJet80;   //!
   TBranch        *b_HLT_AK4CaloJet100;   //!
   TBranch        *b_HLT_AK4CaloJet120;   //!
   TBranch        *b_HLT_AK4PFJet30;   //!
   TBranch        *b_HLT_AK4PFJet50;   //!
   TBranch        *b_HLT_AK4PFJet80;   //!
   TBranch        *b_HLT_AK4PFJet100;   //!
   TBranch        *b_HLT_AK4PFJet120;   //!
   TBranch        *b_HLT_SinglePhoton10_Eta3p1ForPPRef;   //!
   TBranch        *b_HLT_SinglePhoton20_Eta3p1ForPPRef;   //!
   TBranch        *b_HLT_SinglePhoton30_Eta3p1ForPPRef;   //!
   TBranch        *b_HLT_Photon20_HoverELoose;   //!
   TBranch        *b_HLT_Photon30_HoverELoose;   //!
   TBranch        *b_HLT_EcalCalibration;   //!
   TBranch        *b_HLT_HcalCalibration;   //!
   TBranch        *b_HLT_L1UnpairedBunchBptxMinus;   //!
   TBranch        *b_HLT_L1UnpairedBunchBptxPlus;   //!
   TBranch        *b_HLT_L1NotBptxOR;   //!
   TBranch        *b_HLT_L1_CDC_SingleMu_3_er1p2_TOP120_DPHI2p618_3p142;   //!
   TBranch        *b_HLT_CDC_L2cosmic_10_er1p0;   //!
   TBranch        *b_HLT_CDC_L2cosmic_5p5_er1p0;   //!
   TBranch        *b_HLT_HcalNZS;   //!
   TBranch        *b_HLT_HcalPhiSym;   //!
   TBranch        *b_HLT_HcalIsolatedbunch;   //!
   TBranch        *b_HLT_IsoTrackHB;   //!
   TBranch        *b_HLT_IsoTrackHE;   //!
   TBranch        *b_HLT_ZeroBias_FirstCollisionAfterAbortGap;   //!
   TBranch        *b_HLT_ZeroBias_IsolatedBunches;   //!
   TBranch        *b_HLT_ZeroBias_FirstCollisionInTrain;   //!
   TBranch        *b_HLT_ZeroBias_LastCollisionInTrain;   //!
   TBranch        *b_HLT_ZeroBias_FirstBXAfterTrain;   //!
   TBranch        *b_HLT_IsoMu24_eta2p1_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr;   //!
   TBranch        *b_HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr_MET90;   //!
   TBranch        *b_HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr_MET100;   //!
   TBranch        *b_HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr_MET110;   //!
   TBranch        *b_HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr_MET120;   //!
   TBranch        *b_HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr_MET130;   //!
   TBranch        *b_HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr_MET140;   //!
   TBranch        *b_HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr;   //!
   TBranch        *b_HLT_MediumChargedIsoPFTau180HighPtRelaxedIso_Trk50_eta2p1_1pr;   //!
   TBranch        *b_HLT_MediumChargedIsoPFTau180HighPtRelaxedIso_Trk50_eta2p1;   //!
   TBranch        *b_HLT_MediumChargedIsoPFTau200HighPtRelaxedIso_Trk50_eta2p1;   //!
   TBranch        *b_HLT_MediumChargedIsoPFTau220HighPtRelaxedIso_Trk50_eta2p1;   //!
   TBranch        *b_HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL;   //!
   TBranch        *b_HLT_Rsq0p35;   //!
   TBranch        *b_HLT_Rsq0p40;   //!
   TBranch        *b_HLT_RsqMR300_Rsq0p09_MR200;   //!
   TBranch        *b_HLT_RsqMR320_Rsq0p09_MR200;   //!
   TBranch        *b_HLT_RsqMR300_Rsq0p09_MR200_4jet;   //!
   TBranch        *b_HLT_RsqMR320_Rsq0p09_MR200_4jet;   //!
   TBranch        *b_HLT_IsoMu27_MET90;   //!
   TBranch        *b_HLT_DoubleMediumChargedIsoPFTau35_Trk1_eta2p1_Reg;   //!
   TBranch        *b_HLT_DoubleMediumChargedIsoPFTau35_Trk1_TightID_eta2p1_Reg;   //!
   TBranch        *b_HLT_DoubleTightChargedIsoPFTau35_Trk1_eta2p1_Reg;   //!
   TBranch        *b_HLT_DoubleTightChargedIsoPFTau35_Trk1_TightID_eta2p1_Reg;   //!
   TBranch        *b_HLT_DoubleMediumChargedIsoPFTauHPS30_L1MaxMass_Trk1_eta2p1_Reg;   //!
   TBranch        *b_HLT_DoubleTightChargedIsoPFTauHPS35_Trk1_eta2p1_Reg;   //!
   TBranch        *b_HLT_DoubleMediumChargedIsoPFTauHPS35_Trk1_TightID_eta2p1_Reg;   //!
   TBranch        *b_HLT_DoubleMediumChargedIsoPFTauHPS35_Trk1_eta2p1_Reg;   //!
   TBranch        *b_HLT_DoubleTightChargedIsoPFTauHPS35_Trk1_TightID_eta2p1_Reg;   //!
   TBranch        *b_HLT_DoubleMediumChargedIsoPFTauHPS40_Trk1_eta2p1_Reg;   //!
   TBranch        *b_HLT_DoubleTightChargedIsoPFTauHPS40_Trk1_eta2p1_Reg;   //!
   TBranch        *b_HLT_DoubleMediumChargedIsoPFTauHPS40_Trk1_TightID_eta2p1_Reg;   //!
   TBranch        *b_HLT_DoubleTightChargedIsoPFTauHPS40_Trk1_TightID_eta2p1_Reg;   //!
   TBranch        *b_HLT_VBF_DoubleLooseChargedIsoPFTau20_Trk1_eta2p1;   //!
   TBranch        *b_HLT_VBF_DoubleLooseChargedIsoPFTauHPS20_Trk1_eta2p1;   //!
   TBranch        *b_HLT_VBF_DoubleMediumChargedIsoPFTauHPS20_Trk1_eta2p1;   //!
   TBranch        *b_HLT_VBF_DoubleTightChargedIsoPFTauHPS20_Trk1_eta2p1;   //!
   TBranch        *b_HLT_Photon50_R9Id90_HE10_IsoM_EBOnly_PFJetsMJJ300DEta3_PFMET50;   //!
   TBranch        *b_HLT_Photon75_R9Id90_HE10_IsoM_EBOnly_PFJetsMJJ300DEta3;   //!
   TBranch        *b_HLT_Photon75_R9Id90_HE10_IsoM_EBOnly_PFJetsMJJ600DEta3;   //!
   TBranch        *b_HLT_PFMET100_PFMHT100_IDTight_PFHT60;   //!
   TBranch        *b_HLT_PFMETNoMu100_PFMHTNoMu100_IDTight_PFHT60;   //!
   TBranch        *b_HLT_PFMETTypeOne100_PFMHT100_IDTight_PFHT60;   //!
   TBranch        *b_HLT_Mu18_Mu9_SameSign;   //!
   TBranch        *b_HLT_Mu18_Mu9_SameSign_DZ;   //!
   TBranch        *b_HLT_Mu18_Mu9;   //!
   TBranch        *b_HLT_Mu18_Mu9_DZ;   //!
   TBranch        *b_HLT_Mu20_Mu10_SameSign;   //!
   TBranch        *b_HLT_Mu20_Mu10_SameSign_DZ;   //!
   TBranch        *b_HLT_Mu20_Mu10;   //!
   TBranch        *b_HLT_Mu20_Mu10_DZ;   //!
   TBranch        *b_HLT_Mu23_Mu12_SameSign;   //!
   TBranch        *b_HLT_Mu23_Mu12_SameSign_DZ;   //!
   TBranch        *b_HLT_Mu23_Mu12;   //!
   TBranch        *b_HLT_Mu23_Mu12_DZ;   //!
   TBranch        *b_HLT_DoubleMu2_Jpsi_DoubleTrk1_Phi1p05;   //!
   TBranch        *b_HLT_DoubleMu2_Jpsi_DoubleTkMu0_Phi;   //!
   TBranch        *b_HLT_DoubleMu3_DCA_PFMET50_PFMHT60;   //!
   TBranch        *b_HLT_TripleMu_5_3_3_Mass3p8_DCA;   //!
   TBranch        *b_HLT_QuadPFJet98_83_71_15_DoublePFBTagDeepCSV_1p3_7p7_VBF1;   //!
   TBranch        *b_HLT_QuadPFJet103_88_75_15_DoublePFBTagDeepCSV_1p3_7p7_VBF1;   //!
   TBranch        *b_HLT_QuadPFJet111_90_80_15_DoublePFBTagDeepCSV_1p3_7p7_VBF1;   //!
   TBranch        *b_HLT_QuadPFJet98_83_71_15_PFBTagDeepCSV_1p3_VBF2;   //!
   TBranch        *b_HLT_QuadPFJet103_88_75_15_PFBTagDeepCSV_1p3_VBF2;   //!
   TBranch        *b_HLT_QuadPFJet105_88_76_15_PFBTagDeepCSV_1p3_VBF2;   //!
   TBranch        *b_HLT_QuadPFJet111_90_80_15_PFBTagDeepCSV_1p3_VBF2;   //!
   TBranch        *b_HLT_QuadPFJet98_83_71_15;   //!
   TBranch        *b_HLT_QuadPFJet103_88_75_15;   //!
   TBranch        *b_HLT_QuadPFJet105_88_76_15;   //!
   TBranch        *b_HLT_QuadPFJet111_90_80_15;   //!
   TBranch        *b_HLT_AK8PFJet330_TrimMass30_PFAK8BTagDeepCSV_p17;   //!
   TBranch        *b_HLT_AK8PFJet330_TrimMass30_PFAK8BTagDeepCSV_p1;   //!
   TBranch        *b_HLT_AK8PFJet330_TrimMass30_PFAK8BoostedDoubleB_p02;   //!
   TBranch        *b_HLT_AK8PFJet330_TrimMass30_PFAK8BoostedDoubleB_np2;   //!
   TBranch        *b_HLT_AK8PFJet330_TrimMass30_PFAK8BoostedDoubleB_np4;   //!
   TBranch        *b_HLT_Diphoton30_18_R9IdL_AND_HE_AND_IsoCaloId_NoPixelVeto_Mass55;   //!
   TBranch        *b_HLT_Diphoton30_18_R9IdL_AND_HE_AND_IsoCaloId_NoPixelVeto;   //!
   TBranch        *b_HLT_Mu12_IP6_ToCSCS;   //!
   TBranch        *b_HLT_Mu12_IP6_part0;   //!
   TBranch        *b_HLT_Mu12_IP6_part1;   //!
   TBranch        *b_HLT_Mu12_IP6_part2;   //!
   TBranch        *b_HLT_Mu12_IP6_part3;   //!
   TBranch        *b_HLT_Mu12_IP6_part4;   //!
   TBranch        *b_HLT_Mu9_IP5_ToCSCS;   //!
   TBranch        *b_HLT_Mu9_IP5_part0;   //!
   TBranch        *b_HLT_Mu9_IP5_part1;   //!
   TBranch        *b_HLT_Mu9_IP5_part2;   //!
   TBranch        *b_HLT_Mu9_IP5_part3;   //!
   TBranch        *b_HLT_Mu9_IP5_part4;   //!
   TBranch        *b_HLT_Mu7_IP4_ToCSCS;   //!
   TBranch        *b_HLT_Mu7_IP4_part0;   //!
   TBranch        *b_HLT_Mu7_IP4_part1;   //!
   TBranch        *b_HLT_Mu7_IP4_part2;   //!
   TBranch        *b_HLT_Mu7_IP4_part3;   //!
   TBranch        *b_HLT_Mu7_IP4_part4;   //!
   TBranch        *b_HLT_Mu9_IP4_ToCSCS;   //!
   TBranch        *b_HLT_Mu9_IP4_part0;   //!
   TBranch        *b_HLT_Mu9_IP4_part1;   //!
   TBranch        *b_HLT_Mu9_IP4_part2;   //!
   TBranch        *b_HLT_Mu9_IP4_part3;   //!
   TBranch        *b_HLT_Mu9_IP4_part4;   //!
   TBranch        *b_HLT_Mu8_IP5_ToCSCS;   //!
   TBranch        *b_HLT_Mu8_IP5_part0;   //!
   TBranch        *b_HLT_Mu8_IP5_part1;   //!
   TBranch        *b_HLT_Mu8_IP5_part2;   //!
   TBranch        *b_HLT_Mu8_IP5_part3;   //!
   TBranch        *b_HLT_Mu8_IP5_part4;   //!
   TBranch        *b_HLT_Mu8_IP6_ToCSCS;   //!
   TBranch        *b_HLT_Mu8_IP6_part0;   //!
   TBranch        *b_HLT_Mu8_IP6_part1;   //!
   TBranch        *b_HLT_Mu8_IP6_part2;   //!
   TBranch        *b_HLT_Mu8_IP6_part3;   //!
   TBranch        *b_HLT_Mu8_IP6_part4;   //!
   TBranch        *b_HLT_Mu9_IP6_ToCSCS;   //!
   TBranch        *b_HLT_Mu9_IP6_part0;   //!
   TBranch        *b_HLT_Mu9_IP6_part1;   //!
   TBranch        *b_HLT_Mu9_IP6_part2;   //!
   TBranch        *b_HLT_Mu9_IP6_part3;   //!
   TBranch        *b_HLT_Mu9_IP6_part4;   //!
   TBranch        *b_HLT_Mu8_IP3_ToCSCS;   //!
   TBranch        *b_HLT_Mu8_IP3_part0;   //!
   TBranch        *b_HLT_Mu8_IP3_part1;   //!
   TBranch        *b_HLT_Mu8_IP3_part2;   //!
   TBranch        *b_HLT_Mu8_IP3_part3;   //!
   TBranch        *b_HLT_Mu8_IP3_part4;   //!
   TBranch        *b_HLT_Mu9_IP0_part0;   //!
   TBranch        *b_HLT_Mu9_IP3_part0;   //!
   TBranch        *b_HLT_QuadPFJet105_88_76_15_DoublePFBTagDeepCSV_1p3_7p7_VBF1;   //!
   TBranch        *b_HLT_TrkMu6NoFiltersNoVtx;   //!
   TBranch        *b_HLT_TrkMu16NoFiltersNoVtx;   //!
   TBranch        *b_HLT_DoubleTrkMu_16_6_NoFiltersNoVtx;   //!
   TBranch        *b_HLT_PPSMaxTracksPerArm1;   //!
   TBranch        *b_HLT_PPSMaxTracksPerRP4;   //!
   TBranch        *b_HLTriggerFinalPath;   //!

   DijetHistosFill(TTree *tree=0, int itype=1, string datasetname="X",
		   string versionname="vX");
   virtual ~DijetHistosFill();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);

   //bool LoadJSON();
   // Code originally from jetphys/HistosFill.C
   void PrintInfo(string info, bool printcout);
   bool LoadJSON(string json);
   bool LoadLumi();
};

#endif

#ifdef DijetHistosFill_cxx
DijetHistosFill::DijetHistosFill(TTree *tree, int itype, string datasetname, string versionname) : fChain(0), isMC(itype), dataset(datasetname), version(versionname)
{

  // Use data set to decide on active branches
  //string& ds = datasetname;
  //isrun3 = (ds=="RunCearly");
  isRun2 = (TString(datasetname.c_str()).Contains("UL2018") ? 4 :
	    (TString(datasetname.c_str()).Contains("UL2017") ? 3 :
	     (TString(datasetname.c_str()).Contains("UL2016APV") ? 1 :
	      (TString(datasetname.c_str()).Contains("UL2016BCD") ? 1 :
	       (TString(datasetname.c_str()).Contains("UL2016EF") ? 1 :
		(TString(datasetname.c_str()).Contains("UL2016") ? 2 :
		 0))))));
  isRun3 = (TString(datasetname.c_str()).Contains("2022") ||
	    TString(datasetname.c_str()).Contains("2023") ||
	    TString(datasetname.c_str()).Contains("Summer22"));
  assert(isRun2 || isRun3);
  assert(!(isRun2 && isRun3));
  isZB = (TString(datasetname.c_str()).Contains("_ZB"));
  isMG = (isMC==2);

// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {

#ifdef SINGLE_TREE
      // The following code should be used if you want this class to access
      // a single tree instead of a chain
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("Memory Directory");
      if (!f || !f->IsOpen()) {
         f = new TFile("Memory Directory");
      }
      f->GetObject("Events",tree);

#else // SINGLE_TREE

      // The following code should be used if you want this class to access a chain
      // of trees.
      TChain * chain = new TChain("Events","");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_100.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_101.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_102.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_103.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_104.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_105.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_106.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_107.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_108.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_109.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_10.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_110.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_111.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_112.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_113.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_114.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_115.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_116.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_117.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_118.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_119.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_11.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_120.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_121.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_122.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_123.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_124.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_125.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_126.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_127.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_128.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_129.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_12.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_130.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_131.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_132.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_133.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_134.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_135.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_136.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_137.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_138.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_139.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_13.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_140.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_141.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_142.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_143.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_144.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_145.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_146.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_147.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_148.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_149.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_14.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_150.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_151.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_152.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_153.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_154.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_155.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_156.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_157.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_158.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_159.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_15.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_160.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_161.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_162.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_163.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_164.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_165.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_166.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_167.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_168.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_169.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_16.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_170.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_171.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_172.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_173.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_174.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_175.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_176.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_177.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_178.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_179.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_17.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_180.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_181.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_182.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_183.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_184.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_185.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_186.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_187.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_188.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_189.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_18.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_190.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_191.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_192.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_193.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_194.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_195.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_196.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_197.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_198.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_199.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_19.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_1.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_200.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_201.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_202.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_203.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_204.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_205.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_206.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_207.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_208.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_209.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_20.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_210.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_211.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_212.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_213.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_214.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_215.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_216.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_217.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_218.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_219.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_21.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_220.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_221.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_222.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_223.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_224.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_225.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_226.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_227.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_228.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_229.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_22.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_230.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_231.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_232.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_233.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_234.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_235.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_236.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_237.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_238.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_239.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_23.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_240.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_241.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_242.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_243.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_244.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_245.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_246.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_247.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_248.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_249.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_24.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_250.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_251.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_252.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_253.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_254.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_255.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_256.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_257.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_258.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_259.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_25.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_260.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_26.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_27.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_28.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_29.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_2.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_30.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_31.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_32.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_33.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_34.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_35.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_36.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_37.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_38.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_39.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_3.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_40.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_41.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_42.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_43.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_44.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_45.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_46.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_47.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_48.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_49.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_4.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_50.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_51.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_52.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_53.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_54.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_55.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_56.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_57.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_58.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_59.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_5.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_60.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_61.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_62.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_63.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_64.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_65.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_66.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_67.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_68.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_69.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_6.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_70.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_71.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_72.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_73.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_74.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_75.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_76.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_77.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_78.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_79.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_7.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_80.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_81.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_82.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_83.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_84.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_85.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_86.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_87.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_88.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_89.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_8.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_90.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_91.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_92.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_93.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_94.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_95.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_96.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_97.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_98.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_99.root/Events");
      chain->Add("/media/DATA/JME_NANO_MC/2022/QCD_Pt-15to7000_TuneCP5_Flat2018_13p6TeV_pythia8/JMENanoRun3_v1p1_MC22_122/220814_132403/0000/tree_9.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_100.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_101.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_102.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_103.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_104.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_105.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_106.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_107.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_108.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_109.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_10.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_110.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_111.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_112.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_113.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_114.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_115.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_116.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_117.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_118.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_119.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_11.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_120.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_121.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_122.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_123.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_124.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_125.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_126.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_127.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_128.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_129.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_12.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_130.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_131.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_132.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_133.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_134.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_135.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_136.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_137.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_138.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_139.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_13.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_140.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_141.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_142.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_143.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_144.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_145.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_146.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_147.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_148.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_149.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_14.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_150.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_151.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_152.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_153.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_154.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_155.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_156.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_157.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_158.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_159.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_15.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_160.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_161.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_162.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_163.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_164.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_165.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_166.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_167.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_168.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_169.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_16.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_170.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_171.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_172.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_173.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_174.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_175.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_176.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_177.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_178.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_179.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_17.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_180.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_181.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_182.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_183.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_184.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_185.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_186.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_187.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_188.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_18.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_19.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_1.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_20.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_21.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_22.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_23.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_24.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_25.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_26.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_27.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_28.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_29.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_2.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_30.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_31.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_32.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_33.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_34.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_35.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_36.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_37.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_38.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_39.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_3.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_40.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_41.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_42.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_43.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_44.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_45.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_46.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_47.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_48.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_49.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_4.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_50.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_51.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_52.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_53.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_54.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_55.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_56.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_57.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_58.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_59.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_5.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_60.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_61.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_62.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_63.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_64.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_65.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_66.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_67.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_68.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_69.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_6.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_70.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_71.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_72.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_73.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_74.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_75.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_76.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_77.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_78.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_79.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_7.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_80.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_81.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_82.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_83.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_84.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_85.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_86.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_87.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_88.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_89.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_8.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_90.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_91.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_92.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_93.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_94.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_95.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_96.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_97.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_98.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_99.root/Events");
      chain->Add("/media/DATA/JME_NANO_DATA/2022/JMENanoRun3_v1p1_Run2022C-PromptReco/220814_132239/0000/tree_9.root/Events");
      tree = chain;
#endif // SINGLE_TREE

   }
   Init(tree);
}

DijetHistosFill::~DijetHistosFill()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t DijetHistosFill::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t DijetHistosFill::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void DijetHistosFill::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("run", &run, &b_run);
   fChain->SetBranchAddress("luminosityBlock", &luminosityBlock, &b_luminosityBlock);
   fChain->SetBranchAddress("event", &event, &b_event);
   //fChain->SetBranchAddress("bunchCrossing", &bunchCrossing, &b_bunchCrossing);
   if (isMC) fChain->SetBranchAddress("HTXS_Higgs_pt", &HTXS_Higgs_pt, &b_HTXS_Higgs_pt);
   if (isMC) fChain->SetBranchAddress("HTXS_Higgs_y", &HTXS_Higgs_y, &b_HTXS_Higgs_y);
   if (isMC) fChain->SetBranchAddress("HTXS_stage1_1_cat_pTjet25GeV", &HTXS_stage1_1_cat_pTjet25GeV, &b_HTXS_stage1_1_cat_pTjet25GeV);
   if (isMC) fChain->SetBranchAddress("HTXS_stage1_1_cat_pTjet30GeV", &HTXS_stage1_1_cat_pTjet30GeV, &b_HTXS_stage1_1_cat_pTjet30GeV);
   if (isMC) fChain->SetBranchAddress("HTXS_stage1_1_fine_cat_pTjet25GeV", &HTXS_stage1_1_fine_cat_pTjet25GeV, &b_HTXS_stage1_1_fine_cat_pTjet25GeV);
   if (isMC) fChain->SetBranchAddress("HTXS_stage1_1_fine_cat_pTjet30GeV", &HTXS_stage1_1_fine_cat_pTjet30GeV, &b_HTXS_stage1_1_fine_cat_pTjet30GeV);
   if (isMC) fChain->SetBranchAddress("HTXS_stage1_2_cat_pTjet25GeV", &HTXS_stage1_2_cat_pTjet25GeV, &b_HTXS_stage1_2_cat_pTjet25GeV);
   if (isMC) fChain->SetBranchAddress("HTXS_stage1_2_cat_pTjet30GeV", &HTXS_stage1_2_cat_pTjet30GeV, &b_HTXS_stage1_2_cat_pTjet30GeV);
   if (isMC) fChain->SetBranchAddress("HTXS_stage1_2_fine_cat_pTjet25GeV", &HTXS_stage1_2_fine_cat_pTjet25GeV, &b_HTXS_stage1_2_fine_cat_pTjet25GeV);
   if (isMC) fChain->SetBranchAddress("HTXS_stage1_2_fine_cat_pTjet30GeV", &HTXS_stage1_2_fine_cat_pTjet30GeV, &b_HTXS_stage1_2_fine_cat_pTjet30GeV);
   if (isMC) fChain->SetBranchAddress("HTXS_stage_0", &HTXS_stage_0, &b_HTXS_stage_0);
   if (isMC) fChain->SetBranchAddress("HTXS_stage_1_pTjet25", &HTXS_stage_1_pTjet25, &b_HTXS_stage_1_pTjet25);
   if (isMC) fChain->SetBranchAddress("HTXS_stage_1_pTjet30", &HTXS_stage_1_pTjet30, &b_HTXS_stage_1_pTjet30);
   if (isMC) fChain->SetBranchAddress("HTXS_njets25", &HTXS_njets25, &b_HTXS_njets25);
   if (isMC) fChain->SetBranchAddress("HTXS_njets30", &HTXS_njets30, &b_HTXS_njets30);
   //fChain->SetBranchAddress("BeamSpot_sigmaZ", &BeamSpot_sigmaZ, &b_BeamSpot_sigmaZ);
   //fChain->SetBranchAddress("BeamSpot_sigmaZError", &BeamSpot_sigmaZError, &b_BeamSpot_sigmaZError);
   //fChain->SetBranchAddress("BeamSpot_z", &BeamSpot_z, &b_BeamSpot_z);
   //fChain->SetBranchAddress("BeamSpot_zError", &BeamSpot_zError, &b_BeamSpot_zError);
   //fChain->SetBranchAddress("BeamSpot_type", &BeamSpot_type, &b_BeamSpot_type);
   //if (isMC) fChain->SetBranchAddress("btagWeight_CSVV2", &btagWeight_CSVV2, &b_btagWeight_CSVV2);
   //if (isMC) fChain->SetBranchAddress("btagWeight_DeepCSVB", &btagWeight_DeepCSVB, &b_btagWeight_DeepCSVB);
   fChain->SetBranchAddress("CaloMET_phi", &CaloMET_phi, &b_CaloMET_phi);
   fChain->SetBranchAddress("CaloMET_pt", &CaloMET_pt, &b_CaloMET_pt);
   fChain->SetBranchAddress("CaloMET_sumEt", &CaloMET_sumEt, &b_CaloMET_sumEt);
   fChain->SetBranchAddress("ChsMET_phi", &ChsMET_phi, &b_ChsMET_phi);
   fChain->SetBranchAddress("ChsMET_pt", &ChsMET_pt, &b_ChsMET_pt);
   fChain->SetBranchAddress("ChsMET_sumEt", &ChsMET_sumEt, &b_ChsMET_sumEt);
   fChain->SetBranchAddress("nCorrT1METJet", &nCorrT1METJet, &b_nCorrT1METJet);
   fChain->SetBranchAddress("CorrT1METJet_area", CorrT1METJet_area, &b_CorrT1METJet_area);
   fChain->SetBranchAddress("CorrT1METJet_eta", CorrT1METJet_eta, &b_CorrT1METJet_eta);
   fChain->SetBranchAddress("CorrT1METJet_muonSubtrFactor", CorrT1METJet_muonSubtrFactor, &b_CorrT1METJet_muonSubtrFactor);
   fChain->SetBranchAddress("CorrT1METJet_phi", CorrT1METJet_phi, &b_CorrT1METJet_phi);
   fChain->SetBranchAddress("CorrT1METJet_rawPt", CorrT1METJet_rawPt, &b_CorrT1METJet_rawPt);
   fChain->SetBranchAddress("DeepMETResolutionTune_phi", &DeepMETResolutionTune_phi, &b_DeepMETResolutionTune_phi);
   fChain->SetBranchAddress("DeepMETResolutionTune_pt", &DeepMETResolutionTune_pt, &b_DeepMETResolutionTune_pt);
   fChain->SetBranchAddress("DeepMETResponseTune_phi", &DeepMETResponseTune_phi, &b_DeepMETResponseTune_phi);
   fChain->SetBranchAddress("DeepMETResponseTune_pt", &DeepMETResponseTune_pt, &b_DeepMETResponseTune_pt);
   fChain->SetBranchAddress("nElectron", &nElectron, &b_nElectron);
   fChain->SetBranchAddress("Electron_deltaEtaSC", Electron_deltaEtaSC, &b_Electron_deltaEtaSC);
   fChain->SetBranchAddress("Electron_dr03EcalRecHitSumEt", Electron_dr03EcalRecHitSumEt, &b_Electron_dr03EcalRecHitSumEt);
   fChain->SetBranchAddress("Electron_dr03HcalDepth1TowerSumEt", Electron_dr03HcalDepth1TowerSumEt, &b_Electron_dr03HcalDepth1TowerSumEt);
   fChain->SetBranchAddress("Electron_dr03TkSumPt", Electron_dr03TkSumPt, &b_Electron_dr03TkSumPt);
   fChain->SetBranchAddress("Electron_dr03TkSumPtHEEP", Electron_dr03TkSumPtHEEP, &b_Electron_dr03TkSumPtHEEP);
   fChain->SetBranchAddress("Electron_dxy", Electron_dxy, &b_Electron_dxy);
   fChain->SetBranchAddress("Electron_dxyErr", Electron_dxyErr, &b_Electron_dxyErr);
   fChain->SetBranchAddress("Electron_dz", Electron_dz, &b_Electron_dz);
   fChain->SetBranchAddress("Electron_dzErr", Electron_dzErr, &b_Electron_dzErr);
   fChain->SetBranchAddress("Electron_eInvMinusPInv", Electron_eInvMinusPInv, &b_Electron_eInvMinusPInv);
   fChain->SetBranchAddress("Electron_energyErr", Electron_energyErr, &b_Electron_energyErr);
   fChain->SetBranchAddress("Electron_eta", Electron_eta, &b_Electron_eta);
   fChain->SetBranchAddress("Electron_hoe", Electron_hoe, &b_Electron_hoe);
   fChain->SetBranchAddress("Electron_ip3d", Electron_ip3d, &b_Electron_ip3d);
   fChain->SetBranchAddress("Electron_jetPtRelv2", Electron_jetPtRelv2, &b_Electron_jetPtRelv2);
   fChain->SetBranchAddress("Electron_jetRelIso", Electron_jetRelIso, &b_Electron_jetRelIso);
   fChain->SetBranchAddress("Electron_mass", Electron_mass, &b_Electron_mass);
   fChain->SetBranchAddress("Electron_miniPFRelIso_all", Electron_miniPFRelIso_all, &b_Electron_miniPFRelIso_all);
   fChain->SetBranchAddress("Electron_miniPFRelIso_chg", Electron_miniPFRelIso_chg, &b_Electron_miniPFRelIso_chg);
   //fChain->SetBranchAddress("Electron_mvaHZZIso", Electron_mvaHZZIso, &b_Electron_mvaHZZIso);
   //fChain->SetBranchAddress("Electron_mvaIso", Electron_mvaIso, &b_Electron_mvaIso);
   //fChain->SetBranchAddress("Electron_mvaNoIso", Electron_mvaNoIso, &b_Electron_mvaNoIso);
   fChain->SetBranchAddress("Electron_pfRelIso03_all", Electron_pfRelIso03_all, &b_Electron_pfRelIso03_all);
   fChain->SetBranchAddress("Electron_pfRelIso03_chg", Electron_pfRelIso03_chg, &b_Electron_pfRelIso03_chg);
   fChain->SetBranchAddress("Electron_phi", Electron_phi, &b_Electron_phi);
   fChain->SetBranchAddress("Electron_pt", Electron_pt, &b_Electron_pt);
   fChain->SetBranchAddress("Electron_r9", Electron_r9, &b_Electron_r9);
   fChain->SetBranchAddress("Electron_scEtOverPt", Electron_scEtOverPt, &b_Electron_scEtOverPt);
   fChain->SetBranchAddress("Electron_sieie", Electron_sieie, &b_Electron_sieie);
   fChain->SetBranchAddress("Electron_sip3d", Electron_sip3d, &b_Electron_sip3d);
   fChain->SetBranchAddress("Electron_mvaTTH", Electron_mvaTTH, &b_Electron_mvaTTH);
   fChain->SetBranchAddress("Electron_charge", Electron_charge, &b_Electron_charge);
   fChain->SetBranchAddress("Electron_cutBased", Electron_cutBased, &b_Electron_cutBased);
   fChain->SetBranchAddress("Electron_jetIdx", Electron_jetIdx, &b_Electron_jetIdx);
   fChain->SetBranchAddress("Electron_pdgId", Electron_pdgId, &b_Electron_pdgId);
   fChain->SetBranchAddress("Electron_photonIdx", Electron_photonIdx, &b_Electron_photonIdx);
   fChain->SetBranchAddress("Electron_tightCharge", Electron_tightCharge, &b_Electron_tightCharge);
   fChain->SetBranchAddress("Electron_vidNestedWPBitmap", Electron_vidNestedWPBitmap, &b_Electron_vidNestedWPBitmap);
   fChain->SetBranchAddress("Electron_vidNestedWPBitmapHEEP", Electron_vidNestedWPBitmapHEEP, &b_Electron_vidNestedWPBitmapHEEP);
   //fChain->SetBranchAddress("Electron_fsrPhotonIdx", Electron_fsrPhotonIdx, &b_Electron_fsrPhotonIdx);
   fChain->SetBranchAddress("Electron_convVeto", Electron_convVeto, &b_Electron_convVeto);
   fChain->SetBranchAddress("Electron_cutBased_HEEP", Electron_cutBased_HEEP, &b_Electron_cutBased_HEEP);
   fChain->SetBranchAddress("Electron_isPFcand", Electron_isPFcand, &b_Electron_isPFcand);
   fChain->SetBranchAddress("Electron_jetNDauCharged", Electron_jetNDauCharged, &b_Electron_jetNDauCharged);
   fChain->SetBranchAddress("Electron_lostHits", Electron_lostHits, &b_Electron_lostHits);
   //fChain->SetBranchAddress("Electron_mvaIso_WP80", Electron_mvaIso_WP80, &b_Electron_mvaIso_WP80);
   //fChain->SetBranchAddress("Electron_mvaIso_WP90", Electron_mvaIso_WP90, &b_Electron_mvaIso_WP90);
   //fChain->SetBranchAddress("Electron_mvaIso_WPL", Electron_mvaIso_WPL, &b_Electron_mvaIso_WPL);
   //fChain->SetBranchAddress("Electron_mvaNoIso_WP80", Electron_mvaNoIso_WP80, &b_Electron_mvaNoIso_WP80);
   //fChain->SetBranchAddress("Electron_mvaNoIso_WP90", Electron_mvaNoIso_WP90, &b_Electron_mvaNoIso_WP90);
   //fChain->SetBranchAddress("Electron_mvaNoIso_WPL", Electron_mvaNoIso_WPL, &b_Electron_mvaNoIso_WPL);
   fChain->SetBranchAddress("Electron_seedGain", Electron_seedGain, &b_Electron_seedGain);

   fChain->SetBranchAddress("nFsrPhoton", &nFsrPhoton, &b_nFsrPhoton);
   fChain->SetBranchAddress("FsrPhoton_dROverEt2", FsrPhoton_dROverEt2, &b_FsrPhoton_dROverEt2);
   fChain->SetBranchAddress("FsrPhoton_eta", FsrPhoton_eta, &b_FsrPhoton_eta);
   fChain->SetBranchAddress("FsrPhoton_phi", FsrPhoton_phi, &b_FsrPhoton_phi);
   fChain->SetBranchAddress("FsrPhoton_pt", FsrPhoton_pt, &b_FsrPhoton_pt);
   fChain->SetBranchAddress("FsrPhoton_relIso03", FsrPhoton_relIso03, &b_FsrPhoton_relIso03);
   //fChain->SetBranchAddress("FsrPhoton_electronIdx", FsrPhoton_electronIdx, &b_FsrPhoton_electronIdx);
   fChain->SetBranchAddress("FsrPhoton_muonIdx", FsrPhoton_muonIdx, &b_FsrPhoton_muonIdx);
   if (isMC) fChain->SetBranchAddress("nGenJetAK8", &nGenJetAK8, &b_nGenJetAK8);
   if (isMC) fChain->SetBranchAddress("GenJetAK8_eta", GenJetAK8_eta, &b_GenJetAK8_eta);
   if (isMC) fChain->SetBranchAddress("GenJetAK8_mass", GenJetAK8_mass, &b_GenJetAK8_mass);
   if (isMC) fChain->SetBranchAddress("GenJetAK8_phi", GenJetAK8_phi, &b_GenJetAK8_phi);
   if (isMC) fChain->SetBranchAddress("GenJetAK8_pt", GenJetAK8_pt, &b_GenJetAK8_pt);
   //if (isMC) fChain->SetBranchAddress("GenJetAK8_nConstituents", GenJetAK8_nConstituents, &b_GenJetAK8_nConstituents);
   if (isMC) fChain->SetBranchAddress("nGenJet", &nGenJet, &b_nGenJet);
   if (isMC) fChain->SetBranchAddress("GenJet_eta", GenJet_eta, &b_GenJet_eta);
   if (isMC) fChain->SetBranchAddress("GenJet_mass", GenJet_mass, &b_GenJet_mass);
   if (isMC) fChain->SetBranchAddress("GenJet_phi", GenJet_phi, &b_GenJet_phi);
   if (isMC) fChain->SetBranchAddress("GenJet_pt", GenJet_pt, &b_GenJet_pt);
   //if (isMC) fChain->SetBranchAddress("GenJet_nConstituents", GenJet_nConstituents, &b_GenJet_nConstituents);
   if (isMC) fChain->SetBranchAddress("nGenPart", &nGenPart, &b_nGenPart);
   if (isMC) fChain->SetBranchAddress("GenPart_eta", GenPart_eta, &b_GenPart_eta);
   if (isMC) fChain->SetBranchAddress("GenPart_mass", GenPart_mass, &b_GenPart_mass);
   if (isMC) fChain->SetBranchAddress("GenPart_phi", GenPart_phi, &b_GenPart_phi);
   if (isMC) fChain->SetBranchAddress("GenPart_pt", GenPart_pt, &b_GenPart_pt);
   if (isMC) fChain->SetBranchAddress("GenPart_genPartIdxMother", GenPart_genPartIdxMother, &b_GenPart_genPartIdxMother);
   if (isMC) fChain->SetBranchAddress("GenPart_pdgId", GenPart_pdgId, &b_GenPart_pdgId);
   if (isMC) fChain->SetBranchAddress("GenPart_status", GenPart_status, &b_GenPart_status);
   if (isMC) fChain->SetBranchAddress("GenPart_statusFlags", GenPart_statusFlags, &b_GenPart_statusFlags);
   //if (isMC) fChain->SetBranchAddress("nGenProton", &nGenProton, &b_nGenProton);
   //if (isMC) fChain->SetBranchAddress("GenProton_px", GenProton_px, &b_GenProton_px);
   //if (isMC) fChain->SetBranchAddress("GenProton_py", GenProton_py, &b_GenProton_py);
   //if (isMC) fChain->SetBranchAddress("GenProton_pz", GenProton_pz, &b_GenProton_pz);
   //if (isMC) fChain->SetBranchAddress("GenProton_vz", GenProton_vz, &b_GenProton_vz);
   //if (isMC) fChain->SetBranchAddress("GenProton_isPU", GenProton_isPU, &b_GenProton_isPU);
   if (isMC) fChain->SetBranchAddress("nSubGenJetAK8", &nSubGenJetAK8, &b_nSubGenJetAK8);
   if (isMC) fChain->SetBranchAddress("SubGenJetAK8_eta", SubGenJetAK8_eta, &b_SubGenJetAK8_eta);
   if (isMC) fChain->SetBranchAddress("SubGenJetAK8_mass", SubGenJetAK8_mass, &b_SubGenJetAK8_mass);
   if (isMC) fChain->SetBranchAddress("SubGenJetAK8_phi", SubGenJetAK8_phi, &b_SubGenJetAK8_phi);
   if (isMC) fChain->SetBranchAddress("SubGenJetAK8_pt", SubGenJetAK8_pt, &b_SubGenJetAK8_pt);
   if (isMC) fChain->SetBranchAddress("Generator_binvar", &Generator_binvar, &b_Generator_binvar);
   if (isMG) fChain->SetBranchAddress("LHE_HT", &LHE_HT, &b_LHE_HT); // added by hand
   if (isMC) fChain->SetBranchAddress("Generator_scalePDF", &Generator_scalePDF, &b_Generator_scalePDF);
   if (isMC) fChain->SetBranchAddress("Generator_weight", &Generator_weight, &b_Generator_weight);
   if (isMC) fChain->SetBranchAddress("Generator_x1", &Generator_x1, &b_Generator_x1);
   if (isMC) fChain->SetBranchAddress("Generator_x2", &Generator_x2, &b_Generator_x2);
   if (isMC) fChain->SetBranchAddress("Generator_xpdf1", &Generator_xpdf1, &b_Generator_xpdf1);
   if (isMC) fChain->SetBranchAddress("Generator_xpdf2", &Generator_xpdf2, &b_Generator_xpdf2);
   if (isMC) fChain->SetBranchAddress("Generator_id1", &Generator_id1, &b_Generator_id1);
   if (isMC) fChain->SetBranchAddress("Generator_id2", &Generator_id2, &b_Generator_id2);
   if (isMC) fChain->SetBranchAddress("GenVtx_x", &GenVtx_x, &b_GenVtx_x);
   if (isMC) fChain->SetBranchAddress("GenVtx_y", &GenVtx_y, &b_GenVtx_y);
   if (isMC) fChain->SetBranchAddress("GenVtx_z", &GenVtx_z, &b_GenVtx_z);
   if (isMC) fChain->SetBranchAddress("nGenVisTau", &nGenVisTau, &b_nGenVisTau);
   if (isMC) fChain->SetBranchAddress("GenVisTau_eta", GenVisTau_eta, &b_GenVisTau_eta);
   if (isMC) fChain->SetBranchAddress("GenVisTau_mass", GenVisTau_mass, &b_GenVisTau_mass);
   if (isMC) fChain->SetBranchAddress("GenVisTau_phi", GenVisTau_phi, &b_GenVisTau_phi);
   if (isMC) fChain->SetBranchAddress("GenVisTau_pt", GenVisTau_pt, &b_GenVisTau_pt);
   if (isMC) fChain->SetBranchAddress("GenVisTau_charge", GenVisTau_charge, &b_GenVisTau_charge);
   if (isMC) fChain->SetBranchAddress("GenVisTau_genPartIdxMother", GenVisTau_genPartIdxMother, &b_GenVisTau_genPartIdxMother);
   if (isMC) fChain->SetBranchAddress("GenVisTau_status", GenVisTau_status, &b_GenVisTau_status);
   if (isMC) fChain->SetBranchAddress("genWeight", &genWeight, &b_genWeight);
   if (isMC) fChain->SetBranchAddress("nPSWeight", &nPSWeight, &b_nPSWeight);
   if (isMC) fChain->SetBranchAddress("PSWeight", PSWeight, &b_PSWeight);
   fChain->SetBranchAddress("nIsoTrack", &nIsoTrack, &b_nIsoTrack);
   fChain->SetBranchAddress("IsoTrack_dxy", IsoTrack_dxy, &b_IsoTrack_dxy);
   fChain->SetBranchAddress("IsoTrack_dz", IsoTrack_dz, &b_IsoTrack_dz);
   fChain->SetBranchAddress("IsoTrack_eta", IsoTrack_eta, &b_IsoTrack_eta);
   fChain->SetBranchAddress("IsoTrack_pfRelIso03_all", IsoTrack_pfRelIso03_all, &b_IsoTrack_pfRelIso03_all);
   fChain->SetBranchAddress("IsoTrack_pfRelIso03_chg", IsoTrack_pfRelIso03_chg, &b_IsoTrack_pfRelIso03_chg);
   fChain->SetBranchAddress("IsoTrack_phi", IsoTrack_phi, &b_IsoTrack_phi);
   fChain->SetBranchAddress("IsoTrack_pt", IsoTrack_pt, &b_IsoTrack_pt);
   fChain->SetBranchAddress("IsoTrack_miniPFRelIso_all", IsoTrack_miniPFRelIso_all, &b_IsoTrack_miniPFRelIso_all);
   fChain->SetBranchAddress("IsoTrack_miniPFRelIso_chg", IsoTrack_miniPFRelIso_chg, &b_IsoTrack_miniPFRelIso_chg);
   fChain->SetBranchAddress("IsoTrack_charge", IsoTrack_charge, &b_IsoTrack_charge);
   fChain->SetBranchAddress("IsoTrack_fromPV", IsoTrack_fromPV, &b_IsoTrack_fromPV);
   fChain->SetBranchAddress("IsoTrack_pdgId", IsoTrack_pdgId, &b_IsoTrack_pdgId);
   fChain->SetBranchAddress("IsoTrack_isHighPurityTrack", IsoTrack_isHighPurityTrack, &b_IsoTrack_isHighPurityTrack);
   fChain->SetBranchAddress("IsoTrack_isPFcand", IsoTrack_isPFcand, &b_IsoTrack_isPFcand);
   fChain->SetBranchAddress("IsoTrack_isFromLostTrack", IsoTrack_isFromLostTrack, &b_IsoTrack_isFromLostTrack);

   //if (isMC) fChain->SetBranchAddress("nGenJetAK8ForJEC", &nGenJetAK8ForJEC, &b_nGenJetAK8ForJEC);
   //if (isMC) fChain->SetBranchAddress("GenJetAK8ForJEC_eta", GenJetAK8ForJEC_eta, &b_GenJetAK8ForJEC_eta);
   //if (isMC) fChain->SetBranchAddress("GenJetAK8ForJEC_mass", GenJetAK8ForJEC_mass, &b_GenJetAK8ForJEC_mass);
   //if (isMC) fChain->SetBranchAddress("GenJetAK8ForJEC_phi", GenJetAK8ForJEC_phi, &b_GenJetAK8ForJEC_phi);
   //if (isMC) fChain->SetBranchAddress("GenJetAK8ForJEC_pt", GenJetAK8ForJEC_pt, &b_GenJetAK8ForJEC_pt);
   //if (isMC) fChain->SetBranchAddress("GenJetAK8ForJEC_nConstituents", GenJetAK8ForJEC_nConstituents, &b_GenJetAK8ForJEC_nConstituents);

   fChain->SetBranchAddress("nJet", &nJet, &b_nJet);
   fChain->SetBranchAddress("Jet_area", Jet_area, &b_Jet_area);
   //   fChain->SetBranchAddress("Jet_btagCSVV2", Jet_btagCSVV2, &b_Jet_btagCSVV2);
   //   fChain->SetBranchAddress("Jet_btagDeepB", Jet_btagDeepB, &b_Jet_btagDeepB);
   //   fChain->SetBranchAddress("Jet_btagDeepCvB", Jet_btagDeepCvB, &b_Jet_btagDeepCvB);
   //   fChain->SetBranchAddress("Jet_btagDeepCvL", Jet_btagDeepCvL, &b_Jet_btagDeepCvL);
   //   fChain->SetBranchAddress("Jet_btagDeepFlavB", Jet_btagDeepFlavB, &b_Jet_btagDeepFlavB);
   fChain->SetBranchAddress("Jet_btagDeepFlavCvB", Jet_btagDeepFlavCvB, &b_Jet_btagDeepFlavCvB);
   fChain->SetBranchAddress("Jet_btagDeepFlavCvL", Jet_btagDeepFlavCvL, &b_Jet_btagDeepFlavCvL);
   //   fChain->SetBranchAddress("Jet_btagDeepFlavG", Jet_btagDeepFlavG, &b_Jet_btagDeepFlavG);
   fChain->SetBranchAddress("Jet_btagDeepFlavQG", Jet_btagDeepFlavQG, &b_Jet_btagDeepFlavQG);
   //   fChain->SetBranchAddress("Jet_btagDeepFlavUDS", Jet_btagDeepFlavUDS, &b_Jet_btagDeepFlavUDS);
   fChain->SetBranchAddress("Jet_chEmEF", Jet_chEmEF, &b_Jet_chEmEF);
   fChain->SetBranchAddress("Jet_chHEF", Jet_chHEF, &b_Jet_chHEF);
   fChain->SetBranchAddress("Jet_eta", Jet_eta, &b_Jet_eta);
   //   fChain->SetBranchAddress("Jet_hfEmEF", Jet_hfEmEF, &b_Jet_hfEmEF);
   //   fChain->SetBranchAddress("Jet_hfHEF", Jet_hfHEF, &b_Jet_hfHEF);
   fChain->SetBranchAddress("Jet_hfsigmaEtaEta", Jet_hfsigmaEtaEta, &b_Jet_hfsigmaEtaEta);
   fChain->SetBranchAddress("Jet_hfsigmaPhiPhi", Jet_hfsigmaPhiPhi, &b_Jet_hfsigmaPhiPhi);
   fChain->SetBranchAddress("Jet_mass", Jet_mass, &b_Jet_mass);
   fChain->SetBranchAddress("Jet_muEF", Jet_muEF, &b_Jet_muEF);
   fChain->SetBranchAddress("Jet_muonSubtrFactor", Jet_muonSubtrFactor, &b_Jet_muonSubtrFactor);
   fChain->SetBranchAddress("Jet_neEmEF", Jet_neEmEF, &b_Jet_neEmEF);
   fChain->SetBranchAddress("Jet_neHEF", Jet_neHEF, &b_Jet_neHEF);
   //   fChain->SetBranchAddress("Jet_particleNetAK4_B", Jet_particleNetAK4_B, &b_Jet_particleNetAK4_B);
   //   fChain->SetBranchAddress("Jet_particleNetAK4_CvsB", Jet_particleNetAK4_CvsB, &b_Jet_particleNetAK4_CvsB);
   //   fChain->SetBranchAddress("Jet_particleNetAK4_CvsL", Jet_particleNetAK4_CvsL, &b_Jet_particleNetAK4_CvsL);
   //   fChain->SetBranchAddress("Jet_particleNetAK4_QvsG", Jet_particleNetAK4_QvsG, &b_Jet_particleNetAK4_QvsG);
   //   fChain->SetBranchAddress("Jet_particleNetAK4_puIdDisc", Jet_particleNetAK4_puIdDisc, &b_Jet_particleNetAK4_puIdDisc);
   fChain->SetBranchAddress("Jet_phi", Jet_phi, &b_Jet_phi);
   fChain->SetBranchAddress("Jet_pt", Jet_pt, &b_Jet_pt);
   //   fChain->SetBranchAddress("Jet_puId_beta", Jet_puId_beta, &b_Jet_puId_beta);
   //   fChain->SetBranchAddress("Jet_puId_dR2Mean", Jet_puId_dR2Mean, &b_Jet_puId_dR2Mean);
   //   fChain->SetBranchAddress("Jet_puId_frac01", Jet_puId_frac01, &b_Jet_puId_frac01);
   //   fChain->SetBranchAddress("Jet_puId_frac02", Jet_puId_frac02, &b_Jet_puId_frac02);
   //   fChain->SetBranchAddress("Jet_puId_frac03", Jet_puId_frac03, &b_Jet_puId_frac03);
   //   fChain->SetBranchAddress("Jet_puId_frac04", Jet_puId_frac04, &b_Jet_puId_frac04);
   //   fChain->SetBranchAddress("Jet_puId_jetR", Jet_puId_jetR, &b_Jet_puId_jetR);
   //   fChain->SetBranchAddress("Jet_puId_jetRchg", Jet_puId_jetRchg, &b_Jet_puId_jetRchg);
   //   fChain->SetBranchAddress("Jet_puId_majW", Jet_puId_majW, &b_Jet_puId_majW);
   //   fChain->SetBranchAddress("Jet_puId_minW", Jet_puId_minW, &b_Jet_puId_minW);
   //   fChain->SetBranchAddress("Jet_puId_ptD", Jet_puId_ptD, &b_Jet_puId_ptD);
   //   fChain->SetBranchAddress("Jet_puId_pull", Jet_puId_pull, &b_Jet_puId_pull);
   //   fChain->SetBranchAddress("Jet_qgl_axis2", Jet_qgl_axis2, &b_Jet_qgl_axis2);
   //   fChain->SetBranchAddress("Jet_qgl_ptD", Jet_qgl_ptD, &b_Jet_qgl_ptD);
   fChain->SetBranchAddress("Jet_rawFactor", Jet_rawFactor, &b_Jet_rawFactor);
   fChain->SetBranchAddress("PNetRegPtRawCorr", PNetRegPtRawCorr, &b_PNetRegPtRawCorr);
   fChain->SetBranchAddress("PNetRegPtRawCorrNeutrino", PNetRegPtRawCorrNeutrino, &b_PNetRegPtRawCorrNeutrino);
   fChain->SetBranchAddress("Jet_electronIdx1", Jet_electronIdx1, &b_Jet_electronIdx1);
   fChain->SetBranchAddress("Jet_electronIdx2", Jet_electronIdx2, &b_Jet_electronIdx2);
   fChain->SetBranchAddress("Jet_hfadjacentEtaStripsSize", Jet_hfadjacentEtaStripsSize, &b_Jet_hfadjacentEtaStripsSize);
   fChain->SetBranchAddress("Jet_hfcentralEtaStripSize", Jet_hfcentralEtaStripSize, &b_Jet_hfcentralEtaStripSize);
   fChain->SetBranchAddress("Jet_jetId", Jet_jetId, &b_Jet_jetId);
   fChain->SetBranchAddress("Jet_muonIdx1", Jet_muonIdx1, &b_Jet_muonIdx1);
   fChain->SetBranchAddress("Jet_muonIdx2", Jet_muonIdx2, &b_Jet_muonIdx2);
   //   fChain->SetBranchAddress("Jet_nConstChHads", Jet_nConstChHads, &b_Jet_nConstChHads);
   //   fChain->SetBranchAddress("Jet_nConstElecs", Jet_nConstElecs, &b_Jet_nConstElecs);
   //   fChain->SetBranchAddress("Jet_nConstHFEMs", Jet_nConstHFEMs, &b_Jet_nConstHFEMs);
   //   fChain->SetBranchAddress("Jet_nConstHFHads", Jet_nConstHFHads, &b_Jet_nConstHFHads);
   //   fChain->SetBranchAddress("Jet_nConstMuons", Jet_nConstMuons, &b_Jet_nConstMuons);
   //   fChain->SetBranchAddress("Jet_nConstNeuHads", Jet_nConstNeuHads, &b_Jet_nConstNeuHads);
   //   fChain->SetBranchAddress("Jet_nConstPhotons", Jet_nConstPhotons, &b_Jet_nConstPhotons);
   fChain->SetBranchAddress("Jet_nElectrons", Jet_nElectrons, &b_Jet_nElectrons);
   fChain->SetBranchAddress("Jet_nMuons", Jet_nMuons, &b_Jet_nMuons);
   //   fChain->SetBranchAddress("Jet_puId_nCharged", Jet_puId_nCharged, &b_Jet_puId_nCharged);
   //   fChain->SetBranchAddress("Jet_qgl_mult", Jet_qgl_mult, &b_Jet_qgl_mult);
   fChain->SetBranchAddress("Jet_nConstituents", Jet_nConstituents, &b_Jet_nConstituents);
   /*
   fChain->SetBranchAddress("nJetCHS", &nJetCHS, &b_nJetCHS);
   fChain->SetBranchAddress("JetCHS_area", JetCHS_area, &b_JetCHS_area);
   fChain->SetBranchAddress("JetCHS_btagCSVV2", JetCHS_btagCSVV2, &b_JetCHS_btagCSVV2);
   fChain->SetBranchAddress("JetCHS_btagDeepB", JetCHS_btagDeepB, &b_JetCHS_btagDeepB);
   fChain->SetBranchAddress("JetCHS_btagDeepCvB", JetCHS_btagDeepCvB, &b_JetCHS_btagDeepCvB);
   fChain->SetBranchAddress("JetCHS_btagDeepCvL", JetCHS_btagDeepCvL, &b_JetCHS_btagDeepCvL);
   fChain->SetBranchAddress("JetCHS_btagDeepFlavB", JetCHS_btagDeepFlavB, &b_JetCHS_btagDeepFlavB);
   fChain->SetBranchAddress("JetCHS_btagDeepFlavCvB", JetCHS_btagDeepFlavCvB, &b_JetCHS_btagDeepFlavCvB);
   fChain->SetBranchAddress("JetCHS_btagDeepFlavCvL", JetCHS_btagDeepFlavCvL, &b_JetCHS_btagDeepFlavCvL);
   fChain->SetBranchAddress("JetCHS_btagDeepFlavG", JetCHS_btagDeepFlavG, &b_JetCHS_btagDeepFlavG);
   fChain->SetBranchAddress("JetCHS_btagDeepFlavQG", JetCHS_btagDeepFlavQG, &b_JetCHS_btagDeepFlavQG);
   fChain->SetBranchAddress("JetCHS_btagDeepFlavUDS", JetCHS_btagDeepFlavUDS, &b_JetCHS_btagDeepFlavUDS);
   fChain->SetBranchAddress("JetCHS_chEmEF", JetCHS_chEmEF, &b_JetCHS_chEmEF);
   fChain->SetBranchAddress("JetCHS_chFPV0EF", JetCHS_chFPV0EF, &b_JetCHS_chFPV0EF);
   fChain->SetBranchAddress("JetCHS_chFPV1EF", JetCHS_chFPV1EF, &b_JetCHS_chFPV1EF);
   fChain->SetBranchAddress("JetCHS_chFPV2EF", JetCHS_chFPV2EF, &b_JetCHS_chFPV2EF);
   fChain->SetBranchAddress("JetCHS_chFPV3EF", JetCHS_chFPV3EF, &b_JetCHS_chFPV3EF);
   fChain->SetBranchAddress("JetCHS_chHEF", JetCHS_chHEF, &b_JetCHS_chHEF);
   fChain->SetBranchAddress("JetCHS_eta", JetCHS_eta, &b_JetCHS_eta);
   fChain->SetBranchAddress("JetCHS_hfEmEF", JetCHS_hfEmEF, &b_JetCHS_hfEmEF);
   fChain->SetBranchAddress("JetCHS_hfHEF", JetCHS_hfHEF, &b_JetCHS_hfHEF);
   fChain->SetBranchAddress("JetCHS_hfsigmaEtaEta", JetCHS_hfsigmaEtaEta, &b_JetCHS_hfsigmaEtaEta);
   fChain->SetBranchAddress("JetCHS_hfsigmaPhiPhi", JetCHS_hfsigmaPhiPhi, &b_JetCHS_hfsigmaPhiPhi);
   fChain->SetBranchAddress("JetCHS_mass", JetCHS_mass, &b_JetCHS_mass);
   fChain->SetBranchAddress("JetCHS_muEF", JetCHS_muEF, &b_JetCHS_muEF);
   fChain->SetBranchAddress("JetCHS_muonSubtrFactor", JetCHS_muonSubtrFactor, &b_JetCHS_muonSubtrFactor);
   fChain->SetBranchAddress("JetCHS_neEmEF", JetCHS_neEmEF, &b_JetCHS_neEmEF);
   fChain->SetBranchAddress("JetCHS_neHEF", JetCHS_neHEF, &b_JetCHS_neHEF);
   fChain->SetBranchAddress("JetCHS_particleNetAK4_B", JetCHS_particleNetAK4_B, &b_JetCHS_particleNetAK4_B);
   fChain->SetBranchAddress("JetCHS_particleNetAK4_CvsB", JetCHS_particleNetAK4_CvsB, &b_JetCHS_particleNetAK4_CvsB);
   fChain->SetBranchAddress("JetCHS_particleNetAK4_CvsL", JetCHS_particleNetAK4_CvsL, &b_JetCHS_particleNetAK4_CvsL);
   fChain->SetBranchAddress("JetCHS_particleNetAK4_QvsG", JetCHS_particleNetAK4_QvsG, &b_JetCHS_particleNetAK4_QvsG);
   fChain->SetBranchAddress("JetCHS_particleNetAK4_puIdDisc", JetCHS_particleNetAK4_puIdDisc, &b_JetCHS_particleNetAK4_puIdDisc);
   fChain->SetBranchAddress("JetCHS_phi", JetCHS_phi, &b_JetCHS_phi);
   fChain->SetBranchAddress("JetCHS_pt", JetCHS_pt, &b_JetCHS_pt);
   fChain->SetBranchAddress("JetCHS_puIdDisc", JetCHS_puIdDisc, &b_JetCHS_puIdDisc);
   fChain->SetBranchAddress("JetCHS_puId_beta", JetCHS_puId_beta, &b_JetCHS_puId_beta);
   fChain->SetBranchAddress("JetCHS_puId_dR2Mean", JetCHS_puId_dR2Mean, &b_JetCHS_puId_dR2Mean);
   fChain->SetBranchAddress("JetCHS_puId_frac01", JetCHS_puId_frac01, &b_JetCHS_puId_frac01);
   fChain->SetBranchAddress("JetCHS_puId_frac02", JetCHS_puId_frac02, &b_JetCHS_puId_frac02);
   fChain->SetBranchAddress("JetCHS_puId_frac03", JetCHS_puId_frac03, &b_JetCHS_puId_frac03);
   fChain->SetBranchAddress("JetCHS_puId_frac04", JetCHS_puId_frac04, &b_JetCHS_puId_frac04);
   fChain->SetBranchAddress("JetCHS_puId_jetR", JetCHS_puId_jetR, &b_JetCHS_puId_jetR);
   fChain->SetBranchAddress("JetCHS_puId_jetRchg", JetCHS_puId_jetRchg, &b_JetCHS_puId_jetRchg);
   fChain->SetBranchAddress("JetCHS_puId_majW", JetCHS_puId_majW, &b_JetCHS_puId_majW);
   fChain->SetBranchAddress("JetCHS_puId_minW", JetCHS_puId_minW, &b_JetCHS_puId_minW);
   fChain->SetBranchAddress("JetCHS_puId_ptD", JetCHS_puId_ptD, &b_JetCHS_puId_ptD);
   fChain->SetBranchAddress("JetCHS_puId_pull", JetCHS_puId_pull, &b_JetCHS_puId_pull);
   fChain->SetBranchAddress("JetCHS_qgl", JetCHS_qgl, &b_JetCHS_qgl);
   fChain->SetBranchAddress("JetCHS_qgl_axis2", JetCHS_qgl_axis2, &b_JetCHS_qgl_axis2);
   fChain->SetBranchAddress("JetCHS_qgl_ptD", JetCHS_qgl_ptD, &b_JetCHS_qgl_ptD);
   fChain->SetBranchAddress("JetCHS_rawFactor", JetCHS_rawFactor, &b_JetCHS_rawFactor);
   fChain->SetBranchAddress("JetCHS_electronIdx1", JetCHS_electronIdx1, &b_JetCHS_electronIdx1);
   fChain->SetBranchAddress("JetCHS_electronIdx2", JetCHS_electronIdx2, &b_JetCHS_electronIdx2);
   fChain->SetBranchAddress("JetCHS_hfadjacentEtaStripsSize", JetCHS_hfadjacentEtaStripsSize, &b_JetCHS_hfadjacentEtaStripsSize);
   fChain->SetBranchAddress("JetCHS_hfcentralEtaStripSize", JetCHS_hfcentralEtaStripSize, &b_JetCHS_hfcentralEtaStripSize);
   fChain->SetBranchAddress("JetCHS_jetId", JetCHS_jetId, &b_JetCHS_jetId);
   fChain->SetBranchAddress("JetCHS_muonIdx1", JetCHS_muonIdx1, &b_JetCHS_muonIdx1);
   fChain->SetBranchAddress("JetCHS_muonIdx2", JetCHS_muonIdx2, &b_JetCHS_muonIdx2);
   fChain->SetBranchAddress("JetCHS_nConstChHads", JetCHS_nConstChHads, &b_JetCHS_nConstChHads);
   fChain->SetBranchAddress("JetCHS_nConstElecs", JetCHS_nConstElecs, &b_JetCHS_nConstElecs);
   fChain->SetBranchAddress("JetCHS_nConstHFEMs", JetCHS_nConstHFEMs, &b_JetCHS_nConstHFEMs);
   fChain->SetBranchAddress("JetCHS_nConstHFHads", JetCHS_nConstHFHads, &b_JetCHS_nConstHFHads);
   fChain->SetBranchAddress("JetCHS_nConstMuons", JetCHS_nConstMuons, &b_JetCHS_nConstMuons);
   fChain->SetBranchAddress("JetCHS_nConstNeuHads", JetCHS_nConstNeuHads, &b_JetCHS_nConstNeuHads);
   fChain->SetBranchAddress("JetCHS_nConstPhotons", JetCHS_nConstPhotons, &b_JetCHS_nConstPhotons);
   fChain->SetBranchAddress("JetCHS_nElectrons", JetCHS_nElectrons, &b_JetCHS_nElectrons);
   fChain->SetBranchAddress("JetCHS_nMuons", JetCHS_nMuons, &b_JetCHS_nMuons);
   fChain->SetBranchAddress("JetCHS_puId", JetCHS_puId, &b_JetCHS_puId);
   fChain->SetBranchAddress("JetCHS_puId_nCharged", JetCHS_puId_nCharged, &b_JetCHS_puId_nCharged);
   fChain->SetBranchAddress("JetCHS_qgl_mult", JetCHS_qgl_mult, &b_JetCHS_qgl_mult);
   fChain->SetBranchAddress("JetCHS_nConstituents", JetCHS_nConstituents, &b_JetCHS_nConstituents);
   */
   //   fChain->SetBranchAddress("L1PreFiringWeight_Dn", &L1PreFiringWeight_Dn, &b_L1PreFiringWeight_Dn);
   //   fChain->SetBranchAddress("L1PreFiringWeight_ECAL_Dn", &L1PreFiringWeight_ECAL_Dn, &b_L1PreFiringWeight_ECAL_Dn);
   //   fChain->SetBranchAddress("L1PreFiringWeight_ECAL_Nom", &L1PreFiringWeight_ECAL_Nom, &b_L1PreFiringWeight_ECAL_Nom);
   //   fChain->SetBranchAddress("L1PreFiringWeight_ECAL_Up", &L1PreFiringWeight_ECAL_Up, &b_L1PreFiringWeight_ECAL_Up);
   //   fChain->SetBranchAddress("L1PreFiringWeight_Muon_Nom", &L1PreFiringWeight_Muon_Nom, &b_L1PreFiringWeight_Muon_Nom);
   //   fChain->SetBranchAddress("L1PreFiringWeight_Muon_StatDn", &L1PreFiringWeight_Muon_StatDn, &b_L1PreFiringWeight_Muon_StatDn);
   //   fChain->SetBranchAddress("L1PreFiringWeight_Muon_StatUp", &L1PreFiringWeight_Muon_StatUp, &b_L1PreFiringWeight_Muon_StatUp);
   //   fChain->SetBranchAddress("L1PreFiringWeight_Muon_SystDn", &L1PreFiringWeight_Muon_SystDn, &b_L1PreFiringWeight_Muon_SystDn);
   //   fChain->SetBranchAddress("L1PreFiringWeight_Muon_SystUp", &L1PreFiringWeight_Muon_SystUp, &b_L1PreFiringWeight_Muon_SystUp);
   //   fChain->SetBranchAddress("L1PreFiringWeight_Nom", &L1PreFiringWeight_Nom, &b_L1PreFiringWeight_Nom);
   //   fChain->SetBranchAddress("L1PreFiringWeight_Up", &L1PreFiringWeight_Up, &b_L1PreFiringWeight_Up);
   fChain->SetBranchAddress("nLowPtElectron", &nLowPtElectron, &b_nLowPtElectron);
   fChain->SetBranchAddress("LowPtElectron_ID", LowPtElectron_ID, &b_LowPtElectron_ID);
   fChain->SetBranchAddress("LowPtElectron_convVtxRadius", LowPtElectron_convVtxRadius, &b_LowPtElectron_convVtxRadius);
   fChain->SetBranchAddress("LowPtElectron_deltaEtaSC", LowPtElectron_deltaEtaSC, &b_LowPtElectron_deltaEtaSC);
   fChain->SetBranchAddress("LowPtElectron_dxy", LowPtElectron_dxy, &b_LowPtElectron_dxy);
   fChain->SetBranchAddress("LowPtElectron_dxyErr", LowPtElectron_dxyErr, &b_LowPtElectron_dxyErr);
   fChain->SetBranchAddress("LowPtElectron_dz", LowPtElectron_dz, &b_LowPtElectron_dz);
   fChain->SetBranchAddress("LowPtElectron_dzErr", LowPtElectron_dzErr, &b_LowPtElectron_dzErr);
   fChain->SetBranchAddress("LowPtElectron_eInvMinusPInv", LowPtElectron_eInvMinusPInv, &b_LowPtElectron_eInvMinusPInv);
   fChain->SetBranchAddress("LowPtElectron_energyErr", LowPtElectron_energyErr, &b_LowPtElectron_energyErr);
   fChain->SetBranchAddress("LowPtElectron_eta", LowPtElectron_eta, &b_LowPtElectron_eta);
   fChain->SetBranchAddress("LowPtElectron_hoe", LowPtElectron_hoe, &b_LowPtElectron_hoe);
   fChain->SetBranchAddress("LowPtElectron_mass", LowPtElectron_mass, &b_LowPtElectron_mass);
   fChain->SetBranchAddress("LowPtElectron_miniPFRelIso_all", LowPtElectron_miniPFRelIso_all, &b_LowPtElectron_miniPFRelIso_all);
   fChain->SetBranchAddress("LowPtElectron_miniPFRelIso_chg", LowPtElectron_miniPFRelIso_chg, &b_LowPtElectron_miniPFRelIso_chg);
   fChain->SetBranchAddress("LowPtElectron_phi", LowPtElectron_phi, &b_LowPtElectron_phi);
   fChain->SetBranchAddress("LowPtElectron_pt", LowPtElectron_pt, &b_LowPtElectron_pt);
   fChain->SetBranchAddress("LowPtElectron_ptbiased", LowPtElectron_ptbiased, &b_LowPtElectron_ptbiased);
   fChain->SetBranchAddress("LowPtElectron_r9", LowPtElectron_r9, &b_LowPtElectron_r9);
   fChain->SetBranchAddress("LowPtElectron_scEtOverPt", LowPtElectron_scEtOverPt, &b_LowPtElectron_scEtOverPt);
   fChain->SetBranchAddress("LowPtElectron_sieie", LowPtElectron_sieie, &b_LowPtElectron_sieie);
   fChain->SetBranchAddress("LowPtElectron_unbiased", LowPtElectron_unbiased, &b_LowPtElectron_unbiased);
   fChain->SetBranchAddress("LowPtElectron_charge", LowPtElectron_charge, &b_LowPtElectron_charge);
   fChain->SetBranchAddress("LowPtElectron_convWP", LowPtElectron_convWP, &b_LowPtElectron_convWP);
   //fChain->SetBranchAddress("LowPtElectron_electronIdx", LowPtElectron_electronIdx, &b_LowPtElectron_electronIdx);
   fChain->SetBranchAddress("LowPtElectron_pdgId", LowPtElectron_pdgId, &b_LowPtElectron_pdgId);
   fChain->SetBranchAddress("LowPtElectron_convVeto", LowPtElectron_convVeto, &b_LowPtElectron_convVeto);
   fChain->SetBranchAddress("LowPtElectron_lostHits", LowPtElectron_lostHits, &b_LowPtElectron_lostHits);
   if (isMC) fChain->SetBranchAddress("GenMET_phi", &GenMET_phi, &b_GenMET_phi);
   if (isMC) fChain->SetBranchAddress("GenMET_pt", &GenMET_pt, &b_GenMET_pt);
   fChain->SetBranchAddress("MET_MetUnclustEnUpDeltaX", &MET_MetUnclustEnUpDeltaX, &b_MET_MetUnclustEnUpDeltaX);
   fChain->SetBranchAddress("MET_MetUnclustEnUpDeltaY", &MET_MetUnclustEnUpDeltaY, &b_MET_MetUnclustEnUpDeltaY);
   fChain->SetBranchAddress("MET_covXX", &MET_covXX, &b_MET_covXX);
   fChain->SetBranchAddress("MET_covXY", &MET_covXY, &b_MET_covXY);
   fChain->SetBranchAddress("MET_covYY", &MET_covYY, &b_MET_covYY);
   fChain->SetBranchAddress("MET_phi", &MET_phi, &b_MET_phi);
   fChain->SetBranchAddress("MET_pt", &MET_pt, &b_MET_pt);
   fChain->SetBranchAddress("MET_significance", &MET_significance, &b_MET_significance);
   fChain->SetBranchAddress("MET_sumEt", &MET_sumEt, &b_MET_sumEt);
   fChain->SetBranchAddress("MET_sumPtUnclustered", &MET_sumPtUnclustered, &b_MET_sumPtUnclustered);
   fChain->SetBranchAddress("nMuon", &nMuon, &b_nMuon);
   fChain->SetBranchAddress("Muon_dxy", Muon_dxy, &b_Muon_dxy);
   fChain->SetBranchAddress("Muon_dxyErr", Muon_dxyErr, &b_Muon_dxyErr);
   fChain->SetBranchAddress("Muon_dxybs", Muon_dxybs, &b_Muon_dxybs);
   fChain->SetBranchAddress("Muon_dz", Muon_dz, &b_Muon_dz);
   fChain->SetBranchAddress("Muon_dzErr", Muon_dzErr, &b_Muon_dzErr);
   fChain->SetBranchAddress("Muon_eta", Muon_eta, &b_Muon_eta);
   fChain->SetBranchAddress("Muon_ip3d", Muon_ip3d, &b_Muon_ip3d);
   fChain->SetBranchAddress("Muon_jetPtRelv2", Muon_jetPtRelv2, &b_Muon_jetPtRelv2);
   fChain->SetBranchAddress("Muon_jetRelIso", Muon_jetRelIso, &b_Muon_jetRelIso);
   fChain->SetBranchAddress("Muon_mass", Muon_mass, &b_Muon_mass);
   fChain->SetBranchAddress("Muon_miniPFRelIso_all", Muon_miniPFRelIso_all, &b_Muon_miniPFRelIso_all);
   fChain->SetBranchAddress("Muon_miniPFRelIso_chg", Muon_miniPFRelIso_chg, &b_Muon_miniPFRelIso_chg);
   fChain->SetBranchAddress("Muon_pfRelIso03_all", Muon_pfRelIso03_all, &b_Muon_pfRelIso03_all);
   fChain->SetBranchAddress("Muon_pfRelIso03_chg", Muon_pfRelIso03_chg, &b_Muon_pfRelIso03_chg);
   fChain->SetBranchAddress("Muon_pfRelIso04_all", Muon_pfRelIso04_all, &b_Muon_pfRelIso04_all);
   fChain->SetBranchAddress("Muon_phi", Muon_phi, &b_Muon_phi);
   fChain->SetBranchAddress("Muon_pt", Muon_pt, &b_Muon_pt);
   fChain->SetBranchAddress("Muon_ptErr", Muon_ptErr, &b_Muon_ptErr);
   fChain->SetBranchAddress("Muon_segmentComp", Muon_segmentComp, &b_Muon_segmentComp);
   fChain->SetBranchAddress("Muon_sip3d", Muon_sip3d, &b_Muon_sip3d);
   fChain->SetBranchAddress("Muon_softMva", Muon_softMva, &b_Muon_softMva);
   fChain->SetBranchAddress("Muon_tkRelIso", Muon_tkRelIso, &b_Muon_tkRelIso);
   fChain->SetBranchAddress("Muon_tunepRelPt", Muon_tunepRelPt, &b_Muon_tunepRelPt);
   fChain->SetBranchAddress("Muon_mvaLowPt", Muon_mvaLowPt, &b_Muon_mvaLowPt);
   fChain->SetBranchAddress("Muon_mvaTTH", Muon_mvaTTH, &b_Muon_mvaTTH);
   fChain->SetBranchAddress("Muon_charge", Muon_charge, &b_Muon_charge);
   fChain->SetBranchAddress("Muon_jetIdx", Muon_jetIdx, &b_Muon_jetIdx);
   fChain->SetBranchAddress("Muon_nStations", Muon_nStations, &b_Muon_nStations);
   fChain->SetBranchAddress("Muon_nTrackerLayers", Muon_nTrackerLayers, &b_Muon_nTrackerLayers);
   fChain->SetBranchAddress("Muon_pdgId", Muon_pdgId, &b_Muon_pdgId);
   fChain->SetBranchAddress("Muon_tightCharge", Muon_tightCharge, &b_Muon_tightCharge);
   fChain->SetBranchAddress("Muon_fsrPhotonIdx", Muon_fsrPhotonIdx, &b_Muon_fsrPhotonIdx);
   fChain->SetBranchAddress("Muon_highPtId", Muon_highPtId, &b_Muon_highPtId);
   fChain->SetBranchAddress("Muon_highPurity", Muon_highPurity, &b_Muon_highPurity);
   fChain->SetBranchAddress("Muon_inTimeMuon", Muon_inTimeMuon, &b_Muon_inTimeMuon);
   fChain->SetBranchAddress("Muon_isGlobal", Muon_isGlobal, &b_Muon_isGlobal);
   fChain->SetBranchAddress("Muon_isPFcand", Muon_isPFcand, &b_Muon_isPFcand);
   fChain->SetBranchAddress("Muon_isStandalone", Muon_isStandalone, &b_Muon_isStandalone);
   fChain->SetBranchAddress("Muon_isTracker", Muon_isTracker, &b_Muon_isTracker);
   fChain->SetBranchAddress("Muon_jetNDauCharged", Muon_jetNDauCharged, &b_Muon_jetNDauCharged);
   fChain->SetBranchAddress("Muon_looseId", Muon_looseId, &b_Muon_looseId);
   fChain->SetBranchAddress("Muon_mediumId", Muon_mediumId, &b_Muon_mediumId);
   fChain->SetBranchAddress("Muon_mediumPromptId", Muon_mediumPromptId, &b_Muon_mediumPromptId);
   fChain->SetBranchAddress("Muon_miniIsoId", Muon_miniIsoId, &b_Muon_miniIsoId);
   fChain->SetBranchAddress("Muon_multiIsoId", Muon_multiIsoId, &b_Muon_multiIsoId);
   //   fChain->SetBranchAddress("Muon_mvaId", Muon_mvaId, &b_Muon_mvaId);
   //   fChain->SetBranchAddress("Muon_mvaLowPtId", Muon_mvaLowPtId, &b_Muon_mvaLowPtId);
   fChain->SetBranchAddress("Muon_pfIsoId", Muon_pfIsoId, &b_Muon_pfIsoId);
   fChain->SetBranchAddress("Muon_puppiIsoId", Muon_puppiIsoId, &b_Muon_puppiIsoId);
   fChain->SetBranchAddress("Muon_softId", Muon_softId, &b_Muon_softId);
   fChain->SetBranchAddress("Muon_softMvaId", Muon_softMvaId, &b_Muon_softMvaId);
   fChain->SetBranchAddress("Muon_tightId", Muon_tightId, &b_Muon_tightId);
   fChain->SetBranchAddress("Muon_tkIsoId", Muon_tkIsoId, &b_Muon_tkIsoId);
   fChain->SetBranchAddress("Muon_triggerIdLoose", Muon_triggerIdLoose, &b_Muon_triggerIdLoose);
   fChain->SetBranchAddress("nPhoton", &nPhoton, &b_nPhoton);
   //   fChain->SetBranchAddress("Photon_dEscaleDown", Photon_dEscaleDown, &b_Photon_dEscaleDown);
   //   fChain->SetBranchAddress("Photon_dEscaleUp", Photon_dEscaleUp, &b_Photon_dEscaleUp);
   //   fChain->SetBranchAddress("Photon_dEsigmaDown", Photon_dEsigmaDown, &b_Photon_dEsigmaDown);
   //   fChain->SetBranchAddress("Photon_dEsigmaUp", Photon_dEsigmaUp, &b_Photon_dEsigmaUp);
   //   fChain->SetBranchAddress("Photon_eCorr", Photon_eCorr, &b_Photon_eCorr);
   fChain->SetBranchAddress("Photon_energyErr", Photon_energyErr, &b_Photon_energyErr);
   //fChain->SetBranchAddress("Photon_energyRaw", Photon_energyRaw, &b_Photon_energyRaw);
   //fChain->SetBranchAddress("Photon_esEffSigmaRR", Photon_esEffSigmaRR, &b_Photon_esEffSigmaRR);
   //fChain->SetBranchAddress("Photon_esEnergyOverRawE", Photon_esEnergyOverRawE, &b_Photon_esEnergyOverRawE);
   fChain->SetBranchAddress("Photon_eta", Photon_eta, &b_Photon_eta);
   //fChain->SetBranchAddress("Photon_etaWidth", Photon_etaWidth, &b_Photon_etaWidth);
   //fChain->SetBranchAddress("Photon_haloTaggerMVAVal", Photon_haloTaggerMVAVal, &b_Photon_haloTaggerMVAVal);
   fChain->SetBranchAddress("Photon_hoe", Photon_hoe, &b_Photon_hoe);
   fChain->SetBranchAddress("Photon_mvaID", Photon_mvaID, &b_Photon_mvaID);
   //fChain->SetBranchAddress("Photon_pfChargedIsoPFPV", Photon_pfChargedIsoPFPV, &b_Photon_pfChargedIsoPFPV);
   //fChain->SetBranchAddress("Photon_pfChargedIsoWorstVtx", Photon_pfChargedIsoWorstVtx, &b_Photon_pfChargedIsoWorstVtx);
   //fChain->SetBranchAddress("Photon_pfPhoIso03", Photon_pfPhoIso03, &b_Photon_pfPhoIso03);
   //   fChain->SetBranchAddress("Photon_pfRelIso03_all", Photon_pfRelIso03_all, &b_Photon_pfRelIso03_all);
   //   fChain->SetBranchAddress("Photon_pfRelIso03_chg", Photon_pfRelIso03_chg, &b_Photon_pfRelIso03_chg);
   fChain->SetBranchAddress("Photon_phi", Photon_phi, &b_Photon_phi);
   //fChain->SetBranchAddress("Photon_phiWidth", Photon_phiWidth, &b_Photon_phiWidth);
   fChain->SetBranchAddress("Photon_pt", Photon_pt, &b_Photon_pt);
   fChain->SetBranchAddress("Photon_r9", Photon_r9, &b_Photon_r9);
   //fChain->SetBranchAddress("Photon_s4", Photon_s4, &b_Photon_s4);
   fChain->SetBranchAddress("Photon_sieie", Photon_sieie, &b_Photon_sieie);
   //fChain->SetBranchAddress("Photon_sieip", Photon_sieip, &b_Photon_sieip);
   //fChain->SetBranchAddress("Photon_sipip", Photon_sipip, &b_Photon_sipip);
   //fChain->SetBranchAddress("Photon_x_calo", Photon_x_calo, &b_Photon_x_calo);
   //fChain->SetBranchAddress("Photon_y_calo", Photon_y_calo, &b_Photon_y_calo);
   //fChain->SetBranchAddress("Photon_z_calo", Photon_z_calo, &b_Photon_z_calo);
   fChain->SetBranchAddress("Photon_cutBased", Photon_cutBased, &b_Photon_cutBased);
   //   fChain->SetBranchAddress("Photon_cutBased_Fall17V1Bitmap", Photon_cutBased_Fall17V1Bitmap, &b_Photon_cutBased_Fall17V1Bitmap);
   fChain->SetBranchAddress("Photon_electronIdx", Photon_electronIdx, &b_Photon_electronIdx);
   fChain->SetBranchAddress("Photon_jetIdx", Photon_jetIdx, &b_Photon_jetIdx);
   fChain->SetBranchAddress("Photon_vidNestedWPBitmap", Photon_vidNestedWPBitmap, &b_Photon_vidNestedWPBitmap);
   fChain->SetBranchAddress("Photon_electronVeto", Photon_electronVeto, &b_Photon_electronVeto);
   fChain->SetBranchAddress("Photon_isScEtaEB", Photon_isScEtaEB, &b_Photon_isScEtaEB);
   fChain->SetBranchAddress("Photon_isScEtaEE", Photon_isScEtaEE, &b_Photon_isScEtaEE);
   fChain->SetBranchAddress("Photon_mvaID_WP80", Photon_mvaID_WP80, &b_Photon_mvaID_WP80);
   fChain->SetBranchAddress("Photon_mvaID_WP90", Photon_mvaID_WP90, &b_Photon_mvaID_WP90);
   fChain->SetBranchAddress("Photon_pixelSeed", Photon_pixelSeed, &b_Photon_pixelSeed);
   fChain->SetBranchAddress("Photon_seedGain", Photon_seedGain, &b_Photon_seedGain);
   if (isMC) fChain->SetBranchAddress("Pileup_nTrueInt", &Pileup_nTrueInt, &b_Pileup_nTrueInt);
   if (isMC) fChain->SetBranchAddress("Pileup_pudensity", &Pileup_pudensity, &b_Pileup_pudensity);
   if (isMC) fChain->SetBranchAddress("Pileup_gpudensity", &Pileup_gpudensity, &b_Pileup_gpudensity);
   if (isMC && !(isMG && isRun3)) fChain->SetBranchAddress("Pileup_pthatmax", &Pileup_pthatmax, &b_Pileup_pthatmax);
   if (isMC) fChain->SetBranchAddress("Pileup_nPU", &Pileup_nPU, &b_Pileup_nPU);
   if (isMC) fChain->SetBranchAddress("Pileup_sumEOOT", &Pileup_sumEOOT, &b_Pileup_sumEOOT);
   if (isMC) fChain->SetBranchAddress("Pileup_sumLOOT", &Pileup_sumLOOT, &b_Pileup_sumLOOT);
   fChain->SetBranchAddress("PuppiMET_phi", &PuppiMET_phi, &b_PuppiMET_phi);
   fChain->SetBranchAddress("PuppiMET_phiJERDown", &PuppiMET_phiJERDown, &b_PuppiMET_phiJERDown);
   fChain->SetBranchAddress("PuppiMET_phiJERUp", &PuppiMET_phiJERUp, &b_PuppiMET_phiJERUp);
   fChain->SetBranchAddress("PuppiMET_phiJESDown", &PuppiMET_phiJESDown, &b_PuppiMET_phiJESDown);
   fChain->SetBranchAddress("PuppiMET_phiJESUp", &PuppiMET_phiJESUp, &b_PuppiMET_phiJESUp);
   fChain->SetBranchAddress("PuppiMET_phiUnclusteredDown", &PuppiMET_phiUnclusteredDown, &b_PuppiMET_phiUnclusteredDown);
   fChain->SetBranchAddress("PuppiMET_phiUnclusteredUp", &PuppiMET_phiUnclusteredUp, &b_PuppiMET_phiUnclusteredUp);
   fChain->SetBranchAddress("PuppiMET_pt", &PuppiMET_pt, &b_PuppiMET_pt);
   fChain->SetBranchAddress("PuppiMET_ptJERDown", &PuppiMET_ptJERDown, &b_PuppiMET_ptJERDown);
   fChain->SetBranchAddress("PuppiMET_ptJERUp", &PuppiMET_ptJERUp, &b_PuppiMET_ptJERUp);
   fChain->SetBranchAddress("PuppiMET_ptJESDown", &PuppiMET_ptJESDown, &b_PuppiMET_ptJESDown);
   fChain->SetBranchAddress("PuppiMET_ptJESUp", &PuppiMET_ptJESUp, &b_PuppiMET_ptJESUp);
   fChain->SetBranchAddress("PuppiMET_ptUnclusteredDown", &PuppiMET_ptUnclusteredDown, &b_PuppiMET_ptUnclusteredDown);
   fChain->SetBranchAddress("PuppiMET_ptUnclusteredUp", &PuppiMET_ptUnclusteredUp, &b_PuppiMET_ptUnclusteredUp);
   fChain->SetBranchAddress("PuppiMET_sumEt", &PuppiMET_sumEt, &b_PuppiMET_sumEt);
   fChain->SetBranchAddress("RawMET_phi", &RawMET_phi, &b_RawMET_phi);
   fChain->SetBranchAddress("RawMET_pt", &RawMET_pt, &b_RawMET_pt);
   fChain->SetBranchAddress("RawMET_sumEt", &RawMET_sumEt, &b_RawMET_sumEt);
   fChain->SetBranchAddress("RawPuppiMET_phi", &RawPuppiMET_phi, &b_RawPuppiMET_phi);
   fChain->SetBranchAddress("RawPuppiMET_pt", &RawPuppiMET_pt, &b_RawPuppiMET_pt);
   fChain->SetBranchAddress("RawPuppiMET_sumEt", &RawPuppiMET_sumEt, &b_RawPuppiMET_sumEt);
   if (isRun2) {
     fChain->SetBranchAddress("fixedGridRhoFastjetAll", &Rho_fixedGridRhoFastjetAll, &b_Rho_fixedGridRhoFastjetAll);
   }
   else {
     fChain->SetBranchAddress("Rho_fixedGridRhoAll", &Rho_fixedGridRhoAll, &b_Rho_fixedGridRhoAll);
     fChain->SetBranchAddress("Rho_fixedGridRhoFastjetAll", &Rho_fixedGridRhoFastjetAll, &b_Rho_fixedGridRhoFastjetAll);
     fChain->SetBranchAddress("Rho_fixedGridRhoFastjetCentral", &Rho_fixedGridRhoFastjetCentral, &b_Rho_fixedGridRhoFastjetCentral);
     fChain->SetBranchAddress("Rho_fixedGridRhoFastjetCentralCalo", &Rho_fixedGridRhoFastjetCentralCalo, &b_Rho_fixedGridRhoFastjetCentralCalo);
     fChain->SetBranchAddress("Rho_fixedGridRhoFastjetCentralChargedPileUp", &Rho_fixedGridRhoFastjetCentralChargedPileUp, &b_Rho_fixedGridRhoFastjetCentralChargedPileUp);
     fChain->SetBranchAddress("Rho_fixedGridRhoFastjetCentralNeutral", &Rho_fixedGridRhoFastjetCentralNeutral, &b_Rho_fixedGridRhoFastjetCentralNeutral);
   }
   if (isMC) fChain->SetBranchAddress("nGenDressedLepton", &nGenDressedLepton, &b_nGenDressedLepton);
   if (isMC) fChain->SetBranchAddress("GenDressedLepton_eta", GenDressedLepton_eta, &b_GenDressedLepton_eta);
   if (isMC) fChain->SetBranchAddress("GenDressedLepton_mass", GenDressedLepton_mass, &b_GenDressedLepton_mass);
   if (isMC) fChain->SetBranchAddress("GenDressedLepton_phi", GenDressedLepton_phi, &b_GenDressedLepton_phi);
   if (isMC) fChain->SetBranchAddress("GenDressedLepton_pt", GenDressedLepton_pt, &b_GenDressedLepton_pt);
   if (isMC) fChain->SetBranchAddress("GenDressedLepton_pdgId", GenDressedLepton_pdgId, &b_GenDressedLepton_pdgId);
   if (isMC) fChain->SetBranchAddress("GenDressedLepton_hasTauAnc", GenDressedLepton_hasTauAnc, &b_GenDressedLepton_hasTauAnc);
   if (isMC) fChain->SetBranchAddress("nGenIsolatedPhoton", &nGenIsolatedPhoton, &b_nGenIsolatedPhoton);
   if (isMC) fChain->SetBranchAddress("GenIsolatedPhoton_eta", GenIsolatedPhoton_eta, &b_GenIsolatedPhoton_eta);
   if (isMC) fChain->SetBranchAddress("GenIsolatedPhoton_mass", GenIsolatedPhoton_mass, &b_GenIsolatedPhoton_mass);
   if (isMC) fChain->SetBranchAddress("GenIsolatedPhoton_phi", GenIsolatedPhoton_phi, &b_GenIsolatedPhoton_phi);
   if (isMC) fChain->SetBranchAddress("GenIsolatedPhoton_pt", GenIsolatedPhoton_pt, &b_GenIsolatedPhoton_pt);
   fChain->SetBranchAddress("nSoftActivityJet", &nSoftActivityJet, &b_nSoftActivityJet);
   fChain->SetBranchAddress("SoftActivityJet_eta", SoftActivityJet_eta, &b_SoftActivityJet_eta);
   fChain->SetBranchAddress("SoftActivityJet_phi", SoftActivityJet_phi, &b_SoftActivityJet_phi);
   fChain->SetBranchAddress("SoftActivityJet_pt", SoftActivityJet_pt, &b_SoftActivityJet_pt);
   fChain->SetBranchAddress("SoftActivityJetHT", &SoftActivityJetHT, &b_SoftActivityJetHT);
   fChain->SetBranchAddress("SoftActivityJetHT10", &SoftActivityJetHT10, &b_SoftActivityJetHT10);
   fChain->SetBranchAddress("SoftActivityJetHT2", &SoftActivityJetHT2, &b_SoftActivityJetHT2);
   fChain->SetBranchAddress("SoftActivityJetHT5", &SoftActivityJetHT5, &b_SoftActivityJetHT5);
   fChain->SetBranchAddress("SoftActivityJetNjets10", &SoftActivityJetNjets10, &b_SoftActivityJetNjets10);
   fChain->SetBranchAddress("SoftActivityJetNjets2", &SoftActivityJetNjets2, &b_SoftActivityJetNjets2);
   fChain->SetBranchAddress("SoftActivityJetNjets5", &SoftActivityJetNjets5, &b_SoftActivityJetNjets5);
   fChain->SetBranchAddress("nSubJet", &nSubJet, &b_nSubJet);
   //   fChain->SetBranchAddress("SubJet_btagCSVV2", SubJet_btagCSVV2, &b_SubJet_btagCSVV2);
   fChain->SetBranchAddress("SubJet_btagDeepB", SubJet_btagDeepB, &b_SubJet_btagDeepB);
   fChain->SetBranchAddress("SubJet_eta", SubJet_eta, &b_SubJet_eta);
   fChain->SetBranchAddress("SubJet_mass", SubJet_mass, &b_SubJet_mass);
   fChain->SetBranchAddress("SubJet_n2b1", SubJet_n2b1, &b_SubJet_n2b1);
   fChain->SetBranchAddress("SubJet_n3b1", SubJet_n3b1, &b_SubJet_n3b1);
   fChain->SetBranchAddress("SubJet_phi", SubJet_phi, &b_SubJet_phi);
   fChain->SetBranchAddress("SubJet_pt", SubJet_pt, &b_SubJet_pt);
   fChain->SetBranchAddress("SubJet_rawFactor", SubJet_rawFactor, &b_SubJet_rawFactor);
   fChain->SetBranchAddress("SubJet_tau1", SubJet_tau1, &b_SubJet_tau1);
   fChain->SetBranchAddress("SubJet_tau2", SubJet_tau2, &b_SubJet_tau2);
   fChain->SetBranchAddress("SubJet_tau3", SubJet_tau3, &b_SubJet_tau3);
   fChain->SetBranchAddress("SubJet_tau4", SubJet_tau4, &b_SubJet_tau4);
   fChain->SetBranchAddress("nTau", &nTau, &b_nTau);
   fChain->SetBranchAddress("Tau_chargedIso", Tau_chargedIso, &b_Tau_chargedIso);
   fChain->SetBranchAddress("Tau_dxy", Tau_dxy, &b_Tau_dxy);
   fChain->SetBranchAddress("Tau_dz", Tau_dz, &b_Tau_dz);
   fChain->SetBranchAddress("Tau_eta", Tau_eta, &b_Tau_eta);
   fChain->SetBranchAddress("Tau_leadTkDeltaEta", Tau_leadTkDeltaEta, &b_Tau_leadTkDeltaEta);
   fChain->SetBranchAddress("Tau_leadTkDeltaPhi", Tau_leadTkDeltaPhi, &b_Tau_leadTkDeltaPhi);
   fChain->SetBranchAddress("Tau_leadTkPtOverTauPt", Tau_leadTkPtOverTauPt, &b_Tau_leadTkPtOverTauPt);
   fChain->SetBranchAddress("Tau_mass", Tau_mass, &b_Tau_mass);
   fChain->SetBranchAddress("Tau_neutralIso", Tau_neutralIso, &b_Tau_neutralIso);
   fChain->SetBranchAddress("Tau_phi", Tau_phi, &b_Tau_phi);
   fChain->SetBranchAddress("Tau_photonsOutsideSignalCone", Tau_photonsOutsideSignalCone, &b_Tau_photonsOutsideSignalCone);
   fChain->SetBranchAddress("Tau_pt", Tau_pt, &b_Tau_pt);
   fChain->SetBranchAddress("Tau_puCorr", Tau_puCorr, &b_Tau_puCorr);
   //fChain->SetBranchAddress("Tau_rawDeepTau2017v2p1VSe", Tau_rawDeepTau2017v2p1VSe, &b_Tau_rawDeepTau2017v2p1VSe);
   //fChain->SetBranchAddress("Tau_rawDeepTau2017v2p1VSjet", Tau_rawDeepTau2017v2p1VSjet, &b_Tau_rawDeepTau2017v2p1VSjet);
   //fChain->SetBranchAddress("Tau_rawDeepTau2017v2p1VSmu", Tau_rawDeepTau2017v2p1VSmu, &b_Tau_rawDeepTau2017v2p1VSmu);
   //fChain->SetBranchAddress("Tau_rawDeepTau2018v2p5VSe", Tau_rawDeepTau2018v2p5VSe, &b_Tau_rawDeepTau2018v2p5VSe);
   //fChain->SetBranchAddress("Tau_rawDeepTau2018v2p5VSjet", Tau_rawDeepTau2018v2p5VSjet, &b_Tau_rawDeepTau2018v2p5VSjet);
   //fChain->SetBranchAddress("Tau_rawDeepTau2018v2p5VSmu", Tau_rawDeepTau2018v2p5VSmu, &b_Tau_rawDeepTau2018v2p5VSmu);
   fChain->SetBranchAddress("Tau_rawIso", Tau_rawIso, &b_Tau_rawIso);
   fChain->SetBranchAddress("Tau_rawIsodR03", Tau_rawIsodR03, &b_Tau_rawIsodR03);
   fChain->SetBranchAddress("Tau_charge", Tau_charge, &b_Tau_charge);
   fChain->SetBranchAddress("Tau_decayMode", Tau_decayMode, &b_Tau_decayMode);
   fChain->SetBranchAddress("Tau_jetIdx", Tau_jetIdx, &b_Tau_jetIdx);
   fChain->SetBranchAddress("Tau_idAntiEleDeadECal", Tau_idAntiEleDeadECal, &b_Tau_idAntiEleDeadECal);
   fChain->SetBranchAddress("Tau_idAntiMu", Tau_idAntiMu, &b_Tau_idAntiMu);
   fChain->SetBranchAddress("Tau_idDecayModeOldDMs", Tau_idDecayModeOldDMs, &b_Tau_idDecayModeOldDMs);
   //fChain->SetBranchAddress("Tau_idDeepTau2017v2p1VSe", Tau_idDeepTau2017v2p1VSe, &b_Tau_idDeepTau2017v2p1VSe);
   //fChain->SetBranchAddress("Tau_idDeepTau2017v2p1VSjet", Tau_idDeepTau2017v2p1VSjet, &b_Tau_idDeepTau2017v2p1VSjet);
   //fChain->SetBranchAddress("Tau_idDeepTau2017v2p1VSmu", Tau_idDeepTau2017v2p1VSmu, &b_Tau_idDeepTau2017v2p1VSmu);
   //fChain->SetBranchAddress("Tau_idDeepTau2018v2p5VSe", Tau_idDeepTau2018v2p5VSe, &b_Tau_idDeepTau2018v2p5VSe);
   //fChain->SetBranchAddress("Tau_idDeepTau2018v2p5VSjet", Tau_idDeepTau2018v2p5VSjet, &b_Tau_idDeepTau2018v2p5VSjet);
   //fChain->SetBranchAddress("Tau_idDeepTau2018v2p5VSmu", Tau_idDeepTau2018v2p5VSmu, &b_Tau_idDeepTau2018v2p5VSmu);
   fChain->SetBranchAddress("TkMET_phi", &TkMET_phi, &b_TkMET_phi);
   fChain->SetBranchAddress("TkMET_pt", &TkMET_pt, &b_TkMET_pt);
   fChain->SetBranchAddress("TkMET_sumEt", &TkMET_sumEt, &b_TkMET_sumEt);
   fChain->SetBranchAddress("nTrigObj", &nTrigObj, &b_nTrigObj);
   fChain->SetBranchAddress("TrigObj_pt", TrigObj_pt, &b_TrigObj_pt);
   fChain->SetBranchAddress("TrigObj_eta", TrigObj_eta, &b_TrigObj_eta);
   fChain->SetBranchAddress("TrigObj_phi", TrigObj_phi, &b_TrigObj_phi);
   fChain->SetBranchAddress("TrigObj_l1pt", TrigObj_l1pt, &b_TrigObj_l1pt);
   fChain->SetBranchAddress("TrigObj_l1pt_2", TrigObj_l1pt_2, &b_TrigObj_l1pt_2);
   fChain->SetBranchAddress("TrigObj_l2pt", TrigObj_l2pt, &b_TrigObj_l2pt);
   fChain->SetBranchAddress("TrigObj_id", TrigObj_id, &b_TrigObj_id);
   fChain->SetBranchAddress("TrigObj_l1iso", TrigObj_l1iso, &b_TrigObj_l1iso);
   fChain->SetBranchAddress("TrigObj_l1charge", TrigObj_l1charge, &b_TrigObj_l1charge);
   fChain->SetBranchAddress("TrigObj_filterBits", TrigObj_filterBits, &b_TrigObj_filterBits);
   if (isMC) fChain->SetBranchAddress("genTtbarId", &genTtbarId, &b_genTtbarId);
   fChain->SetBranchAddress("nOtherPV", &nOtherPV, &b_nOtherPV);
   fChain->SetBranchAddress("OtherPV_z", OtherPV_z, &b_OtherPV_z);
   //fChain->SetBranchAddress("OtherPV_score", OtherPV_score, &b_OtherPV_score);
   fChain->SetBranchAddress("PV_ndof", &PV_ndof, &b_PV_ndof);
   fChain->SetBranchAddress("PV_x", &PV_x, &b_PV_x);
   fChain->SetBranchAddress("PV_y", &PV_y, &b_PV_y);
   fChain->SetBranchAddress("PV_z", &PV_z, &b_PV_z);
   fChain->SetBranchAddress("PV_chi2", &PV_chi2, &b_PV_chi2);
   fChain->SetBranchAddress("PV_score", &PV_score, &b_PV_score);
   fChain->SetBranchAddress("PV_npvs", &PV_npvs, &b_PV_npvs);
   fChain->SetBranchAddress("PV_npvsGood", &PV_npvsGood, &b_PV_npvsGood);
   fChain->SetBranchAddress("nSV", &nSV, &b_nSV);
   fChain->SetBranchAddress("SV_dlen", SV_dlen, &b_SV_dlen);
   fChain->SetBranchAddress("SV_dlenSig", SV_dlenSig, &b_SV_dlenSig);
   fChain->SetBranchAddress("SV_dxy", SV_dxy, &b_SV_dxy);
   fChain->SetBranchAddress("SV_dxySig", SV_dxySig, &b_SV_dxySig);
   fChain->SetBranchAddress("SV_pAngle", SV_pAngle, &b_SV_pAngle);
   fChain->SetBranchAddress("SV_charge", SV_charge, &b_SV_charge);
   if (isMC) fChain->SetBranchAddress("Electron_genPartIdx", Electron_genPartIdx, &b_Electron_genPartIdx);
   if (isMC) fChain->SetBranchAddress("Electron_genPartFlav", Electron_genPartFlav, &b_Electron_genPartFlav);

   if (isMC) fChain->SetBranchAddress("GenJetAK8_partonFlavour", GenJetAK8_partonFlavour, &b_GenJetAK8_partonFlavour);
   if (isMC) fChain->SetBranchAddress("GenJetAK8_hadronFlavour", GenJetAK8_hadronFlavour, &b_GenJetAK8_hadronFlavour);
   //if (isMC) fChain->SetBranchAddress("GenJetAK8ForJEC_partonFlavour", GenJetAK8ForJEC_partonFlavour, &b_GenJetAK8ForJEC_partonFlavour);
   //if (isMC) fChain->SetBranchAddress("GenJetAK8ForJEC_hadronFlavour", GenJetAK8ForJEC_hadronFlavour, &b_GenJetAK8ForJEC_hadronFlavour);
   if (isMC) fChain->SetBranchAddress("GenJet_partonFlavour", GenJet_partonFlavour, &b_GenJet_partonFlavour);
   if (isMC) fChain->SetBranchAddress("GenJet_hadronFlavour", GenJet_hadronFlavour, &b_GenJet_hadronFlavour);
   if (isMC) fChain->SetBranchAddress("GenVtx_t0", &GenVtx_t0, &b_GenVtx_t0);

   /*
   if (isMC) fChain->SetBranchAddress("JetCHS_genJetIdx", JetCHS_genJetIdx, &b_JetCHS_genJetIdx);
   if (isMC) fChain->SetBranchAddress("JetCHS_hadronFlavour", JetCHS_hadronFlavour, &b_JetCHS_hadronFlavour);
   if (isMC) fChain->SetBranchAddress("JetCHS_partonFlavour", JetCHS_partonFlavour, &b_JetCHS_partonFlavour);
   */

   if (isMC) fChain->SetBranchAddress("Jet_genJetIdx", Jet_genJetIdx, &b_Jet_genJetIdx);
   if (isMC) fChain->SetBranchAddress("Jet_hadronFlavour", Jet_hadronFlavour, &b_Jet_hadronFlavour);
   if (isMC) fChain->SetBranchAddress("Jet_partonFlavour", Jet_partonFlavour, &b_Jet_partonFlavour);
   if (isMC) fChain->SetBranchAddress("LowPtElectron_genPartIdx", LowPtElectron_genPartIdx, &b_LowPtElectron_genPartIdx);
   if (isMC) fChain->SetBranchAddress("LowPtElectron_genPartFlav", LowPtElectron_genPartFlav, &b_LowPtElectron_genPartFlav);
   if (isMC) fChain->SetBranchAddress("Muon_genPartIdx", Muon_genPartIdx, &b_Muon_genPartIdx);
   if (isMC) fChain->SetBranchAddress("Muon_genPartFlav", Muon_genPartFlav, &b_Muon_genPartFlav);
   if (isMC) fChain->SetBranchAddress("Photon_genPartIdx", Photon_genPartIdx, &b_Photon_genPartIdx);
   if (isMC) fChain->SetBranchAddress("Photon_genPartFlav", Photon_genPartFlav, &b_Photon_genPartFlav);
   if (isMC) fChain->SetBranchAddress("MET_fiducialGenPhi", &MET_fiducialGenPhi, &b_MET_fiducialGenPhi);
   if (isMC) fChain->SetBranchAddress("MET_fiducialGenPt", &MET_fiducialGenPt, &b_MET_fiducialGenPt);
   //   fChain->SetBranchAddress("Electron_cleanmask", Electron_cleanmask, &b_Electron_cleanmask);
   //   fChain->SetBranchAddress("Jet_cleanmask", Jet_cleanmask, &b_Jet_cleanmask);
   //fChain->SetBranchAddress("LowPtElectron_cleanmask", LowPtElectron_cleanmask, &b_LowPtElectron_cleanmask);
   //   fChain->SetBranchAddress("Muon_cleanmask", Muon_cleanmask, &b_Muon_cleanmask);
   //   fChain->SetBranchAddress("Photon_cleanmask", Photon_cleanmask, &b_Photon_cleanmask);
   //   fChain->SetBranchAddress("Tau_cleanmask", Tau_cleanmask, &b_Tau_cleanmask);
   if (isMC) fChain->SetBranchAddress("SubJet_hadronFlavour", SubJet_hadronFlavour, &b_SubJet_hadronFlavour);
   if (isMC) fChain->SetBranchAddress("SubJet_nBHadrons", SubJet_nBHadrons, &b_SubJet_nBHadrons);
   if (isMC) fChain->SetBranchAddress("SubJet_nCHadrons", SubJet_nCHadrons, &b_SubJet_nCHadrons);
   fChain->SetBranchAddress("SV_chi2", SV_chi2, &b_SV_chi2);
   fChain->SetBranchAddress("SV_eta", SV_eta, &b_SV_eta);
   fChain->SetBranchAddress("SV_mass", SV_mass, &b_SV_mass);
   fChain->SetBranchAddress("SV_ndof", SV_ndof, &b_SV_ndof);
   fChain->SetBranchAddress("SV_phi", SV_phi, &b_SV_phi);
   fChain->SetBranchAddress("SV_pt", SV_pt, &b_SV_pt);
   fChain->SetBranchAddress("SV_x", SV_x, &b_SV_x);
   fChain->SetBranchAddress("SV_y", SV_y, &b_SV_y);
   fChain->SetBranchAddress("SV_z", SV_z, &b_SV_z);
   fChain->SetBranchAddress("SV_ntracks", SV_ntracks, &b_SV_ntracks);
   if (isMC) fChain->SetBranchAddress("Tau_genPartIdx", Tau_genPartIdx, &b_Tau_genPartIdx);
   if (isMC) fChain->SetBranchAddress("Tau_genPartFlav", Tau_genPartFlav, &b_Tau_genPartFlav);
   /*
   fChain->SetBranchAddress("L1_AlwaysTrue", &L1_AlwaysTrue, &b_L1_AlwaysTrue);
   fChain->SetBranchAddress("L1_BPTX_AND_Ref1_VME", &L1_BPTX_AND_Ref1_VME, &b_L1_BPTX_AND_Ref1_VME);
   fChain->SetBranchAddress("L1_BPTX_AND_Ref3_VME", &L1_BPTX_AND_Ref3_VME, &b_L1_BPTX_AND_Ref3_VME);
   fChain->SetBranchAddress("L1_BPTX_AND_Ref4_VME", &L1_BPTX_AND_Ref4_VME, &b_L1_BPTX_AND_Ref4_VME);
   fChain->SetBranchAddress("L1_BPTX_BeamGas_B1_VME", &L1_BPTX_BeamGas_B1_VME, &b_L1_BPTX_BeamGas_B1_VME);
   fChain->SetBranchAddress("L1_BPTX_BeamGas_B2_VME", &L1_BPTX_BeamGas_B2_VME, &b_L1_BPTX_BeamGas_B2_VME);
   fChain->SetBranchAddress("L1_BPTX_BeamGas_Ref1_VME", &L1_BPTX_BeamGas_Ref1_VME, &b_L1_BPTX_BeamGas_Ref1_VME);
   fChain->SetBranchAddress("L1_BPTX_BeamGas_Ref2_VME", &L1_BPTX_BeamGas_Ref2_VME, &b_L1_BPTX_BeamGas_Ref2_VME);
   fChain->SetBranchAddress("L1_BPTX_NotOR_VME", &L1_BPTX_NotOR_VME, &b_L1_BPTX_NotOR_VME);
   fChain->SetBranchAddress("L1_BPTX_OR_Ref3_VME", &L1_BPTX_OR_Ref3_VME, &b_L1_BPTX_OR_Ref3_VME);
   fChain->SetBranchAddress("L1_BPTX_OR_Ref4_VME", &L1_BPTX_OR_Ref4_VME, &b_L1_BPTX_OR_Ref4_VME);
   fChain->SetBranchAddress("L1_BPTX_RefAND_VME", &L1_BPTX_RefAND_VME, &b_L1_BPTX_RefAND_VME);
   fChain->SetBranchAddress("L1_BptxMinus", &L1_BptxMinus, &b_L1_BptxMinus);
   fChain->SetBranchAddress("L1_BptxOR", &L1_BptxOR, &b_L1_BptxOR);
   fChain->SetBranchAddress("L1_BptxPlus", &L1_BptxPlus, &b_L1_BptxPlus);
   fChain->SetBranchAddress("L1_BptxXOR", &L1_BptxXOR, &b_L1_BptxXOR);
   fChain->SetBranchAddress("L1_CDC_SingleMu_3_er1p2_TOP120_DPHI2p618_3p142", &L1_CDC_SingleMu_3_er1p2_TOP120_DPHI2p618_3p142, &b_L1_CDC_SingleMu_3_er1p2_TOP120_DPHI2p618_3p142);
   fChain->SetBranchAddress("L1_DoubleEG8er2p5_HTT260er", &L1_DoubleEG8er2p5_HTT260er, &b_L1_DoubleEG8er2p5_HTT260er);
   fChain->SetBranchAddress("L1_DoubleEG8er2p5_HTT280er", &L1_DoubleEG8er2p5_HTT280er, &b_L1_DoubleEG8er2p5_HTT280er);
   fChain->SetBranchAddress("L1_DoubleEG8er2p5_HTT300er", &L1_DoubleEG8er2p5_HTT300er, &b_L1_DoubleEG8er2p5_HTT300er);
   fChain->SetBranchAddress("L1_DoubleEG8er2p5_HTT320er", &L1_DoubleEG8er2p5_HTT320er, &b_L1_DoubleEG8er2p5_HTT320er);
   fChain->SetBranchAddress("L1_DoubleEG8er2p5_HTT340er", &L1_DoubleEG8er2p5_HTT340er, &b_L1_DoubleEG8er2p5_HTT340er);
   fChain->SetBranchAddress("L1_DoubleEG_15_10_er2p5", &L1_DoubleEG_15_10_er2p5, &b_L1_DoubleEG_15_10_er2p5);
   fChain->SetBranchAddress("L1_DoubleEG_20_10_er2p5", &L1_DoubleEG_20_10_er2p5, &b_L1_DoubleEG_20_10_er2p5);
   fChain->SetBranchAddress("L1_DoubleEG_22_10_er2p5", &L1_DoubleEG_22_10_er2p5, &b_L1_DoubleEG_22_10_er2p5);
   fChain->SetBranchAddress("L1_DoubleEG_25_12_er2p5", &L1_DoubleEG_25_12_er2p5, &b_L1_DoubleEG_25_12_er2p5);
   fChain->SetBranchAddress("L1_DoubleEG_25_14_er2p5", &L1_DoubleEG_25_14_er2p5, &b_L1_DoubleEG_25_14_er2p5);
   fChain->SetBranchAddress("L1_DoubleEG_27_14_er2p5", &L1_DoubleEG_27_14_er2p5, &b_L1_DoubleEG_27_14_er2p5);
   fChain->SetBranchAddress("L1_DoubleEG_LooseIso20_10_er2p5", &L1_DoubleEG_LooseIso20_10_er2p5, &b_L1_DoubleEG_LooseIso20_10_er2p5);
   fChain->SetBranchAddress("L1_DoubleEG_LooseIso22_10_er2p5", &L1_DoubleEG_LooseIso22_10_er2p5, &b_L1_DoubleEG_LooseIso22_10_er2p5);
   fChain->SetBranchAddress("L1_DoubleEG_LooseIso22_12_er2p5", &L1_DoubleEG_LooseIso22_12_er2p5, &b_L1_DoubleEG_LooseIso22_12_er2p5);
   fChain->SetBranchAddress("L1_DoubleEG_LooseIso25_12_er2p5", &L1_DoubleEG_LooseIso25_12_er2p5, &b_L1_DoubleEG_LooseIso25_12_er2p5);
   fChain->SetBranchAddress("L1_DoubleIsoTau28er2p1", &L1_DoubleIsoTau28er2p1, &b_L1_DoubleIsoTau28er2p1);
   fChain->SetBranchAddress("L1_DoubleIsoTau28er2p1_Mass_Max80", &L1_DoubleIsoTau28er2p1_Mass_Max80, &b_L1_DoubleIsoTau28er2p1_Mass_Max80);
   fChain->SetBranchAddress("L1_DoubleIsoTau28er2p1_Mass_Max90", &L1_DoubleIsoTau28er2p1_Mass_Max90, &b_L1_DoubleIsoTau28er2p1_Mass_Max90);
   fChain->SetBranchAddress("L1_DoubleIsoTau30er2p1", &L1_DoubleIsoTau30er2p1, &b_L1_DoubleIsoTau30er2p1);
   fChain->SetBranchAddress("L1_DoubleIsoTau30er2p1_Mass_Max80", &L1_DoubleIsoTau30er2p1_Mass_Max80, &b_L1_DoubleIsoTau30er2p1_Mass_Max80);
   fChain->SetBranchAddress("L1_DoubleIsoTau30er2p1_Mass_Max90", &L1_DoubleIsoTau30er2p1_Mass_Max90, &b_L1_DoubleIsoTau30er2p1_Mass_Max90);
   fChain->SetBranchAddress("L1_DoubleIsoTau32er2p1", &L1_DoubleIsoTau32er2p1, &b_L1_DoubleIsoTau32er2p1);
   fChain->SetBranchAddress("L1_DoubleIsoTau34er2p1", &L1_DoubleIsoTau34er2p1, &b_L1_DoubleIsoTau34er2p1);
   fChain->SetBranchAddress("L1_DoubleIsoTau36er2p1", &L1_DoubleIsoTau36er2p1, &b_L1_DoubleIsoTau36er2p1);
   fChain->SetBranchAddress("L1_DoubleJet100er2p3_dEta_Max1p6", &L1_DoubleJet100er2p3_dEta_Max1p6, &b_L1_DoubleJet100er2p3_dEta_Max1p6);
   fChain->SetBranchAddress("L1_DoubleJet100er2p5", &L1_DoubleJet100er2p5, &b_L1_DoubleJet100er2p5);
   fChain->SetBranchAddress("L1_DoubleJet112er2p3_dEta_Max1p6", &L1_DoubleJet112er2p3_dEta_Max1p6, &b_L1_DoubleJet112er2p3_dEta_Max1p6);
   fChain->SetBranchAddress("L1_DoubleJet120er2p5", &L1_DoubleJet120er2p5, &b_L1_DoubleJet120er2p5);
   fChain->SetBranchAddress("L1_DoubleJet150er2p5", &L1_DoubleJet150er2p5, &b_L1_DoubleJet150er2p5);
   fChain->SetBranchAddress("L1_DoubleJet30er2p5_Mass_Min150_dEta_Max1p5", &L1_DoubleJet30er2p5_Mass_Min150_dEta_Max1p5, &b_L1_DoubleJet30er2p5_Mass_Min150_dEta_Max1p5);
   fChain->SetBranchAddress("L1_DoubleJet30er2p5_Mass_Min200_dEta_Max1p5", &L1_DoubleJet30er2p5_Mass_Min200_dEta_Max1p5, &b_L1_DoubleJet30er2p5_Mass_Min200_dEta_Max1p5);
   fChain->SetBranchAddress("L1_DoubleJet30er2p5_Mass_Min250_dEta_Max1p5", &L1_DoubleJet30er2p5_Mass_Min250_dEta_Max1p5, &b_L1_DoubleJet30er2p5_Mass_Min250_dEta_Max1p5);
   fChain->SetBranchAddress("L1_DoubleJet30er2p5_Mass_Min300_dEta_Max1p5", &L1_DoubleJet30er2p5_Mass_Min300_dEta_Max1p5, &b_L1_DoubleJet30er2p5_Mass_Min300_dEta_Max1p5);
   fChain->SetBranchAddress("L1_DoubleJet30er2p5_Mass_Min330_dEta_Max1p5", &L1_DoubleJet30er2p5_Mass_Min330_dEta_Max1p5, &b_L1_DoubleJet30er2p5_Mass_Min330_dEta_Max1p5);
   fChain->SetBranchAddress("L1_DoubleJet30er2p5_Mass_Min360_dEta_Max1p5", &L1_DoubleJet30er2p5_Mass_Min360_dEta_Max1p5, &b_L1_DoubleJet30er2p5_Mass_Min360_dEta_Max1p5);
   fChain->SetBranchAddress("L1_DoubleJet35_Mass_Min450_IsoTau45_RmOvlp", &L1_DoubleJet35_Mass_Min450_IsoTau45_RmOvlp, &b_L1_DoubleJet35_Mass_Min450_IsoTau45_RmOvlp);
   fChain->SetBranchAddress("L1_DoubleJet40er2p5", &L1_DoubleJet40er2p5, &b_L1_DoubleJet40er2p5);
   fChain->SetBranchAddress("L1_DoubleJet_100_30_DoubleJet30_Mass_Min620", &L1_DoubleJet_100_30_DoubleJet30_Mass_Min620, &b_L1_DoubleJet_100_30_DoubleJet30_Mass_Min620);
   fChain->SetBranchAddress("L1_DoubleJet_110_35_DoubleJet35_Mass_Min620", &L1_DoubleJet_110_35_DoubleJet35_Mass_Min620, &b_L1_DoubleJet_110_35_DoubleJet35_Mass_Min620);
   fChain->SetBranchAddress("L1_DoubleJet_115_40_DoubleJet40_Mass_Min620", &L1_DoubleJet_115_40_DoubleJet40_Mass_Min620, &b_L1_DoubleJet_115_40_DoubleJet40_Mass_Min620);
   fChain->SetBranchAddress("L1_DoubleJet_115_40_DoubleJet40_Mass_Min620_Jet60TT28", &L1_DoubleJet_115_40_DoubleJet40_Mass_Min620_Jet60TT28, &b_L1_DoubleJet_115_40_DoubleJet40_Mass_Min620_Jet60TT28);
   fChain->SetBranchAddress("L1_DoubleJet_120_45_DoubleJet45_Mass_Min620", &L1_DoubleJet_120_45_DoubleJet45_Mass_Min620, &b_L1_DoubleJet_120_45_DoubleJet45_Mass_Min620);
   fChain->SetBranchAddress("L1_DoubleJet_120_45_DoubleJet45_Mass_Min620_Jet60TT28", &L1_DoubleJet_120_45_DoubleJet45_Mass_Min620_Jet60TT28, &b_L1_DoubleJet_120_45_DoubleJet45_Mass_Min620_Jet60TT28);
   fChain->SetBranchAddress("L1_DoubleJet_80_30_Mass_Min420_DoubleMu0_SQ", &L1_DoubleJet_80_30_Mass_Min420_DoubleMu0_SQ, &b_L1_DoubleJet_80_30_Mass_Min420_DoubleMu0_SQ);
   fChain->SetBranchAddress("L1_DoubleJet_80_30_Mass_Min420_IsoTau40_RmOvlp", &L1_DoubleJet_80_30_Mass_Min420_IsoTau40_RmOvlp, &b_L1_DoubleJet_80_30_Mass_Min420_IsoTau40_RmOvlp);
   fChain->SetBranchAddress("L1_DoubleJet_80_30_Mass_Min420_Mu8", &L1_DoubleJet_80_30_Mass_Min420_Mu8, &b_L1_DoubleJet_80_30_Mass_Min420_Mu8);
   fChain->SetBranchAddress("L1_DoubleJet_90_30_DoubleJet30_Mass_Min620", &L1_DoubleJet_90_30_DoubleJet30_Mass_Min620, &b_L1_DoubleJet_90_30_DoubleJet30_Mass_Min620);
   fChain->SetBranchAddress("L1_DoubleLooseIsoEG22er2p1", &L1_DoubleLooseIsoEG22er2p1, &b_L1_DoubleLooseIsoEG22er2p1);
   fChain->SetBranchAddress("L1_DoubleLooseIsoEG24er2p1", &L1_DoubleLooseIsoEG24er2p1, &b_L1_DoubleLooseIsoEG24er2p1);
   fChain->SetBranchAddress("L1_DoubleMu0", &L1_DoubleMu0, &b_L1_DoubleMu0);
   fChain->SetBranchAddress("L1_DoubleMu0_Mass_Min1", &L1_DoubleMu0_Mass_Min1, &b_L1_DoubleMu0_Mass_Min1);
   fChain->SetBranchAddress("L1_DoubleMu0_OQ", &L1_DoubleMu0_OQ, &b_L1_DoubleMu0_OQ);
   fChain->SetBranchAddress("L1_DoubleMu0_SQ", &L1_DoubleMu0_SQ, &b_L1_DoubleMu0_SQ);
   fChain->SetBranchAddress("L1_DoubleMu0_SQ_OS", &L1_DoubleMu0_SQ_OS, &b_L1_DoubleMu0_SQ_OS);
   fChain->SetBranchAddress("L1_DoubleMu0_dR_Max1p6_Jet90er2p5_dR_Max0p8", &L1_DoubleMu0_dR_Max1p6_Jet90er2p5_dR_Max0p8, &b_L1_DoubleMu0_dR_Max1p6_Jet90er2p5_dR_Max0p8);
   fChain->SetBranchAddress("L1_DoubleMu0er1p4_SQ_OS_dR_Max1p4", &L1_DoubleMu0er1p4_SQ_OS_dR_Max1p4, &b_L1_DoubleMu0er1p4_SQ_OS_dR_Max1p4);
   fChain->SetBranchAddress("L1_DoubleMu0er1p5_SQ", &L1_DoubleMu0er1p5_SQ, &b_L1_DoubleMu0er1p5_SQ);
   fChain->SetBranchAddress("L1_DoubleMu0er1p5_SQ_OS", &L1_DoubleMu0er1p5_SQ_OS, &b_L1_DoubleMu0er1p5_SQ_OS);
   fChain->SetBranchAddress("L1_DoubleMu0er1p5_SQ_OS_dR_Max1p4", &L1_DoubleMu0er1p5_SQ_OS_dR_Max1p4, &b_L1_DoubleMu0er1p5_SQ_OS_dR_Max1p4);
   fChain->SetBranchAddress("L1_DoubleMu0er1p5_SQ_dR_Max1p4", &L1_DoubleMu0er1p5_SQ_dR_Max1p4, &b_L1_DoubleMu0er1p5_SQ_dR_Max1p4);
   fChain->SetBranchAddress("L1_DoubleMu0er2p0_SQ_OS_dR_Max1p4", &L1_DoubleMu0er2p0_SQ_OS_dR_Max1p4, &b_L1_DoubleMu0er2p0_SQ_OS_dR_Max1p4);
   fChain->SetBranchAddress("L1_DoubleMu0er2p0_SQ_dR_Max1p4", &L1_DoubleMu0er2p0_SQ_dR_Max1p4, &b_L1_DoubleMu0er2p0_SQ_dR_Max1p4);
   fChain->SetBranchAddress("L1_DoubleMu18er2p1", &L1_DoubleMu18er2p1, &b_L1_DoubleMu18er2p1);
   fChain->SetBranchAddress("L1_DoubleMu3_OS_DoubleEG7p5Upsilon", &L1_DoubleMu3_OS_DoubleEG7p5Upsilon, &b_L1_DoubleMu3_OS_DoubleEG7p5Upsilon);
   fChain->SetBranchAddress("L1_DoubleMu3_SQ_ETMHF50_HTT60er", &L1_DoubleMu3_SQ_ETMHF50_HTT60er, &b_L1_DoubleMu3_SQ_ETMHF50_HTT60er);
   fChain->SetBranchAddress("L1_DoubleMu3_SQ_ETMHF50_Jet60er2p5", &L1_DoubleMu3_SQ_ETMHF50_Jet60er2p5, &b_L1_DoubleMu3_SQ_ETMHF50_Jet60er2p5);
   fChain->SetBranchAddress("L1_DoubleMu3_SQ_ETMHF50_Jet60er2p5_OR_DoubleJet40er2p5", &L1_DoubleMu3_SQ_ETMHF50_Jet60er2p5_OR_DoubleJet40er2p5, &b_L1_DoubleMu3_SQ_ETMHF50_Jet60er2p5_OR_DoubleJet40er2p5);
   fChain->SetBranchAddress("L1_DoubleMu3_SQ_ETMHF60_Jet60er2p5", &L1_DoubleMu3_SQ_ETMHF60_Jet60er2p5, &b_L1_DoubleMu3_SQ_ETMHF60_Jet60er2p5);
   fChain->SetBranchAddress("L1_DoubleMu3_SQ_HTT220er", &L1_DoubleMu3_SQ_HTT220er, &b_L1_DoubleMu3_SQ_HTT220er);
   fChain->SetBranchAddress("L1_DoubleMu3_SQ_HTT240er", &L1_DoubleMu3_SQ_HTT240er, &b_L1_DoubleMu3_SQ_HTT240er);
   fChain->SetBranchAddress("L1_DoubleMu3_SQ_HTT260er", &L1_DoubleMu3_SQ_HTT260er, &b_L1_DoubleMu3_SQ_HTT260er);
   fChain->SetBranchAddress("L1_DoubleMu3_dR_Max1p6_Jet90er2p5_dR_Max0p8", &L1_DoubleMu3_dR_Max1p6_Jet90er2p5_dR_Max0p8, &b_L1_DoubleMu3_dR_Max1p6_Jet90er2p5_dR_Max0p8);
   fChain->SetBranchAddress("L1_DoubleMu4_SQ_EG9er2p5", &L1_DoubleMu4_SQ_EG9er2p5, &b_L1_DoubleMu4_SQ_EG9er2p5);
   fChain->SetBranchAddress("L1_DoubleMu4_SQ_OS", &L1_DoubleMu4_SQ_OS, &b_L1_DoubleMu4_SQ_OS);
   fChain->SetBranchAddress("L1_DoubleMu4_SQ_OS_dR_Max1p2", &L1_DoubleMu4_SQ_OS_dR_Max1p2, &b_L1_DoubleMu4_SQ_OS_dR_Max1p2);
   fChain->SetBranchAddress("L1_DoubleMu4p5_SQ_OS", &L1_DoubleMu4p5_SQ_OS, &b_L1_DoubleMu4p5_SQ_OS);
   fChain->SetBranchAddress("L1_DoubleMu4p5_SQ_OS_dR_Max1p2", &L1_DoubleMu4p5_SQ_OS_dR_Max1p2, &b_L1_DoubleMu4p5_SQ_OS_dR_Max1p2);
   fChain->SetBranchAddress("L1_DoubleMu4p5er2p0_SQ_OS", &L1_DoubleMu4p5er2p0_SQ_OS, &b_L1_DoubleMu4p5er2p0_SQ_OS);
   fChain->SetBranchAddress("L1_DoubleMu4p5er2p0_SQ_OS_Mass7to18", &L1_DoubleMu4p5er2p0_SQ_OS_Mass7to18, &b_L1_DoubleMu4p5er2p0_SQ_OS_Mass7to18);
   fChain->SetBranchAddress("L1_DoubleMu4p5er2p0_SQ_OS_Mass_Min7", &L1_DoubleMu4p5er2p0_SQ_OS_Mass_Min7, &b_L1_DoubleMu4p5er2p0_SQ_OS_Mass_Min7);
   fChain->SetBranchAddress("L1_DoubleMu5Upsilon_OS_DoubleEG3", &L1_DoubleMu5Upsilon_OS_DoubleEG3, &b_L1_DoubleMu5Upsilon_OS_DoubleEG3);
   fChain->SetBranchAddress("L1_DoubleMu5_SQ_EG9er2p5", &L1_DoubleMu5_SQ_EG9er2p5, &b_L1_DoubleMu5_SQ_EG9er2p5);
   fChain->SetBranchAddress("L1_DoubleMu8_SQ", &L1_DoubleMu8_SQ, &b_L1_DoubleMu8_SQ);
   fChain->SetBranchAddress("L1_DoubleMu9_SQ", &L1_DoubleMu9_SQ, &b_L1_DoubleMu9_SQ);
   fChain->SetBranchAddress("L1_DoubleMu_12_5", &L1_DoubleMu_12_5, &b_L1_DoubleMu_12_5);
   fChain->SetBranchAddress("L1_DoubleMu_15_5_SQ", &L1_DoubleMu_15_5_SQ, &b_L1_DoubleMu_15_5_SQ);
   fChain->SetBranchAddress("L1_DoubleMu_15_7", &L1_DoubleMu_15_7, &b_L1_DoubleMu_15_7);
   fChain->SetBranchAddress("L1_DoubleMu_15_7_Mass_Min1", &L1_DoubleMu_15_7_Mass_Min1, &b_L1_DoubleMu_15_7_Mass_Min1);
   fChain->SetBranchAddress("L1_DoubleMu_15_7_SQ", &L1_DoubleMu_15_7_SQ, &b_L1_DoubleMu_15_7_SQ);
   fChain->SetBranchAddress("L1_DoubleTau70er2p1", &L1_DoubleTau70er2p1, &b_L1_DoubleTau70er2p1);
   fChain->SetBranchAddress("L1_ETM120", &L1_ETM120, &b_L1_ETM120);
   fChain->SetBranchAddress("L1_ETM150", &L1_ETM150, &b_L1_ETM150);
   fChain->SetBranchAddress("L1_ETMHF100", &L1_ETMHF100, &b_L1_ETMHF100);
   fChain->SetBranchAddress("L1_ETMHF100_HTT60er", &L1_ETMHF100_HTT60er, &b_L1_ETMHF100_HTT60er);
   fChain->SetBranchAddress("L1_ETMHF110", &L1_ETMHF110, &b_L1_ETMHF110);
   fChain->SetBranchAddress("L1_ETMHF110_HTT60er", &L1_ETMHF110_HTT60er, &b_L1_ETMHF110_HTT60er);
   fChain->SetBranchAddress("L1_ETMHF110_HTT60er_NotSecondBunchInTrain", &L1_ETMHF110_HTT60er_NotSecondBunchInTrain, &b_L1_ETMHF110_HTT60er_NotSecondBunchInTrain);
   fChain->SetBranchAddress("L1_ETMHF120", &L1_ETMHF120, &b_L1_ETMHF120);
   fChain->SetBranchAddress("L1_ETMHF120_HTT60er", &L1_ETMHF120_HTT60er, &b_L1_ETMHF120_HTT60er);
   fChain->SetBranchAddress("L1_ETMHF120_NotSecondBunchInTrain", &L1_ETMHF120_NotSecondBunchInTrain, &b_L1_ETMHF120_NotSecondBunchInTrain);
   fChain->SetBranchAddress("L1_ETMHF130", &L1_ETMHF130, &b_L1_ETMHF130);
   fChain->SetBranchAddress("L1_ETMHF130_HTT60er", &L1_ETMHF130_HTT60er, &b_L1_ETMHF130_HTT60er);
   fChain->SetBranchAddress("L1_ETMHF140", &L1_ETMHF140, &b_L1_ETMHF140);
   fChain->SetBranchAddress("L1_ETMHF150", &L1_ETMHF150, &b_L1_ETMHF150);
   fChain->SetBranchAddress("L1_ETMHF90_HTT60er", &L1_ETMHF90_HTT60er, &b_L1_ETMHF90_HTT60er);
   fChain->SetBranchAddress("L1_ETT1200", &L1_ETT1200, &b_L1_ETT1200);
   fChain->SetBranchAddress("L1_ETT1600", &L1_ETT1600, &b_L1_ETT1600);
   fChain->SetBranchAddress("L1_ETT2000", &L1_ETT2000, &b_L1_ETT2000);
   fChain->SetBranchAddress("L1_FirstBunchAfterTrain", &L1_FirstBunchAfterTrain, &b_L1_FirstBunchAfterTrain);
   fChain->SetBranchAddress("L1_FirstBunchBeforeTrain", &L1_FirstBunchBeforeTrain, &b_L1_FirstBunchBeforeTrain);
   fChain->SetBranchAddress("L1_FirstBunchInTrain", &L1_FirstBunchInTrain, &b_L1_FirstBunchInTrain);
   fChain->SetBranchAddress("L1_FirstCollisionInOrbit", &L1_FirstCollisionInOrbit, &b_L1_FirstCollisionInOrbit);
   fChain->SetBranchAddress("L1_FirstCollisionInTrain", &L1_FirstCollisionInTrain, &b_L1_FirstCollisionInTrain);
   fChain->SetBranchAddress("L1_HCAL_LaserMon_Trig", &L1_HCAL_LaserMon_Trig, &b_L1_HCAL_LaserMon_Trig);
   fChain->SetBranchAddress("L1_HCAL_LaserMon_Veto", &L1_HCAL_LaserMon_Veto, &b_L1_HCAL_LaserMon_Veto);
   fChain->SetBranchAddress("L1_HTT120er", &L1_HTT120er, &b_L1_HTT120er);
   fChain->SetBranchAddress("L1_HTT160er", &L1_HTT160er, &b_L1_HTT160er);
   fChain->SetBranchAddress("L1_HTT200er", &L1_HTT200er, &b_L1_HTT200er);
   fChain->SetBranchAddress("L1_HTT255er", &L1_HTT255er, &b_L1_HTT255er);
   fChain->SetBranchAddress("L1_HTT280er", &L1_HTT280er, &b_L1_HTT280er);
   fChain->SetBranchAddress("L1_HTT280er_QuadJet_70_55_40_35_er2p4", &L1_HTT280er_QuadJet_70_55_40_35_er2p4, &b_L1_HTT280er_QuadJet_70_55_40_35_er2p4);
   fChain->SetBranchAddress("L1_HTT320er", &L1_HTT320er, &b_L1_HTT320er);
   fChain->SetBranchAddress("L1_HTT320er_QuadJet_70_55_40_40_er2p4", &L1_HTT320er_QuadJet_70_55_40_40_er2p4, &b_L1_HTT320er_QuadJet_70_55_40_40_er2p4);
   fChain->SetBranchAddress("L1_HTT320er_QuadJet_80_60_er2p1_45_40_er2p3", &L1_HTT320er_QuadJet_80_60_er2p1_45_40_er2p3, &b_L1_HTT320er_QuadJet_80_60_er2p1_45_40_er2p3);
   fChain->SetBranchAddress("L1_HTT320er_QuadJet_80_60_er2p1_50_45_er2p3", &L1_HTT320er_QuadJet_80_60_er2p1_50_45_er2p3, &b_L1_HTT320er_QuadJet_80_60_er2p1_50_45_er2p3);
   fChain->SetBranchAddress("L1_HTT360er", &L1_HTT360er, &b_L1_HTT360er);
   fChain->SetBranchAddress("L1_HTT400er", &L1_HTT400er, &b_L1_HTT400er);
   fChain->SetBranchAddress("L1_HTT450er", &L1_HTT450er, &b_L1_HTT450er);
   fChain->SetBranchAddress("L1_IsoEG32er2p5_Mt40", &L1_IsoEG32er2p5_Mt40, &b_L1_IsoEG32er2p5_Mt40);
   fChain->SetBranchAddress("L1_IsoEG32er2p5_Mt44", &L1_IsoEG32er2p5_Mt44, &b_L1_IsoEG32er2p5_Mt44);
   fChain->SetBranchAddress("L1_IsoEG32er2p5_Mt48", &L1_IsoEG32er2p5_Mt48, &b_L1_IsoEG32er2p5_Mt48);
   fChain->SetBranchAddress("L1_IsoTau40er2p1_ETMHF100", &L1_IsoTau40er2p1_ETMHF100, &b_L1_IsoTau40er2p1_ETMHF100);
   fChain->SetBranchAddress("L1_IsoTau40er2p1_ETMHF110", &L1_IsoTau40er2p1_ETMHF110, &b_L1_IsoTau40er2p1_ETMHF110);
   fChain->SetBranchAddress("L1_IsoTau40er2p1_ETMHF80", &L1_IsoTau40er2p1_ETMHF80, &b_L1_IsoTau40er2p1_ETMHF80);
   fChain->SetBranchAddress("L1_IsoTau40er2p1_ETMHF90", &L1_IsoTau40er2p1_ETMHF90, &b_L1_IsoTau40er2p1_ETMHF90);
   fChain->SetBranchAddress("L1_IsolatedBunch", &L1_IsolatedBunch, &b_L1_IsolatedBunch);
   fChain->SetBranchAddress("L1_LastBunchInTrain", &L1_LastBunchInTrain, &b_L1_LastBunchInTrain);
   fChain->SetBranchAddress("L1_LastCollisionInTrain", &L1_LastCollisionInTrain, &b_L1_LastCollisionInTrain);
   fChain->SetBranchAddress("L1_LooseIsoEG22er2p1_IsoTau26er2p1_dR_Min0p3", &L1_LooseIsoEG22er2p1_IsoTau26er2p1_dR_Min0p3, &b_L1_LooseIsoEG22er2p1_IsoTau26er2p1_dR_Min0p3);
   fChain->SetBranchAddress("L1_LooseIsoEG22er2p1_Tau70er2p1_dR_Min0p3", &L1_LooseIsoEG22er2p1_Tau70er2p1_dR_Min0p3, &b_L1_LooseIsoEG22er2p1_Tau70er2p1_dR_Min0p3);
   fChain->SetBranchAddress("L1_LooseIsoEG24er2p1_HTT100er", &L1_LooseIsoEG24er2p1_HTT100er, &b_L1_LooseIsoEG24er2p1_HTT100er);
   fChain->SetBranchAddress("L1_LooseIsoEG24er2p1_IsoTau27er2p1_dR_Min0p3", &L1_LooseIsoEG24er2p1_IsoTau27er2p1_dR_Min0p3, &b_L1_LooseIsoEG24er2p1_IsoTau27er2p1_dR_Min0p3);
   fChain->SetBranchAddress("L1_LooseIsoEG26er2p1_HTT100er", &L1_LooseIsoEG26er2p1_HTT100er, &b_L1_LooseIsoEG26er2p1_HTT100er);
   fChain->SetBranchAddress("L1_LooseIsoEG26er2p1_Jet34er2p5_dR_Min0p3", &L1_LooseIsoEG26er2p1_Jet34er2p5_dR_Min0p3, &b_L1_LooseIsoEG26er2p1_Jet34er2p5_dR_Min0p3);
   fChain->SetBranchAddress("L1_LooseIsoEG28er2p1_HTT100er", &L1_LooseIsoEG28er2p1_HTT100er, &b_L1_LooseIsoEG28er2p1_HTT100er);
   fChain->SetBranchAddress("L1_LooseIsoEG28er2p1_Jet34er2p5_dR_Min0p3", &L1_LooseIsoEG28er2p1_Jet34er2p5_dR_Min0p3, &b_L1_LooseIsoEG28er2p1_Jet34er2p5_dR_Min0p3);
   fChain->SetBranchAddress("L1_LooseIsoEG30er2p1_HTT100er", &L1_LooseIsoEG30er2p1_HTT100er, &b_L1_LooseIsoEG30er2p1_HTT100er);
   fChain->SetBranchAddress("L1_LooseIsoEG30er2p1_Jet34er2p5_dR_Min0p3", &L1_LooseIsoEG30er2p1_Jet34er2p5_dR_Min0p3, &b_L1_LooseIsoEG30er2p1_Jet34er2p5_dR_Min0p3);
   fChain->SetBranchAddress("L1_MinimumBiasHF0_AND_BptxAND", &L1_MinimumBiasHF0_AND_BptxAND, &b_L1_MinimumBiasHF0_AND_BptxAND);
   fChain->SetBranchAddress("L1_Mu10er2p3_Jet32er2p3_dR_Max0p4_DoubleJet32er2p3_dEta_Max1p6", &L1_Mu10er2p3_Jet32er2p3_dR_Max0p4_DoubleJet32er2p3_dEta_Max1p6, &b_L1_Mu10er2p3_Jet32er2p3_dR_Max0p4_DoubleJet32er2p3_dEta_Max1p6);
   fChain->SetBranchAddress("L1_Mu12er2p3_Jet40er2p1_dR_Max0p4_DoubleJet40er2p1_dEta_Max1p6", &L1_Mu12er2p3_Jet40er2p1_dR_Max0p4_DoubleJet40er2p1_dEta_Max1p6, &b_L1_Mu12er2p3_Jet40er2p1_dR_Max0p4_DoubleJet40er2p1_dEta_Max1p6);
   fChain->SetBranchAddress("L1_Mu12er2p3_Jet40er2p3_dR_Max0p4_DoubleJet40er2p3_dEta_Max1p6", &L1_Mu12er2p3_Jet40er2p3_dR_Max0p4_DoubleJet40er2p3_dEta_Max1p6, &b_L1_Mu12er2p3_Jet40er2p3_dR_Max0p4_DoubleJet40er2p3_dEta_Max1p6);
   fChain->SetBranchAddress("L1_Mu18er2p1_Tau24er2p1", &L1_Mu18er2p1_Tau24er2p1, &b_L1_Mu18er2p1_Tau24er2p1);
   fChain->SetBranchAddress("L1_Mu18er2p1_Tau26er2p1", &L1_Mu18er2p1_Tau26er2p1, &b_L1_Mu18er2p1_Tau26er2p1);
   fChain->SetBranchAddress("L1_Mu20_EG10er2p5", &L1_Mu20_EG10er2p5, &b_L1_Mu20_EG10er2p5);
   fChain->SetBranchAddress("L1_Mu22er2p1_IsoTau28er2p1", &L1_Mu22er2p1_IsoTau28er2p1, &b_L1_Mu22er2p1_IsoTau28er2p1);
   fChain->SetBranchAddress("L1_Mu22er2p1_IsoTau30er2p1", &L1_Mu22er2p1_IsoTau30er2p1, &b_L1_Mu22er2p1_IsoTau30er2p1);
   fChain->SetBranchAddress("L1_Mu22er2p1_IsoTau32er2p1", &L1_Mu22er2p1_IsoTau32er2p1, &b_L1_Mu22er2p1_IsoTau32er2p1);
   fChain->SetBranchAddress("L1_Mu22er2p1_IsoTau34er2p1", &L1_Mu22er2p1_IsoTau34er2p1, &b_L1_Mu22er2p1_IsoTau34er2p1);
   fChain->SetBranchAddress("L1_Mu22er2p1_IsoTau36er2p1", &L1_Mu22er2p1_IsoTau36er2p1, &b_L1_Mu22er2p1_IsoTau36er2p1);
   fChain->SetBranchAddress("L1_Mu22er2p1_IsoTau40er2p1", &L1_Mu22er2p1_IsoTau40er2p1, &b_L1_Mu22er2p1_IsoTau40er2p1);
   fChain->SetBranchAddress("L1_Mu22er2p1_Tau70er2p1", &L1_Mu22er2p1_Tau70er2p1, &b_L1_Mu22er2p1_Tau70er2p1);
   fChain->SetBranchAddress("L1_Mu3_Jet120er2p5_dR_Max0p4", &L1_Mu3_Jet120er2p5_dR_Max0p4, &b_L1_Mu3_Jet120er2p5_dR_Max0p4);
   fChain->SetBranchAddress("L1_Mu3_Jet120er2p5_dR_Max0p8", &L1_Mu3_Jet120er2p5_dR_Max0p8, &b_L1_Mu3_Jet120er2p5_dR_Max0p8);
   fChain->SetBranchAddress("L1_Mu3_Jet16er2p5_dR_Max0p4", &L1_Mu3_Jet16er2p5_dR_Max0p4, &b_L1_Mu3_Jet16er2p5_dR_Max0p4);
   fChain->SetBranchAddress("L1_Mu3_Jet30er2p5", &L1_Mu3_Jet30er2p5, &b_L1_Mu3_Jet30er2p5);
   fChain->SetBranchAddress("L1_Mu3_Jet35er2p5_dR_Max0p4", &L1_Mu3_Jet35er2p5_dR_Max0p4, &b_L1_Mu3_Jet35er2p5_dR_Max0p4);
   fChain->SetBranchAddress("L1_Mu3_Jet60er2p5_dR_Max0p4", &L1_Mu3_Jet60er2p5_dR_Max0p4, &b_L1_Mu3_Jet60er2p5_dR_Max0p4);
   fChain->SetBranchAddress("L1_Mu3_Jet80er2p5_dR_Max0p4", &L1_Mu3_Jet80er2p5_dR_Max0p4, &b_L1_Mu3_Jet80er2p5_dR_Max0p4);
   fChain->SetBranchAddress("L1_Mu3er1p5_Jet100er2p5_ETMHF40", &L1_Mu3er1p5_Jet100er2p5_ETMHF40, &b_L1_Mu3er1p5_Jet100er2p5_ETMHF40);
   fChain->SetBranchAddress("L1_Mu3er1p5_Jet100er2p5_ETMHF50", &L1_Mu3er1p5_Jet100er2p5_ETMHF50, &b_L1_Mu3er1p5_Jet100er2p5_ETMHF50);
   fChain->SetBranchAddress("L1_Mu5_EG23er2p5", &L1_Mu5_EG23er2p5, &b_L1_Mu5_EG23er2p5);
   fChain->SetBranchAddress("L1_Mu5_LooseIsoEG20er2p5", &L1_Mu5_LooseIsoEG20er2p5, &b_L1_Mu5_LooseIsoEG20er2p5);
   fChain->SetBranchAddress("L1_Mu6_DoubleEG10er2p5", &L1_Mu6_DoubleEG10er2p5, &b_L1_Mu6_DoubleEG10er2p5);
   fChain->SetBranchAddress("L1_Mu6_DoubleEG12er2p5", &L1_Mu6_DoubleEG12er2p5, &b_L1_Mu6_DoubleEG12er2p5);
   fChain->SetBranchAddress("L1_Mu6_DoubleEG15er2p5", &L1_Mu6_DoubleEG15er2p5, &b_L1_Mu6_DoubleEG15er2p5);
   fChain->SetBranchAddress("L1_Mu6_DoubleEG17er2p5", &L1_Mu6_DoubleEG17er2p5, &b_L1_Mu6_DoubleEG17er2p5);
   fChain->SetBranchAddress("L1_Mu6_HTT240er", &L1_Mu6_HTT240er, &b_L1_Mu6_HTT240er);
   fChain->SetBranchAddress("L1_Mu6_HTT250er", &L1_Mu6_HTT250er, &b_L1_Mu6_HTT250er);
   fChain->SetBranchAddress("L1_Mu7_EG20er2p5", &L1_Mu7_EG20er2p5, &b_L1_Mu7_EG20er2p5);
   fChain->SetBranchAddress("L1_Mu7_EG23er2p5", &L1_Mu7_EG23er2p5, &b_L1_Mu7_EG23er2p5);
   fChain->SetBranchAddress("L1_Mu7_LooseIsoEG20er2p5", &L1_Mu7_LooseIsoEG20er2p5, &b_L1_Mu7_LooseIsoEG20er2p5);
   fChain->SetBranchAddress("L1_Mu7_LooseIsoEG23er2p5", &L1_Mu7_LooseIsoEG23er2p5, &b_L1_Mu7_LooseIsoEG23er2p5);
   fChain->SetBranchAddress("L1_NotBptxOR", &L1_NotBptxOR, &b_L1_NotBptxOR);
   fChain->SetBranchAddress("L1_QuadJet36er2p5_IsoTau52er2p1", &L1_QuadJet36er2p5_IsoTau52er2p1, &b_L1_QuadJet36er2p5_IsoTau52er2p1);
   fChain->SetBranchAddress("L1_QuadJet60er2p5", &L1_QuadJet60er2p5, &b_L1_QuadJet60er2p5);
   fChain->SetBranchAddress("L1_QuadJet_95_75_65_20_DoubleJet_75_65_er2p5_Jet20_FWD3p0", &L1_QuadJet_95_75_65_20_DoubleJet_75_65_er2p5_Jet20_FWD3p0, &b_L1_QuadJet_95_75_65_20_DoubleJet_75_65_er2p5_Jet20_FWD3p0);
   fChain->SetBranchAddress("L1_QuadMu0", &L1_QuadMu0, &b_L1_QuadMu0);
   fChain->SetBranchAddress("L1_QuadMu0_OQ", &L1_QuadMu0_OQ, &b_L1_QuadMu0_OQ);
   fChain->SetBranchAddress("L1_QuadMu0_SQ", &L1_QuadMu0_SQ, &b_L1_QuadMu0_SQ);
   fChain->SetBranchAddress("L1_SecondBunchInTrain", &L1_SecondBunchInTrain, &b_L1_SecondBunchInTrain);
   fChain->SetBranchAddress("L1_SecondLastBunchInTrain", &L1_SecondLastBunchInTrain, &b_L1_SecondLastBunchInTrain);
   fChain->SetBranchAddress("L1_SingleEG10er2p5", &L1_SingleEG10er2p5, &b_L1_SingleEG10er2p5);
   fChain->SetBranchAddress("L1_SingleEG15er2p5", &L1_SingleEG15er2p5, &b_L1_SingleEG15er2p5);
   fChain->SetBranchAddress("L1_SingleEG26er2p5", &L1_SingleEG26er2p5, &b_L1_SingleEG26er2p5);
   fChain->SetBranchAddress("L1_SingleEG28_FWD2p5", &L1_SingleEG28_FWD2p5, &b_L1_SingleEG28_FWD2p5);
   fChain->SetBranchAddress("L1_SingleEG28er1p5", &L1_SingleEG28er1p5, &b_L1_SingleEG28er1p5);
   fChain->SetBranchAddress("L1_SingleEG28er2p1", &L1_SingleEG28er2p1, &b_L1_SingleEG28er2p1);
   fChain->SetBranchAddress("L1_SingleEG28er2p5", &L1_SingleEG28er2p5, &b_L1_SingleEG28er2p5);
   fChain->SetBranchAddress("L1_SingleEG34er2p5", &L1_SingleEG34er2p5, &b_L1_SingleEG34er2p5);
   fChain->SetBranchAddress("L1_SingleEG36er2p5", &L1_SingleEG36er2p5, &b_L1_SingleEG36er2p5);
   fChain->SetBranchAddress("L1_SingleEG38er2p5", &L1_SingleEG38er2p5, &b_L1_SingleEG38er2p5);
   fChain->SetBranchAddress("L1_SingleEG40er2p5", &L1_SingleEG40er2p5, &b_L1_SingleEG40er2p5);
   fChain->SetBranchAddress("L1_SingleEG42er2p5", &L1_SingleEG42er2p5, &b_L1_SingleEG42er2p5);
   fChain->SetBranchAddress("L1_SingleEG45er2p5", &L1_SingleEG45er2p5, &b_L1_SingleEG45er2p5);
   fChain->SetBranchAddress("L1_SingleEG50", &L1_SingleEG50, &b_L1_SingleEG50);
   fChain->SetBranchAddress("L1_SingleEG60", &L1_SingleEG60, &b_L1_SingleEG60);
   fChain->SetBranchAddress("L1_SingleEG8er2p5", &L1_SingleEG8er2p5, &b_L1_SingleEG8er2p5);
   fChain->SetBranchAddress("L1_SingleIsoEG24er1p5", &L1_SingleIsoEG24er1p5, &b_L1_SingleIsoEG24er1p5);
   fChain->SetBranchAddress("L1_SingleIsoEG24er2p1", &L1_SingleIsoEG24er2p1, &b_L1_SingleIsoEG24er2p1);
   fChain->SetBranchAddress("L1_SingleIsoEG26er1p5", &L1_SingleIsoEG26er1p5, &b_L1_SingleIsoEG26er1p5);
   fChain->SetBranchAddress("L1_SingleIsoEG26er2p1", &L1_SingleIsoEG26er2p1, &b_L1_SingleIsoEG26er2p1);
   fChain->SetBranchAddress("L1_SingleIsoEG26er2p5", &L1_SingleIsoEG26er2p5, &b_L1_SingleIsoEG26er2p5);
   fChain->SetBranchAddress("L1_SingleIsoEG28_FWD2p5", &L1_SingleIsoEG28_FWD2p5, &b_L1_SingleIsoEG28_FWD2p5);
   fChain->SetBranchAddress("L1_SingleIsoEG28er1p5", &L1_SingleIsoEG28er1p5, &b_L1_SingleIsoEG28er1p5);
   fChain->SetBranchAddress("L1_SingleIsoEG28er2p1", &L1_SingleIsoEG28er2p1, &b_L1_SingleIsoEG28er2p1);
   fChain->SetBranchAddress("L1_SingleIsoEG28er2p5", &L1_SingleIsoEG28er2p5, &b_L1_SingleIsoEG28er2p5);
   fChain->SetBranchAddress("L1_SingleIsoEG30er2p1", &L1_SingleIsoEG30er2p1, &b_L1_SingleIsoEG30er2p1);
   fChain->SetBranchAddress("L1_SingleIsoEG30er2p5", &L1_SingleIsoEG30er2p5, &b_L1_SingleIsoEG30er2p5);
   fChain->SetBranchAddress("L1_SingleIsoEG32er2p1", &L1_SingleIsoEG32er2p1, &b_L1_SingleIsoEG32er2p1);
   fChain->SetBranchAddress("L1_SingleIsoEG32er2p5", &L1_SingleIsoEG32er2p5, &b_L1_SingleIsoEG32er2p5);
   fChain->SetBranchAddress("L1_SingleIsoEG34er2p5", &L1_SingleIsoEG34er2p5, &b_L1_SingleIsoEG34er2p5);
   fChain->SetBranchAddress("L1_SingleJet10erHE", &L1_SingleJet10erHE, &b_L1_SingleJet10erHE);
   fChain->SetBranchAddress("L1_SingleJet120", &L1_SingleJet120, &b_L1_SingleJet120);
   fChain->SetBranchAddress("L1_SingleJet120_FWD3p0", &L1_SingleJet120_FWD3p0, &b_L1_SingleJet120_FWD3p0);
   fChain->SetBranchAddress("L1_SingleJet120er2p5", &L1_SingleJet120er2p5, &b_L1_SingleJet120er2p5);
   fChain->SetBranchAddress("L1_SingleJet12erHE", &L1_SingleJet12erHE, &b_L1_SingleJet12erHE);
   fChain->SetBranchAddress("L1_SingleJet140er2p5", &L1_SingleJet140er2p5, &b_L1_SingleJet140er2p5);
   fChain->SetBranchAddress("L1_SingleJet140er2p5_ETMHF70", &L1_SingleJet140er2p5_ETMHF70, &b_L1_SingleJet140er2p5_ETMHF70);
   fChain->SetBranchAddress("L1_SingleJet140er2p5_ETMHF80", &L1_SingleJet140er2p5_ETMHF80, &b_L1_SingleJet140er2p5_ETMHF80);
   fChain->SetBranchAddress("L1_SingleJet140er2p5_ETMHF90", &L1_SingleJet140er2p5_ETMHF90, &b_L1_SingleJet140er2p5_ETMHF90);
   fChain->SetBranchAddress("L1_SingleJet160er2p5", &L1_SingleJet160er2p5, &b_L1_SingleJet160er2p5);
   fChain->SetBranchAddress("L1_SingleJet180", &L1_SingleJet180, &b_L1_SingleJet180);
   fChain->SetBranchAddress("L1_SingleJet180er2p5", &L1_SingleJet180er2p5, &b_L1_SingleJet180er2p5);
   fChain->SetBranchAddress("L1_SingleJet200", &L1_SingleJet200, &b_L1_SingleJet200);
   fChain->SetBranchAddress("L1_SingleJet20er2p5_NotBptxOR", &L1_SingleJet20er2p5_NotBptxOR, &b_L1_SingleJet20er2p5_NotBptxOR);
   fChain->SetBranchAddress("L1_SingleJet20er2p5_NotBptxOR_3BX", &L1_SingleJet20er2p5_NotBptxOR_3BX, &b_L1_SingleJet20er2p5_NotBptxOR_3BX);
   fChain->SetBranchAddress("L1_SingleJet35", &L1_SingleJet35, &b_L1_SingleJet35);
   fChain->SetBranchAddress("L1_SingleJet35_FWD3p0", &L1_SingleJet35_FWD3p0, &b_L1_SingleJet35_FWD3p0);
   fChain->SetBranchAddress("L1_SingleJet35er2p5", &L1_SingleJet35er2p5, &b_L1_SingleJet35er2p5);
   fChain->SetBranchAddress("L1_SingleJet43er2p5_NotBptxOR_3BX", &L1_SingleJet43er2p5_NotBptxOR_3BX, &b_L1_SingleJet43er2p5_NotBptxOR_3BX);
   fChain->SetBranchAddress("L1_SingleJet46er2p5_NotBptxOR_3BX", &L1_SingleJet46er2p5_NotBptxOR_3BX, &b_L1_SingleJet46er2p5_NotBptxOR_3BX);
   fChain->SetBranchAddress("L1_SingleJet60", &L1_SingleJet60, &b_L1_SingleJet60);
   fChain->SetBranchAddress("L1_SingleJet60_FWD3p0", &L1_SingleJet60_FWD3p0, &b_L1_SingleJet60_FWD3p0);
   fChain->SetBranchAddress("L1_SingleJet60er2p5", &L1_SingleJet60er2p5, &b_L1_SingleJet60er2p5);
   fChain->SetBranchAddress("L1_SingleJet8erHE", &L1_SingleJet8erHE, &b_L1_SingleJet8erHE);
   fChain->SetBranchAddress("L1_SingleJet90", &L1_SingleJet90, &b_L1_SingleJet90);
   fChain->SetBranchAddress("L1_SingleJet90_FWD3p0", &L1_SingleJet90_FWD3p0, &b_L1_SingleJet90_FWD3p0);
   fChain->SetBranchAddress("L1_SingleJet90er2p5", &L1_SingleJet90er2p5, &b_L1_SingleJet90er2p5);
   fChain->SetBranchAddress("L1_SingleLooseIsoEG26er1p5", &L1_SingleLooseIsoEG26er1p5, &b_L1_SingleLooseIsoEG26er1p5);
   fChain->SetBranchAddress("L1_SingleLooseIsoEG26er2p5", &L1_SingleLooseIsoEG26er2p5, &b_L1_SingleLooseIsoEG26er2p5);
   fChain->SetBranchAddress("L1_SingleLooseIsoEG28_FWD2p5", &L1_SingleLooseIsoEG28_FWD2p5, &b_L1_SingleLooseIsoEG28_FWD2p5);
   fChain->SetBranchAddress("L1_SingleLooseIsoEG28er1p5", &L1_SingleLooseIsoEG28er1p5, &b_L1_SingleLooseIsoEG28er1p5);
   fChain->SetBranchAddress("L1_SingleLooseIsoEG28er2p1", &L1_SingleLooseIsoEG28er2p1, &b_L1_SingleLooseIsoEG28er2p1);
   fChain->SetBranchAddress("L1_SingleLooseIsoEG28er2p5", &L1_SingleLooseIsoEG28er2p5, &b_L1_SingleLooseIsoEG28er2p5);
   fChain->SetBranchAddress("L1_SingleLooseIsoEG30er1p5", &L1_SingleLooseIsoEG30er1p5, &b_L1_SingleLooseIsoEG30er1p5);
   fChain->SetBranchAddress("L1_SingleLooseIsoEG30er2p5", &L1_SingleLooseIsoEG30er2p5, &b_L1_SingleLooseIsoEG30er2p5);
   fChain->SetBranchAddress("L1_SingleMu0_BMTF", &L1_SingleMu0_BMTF, &b_L1_SingleMu0_BMTF);
   fChain->SetBranchAddress("L1_SingleMu0_DQ", &L1_SingleMu0_DQ, &b_L1_SingleMu0_DQ);
   fChain->SetBranchAddress("L1_SingleMu0_EMTF", &L1_SingleMu0_EMTF, &b_L1_SingleMu0_EMTF);
   fChain->SetBranchAddress("L1_SingleMu0_OMTF", &L1_SingleMu0_OMTF, &b_L1_SingleMu0_OMTF);
   fChain->SetBranchAddress("L1_SingleMu10er1p5", &L1_SingleMu10er1p5, &b_L1_SingleMu10er1p5);
   fChain->SetBranchAddress("L1_SingleMu12_DQ_BMTF", &L1_SingleMu12_DQ_BMTF, &b_L1_SingleMu12_DQ_BMTF);
   fChain->SetBranchAddress("L1_SingleMu12_DQ_EMTF", &L1_SingleMu12_DQ_EMTF, &b_L1_SingleMu12_DQ_EMTF);
   fChain->SetBranchAddress("L1_SingleMu12_DQ_OMTF", &L1_SingleMu12_DQ_OMTF, &b_L1_SingleMu12_DQ_OMTF);
   fChain->SetBranchAddress("L1_SingleMu12er1p5", &L1_SingleMu12er1p5, &b_L1_SingleMu12er1p5);
   fChain->SetBranchAddress("L1_SingleMu14er1p5", &L1_SingleMu14er1p5, &b_L1_SingleMu14er1p5);
   fChain->SetBranchAddress("L1_SingleMu15_DQ", &L1_SingleMu15_DQ, &b_L1_SingleMu15_DQ);
   fChain->SetBranchAddress("L1_SingleMu16er1p5", &L1_SingleMu16er1p5, &b_L1_SingleMu16er1p5);
   fChain->SetBranchAddress("L1_SingleMu18", &L1_SingleMu18, &b_L1_SingleMu18);
   fChain->SetBranchAddress("L1_SingleMu18er1p5", &L1_SingleMu18er1p5, &b_L1_SingleMu18er1p5);
   fChain->SetBranchAddress("L1_SingleMu20", &L1_SingleMu20, &b_L1_SingleMu20);
   fChain->SetBranchAddress("L1_SingleMu22", &L1_SingleMu22, &b_L1_SingleMu22);
   fChain->SetBranchAddress("L1_SingleMu22_BMTF", &L1_SingleMu22_BMTF, &b_L1_SingleMu22_BMTF);
   fChain->SetBranchAddress("L1_SingleMu22_EMTF", &L1_SingleMu22_EMTF, &b_L1_SingleMu22_EMTF);
   fChain->SetBranchAddress("L1_SingleMu22_OMTF", &L1_SingleMu22_OMTF, &b_L1_SingleMu22_OMTF);
   fChain->SetBranchAddress("L1_SingleMu25", &L1_SingleMu25, &b_L1_SingleMu25);
   fChain->SetBranchAddress("L1_SingleMu3", &L1_SingleMu3, &b_L1_SingleMu3);
   fChain->SetBranchAddress("L1_SingleMu5", &L1_SingleMu5, &b_L1_SingleMu5);
   fChain->SetBranchAddress("L1_SingleMu6er1p5", &L1_SingleMu6er1p5, &b_L1_SingleMu6er1p5);
   fChain->SetBranchAddress("L1_SingleMu7", &L1_SingleMu7, &b_L1_SingleMu7);
   fChain->SetBranchAddress("L1_SingleMu7_DQ", &L1_SingleMu7_DQ, &b_L1_SingleMu7_DQ);
   fChain->SetBranchAddress("L1_SingleMu7er1p5", &L1_SingleMu7er1p5, &b_L1_SingleMu7er1p5);
   fChain->SetBranchAddress("L1_SingleMu8er1p5", &L1_SingleMu8er1p5, &b_L1_SingleMu8er1p5);
   fChain->SetBranchAddress("L1_SingleMu9er1p5", &L1_SingleMu9er1p5, &b_L1_SingleMu9er1p5);
   fChain->SetBranchAddress("L1_SingleMuCosmics", &L1_SingleMuCosmics, &b_L1_SingleMuCosmics);
   fChain->SetBranchAddress("L1_SingleMuCosmics_BMTF", &L1_SingleMuCosmics_BMTF, &b_L1_SingleMuCosmics_BMTF);
   fChain->SetBranchAddress("L1_SingleMuCosmics_EMTF", &L1_SingleMuCosmics_EMTF, &b_L1_SingleMuCosmics_EMTF);
   fChain->SetBranchAddress("L1_SingleMuCosmics_OMTF", &L1_SingleMuCosmics_OMTF, &b_L1_SingleMuCosmics_OMTF);
   fChain->SetBranchAddress("L1_SingleMuOpen", &L1_SingleMuOpen, &b_L1_SingleMuOpen);
   fChain->SetBranchAddress("L1_SingleMuOpen_NotBptxOR", &L1_SingleMuOpen_NotBptxOR, &b_L1_SingleMuOpen_NotBptxOR);
   fChain->SetBranchAddress("L1_SingleMuOpen_er1p1_NotBptxOR_3BX", &L1_SingleMuOpen_er1p1_NotBptxOR_3BX, &b_L1_SingleMuOpen_er1p1_NotBptxOR_3BX);
   fChain->SetBranchAddress("L1_SingleMuOpen_er1p4_NotBptxOR_3BX", &L1_SingleMuOpen_er1p4_NotBptxOR_3BX, &b_L1_SingleMuOpen_er1p4_NotBptxOR_3BX);
   fChain->SetBranchAddress("L1_SingleTau120er2p1", &L1_SingleTau120er2p1, &b_L1_SingleTau120er2p1);
   fChain->SetBranchAddress("L1_SingleTau130er2p1", &L1_SingleTau130er2p1, &b_L1_SingleTau130er2p1);
   fChain->SetBranchAddress("L1_TOTEM_1", &L1_TOTEM_1, &b_L1_TOTEM_1);
   fChain->SetBranchAddress("L1_TOTEM_2", &L1_TOTEM_2, &b_L1_TOTEM_2);
   fChain->SetBranchAddress("L1_TOTEM_3", &L1_TOTEM_3, &b_L1_TOTEM_3);
   fChain->SetBranchAddress("L1_TOTEM_4", &L1_TOTEM_4, &b_L1_TOTEM_4);
   fChain->SetBranchAddress("L1_TripleEG16er2p5", &L1_TripleEG16er2p5, &b_L1_TripleEG16er2p5);
   fChain->SetBranchAddress("L1_TripleEG_16_12_8_er2p5", &L1_TripleEG_16_12_8_er2p5, &b_L1_TripleEG_16_12_8_er2p5);
   fChain->SetBranchAddress("L1_TripleEG_16_15_8_er2p5", &L1_TripleEG_16_15_8_er2p5, &b_L1_TripleEG_16_15_8_er2p5);
   fChain->SetBranchAddress("L1_TripleEG_18_17_8_er2p5", &L1_TripleEG_18_17_8_er2p5, &b_L1_TripleEG_18_17_8_er2p5);
   fChain->SetBranchAddress("L1_TripleEG_18_18_12_er2p5", &L1_TripleEG_18_18_12_er2p5, &b_L1_TripleEG_18_18_12_er2p5);
   fChain->SetBranchAddress("L1_TripleJet_100_80_70_DoubleJet_80_70_er2p5", &L1_TripleJet_100_80_70_DoubleJet_80_70_er2p5, &b_L1_TripleJet_100_80_70_DoubleJet_80_70_er2p5);
   fChain->SetBranchAddress("L1_TripleJet_105_85_75_DoubleJet_85_75_er2p5", &L1_TripleJet_105_85_75_DoubleJet_85_75_er2p5, &b_L1_TripleJet_105_85_75_DoubleJet_85_75_er2p5);
   fChain->SetBranchAddress("L1_TripleJet_95_75_65_DoubleJet_75_65_er2p5", &L1_TripleJet_95_75_65_DoubleJet_75_65_er2p5, &b_L1_TripleJet_95_75_65_DoubleJet_75_65_er2p5);
   fChain->SetBranchAddress("L1_TripleMu0", &L1_TripleMu0, &b_L1_TripleMu0);
   fChain->SetBranchAddress("L1_TripleMu0_OQ", &L1_TripleMu0_OQ, &b_L1_TripleMu0_OQ);
   fChain->SetBranchAddress("L1_TripleMu0_SQ", &L1_TripleMu0_SQ, &b_L1_TripleMu0_SQ);
   fChain->SetBranchAddress("L1_TripleMu3", &L1_TripleMu3, &b_L1_TripleMu3);
   fChain->SetBranchAddress("L1_TripleMu3_SQ", &L1_TripleMu3_SQ, &b_L1_TripleMu3_SQ);
   fChain->SetBranchAddress("L1_TripleMu_5SQ_3SQ_0OQ", &L1_TripleMu_5SQ_3SQ_0OQ, &b_L1_TripleMu_5SQ_3SQ_0OQ);
   fChain->SetBranchAddress("L1_TripleMu_5SQ_3SQ_0OQ_DoubleMu_5_3_SQ_OS_Mass_Max9", &L1_TripleMu_5SQ_3SQ_0OQ_DoubleMu_5_3_SQ_OS_Mass_Max9, &b_L1_TripleMu_5SQ_3SQ_0OQ_DoubleMu_5_3_SQ_OS_Mass_Max9);
   fChain->SetBranchAddress("L1_TripleMu_5SQ_3SQ_0_DoubleMu_5_3_SQ_OS_Mass_Max9", &L1_TripleMu_5SQ_3SQ_0_DoubleMu_5_3_SQ_OS_Mass_Max9, &b_L1_TripleMu_5SQ_3SQ_0_DoubleMu_5_3_SQ_OS_Mass_Max9);
   fChain->SetBranchAddress("L1_TripleMu_5_3_3", &L1_TripleMu_5_3_3, &b_L1_TripleMu_5_3_3);
   fChain->SetBranchAddress("L1_TripleMu_5_3_3_SQ", &L1_TripleMu_5_3_3_SQ, &b_L1_TripleMu_5_3_3_SQ);
   fChain->SetBranchAddress("L1_TripleMu_5_3p5_2p5", &L1_TripleMu_5_3p5_2p5, &b_L1_TripleMu_5_3p5_2p5);
   fChain->SetBranchAddress("L1_TripleMu_5_3p5_2p5_DoubleMu_5_2p5_OS_Mass_5to17", &L1_TripleMu_5_3p5_2p5_DoubleMu_5_2p5_OS_Mass_5to17, &b_L1_TripleMu_5_3p5_2p5_DoubleMu_5_2p5_OS_Mass_5to17);
   fChain->SetBranchAddress("L1_TripleMu_5_3p5_2p5_OQ_DoubleMu_5_2p5_OQ_OS_Mass_5to17", &L1_TripleMu_5_3p5_2p5_OQ_DoubleMu_5_2p5_OQ_OS_Mass_5to17, &b_L1_TripleMu_5_3p5_2p5_OQ_DoubleMu_5_2p5_OQ_OS_Mass_5to17);
   fChain->SetBranchAddress("L1_TripleMu_5_4_2p5_DoubleMu_5_2p5_OS_Mass_5to17", &L1_TripleMu_5_4_2p5_DoubleMu_5_2p5_OS_Mass_5to17, &b_L1_TripleMu_5_4_2p5_DoubleMu_5_2p5_OS_Mass_5to17);
   fChain->SetBranchAddress("L1_TripleMu_5_5_3", &L1_TripleMu_5_5_3, &b_L1_TripleMu_5_5_3);
   fChain->SetBranchAddress("L1_UnpairedBunchBptxMinus", &L1_UnpairedBunchBptxMinus, &b_L1_UnpairedBunchBptxMinus);
   fChain->SetBranchAddress("L1_UnpairedBunchBptxPlus", &L1_UnpairedBunchBptxPlus, &b_L1_UnpairedBunchBptxPlus);
   fChain->SetBranchAddress("L1_ZeroBias", &L1_ZeroBias, &b_L1_ZeroBias);
   fChain->SetBranchAddress("L1_ZeroBias_copy", &L1_ZeroBias_copy, &b_L1_ZeroBias_copy);
   fChain->SetBranchAddress("L1_UnprefireableEvent", &L1_UnprefireableEvent, &b_L1_UnprefireableEvent);
   */
   // fChain->SetBranchAddress("Flag_HBHENoiseFilter", &Flag_HBHENoiseFilter, &b_Flag_HBHENoiseFilter);
   // fChain->SetBranchAddress("Flag_HBHENoiseIsoFilter", &Flag_HBHENoiseIsoFilter, &b_Flag_HBHENoiseIsoFilter);
   // fChain->SetBranchAddress("Flag_CSCTightHaloFilter", &Flag_CSCTightHaloFilter, &b_Flag_CSCTightHaloFilter);
   // fChain->SetBranchAddress("Flag_CSCTightHaloTrkMuUnvetoFilter", &Flag_CSCTightHaloTrkMuUnvetoFilter, &b_Flag_CSCTightHaloTrkMuUnvetoFilter);
   // fChain->SetBranchAddress("Flag_CSCTightHalo2015Filter", &Flag_CSCTightHalo2015Filter, &b_Flag_CSCTightHalo2015Filter);
   // fChain->SetBranchAddress("Flag_globalTightHalo2016Filter", &Flag_globalTightHalo2016Filter, &b_Flag_globalTightHalo2016Filter);
   fChain->SetBranchAddress("Flag_globalSuperTightHalo2016Filter", &Flag_globalSuperTightHalo2016Filter, &b_Flag_globalSuperTightHalo2016Filter);
   // fChain->SetBranchAddress("Flag_HcalStripHaloFilter", &Flag_HcalStripHaloFilter, &b_Flag_HcalStripHaloFilter);
   // fChain->SetBranchAddress("Flag_hcalLaserEventFilter", &Flag_hcalLaserEventFilter, &b_Flag_hcalLaserEventFilter);
   fChain->SetBranchAddress("Flag_EcalDeadCellTriggerPrimitiveFilter", &Flag_EcalDeadCellTriggerPrimitiveFilter, &b_Flag_EcalDeadCellTriggerPrimitiveFilter);
   // fChain->SetBranchAddress("Flag_EcalDeadCellBoundaryEnergyFilter", &Flag_EcalDeadCellBoundaryEnergyFilter, &b_Flag_EcalDeadCellBoundaryEnergyFilter);
   fChain->SetBranchAddress("Flag_ecalBadCalibFilter", &Flag_ecalBadCalibFilter, &b_Flag_ecalBadCalibFilter);
   fChain->SetBranchAddress("Flag_goodVertices", &Flag_goodVertices, &b_Flag_goodVertices);
   fChain->SetBranchAddress("Flag_eeBadScFilter", &Flag_eeBadScFilter, &b_Flag_eeBadScFilter);
   // fChain->SetBranchAddress("Flag_ecalLaserCorrFilter", &Flag_ecalLaserCorrFilter, &b_Flag_ecalLaserCorrFilter);
   // fChain->SetBranchAddress("Flag_trkPOGFilters", &Flag_trkPOGFilters, &b_Flag_trkPOGFilters);
   // fChain->SetBranchAddress("Flag_chargedHadronTrackResolutionFilter", &Flag_chargedHadronTrackResolutionFilter, &b_Flag_chargedHadronTrackResolutionFilter);
   // fChain->SetBranchAddress("Flag_muonBadTrackFilter", &Flag_muonBadTrackFilter, &b_Flag_muonBadTrackFilter);
   // fChain->SetBranchAddress("Flag_BadChargedCandidateFilter", &Flag_BadChargedCandidateFilter, &b_Flag_BadChargedCandidateFilter);
   fChain->SetBranchAddress("Flag_BadPFMuonFilter", &Flag_BadPFMuonFilter, &b_Flag_BadPFMuonFilter);
   fChain->SetBranchAddress("Flag_BadPFMuonDzFilter", &Flag_BadPFMuonDzFilter, &b_Flag_BadPFMuonDzFilter);
   fChain->SetBranchAddress("Flag_hfNoisyHitsFilter", &Flag_hfNoisyHitsFilter, &b_Flag_hfNoisyHitsFilter);
   // fChain->SetBranchAddress("Flag_BadChargedCandidateSummer16Filter", &Flag_BadChargedCandidateSummer16Filter, &b_Flag_BadChargedCandidateSummer16Filter);
   // fChain->SetBranchAddress("Flag_BadPFMuonSummer16Filter", &Flag_BadPFMuonSummer16Filter, &b_Flag_BadPFMuonSummer16Filter);
   // fChain->SetBranchAddress("Flag_trkPOG_manystripclus53X", &Flag_trkPOG_manystripclus53X, &b_Flag_trkPOG_manystripclus53X);
   // fChain->SetBranchAddress("Flag_trkPOG_toomanystripclus53X", &Flag_trkPOG_toomanystripclus53X, &b_Flag_trkPOG_toomanystripclus53X);
   // fChain->SetBranchAddress("Flag_trkPOG_logErrorTooManyClusters", &Flag_trkPOG_logErrorTooManyClusters, &b_Flag_trkPOG_logErrorTooManyClusters);
   fChain->SetBranchAddress("Flag_METFilters", &Flag_METFilters, &b_Flag_METFilters);
   /*
   fChain->SetBranchAddress("L1Reco_step", &L1Reco_step, &b_L1Reco_step);
   fChain->SetBranchAddress("L1simulation_step", &L1simulation_step, &b_L1simulation_step);
   fChain->SetBranchAddress("HLTriggerFirstPath", &HLTriggerFirstPath, &b_HLTriggerFirstPath);
   fChain->SetBranchAddress("HLT_AK8PFJet360_TrimMass30", &HLT_AK8PFJet360_TrimMass30, &b_HLT_AK8PFJet360_TrimMass30);
   fChain->SetBranchAddress("HLT_AK8PFJet380_TrimMass30", &HLT_AK8PFJet380_TrimMass30, &b_HLT_AK8PFJet380_TrimMass30);
   fChain->SetBranchAddress("HLT_AK8PFJet400_TrimMass30", &HLT_AK8PFJet400_TrimMass30, &b_HLT_AK8PFJet400_TrimMass30);
   fChain->SetBranchAddress("HLT_AK8PFJet420_TrimMass30", &HLT_AK8PFJet420_TrimMass30, &b_HLT_AK8PFJet420_TrimMass30);
   fChain->SetBranchAddress("HLT_AK8PFHT750_TrimMass50", &HLT_AK8PFHT750_TrimMass50, &b_HLT_AK8PFHT750_TrimMass50);
   fChain->SetBranchAddress("HLT_AK8PFHT800_TrimMass50", &HLT_AK8PFHT800_TrimMass50, &b_HLT_AK8PFHT800_TrimMass50);
   fChain->SetBranchAddress("HLT_AK8PFHT850_TrimMass50", &HLT_AK8PFHT850_TrimMass50, &b_HLT_AK8PFHT850_TrimMass50);
   fChain->SetBranchAddress("HLT_AK8PFHT900_TrimMass50", &HLT_AK8PFHT900_TrimMass50, &b_HLT_AK8PFHT900_TrimMass50);
   fChain->SetBranchAddress("HLT_CaloJet500_NoJetID", &HLT_CaloJet500_NoJetID, &b_HLT_CaloJet500_NoJetID);
   fChain->SetBranchAddress("HLT_CaloJet550_NoJetID", &HLT_CaloJet550_NoJetID, &b_HLT_CaloJet550_NoJetID);
   fChain->SetBranchAddress("HLT_DoubleMu5_Upsilon_DoubleEle3_CaloIdL_TrackIdL", &HLT_DoubleMu5_Upsilon_DoubleEle3_CaloIdL_TrackIdL, &b_HLT_DoubleMu5_Upsilon_DoubleEle3_CaloIdL_TrackIdL);
   fChain->SetBranchAddress("HLT_DoubleMu3_DoubleEle7p5_CaloIdL_TrackIdL_Upsilon", &HLT_DoubleMu3_DoubleEle7p5_CaloIdL_TrackIdL_Upsilon, &b_HLT_DoubleMu3_DoubleEle7p5_CaloIdL_TrackIdL_Upsilon);
   fChain->SetBranchAddress("HLT_Trimuon5_3p5_2_Upsilon_Muon", &HLT_Trimuon5_3p5_2_Upsilon_Muon, &b_HLT_Trimuon5_3p5_2_Upsilon_Muon);
   fChain->SetBranchAddress("HLT_TrimuonOpen_5_3p5_2_Upsilon_Muon", &HLT_TrimuonOpen_5_3p5_2_Upsilon_Muon, &b_HLT_TrimuonOpen_5_3p5_2_Upsilon_Muon);
   fChain->SetBranchAddress("HLT_DoubleEle25_CaloIdL_MW", &HLT_DoubleEle25_CaloIdL_MW, &b_HLT_DoubleEle25_CaloIdL_MW);
   fChain->SetBranchAddress("HLT_DoubleEle27_CaloIdL_MW", &HLT_DoubleEle27_CaloIdL_MW, &b_HLT_DoubleEle27_CaloIdL_MW);
   fChain->SetBranchAddress("HLT_DoubleEle33_CaloIdL_MW", &HLT_DoubleEle33_CaloIdL_MW, &b_HLT_DoubleEle33_CaloIdL_MW);
   fChain->SetBranchAddress("HLT_DoubleEle24_eta2p1_WPTight_Gsf", &HLT_DoubleEle24_eta2p1_WPTight_Gsf, &b_HLT_DoubleEle24_eta2p1_WPTight_Gsf);
   fChain->SetBranchAddress("HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_DZ_PFHT350", &HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_DZ_PFHT350, &b_HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_DZ_PFHT350);
   fChain->SetBranchAddress("HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_PFHT350", &HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_PFHT350, &b_HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_PFHT350);
   fChain->SetBranchAddress("HLT_Ele27_Ele37_CaloIdL_MW", &HLT_Ele27_Ele37_CaloIdL_MW, &b_HLT_Ele27_Ele37_CaloIdL_MW);
   fChain->SetBranchAddress("HLT_Mu27_Ele37_CaloIdL_MW", &HLT_Mu27_Ele37_CaloIdL_MW, &b_HLT_Mu27_Ele37_CaloIdL_MW);
   fChain->SetBranchAddress("HLT_Mu37_Ele27_CaloIdL_MW", &HLT_Mu37_Ele27_CaloIdL_MW, &b_HLT_Mu37_Ele27_CaloIdL_MW);
   fChain->SetBranchAddress("HLT_Mu37_TkMu27", &HLT_Mu37_TkMu27, &b_HLT_Mu37_TkMu27);
   fChain->SetBranchAddress("HLT_DoubleMu4_3_Bs", &HLT_DoubleMu4_3_Bs, &b_HLT_DoubleMu4_3_Bs);
   fChain->SetBranchAddress("HLT_DoubleMu4_3_Jpsi", &HLT_DoubleMu4_3_Jpsi, &b_HLT_DoubleMu4_3_Jpsi);
   fChain->SetBranchAddress("HLT_DoubleMu4_JpsiTrk_Displaced", &HLT_DoubleMu4_JpsiTrk_Displaced, &b_HLT_DoubleMu4_JpsiTrk_Displaced);
   fChain->SetBranchAddress("HLT_DoubleMu4_LowMassNonResonantTrk_Displaced", &HLT_DoubleMu4_LowMassNonResonantTrk_Displaced, &b_HLT_DoubleMu4_LowMassNonResonantTrk_Displaced);
   fChain->SetBranchAddress("HLT_DoubleMu3_Trk_Tau3mu", &HLT_DoubleMu3_Trk_Tau3mu, &b_HLT_DoubleMu3_Trk_Tau3mu);
   fChain->SetBranchAddress("HLT_DoubleMu3_TkMu_DsTau3Mu", &HLT_DoubleMu3_TkMu_DsTau3Mu, &b_HLT_DoubleMu3_TkMu_DsTau3Mu);
   fChain->SetBranchAddress("HLT_DoubleMu4_PsiPrimeTrk_Displaced", &HLT_DoubleMu4_PsiPrimeTrk_Displaced, &b_HLT_DoubleMu4_PsiPrimeTrk_Displaced);
   fChain->SetBranchAddress("HLT_DoubleMu4_Mass3p8_DZ_PFHT350", &HLT_DoubleMu4_Mass3p8_DZ_PFHT350, &b_HLT_DoubleMu4_Mass3p8_DZ_PFHT350);
   fChain->SetBranchAddress("HLT_Mu3_PFJet40", &HLT_Mu3_PFJet40, &b_HLT_Mu3_PFJet40);
   fChain->SetBranchAddress("HLT_Mu7p5_L2Mu2_Jpsi", &HLT_Mu7p5_L2Mu2_Jpsi, &b_HLT_Mu7p5_L2Mu2_Jpsi);
   fChain->SetBranchAddress("HLT_Mu7p5_L2Mu2_Upsilon", &HLT_Mu7p5_L2Mu2_Upsilon, &b_HLT_Mu7p5_L2Mu2_Upsilon);
   fChain->SetBranchAddress("HLT_Mu7p5_Track2_Jpsi", &HLT_Mu7p5_Track2_Jpsi, &b_HLT_Mu7p5_Track2_Jpsi);
   fChain->SetBranchAddress("HLT_Mu7p5_Track3p5_Jpsi", &HLT_Mu7p5_Track3p5_Jpsi, &b_HLT_Mu7p5_Track3p5_Jpsi);
   fChain->SetBranchAddress("HLT_Mu7p5_Track7_Jpsi", &HLT_Mu7p5_Track7_Jpsi, &b_HLT_Mu7p5_Track7_Jpsi);
   fChain->SetBranchAddress("HLT_Mu7p5_Track2_Upsilon", &HLT_Mu7p5_Track2_Upsilon, &b_HLT_Mu7p5_Track2_Upsilon);
   fChain->SetBranchAddress("HLT_Mu7p5_Track3p5_Upsilon", &HLT_Mu7p5_Track3p5_Upsilon, &b_HLT_Mu7p5_Track3p5_Upsilon);
   fChain->SetBranchAddress("HLT_Mu7p5_Track7_Upsilon", &HLT_Mu7p5_Track7_Upsilon, &b_HLT_Mu7p5_Track7_Upsilon);
   fChain->SetBranchAddress("HLT_Mu3_L1SingleMu5orSingleMu7", &HLT_Mu3_L1SingleMu5orSingleMu7, &b_HLT_Mu3_L1SingleMu5orSingleMu7);
   fChain->SetBranchAddress("HLT_DoublePhoton33_CaloIdL", &HLT_DoublePhoton33_CaloIdL, &b_HLT_DoublePhoton33_CaloIdL);
   fChain->SetBranchAddress("HLT_DoublePhoton70", &HLT_DoublePhoton70, &b_HLT_DoublePhoton70);
   fChain->SetBranchAddress("HLT_DoublePhoton85", &HLT_DoublePhoton85, &b_HLT_DoublePhoton85);
   fChain->SetBranchAddress("HLT_Ele20_WPTight_Gsf", &HLT_Ele20_WPTight_Gsf, &b_HLT_Ele20_WPTight_Gsf);
   fChain->SetBranchAddress("HLT_Ele15_WPLoose_Gsf", &HLT_Ele15_WPLoose_Gsf, &b_HLT_Ele15_WPLoose_Gsf);
   fChain->SetBranchAddress("HLT_Ele17_WPLoose_Gsf", &HLT_Ele17_WPLoose_Gsf, &b_HLT_Ele17_WPLoose_Gsf);
   fChain->SetBranchAddress("HLT_Ele20_WPLoose_Gsf", &HLT_Ele20_WPLoose_Gsf, &b_HLT_Ele20_WPLoose_Gsf);
   fChain->SetBranchAddress("HLT_Ele20_eta2p1_WPLoose_Gsf", &HLT_Ele20_eta2p1_WPLoose_Gsf, &b_HLT_Ele20_eta2p1_WPLoose_Gsf);
   fChain->SetBranchAddress("HLT_DiEle27_WPTightCaloOnly_L1DoubleEG", &HLT_DiEle27_WPTightCaloOnly_L1DoubleEG, &b_HLT_DiEle27_WPTightCaloOnly_L1DoubleEG);
   fChain->SetBranchAddress("HLT_Ele27_WPTight_Gsf", &HLT_Ele27_WPTight_Gsf, &b_HLT_Ele27_WPTight_Gsf);
   fChain->SetBranchAddress("HLT_Ele28_WPTight_Gsf", &HLT_Ele28_WPTight_Gsf, &b_HLT_Ele28_WPTight_Gsf);
   fChain->SetBranchAddress("HLT_Ele30_WPTight_Gsf", &HLT_Ele30_WPTight_Gsf, &b_HLT_Ele30_WPTight_Gsf);
   fChain->SetBranchAddress("HLT_Ele32_WPTight_Gsf", &HLT_Ele32_WPTight_Gsf, &b_HLT_Ele32_WPTight_Gsf);
   fChain->SetBranchAddress("HLT_Ele35_WPTight_Gsf", &HLT_Ele35_WPTight_Gsf, &b_HLT_Ele35_WPTight_Gsf);
   fChain->SetBranchAddress("HLT_Ele35_WPTight_Gsf_L1EGMT", &HLT_Ele35_WPTight_Gsf_L1EGMT, &b_HLT_Ele35_WPTight_Gsf_L1EGMT);
   fChain->SetBranchAddress("HLT_Ele38_WPTight_Gsf", &HLT_Ele38_WPTight_Gsf, &b_HLT_Ele38_WPTight_Gsf);
   fChain->SetBranchAddress("HLT_Ele40_WPTight_Gsf", &HLT_Ele40_WPTight_Gsf, &b_HLT_Ele40_WPTight_Gsf);
   fChain->SetBranchAddress("HLT_Ele32_WPTight_Gsf_L1DoubleEG", &HLT_Ele32_WPTight_Gsf_L1DoubleEG, &b_HLT_Ele32_WPTight_Gsf_L1DoubleEG);
   fChain->SetBranchAddress("HLT_Ele24_eta2p1_WPTight_Gsf_LooseChargedIsoPFTau30_eta2p1_CrossL1", &HLT_Ele24_eta2p1_WPTight_Gsf_LooseChargedIsoPFTau30_eta2p1_CrossL1, &b_HLT_Ele24_eta2p1_WPTight_Gsf_LooseChargedIsoPFTau30_eta2p1_CrossL1);
   fChain->SetBranchAddress("HLT_Ele24_eta2p1_WPTight_Gsf_LooseChargedIsoPFTauHPS30_eta2p1_CrossL1", &HLT_Ele24_eta2p1_WPTight_Gsf_LooseChargedIsoPFTauHPS30_eta2p1_CrossL1, &b_HLT_Ele24_eta2p1_WPTight_Gsf_LooseChargedIsoPFTauHPS30_eta2p1_CrossL1);
   fChain->SetBranchAddress("HLT_Ele24_eta2p1_WPTight_Gsf_MediumChargedIsoPFTauHPS30_eta2p1_CrossL1", &HLT_Ele24_eta2p1_WPTight_Gsf_MediumChargedIsoPFTauHPS30_eta2p1_CrossL1, &b_HLT_Ele24_eta2p1_WPTight_Gsf_MediumChargedIsoPFTauHPS30_eta2p1_CrossL1);
   fChain->SetBranchAddress("HLT_Ele24_eta2p1_WPTight_Gsf_TightChargedIsoPFTauHPS30_eta2p1_CrossL1", &HLT_Ele24_eta2p1_WPTight_Gsf_TightChargedIsoPFTauHPS30_eta2p1_CrossL1, &b_HLT_Ele24_eta2p1_WPTight_Gsf_TightChargedIsoPFTauHPS30_eta2p1_CrossL1);
   fChain->SetBranchAddress("HLT_Ele24_eta2p1_WPTight_Gsf_LooseChargedIsoPFTauHPS30_eta2p1_TightID_CrossL1", &HLT_Ele24_eta2p1_WPTight_Gsf_LooseChargedIsoPFTauHPS30_eta2p1_TightID_CrossL1, &b_HLT_Ele24_eta2p1_WPTight_Gsf_LooseChargedIsoPFTauHPS30_eta2p1_TightID_CrossL1);
   fChain->SetBranchAddress("HLT_Ele24_eta2p1_WPTight_Gsf_MediumChargedIsoPFTauHPS30_eta2p1_TightID_CrossL1", &HLT_Ele24_eta2p1_WPTight_Gsf_MediumChargedIsoPFTauHPS30_eta2p1_TightID_CrossL1, &b_HLT_Ele24_eta2p1_WPTight_Gsf_MediumChargedIsoPFTauHPS30_eta2p1_TightID_CrossL1);
   fChain->SetBranchAddress("HLT_Ele24_eta2p1_WPTight_Gsf_TightChargedIsoPFTauHPS30_eta2p1_TightID_CrossL1", &HLT_Ele24_eta2p1_WPTight_Gsf_TightChargedIsoPFTauHPS30_eta2p1_TightID_CrossL1, &b_HLT_Ele24_eta2p1_WPTight_Gsf_TightChargedIsoPFTauHPS30_eta2p1_TightID_CrossL1);
   fChain->SetBranchAddress("HLT_HT450_Beamspot", &HLT_HT450_Beamspot, &b_HLT_HT450_Beamspot);
   fChain->SetBranchAddress("HLT_HT300_Beamspot", &HLT_HT300_Beamspot, &b_HLT_HT300_Beamspot);
   fChain->SetBranchAddress("HLT_ZeroBias_Beamspot", &HLT_ZeroBias_Beamspot, &b_HLT_ZeroBias_Beamspot);
   fChain->SetBranchAddress("HLT_IsoMu20_eta2p1_LooseChargedIsoPFTau27_eta2p1_CrossL1", &HLT_IsoMu20_eta2p1_LooseChargedIsoPFTau27_eta2p1_CrossL1, &b_HLT_IsoMu20_eta2p1_LooseChargedIsoPFTau27_eta2p1_CrossL1);
   fChain->SetBranchAddress("HLT_IsoMu20_eta2p1_LooseChargedIsoPFTauHPS27_eta2p1_CrossL1", &HLT_IsoMu20_eta2p1_LooseChargedIsoPFTauHPS27_eta2p1_CrossL1, &b_HLT_IsoMu20_eta2p1_LooseChargedIsoPFTauHPS27_eta2p1_CrossL1);
   fChain->SetBranchAddress("HLT_IsoMu20_eta2p1_MediumChargedIsoPFTauHPS27_eta2p1_CrossL1", &HLT_IsoMu20_eta2p1_MediumChargedIsoPFTauHPS27_eta2p1_CrossL1, &b_HLT_IsoMu20_eta2p1_MediumChargedIsoPFTauHPS27_eta2p1_CrossL1);
   fChain->SetBranchAddress("HLT_IsoMu20_eta2p1_TightChargedIsoPFTauHPS27_eta2p1_CrossL1", &HLT_IsoMu20_eta2p1_TightChargedIsoPFTauHPS27_eta2p1_CrossL1, &b_HLT_IsoMu20_eta2p1_TightChargedIsoPFTauHPS27_eta2p1_CrossL1);
   fChain->SetBranchAddress("HLT_IsoMu20_eta2p1_LooseChargedIsoPFTauHPS27_eta2p1_TightID_CrossL1", &HLT_IsoMu20_eta2p1_LooseChargedIsoPFTauHPS27_eta2p1_TightID_CrossL1, &b_HLT_IsoMu20_eta2p1_LooseChargedIsoPFTauHPS27_eta2p1_TightID_CrossL1);
   fChain->SetBranchAddress("HLT_IsoMu20_eta2p1_MediumChargedIsoPFTauHPS27_eta2p1_TightID_CrossL1", &HLT_IsoMu20_eta2p1_MediumChargedIsoPFTauHPS27_eta2p1_TightID_CrossL1, &b_HLT_IsoMu20_eta2p1_MediumChargedIsoPFTauHPS27_eta2p1_TightID_CrossL1);
   fChain->SetBranchAddress("HLT_IsoMu20_eta2p1_TightChargedIsoPFTauHPS27_eta2p1_TightID_CrossL1", &HLT_IsoMu20_eta2p1_TightChargedIsoPFTauHPS27_eta2p1_TightID_CrossL1, &b_HLT_IsoMu20_eta2p1_TightChargedIsoPFTauHPS27_eta2p1_TightID_CrossL1);
   fChain->SetBranchAddress("HLT_IsoMu24_eta2p1_MediumChargedIsoPFTau35_Trk1_eta2p1_Reg_CrossL1", &HLT_IsoMu24_eta2p1_MediumChargedIsoPFTau35_Trk1_eta2p1_Reg_CrossL1, &b_HLT_IsoMu24_eta2p1_MediumChargedIsoPFTau35_Trk1_eta2p1_Reg_CrossL1);
   fChain->SetBranchAddress("HLT_IsoMu24_eta2p1_MediumChargedIsoPFTau35_Trk1_TightID_eta2p1_Reg_CrossL1", &HLT_IsoMu24_eta2p1_MediumChargedIsoPFTau35_Trk1_TightID_eta2p1_Reg_CrossL1, &b_HLT_IsoMu24_eta2p1_MediumChargedIsoPFTau35_Trk1_TightID_eta2p1_Reg_CrossL1);
   fChain->SetBranchAddress("HLT_IsoMu24_eta2p1_TightChargedIsoPFTau35_Trk1_eta2p1_Reg_CrossL1", &HLT_IsoMu24_eta2p1_TightChargedIsoPFTau35_Trk1_eta2p1_Reg_CrossL1, &b_HLT_IsoMu24_eta2p1_TightChargedIsoPFTau35_Trk1_eta2p1_Reg_CrossL1);
   fChain->SetBranchAddress("HLT_IsoMu24_eta2p1_TightChargedIsoPFTau35_Trk1_TightID_eta2p1_Reg_CrossL1", &HLT_IsoMu24_eta2p1_TightChargedIsoPFTau35_Trk1_TightID_eta2p1_Reg_CrossL1, &b_HLT_IsoMu24_eta2p1_TightChargedIsoPFTau35_Trk1_TightID_eta2p1_Reg_CrossL1);
   fChain->SetBranchAddress("HLT_IsoMu24_eta2p1_TightChargedIsoPFTauHPS35_Trk1_eta2p1_Reg_CrossL1", &HLT_IsoMu24_eta2p1_TightChargedIsoPFTauHPS35_Trk1_eta2p1_Reg_CrossL1, &b_HLT_IsoMu24_eta2p1_TightChargedIsoPFTauHPS35_Trk1_eta2p1_Reg_CrossL1);
   fChain->SetBranchAddress("HLT_IsoMu24_eta2p1_MediumChargedIsoPFTauHPS35_Trk1_TightID_eta2p1_Reg_CrossL1", &HLT_IsoMu24_eta2p1_MediumChargedIsoPFTauHPS35_Trk1_TightID_eta2p1_Reg_CrossL1, &b_HLT_IsoMu24_eta2p1_MediumChargedIsoPFTauHPS35_Trk1_TightID_eta2p1_Reg_CrossL1);
   fChain->SetBranchAddress("HLT_IsoMu24_eta2p1_TightChargedIsoPFTauHPS35_Trk1_TightID_eta2p1_Reg_CrossL1", &HLT_IsoMu24_eta2p1_TightChargedIsoPFTauHPS35_Trk1_TightID_eta2p1_Reg_CrossL1, &b_HLT_IsoMu24_eta2p1_TightChargedIsoPFTauHPS35_Trk1_TightID_eta2p1_Reg_CrossL1);
   fChain->SetBranchAddress("HLT_IsoMu24_eta2p1_MediumChargedIsoPFTauHPS35_Trk1_eta2p1_Reg_CrossL1", &HLT_IsoMu24_eta2p1_MediumChargedIsoPFTauHPS35_Trk1_eta2p1_Reg_CrossL1, &b_HLT_IsoMu24_eta2p1_MediumChargedIsoPFTauHPS35_Trk1_eta2p1_Reg_CrossL1);
   fChain->SetBranchAddress("HLT_IsoMu24_eta2p1_MediumChargedIsoPFTauHPS30_Trk1_eta2p1_Reg_CrossL1", &HLT_IsoMu24_eta2p1_MediumChargedIsoPFTauHPS30_Trk1_eta2p1_Reg_CrossL1, &b_HLT_IsoMu24_eta2p1_MediumChargedIsoPFTauHPS30_Trk1_eta2p1_Reg_CrossL1);
   fChain->SetBranchAddress("HLT_IsoMu27_LooseChargedIsoPFTau20_Trk1_eta2p1_SingleL1", &HLT_IsoMu27_LooseChargedIsoPFTau20_Trk1_eta2p1_SingleL1, &b_HLT_IsoMu27_LooseChargedIsoPFTau20_Trk1_eta2p1_SingleL1);
   fChain->SetBranchAddress("HLT_IsoMu27_LooseChargedIsoPFTauHPS20_Trk1_eta2p1_SingleL1", &HLT_IsoMu27_LooseChargedIsoPFTauHPS20_Trk1_eta2p1_SingleL1, &b_HLT_IsoMu27_LooseChargedIsoPFTauHPS20_Trk1_eta2p1_SingleL1);
   fChain->SetBranchAddress("HLT_IsoMu27_MediumChargedIsoPFTauHPS20_Trk1_eta2p1_SingleL1", &HLT_IsoMu27_MediumChargedIsoPFTauHPS20_Trk1_eta2p1_SingleL1, &b_HLT_IsoMu27_MediumChargedIsoPFTauHPS20_Trk1_eta2p1_SingleL1);
   fChain->SetBranchAddress("HLT_IsoMu27_TightChargedIsoPFTauHPS20_Trk1_eta2p1_SingleL1", &HLT_IsoMu27_TightChargedIsoPFTauHPS20_Trk1_eta2p1_SingleL1, &b_HLT_IsoMu27_TightChargedIsoPFTauHPS20_Trk1_eta2p1_SingleL1);
   fChain->SetBranchAddress("HLT_IsoMu20", &HLT_IsoMu20, &b_HLT_IsoMu20);
   fChain->SetBranchAddress("HLT_IsoMu24", &HLT_IsoMu24, &b_HLT_IsoMu24);
   fChain->SetBranchAddress("HLT_IsoMu24_eta2p1", &HLT_IsoMu24_eta2p1, &b_HLT_IsoMu24_eta2p1);
   fChain->SetBranchAddress("HLT_IsoMu27", &HLT_IsoMu27, &b_HLT_IsoMu27);
   fChain->SetBranchAddress("HLT_IsoMu30", &HLT_IsoMu30, &b_HLT_IsoMu30);
   fChain->SetBranchAddress("HLT_UncorrectedJetE30_NoBPTX", &HLT_UncorrectedJetE30_NoBPTX, &b_HLT_UncorrectedJetE30_NoBPTX);
   fChain->SetBranchAddress("HLT_UncorrectedJetE30_NoBPTX3BX", &HLT_UncorrectedJetE30_NoBPTX3BX, &b_HLT_UncorrectedJetE30_NoBPTX3BX);
   fChain->SetBranchAddress("HLT_UncorrectedJetE60_NoBPTX3BX", &HLT_UncorrectedJetE60_NoBPTX3BX, &b_HLT_UncorrectedJetE60_NoBPTX3BX);
   fChain->SetBranchAddress("HLT_UncorrectedJetE70_NoBPTX3BX", &HLT_UncorrectedJetE70_NoBPTX3BX, &b_HLT_UncorrectedJetE70_NoBPTX3BX);
   fChain->SetBranchAddress("HLT_L1SingleMu18", &HLT_L1SingleMu18, &b_HLT_L1SingleMu18);
   fChain->SetBranchAddress("HLT_L1SingleMu25", &HLT_L1SingleMu25, &b_HLT_L1SingleMu25);
   fChain->SetBranchAddress("HLT_L1SingleMuCosmics", &HLT_L1SingleMuCosmics, &b_HLT_L1SingleMuCosmics);
   fChain->SetBranchAddress("HLT_L2Mu10", &HLT_L2Mu10, &b_HLT_L2Mu10);
   fChain->SetBranchAddress("HLT_L2Mu10_NoVertex_NoBPTX3BX", &HLT_L2Mu10_NoVertex_NoBPTX3BX, &b_HLT_L2Mu10_NoVertex_NoBPTX3BX);
   fChain->SetBranchAddress("HLT_L2Mu10_NoVertex_NoBPTX", &HLT_L2Mu10_NoVertex_NoBPTX, &b_HLT_L2Mu10_NoVertex_NoBPTX);
   fChain->SetBranchAddress("HLT_L2Mu45_NoVertex_3Sta_NoBPTX3BX", &HLT_L2Mu45_NoVertex_3Sta_NoBPTX3BX, &b_HLT_L2Mu45_NoVertex_3Sta_NoBPTX3BX);
   fChain->SetBranchAddress("HLT_L2Mu40_NoVertex_3Sta_NoBPTX3BX", &HLT_L2Mu40_NoVertex_3Sta_NoBPTX3BX, &b_HLT_L2Mu40_NoVertex_3Sta_NoBPTX3BX);
   fChain->SetBranchAddress("HLT_L2Mu50", &HLT_L2Mu50, &b_HLT_L2Mu50);
   fChain->SetBranchAddress("HLT_L2Mu23NoVtx_2Cha", &HLT_L2Mu23NoVtx_2Cha, &b_HLT_L2Mu23NoVtx_2Cha);
   fChain->SetBranchAddress("HLT_L2Mu23NoVtx_2Cha_CosmicSeed", &HLT_L2Mu23NoVtx_2Cha_CosmicSeed, &b_HLT_L2Mu23NoVtx_2Cha_CosmicSeed);
   fChain->SetBranchAddress("HLT_DoubleL2Mu30NoVtx_2Cha_CosmicSeed_Eta2p4", &HLT_DoubleL2Mu30NoVtx_2Cha_CosmicSeed_Eta2p4, &b_HLT_DoubleL2Mu30NoVtx_2Cha_CosmicSeed_Eta2p4);
   fChain->SetBranchAddress("HLT_DoubleL2Mu30NoVtx_2Cha_Eta2p4", &HLT_DoubleL2Mu30NoVtx_2Cha_Eta2p4, &b_HLT_DoubleL2Mu30NoVtx_2Cha_Eta2p4);
   fChain->SetBranchAddress("HLT_DoubleL2Mu50", &HLT_DoubleL2Mu50, &b_HLT_DoubleL2Mu50);
   fChain->SetBranchAddress("HLT_DoubleL2Mu23NoVtx_2Cha_CosmicSeed", &HLT_DoubleL2Mu23NoVtx_2Cha_CosmicSeed, &b_HLT_DoubleL2Mu23NoVtx_2Cha_CosmicSeed);
   fChain->SetBranchAddress("HLT_DoubleL2Mu23NoVtx_2Cha_CosmicSeed_NoL2Matched", &HLT_DoubleL2Mu23NoVtx_2Cha_CosmicSeed_NoL2Matched, &b_HLT_DoubleL2Mu23NoVtx_2Cha_CosmicSeed_NoL2Matched);
   fChain->SetBranchAddress("HLT_DoubleL2Mu25NoVtx_2Cha_CosmicSeed", &HLT_DoubleL2Mu25NoVtx_2Cha_CosmicSeed, &b_HLT_DoubleL2Mu25NoVtx_2Cha_CosmicSeed);
   fChain->SetBranchAddress("HLT_DoubleL2Mu25NoVtx_2Cha_CosmicSeed_NoL2Matched", &HLT_DoubleL2Mu25NoVtx_2Cha_CosmicSeed_NoL2Matched, &b_HLT_DoubleL2Mu25NoVtx_2Cha_CosmicSeed_NoL2Matched);
   fChain->SetBranchAddress("HLT_DoubleL2Mu25NoVtx_2Cha_CosmicSeed_Eta2p4", &HLT_DoubleL2Mu25NoVtx_2Cha_CosmicSeed_Eta2p4, &b_HLT_DoubleL2Mu25NoVtx_2Cha_CosmicSeed_Eta2p4);
   fChain->SetBranchAddress("HLT_DoubleL2Mu23NoVtx_2Cha", &HLT_DoubleL2Mu23NoVtx_2Cha, &b_HLT_DoubleL2Mu23NoVtx_2Cha);
   fChain->SetBranchAddress("HLT_DoubleL2Mu23NoVtx_2Cha_NoL2Matched", &HLT_DoubleL2Mu23NoVtx_2Cha_NoL2Matched, &b_HLT_DoubleL2Mu23NoVtx_2Cha_NoL2Matched);
   fChain->SetBranchAddress("HLT_DoubleL2Mu25NoVtx_2Cha", &HLT_DoubleL2Mu25NoVtx_2Cha, &b_HLT_DoubleL2Mu25NoVtx_2Cha);
   fChain->SetBranchAddress("HLT_DoubleL2Mu25NoVtx_2Cha_NoL2Matched", &HLT_DoubleL2Mu25NoVtx_2Cha_NoL2Matched, &b_HLT_DoubleL2Mu25NoVtx_2Cha_NoL2Matched);
   fChain->SetBranchAddress("HLT_DoubleL2Mu25NoVtx_2Cha_Eta2p4", &HLT_DoubleL2Mu25NoVtx_2Cha_Eta2p4, &b_HLT_DoubleL2Mu25NoVtx_2Cha_Eta2p4);
   fChain->SetBranchAddress("HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL", &HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL, &b_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL);
   fChain->SetBranchAddress("HLT_Mu19_TrkIsoVVL_Mu9_TrkIsoVVL", &HLT_Mu19_TrkIsoVVL_Mu9_TrkIsoVVL, &b_HLT_Mu19_TrkIsoVVL_Mu9_TrkIsoVVL);
   fChain->SetBranchAddress("HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ", &HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ, &b_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ);
   fChain->SetBranchAddress("HLT_Mu19_TrkIsoVVL_Mu9_TrkIsoVVL_DZ", &HLT_Mu19_TrkIsoVVL_Mu9_TrkIsoVVL_DZ, &b_HLT_Mu19_TrkIsoVVL_Mu9_TrkIsoVVL_DZ);
   fChain->SetBranchAddress("HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass8", &HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass8, &b_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass8);
   fChain->SetBranchAddress("HLT_Mu19_TrkIsoVVL_Mu9_TrkIsoVVL_DZ_Mass8", &HLT_Mu19_TrkIsoVVL_Mu9_TrkIsoVVL_DZ_Mass8, &b_HLT_Mu19_TrkIsoVVL_Mu9_TrkIsoVVL_DZ_Mass8);
   fChain->SetBranchAddress("HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8", &HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8, &b_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8);
   fChain->SetBranchAddress("HLT_Mu19_TrkIsoVVL_Mu9_TrkIsoVVL_DZ_Mass3p8", &HLT_Mu19_TrkIsoVVL_Mu9_TrkIsoVVL_DZ_Mass3p8, &b_HLT_Mu19_TrkIsoVVL_Mu9_TrkIsoVVL_DZ_Mass3p8);
   fChain->SetBranchAddress("HLT_Mu25_TkMu0_Onia", &HLT_Mu25_TkMu0_Onia, &b_HLT_Mu25_TkMu0_Onia);
   fChain->SetBranchAddress("HLT_Mu30_TkMu0_Psi", &HLT_Mu30_TkMu0_Psi, &b_HLT_Mu30_TkMu0_Psi);
   fChain->SetBranchAddress("HLT_Mu30_TkMu0_Upsilon", &HLT_Mu30_TkMu0_Upsilon, &b_HLT_Mu30_TkMu0_Upsilon);
   fChain->SetBranchAddress("HLT_Mu20_TkMu0_Phi", &HLT_Mu20_TkMu0_Phi, &b_HLT_Mu20_TkMu0_Phi);
   fChain->SetBranchAddress("HLT_Mu25_TkMu0_Phi", &HLT_Mu25_TkMu0_Phi, &b_HLT_Mu25_TkMu0_Phi);
   fChain->SetBranchAddress("HLT_Mu12", &HLT_Mu12, &b_HLT_Mu12);
   fChain->SetBranchAddress("HLT_Mu15", &HLT_Mu15, &b_HLT_Mu15);
   fChain->SetBranchAddress("HLT_Mu20", &HLT_Mu20, &b_HLT_Mu20);
   fChain->SetBranchAddress("HLT_Mu27", &HLT_Mu27, &b_HLT_Mu27);
   fChain->SetBranchAddress("HLT_Mu50", &HLT_Mu50, &b_HLT_Mu50);
   fChain->SetBranchAddress("HLT_Mu55", &HLT_Mu55, &b_HLT_Mu55);
   fChain->SetBranchAddress("HLT_OldMu100", &HLT_OldMu100, &b_HLT_OldMu100);
   fChain->SetBranchAddress("HLT_TkMu100", &HLT_TkMu100, &b_HLT_TkMu100);
   fChain->SetBranchAddress("HLT_DiPFJet15_NoCaloMatched", &HLT_DiPFJet15_NoCaloMatched, &b_HLT_DiPFJet15_NoCaloMatched);
   fChain->SetBranchAddress("HLT_DiPFJet25_NoCaloMatched", &HLT_DiPFJet25_NoCaloMatched, &b_HLT_DiPFJet25_NoCaloMatched);
   fChain->SetBranchAddress("HLT_DiPFJet15_FBEta3_NoCaloMatched", &HLT_DiPFJet15_FBEta3_NoCaloMatched, &b_HLT_DiPFJet15_FBEta3_NoCaloMatched);
   fChain->SetBranchAddress("HLT_DiPFJet25_FBEta3_NoCaloMatched", &HLT_DiPFJet25_FBEta3_NoCaloMatched, &b_HLT_DiPFJet25_FBEta3_NoCaloMatched);
   */
   if (!isZB) {
     fChain->SetBranchAddress("HLT_DiPFJetAve40", &HLT_DiPFJetAve40, &b_HLT_DiPFJetAve40);
     fChain->SetBranchAddress("HLT_DiPFJetAve60", &HLT_DiPFJetAve60, &b_HLT_DiPFJetAve60);
     fChain->SetBranchAddress("HLT_DiPFJetAve80", &HLT_DiPFJetAve80, &b_HLT_DiPFJetAve80);
     fChain->SetBranchAddress("HLT_DiPFJetAve140", &HLT_DiPFJetAve140, &b_HLT_DiPFJetAve140);
     fChain->SetBranchAddress("HLT_DiPFJetAve200", &HLT_DiPFJetAve200, &b_HLT_DiPFJetAve200);
     fChain->SetBranchAddress("HLT_DiPFJetAve260", &HLT_DiPFJetAve260, &b_HLT_DiPFJetAve260);
     fChain->SetBranchAddress("HLT_DiPFJetAve320", &HLT_DiPFJetAve320, &b_HLT_DiPFJetAve320);
     fChain->SetBranchAddress("HLT_DiPFJetAve400", &HLT_DiPFJetAve400, &b_HLT_DiPFJetAve400);
     fChain->SetBranchAddress("HLT_DiPFJetAve500", &HLT_DiPFJetAve500, &b_HLT_DiPFJetAve500);
   }
   /*
   fChain->SetBranchAddress("HLT_DiPFJetAve15_HFJEC", &HLT_DiPFJetAve15_HFJEC, &b_HLT_DiPFJetAve15_HFJEC);
   fChain->SetBranchAddress("HLT_DiPFJetAve25_HFJEC", &HLT_DiPFJetAve25_HFJEC, &b_HLT_DiPFJetAve25_HFJEC);
   fChain->SetBranchAddress("HLT_DiPFJetAve35_HFJEC", &HLT_DiPFJetAve35_HFJEC, &b_HLT_DiPFJetAve35_HFJEC);
   */
   //if (dataset!="UL2017B") {
   if (!isZB) {
     fChain->SetBranchAddress("HLT_DiPFJetAve60_HFJEC", &HLT_DiPFJetAve60_HFJEC, &b_HLT_DiPFJetAve60_HFJEC);
     fChain->SetBranchAddress("HLT_DiPFJetAve80_HFJEC", &HLT_DiPFJetAve80_HFJEC, &b_HLT_DiPFJetAve80_HFJEC);
     fChain->SetBranchAddress("HLT_DiPFJetAve100_HFJEC", &HLT_DiPFJetAve100_HFJEC, &b_HLT_DiPFJetAve100_HFJEC);
     fChain->SetBranchAddress("HLT_DiPFJetAve160_HFJEC", &HLT_DiPFJetAve160_HFJEC, &b_HLT_DiPFJetAve160_HFJEC);
     fChain->SetBranchAddress("HLT_DiPFJetAve220_HFJEC", &HLT_DiPFJetAve220_HFJEC, &b_HLT_DiPFJetAve220_HFJEC);
     fChain->SetBranchAddress("HLT_DiPFJetAve300_HFJEC", &HLT_DiPFJetAve300_HFJEC, &b_HLT_DiPFJetAve300_HFJEC);
     //}
     //fChain->SetBranchAddress("HLT_AK8PFJet15", &HLT_AK8PFJet15, &b_HLT_AK8PFJet15);
     //fChain->SetBranchAddress("HLT_AK8PFJet25", &HLT_AK8PFJet25, &b_HLT_AK8PFJet25);
     fChain->SetBranchAddress("HLT_AK8PFJet40", &HLT_AK8PFJet40, &b_HLT_AK8PFJet40);
     fChain->SetBranchAddress("HLT_AK8PFJet60", &HLT_AK8PFJet60, &b_HLT_AK8PFJet60);
     fChain->SetBranchAddress("HLT_AK8PFJet80", &HLT_AK8PFJet80, &b_HLT_AK8PFJet80);
     fChain->SetBranchAddress("HLT_AK8PFJet140", &HLT_AK8PFJet140, &b_HLT_AK8PFJet140);
     fChain->SetBranchAddress("HLT_AK8PFJet200", &HLT_AK8PFJet200, &b_HLT_AK8PFJet200);
     fChain->SetBranchAddress("HLT_AK8PFJet260", &HLT_AK8PFJet260, &b_HLT_AK8PFJet260);
     fChain->SetBranchAddress("HLT_AK8PFJet320", &HLT_AK8PFJet320, &b_HLT_AK8PFJet320);
     fChain->SetBranchAddress("HLT_AK8PFJet400", &HLT_AK8PFJet400, &b_HLT_AK8PFJet400);
     fChain->SetBranchAddress("HLT_AK8PFJet450", &HLT_AK8PFJet450, &b_HLT_AK8PFJet450);
     fChain->SetBranchAddress("HLT_AK8PFJet500", &HLT_AK8PFJet500, &b_HLT_AK8PFJet500);
     if (isRun2>2)
       fChain->SetBranchAddress("HLT_AK8PFJet550", &HLT_AK8PFJet550, &b_HLT_AK8PFJet550);
     //fChain->SetBranchAddress("HLT_PFJet15", &HLT_PFJet15, &b_HLT_PFJet15);
     //fChain->SetBranchAddress("HLT_PFJet25", &HLT_PFJet25, &b_HLT_PFJet25);
     fChain->SetBranchAddress("HLT_PFJet40", &HLT_PFJet40, &b_HLT_PFJet40);
     fChain->SetBranchAddress("HLT_PFJet60", &HLT_PFJet60, &b_HLT_PFJet60);
     fChain->SetBranchAddress("HLT_PFJet80", &HLT_PFJet80, &b_HLT_PFJet80);
     fChain->SetBranchAddress("HLT_PFJet140", &HLT_PFJet140, &b_HLT_PFJet140);
     fChain->SetBranchAddress("HLT_PFJet200", &HLT_PFJet200, &b_HLT_PFJet200);
     fChain->SetBranchAddress("HLT_PFJet260", &HLT_PFJet260, &b_HLT_PFJet260);
     fChain->SetBranchAddress("HLT_PFJet320", &HLT_PFJet320, &b_HLT_PFJet320);
     fChain->SetBranchAddress("HLT_PFJet400", &HLT_PFJet400, &b_HLT_PFJet400);
     fChain->SetBranchAddress("HLT_PFJet450", &HLT_PFJet450, &b_HLT_PFJet450);
     fChain->SetBranchAddress("HLT_PFJet500", &HLT_PFJet500, &b_HLT_PFJet500);
     if (isRun2>2) {// && dataset!="UL2017B") {
       fChain->SetBranchAddress("HLT_PFJet550", &HLT_PFJet550, &b_HLT_PFJet550);
       //fChain->SetBranchAddress("HLT_PFJetFwd15", &HLT_PFJetFwd15, &b_HLT_PFJetFwd15);
       //fChain->SetBranchAddress("HLT_PFJetFwd25", &HLT_PFJetFwd25, &b_HLT_PFJetFwd25);
       fChain->SetBranchAddress("HLT_PFJetFwd40", &HLT_PFJetFwd40, &b_HLT_PFJetFwd40);
       fChain->SetBranchAddress("HLT_PFJetFwd60", &HLT_PFJetFwd60, &b_HLT_PFJetFwd60);
       fChain->SetBranchAddress("HLT_PFJetFwd80", &HLT_PFJetFwd80, &b_HLT_PFJetFwd80);
       fChain->SetBranchAddress("HLT_PFJetFwd140", &HLT_PFJetFwd140, &b_HLT_PFJetFwd140);
       fChain->SetBranchAddress("HLT_PFJetFwd200", &HLT_PFJetFwd200, &b_HLT_PFJetFwd200);
       fChain->SetBranchAddress("HLT_PFJetFwd260", &HLT_PFJetFwd260, &b_HLT_PFJetFwd260);
       fChain->SetBranchAddress("HLT_PFJetFwd320", &HLT_PFJetFwd320, &b_HLT_PFJetFwd320);
       fChain->SetBranchAddress("HLT_PFJetFwd400", &HLT_PFJetFwd400, &b_HLT_PFJetFwd400);
       fChain->SetBranchAddress("HLT_PFJetFwd450", &HLT_PFJetFwd450, &b_HLT_PFJetFwd450);
       fChain->SetBranchAddress("HLT_PFJetFwd500", &HLT_PFJetFwd500, &b_HLT_PFJetFwd500);
       //fChain->SetBranchAddress("HLT_AK8PFJetFwd15", &HLT_AK8PFJetFwd15, &b_HLT_AK8PFJetFwd15);
       //fChain->SetBranchAddress("HLT_AK8PFJetFwd25", &HLT_AK8PFJetFwd25, &b_HLT_AK8PFJetFwd25);
       //fChain->SetBranchAddress("HLT_AK8PFJetFwd40", &HLT_AK8PFJetFwd40, &b_HLT_AK8PFJetFwd40);
       //fChain->SetBranchAddress("HLT_AK8PFJetFwd60", &HLT_AK8PFJetFwd60, &b_HLT_AK8PFJetFwd60);
       //fChain->SetBranchAddress("HLT_AK8PFJetFwd80", &HLT_AK8PFJetFwd80, &b_HLT_AK8PFJetFwd80);
       //fChain->SetBranchAddress("HLT_AK8PFJetFwd140", &HLT_AK8PFJetFwd140, &b_HLT_AK8PFJetFwd140);
       //fChain->SetBranchAddress("HLT_AK8PFJetFwd200", &HLT_AK8PFJetFwd200, &b_HLT_AK8PFJetFwd200);
       //fChain->SetBranchAddress("HLT_AK8PFJetFwd260", &HLT_AK8PFJetFwd260, &b_HLT_AK8PFJetFwd260);
       //fChain->SetBranchAddress("HLT_AK8PFJetFwd320", &HLT_AK8PFJetFwd320, &b_HLT_AK8PFJetFwd320);
       //fChain->SetBranchAddress("HLT_AK8PFJetFwd400", &HLT_AK8PFJetFwd400, &b_HLT_AK8PFJetFwd400);
       //fChain->SetBranchAddress("HLT_AK8PFJetFwd450", &HLT_AK8PFJetFwd450, &b_HLT_AK8PFJetFwd450);
       //fChain->SetBranchAddress("HLT_AK8PFJetFwd500", &HLT_AK8PFJetFwd500, &b_HLT_AK8PFJetFwd500);
     }
   } // !isZB
   /*
   fChain->SetBranchAddress("HLT_PFHT180", &HLT_PFHT180, &b_HLT_PFHT180);
   fChain->SetBranchAddress("HLT_PFHT250", &HLT_PFHT250, &b_HLT_PFHT250);
   fChain->SetBranchAddress("HLT_PFHT370", &HLT_PFHT370, &b_HLT_PFHT370);
   fChain->SetBranchAddress("HLT_PFHT430", &HLT_PFHT430, &b_HLT_PFHT430);
   fChain->SetBranchAddress("HLT_PFHT510", &HLT_PFHT510, &b_HLT_PFHT510);
   fChain->SetBranchAddress("HLT_PFHT590", &HLT_PFHT590, &b_HLT_PFHT590);
   fChain->SetBranchAddress("HLT_PFHT680", &HLT_PFHT680, &b_HLT_PFHT680);
   fChain->SetBranchAddress("HLT_PFHT780", &HLT_PFHT780, &b_HLT_PFHT780);
   fChain->SetBranchAddress("HLT_PFHT890", &HLT_PFHT890, &b_HLT_PFHT890);
   fChain->SetBranchAddress("HLT_PFHT1050", &HLT_PFHT1050, &b_HLT_PFHT1050);
   fChain->SetBranchAddress("HLT_PFHT500_PFMET100_PFMHT100_IDTight", &HLT_PFHT500_PFMET100_PFMHT100_IDTight, &b_HLT_PFHT500_PFMET100_PFMHT100_IDTight);
   fChain->SetBranchAddress("HLT_PFHT500_PFMET110_PFMHT110_IDTight", &HLT_PFHT500_PFMET110_PFMHT110_IDTight, &b_HLT_PFHT500_PFMET110_PFMHT110_IDTight);
   fChain->SetBranchAddress("HLT_PFHT700_PFMET85_PFMHT85_IDTight", &HLT_PFHT700_PFMET85_PFMHT85_IDTight, &b_HLT_PFHT700_PFMET85_PFMHT85_IDTight);
   fChain->SetBranchAddress("HLT_PFHT700_PFMET95_PFMHT95_IDTight", &HLT_PFHT700_PFMET95_PFMHT95_IDTight, &b_HLT_PFHT700_PFMET95_PFMHT95_IDTight);
   fChain->SetBranchAddress("HLT_PFHT800_PFMET75_PFMHT75_IDTight", &HLT_PFHT800_PFMET75_PFMHT75_IDTight, &b_HLT_PFHT800_PFMET75_PFMHT75_IDTight);
   fChain->SetBranchAddress("HLT_PFHT800_PFMET85_PFMHT85_IDTight", &HLT_PFHT800_PFMET85_PFMHT85_IDTight, &b_HLT_PFHT800_PFMET85_PFMHT85_IDTight);
   fChain->SetBranchAddress("HLT_PFMET110_PFMHT110_IDTight", &HLT_PFMET110_PFMHT110_IDTight, &b_HLT_PFMET110_PFMHT110_IDTight);
   fChain->SetBranchAddress("HLT_PFMET120_PFMHT120_IDTight", &HLT_PFMET120_PFMHT120_IDTight, &b_HLT_PFMET120_PFMHT120_IDTight);
   fChain->SetBranchAddress("HLT_PFMET130_PFMHT130_IDTight", &HLT_PFMET130_PFMHT130_IDTight, &b_HLT_PFMET130_PFMHT130_IDTight);
   fChain->SetBranchAddress("HLT_PFMET140_PFMHT140_IDTight", &HLT_PFMET140_PFMHT140_IDTight, &b_HLT_PFMET140_PFMHT140_IDTight);
   fChain->SetBranchAddress("HLT_PFMET100_PFMHT100_IDTight_CaloBTagDeepCSV_3p1", &HLT_PFMET100_PFMHT100_IDTight_CaloBTagDeepCSV_3p1, &b_HLT_PFMET100_PFMHT100_IDTight_CaloBTagDeepCSV_3p1);
   fChain->SetBranchAddress("HLT_PFMET110_PFMHT110_IDTight_CaloBTagDeepCSV_3p1", &HLT_PFMET110_PFMHT110_IDTight_CaloBTagDeepCSV_3p1, &b_HLT_PFMET110_PFMHT110_IDTight_CaloBTagDeepCSV_3p1);
   fChain->SetBranchAddress("HLT_PFMET120_PFMHT120_IDTight_CaloBTagDeepCSV_3p1", &HLT_PFMET120_PFMHT120_IDTight_CaloBTagDeepCSV_3p1, &b_HLT_PFMET120_PFMHT120_IDTight_CaloBTagDeepCSV_3p1);
   fChain->SetBranchAddress("HLT_PFMET130_PFMHT130_IDTight_CaloBTagDeepCSV_3p1", &HLT_PFMET130_PFMHT130_IDTight_CaloBTagDeepCSV_3p1, &b_HLT_PFMET130_PFMHT130_IDTight_CaloBTagDeepCSV_3p1);
   fChain->SetBranchAddress("HLT_PFMET140_PFMHT140_IDTight_CaloBTagDeepCSV_3p1", &HLT_PFMET140_PFMHT140_IDTight_CaloBTagDeepCSV_3p1, &b_HLT_PFMET140_PFMHT140_IDTight_CaloBTagDeepCSV_3p1);
   fChain->SetBranchAddress("HLT_PFMET120_PFMHT120_IDTight_PFHT60", &HLT_PFMET120_PFMHT120_IDTight_PFHT60, &b_HLT_PFMET120_PFMHT120_IDTight_PFHT60);
   fChain->SetBranchAddress("HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60", &HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60, &b_HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60);
   fChain->SetBranchAddress("HLT_PFMETTypeOne120_PFMHT120_IDTight_PFHT60", &HLT_PFMETTypeOne120_PFMHT120_IDTight_PFHT60, &b_HLT_PFMETTypeOne120_PFMHT120_IDTight_PFHT60);
   fChain->SetBranchAddress("HLT_PFMETTypeOne110_PFMHT110_IDTight", &HLT_PFMETTypeOne110_PFMHT110_IDTight, &b_HLT_PFMETTypeOne110_PFMHT110_IDTight);
   fChain->SetBranchAddress("HLT_PFMETTypeOne120_PFMHT120_IDTight", &HLT_PFMETTypeOne120_PFMHT120_IDTight, &b_HLT_PFMETTypeOne120_PFMHT120_IDTight);
   fChain->SetBranchAddress("HLT_PFMETTypeOne130_PFMHT130_IDTight", &HLT_PFMETTypeOne130_PFMHT130_IDTight, &b_HLT_PFMETTypeOne130_PFMHT130_IDTight);
   fChain->SetBranchAddress("HLT_PFMETTypeOne140_PFMHT140_IDTight", &HLT_PFMETTypeOne140_PFMHT140_IDTight, &b_HLT_PFMETTypeOne140_PFMHT140_IDTight);
   fChain->SetBranchAddress("HLT_PFMETNoMu110_PFMHTNoMu110_IDTight", &HLT_PFMETNoMu110_PFMHTNoMu110_IDTight, &b_HLT_PFMETNoMu110_PFMHTNoMu110_IDTight);
   fChain->SetBranchAddress("HLT_PFMETNoMu120_PFMHTNoMu120_IDTight", &HLT_PFMETNoMu120_PFMHTNoMu120_IDTight, &b_HLT_PFMETNoMu120_PFMHTNoMu120_IDTight);
   fChain->SetBranchAddress("HLT_PFMETNoMu130_PFMHTNoMu130_IDTight", &HLT_PFMETNoMu130_PFMHTNoMu130_IDTight, &b_HLT_PFMETNoMu130_PFMHTNoMu130_IDTight);
   fChain->SetBranchAddress("HLT_PFMETNoMu140_PFMHTNoMu140_IDTight", &HLT_PFMETNoMu140_PFMHTNoMu140_IDTight, &b_HLT_PFMETNoMu140_PFMHTNoMu140_IDTight);
   fChain->SetBranchAddress("HLT_MonoCentralPFJet80_PFMETNoMu110_PFMHTNoMu110_IDTight", &HLT_MonoCentralPFJet80_PFMETNoMu110_PFMHTNoMu110_IDTight, &b_HLT_MonoCentralPFJet80_PFMETNoMu110_PFMHTNoMu110_IDTight);
   fChain->SetBranchAddress("HLT_MonoCentralPFJet80_PFMETNoMu120_PFMHTNoMu120_IDTight", &HLT_MonoCentralPFJet80_PFMETNoMu120_PFMHTNoMu120_IDTight, &b_HLT_MonoCentralPFJet80_PFMETNoMu120_PFMHTNoMu120_IDTight);
   fChain->SetBranchAddress("HLT_MonoCentralPFJet80_PFMETNoMu130_PFMHTNoMu130_IDTight", &HLT_MonoCentralPFJet80_PFMETNoMu130_PFMHTNoMu130_IDTight, &b_HLT_MonoCentralPFJet80_PFMETNoMu130_PFMHTNoMu130_IDTight);
   fChain->SetBranchAddress("HLT_MonoCentralPFJet80_PFMETNoMu140_PFMHTNoMu140_IDTight", &HLT_MonoCentralPFJet80_PFMETNoMu140_PFMHTNoMu140_IDTight, &b_HLT_MonoCentralPFJet80_PFMETNoMu140_PFMHTNoMu140_IDTight);
   fChain->SetBranchAddress("HLT_L1ETMHadSeeds", &HLT_L1ETMHadSeeds, &b_HLT_L1ETMHadSeeds);
   fChain->SetBranchAddress("HLT_CaloMHT90", &HLT_CaloMHT90, &b_HLT_CaloMHT90);
   fChain->SetBranchAddress("HLT_CaloMET80_NotCleaned", &HLT_CaloMET80_NotCleaned, &b_HLT_CaloMET80_NotCleaned);
   fChain->SetBranchAddress("HLT_CaloMET90_NotCleaned", &HLT_CaloMET90_NotCleaned, &b_HLT_CaloMET90_NotCleaned);
   fChain->SetBranchAddress("HLT_CaloMET100_NotCleaned", &HLT_CaloMET100_NotCleaned, &b_HLT_CaloMET100_NotCleaned);
   fChain->SetBranchAddress("HLT_CaloMET110_NotCleaned", &HLT_CaloMET110_NotCleaned, &b_HLT_CaloMET110_NotCleaned);
   fChain->SetBranchAddress("HLT_CaloMET250_NotCleaned", &HLT_CaloMET250_NotCleaned, &b_HLT_CaloMET250_NotCleaned);
   fChain->SetBranchAddress("HLT_CaloMET300_NotCleaned", &HLT_CaloMET300_NotCleaned, &b_HLT_CaloMET300_NotCleaned);
   fChain->SetBranchAddress("HLT_CaloMET350_NotCleaned", &HLT_CaloMET350_NotCleaned, &b_HLT_CaloMET350_NotCleaned);
   fChain->SetBranchAddress("HLT_PFMET200_NotCleaned", &HLT_PFMET200_NotCleaned, &b_HLT_PFMET200_NotCleaned);
   fChain->SetBranchAddress("HLT_PFMET250_NotCleaned", &HLT_PFMET250_NotCleaned, &b_HLT_PFMET250_NotCleaned);
   fChain->SetBranchAddress("HLT_PFMET300_NotCleaned", &HLT_PFMET300_NotCleaned, &b_HLT_PFMET300_NotCleaned);
   fChain->SetBranchAddress("HLT_PFMET200_BeamHaloCleaned", &HLT_PFMET200_BeamHaloCleaned, &b_HLT_PFMET200_BeamHaloCleaned);
   fChain->SetBranchAddress("HLT_PFMETTypeOne200_BeamHaloCleaned", &HLT_PFMETTypeOne200_BeamHaloCleaned, &b_HLT_PFMETTypeOne200_BeamHaloCleaned);
   fChain->SetBranchAddress("HLT_MET105_IsoTrk50", &HLT_MET105_IsoTrk50, &b_HLT_MET105_IsoTrk50);
   fChain->SetBranchAddress("HLT_MET120_IsoTrk50", &HLT_MET120_IsoTrk50, &b_HLT_MET120_IsoTrk50);
   fChain->SetBranchAddress("HLT_SingleJet30_Mu12_SinglePFJet40", &HLT_SingleJet30_Mu12_SinglePFJet40, &b_HLT_SingleJet30_Mu12_SinglePFJet40);
   fChain->SetBranchAddress("HLT_Mu12_DoublePFJets40_CaloBTagDeepCSV_p71", &HLT_Mu12_DoublePFJets40_CaloBTagDeepCSV_p71, &b_HLT_Mu12_DoublePFJets40_CaloBTagDeepCSV_p71);
   fChain->SetBranchAddress("HLT_Mu12_DoublePFJets100_CaloBTagDeepCSV_p71", &HLT_Mu12_DoublePFJets100_CaloBTagDeepCSV_p71, &b_HLT_Mu12_DoublePFJets100_CaloBTagDeepCSV_p71);
   fChain->SetBranchAddress("HLT_Mu12_DoublePFJets200_CaloBTagDeepCSV_p71", &HLT_Mu12_DoublePFJets200_CaloBTagDeepCSV_p71, &b_HLT_Mu12_DoublePFJets200_CaloBTagDeepCSV_p71);
   fChain->SetBranchAddress("HLT_Mu12_DoublePFJets350_CaloBTagDeepCSV_p71", &HLT_Mu12_DoublePFJets350_CaloBTagDeepCSV_p71, &b_HLT_Mu12_DoublePFJets350_CaloBTagDeepCSV_p71);
   fChain->SetBranchAddress("HLT_Mu12_DoublePFJets40MaxDeta1p6_DoubleCaloBTagDeepCSV_p71", &HLT_Mu12_DoublePFJets40MaxDeta1p6_DoubleCaloBTagDeepCSV_p71, &b_HLT_Mu12_DoublePFJets40MaxDeta1p6_DoubleCaloBTagDeepCSV_p71);
   fChain->SetBranchAddress("HLT_Mu12_DoublePFJets54MaxDeta1p6_DoubleCaloBTagDeepCSV_p71", &HLT_Mu12_DoublePFJets54MaxDeta1p6_DoubleCaloBTagDeepCSV_p71, &b_HLT_Mu12_DoublePFJets54MaxDeta1p6_DoubleCaloBTagDeepCSV_p71);
   fChain->SetBranchAddress("HLT_Mu12_DoublePFJets62MaxDeta1p6_DoubleCaloBTagDeepCSV_p71", &HLT_Mu12_DoublePFJets62MaxDeta1p6_DoubleCaloBTagDeepCSV_p71, &b_HLT_Mu12_DoublePFJets62MaxDeta1p6_DoubleCaloBTagDeepCSV_p71);
   fChain->SetBranchAddress("HLT_DoublePFJets40_CaloBTagDeepCSV_p71", &HLT_DoublePFJets40_CaloBTagDeepCSV_p71, &b_HLT_DoublePFJets40_CaloBTagDeepCSV_p71);
   fChain->SetBranchAddress("HLT_DoublePFJets100_CaloBTagDeepCSV_p71", &HLT_DoublePFJets100_CaloBTagDeepCSV_p71, &b_HLT_DoublePFJets100_CaloBTagDeepCSV_p71);
   fChain->SetBranchAddress("HLT_DoublePFJets200_CaloBTagDeepCSV_p71", &HLT_DoublePFJets200_CaloBTagDeepCSV_p71, &b_HLT_DoublePFJets200_CaloBTagDeepCSV_p71);
   fChain->SetBranchAddress("HLT_DoublePFJets350_CaloBTagDeepCSV_p71", &HLT_DoublePFJets350_CaloBTagDeepCSV_p71, &b_HLT_DoublePFJets350_CaloBTagDeepCSV_p71);
   fChain->SetBranchAddress("HLT_DoublePFJets116MaxDeta1p6_DoubleCaloBTagDeepCSV_p71", &HLT_DoublePFJets116MaxDeta1p6_DoubleCaloBTagDeepCSV_p71, &b_HLT_DoublePFJets116MaxDeta1p6_DoubleCaloBTagDeepCSV_p71);
   fChain->SetBranchAddress("HLT_DoublePFJets128MaxDeta1p6_DoubleCaloBTagDeepCSV_p71", &HLT_DoublePFJets128MaxDeta1p6_DoubleCaloBTagDeepCSV_p71, &b_HLT_DoublePFJets128MaxDeta1p6_DoubleCaloBTagDeepCSV_p71);
   fChain->SetBranchAddress("HLT_Photon300_NoHE", &HLT_Photon300_NoHE, &b_HLT_Photon300_NoHE);
   fChain->SetBranchAddress("HLT_Mu8_TrkIsoVVL", &HLT_Mu8_TrkIsoVVL, &b_HLT_Mu8_TrkIsoVVL);
   fChain->SetBranchAddress("HLT_Mu8_DiEle12_CaloIdL_TrackIdL_DZ", &HLT_Mu8_DiEle12_CaloIdL_TrackIdL_DZ, &b_HLT_Mu8_DiEle12_CaloIdL_TrackIdL_DZ);
   fChain->SetBranchAddress("HLT_Mu8_DiEle12_CaloIdL_TrackIdL", &HLT_Mu8_DiEle12_CaloIdL_TrackIdL, &b_HLT_Mu8_DiEle12_CaloIdL_TrackIdL);
   fChain->SetBranchAddress("HLT_Mu8_Ele8_CaloIdM_TrackIdM_Mass8_PFHT350_DZ", &HLT_Mu8_Ele8_CaloIdM_TrackIdM_Mass8_PFHT350_DZ, &b_HLT_Mu8_Ele8_CaloIdM_TrackIdM_Mass8_PFHT350_DZ);
   fChain->SetBranchAddress("HLT_Mu8_Ele8_CaloIdM_TrackIdM_Mass8_PFHT350", &HLT_Mu8_Ele8_CaloIdM_TrackIdM_Mass8_PFHT350, &b_HLT_Mu8_Ele8_CaloIdM_TrackIdM_Mass8_PFHT350);
   fChain->SetBranchAddress("HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ", &HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ, &b_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ);
   fChain->SetBranchAddress("HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_PFDiJet30", &HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_PFDiJet30, &b_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_PFDiJet30);
   fChain->SetBranchAddress("HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_CaloDiJet30", &HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_CaloDiJet30, &b_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_CaloDiJet30);
   fChain->SetBranchAddress("HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_PFDiJet30_PFBtagDeepCSV_1p5", &HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_PFDiJet30_PFBtagDeepCSV_1p5, &b_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_PFDiJet30_PFBtagDeepCSV_1p5);
   fChain->SetBranchAddress("HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_CaloDiJet30_CaloBtagDeepCSV_1p5", &HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_CaloDiJet30_CaloBtagDeepCSV_1p5, &b_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_CaloDiJet30_CaloBtagDeepCSV_1p5);
   fChain->SetBranchAddress("HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL", &HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL, &b_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL);
   fChain->SetBranchAddress("HLT_Mu17_TrkIsoVVL", &HLT_Mu17_TrkIsoVVL, &b_HLT_Mu17_TrkIsoVVL);
   fChain->SetBranchAddress("HLT_Mu19_TrkIsoVVL", &HLT_Mu19_TrkIsoVVL, &b_HLT_Mu19_TrkIsoVVL);
   fChain->SetBranchAddress("HLT_BTagMu_AK4DiJet20_Mu5", &HLT_BTagMu_AK4DiJet20_Mu5, &b_HLT_BTagMu_AK4DiJet20_Mu5);
   fChain->SetBranchAddress("HLT_BTagMu_AK4DiJet40_Mu5", &HLT_BTagMu_AK4DiJet40_Mu5, &b_HLT_BTagMu_AK4DiJet40_Mu5);
   fChain->SetBranchAddress("HLT_BTagMu_AK4DiJet70_Mu5", &HLT_BTagMu_AK4DiJet70_Mu5, &b_HLT_BTagMu_AK4DiJet70_Mu5);
   fChain->SetBranchAddress("HLT_BTagMu_AK4DiJet110_Mu5", &HLT_BTagMu_AK4DiJet110_Mu5, &b_HLT_BTagMu_AK4DiJet110_Mu5);
   fChain->SetBranchAddress("HLT_BTagMu_AK4DiJet170_Mu5", &HLT_BTagMu_AK4DiJet170_Mu5, &b_HLT_BTagMu_AK4DiJet170_Mu5);
   fChain->SetBranchAddress("HLT_BTagMu_AK4Jet300_Mu5", &HLT_BTagMu_AK4Jet300_Mu5, &b_HLT_BTagMu_AK4Jet300_Mu5);
   fChain->SetBranchAddress("HLT_BTagMu_AK8DiJet170_Mu5", &HLT_BTagMu_AK8DiJet170_Mu5, &b_HLT_BTagMu_AK8DiJet170_Mu5);
   fChain->SetBranchAddress("HLT_BTagMu_AK8Jet170_DoubleMu5", &HLT_BTagMu_AK8Jet170_DoubleMu5, &b_HLT_BTagMu_AK8Jet170_DoubleMu5);
   fChain->SetBranchAddress("HLT_BTagMu_AK8Jet300_Mu5", &HLT_BTagMu_AK8Jet300_Mu5, &b_HLT_BTagMu_AK8Jet300_Mu5);
   fChain->SetBranchAddress("HLT_BTagMu_AK4DiJet20_Mu5_noalgo", &HLT_BTagMu_AK4DiJet20_Mu5_noalgo, &b_HLT_BTagMu_AK4DiJet20_Mu5_noalgo);
   fChain->SetBranchAddress("HLT_BTagMu_AK4DiJet40_Mu5_noalgo", &HLT_BTagMu_AK4DiJet40_Mu5_noalgo, &b_HLT_BTagMu_AK4DiJet40_Mu5_noalgo);
   fChain->SetBranchAddress("HLT_BTagMu_AK4DiJet70_Mu5_noalgo", &HLT_BTagMu_AK4DiJet70_Mu5_noalgo, &b_HLT_BTagMu_AK4DiJet70_Mu5_noalgo);
   fChain->SetBranchAddress("HLT_BTagMu_AK4DiJet110_Mu5_noalgo", &HLT_BTagMu_AK4DiJet110_Mu5_noalgo, &b_HLT_BTagMu_AK4DiJet110_Mu5_noalgo);
   fChain->SetBranchAddress("HLT_BTagMu_AK4DiJet170_Mu5_noalgo", &HLT_BTagMu_AK4DiJet170_Mu5_noalgo, &b_HLT_BTagMu_AK4DiJet170_Mu5_noalgo);
   fChain->SetBranchAddress("HLT_BTagMu_AK4Jet300_Mu5_noalgo", &HLT_BTagMu_AK4Jet300_Mu5_noalgo, &b_HLT_BTagMu_AK4Jet300_Mu5_noalgo);
   fChain->SetBranchAddress("HLT_BTagMu_AK8DiJet170_Mu5_noalgo", &HLT_BTagMu_AK8DiJet170_Mu5_noalgo, &b_HLT_BTagMu_AK8DiJet170_Mu5_noalgo);
   fChain->SetBranchAddress("HLT_BTagMu_AK8Jet170_DoubleMu5_noalgo", &HLT_BTagMu_AK8Jet170_DoubleMu5_noalgo, &b_HLT_BTagMu_AK8Jet170_DoubleMu5_noalgo);
   fChain->SetBranchAddress("HLT_BTagMu_AK8Jet300_Mu5_noalgo", &HLT_BTagMu_AK8Jet300_Mu5_noalgo, &b_HLT_BTagMu_AK8Jet300_Mu5_noalgo);
   fChain->SetBranchAddress("HLT_Ele15_Ele8_CaloIdL_TrackIdL_IsoVL", &HLT_Ele15_Ele8_CaloIdL_TrackIdL_IsoVL, &b_HLT_Ele15_Ele8_CaloIdL_TrackIdL_IsoVL);
   fChain->SetBranchAddress("HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ", &HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ, &b_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ);
   fChain->SetBranchAddress("HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL", &HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL, &b_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL);
   fChain->SetBranchAddress("HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ", &HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ, &b_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ);
   fChain->SetBranchAddress("HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL", &HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL, &b_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL);
   fChain->SetBranchAddress("HLT_Mu12_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL", &HLT_Mu12_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL, &b_HLT_Mu12_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL);
   fChain->SetBranchAddress("HLT_Mu12_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ", &HLT_Mu12_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ, &b_HLT_Mu12_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ);
   fChain->SetBranchAddress("HLT_Mu12_DoublePhoton20", &HLT_Mu12_DoublePhoton20, &b_HLT_Mu12_DoublePhoton20);
   fChain->SetBranchAddress("HLT_TriplePhoton_20_20_20_CaloIdLV2", &HLT_TriplePhoton_20_20_20_CaloIdLV2, &b_HLT_TriplePhoton_20_20_20_CaloIdLV2);
   fChain->SetBranchAddress("HLT_TriplePhoton_20_20_20_CaloIdLV2_R9IdVL", &HLT_TriplePhoton_20_20_20_CaloIdLV2_R9IdVL, &b_HLT_TriplePhoton_20_20_20_CaloIdLV2_R9IdVL);
   fChain->SetBranchAddress("HLT_TriplePhoton_30_30_10_CaloIdLV2", &HLT_TriplePhoton_30_30_10_CaloIdLV2, &b_HLT_TriplePhoton_30_30_10_CaloIdLV2);
   fChain->SetBranchAddress("HLT_TriplePhoton_30_30_10_CaloIdLV2_R9IdVL", &HLT_TriplePhoton_30_30_10_CaloIdLV2_R9IdVL, &b_HLT_TriplePhoton_30_30_10_CaloIdLV2_R9IdVL);
   fChain->SetBranchAddress("HLT_TriplePhoton_35_35_5_CaloIdLV2_R9IdVL", &HLT_TriplePhoton_35_35_5_CaloIdLV2_R9IdVL, &b_HLT_TriplePhoton_35_35_5_CaloIdLV2_R9IdVL);
   fChain->SetBranchAddress("HLT_Photon20", &HLT_Photon20, &b_HLT_Photon20);
   fChain->SetBranchAddress("HLT_Photon33", &HLT_Photon33, &b_HLT_Photon33);
   fChain->SetBranchAddress("HLT_Photon50", &HLT_Photon50, &b_HLT_Photon50);
   fChain->SetBranchAddress("HLT_Photon75", &HLT_Photon75, &b_HLT_Photon75);
   fChain->SetBranchAddress("HLT_Photon90", &HLT_Photon90, &b_HLT_Photon90);
   fChain->SetBranchAddress("HLT_Photon120", &HLT_Photon120, &b_HLT_Photon120);
   fChain->SetBranchAddress("HLT_Photon150", &HLT_Photon150, &b_HLT_Photon150);
   fChain->SetBranchAddress("HLT_Photon175", &HLT_Photon175, &b_HLT_Photon175);
   fChain->SetBranchAddress("HLT_Photon200", &HLT_Photon200, &b_HLT_Photon200);
   fChain->SetBranchAddress("HLT_Photon100EB_TightID_TightIso", &HLT_Photon100EB_TightID_TightIso, &b_HLT_Photon100EB_TightID_TightIso);
   fChain->SetBranchAddress("HLT_Photon110EB_TightID_TightIso", &HLT_Photon110EB_TightID_TightIso, &b_HLT_Photon110EB_TightID_TightIso);
   fChain->SetBranchAddress("HLT_Photon120EB_TightID_TightIso", &HLT_Photon120EB_TightID_TightIso, &b_HLT_Photon120EB_TightID_TightIso);
   fChain->SetBranchAddress("HLT_Photon100EBHE10", &HLT_Photon100EBHE10, &b_HLT_Photon100EBHE10);
   fChain->SetBranchAddress("HLT_Photon100EEHE10", &HLT_Photon100EEHE10, &b_HLT_Photon100EEHE10);
   fChain->SetBranchAddress("HLT_Photon100EE_TightID_TightIso", &HLT_Photon100EE_TightID_TightIso, &b_HLT_Photon100EE_TightID_TightIso);
   fChain->SetBranchAddress("HLT_Photon50_R9Id90_HE10_IsoM", &HLT_Photon50_R9Id90_HE10_IsoM, &b_HLT_Photon50_R9Id90_HE10_IsoM);
   fChain->SetBranchAddress("HLT_Photon75_R9Id90_HE10_IsoM", &HLT_Photon75_R9Id90_HE10_IsoM, &b_HLT_Photon75_R9Id90_HE10_IsoM);
   fChain->SetBranchAddress("HLT_Photon75_R9Id90_HE10_IsoM_EBOnly_CaloMJJ300_PFJetsMJJ400DEta3", &HLT_Photon75_R9Id90_HE10_IsoM_EBOnly_CaloMJJ300_PFJetsMJJ400DEta3, &b_HLT_Photon75_R9Id90_HE10_IsoM_EBOnly_CaloMJJ300_PFJetsMJJ400DEta3);
   fChain->SetBranchAddress("HLT_Photon75_R9Id90_HE10_IsoM_EBOnly_CaloMJJ400_PFJetsMJJ600DEta3", &HLT_Photon75_R9Id90_HE10_IsoM_EBOnly_CaloMJJ400_PFJetsMJJ600DEta3, &b_HLT_Photon75_R9Id90_HE10_IsoM_EBOnly_CaloMJJ400_PFJetsMJJ600DEta3);
   fChain->SetBranchAddress("HLT_Photon90_R9Id90_HE10_IsoM", &HLT_Photon90_R9Id90_HE10_IsoM, &b_HLT_Photon90_R9Id90_HE10_IsoM);
   fChain->SetBranchAddress("HLT_Photon120_R9Id90_HE10_IsoM", &HLT_Photon120_R9Id90_HE10_IsoM, &b_HLT_Photon120_R9Id90_HE10_IsoM);
   fChain->SetBranchAddress("HLT_Photon165_R9Id90_HE10_IsoM", &HLT_Photon165_R9Id90_HE10_IsoM, &b_HLT_Photon165_R9Id90_HE10_IsoM);
   fChain->SetBranchAddress("HLT_Photon90_CaloIdL_PFHT700", &HLT_Photon90_CaloIdL_PFHT700, &b_HLT_Photon90_CaloIdL_PFHT700);
   fChain->SetBranchAddress("HLT_Diphoton30_22_R9Id_OR_IsoCaloId_AND_HE_R9Id_Mass90", &HLT_Diphoton30_22_R9Id_OR_IsoCaloId_AND_HE_R9Id_Mass90, &b_HLT_Diphoton30_22_R9Id_OR_IsoCaloId_AND_HE_R9Id_Mass90);
   fChain->SetBranchAddress("HLT_Diphoton30_22_R9Id_OR_IsoCaloId_AND_HE_R9Id_Mass95", &HLT_Diphoton30_22_R9Id_OR_IsoCaloId_AND_HE_R9Id_Mass95, &b_HLT_Diphoton30_22_R9Id_OR_IsoCaloId_AND_HE_R9Id_Mass95);
   fChain->SetBranchAddress("HLT_Diphoton30PV_18PV_R9Id_AND_IsoCaloId_AND_HE_R9Id_PixelVeto_Mass55", &HLT_Diphoton30PV_18PV_R9Id_AND_IsoCaloId_AND_HE_R9Id_PixelVeto_Mass55, &b_HLT_Diphoton30PV_18PV_R9Id_AND_IsoCaloId_AND_HE_R9Id_PixelVeto_Mass55);
   fChain->SetBranchAddress("HLT_Diphoton30PV_18PV_R9Id_AND_IsoCaloId_AND_HE_R9Id_NoPixelVeto_Mass55", &HLT_Diphoton30PV_18PV_R9Id_AND_IsoCaloId_AND_HE_R9Id_NoPixelVeto_Mass55, &b_HLT_Diphoton30PV_18PV_R9Id_AND_IsoCaloId_AND_HE_R9Id_NoPixelVeto_Mass55);
   fChain->SetBranchAddress("HLT_Photon35_TwoProngs35", &HLT_Photon35_TwoProngs35, &b_HLT_Photon35_TwoProngs35);
   fChain->SetBranchAddress("HLT_IsoMu24_TwoProngs35", &HLT_IsoMu24_TwoProngs35, &b_HLT_IsoMu24_TwoProngs35);
   fChain->SetBranchAddress("HLT_Dimuon0_Jpsi_L1_NoOS", &HLT_Dimuon0_Jpsi_L1_NoOS, &b_HLT_Dimuon0_Jpsi_L1_NoOS);
   fChain->SetBranchAddress("HLT_Dimuon0_Jpsi_NoVertexing_NoOS", &HLT_Dimuon0_Jpsi_NoVertexing_NoOS, &b_HLT_Dimuon0_Jpsi_NoVertexing_NoOS);
   fChain->SetBranchAddress("HLT_Dimuon0_Jpsi", &HLT_Dimuon0_Jpsi, &b_HLT_Dimuon0_Jpsi);
   fChain->SetBranchAddress("HLT_Dimuon0_Jpsi_NoVertexing", &HLT_Dimuon0_Jpsi_NoVertexing, &b_HLT_Dimuon0_Jpsi_NoVertexing);
   fChain->SetBranchAddress("HLT_Dimuon0_Jpsi_L1_4R_0er1p5R", &HLT_Dimuon0_Jpsi_L1_4R_0er1p5R, &b_HLT_Dimuon0_Jpsi_L1_4R_0er1p5R);
   fChain->SetBranchAddress("HLT_Dimuon0_Jpsi_NoVertexing_L1_4R_0er1p5R", &HLT_Dimuon0_Jpsi_NoVertexing_L1_4R_0er1p5R, &b_HLT_Dimuon0_Jpsi_NoVertexing_L1_4R_0er1p5R);
   fChain->SetBranchAddress("HLT_Dimuon0_Jpsi3p5_Muon2", &HLT_Dimuon0_Jpsi3p5_Muon2, &b_HLT_Dimuon0_Jpsi3p5_Muon2);
   fChain->SetBranchAddress("HLT_Dimuon0_Upsilon_L1_4p5", &HLT_Dimuon0_Upsilon_L1_4p5, &b_HLT_Dimuon0_Upsilon_L1_4p5);
   fChain->SetBranchAddress("HLT_Dimuon0_Upsilon_L1_5", &HLT_Dimuon0_Upsilon_L1_5, &b_HLT_Dimuon0_Upsilon_L1_5);
   fChain->SetBranchAddress("HLT_Dimuon0_Upsilon_L1_4p5NoOS", &HLT_Dimuon0_Upsilon_L1_4p5NoOS, &b_HLT_Dimuon0_Upsilon_L1_4p5NoOS);
   fChain->SetBranchAddress("HLT_Dimuon0_Upsilon_L1_4p5er2p0", &HLT_Dimuon0_Upsilon_L1_4p5er2p0, &b_HLT_Dimuon0_Upsilon_L1_4p5er2p0);
   fChain->SetBranchAddress("HLT_Dimuon0_Upsilon_L1_4p5er2p0M", &HLT_Dimuon0_Upsilon_L1_4p5er2p0M, &b_HLT_Dimuon0_Upsilon_L1_4p5er2p0M);
   fChain->SetBranchAddress("HLT_Dimuon0_Upsilon_NoVertexing", &HLT_Dimuon0_Upsilon_NoVertexing, &b_HLT_Dimuon0_Upsilon_NoVertexing);
   fChain->SetBranchAddress("HLT_Dimuon0_Upsilon_L1_5M", &HLT_Dimuon0_Upsilon_L1_5M, &b_HLT_Dimuon0_Upsilon_L1_5M);
   fChain->SetBranchAddress("HLT_Dimuon0_LowMass_L1_0er1p5R", &HLT_Dimuon0_LowMass_L1_0er1p5R, &b_HLT_Dimuon0_LowMass_L1_0er1p5R);
   fChain->SetBranchAddress("HLT_Dimuon0_LowMass_L1_0er1p5", &HLT_Dimuon0_LowMass_L1_0er1p5, &b_HLT_Dimuon0_LowMass_L1_0er1p5);
   fChain->SetBranchAddress("HLT_Dimuon0_LowMass", &HLT_Dimuon0_LowMass, &b_HLT_Dimuon0_LowMass);
   fChain->SetBranchAddress("HLT_Dimuon0_LowMass_L1_4", &HLT_Dimuon0_LowMass_L1_4, &b_HLT_Dimuon0_LowMass_L1_4);
   fChain->SetBranchAddress("HLT_Dimuon0_LowMass_L1_4R", &HLT_Dimuon0_LowMass_L1_4R, &b_HLT_Dimuon0_LowMass_L1_4R);
   fChain->SetBranchAddress("HLT_Dimuon0_LowMass_L1_TM530", &HLT_Dimuon0_LowMass_L1_TM530, &b_HLT_Dimuon0_LowMass_L1_TM530);
   fChain->SetBranchAddress("HLT_Dimuon0_Upsilon_Muon_L1_TM0", &HLT_Dimuon0_Upsilon_Muon_L1_TM0, &b_HLT_Dimuon0_Upsilon_Muon_L1_TM0);
   fChain->SetBranchAddress("HLT_Dimuon0_Upsilon_Muon_NoL1Mass", &HLT_Dimuon0_Upsilon_Muon_NoL1Mass, &b_HLT_Dimuon0_Upsilon_Muon_NoL1Mass);
   fChain->SetBranchAddress("HLT_TripleMu_5_3_3_Mass3p8_DZ", &HLT_TripleMu_5_3_3_Mass3p8_DZ, &b_HLT_TripleMu_5_3_3_Mass3p8_DZ);
   fChain->SetBranchAddress("HLT_TripleMu_10_5_5_DZ", &HLT_TripleMu_10_5_5_DZ, &b_HLT_TripleMu_10_5_5_DZ);
   fChain->SetBranchAddress("HLT_TripleMu_12_10_5", &HLT_TripleMu_12_10_5, &b_HLT_TripleMu_12_10_5);
   fChain->SetBranchAddress("HLT_Tau3Mu_Mu7_Mu1_TkMu1_Tau15", &HLT_Tau3Mu_Mu7_Mu1_TkMu1_Tau15, &b_HLT_Tau3Mu_Mu7_Mu1_TkMu1_Tau15);
   fChain->SetBranchAddress("HLT_Tau3Mu_Mu7_Mu1_TkMu1_Tau15_Charge1", &HLT_Tau3Mu_Mu7_Mu1_TkMu1_Tau15_Charge1, &b_HLT_Tau3Mu_Mu7_Mu1_TkMu1_Tau15_Charge1);
   fChain->SetBranchAddress("HLT_Tau3Mu_Mu7_Mu1_TkMu1_IsoTau15", &HLT_Tau3Mu_Mu7_Mu1_TkMu1_IsoTau15, &b_HLT_Tau3Mu_Mu7_Mu1_TkMu1_IsoTau15);
   fChain->SetBranchAddress("HLT_Tau3Mu_Mu7_Mu1_TkMu1_IsoTau15_Charge1", &HLT_Tau3Mu_Mu7_Mu1_TkMu1_IsoTau15_Charge1, &b_HLT_Tau3Mu_Mu7_Mu1_TkMu1_IsoTau15_Charge1);
   fChain->SetBranchAddress("HLT_DoubleMu3_DZ_PFMET50_PFMHT60", &HLT_DoubleMu3_DZ_PFMET50_PFMHT60, &b_HLT_DoubleMu3_DZ_PFMET50_PFMHT60);
   fChain->SetBranchAddress("HLT_DoubleMu3_DZ_PFMET70_PFMHT70", &HLT_DoubleMu3_DZ_PFMET70_PFMHT70, &b_HLT_DoubleMu3_DZ_PFMET70_PFMHT70);
   fChain->SetBranchAddress("HLT_DoubleMu3_DZ_PFMET90_PFMHT90", &HLT_DoubleMu3_DZ_PFMET90_PFMHT90, &b_HLT_DoubleMu3_DZ_PFMET90_PFMHT90);
   fChain->SetBranchAddress("HLT_DoubleMu3_Trk_Tau3mu_NoL1Mass", &HLT_DoubleMu3_Trk_Tau3mu_NoL1Mass, &b_HLT_DoubleMu3_Trk_Tau3mu_NoL1Mass);
   fChain->SetBranchAddress("HLT_DoubleMu4_Jpsi_Displaced", &HLT_DoubleMu4_Jpsi_Displaced, &b_HLT_DoubleMu4_Jpsi_Displaced);
   fChain->SetBranchAddress("HLT_DoubleMu4_Jpsi_NoVertexing", &HLT_DoubleMu4_Jpsi_NoVertexing, &b_HLT_DoubleMu4_Jpsi_NoVertexing);
   fChain->SetBranchAddress("HLT_DoubleMu4_JpsiTrkTrk_Displaced", &HLT_DoubleMu4_JpsiTrkTrk_Displaced, &b_HLT_DoubleMu4_JpsiTrkTrk_Displaced);
   fChain->SetBranchAddress("HLT_DoubleMu43NoFiltersNoVtx", &HLT_DoubleMu43NoFiltersNoVtx, &b_HLT_DoubleMu43NoFiltersNoVtx);
   fChain->SetBranchAddress("HLT_DoubleMu48NoFiltersNoVtx", &HLT_DoubleMu48NoFiltersNoVtx, &b_HLT_DoubleMu48NoFiltersNoVtx);
   fChain->SetBranchAddress("HLT_Mu43NoFiltersNoVtx_Photon43_CaloIdL", &HLT_Mu43NoFiltersNoVtx_Photon43_CaloIdL, &b_HLT_Mu43NoFiltersNoVtx_Photon43_CaloIdL);
   fChain->SetBranchAddress("HLT_Mu48NoFiltersNoVtx_Photon48_CaloIdL", &HLT_Mu48NoFiltersNoVtx_Photon48_CaloIdL, &b_HLT_Mu48NoFiltersNoVtx_Photon48_CaloIdL);
   fChain->SetBranchAddress("HLT_Mu38NoFiltersNoVtxDisplaced_Photon38_CaloIdL", &HLT_Mu38NoFiltersNoVtxDisplaced_Photon38_CaloIdL, &b_HLT_Mu38NoFiltersNoVtxDisplaced_Photon38_CaloIdL);
   fChain->SetBranchAddress("HLT_Mu43NoFiltersNoVtxDisplaced_Photon43_CaloIdL", &HLT_Mu43NoFiltersNoVtxDisplaced_Photon43_CaloIdL, &b_HLT_Mu43NoFiltersNoVtxDisplaced_Photon43_CaloIdL);
   fChain->SetBranchAddress("HLT_DoubleMu33NoFiltersNoVtxDisplaced", &HLT_DoubleMu33NoFiltersNoVtxDisplaced, &b_HLT_DoubleMu33NoFiltersNoVtxDisplaced);
   fChain->SetBranchAddress("HLT_DoubleMu40NoFiltersNoVtxDisplaced", &HLT_DoubleMu40NoFiltersNoVtxDisplaced, &b_HLT_DoubleMu40NoFiltersNoVtxDisplaced);
   fChain->SetBranchAddress("HLT_DoubleMu20_7_Mass0to30_L1_DM4", &HLT_DoubleMu20_7_Mass0to30_L1_DM4, &b_HLT_DoubleMu20_7_Mass0to30_L1_DM4);
   fChain->SetBranchAddress("HLT_DoubleMu20_7_Mass0to30_L1_DM4EG", &HLT_DoubleMu20_7_Mass0to30_L1_DM4EG, &b_HLT_DoubleMu20_7_Mass0to30_L1_DM4EG);
   fChain->SetBranchAddress("HLT_HT425", &HLT_HT425, &b_HLT_HT425);
   fChain->SetBranchAddress("HLT_HT430_DisplacedDijet40_DisplacedTrack", &HLT_HT430_DisplacedDijet40_DisplacedTrack, &b_HLT_HT430_DisplacedDijet40_DisplacedTrack);
   fChain->SetBranchAddress("HLT_HT500_DisplacedDijet40_DisplacedTrack", &HLT_HT500_DisplacedDijet40_DisplacedTrack, &b_HLT_HT500_DisplacedDijet40_DisplacedTrack);
   fChain->SetBranchAddress("HLT_HT430_DisplacedDijet60_DisplacedTrack", &HLT_HT430_DisplacedDijet60_DisplacedTrack, &b_HLT_HT430_DisplacedDijet60_DisplacedTrack);
   fChain->SetBranchAddress("HLT_HT400_DisplacedDijet40_DisplacedTrack", &HLT_HT400_DisplacedDijet40_DisplacedTrack, &b_HLT_HT400_DisplacedDijet40_DisplacedTrack);
   fChain->SetBranchAddress("HLT_HT650_DisplacedDijet60_Inclusive", &HLT_HT650_DisplacedDijet60_Inclusive, &b_HLT_HT650_DisplacedDijet60_Inclusive);
   fChain->SetBranchAddress("HLT_HT550_DisplacedDijet60_Inclusive", &HLT_HT550_DisplacedDijet60_Inclusive, &b_HLT_HT550_DisplacedDijet60_Inclusive);
   fChain->SetBranchAddress("HLT_DiJet110_35_Mjj650_PFMET110", &HLT_DiJet110_35_Mjj650_PFMET110, &b_HLT_DiJet110_35_Mjj650_PFMET110);
   fChain->SetBranchAddress("HLT_DiJet110_35_Mjj650_PFMET120", &HLT_DiJet110_35_Mjj650_PFMET120, &b_HLT_DiJet110_35_Mjj650_PFMET120);
   fChain->SetBranchAddress("HLT_DiJet110_35_Mjj650_PFMET130", &HLT_DiJet110_35_Mjj650_PFMET130, &b_HLT_DiJet110_35_Mjj650_PFMET130);
   fChain->SetBranchAddress("HLT_TripleJet110_35_35_Mjj650_PFMET110", &HLT_TripleJet110_35_35_Mjj650_PFMET110, &b_HLT_TripleJet110_35_35_Mjj650_PFMET110);
   fChain->SetBranchAddress("HLT_TripleJet110_35_35_Mjj650_PFMET120", &HLT_TripleJet110_35_35_Mjj650_PFMET120, &b_HLT_TripleJet110_35_35_Mjj650_PFMET120);
   fChain->SetBranchAddress("HLT_TripleJet110_35_35_Mjj650_PFMET130", &HLT_TripleJet110_35_35_Mjj650_PFMET130, &b_HLT_TripleJet110_35_35_Mjj650_PFMET130);
   fChain->SetBranchAddress("HLT_Ele30_eta2p1_WPTight_Gsf_CentralPFJet35_EleCleaned", &HLT_Ele30_eta2p1_WPTight_Gsf_CentralPFJet35_EleCleaned, &b_HLT_Ele30_eta2p1_WPTight_Gsf_CentralPFJet35_EleCleaned);
   fChain->SetBranchAddress("HLT_Ele28_eta2p1_WPTight_Gsf_HT150", &HLT_Ele28_eta2p1_WPTight_Gsf_HT150, &b_HLT_Ele28_eta2p1_WPTight_Gsf_HT150);
   fChain->SetBranchAddress("HLT_Ele28_HighEta_SC20_Mass55", &HLT_Ele28_HighEta_SC20_Mass55, &b_HLT_Ele28_HighEta_SC20_Mass55);
   fChain->SetBranchAddress("HLT_DoubleMu20_7_Mass0to30_Photon23", &HLT_DoubleMu20_7_Mass0to30_Photon23, &b_HLT_DoubleMu20_7_Mass0to30_Photon23);
   fChain->SetBranchAddress("HLT_Ele15_IsoVVVL_PFHT450_CaloBTagDeepCSV_4p5", &HLT_Ele15_IsoVVVL_PFHT450_CaloBTagDeepCSV_4p5, &b_HLT_Ele15_IsoVVVL_PFHT450_CaloBTagDeepCSV_4p5);
   fChain->SetBranchAddress("HLT_Ele15_IsoVVVL_PFHT450_PFMET50", &HLT_Ele15_IsoVVVL_PFHT450_PFMET50, &b_HLT_Ele15_IsoVVVL_PFHT450_PFMET50);
   fChain->SetBranchAddress("HLT_Ele15_IsoVVVL_PFHT450", &HLT_Ele15_IsoVVVL_PFHT450, &b_HLT_Ele15_IsoVVVL_PFHT450);
   fChain->SetBranchAddress("HLT_Ele50_IsoVVVL_PFHT450", &HLT_Ele50_IsoVVVL_PFHT450, &b_HLT_Ele50_IsoVVVL_PFHT450);
   fChain->SetBranchAddress("HLT_Ele15_IsoVVVL_PFHT600", &HLT_Ele15_IsoVVVL_PFHT600, &b_HLT_Ele15_IsoVVVL_PFHT600);
   fChain->SetBranchAddress("HLT_Mu4_TrkIsoVVL_DiPFJet90_40_DEta3p5_MJJ750_HTT300_PFMETNoMu60", &HLT_Mu4_TrkIsoVVL_DiPFJet90_40_DEta3p5_MJJ750_HTT300_PFMETNoMu60, &b_HLT_Mu4_TrkIsoVVL_DiPFJet90_40_DEta3p5_MJJ750_HTT300_PFMETNoMu60);
   fChain->SetBranchAddress("HLT_Mu8_TrkIsoVVL_DiPFJet40_DEta3p5_MJJ750_HTT300_PFMETNoMu60", &HLT_Mu8_TrkIsoVVL_DiPFJet40_DEta3p5_MJJ750_HTT300_PFMETNoMu60, &b_HLT_Mu8_TrkIsoVVL_DiPFJet40_DEta3p5_MJJ750_HTT300_PFMETNoMu60);
   fChain->SetBranchAddress("HLT_Mu10_TrkIsoVVL_DiPFJet40_DEta3p5_MJJ750_HTT350_PFMETNoMu60", &HLT_Mu10_TrkIsoVVL_DiPFJet40_DEta3p5_MJJ750_HTT350_PFMETNoMu60, &b_HLT_Mu10_TrkIsoVVL_DiPFJet40_DEta3p5_MJJ750_HTT350_PFMETNoMu60);
   fChain->SetBranchAddress("HLT_Mu15_IsoVVVL_PFHT450_CaloBTagDeepCSV_4p5", &HLT_Mu15_IsoVVVL_PFHT450_CaloBTagDeepCSV_4p5, &b_HLT_Mu15_IsoVVVL_PFHT450_CaloBTagDeepCSV_4p5);
   fChain->SetBranchAddress("HLT_Mu15_IsoVVVL_PFHT450_PFMET50", &HLT_Mu15_IsoVVVL_PFHT450_PFMET50, &b_HLT_Mu15_IsoVVVL_PFHT450_PFMET50);
   fChain->SetBranchAddress("HLT_Mu15_IsoVVVL_PFHT450", &HLT_Mu15_IsoVVVL_PFHT450, &b_HLT_Mu15_IsoVVVL_PFHT450);
   fChain->SetBranchAddress("HLT_Mu50_IsoVVVL_PFHT450", &HLT_Mu50_IsoVVVL_PFHT450, &b_HLT_Mu50_IsoVVVL_PFHT450);
   fChain->SetBranchAddress("HLT_Mu15_IsoVVVL_PFHT600", &HLT_Mu15_IsoVVVL_PFHT600, &b_HLT_Mu15_IsoVVVL_PFHT600);
   fChain->SetBranchAddress("HLT_Mu3er1p5_PFJet100er2p5_PFMET70_PFMHT70_IDTight", &HLT_Mu3er1p5_PFJet100er2p5_PFMET70_PFMHT70_IDTight, &b_HLT_Mu3er1p5_PFJet100er2p5_PFMET70_PFMHT70_IDTight);
   fChain->SetBranchAddress("HLT_Mu3er1p5_PFJet100er2p5_PFMET80_PFMHT80_IDTight", &HLT_Mu3er1p5_PFJet100er2p5_PFMET80_PFMHT80_IDTight, &b_HLT_Mu3er1p5_PFJet100er2p5_PFMET80_PFMHT80_IDTight);
   fChain->SetBranchAddress("HLT_Mu3er1p5_PFJet100er2p5_PFMET90_PFMHT90_IDTight", &HLT_Mu3er1p5_PFJet100er2p5_PFMET90_PFMHT90_IDTight, &b_HLT_Mu3er1p5_PFJet100er2p5_PFMET90_PFMHT90_IDTight);
   fChain->SetBranchAddress("HLT_Mu3er1p5_PFJet100er2p5_PFMET100_PFMHT100_IDTight", &HLT_Mu3er1p5_PFJet100er2p5_PFMET100_PFMHT100_IDTight, &b_HLT_Mu3er1p5_PFJet100er2p5_PFMET100_PFMHT100_IDTight);
   fChain->SetBranchAddress("HLT_Mu3er1p5_PFJet100er2p5_PFMETNoMu70_PFMHTNoMu70_IDTight", &HLT_Mu3er1p5_PFJet100er2p5_PFMETNoMu70_PFMHTNoMu70_IDTight, &b_HLT_Mu3er1p5_PFJet100er2p5_PFMETNoMu70_PFMHTNoMu70_IDTight);
   fChain->SetBranchAddress("HLT_Mu3er1p5_PFJet100er2p5_PFMETNoMu80_PFMHTNoMu80_IDTight", &HLT_Mu3er1p5_PFJet100er2p5_PFMETNoMu80_PFMHTNoMu80_IDTight, &b_HLT_Mu3er1p5_PFJet100er2p5_PFMETNoMu80_PFMHTNoMu80_IDTight);
   fChain->SetBranchAddress("HLT_Mu3er1p5_PFJet100er2p5_PFMETNoMu90_PFMHTNoMu90_IDTight", &HLT_Mu3er1p5_PFJet100er2p5_PFMETNoMu90_PFMHTNoMu90_IDTight, &b_HLT_Mu3er1p5_PFJet100er2p5_PFMETNoMu90_PFMHTNoMu90_IDTight);
   fChain->SetBranchAddress("HLT_Mu3er1p5_PFJet100er2p5_PFMETNoMu100_PFMHTNoMu100_IDTight", &HLT_Mu3er1p5_PFJet100er2p5_PFMETNoMu100_PFMHTNoMu100_IDTight, &b_HLT_Mu3er1p5_PFJet100er2p5_PFMETNoMu100_PFMHTNoMu100_IDTight);
   fChain->SetBranchAddress("HLT_Dimuon10_PsiPrime_Barrel_Seagulls", &HLT_Dimuon10_PsiPrime_Barrel_Seagulls, &b_HLT_Dimuon10_PsiPrime_Barrel_Seagulls);
   fChain->SetBranchAddress("HLT_Dimuon20_Jpsi_Barrel_Seagulls", &HLT_Dimuon20_Jpsi_Barrel_Seagulls, &b_HLT_Dimuon20_Jpsi_Barrel_Seagulls);
   fChain->SetBranchAddress("HLT_Dimuon12_Upsilon_y1p4", &HLT_Dimuon12_Upsilon_y1p4, &b_HLT_Dimuon12_Upsilon_y1p4);
   fChain->SetBranchAddress("HLT_Dimuon14_Phi_Barrel_Seagulls", &HLT_Dimuon14_Phi_Barrel_Seagulls, &b_HLT_Dimuon14_Phi_Barrel_Seagulls);
   fChain->SetBranchAddress("HLT_Dimuon18_PsiPrime", &HLT_Dimuon18_PsiPrime, &b_HLT_Dimuon18_PsiPrime);
   fChain->SetBranchAddress("HLT_Dimuon25_Jpsi", &HLT_Dimuon25_Jpsi, &b_HLT_Dimuon25_Jpsi);
   fChain->SetBranchAddress("HLT_Dimuon18_PsiPrime_noCorrL1", &HLT_Dimuon18_PsiPrime_noCorrL1, &b_HLT_Dimuon18_PsiPrime_noCorrL1);
   fChain->SetBranchAddress("HLT_Dimuon24_Upsilon_noCorrL1", &HLT_Dimuon24_Upsilon_noCorrL1, &b_HLT_Dimuon24_Upsilon_noCorrL1);
   fChain->SetBranchAddress("HLT_Dimuon24_Phi_noCorrL1", &HLT_Dimuon24_Phi_noCorrL1, &b_HLT_Dimuon24_Phi_noCorrL1);
   fChain->SetBranchAddress("HLT_Dimuon25_Jpsi_noCorrL1", &HLT_Dimuon25_Jpsi_noCorrL1, &b_HLT_Dimuon25_Jpsi_noCorrL1);
   fChain->SetBranchAddress("HLT_DiMu4_Ele9_CaloIdL_TrackIdL_DZ_Mass3p8", &HLT_DiMu4_Ele9_CaloIdL_TrackIdL_DZ_Mass3p8, &b_HLT_DiMu4_Ele9_CaloIdL_TrackIdL_DZ_Mass3p8);
   fChain->SetBranchAddress("HLT_DiMu9_Ele9_CaloIdL_TrackIdL_DZ", &HLT_DiMu9_Ele9_CaloIdL_TrackIdL_DZ, &b_HLT_DiMu9_Ele9_CaloIdL_TrackIdL_DZ);
   fChain->SetBranchAddress("HLT_DiMu9_Ele9_CaloIdL_TrackIdL", &HLT_DiMu9_Ele9_CaloIdL_TrackIdL, &b_HLT_DiMu9_Ele9_CaloIdL_TrackIdL);
   fChain->SetBranchAddress("HLT_DoubleIsoMu20_eta2p1", &HLT_DoubleIsoMu20_eta2p1, &b_HLT_DoubleIsoMu20_eta2p1);
   fChain->SetBranchAddress("HLT_TrkMu12_DoubleTrkMu5NoFiltersNoVtx", &HLT_TrkMu12_DoubleTrkMu5NoFiltersNoVtx, &b_HLT_TrkMu12_DoubleTrkMu5NoFiltersNoVtx);
   fChain->SetBranchAddress("HLT_TrkMu16_DoubleTrkMu6NoFiltersNoVtx", &HLT_TrkMu16_DoubleTrkMu6NoFiltersNoVtx, &b_HLT_TrkMu16_DoubleTrkMu6NoFiltersNoVtx);
   fChain->SetBranchAddress("HLT_TrkMu17_DoubleTrkMu8NoFiltersNoVtx", &HLT_TrkMu17_DoubleTrkMu8NoFiltersNoVtx, &b_HLT_TrkMu17_DoubleTrkMu8NoFiltersNoVtx);
   fChain->SetBranchAddress("HLT_Mu8", &HLT_Mu8, &b_HLT_Mu8);
   fChain->SetBranchAddress("HLT_Mu17", &HLT_Mu17, &b_HLT_Mu17);
   fChain->SetBranchAddress("HLT_Mu19", &HLT_Mu19, &b_HLT_Mu19);
   fChain->SetBranchAddress("HLT_Mu17_Photon30_IsoCaloId", &HLT_Mu17_Photon30_IsoCaloId, &b_HLT_Mu17_Photon30_IsoCaloId);
   fChain->SetBranchAddress("HLT_Ele8_CaloIdL_TrackIdL_IsoVL_PFJet30", &HLT_Ele8_CaloIdL_TrackIdL_IsoVL_PFJet30, &b_HLT_Ele8_CaloIdL_TrackIdL_IsoVL_PFJet30);
   fChain->SetBranchAddress("HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30", &HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30, &b_HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30);
   fChain->SetBranchAddress("HLT_Ele15_CaloIdL_TrackIdL_IsoVL_PFJet30", &HLT_Ele15_CaloIdL_TrackIdL_IsoVL_PFJet30, &b_HLT_Ele15_CaloIdL_TrackIdL_IsoVL_PFJet30);
   fChain->SetBranchAddress("HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30", &HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30, &b_HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30);
   fChain->SetBranchAddress("HLT_Ele8_CaloIdM_TrackIdM_PFJet30", &HLT_Ele8_CaloIdM_TrackIdM_PFJet30, &b_HLT_Ele8_CaloIdM_TrackIdM_PFJet30);
   fChain->SetBranchAddress("HLT_Ele17_CaloIdM_TrackIdM_PFJet30", &HLT_Ele17_CaloIdM_TrackIdM_PFJet30, &b_HLT_Ele17_CaloIdM_TrackIdM_PFJet30);
   fChain->SetBranchAddress("HLT_Ele23_CaloIdM_TrackIdM_PFJet30", &HLT_Ele23_CaloIdM_TrackIdM_PFJet30, &b_HLT_Ele23_CaloIdM_TrackIdM_PFJet30);
   fChain->SetBranchAddress("HLT_Ele50_CaloIdVT_GsfTrkIdT_PFJet165", &HLT_Ele50_CaloIdVT_GsfTrkIdT_PFJet165, &b_HLT_Ele50_CaloIdVT_GsfTrkIdT_PFJet165);
   fChain->SetBranchAddress("HLT_Ele115_CaloIdVT_GsfTrkIdT", &HLT_Ele115_CaloIdVT_GsfTrkIdT, &b_HLT_Ele115_CaloIdVT_GsfTrkIdT);
   fChain->SetBranchAddress("HLT_Ele135_CaloIdVT_GsfTrkIdT", &HLT_Ele135_CaloIdVT_GsfTrkIdT, &b_HLT_Ele135_CaloIdVT_GsfTrkIdT);
   fChain->SetBranchAddress("HLT_Ele145_CaloIdVT_GsfTrkIdT", &HLT_Ele145_CaloIdVT_GsfTrkIdT, &b_HLT_Ele145_CaloIdVT_GsfTrkIdT);
   fChain->SetBranchAddress("HLT_Ele200_CaloIdVT_GsfTrkIdT", &HLT_Ele200_CaloIdVT_GsfTrkIdT, &b_HLT_Ele200_CaloIdVT_GsfTrkIdT);
   fChain->SetBranchAddress("HLT_Ele250_CaloIdVT_GsfTrkIdT", &HLT_Ele250_CaloIdVT_GsfTrkIdT, &b_HLT_Ele250_CaloIdVT_GsfTrkIdT);
   fChain->SetBranchAddress("HLT_Ele300_CaloIdVT_GsfTrkIdT", &HLT_Ele300_CaloIdVT_GsfTrkIdT, &b_HLT_Ele300_CaloIdVT_GsfTrkIdT);
   fChain->SetBranchAddress("HLT_PFHT330PT30_QuadPFJet_75_60_45_40_TriplePFBTagDeepCSV_4p5", &HLT_PFHT330PT30_QuadPFJet_75_60_45_40_TriplePFBTagDeepCSV_4p5, &b_HLT_PFHT330PT30_QuadPFJet_75_60_45_40_TriplePFBTagDeepCSV_4p5);
   fChain->SetBranchAddress("HLT_PFHT330PT30_QuadPFJet_75_60_45_40", &HLT_PFHT330PT30_QuadPFJet_75_60_45_40, &b_HLT_PFHT330PT30_QuadPFJet_75_60_45_40);
   fChain->SetBranchAddress("HLT_PFHT400_SixPFJet32_DoublePFBTagDeepCSV_2p94", &HLT_PFHT400_SixPFJet32_DoublePFBTagDeepCSV_2p94, &b_HLT_PFHT400_SixPFJet32_DoublePFBTagDeepCSV_2p94);
   fChain->SetBranchAddress("HLT_PFHT400_SixPFJet32", &HLT_PFHT400_SixPFJet32, &b_HLT_PFHT400_SixPFJet32);
   fChain->SetBranchAddress("HLT_PFHT450_SixPFJet36_PFBTagDeepCSV_1p59", &HLT_PFHT450_SixPFJet36_PFBTagDeepCSV_1p59, &b_HLT_PFHT450_SixPFJet36_PFBTagDeepCSV_1p59);
   fChain->SetBranchAddress("HLT_PFHT450_SixPFJet36", &HLT_PFHT450_SixPFJet36, &b_HLT_PFHT450_SixPFJet36);
   fChain->SetBranchAddress("HLT_PFHT400_FivePFJet_100_100_60_30_30", &HLT_PFHT400_FivePFJet_100_100_60_30_30, &b_HLT_PFHT400_FivePFJet_100_100_60_30_30);
   fChain->SetBranchAddress("HLT_PFHT400_FivePFJet_100_100_60_30_30_DoublePFBTagDeepCSV_4p5", &HLT_PFHT400_FivePFJet_100_100_60_30_30_DoublePFBTagDeepCSV_4p5, &b_HLT_PFHT400_FivePFJet_100_100_60_30_30_DoublePFBTagDeepCSV_4p5);
   fChain->SetBranchAddress("HLT_PFHT400_FivePFJet_120_120_60_30_30_DoublePFBTagDeepCSV_4p5", &HLT_PFHT400_FivePFJet_120_120_60_30_30_DoublePFBTagDeepCSV_4p5, &b_HLT_PFHT400_FivePFJet_120_120_60_30_30_DoublePFBTagDeepCSV_4p5);
   fChain->SetBranchAddress("HLT_PFHT350", &HLT_PFHT350, &b_HLT_PFHT350);
   fChain->SetBranchAddress("HLT_PFHT350MinPFJet15", &HLT_PFHT350MinPFJet15, &b_HLT_PFHT350MinPFJet15);
   fChain->SetBranchAddress("HLT_Photon60_R9Id90_CaloIdL_IsoL", &HLT_Photon60_R9Id90_CaloIdL_IsoL, &b_HLT_Photon60_R9Id90_CaloIdL_IsoL);
   fChain->SetBranchAddress("HLT_Photon60_R9Id90_CaloIdL_IsoL_DisplacedIdL", &HLT_Photon60_R9Id90_CaloIdL_IsoL_DisplacedIdL, &b_HLT_Photon60_R9Id90_CaloIdL_IsoL_DisplacedIdL);
   fChain->SetBranchAddress("HLT_Photon60_R9Id90_CaloIdL_IsoL_DisplacedIdL_PFHT350MinPFJet15", &HLT_Photon60_R9Id90_CaloIdL_IsoL_DisplacedIdL_PFHT350MinPFJet15, &b_HLT_Photon60_R9Id90_CaloIdL_IsoL_DisplacedIdL_PFHT350MinPFJet15);
   fChain->SetBranchAddress("HLT_ECALHT800", &HLT_ECALHT800, &b_HLT_ECALHT800);
   fChain->SetBranchAddress("HLT_DiSC30_18_EIso_AND_HE_Mass70", &HLT_DiSC30_18_EIso_AND_HE_Mass70, &b_HLT_DiSC30_18_EIso_AND_HE_Mass70);
   fChain->SetBranchAddress("HLT_Physics", &HLT_Physics, &b_HLT_Physics);
   fChain->SetBranchAddress("HLT_Physics_part0", &HLT_Physics_part0, &b_HLT_Physics_part0);
   fChain->SetBranchAddress("HLT_Physics_part1", &HLT_Physics_part1, &b_HLT_Physics_part1);
   fChain->SetBranchAddress("HLT_Physics_part2", &HLT_Physics_part2, &b_HLT_Physics_part2);
   fChain->SetBranchAddress("HLT_Physics_part3", &HLT_Physics_part3, &b_HLT_Physics_part3);
   fChain->SetBranchAddress("HLT_Physics_part4", &HLT_Physics_part4, &b_HLT_Physics_part4);
   fChain->SetBranchAddress("HLT_Physics_part5", &HLT_Physics_part5, &b_HLT_Physics_part5);
   fChain->SetBranchAddress("HLT_Physics_part6", &HLT_Physics_part6, &b_HLT_Physics_part6);
   fChain->SetBranchAddress("HLT_Physics_part7", &HLT_Physics_part7, &b_HLT_Physics_part7);
   fChain->SetBranchAddress("HLT_Random", &HLT_Random, &b_HLT_Random);
   */
   fChain->SetBranchAddress("HLT_ZeroBias", &HLT_ZeroBias, &b_HLT_ZeroBias);
   /*
   fChain->SetBranchAddress("HLT_ZeroBias_Alignment", &HLT_ZeroBias_Alignment, &b_HLT_ZeroBias_Alignment);
   fChain->SetBranchAddress("HLT_ZeroBias_part0", &HLT_ZeroBias_part0, &b_HLT_ZeroBias_part0);
   fChain->SetBranchAddress("HLT_ZeroBias_part1", &HLT_ZeroBias_part1, &b_HLT_ZeroBias_part1);
   fChain->SetBranchAddress("HLT_ZeroBias_part2", &HLT_ZeroBias_part2, &b_HLT_ZeroBias_part2);
   fChain->SetBranchAddress("HLT_ZeroBias_part3", &HLT_ZeroBias_part3, &b_HLT_ZeroBias_part3);
   fChain->SetBranchAddress("HLT_ZeroBias_part4", &HLT_ZeroBias_part4, &b_HLT_ZeroBias_part4);
   fChain->SetBranchAddress("HLT_ZeroBias_part5", &HLT_ZeroBias_part5, &b_HLT_ZeroBias_part5);
   fChain->SetBranchAddress("HLT_ZeroBias_part6", &HLT_ZeroBias_part6, &b_HLT_ZeroBias_part6);
   fChain->SetBranchAddress("HLT_ZeroBias_part7", &HLT_ZeroBias_part7, &b_HLT_ZeroBias_part7);
   fChain->SetBranchAddress("HLT_AK4CaloJet30", &HLT_AK4CaloJet30, &b_HLT_AK4CaloJet30);
   fChain->SetBranchAddress("HLT_AK4CaloJet40", &HLT_AK4CaloJet40, &b_HLT_AK4CaloJet40);
   fChain->SetBranchAddress("HLT_AK4CaloJet50", &HLT_AK4CaloJet50, &b_HLT_AK4CaloJet50);
   fChain->SetBranchAddress("HLT_AK4CaloJet80", &HLT_AK4CaloJet80, &b_HLT_AK4CaloJet80);
   fChain->SetBranchAddress("HLT_AK4CaloJet100", &HLT_AK4CaloJet100, &b_HLT_AK4CaloJet100);
   fChain->SetBranchAddress("HLT_AK4CaloJet120", &HLT_AK4CaloJet120, &b_HLT_AK4CaloJet120);
   fChain->SetBranchAddress("HLT_AK4PFJet30", &HLT_AK4PFJet30, &b_HLT_AK4PFJet30);
   fChain->SetBranchAddress("HLT_AK4PFJet50", &HLT_AK4PFJet50, &b_HLT_AK4PFJet50);
   fChain->SetBranchAddress("HLT_AK4PFJet80", &HLT_AK4PFJet80, &b_HLT_AK4PFJet80);
   fChain->SetBranchAddress("HLT_AK4PFJet100", &HLT_AK4PFJet100, &b_HLT_AK4PFJet100);
   fChain->SetBranchAddress("HLT_AK4PFJet120", &HLT_AK4PFJet120, &b_HLT_AK4PFJet120);
   fChain->SetBranchAddress("HLT_SinglePhoton10_Eta3p1ForPPRef", &HLT_SinglePhoton10_Eta3p1ForPPRef, &b_HLT_SinglePhoton10_Eta3p1ForPPRef);
   fChain->SetBranchAddress("HLT_SinglePhoton20_Eta3p1ForPPRef", &HLT_SinglePhoton20_Eta3p1ForPPRef, &b_HLT_SinglePhoton20_Eta3p1ForPPRef);
   fChain->SetBranchAddress("HLT_SinglePhoton30_Eta3p1ForPPRef", &HLT_SinglePhoton30_Eta3p1ForPPRef, &b_HLT_SinglePhoton30_Eta3p1ForPPRef);
   fChain->SetBranchAddress("HLT_Photon20_HoverELoose", &HLT_Photon20_HoverELoose, &b_HLT_Photon20_HoverELoose);
   fChain->SetBranchAddress("HLT_Photon30_HoverELoose", &HLT_Photon30_HoverELoose, &b_HLT_Photon30_HoverELoose);
   fChain->SetBranchAddress("HLT_EcalCalibration", &HLT_EcalCalibration, &b_HLT_EcalCalibration);
   fChain->SetBranchAddress("HLT_HcalCalibration", &HLT_HcalCalibration, &b_HLT_HcalCalibration);
   fChain->SetBranchAddress("HLT_L1UnpairedBunchBptxMinus", &HLT_L1UnpairedBunchBptxMinus, &b_HLT_L1UnpairedBunchBptxMinus);
   fChain->SetBranchAddress("HLT_L1UnpairedBunchBptxPlus", &HLT_L1UnpairedBunchBptxPlus, &b_HLT_L1UnpairedBunchBptxPlus);
   fChain->SetBranchAddress("HLT_L1NotBptxOR", &HLT_L1NotBptxOR, &b_HLT_L1NotBptxOR);
   fChain->SetBranchAddress("HLT_L1_CDC_SingleMu_3_er1p2_TOP120_DPHI2p618_3p142", &HLT_L1_CDC_SingleMu_3_er1p2_TOP120_DPHI2p618_3p142, &b_HLT_L1_CDC_SingleMu_3_er1p2_TOP120_DPHI2p618_3p142);
   fChain->SetBranchAddress("HLT_CDC_L2cosmic_10_er1p0", &HLT_CDC_L2cosmic_10_er1p0, &b_HLT_CDC_L2cosmic_10_er1p0);
   fChain->SetBranchAddress("HLT_CDC_L2cosmic_5p5_er1p0", &HLT_CDC_L2cosmic_5p5_er1p0, &b_HLT_CDC_L2cosmic_5p5_er1p0);
   fChain->SetBranchAddress("HLT_HcalNZS", &HLT_HcalNZS, &b_HLT_HcalNZS);
   fChain->SetBranchAddress("HLT_HcalPhiSym", &HLT_HcalPhiSym, &b_HLT_HcalPhiSym);
   fChain->SetBranchAddress("HLT_HcalIsolatedbunch", &HLT_HcalIsolatedbunch, &b_HLT_HcalIsolatedbunch);
   fChain->SetBranchAddress("HLT_IsoTrackHB", &HLT_IsoTrackHB, &b_HLT_IsoTrackHB);
   fChain->SetBranchAddress("HLT_IsoTrackHE", &HLT_IsoTrackHE, &b_HLT_IsoTrackHE);
   fChain->SetBranchAddress("HLT_ZeroBias_FirstCollisionAfterAbortGap", &HLT_ZeroBias_FirstCollisionAfterAbortGap, &b_HLT_ZeroBias_FirstCollisionAfterAbortGap);
   fChain->SetBranchAddress("HLT_ZeroBias_IsolatedBunches", &HLT_ZeroBias_IsolatedBunches, &b_HLT_ZeroBias_IsolatedBunches);
   fChain->SetBranchAddress("HLT_ZeroBias_FirstCollisionInTrain", &HLT_ZeroBias_FirstCollisionInTrain, &b_HLT_ZeroBias_FirstCollisionInTrain);
   fChain->SetBranchAddress("HLT_ZeroBias_LastCollisionInTrain", &HLT_ZeroBias_LastCollisionInTrain, &b_HLT_ZeroBias_LastCollisionInTrain);
   fChain->SetBranchAddress("HLT_ZeroBias_FirstBXAfterTrain", &HLT_ZeroBias_FirstBXAfterTrain, &b_HLT_ZeroBias_FirstBXAfterTrain);
   fChain->SetBranchAddress("HLT_IsoMu24_eta2p1_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr", &HLT_IsoMu24_eta2p1_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr, &b_HLT_IsoMu24_eta2p1_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr);
   fChain->SetBranchAddress("HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr_MET90", &HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr_MET90, &b_HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr_MET90);
   fChain->SetBranchAddress("HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr_MET100", &HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr_MET100, &b_HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr_MET100);
   fChain->SetBranchAddress("HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr_MET110", &HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr_MET110, &b_HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr_MET110);
   fChain->SetBranchAddress("HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr_MET120", &HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr_MET120, &b_HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr_MET120);
   fChain->SetBranchAddress("HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr_MET130", &HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr_MET130, &b_HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr_MET130);
   fChain->SetBranchAddress("HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr_MET140", &HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr_MET140, &b_HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr_MET140);
   fChain->SetBranchAddress("HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr", &HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr, &b_HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr);
   fChain->SetBranchAddress("HLT_MediumChargedIsoPFTau180HighPtRelaxedIso_Trk50_eta2p1_1pr", &HLT_MediumChargedIsoPFTau180HighPtRelaxedIso_Trk50_eta2p1_1pr, &b_HLT_MediumChargedIsoPFTau180HighPtRelaxedIso_Trk50_eta2p1_1pr);
   fChain->SetBranchAddress("HLT_MediumChargedIsoPFTau180HighPtRelaxedIso_Trk50_eta2p1", &HLT_MediumChargedIsoPFTau180HighPtRelaxedIso_Trk50_eta2p1, &b_HLT_MediumChargedIsoPFTau180HighPtRelaxedIso_Trk50_eta2p1);
   fChain->SetBranchAddress("HLT_MediumChargedIsoPFTau200HighPtRelaxedIso_Trk50_eta2p1", &HLT_MediumChargedIsoPFTau200HighPtRelaxedIso_Trk50_eta2p1, &b_HLT_MediumChargedIsoPFTau200HighPtRelaxedIso_Trk50_eta2p1);
   fChain->SetBranchAddress("HLT_MediumChargedIsoPFTau220HighPtRelaxedIso_Trk50_eta2p1", &HLT_MediumChargedIsoPFTau220HighPtRelaxedIso_Trk50_eta2p1, &b_HLT_MediumChargedIsoPFTau220HighPtRelaxedIso_Trk50_eta2p1);
   fChain->SetBranchAddress("HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL", &HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL, &b_HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL);
   fChain->SetBranchAddress("HLT_Rsq0p35", &HLT_Rsq0p35, &b_HLT_Rsq0p35);
   fChain->SetBranchAddress("HLT_Rsq0p40", &HLT_Rsq0p40, &b_HLT_Rsq0p40);
   fChain->SetBranchAddress("HLT_RsqMR300_Rsq0p09_MR200", &HLT_RsqMR300_Rsq0p09_MR200, &b_HLT_RsqMR300_Rsq0p09_MR200);
   fChain->SetBranchAddress("HLT_RsqMR320_Rsq0p09_MR200", &HLT_RsqMR320_Rsq0p09_MR200, &b_HLT_RsqMR320_Rsq0p09_MR200);
   fChain->SetBranchAddress("HLT_RsqMR300_Rsq0p09_MR200_4jet", &HLT_RsqMR300_Rsq0p09_MR200_4jet, &b_HLT_RsqMR300_Rsq0p09_MR200_4jet);
   fChain->SetBranchAddress("HLT_RsqMR320_Rsq0p09_MR200_4jet", &HLT_RsqMR320_Rsq0p09_MR200_4jet, &b_HLT_RsqMR320_Rsq0p09_MR200_4jet);
   fChain->SetBranchAddress("HLT_IsoMu27_MET90", &HLT_IsoMu27_MET90, &b_HLT_IsoMu27_MET90);
   fChain->SetBranchAddress("HLT_DoubleMediumChargedIsoPFTau35_Trk1_eta2p1_Reg", &HLT_DoubleMediumChargedIsoPFTau35_Trk1_eta2p1_Reg, &b_HLT_DoubleMediumChargedIsoPFTau35_Trk1_eta2p1_Reg);
   fChain->SetBranchAddress("HLT_DoubleMediumChargedIsoPFTau35_Trk1_TightID_eta2p1_Reg", &HLT_DoubleMediumChargedIsoPFTau35_Trk1_TightID_eta2p1_Reg, &b_HLT_DoubleMediumChargedIsoPFTau35_Trk1_TightID_eta2p1_Reg);
   fChain->SetBranchAddress("HLT_DoubleTightChargedIsoPFTau35_Trk1_eta2p1_Reg", &HLT_DoubleTightChargedIsoPFTau35_Trk1_eta2p1_Reg, &b_HLT_DoubleTightChargedIsoPFTau35_Trk1_eta2p1_Reg);
   fChain->SetBranchAddress("HLT_DoubleTightChargedIsoPFTau35_Trk1_TightID_eta2p1_Reg", &HLT_DoubleTightChargedIsoPFTau35_Trk1_TightID_eta2p1_Reg, &b_HLT_DoubleTightChargedIsoPFTau35_Trk1_TightID_eta2p1_Reg);
   fChain->SetBranchAddress("HLT_DoubleMediumChargedIsoPFTauHPS30_L1MaxMass_Trk1_eta2p1_Reg", &HLT_DoubleMediumChargedIsoPFTauHPS30_L1MaxMass_Trk1_eta2p1_Reg, &b_HLT_DoubleMediumChargedIsoPFTauHPS30_L1MaxMass_Trk1_eta2p1_Reg);
   fChain->SetBranchAddress("HLT_DoubleTightChargedIsoPFTauHPS35_Trk1_eta2p1_Reg", &HLT_DoubleTightChargedIsoPFTauHPS35_Trk1_eta2p1_Reg, &b_HLT_DoubleTightChargedIsoPFTauHPS35_Trk1_eta2p1_Reg);
   fChain->SetBranchAddress("HLT_DoubleMediumChargedIsoPFTauHPS35_Trk1_TightID_eta2p1_Reg", &HLT_DoubleMediumChargedIsoPFTauHPS35_Trk1_TightID_eta2p1_Reg, &b_HLT_DoubleMediumChargedIsoPFTauHPS35_Trk1_TightID_eta2p1_Reg);
   fChain->SetBranchAddress("HLT_DoubleMediumChargedIsoPFTauHPS35_Trk1_eta2p1_Reg", &HLT_DoubleMediumChargedIsoPFTauHPS35_Trk1_eta2p1_Reg, &b_HLT_DoubleMediumChargedIsoPFTauHPS35_Trk1_eta2p1_Reg);
   fChain->SetBranchAddress("HLT_DoubleTightChargedIsoPFTauHPS35_Trk1_TightID_eta2p1_Reg", &HLT_DoubleTightChargedIsoPFTauHPS35_Trk1_TightID_eta2p1_Reg, &b_HLT_DoubleTightChargedIsoPFTauHPS35_Trk1_TightID_eta2p1_Reg);
   fChain->SetBranchAddress("HLT_DoubleMediumChargedIsoPFTauHPS40_Trk1_eta2p1_Reg", &HLT_DoubleMediumChargedIsoPFTauHPS40_Trk1_eta2p1_Reg, &b_HLT_DoubleMediumChargedIsoPFTauHPS40_Trk1_eta2p1_Reg);
   fChain->SetBranchAddress("HLT_DoubleTightChargedIsoPFTauHPS40_Trk1_eta2p1_Reg", &HLT_DoubleTightChargedIsoPFTauHPS40_Trk1_eta2p1_Reg, &b_HLT_DoubleTightChargedIsoPFTauHPS40_Trk1_eta2p1_Reg);
   fChain->SetBranchAddress("HLT_DoubleMediumChargedIsoPFTauHPS40_Trk1_TightID_eta2p1_Reg", &HLT_DoubleMediumChargedIsoPFTauHPS40_Trk1_TightID_eta2p1_Reg, &b_HLT_DoubleMediumChargedIsoPFTauHPS40_Trk1_TightID_eta2p1_Reg);
   fChain->SetBranchAddress("HLT_DoubleTightChargedIsoPFTauHPS40_Trk1_TightID_eta2p1_Reg", &HLT_DoubleTightChargedIsoPFTauHPS40_Trk1_TightID_eta2p1_Reg, &b_HLT_DoubleTightChargedIsoPFTauHPS40_Trk1_TightID_eta2p1_Reg);
   fChain->SetBranchAddress("HLT_VBF_DoubleLooseChargedIsoPFTau20_Trk1_eta2p1", &HLT_VBF_DoubleLooseChargedIsoPFTau20_Trk1_eta2p1, &b_HLT_VBF_DoubleLooseChargedIsoPFTau20_Trk1_eta2p1);
   fChain->SetBranchAddress("HLT_VBF_DoubleLooseChargedIsoPFTauHPS20_Trk1_eta2p1", &HLT_VBF_DoubleLooseChargedIsoPFTauHPS20_Trk1_eta2p1, &b_HLT_VBF_DoubleLooseChargedIsoPFTauHPS20_Trk1_eta2p1);
   fChain->SetBranchAddress("HLT_VBF_DoubleMediumChargedIsoPFTauHPS20_Trk1_eta2p1", &HLT_VBF_DoubleMediumChargedIsoPFTauHPS20_Trk1_eta2p1, &b_HLT_VBF_DoubleMediumChargedIsoPFTauHPS20_Trk1_eta2p1);
   fChain->SetBranchAddress("HLT_VBF_DoubleTightChargedIsoPFTauHPS20_Trk1_eta2p1", &HLT_VBF_DoubleTightChargedIsoPFTauHPS20_Trk1_eta2p1, &b_HLT_VBF_DoubleTightChargedIsoPFTauHPS20_Trk1_eta2p1);
   fChain->SetBranchAddress("HLT_Photon50_R9Id90_HE10_IsoM_EBOnly_PFJetsMJJ300DEta3_PFMET50", &HLT_Photon50_R9Id90_HE10_IsoM_EBOnly_PFJetsMJJ300DEta3_PFMET50, &b_HLT_Photon50_R9Id90_HE10_IsoM_EBOnly_PFJetsMJJ300DEta3_PFMET50);
   fChain->SetBranchAddress("HLT_Photon75_R9Id90_HE10_IsoM_EBOnly_PFJetsMJJ300DEta3", &HLT_Photon75_R9Id90_HE10_IsoM_EBOnly_PFJetsMJJ300DEta3, &b_HLT_Photon75_R9Id90_HE10_IsoM_EBOnly_PFJetsMJJ300DEta3);
   fChain->SetBranchAddress("HLT_Photon75_R9Id90_HE10_IsoM_EBOnly_PFJetsMJJ600DEta3", &HLT_Photon75_R9Id90_HE10_IsoM_EBOnly_PFJetsMJJ600DEta3, &b_HLT_Photon75_R9Id90_HE10_IsoM_EBOnly_PFJetsMJJ600DEta3);
   fChain->SetBranchAddress("HLT_PFMET100_PFMHT100_IDTight_PFHT60", &HLT_PFMET100_PFMHT100_IDTight_PFHT60, &b_HLT_PFMET100_PFMHT100_IDTight_PFHT60);
   fChain->SetBranchAddress("HLT_PFMETNoMu100_PFMHTNoMu100_IDTight_PFHT60", &HLT_PFMETNoMu100_PFMHTNoMu100_IDTight_PFHT60, &b_HLT_PFMETNoMu100_PFMHTNoMu100_IDTight_PFHT60);
   fChain->SetBranchAddress("HLT_PFMETTypeOne100_PFMHT100_IDTight_PFHT60", &HLT_PFMETTypeOne100_PFMHT100_IDTight_PFHT60, &b_HLT_PFMETTypeOne100_PFMHT100_IDTight_PFHT60);
   fChain->SetBranchAddress("HLT_Mu18_Mu9_SameSign", &HLT_Mu18_Mu9_SameSign, &b_HLT_Mu18_Mu9_SameSign);
   fChain->SetBranchAddress("HLT_Mu18_Mu9_SameSign_DZ", &HLT_Mu18_Mu9_SameSign_DZ, &b_HLT_Mu18_Mu9_SameSign_DZ);
   fChain->SetBranchAddress("HLT_Mu18_Mu9", &HLT_Mu18_Mu9, &b_HLT_Mu18_Mu9);
   fChain->SetBranchAddress("HLT_Mu18_Mu9_DZ", &HLT_Mu18_Mu9_DZ, &b_HLT_Mu18_Mu9_DZ);
   fChain->SetBranchAddress("HLT_Mu20_Mu10_SameSign", &HLT_Mu20_Mu10_SameSign, &b_HLT_Mu20_Mu10_SameSign);
   fChain->SetBranchAddress("HLT_Mu20_Mu10_SameSign_DZ", &HLT_Mu20_Mu10_SameSign_DZ, &b_HLT_Mu20_Mu10_SameSign_DZ);
   fChain->SetBranchAddress("HLT_Mu20_Mu10", &HLT_Mu20_Mu10, &b_HLT_Mu20_Mu10);
   fChain->SetBranchAddress("HLT_Mu20_Mu10_DZ", &HLT_Mu20_Mu10_DZ, &b_HLT_Mu20_Mu10_DZ);
   fChain->SetBranchAddress("HLT_Mu23_Mu12_SameSign", &HLT_Mu23_Mu12_SameSign, &b_HLT_Mu23_Mu12_SameSign);
   fChain->SetBranchAddress("HLT_Mu23_Mu12_SameSign_DZ", &HLT_Mu23_Mu12_SameSign_DZ, &b_HLT_Mu23_Mu12_SameSign_DZ);
   fChain->SetBranchAddress("HLT_Mu23_Mu12", &HLT_Mu23_Mu12, &b_HLT_Mu23_Mu12);
   fChain->SetBranchAddress("HLT_Mu23_Mu12_DZ", &HLT_Mu23_Mu12_DZ, &b_HLT_Mu23_Mu12_DZ);
   fChain->SetBranchAddress("HLT_DoubleMu2_Jpsi_DoubleTrk1_Phi1p05", &HLT_DoubleMu2_Jpsi_DoubleTrk1_Phi1p05, &b_HLT_DoubleMu2_Jpsi_DoubleTrk1_Phi1p05);
   fChain->SetBranchAddress("HLT_DoubleMu2_Jpsi_DoubleTkMu0_Phi", &HLT_DoubleMu2_Jpsi_DoubleTkMu0_Phi, &b_HLT_DoubleMu2_Jpsi_DoubleTkMu0_Phi);
   fChain->SetBranchAddress("HLT_DoubleMu3_DCA_PFMET50_PFMHT60", &HLT_DoubleMu3_DCA_PFMET50_PFMHT60, &b_HLT_DoubleMu3_DCA_PFMET50_PFMHT60);
   fChain->SetBranchAddress("HLT_TripleMu_5_3_3_Mass3p8_DCA", &HLT_TripleMu_5_3_3_Mass3p8_DCA, &b_HLT_TripleMu_5_3_3_Mass3p8_DCA);
   fChain->SetBranchAddress("HLT_QuadPFJet98_83_71_15_DoublePFBTagDeepCSV_1p3_7p7_VBF1", &HLT_QuadPFJet98_83_71_15_DoublePFBTagDeepCSV_1p3_7p7_VBF1, &b_HLT_QuadPFJet98_83_71_15_DoublePFBTagDeepCSV_1p3_7p7_VBF1);
   fChain->SetBranchAddress("HLT_QuadPFJet103_88_75_15_DoublePFBTagDeepCSV_1p3_7p7_VBF1", &HLT_QuadPFJet103_88_75_15_DoublePFBTagDeepCSV_1p3_7p7_VBF1, &b_HLT_QuadPFJet103_88_75_15_DoublePFBTagDeepCSV_1p3_7p7_VBF1);
   fChain->SetBranchAddress("HLT_QuadPFJet111_90_80_15_DoublePFBTagDeepCSV_1p3_7p7_VBF1", &HLT_QuadPFJet111_90_80_15_DoublePFBTagDeepCSV_1p3_7p7_VBF1, &b_HLT_QuadPFJet111_90_80_15_DoublePFBTagDeepCSV_1p3_7p7_VBF1);
   fChain->SetBranchAddress("HLT_QuadPFJet98_83_71_15_PFBTagDeepCSV_1p3_VBF2", &HLT_QuadPFJet98_83_71_15_PFBTagDeepCSV_1p3_VBF2, &b_HLT_QuadPFJet98_83_71_15_PFBTagDeepCSV_1p3_VBF2);
   fChain->SetBranchAddress("HLT_QuadPFJet103_88_75_15_PFBTagDeepCSV_1p3_VBF2", &HLT_QuadPFJet103_88_75_15_PFBTagDeepCSV_1p3_VBF2, &b_HLT_QuadPFJet103_88_75_15_PFBTagDeepCSV_1p3_VBF2);
   fChain->SetBranchAddress("HLT_QuadPFJet105_88_76_15_PFBTagDeepCSV_1p3_VBF2", &HLT_QuadPFJet105_88_76_15_PFBTagDeepCSV_1p3_VBF2, &b_HLT_QuadPFJet105_88_76_15_PFBTagDeepCSV_1p3_VBF2);
   fChain->SetBranchAddress("HLT_QuadPFJet111_90_80_15_PFBTagDeepCSV_1p3_VBF2", &HLT_QuadPFJet111_90_80_15_PFBTagDeepCSV_1p3_VBF2, &b_HLT_QuadPFJet111_90_80_15_PFBTagDeepCSV_1p3_VBF2);
   fChain->SetBranchAddress("HLT_QuadPFJet98_83_71_15", &HLT_QuadPFJet98_83_71_15, &b_HLT_QuadPFJet98_83_71_15);
   fChain->SetBranchAddress("HLT_QuadPFJet103_88_75_15", &HLT_QuadPFJet103_88_75_15, &b_HLT_QuadPFJet103_88_75_15);
   fChain->SetBranchAddress("HLT_QuadPFJet105_88_76_15", &HLT_QuadPFJet105_88_76_15, &b_HLT_QuadPFJet105_88_76_15);
   fChain->SetBranchAddress("HLT_QuadPFJet111_90_80_15", &HLT_QuadPFJet111_90_80_15, &b_HLT_QuadPFJet111_90_80_15);
   fChain->SetBranchAddress("HLT_AK8PFJet330_TrimMass30_PFAK8BTagDeepCSV_p17", &HLT_AK8PFJet330_TrimMass30_PFAK8BTagDeepCSV_p17, &b_HLT_AK8PFJet330_TrimMass30_PFAK8BTagDeepCSV_p17);
   fChain->SetBranchAddress("HLT_AK8PFJet330_TrimMass30_PFAK8BTagDeepCSV_p1", &HLT_AK8PFJet330_TrimMass30_PFAK8BTagDeepCSV_p1, &b_HLT_AK8PFJet330_TrimMass30_PFAK8BTagDeepCSV_p1);
   fChain->SetBranchAddress("HLT_AK8PFJet330_TrimMass30_PFAK8BoostedDoubleB_p02", &HLT_AK8PFJet330_TrimMass30_PFAK8BoostedDoubleB_p02, &b_HLT_AK8PFJet330_TrimMass30_PFAK8BoostedDoubleB_p02);
   fChain->SetBranchAddress("HLT_AK8PFJet330_TrimMass30_PFAK8BoostedDoubleB_np2", &HLT_AK8PFJet330_TrimMass30_PFAK8BoostedDoubleB_np2, &b_HLT_AK8PFJet330_TrimMass30_PFAK8BoostedDoubleB_np2);
   fChain->SetBranchAddress("HLT_AK8PFJet330_TrimMass30_PFAK8BoostedDoubleB_np4", &HLT_AK8PFJet330_TrimMass30_PFAK8BoostedDoubleB_np4, &b_HLT_AK8PFJet330_TrimMass30_PFAK8BoostedDoubleB_np4);
   fChain->SetBranchAddress("HLT_Diphoton30_18_R9IdL_AND_HE_AND_IsoCaloId_NoPixelVeto_Mass55", &HLT_Diphoton30_18_R9IdL_AND_HE_AND_IsoCaloId_NoPixelVeto_Mass55, &b_HLT_Diphoton30_18_R9IdL_AND_HE_AND_IsoCaloId_NoPixelVeto_Mass55);
   fChain->SetBranchAddress("HLT_Diphoton30_18_R9IdL_AND_HE_AND_IsoCaloId_NoPixelVeto", &HLT_Diphoton30_18_R9IdL_AND_HE_AND_IsoCaloId_NoPixelVeto, &b_HLT_Diphoton30_18_R9IdL_AND_HE_AND_IsoCaloId_NoPixelVeto);
   fChain->SetBranchAddress("HLT_Mu12_IP6_ToCSCS", &HLT_Mu12_IP6_ToCSCS, &b_HLT_Mu12_IP6_ToCSCS);
   fChain->SetBranchAddress("HLT_Mu12_IP6_part0", &HLT_Mu12_IP6_part0, &b_HLT_Mu12_IP6_part0);
   fChain->SetBranchAddress("HLT_Mu12_IP6_part1", &HLT_Mu12_IP6_part1, &b_HLT_Mu12_IP6_part1);
   fChain->SetBranchAddress("HLT_Mu12_IP6_part2", &HLT_Mu12_IP6_part2, &b_HLT_Mu12_IP6_part2);
   fChain->SetBranchAddress("HLT_Mu12_IP6_part3", &HLT_Mu12_IP6_part3, &b_HLT_Mu12_IP6_part3);
   fChain->SetBranchAddress("HLT_Mu12_IP6_part4", &HLT_Mu12_IP6_part4, &b_HLT_Mu12_IP6_part4);
   fChain->SetBranchAddress("HLT_Mu9_IP5_ToCSCS", &HLT_Mu9_IP5_ToCSCS, &b_HLT_Mu9_IP5_ToCSCS);
   fChain->SetBranchAddress("HLT_Mu9_IP5_part0", &HLT_Mu9_IP5_part0, &b_HLT_Mu9_IP5_part0);
   fChain->SetBranchAddress("HLT_Mu9_IP5_part1", &HLT_Mu9_IP5_part1, &b_HLT_Mu9_IP5_part1);
   fChain->SetBranchAddress("HLT_Mu9_IP5_part2", &HLT_Mu9_IP5_part2, &b_HLT_Mu9_IP5_part2);
   fChain->SetBranchAddress("HLT_Mu9_IP5_part3", &HLT_Mu9_IP5_part3, &b_HLT_Mu9_IP5_part3);
   fChain->SetBranchAddress("HLT_Mu9_IP5_part4", &HLT_Mu9_IP5_part4, &b_HLT_Mu9_IP5_part4);
   fChain->SetBranchAddress("HLT_Mu7_IP4_ToCSCS", &HLT_Mu7_IP4_ToCSCS, &b_HLT_Mu7_IP4_ToCSCS);
   fChain->SetBranchAddress("HLT_Mu7_IP4_part0", &HLT_Mu7_IP4_part0, &b_HLT_Mu7_IP4_part0);
   fChain->SetBranchAddress("HLT_Mu7_IP4_part1", &HLT_Mu7_IP4_part1, &b_HLT_Mu7_IP4_part1);
   fChain->SetBranchAddress("HLT_Mu7_IP4_part2", &HLT_Mu7_IP4_part2, &b_HLT_Mu7_IP4_part2);
   fChain->SetBranchAddress("HLT_Mu7_IP4_part3", &HLT_Mu7_IP4_part3, &b_HLT_Mu7_IP4_part3);
   fChain->SetBranchAddress("HLT_Mu7_IP4_part4", &HLT_Mu7_IP4_part4, &b_HLT_Mu7_IP4_part4);
   fChain->SetBranchAddress("HLT_Mu9_IP4_ToCSCS", &HLT_Mu9_IP4_ToCSCS, &b_HLT_Mu9_IP4_ToCSCS);
   fChain->SetBranchAddress("HLT_Mu9_IP4_part0", &HLT_Mu9_IP4_part0, &b_HLT_Mu9_IP4_part0);
   fChain->SetBranchAddress("HLT_Mu9_IP4_part1", &HLT_Mu9_IP4_part1, &b_HLT_Mu9_IP4_part1);
   fChain->SetBranchAddress("HLT_Mu9_IP4_part2", &HLT_Mu9_IP4_part2, &b_HLT_Mu9_IP4_part2);
   fChain->SetBranchAddress("HLT_Mu9_IP4_part3", &HLT_Mu9_IP4_part3, &b_HLT_Mu9_IP4_part3);
   fChain->SetBranchAddress("HLT_Mu9_IP4_part4", &HLT_Mu9_IP4_part4, &b_HLT_Mu9_IP4_part4);
   fChain->SetBranchAddress("HLT_Mu8_IP5_ToCSCS", &HLT_Mu8_IP5_ToCSCS, &b_HLT_Mu8_IP5_ToCSCS);
   fChain->SetBranchAddress("HLT_Mu8_IP5_part0", &HLT_Mu8_IP5_part0, &b_HLT_Mu8_IP5_part0);
   fChain->SetBranchAddress("HLT_Mu8_IP5_part1", &HLT_Mu8_IP5_part1, &b_HLT_Mu8_IP5_part1);
   fChain->SetBranchAddress("HLT_Mu8_IP5_part2", &HLT_Mu8_IP5_part2, &b_HLT_Mu8_IP5_part2);
   fChain->SetBranchAddress("HLT_Mu8_IP5_part3", &HLT_Mu8_IP5_part3, &b_HLT_Mu8_IP5_part3);
   fChain->SetBranchAddress("HLT_Mu8_IP5_part4", &HLT_Mu8_IP5_part4, &b_HLT_Mu8_IP5_part4);
   fChain->SetBranchAddress("HLT_Mu8_IP6_ToCSCS", &HLT_Mu8_IP6_ToCSCS, &b_HLT_Mu8_IP6_ToCSCS);
   fChain->SetBranchAddress("HLT_Mu8_IP6_part0", &HLT_Mu8_IP6_part0, &b_HLT_Mu8_IP6_part0);
   fChain->SetBranchAddress("HLT_Mu8_IP6_part1", &HLT_Mu8_IP6_part1, &b_HLT_Mu8_IP6_part1);
   fChain->SetBranchAddress("HLT_Mu8_IP6_part2", &HLT_Mu8_IP6_part2, &b_HLT_Mu8_IP6_part2);
   fChain->SetBranchAddress("HLT_Mu8_IP6_part3", &HLT_Mu8_IP6_part3, &b_HLT_Mu8_IP6_part3);
   fChain->SetBranchAddress("HLT_Mu8_IP6_part4", &HLT_Mu8_IP6_part4, &b_HLT_Mu8_IP6_part4);
   fChain->SetBranchAddress("HLT_Mu9_IP6_ToCSCS", &HLT_Mu9_IP6_ToCSCS, &b_HLT_Mu9_IP6_ToCSCS);
   fChain->SetBranchAddress("HLT_Mu9_IP6_part0", &HLT_Mu9_IP6_part0, &b_HLT_Mu9_IP6_part0);
   fChain->SetBranchAddress("HLT_Mu9_IP6_part1", &HLT_Mu9_IP6_part1, &b_HLT_Mu9_IP6_part1);
   fChain->SetBranchAddress("HLT_Mu9_IP6_part2", &HLT_Mu9_IP6_part2, &b_HLT_Mu9_IP6_part2);
   fChain->SetBranchAddress("HLT_Mu9_IP6_part3", &HLT_Mu9_IP6_part3, &b_HLT_Mu9_IP6_part3);
   fChain->SetBranchAddress("HLT_Mu9_IP6_part4", &HLT_Mu9_IP6_part4, &b_HLT_Mu9_IP6_part4);
   fChain->SetBranchAddress("HLT_Mu8_IP3_ToCSCS", &HLT_Mu8_IP3_ToCSCS, &b_HLT_Mu8_IP3_ToCSCS);
   fChain->SetBranchAddress("HLT_Mu8_IP3_part0", &HLT_Mu8_IP3_part0, &b_HLT_Mu8_IP3_part0);
   fChain->SetBranchAddress("HLT_Mu8_IP3_part1", &HLT_Mu8_IP3_part1, &b_HLT_Mu8_IP3_part1);
   fChain->SetBranchAddress("HLT_Mu8_IP3_part2", &HLT_Mu8_IP3_part2, &b_HLT_Mu8_IP3_part2);
   fChain->SetBranchAddress("HLT_Mu8_IP3_part3", &HLT_Mu8_IP3_part3, &b_HLT_Mu8_IP3_part3);
   fChain->SetBranchAddress("HLT_Mu8_IP3_part4", &HLT_Mu8_IP3_part4, &b_HLT_Mu8_IP3_part4);
   fChain->SetBranchAddress("HLT_Mu9_IP0_part0", &HLT_Mu9_IP0_part0, &b_HLT_Mu9_IP0_part0);
   fChain->SetBranchAddress("HLT_Mu9_IP3_part0", &HLT_Mu9_IP3_part0, &b_HLT_Mu9_IP3_part0);
   fChain->SetBranchAddress("HLT_QuadPFJet105_88_76_15_DoublePFBTagDeepCSV_1p3_7p7_VBF1", &HLT_QuadPFJet105_88_76_15_DoublePFBTagDeepCSV_1p3_7p7_VBF1, &b_HLT_QuadPFJet105_88_76_15_DoublePFBTagDeepCSV_1p3_7p7_VBF1);
   fChain->SetBranchAddress("HLT_TrkMu6NoFiltersNoVtx", &HLT_TrkMu6NoFiltersNoVtx, &b_HLT_TrkMu6NoFiltersNoVtx);
   fChain->SetBranchAddress("HLT_TrkMu16NoFiltersNoVtx", &HLT_TrkMu16NoFiltersNoVtx, &b_HLT_TrkMu16NoFiltersNoVtx);
   fChain->SetBranchAddress("HLT_DoubleTrkMu_16_6_NoFiltersNoVtx", &HLT_DoubleTrkMu_16_6_NoFiltersNoVtx, &b_HLT_DoubleTrkMu_16_6_NoFiltersNoVtx);
   fChain->SetBranchAddress("HLT_PPSMaxTracksPerArm1", &HLT_PPSMaxTracksPerArm1, &b_HLT_PPSMaxTracksPerArm1);
   fChain->SetBranchAddress("HLT_PPSMaxTracksPerRP4", &HLT_PPSMaxTracksPerRP4, &b_HLT_PPSMaxTracksPerRP4);
   fChain->SetBranchAddress("HLTriggerFinalPath", &HLTriggerFinalPath, &b_HLTriggerFinalPath);
   */

   //map<string, Bool_t *> mtrg;
   //Bool_t HLT_MC(true);
   mtrg["HLT_MC"] = &HLT_MC;
   mtrg["HLT_ZeroBias"] = &HLT_ZeroBias;

   if (!isZB) {
     mtrg["HLT_DiPFJetAve40"] = &HLT_DiPFJetAve40;
     mtrg["HLT_DiPFJetAve60"] = &HLT_DiPFJetAve60;
     mtrg["HLT_DiPFJetAve80"] = &HLT_DiPFJetAve80;
     mtrg["HLT_DiPFJetAve140"] = &HLT_DiPFJetAve140;
     mtrg["HLT_DiPFJetAve200"] = &HLT_DiPFJetAve200;
     mtrg["HLT_DiPFJetAve260"] = &HLT_DiPFJetAve260;
     mtrg["HLT_DiPFJetAve320"] = &HLT_DiPFJetAve320;
     mtrg["HLT_DiPFJetAve400"] = &HLT_DiPFJetAve400;
     mtrg["HLT_DiPFJetAve500"] = &HLT_DiPFJetAve500;

     mtrg["HLT_PFJet40"] = &HLT_PFJet40;
     mtrg["HLT_PFJet60"] = &HLT_PFJet60;
     mtrg["HLT_PFJet80"] = &HLT_PFJet80;
     //mtrg["HLT_PFJet110"] = &HLT_PFJet110;
     mtrg["HLT_PFJet140"] = &HLT_PFJet140;
     mtrg["HLT_PFJet200"] = &HLT_PFJet200;
     mtrg["HLT_PFJet260"] = &HLT_PFJet260;
     mtrg["HLT_PFJet320"] = &HLT_PFJet320;
     mtrg["HLT_PFJet400"] = &HLT_PFJet400; // v14
     mtrg["HLT_PFJet450"] = &HLT_PFJet450;
     mtrg["HLT_PFJet500"] = &HLT_PFJet500;
     mtrg["HLT_PFJet550"] = &HLT_PFJet550;

     mtrg["HLT_DiPFJetAve60_HFJEC"] = &HLT_DiPFJetAve60_HFJEC;
     mtrg["HLT_DiPFJetAve80_HFJEC"] = &HLT_DiPFJetAve80_HFJEC;
     mtrg["HLT_DiPFJetAve100_HFJEC"] = &HLT_DiPFJetAve100_HFJEC;
     mtrg["HLT_DiPFJetAve160_HFJEC"] = &HLT_DiPFJetAve160_HFJEC;
     mtrg["HLT_DiPFJetAve220_HFJEC"] = &HLT_DiPFJetAve220_HFJEC;
     mtrg["HLT_DiPFJetAve300_HFJEC"] = &HLT_DiPFJetAve300_HFJEC;

     //mtrg["HLT_PFJetFwd15"] = &HLT_PFJetFwd15;
     //mtrg["HLT_PFJetFwd25"] = &HLT_PFJetFwd25;
     mtrg["HLT_PFJetFwd40"] = &HLT_PFJetFwd40;
     mtrg["HLT_PFJetFwd60"] = &HLT_PFJetFwd60;
     mtrg["HLT_PFJetFwd80"] = &HLT_PFJetFwd80;
     mtrg["HLT_PFJetFwd140"] = &HLT_PFJetFwd140;
     mtrg["HLT_PFJetFwd200"] = &HLT_PFJetFwd200;
     mtrg["HLT_PFJetFwd260"] = &HLT_PFJetFwd260;
     mtrg["HLT_PFJetFwd320"] = &HLT_PFJetFwd320;
     mtrg["HLT_PFJetFwd400"] = &HLT_PFJetFwd400;
     mtrg["HLT_PFJetFwd450"] = &HLT_PFJetFwd450;
     mtrg["HLT_PFJetFwd500"] = &HLT_PFJetFwd500;
   }

   Notify();
}

Bool_t DijetHistosFill::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

  if (debugFiles && fChain) {
    if (fChain->GetCurrentFile()) {
      _filename = fChain->GetCurrentFile()->GetName();
      cout << endl << "Opened file: " << _filename << endl << flush;
    }
  }

   return kTRUE;
}

void DijetHistosFill::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t DijetHistosFill::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
  if (entry) {}; // silence compilation warning about unused entry
   return 1;
}
#endif // #ifdef DijetHistosFill_cxx
