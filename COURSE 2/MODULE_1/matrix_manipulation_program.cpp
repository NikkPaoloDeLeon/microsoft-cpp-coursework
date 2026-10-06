#include <iostream>
#include <string>
#include <array>
#include <random>
#include <iomanip>

// Forward declarations for random generation and operation functions
int generateRandomNumber();

// Forward declarations for printing functions
template<size_t Row, size_t Col>
void printMatrix(const std::array<std::array<int, Col>, Row>& matrixA);
template<size_t Row, size_t Col>
void printMatrixAB(const std::array<std::array<int, Col>, Row>& matrixA, const int (&matrixB)[Row][Col]);
template<size_t Row, size_t Col>
void printMatrixAC(const std::array<std::array<int, Col>, Row>& matrixA, const std::array<std::array<int, Col>, Row>& matrixC);

// Perform basic operations 
template<size_t Row, size_t Col>
std::array<std::array<int, Col>, Row> matrixAddition(const std::array<std::array<int, Col>, Row>& matrixA, const int (&matrixB)[Row][Col]);
template<size_t Row, size_t Col>
std::array<std::array<int, Col>, Row> matrixMultiplication(const std::array<std::array<int, Col>, Row>& matrixA, const int (&matrixB)[Row][Col]);

// Perform matrix transposition 
template<size_t Row, size_t Col>
std::array<std::array<int, Col>, Row> matrixTransposition(const std::array<std::array<int, Row>, Col>& matrixA);

// Get determinant of matrix
template<size_t Row, size_t Col>
int matrixDeterminant(std::array<std::array<int, Col>, Row>& matrixA);

// Implement matrix operations such as addition, multiplication, transpose, and determinant calculation.
int main() {
    std::array<std::array<int, 3>, 3> test1 = {{
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    }};
    int test2[3][3] = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}
    };
    // Sync seed to system time
    std::srand(static_cast<unsigned>(time(0)));
    // Initialize the matrices
    std::array<std::array<int, 3>, 3> matrixA;
    int matrixB[3][3];
    
    int sizeSTD2 = static_cast<int>(std::size(matrixA));

    // Populate stdarray with random numbers
    for (int row {0}; row < sizeSTD2; row++) {
        for (int col {0}; col < sizeSTD2; col++) {
            matrixA[row][col] = generateRandomNumber();
        }
    }
    
    for (auto& Rows : matrixB) {
        for (int& Cols : Rows) {
            Cols = generateRandomNumber();
        }
    }

    printMatrixAB(matrixA, matrixB);



    // Add matrixA and matrixB
    std::array<std::array<int, 3>, 3> matrixSum = matrixAddition(matrixA, matrixB);
    std::array<std::array<int, 3>, 3> matrixProduct =  matrixMultiplication(test1, test2);

    printMatrix(matrixSum);
    std::cout << std::string(30, '-') << '\n';
    printMatrix(matrixProduct);

    std::array<std::array<int, 3>, 3> transposedMatrixA = matrixTransposition(matrixA);
    printMatrixAC(matrixA, transposedMatrixA);

    int determinant = matrixDeterminant(matrixA);
    std::cout << determinant;


    return 0;
}
// Function to print matrixA and matrixB 
template<size_t Row, size_t Col>
void printMatrixAB(const std::array<std::array<int, Col>, Row>& matrixA, const int (&matrixB)[Row][Col]) {
    // Boundary checks
    if (matrixA.size() != std::size(matrixB) && matrixA[0].size() != std::size(matrixB[0])) {
        std::cout << "Incompatible for addtion operation. Both arrays have different dimenstions." << '\n';
        return;
    }
    std::cout << std::left << std::setw(15) << "Matrix A" 
        << std::left << std::setw(12) << "Matrix B" << '\n';
    std::cout << std::string(28, '-') << '\n';
    for (int row {0}; row < 3; row++) {
        for (int col {0}; col < 3; col++) {
            std::cout << std::left << std::setw(3) << matrixA[row][col] << ' ';
        }
        std::cout << "  ";
        for (int col {0}; col < 3; col++) {
            std::cout << std::left << std::setw(3) << matrixB[row][col] << ' ';
        }
        std::cout << '\n';
    }
}

