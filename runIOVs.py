#! /usr/bin/python
import os
import argparse
import time

max_files = 9999

IOV_list = (
    [
        "2025C",
        "2025D",
        "2025E",
        "2025F",
        "2025G",
        "2025C_ZB",
        "2025D_ZB",
        "2025E_ZB",
        "2025F_ZB",
        "2025G_ZB",
    ]
    + [
        file.replace(".txt", "").replace("mcFiles_", "")
        for file in os.listdir("input_files/")
        if "Winter25MG_" in file and "all" not in file
    ]
    + [
        "2024C",
        "2024D",
        "2024E",
        "2024F",
        "2024G",
        "2024H",
        "2024I",
        "2024C_ZB",
        "2024D_ZB",
        "2024E_ZB",
        "2024F_ZB",
        "2024G_ZB",
        "2024H_ZB",
        "2024I_ZB",
    ]
    + [
        file.replace(".txt", "").replace("mcFiles_", "")
        for file in os.listdir("input_files/")
        if "Summer24MG_" in file and "all" not in file
    ]
    + [
        "2023Cv4",
        "2023D",
        "2023Cv123",
        "2023Cv123_ZB",
        "2023Cv4_ZB",
        "2023D_ZB",
    ]
    + [
        file.replace(".txt", "").replace("mcFiles_", "")
        for file in os.listdir("input_files/")
        if "Summer23MG_" in file and "all" not in file
    ]
    + [
        file.replace(".txt", "").replace("mcFiles_", "")
        for file in os.listdir("input_files/")
        if "Summer23MGBPix_" in file and "all" not in file
    ]
    + [
        "2022C",
        "2022D",
        "2022E",
        "2022F",
        "2022G",
        "2022C_ZB",
        "2022D_ZB",
        "2022E_ZB",
        "2022F_ZB",
        "2022G_ZB",
    ]
    + [
        file.replace(".txt", "").replace("mcFiles_", "")
        for file in os.listdir("input_files/")
        if "Summer22MG_" in file and "all" not in file
    ]
    + [
        file.replace(".txt", "").replace("mcFiles_", "")
        for file in os.listdir("input_files/")
        if "Summer22EEMG_" in file and "all" not in file
    ]
)
# IOV_list = ["2022F"]

# resources for slurm
res_iovs = {
    # dataset: [memory, hours, days]
    "2025C": [5, 8, ""],
    "2025D": [5, 8, ""],
    "2025E": [5, 8, ""],
    "2025F": [5, 8, ""],
    "2025G": [5, 8, ""],
    "2025C_ZB": [5, 8, ""],
    "2025D_ZB": [5, 8, ""],
    "2025E_ZB": [5, 8, ""],
    "2025F_ZB": [5, 8, ""],
    "2025G_ZB": [5, 8, ""],
    "2024C": [5, 8, ""],
    "2024D": [5, 8, ""],
    "2024E": [5, 8, ""],
    "2024F": [5, 8, ""],
    "2024G": [5, 8, ""],
    "2024H": [5, 8, ""],
    "2024I": [5, 8, ""],
    "2024C_ZB": [5, 8, ""],
    "2024D_ZB": [5, 8, ""],
    "2024E_ZB": [5, 8, ""],
    "2024F_ZB": [5, 8, ""],
    "2024G_ZB": [5, 8, ""],
    "2024H_ZB": [5, 8, ""],
    "2024I_ZB": [5, 8, ""],
    "2023Cv4": [1, 8, ""],
    "2023D": [5, 6, ""],  # [5, 0, "2-"],
    "2023Cv123": [5, 6, ""],
    "2023Cv123_ZB": [5, 6, ""],  # [5, 0, "2-"],
    "2023Cv4_ZB": [5, 6, ""],  # [5, 0, "2-"],
    "2023D_ZB": [5, 6, ""],  # [5, 0, "2-"],
    "2022C": [5, 6, ""],
    "2022D": [5, 6, ""],
    "2022E": [5, 6, ""],
    "2022F": [15, 12, ""],
    "2022G": [5, 6, ""],
    "2022C_ZB": [5, 6, ""],
    "2022D_ZB": [5, 6, ""],
    "2022E_ZB": [5, 6, ""],
    "2022F_ZB": [5, 6, ""],
    "2022G_ZB": [5, 6, ""],
}
res_iovs.update(
    {
        file.replace(".txt", "").replace("mcFiles_", ""): [6, 6, ""]
        for file in os.listdir("input_files/")
        if ("Summer" in file or "Summer" in file) and "all" not in file
    }
)

