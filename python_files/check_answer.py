import os

import numpy as np


DIR_MATRIX_1 = "..\\matrix\\matrix_1"
DIR_MATRIX_2 = "..\\matrix\\matrix_2"
DIR_RESULTS = "..\\matrix\\results"


if __name__ == "__main__":
    for file_matrix in os.scandir(DIR_MATRIX_1):
        path_matrix_1 = os.path.join(DIR_MATRIX_1, file_matrix.name)
        path_matrix_2 = os.path.join(DIR_MATRIX_2, file_matrix.name)
        path_results = os.path.join(DIR_RESULTS, file_matrix.name)

        matrix_1 = np.loadtxt(path_matrix_1, dtype=int, delimiter=" ")
        matrix_2 = np.loadtxt(path_matrix_2, dtype=int, delimiter=" ")
        results = np.loadtxt(path_results, dtype=int, delimiter=" ")

        if(np.array_equal(np.dot(matrix_1, matrix_2), results) == False):
            print(f"{file_matrix.name} - False")