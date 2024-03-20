import os
import numpy as np


def create_matrix(count: int, size: int, path_to_folder: str) -> None:
    min = 0
    max = 1000
    for i in range(count):
        array = np.random.randint(min, max, (size, size))
        filename = os.path.join(path_to_folder, f"{size}_{i}.txt")
        np.savetxt(filename, array, delimiter=" ", fmt="%d")


if __name__ == "__main__":
    COUNT = 100

    #  Генерация квадратных матриц в matrix_1 и в matrix_2
    for i in range(50, 550, 50):
        create_matrix(COUNT, i, "..\\matrix\\matrix_1")
        create_matrix(COUNT, i, "..\\matrix\\matrix_2")