run3_25 = [x for x in IOV_list if "25" in x]
run3_24 = [x for x in IOV_list if "24" in x]
run3_23 = [x for x in IOV_list if "23" in x]
run3_22 = [x for x in IOV_list if "22" in x]


parser = argparse.ArgumentParser(description="Run all IOVs")

parser.add_argument("-i", "--IOV_list", required=True, type=str, nargs="+")
parser.add_argument("-v", "--version", required=True)
parser.add_argument(
    "-l",
    "--local",
    default=False,
    action="store_true",
    help="Run locally in the background",
)
parser.add_argument(
    "-d",
    "--debug",
    default=False,
    action="store_true",
    help="Run locally printing the log",
)
parser.add_argument("-p", "--pnetreg", default=False, action="store_true")
parser.add_argument("-u", "--upartreg", default=False, action="store_true")
parser.add_argument("-n", "--neutrino", default=False, action="store_true")
parser.add_argument("-c", "--closure", default=False, action="store_true")
parser.add_argument("-cl2", "--closure-l2", default=False, action="store_true")
parser.add_argument("-f", "--fast", default=False, action="store_true")
parser.add_argument("-of", "--only-failed", default=False, action="store_true")
parser.add_argument("-m", "--max_files", default=9999)
parser.add_argument("-sl", "--slurm", default=False, action="store_true", help="Submit jobs via slurm")
args = parser.parse_args()

IOV_input = []
if args.IOV_list:
    if "all" in args.IOV_list:
        IOV_input = IOV_list
    elif "25" in args.IOV_list and args.IOV_list[0].isdigit():
        IOV_input = run3_25
    elif "24" in args.IOV_list and args.IOV_list[0].isdigit():
        IOV_input = run3_24
    elif "23" in args.IOV_list and args.IOV_list[0].isdigit():
        IOV_input = run3_23
    elif "22" in args.IOV_list and args.IOV_list[0].isdigit():
        IOV_input = run3_22
    else:
        # Check that all IOVs passed are in the list
        for iov in args.IOV_list:
            if iov not in IOV_list:
                print("IOV " + iov + " not in list of IOVs")
                exit()
            else:
                IOV_input.append(iov)
else:
    print("No IOV list passed")
    exit()

if (args.version) and ("test" not in args.IOV_list):
    version = args.version

if args.max_files and ("test" not in args.IOV_list):
    max_files = args.max_files


if args.only_failed:
    # check the size of IOV root file
    print("Total IOVs: ", IOV_input)
    IOV_input_failed=[]
    for iov in IOV_input:
        type_dataset= "mc" if "Summer" in iov else "data"
        file_name =f"rootfiles/{version}/jmenano_{type_dataset}_out_{iov}_{version}.root"
        if os.path.exists(file_name):
            size = os.path.getsize(file_name)
            print(f"Checking IOV {iov}")
            if size < 1e5:
                print(f"IOV {iov} has size {size} bytes, will rerun")
                IOV_input_failed.append(iov)
            else:
                print(f"IOV {iov} has size {size} bytes, will not rerun")
        else:
            print(f"IOV {iov} does not exist, will rerun")
            IOV_input_failed.append(iov)

    IOV_input=IOV_input_failed

print("IOVs to run: ", IOV_input, len(IOV_input))

# Check that the version directory exists, if not create it
if not os.path.exists("rootfiles/" + version):
    os.makedirs("rootfiles/" + version)

if not os.path.exists("/afs/cern.ch/work/j/jessy/private/CMS/PNET_Regression/Residuals/logs_L2L3Res/dijet_logs/" + version):
    os.makedirs("/afs/cern.ch/work/j/jessy/private/CMS/PNET_Regression/Residuals/logs_L2L3Res/dijet_logs/" + version)

pnetreg = args.pnetreg
if "pnetreg" in version:
    pnetreg = True

upartreg = args.upartreg
if "upartreg" in version:
    upartreg = True

neutrino = args.neutrino
if "neutrino" in version:
    neutrino = True

closure = args.closure
if "closure" in version:
    closure = True
    
closureOnlyL2=args.closure_l2
if "closureOnlyL2" in version:
    closureOnlyL2 = True


