import csv

import matplotlib.pyplot as plt
import numpy as np
import scipy.stats as sts

GAMMA = 0.95
STATS_LAB_1 = "../stats/Lab_1/stats.csv"
STATS_LAB_2 = "../stats/Lab_2/stats.csv"
INTERVAL_LAB_1 = "../stats/Lab_1/interval.txt"
INTERVAL_LAB_2 = "../stats/Lab_2/interval.txt"


if __name__ == "__main__":
    """cur_size = 0; size_time = dict()
    with open(STATS_LAB_1, "r") as csvfile:
        csvreader = csv.reader(csvfile, delimiter="\t")
        for row in csvreader:
            size = int(row[0][:row[0].find("_")])
            if(cur_size != size):
                size_time.update({size: []})
                cur_size = size
            size_time[size].append(int(row[1]))

    means_time = list()
    size_time = dict(sorted(size_time.items()))
    with open(INTERVAL_LAB_1, "w") as interval:
        for key in size_time.keys():
            average = np.mean(size_time[key])
            means_time.append(average)
            volume = len(size_time[key])
            s = np.sqrt(volume / (volume - 1)) * np.std(size_time[key])
            t = sts.t.ppf(df=volume - 1, q=(GAMMA + 1) / 2)
            delta = t * s / np.sqrt(volume)
            interval.write(f"Confidence interval for size = {key}: ")
            interval.write(f"({average - delta}, {average + delta})\n")

    plt.title("Зависимость времени перемножения матриц от их размера")
    plt.xlabel("Размер квадратной матрицы (одной стороны)")
    plt.ylabel("Время перемножения матриц, мкс")
    plt.plot(size_time.keys(), means_time)
    plt.show()"""



