import csv

import matplotlib.pyplot as plt
import numpy as np
import scipy.stats as sts

GAMMA = 0.95
STATS_LAB_1 = "..\\stats\\Lab_1\\stats.csv"
STATS_LAB_2 = "..\\stats\\Lab_2\\stats.csv"
INTERVAL_LAB_2 = "..\\stats\\Lab_2\\interval.txt"


def get_size_time(file: str) -> dict:
    cur_size = 0; size_time = dict()
    with open(file, "r") as csvfile:
        csvreader = csv.reader(csvfile, delimiter="\t")
        for row in csvreader:
            size = int(row[0][:row[0].find("_")])
            if(cur_size != size):
                size_time.update({size: []})
                cur_size = size
            size_time[size].append(int(row[1]))
    return size_time


def save_interval(save_path: str, size_time: dict) -> None:
    means_time = list()
    size_time = dict(sorted(size_time.items()))
    with open(save_path, "w") as interval:
        for key in size_time.keys():
            average = np.mean(size_time[key])
            means_time.append(average)
            volume = len(size_time[key])
            s = np.sqrt(volume / (volume - 1)) * np.std(size_time[key])
            t = sts.t.ppf(df=volume - 1, q=(GAMMA + 1) / 2)
            delta = t * s / np.sqrt(volume)
            interval.write(f"Confidence interval for size = {key}: ")
            interval.write(f"({average - delta}, {average + delta})\n")


if __name__ == "__main__":
    lab_1 = get_size_time(STATS_LAB_1)
    lab_2 = get_size_time(STATS_LAB_2)

    save_interval(INTERVAL_LAB_2, lab_2)

    lab_1 = dict(sorted(lab_1.items()))
    lab_2 = dict(sorted(lab_2.items()))
    means_time_lab_1 = []; means_time_lab_2 = []
    for key in lab_1.keys():
        means_time_lab_1.append(np.mean(lab_1[key]))
        means_time_lab_2.append(np.mean(lab_2[key]))

    plt.xlabel("Размер квадратной матрицы (одной стороны)")
    plt.ylabel("Время перемножения матриц, мкс")
    plt.plot(lab_1.keys(), means_time_lab_1, label="Без распараллеливания")
    plt.plot(lab_1.keys(), means_time_lab_2, label="С распараллеливанием")
    plt.legend()
    plt.show()