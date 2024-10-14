# dijet

Dijet and multijet analysis to obtain the inputs for the L2L3Residuals  within the JetMET group of CMS as described by the [JERC](https://cms-jerc.web.cern.ch/) sub-group. The results are to be combined with the [photon+jet](https://github.com/matteomalucchi/gamjet-analysis) and [Z+jet](https://gitlab.cern.ch/mmalucch/ZbAnalysis) analyses with the scripts provided in the [jecsys3](https://github.com/matteomalucchi/jecsys3) repository.

## Dependencies

An installation of ROOT is required to run the scripts.

## How to run

Run on slurm for 2022+2023 recompiling the libraries

```bash
python runIOVs.py -i all -v version
```

This script executes the following actions:

- comment / uncomment the `#define PNETREG` / `#define PNETREGNEUTRINO` in `src/DijetHistosFill.C` to choose whether to apply the PNet regression or the PNet regression including neutrino
- uncomment `#define GPU` in `make/mk_DijetHistosFill.C`
- `make clean`
- `make`
- comment `#define GPU` in `make/mk_DijetHistosFill.C`

Once the jobs are completed, to do the post processing run:

```bash
python post_processing.py  -i all -v version
```

This script executes the following actions:

- combine the datasets together using `python addAllIOVs.py -v version -i all`
- change version and year in `histogram_scripts/DijetHistosCombine.C` and run  `root -q -l -b DijetHistosCombine.C`
