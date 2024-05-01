import os
import numpy as np


def create_matrix(count: int, size: int, path_to_folder: str) -> None:
    min = 0
    max = 1000
    for i in range(count):
        array = np.random.randint(min, max, (size, size))
        filename = os.path.join(path_to_folder, f"{size}_{i}.txt")
        np.savetxt(filename, array, delimiter=" ", fmt="%d")


def create_folders() -> None:
    matrix_dir = ["matrix_1", "matrix_2", "results"]
    lab_dir = ["Lab_1", "Lab_2", "Lab_3", "Lab_4"]

    if (os.path.isdir("..\\matrix") == False):
        os.mkdir("..\\matrix")
    for dir in matrix_dir:
        path_dir = os.path.join("..\\matrix", dir)
        if (os.path.isdir(path_dir) == False):
            os.mkdir(path_dir)
    
    if (os.path.isdir("..\\stats") == False):
        os.mkdir("..\\stats")
    for dir in lab_dir:
        path_dir = os.path.join("..\\stats", dir)
        if (os.path.isdir(path_dir) == False):
            os.mkdir(path_dir)



if __name__ == "__main__":
    COUNT = 100

    #  Генерация квадратных матриц в matrix_1 и в matrix_2
    create_folders()
    for i in range(50, 550, 50):
        create_matrix(COUNT, i, "..\\matrix\\matrix_1")
        create_matrix(COUNT, i, "..\\matrix\\matrix_2")