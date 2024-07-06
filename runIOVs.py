#! /usr/bin/python
import os
import argparse


max_files = 9999

IOV_list = [
    "2023Cv4",
    # "2023D",
    "2023Cv123",
    "2023Cv123_ZB",
    "2023Cv4_ZB",
    # "2023D_ZB",
    "Summer23MG_1",
    "Summer23MG_2",
    "Summer23MG_3",
    "Summer23MG_4",
    "Summer23MG_5",
    "Summer23MG_6",
    # "Summer23MGBPix_1",
    # "Summer23MGBPix_2",
    # "Summer23MGBPix_3",
    # "Summer23MGBPix_4",
]

res_iovs = {
    # dataset: [memory, hours, days]
    "2023Cv4": [1, 8, ""],
    "2023D": [5, 12, ""],#[5, 0, "2-"],
    "2023Cv123": [5, 6, ""],
    "2023Cv123_ZB": [5, 12, ""],#[5, 0, "2-"],
    "2023Cv4_ZB": [5, 12, ""],#[5, 0, "2-"],
    "2023D_ZB": [5, 12, ""],#[5, 0, "2-"],
    "Summer23MG_1": [5, 0, "2-"],
    "Summer23MG_2": [5, 0, "2-"],
    "Summer23MG_3": [5, 12, ""],#[5, 0, "2-"],
    "Summer23MG_4": [5, 12, ""],#[5, 0, "2-"],
    "Summer23MG_5": [5, 12, ""],#[5, 0, "2-"],
    "Summer23MG_6": [5, 12, ""],#[5, 0, "2-"],
    "Summer23MGBPix_1": [5, 12, ""],#[5, 0, "2-"],
    "Summer23MGBPix_2": [5, 12, ""],#[5, 0, "2-"],
    "Summer23MGBPix_3": [5, 12, ""],#[5, 0, "2-"],
    "Summer23MGBPix_4": [5, 12, ""],#[5, 0, "2-"],
}

# Run 3 is all samples with year 2023 and 2022 from the full IOV_list
run3_IOV_list = [x for x in IOV_list if "2023" in x or "2022" in x or "Summer22" in x]
run3_DT = [x for x in IOV_list if "2023" in x or "2022" in x]
run3_22_DT = [x for x in IOV_list if "2022" in x]
run3_MC = [x for x in IOV_list if "Summer22" in x]
summer23_MC = [x for x in IOV_list if "Summer23" in x]
tot_23_das = [x for x in IOV_list if ("23" in x)]

version = "v38_Summer23MG_NoL2L3Res_Off_reweight_jets_test2"

IOV_input = []

parser = argparse.ArgumentParser(description="Run all IOVs")

# The user can pass the IOV list, version, max number of files as an argument
parser.add_argument("-i", "--IOV_list", nargs="+", default=IOV_input)
parser.add_argument("-v", "--version", default=version)
parser.add_argument("-l", "--local", default=False, action="store_true")
parser.add_argument("--max_files", default=9999)
args = parser.parse_args()

if args.IOV_list:
    if "all" in args.IOV_list:
        IOV_input = IOV_list
    elif "run3" in args.IOV_list:
        IOV_input = run3_IOV_list
    elif "run3DT" in args.IOV_list:
        IOV_input = run3_DT
    elif "run3_22DT" in args.IOV_list:
        IOV_input = run3_22_DT
    elif "run3MC" in args.IOV_list:
        IOV_input = run3_MC
    elif "summer23MC" in args.IOV_list:
        IOV_input = summer23_MC
    elif "tot_23_das" in args.IOV_list:
        IOV_input = tot_23_das
    elif "test" in args.IOV_list:
        IOV_input = run3_IOV_list[1:5]
        max_files = 4
        version = version + "_test"
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

print("IOVs to run: ", IOV_input)

# Check that the version directory exists, if not create it
if not os.path.exists("rootfiles/" + version):
    os.makedirs("rootfiles/" + version)

if not os.path.exists("logs/" + version):
    os.makedirs("logs/" + version)

for iov in IOV_input:
    print(f"Process DijetHistosFill.C+g for IOV {iov}")
    # os.system(f"ls -ltrh rootfiles/jmenano_mc_out_{iov}_{version}.root")
    # os.system(f"ls -ltrh rootfiles/jmenano_data_out_{iov}_{version}.root")
    # os.system(f"ls -ltrh logs/log_{iov}_{version}.log")

    # os.remove("CondFormats/JetMETObjects/src/Utilities_cc.d", True)
    # os.remove("CondFormats/JetMETObjects/src/Utilities_cc.so")
    # os.remove("CondFormats/JetMETObjects/src/Utilities_cc_ACLiC_dict_rdict.pcm")

    # os.system(
    #     f'time root -l -b -q \'make/mk_DijetHistosFill.C("{iov}","{version}",{max_files})\''
    # )
    # os.system(f"sbatch submit_slurm.sh {iov} {version} {max_files}")

    if args.local:
        os.system(
            f'nohup time root -l -b -q \'make/mk_DijetHistosFill.C("{iov}","{version}",{max_files})\' > logs/{version}/log_{iov}_{version}.log &'
        )
    else:
        os.system(
            f"sbatch --job-name=dijet_{iov}_{version} -p {'long' if (res_iovs[iov][1] > 12 or res_iovs[iov][2]) else 'standard'} --time={res_iovs[iov][2]}0{res_iovs[iov][1]}:00:00 --ntasks=1 --cpus-per-task=1 --mem={res_iovs[iov][0]}gb --output=logs/{version}/log_{iov}_{version}.log submit_slurm.sh {iov} {version} {max_files}"
        )

    print(f" => Follow logging with 'tail -f logs/{version}/log_{iov}_{version}.log'")


#    os.system("fs flush")
#    wait()
#    time.sleep(sleep_time)