if not args.fast:
    # choose if pnetreg or pnetregneutrino
    with open("src/DijetHistosFill.C", "r") as file:
        filedata = file.read()

    if pnetreg and not neutrino:
        print("Setting up PNetReg without neutrino")
        if "// #define PNETREG\n" in filedata:
            print("uncommenting PNETREG")
            filedata = filedata.replace("// #define PNETREG\n", "#define PNETREG\n")
        if not "// #define PNETREGNEUTRINO\n" in filedata:
            print("commenting PNETREGNEUTRINO")
            filedata = filedata.replace(
                "#define PNETREGNEUTRINO\n", "// #define PNETREGNEUTRINO\n"
            )
        if not "// #define UPARTREG\n" in filedata:
            print("commenting UPARTREG")
            filedata = filedata.replace("#define UPARTREG\n", "// #define UPARTREG\n")
        if not "// #define UPARTREGNEUTRINO\n" in filedata:
            print("commenting UPARTREGNEUTRINO")
            filedata = filedata.replace(
                "#define UPARTREGNEUTRINO\n", "// #define UPARTREGNEUTRINO\n"
            )
    elif pnetreg and neutrino:
        print("Setting up PNetReg with neutrino")
        if "// #define PNETREGNEUTRINO\n" in filedata:
            print("uncommenting PNETREGNEUTRINO")
            filedata = filedata.replace(
                "// #define PNETREGNEUTRINO\n", "#define PNETREGNEUTRINO\n"
            )
        if not "// #define PNETREG\n" in filedata:
            print("commenting PNETREG")
            filedata = filedata.replace("#define PNETREG\n", "// #define PNETREG\n")
        if not "// #define UPARTREG\n" in filedata:
            print("commenting UPARTREG")
            filedata = filedata.replace("#define UPARTREG\n", "// #define UPARTREG\n")
        if not "// #define UPARTREGNEUTRINO\n" in filedata:
            print("commenting UPARTREGNEUTRINO")
            filedata = filedata.replace(
                "#define UPARTREGNEUTRINO\n", "// #define UPARTREGNEUTRINO\n"
            )
    elif upartreg and not neutrino:
        print("Setting up UparTReg without neutrino")
        if "// #define UPARTREG\n" in filedata:
            print("uncommenting UPARTREG")
            filedata = filedata.replace("// #define UPARTREG\n", "#define UPARTREG\n")
        if not "// #define UPARTREGNEUTRINO\n" in filedata:
            print("commenting UPARTREGNEUTRINO")
            filedata = filedata.replace(
                "#define UPARTREGNEUTRINO\n", "// #define UPARTREGNEUTRINO\n"
            )
        if not "// #define PNETREG\n" in filedata:
            print("commenting PNETREG")
            filedata = filedata.replace("#define PNETREG\n", "// #define PNETREG\n")
        if not "// #define PNETREGNEUTRINO\n" in filedata:
            print("commenting PNETREGNEUTRINO")
            filedata = filedata.replace(
                "#define PNETREGNEUTRINO\n", "// #define PNETREGNEUTRINO\n"
            )
    elif upartreg and neutrino:
        print("Setting up UParTReg with neutrino")
        if "// #define UPARTREGNEUTRINO\n" in filedata:
            print("uncommenting UPARTREGNEUTRINO")
            filedata = filedata.replace(
                "// #define UPARTREGNEUTRINO\n", "#define UPARTREGNEUTRINO\n"
            )
        if not "// #define UPARTREG\n" in filedata:
            print("commenting UPARTREG")
            filedata = filedata.replace("#define UPARTREG\n", "// #define UPARTREG\n")
        if not "// #define PNETREG\n" in filedata:
            print("commenting PNETREG")
            filedata = filedata.replace("#define PNETREG\n", "// #define PNETREG\n")
        if not "// #define PNETREGNEUTRINO\n" in filedata:
            print("commenting PNETREGNEUTRINO")
            filedata = filedata.replace(
                "#define PNETREGNEUTRINO\n", "// #define PNETREGNEUTRINO\n"
            )
    else:
        print("Using standard jet pT")
        if not "// #define PNETREG\n" in filedata:
            print("commenting PNETREG")
            filedata = filedata.replace("#define PNETREG\n", "// #define PNETREG\n")
        if not "// #define PNETREGNEUTRINO\n" in filedata:
            print("commenting PNETREGNEUTRINO")
            filedata = filedata.replace(
                "#define PNETREGNEUTRINO\n", "// #define PNETREGNEUTRINO\n"
            )
        if not "// #define UPARTREG\n" in filedata:
            print("commenting UPARTREG")
            filedata = filedata.replace("#define UPARTREG\n", "// #define UPARTREG\n")
        if not "// #define UPARTREGNEUTRINO\n" in filedata:
            print("commenting UPARTREGNEUTRINO")
            filedata = filedata.replace(
                "#define UPARTREGNEUTRINO\n", "// #define UPARTREGNEUTRINO\n"
            )

    # find line that starts with bool CLOSURE_L2L3RES
    for line in filedata.split("\n"):
        if line.startswith("bool CLOSURE_L2L3RES"):
            if closure and not closureOnlyL2:
                print("Setting CLOSURE_L2L3RES to true")
                line_new = f"bool CLOSURE_L2L3RES = true;"
            else:
                print("Setting CLOSURE_L2L3RES to false")
                line_new = f"bool CLOSURE_L2L3RES = false;"
            break
    
    # modify line
    filedata = filedata.replace(line, line_new)
            
    for line in filedata.split("\n"):
        if line.startswith("bool CLOSURE_L2RES"):
            if closureOnlyL2:
                print("Setting CLOSURE_L2RES to true")
                line_new = f"bool CLOSURE_L2RES = true;"
            else:
                print("Setting CLOSURE_L2RES to false")
                line_new = f"bool CLOSURE_L2RES = false;"
            break
    
    # modify line
    filedata = filedata.replace(line, line_new)

    # print(filedata[:700])

    with open("src/DijetHistosFill.C", "w") as file:
        file.write(filedata)

    time.sleep(10)

    # uncomment GPU
    with open("make/mk_DijetHistosFill.C", "r") as file:
        filedata = file.read()

    if "// #define GPU" in filedata:
        print("uncommenting GPU")
        filedata = filedata.replace("// #define GPU", "#define GPU")

    with open("make/mk_DijetHistosFill.C", "w") as file:
        file.write(filedata)

    time.sleep(10)

    # clean and make
    os.system("make clean")
    os.system("make")

    # comment GPU
    with open("make/mk_DijetHistosFill.C", "r") as file:
        filedata = file.read()

    filedata = filedata.replace("#define GPU", "// #define GPU")
    print("commenting GPU")

    with open("make/mk_DijetHistosFill.C", "w") as file:
        file.write(filedata)
    time.sleep(10)

