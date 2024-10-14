# dijet
CMS dijet analysis

Quick starter guide:

`root -l -b -q mk_CondFormats.C`

`root -l -b -q mk_DijetHistosFill.C\(\"ERA\"\)\,\(\"VERSION\"\)`
[or 'python runIOVs.py'] ['hadd' files by hand if using runIOVs.py]

`root -l -b -q DijetHistosCombine.C+g`

`root -l -b -q DijetHistosJER.C+g`

`root -l -b -q DijetHistosOverlay.C+g`

Aim of this package is to consolidate multiple analyses done with JetMET and ZeroBias primary data sets together with the corresponding QCD dijet MC. These include: MC truth JEC, jet veto maps, Jet ID, JER pT-dependent scale factors, dijet eta-dependent JEC (L2Res), multijet pT-dependent JEC (L3Res), PF jet composition (JEC global fit), inclusive jet cross section (physics analysis).

The general core design principles are:
- use (JME)NANO files as input (local data storage)
- use TTree::MakeClass as template (beginner-friendly code, re-freshable header)
- use standalone ROOT (quick prototyping)
- store results in hadd'able format, e.g TH2D, TProfile2D (allow partial re-processing)
- utilize TProfile2D over TH3D whenever possible (fast and small)
- combine triggers and eras in post-processing (superfast iteration)
- store each analysis in separate folder (parallel development, switching on/off)
- provide post-processing tools (e.g. JER extraction, unfolding)
- aspire for linear processing (no loops, e.g. L2Res->JER SF->L2Res again)
- provide paper quality plotting (e.g. DP Notes)

Ultimate goal would be to run mature JetMET analyses automatically and directly after Prompt Reco (JEC4Prompt) for each fill of ~1/fb within 24h, to ensure best possible time-stability and DQM monitoring with robust, physics-relevant standard candles (JEC, JER, jet cross section).





