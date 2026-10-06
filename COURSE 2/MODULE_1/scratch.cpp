#include <iostream>

int main() {
    int matrix[3][3] = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
    };

    int matrixB[3][3] = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}
    };

    int matrixC[3][3];
    

    for (int rows {0}; rows < 3; rows++) {
        for (int cols {0}; cols < 3; cols++) {
            matrixC[rows][cols] = matrix[rows][cols] + matrixB[rows][cols];
        }
    }

    /*for (int rows {0}; rows < 3; rows++) {
        for (int cols {0}; cols < 3; cols++) {
            matrix[rows][cols] *= 2;
        }
    }*/
    for (int rows {0}; rows < 3; rows++) {
        for (int cols {0}; cols < 3; cols++) {
            std::cout << matrixC[rows][cols] << ' ';
        }
        std::cout << '\n';
    }

}