// Function to print matrixA and its transposed part.
template<size_t Row, size_t Col>
void printMatrixAC(const std::array<std::array<int, Col>, Row>& matrixA, const std::array<std::array<int, Col>, Row>& matrixC) {
    // Boundary checks
    if (matrixA.size() != std::size(matrixC) && matrixA[0].size() != std::size(matrixC[0])) {
        std::cout << "Incompatible for addtion operation. Both arrays have different dimenstions." << '\n';
        return;
    }
    std::cout << std::left << std::setw(15) << "Matrix A" 
        << std::left << std::setw(12) << "Matrix A (transposed)" << '\n';
    std::cout << std::string(28, '-') << '\n';
    for (int row {0}; row < 3; row++) {
        for (int col {0}; col < 3; col++) {
            std::cout << std::left << std::setw(3) << matrixA[row][col] << ' ';
        }
        std::cout << "  ";
        for (int col {0}; col < 3; col++) {
            std::cout << std::left << std::setw(3) << matrixC[row][col] << ' ';
        }
        std::cout << '\n';
    }
}

// Function to print the elements of the Matrix A
template<size_t Row, size_t Col>
void printMatrix(const std::array<std::array<int, Col>, Row>& matrixA) {
    int size = static_cast<int>(std::size(matrixA));
    for (int row {0}; row < size;  row++) {
        for (int col {0}; col < size; col++) {
            std::cout << matrixA[row][col] << " ";
        }
        std::cout << '\n';
    }
}

template<size_t Row, size_t Col>
std::array<std::array<int, Col>, Row> matrixAddition(const std::array<std::array<int, Col>, Row>& matrixA, const int (&matrixB)[Row][Col]) {
    std::array<std::array<int, 3>,3> matrixC;
    for (int row {0}; row < 3; row++) {
        for (int col {0}; col < 3; col++) {
            std::cout << "Adding numbers in row " << (row + 1) << " from matrixA and matrixB " << 
            matrixA[row][col] << " + " << matrixB[row][col] << '\n';
            matrixC[row][col] = matrixA[row][col] + matrixB[row][col];
        }
    }
    return matrixC;
}

template<size_t Row, size_t Col>
std::array<std::array<int, Col>, Row> matrixMultiplication(const std::array<std::array<int, Col>, Row>& matrixA, const int (&matrixB)[Row][Col]) {
    std::array<std::array<int, Col>, Row> matrixProduct;
    int sum {0};
    for (size_t i {0}; i < 3; i++) {
        for (size_t j {0}; j < 3; j++) {
            // std::cout << "Multiplyin numbers in row " << (row + 1) << " from matrixA and matrixB " << 
            for (size_t k {0}; k < 3; k++) {
                sum += (matrixA[j][k] * matrixB[k][i]); 
            }
            matrixProduct[j][i] = sum;
            sum = 0;
        }
    }
    return matrixProduct;
} 

template<size_t Row, size_t Col>
std::array<std::array<int, Col>, Row> matrixTransposition(const std::array<std::array<int, Row>, Col>& matrixA) {
    std::array<std::array<int, Col>, Row> transposedMatrixA;
    for (size_t row {0};  row < Row; row++) {
        for (size_t col {0}; col < Col; col++) {
            std::cout << "Tranposition of Rows and columns of matrixA. " <<
            "Position " << '(' << row << ", " << col << ')' << " to " << 
             "Position " << '(' << col << ", " << row << ')' << '\n';
             transposedMatrixA[row][col] = matrixA[col][row];
        }
    }
    return transposedMatrixA;
}

template<size_t Row, size_t Col>
int matrixDeterminant(std::array<std::array<int, Col>, Row>& matrixA) {
    int determinant {0};
    determinant = (matrixA[0][0] * ((matrixA[1][1] * matrixA[2][2]) - (matrixA[1][2] * matrixA[2][1]))) - 
        (matrixA[0][1] * ((matrixA[1][0] * matrixA[2][2]) - (matrixA[1][2] * matrixA[2][0]))) + 
        (matrixA[0][2] * ((matrixA[1][0] * matrixA[2][1]) - (matrixA[1][1] * matrixA[2][0])));
    return determinant;
} 

int generateRandomNumber() {
    return (std::rand() % (100 - 1 + 1) + 1);
}