for iov in IOV_input:
    print(f"Process DijetHistosFill.C+g for IOV {iov}")

    if args.local:
        os.system(
            f'nohup time root -l -b -q \'make/mk_DijetHistosFill.C("{iov}","{version}",{max_files})\' > /afs/cern.ch/work/j/jessy/private/CMS/PNET_Regression/Residuals/logs_L2L3Res/dijet_logs/{version}/TEST_log_{iov}_{version}.log &'
        )
    elif args.debug:
        os.system(
            f'time root -l -b -q \'make/mk_DijetHistosFill.C("{iov}","{version}",{max_files})\''
        )
    else:
        if args.slurm:
            print(f"Submitting job for IOV {iov} via slurm")
            os.system(
                f"sbatch --job-name=dijet_{iov}_{version} -p {'long' if (res_iovs[iov][1] > 12 or res_iovs[iov][2]) else 'standard'} --time={res_iovs[iov][2]}0{res_iovs[iov][1]}:00:00 --ntasks=1 --cpus-per-task=1 --mem={res_iovs[iov][0]}gb --output=/work/mmalucch/logs_L2L3Res/dijet_logs/{version}/log_{iov}_{version}.log submit_slurm.sh {iov} {version} {max_files}"
            )
        else:
            print(f"Submitting job for IOV {iov} via HTCondor")
            os.system(
                f"condor_submit -a 'arguments = {iov} {version} {max_files}' -a 'output = /afs/cern.ch/work/j/jessy/private/CMS/PNET_Regression/Residuals/logs_L2L3Res/dijet_logs/{version}/log_{iov}_{version}.out' -a 'error = /afs/cern.ch/work/j/jessy/private/CMS/PNET_Regression/Residuals/logs_L2L3Res/dijet_logs/{version}/log_{iov}_{version}.err' -a 'log = /afs/cern.ch/work/j/jessy/private/CMS/PNET_Regression/Residuals/logs_L2L3Res/dijet_logs/{version}/log_{iov}_{version}.log' submit_condor.sub"
            )
            print(f" => Follow jobs with 'condor_q'")
            
    print(f" => Follow logging with 'tail -f /afs/cern.ch/work/j/jessy/private/CMS/PNET_Regression/Residuals/logs_L2L3Res/dijet_logs/{version}/log_{iov}_{version}.log'")
