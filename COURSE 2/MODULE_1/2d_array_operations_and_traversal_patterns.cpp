#include <iostream>

// Create a 5x5 seating chart (0 =  available, 1 = occupied)
int main() {

    int seating1[5][5] = {
        {0, 1, 0, 1, 0},
        {1, 1, 0, 0, 1},
        {0, 0, 1, 1, 0},
        {1, 0, 0, 1, 1},
        {1, 1, 1, 0, 0}
    };
    /*int Testseating1[5][5] = {
        {0, 1},
        {1, 1, 0, 0, 1},
        {0, 0, 1, 1, 0},
        {1, 0, 0, 1, 1},
        {0, 1, 1, 0, 0}
    };
    int seating2[4][6] = {
        {1, 0, 0, 0, 0, 0},
        {1, 0, 0, 1, 1, 0},
        {1, 1, 1, 1, 0, 1},
        {0, 1, 1, 1, 0, 1}
    };*/

    std::cout << "Theater seating chart initialized!" << '\n';
    std::cout << "0 = available, 1 =  occupied" << '\n';
    // Check seats at (row 2, column3) and (row 4, column1)
    std::cout << "Row 2, Column 3 is " << (seating1[1][2] == 1 ? "Occupied" : "Available") << '\n';
    std::cout << "Row 4, Column 1 is " << (seating1[3][0] == 1 ? "Occupied" : "Available") << '\n';
    // Reserve seat at row 3, column 2
    std::cout << "Reserving seat for row 3, column 2..." << '\n';
    seating1[2][1] = 1;
    std::cout << "Seat reserved!" << '\n';



    // Row major traversal
    std::cout << "Seating chart (row by row):" << '\n';
    for (int row {0}; row < 5; row++) {
        std::cout <<  "Row " <<  (row + 1) << ": ";
        for (int col {0}; col < 5; col++) {
            std::cout << seating1[row][col] << ' ';
        }
        std::cout << '\n';
    }

    // Your code here: Implement column major traversal (column by column)
    std::cout << "Seating chart (column by column: )" << '\n';
    for (int col {0}; col < 5; col++) {
        std::cout << "Column " << (col + 1) << ": ";
        for (int row {0}; row < 5; row++) {
            std::cout << seating1[row][col] << ' ';
        }
        std::cout << '\n';
    }

    // Count total and available seats
    int available {0}, occupied {0};
    for (const auto& row : seating1) {
        for (int col : row) {
            if (col == 1) {
                occupied++;
            } else {
                available++;
            }
        }
    }
    std::cout << "Number of seats available: " << available << '\n';
    std::cout << "Number of seats occupied: " << occupied << '\n';

    // Safe access function
    auto getSeat = [&](int row, int col) -> std::string {
        if (row >= 0 && row < 5 && col >= 0 && col < 5) {
            return (seating1[row][col] == 1 ? "Occupied" : "Availalbe");
        } else {
            std::cout << "Invalid seat position: row " << row
                << ", col " << col << '\n';
                return "Invalid!";
        }
    };

    // Test valid access
    std::cout << "Valid access - Row 2, Col 3: " << getSeat(1, 2) << '\n';
    // Test invalid access
    std::cout << "Invalid access - Row 6, Col 3: " << getSeat(5, 2) << '\n';
    std::cout << "Invalid access - Row 3, Col 8: " << getSeat(2, 7) << '\n';
    std::cout << "Invalid access - Row -1, Col 2: " << getSeat(-1, 1) << '\n';

    return 0;
}