How to RUN on Hefaistos:
------------------------
(try mosh to not drop connection)
- source /work/data/rootbinaries/root/bin/thisroot.sh [6.26.10]
- $ make
- Check that #define GPU in set mk_DijetHistosFill.C
- Execute: `$ python3 runIOVs.py --IOV_list [list of IOVs]`
- - e.g. `$ python3 runIOVs.py --IOV_list 2022C_ZB`
- - Can also use `--IOV_list all` for all IOVs, version X can be passed with `--version v[X]`, for smaller test runs use `--max_files 10` or similar
[- nohup root -l -b -q mk_DijetHistosFill.C\(\"X\"\) > log.txt & [alternative]]
+ runtime about 10-20h for most files
[=> edit (version, IOV_list) and execute 'python renameAllIOVs.py' [not yet]]

+ tail -f log.txt [for individual files]
+ tail -n3 logs/log_*v[X].txt [for overall run status]
+ starting up takes quite a bit (~X sec) due to GetEntries() call
   => code TStopWatch to ignore this startup time, or skip GetEntries

How to ANALYZE locally:
-----------------------
Copy files locally for further processing
- rsync -rutP Hefaistos:/media/storage/dijet/rootfiles/*v[X].root rootfiles/

Hadd files together as needed (either JetMET+ZB, or parts of IOV)
- python addAllIOVs.py

After producing the jmenano_[data,mc]_out_v[X].root root files and hadding:
- root -l -b -q DijetHistosCombine.C+g   [merge triggers]
- root -l -b -q DijetHistosJER.C+g       [JER SF]
- root -l -b -q DijetHistosL2Res.C+g     [dijet L2Res]
- root -l -b -q DijetHistosOverlay.C+g   [draw dijet L2Res]

Multijet plotting
- root -l -b -q minitools/drawMultijet.C+g [draw multijet pTbin+MPF/DB]

Jet veto maps in jecsys3 package:
- root -l -b -q jecsys3/minitools/doJetVetoV2.C
- root -l -b -q jecsys3/minitools/drawJetVetoV2.C


To-do:
- add trigger turn-on folder
- add MET filters => done: Flag_METFilter; also need others?
- multijet: improve high pT efficiency (relative jet veto around leading jet?)
  - also figure out O(5-10%) mpfu even at highest pT
- add smeared collection of jets for MC => done
- option: add monitoring of <rho> for each analysis? => add to PFComposition
- check JetID and METFilters => done?
- figure out segfault for 2018D. Could be array overflow?
- update to Summer20 L1+L2L3 when available

To-do Run3:
- update JEC
- fix multijet Crecoil and PF composition
- update JER SF
- then re-update JER SF pT-dep
- check MET filters


From Fikri, 31 March 2023:
I don't thinkFlag_METFilters is defined at Nano production level. Its defined at Mini production level [1]
As for Jet_jetId, JMENanoV9 uses the same release as the central NanoAODv9, which is 10_6_26. The jetId decisions should follow the recommendations [2] .
[1] https://github.com/cms-sw/cmssw/blob/CMSSW_10_6_26/PhysicsTools/PatAlgos/python/slimming/metFilterPaths_cff.py#L49
[2] https://twiki.cern.ch/twiki/bin/view/CMS/JetID13TeVUL#Preliminary_Recommendations_for

Bugs:
- mpfu in multijet large compared to mpfn. Why? => sign error
- MC genWeight seems not to be working. Why? => w was set before reading event
- Wrong MC: Summer19UL16_V7 -> Summer20UL16_V1

(To do: add 40to70 to Summer22EEMG, filter out bad files).
(To-do: Downdload Summer23 and ReReco samples. Not yet done for ZeroBias at least)
(To-do: QG SFs and response)

// v39. Fixed an issue with Summer23 MC input files which caused gaps in the HT histogram
// v38. Added option for PU reweighting
// v37. Added Summer23 MC samples
// v36. Changed output file structure. Luminosity per trigger histogram (h_lumivstrpu) added
// v35b. Turned off jet smearing. For 19Dec reco added a separation in JEC for 2023C.
// v35. Added new L2L3Residuals along with L2Residuals. Fixed Flag_ filter introduced in v33
// v34. L2L3Residual for Run3
// v33. Updated Run 3 MET filter flags
// v32. Update HF |eta| binning. Extend pT binning. Add L2Res for CD+EFG. E still prompt. Update 2022C_ZB and 2022D_ZB to re-reco.

// v31b,c. Processeed re-reco 2022C,D (is code already v32 for |eta| binning?)

// v31. Update MC JECs to those used by Mikel (Summer22) and switch off L2L3Residuals. Split Summer22(EE)MGs into 2 or 4, fix 2022F JEC. (Next steps: implement pT-dependent JER SF and run with it. Figure out MPF vs DB.)
// v30. Change PuppiMET to RawPuppiMET for raw MET input. Split 2022F file list into two.
// v29: add Run3 code from Iita. Update JEC, jetvetomaps, JSON, rho branch mapping. Remove or comment out branches not in 2023 tuples. Patch Pileup_pthatmax for isMG.
// v28: add Incjet/h2pteta without pT range preselection.
// v27: Filter out corrupt files from 2018D2 and 2018MG (log files >1MB), as well as other large log files. Switch of HLT_ZeroBias for non-ZB datasets. Move input files to input_files subdirectory to clean up. Add useJERSFvsPt switch and functionality for MC.
// v26(ZB): Add UL2017*_ZB eras for Zero Bias primary data set. v26c also added rest.
// v26: Fix division by zero bug for Jet_CF[i] that made MPF0 and MPFu corrupted. Add UL2017MG files.
// v25: Improve handling of JER files. Default data set and versioning to "X" and "vX", set version in runAllIOVs.py". Split UL2018D to UL2018D1, UL2018D2 for more balanced running. Set nGenJetMax=100 (was 76 from 2016GH). Add debugFiles option to print out file names.

// v24: Add ability to run over 2016APV, 2016, 2017, 2018. Add IOV and version to output file name. Switch off smearing (to derive JER SF first). Revert to public JEC+JER versions (V7/V3*2, V6/V3, V5/V2) until new Summer20 files verified. Add runAllIOVs.py. Add automatic HT bin event counting. Add MC truth folder.
=> need MadGraph samples for UL2017

// v23: Add flat JER SF
// v22b: Add MadGraph capability (isMG).

// v22: Add extra profiles to Dijet2 for FSR studies (p2mnu, p2mnux, p2m0tc, p2m0pf etc.)

// v21: Add |pT1-pT2|/|pT1+pT2|<0.7 and allJetsGood flag for Dijet2.

// v20: Add Dijet2 for DESY-style dijet bins in eta and pT. Add jet veto maps. Add timer to estimate run time.

// v19: Fix JEC S19_V7->S20_V1 (except data L2L3Res still S19_V7). Fix MC weight. Fix bug in MPFu calculation (sign error between jX and mX=-jX). Filter Pileup_pthatmax>Generator_binvar. Add prho to PFComposition. (v19b for MC: fix HLT_MC).

// v18: Implement pT,avp and proper bisector for dijet and multijet following JME-21-001. Keep previous pT,ave and bisector as dijet and multijet axes, respectively. Raise pT of recoil jets to 30 GeV in multijet in hopes of reducing MPFu. Add PF composition for incjet, dijet, multijet. Add 15-40 GeV bins for dijet.

(Implement MC (flat, pThat binned, HT binned))
// v17: Add Jet_jetId>=4 (tightLepVeto) and Flag_METFilters>0 (all?) for multijet, dijet, inclusive jet and jet veto maps

// v16: Fix linking of fixedGridRhoFastjetAll (Rho_*) for Run 2. Modify multijet selection (drop all |eta|>2.5 jets from recoil, not just 1+2), patch pT2/pT1<0.6 to pT2/pTrecoil<0.6 (5% bias!), veto all forward jets, add Crecoil 1D+2D. Implement proper L1L2L3-RC MET for MPF. Clean file structure.

// v15: Add UL2016GH data+MC. Run time about 9h for data (77M/245M=>7.5k)? Added JetA and Rho as new inputs. Multijet still not working.

// v14: fix absetamin thresholds for mt["HLT_PFJetFwdX"] for X>=140. Add missing HLT_PFJet400 trigger. Add Jetveto/heta_pretrg for minitools/drawFwdTrigEff.C.

// v13:	invert reference axes on Multijet so that result is pTlead/pTrecoil (v12 and earlier effectively pTrecoil/pTlead). Add requirement that jet[1] and jet[2] at |eta|<2.5, plus check both for pT>30 and pT<0.7*pT[0]
// Implement also new dijetHistos2 for efficient analysis.
// RunE v12e: 5.5/fb (5.476540005), RunF v12f: 1.4/fb (1.363428299)
// RunCD: 7.6/fb (7.561991506)

// v12: Add p2chf,p2nef,p2nhf and p2chftp,p2chftp,p2nhftp to Jetveto. Update JSON file for 2022BCDEF. Add RunF to mk_*.C listing. Add multijet/h2m2a control.
=> todo: add Dijet folder with TProfile2D's vs eta and pT

// v11: Add doJetveto and Jetveto folder. Changed multijet alpha veto from
//      DELTAPHI to DELTAR (avoid bias on forward PU jets)

// v10: Add HLT_ZeroBias. Split text files to ZeroBias and JetMET.
//      Replace TrigObj with TrigObjJMEAK4. Add TH2D h2m0a and
//      hcosdphi for multijet controls
// Oct 12 full JSON: 9.705969501/fb. RunE only: 2.058990167/fb. (ABCD 7.6/fb)
// (JMENANO on eos: v2p0 4.9 TB, v2p1 6.1 TB)

// v9: Add inclusive jet and multijet folders. Add trigger counts.
// v9mc: Switch off L2L3Res

// v8: add UL2018 samples. Implement redoing JEC, add HLT JES with T&P
// data: 16:44->20:42 (3h58min). TrigObj doubling time?
// mc: ~20:42->01:15 (4h33min). TrigObj doubling time?

// v7: add PF composition vs eta and pT. Add hmjj2 and hmjj213
// data 17:15->19:20 (2h5min). mc 21:15->23:27 (2h12min, died).
// mcflat: 08:04->10:00 (1h56)
// ul18a: 10:24->16:46 (6h22)
// Found 10,793,303 bad events according to new JSON (events cut)
// Found 113,084,154 bad events according to trigger bits (events cut)
// Processed 117 runs, 55,380 luminosity blocks and 160,691,332 events
// Analyzed 47,607,178 events
// ul18mc: 9:14->11:59 (2h45h)
// Processed 1 runs, 19,928 luminosity blocks and 19,928,000 events
// Analyzed 19,928,000 events

// v6bothmc on dataFile_QCDFlats.txt
Loaded 38,809,694 entries
Processed 1 runs, 19,996 luminosity blocks and 38,809,694 events
(19:41->23:56->4h15min)

// v6flatmc on dataFile_FlatQCD.txt (new version)
Loaded 18,904,000 entries
Processed 1 runs, 18,904 luminosity blocks and 18,904,000 events
(15:48->17:47, 1h59min)

// v6: run on dataFiles_RunC.txt with 4.86/fb golden JSON => 2.8954/fb
Loaded 129,672,779 entries
Found 49,796,825 bad events according to new JSON (events cut)
Found 67,883,399 bad events according to trigger bits (events cut)
Processed 82 runs, 16,935 luminosity blocks and 79,875,954 events
Saving these to file rootfiles/jmenano_v6.json for brilcalc
Analyzed 11,992,555 events
(21:18->23:13, 1h 55min)

// v5: 4.86/fb golden JSON
Found 4,833,924 bad events according to new JSON (events cut)
Found 8,891,715 bad events according to trigger bits (events cut)
Processed 31 runs, 5,290 luminosity blocks and 10,787,317 events
Saving these to file rootfiles/jmenano.json for brilcalc
Analyzed 1,895,602 events
(09:06->09:19, 13 mins; 0.450/fb out of 4.86/fb)

// v4: move run, LS id earlier just in case. (TBD: Add METfilters).
// v4: 1.44/fb Golden JSON
Found 4868229 bad events according to new JSON (events cut)
Found 8864174 bad events according to trigger bits (events cut)
Processed 30 runs, 5266 luminosity blocks and 10753012 events
Saving these to file rootfiles/jmenano.json for brilcalc
Analyzed 1888838 events

// v3: add runs (and LS)  listing for Santiago+Pallabi + luminosity
// v3: add PtBins
// TBD: add TrigObj (HLT jet?)
Found 1673601 bad events according to new JSON (events cut)
Found 11450550 bad events according to trigger bits (events cut)
Processed 55 runs, 7004 luminosity blocks and 2497090 events
Analyzed 2497090 events
(17:16->17:36, 20 mins)

// v2_fwd40 tried HLT_PFJetFwd40 (HLT_PFJet40 empty)
Found 1673601 bad events according to new JSON (events cut)
Found 13819691 bad events according to trigger bits (events cut)
Found 10619 bad events not in fwd trigger phase space (events cut)
Analyzed 127949 events

// v2 added genWeight for MC (add runbx plot for data?)
// v2 moved to HLT_DiPFJetAve40 only for data (690k->490k)
// processing times 4 and 12 minutes
Found 1673601 bad events according to new JSON (events cut)
Found 13459281 bad events according to trigger bits (events cut)
Found 0 bad events not in fwd trigger phase space (events cut)
Analyzed 488359 events


// v1 data 2022-08-18 16:51 -> 16:57 (6 minutes)
Found 1673601 bad events according to new JSON (events cut)
Found 13257262 bad events according to trigger bits (events cut)
Found 51040 bad events not in fwd trigger phase space (events cut)
Analyzed 690378 events

// v1 mc 2022-08-16 17:07 -> 17:22 (15 minutes)
Loaded 7893896 entries
Analyzed 7893896 events
