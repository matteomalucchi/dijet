#!/bin/bash
IOV=$1
VERSION=$2

source /cvmfs/cms.cern.ch/cmsset_default.sh
export XRD_RUNFORKHANDLER=1

mkdir rootfiles
mv ${VERSION} rootfiles/

python3 post_processing.py -i ${IOV} -v ${VERSION} -f

mv rootfiles/${VERSION} ./
