#!/bin/bash
IOV=$1
VERSION=$2
MAXFILES=$3

source /cvmfs/cms.cern.ch/cmsset_default.sh
export XRD_RUNFORKHANDLER=1

mkdir -p rootfiles/${VERSION}

root -l -b -q "make/mk_DijetHistosFill.C(\"${IOV}\",\"${VERSION}\", ${MAXFILES})"
