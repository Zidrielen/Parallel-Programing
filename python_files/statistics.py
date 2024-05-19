import csv

import matplotlib.pyplot as plt
import numpy as np
import scipy.stats as sts

GAMMA = 0.95
STATS_LAB_3 = "..\\stats\\Lab_3\\stats.csv"
INTERVAL_LAB_3 = "..\\stats\\Lab_3\\interval.txt"


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


def save_interval(save_path: str, size_time: dict) -> dict:
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
    return means_time


if __name__ == "__main__":
    lab_3 = get_size_time(STATS_LAB_3)
    means_time = save_interval(INTERVAL_LAB_3, lab_3)

    plt.xlabel("Размер квадратной матрицы (одной стороны)")
    plt.ylabel("Время перемножения матриц, мкс")
    plt.plot(means_time.keys(), means_time.items())
    plt.legend()
    plt.show()