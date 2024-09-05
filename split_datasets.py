import os


# read txt files in folder
folder = "input_files/"


# list all files
files = os.listdir(folder)
files.sort()

N = 10

dataset_list = [
    "mcFiles_Summer23MG_",
    "mcFiles_Summer23MGBPix_",
]


for dataset in dataset_list:
    file_list = []
    for file in files:
        if "all" in file:
            continue
        if dataset in file:
            if "BPix" not in dataset and "BPix" not in file:
                file_list.append(file)
    # check if list is empty
    if not file_list:
        continue
    tot_file_name = folder + dataset.rstrip("_")    + "_all.txt"
    with open(tot_file_name, "w") as outfile:
        for file in file_list:
            with open(folder + file) as infile:
                for line in infile:
                    outfile.write(line)

    # split the files in N parts
    with open(tot_file_name) as f:
        lines = f.readlines()

    lenghts = [len(lines) // N] * N
    for i in range(len(lines) % N):
        lenghts[i] += 1

    print(lenghts)

    for i in range(N):
        with open(tot_file_name.replace("all", f"{i+1}"), "w") as f:
            f.writelines(lines[: lenghts[i]])
            lines = lines[lenghts[i] :]
