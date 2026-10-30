#include <iostream>
#include <iomanip>
#include <cstdint>

/*
 * LEVEL 2 (INTERMEDIATE): 2D Array Memory Addressing
 * Demonstrates: Row-Major and Column-Major addressing calculations
 * compared against actual pointer memory addresses in C++.
 *
 * Formulas for A[M][N] (0-based indexing):
 * - Row-Major:    Address = Base + (i * N + j) * sizeof(element)
 * - Column-Major: Address = Base + (j * M + i) * sizeof(element)
 */

int main() {
    const int ROWS = 3;
    const int COLS = 4;
    int matrix[ROWS][COLS];

    int val = 1;
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            matrix[i][j] = val++;
        }
    }

    uintptr_t baseAddr = reinterpret_cast<uintptr_t>(&matrix[0][0]);
    size_t elemSize = sizeof(int);

    std::cout << "Matrix Dimensions: " << ROWS << " rows x " << COLS << " cols\n";
    std::cout << "Base Address (B): 0x" << std::hex << baseAddr << std::dec << "\n";
    std::cout << "Element Size (S): " << elemSize << " bytes\n\n";

    // Verify for element at [2][2]
    int target_i = 2, target_j = 2;
    uintptr_t actualAddr = reinterpret_cast<uintptr_t>(&matrix[target_i][target_j]);
    uintptr_t rowMajorAddr = baseAddr + (target_i * COLS + target_j) * elemSize;
    uintptr_t colMajorAddr = baseAddr + (target_j * ROWS + target_i) * elemSize;

    std::cout << "Target element: matrix[" << target_i << "][" << target_j << "] = " 
              << matrix[target_i][target_j] << "\n";
    std::cout << "1. Actual Memory Address:           0x" << std::hex << actualAddr << "\n";
    std::cout << "2. Row-Major Calculated Address:     0x" << rowMajorAddr << "\n";
    std::cout << "3. Column-Major Calculated Address:  0x" << colMajorAddr << "\n";
    std::cout << std::dec;
    std::cout << "Conclusion: C++ stores 2D arrays in " 
              << (actualAddr == rowMajorAddr ? "ROW-MAJOR order." : "COLUMN-MAJOR order.") << "\n";

    return 0;
}
