#include <iostream>
#include <iomanip>
#include <cstdint>

/*
 * Demonstration of Row-Major and Column-Major Memory Addressing in 2D Arrays:
 *
 * Given an array A[M][N] where:
 *   Base Address = B
 *   Element Size = S (bytes)
 *   Row Index = i (0 <= i < M)
 *   Column Index = j (0 <= j < N)
 *
 * Formulas (0-based indexing):
 * 1. Row-Major Order (Used natively in C/C++):
 *    Address(A[i][j]) = B + (i * N + j) * S
 *
 * 2. Column-Major Order (Used in Fortran/MATLAB):
 *    Address(A[i][j]) = B + (j * M + i) * S
 */

int main() {
    const int ROWS = 3;
    const int COLS = 4;
    int arr[ROWS][COLS];

    // Populate array
    int counter = 1;
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            arr[i][j] = counter++;
        }
    }

    uintptr_t baseAddress = reinterpret_cast<uintptr_t>(&arr[0][0]);
    size_t elementSize = sizeof(int);

    std::cout << "============================================================\n";
    std::cout << "       2D Array Memory Addressing Demonstration in C++     \n";
    std::cout << "============================================================\n";
    std::cout << "Matrix Dimensions: " << ROWS << " rows x " << COLS << " columns\n";
    std::cout << "Base Address (B): 0x" << std::hex << baseAddress << std::dec << "\n";
    std::cout << "Element Size (S): " << elementSize << " bytes\n\n";

    std::cout << "Matrix values and actual physical addresses in memory:\n";
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            uintptr_t actualAddr = reinterpret_cast<uintptr_t>(&arr[i][j]);
            std::cout << "arr[" << i << "][" << j << "] = " << std::setw(2) << arr[i][j]
                      << " | Addr: 0x" << std::hex << actualAddr << std::dec << "\n";
        }
    }

    std::cout << "\n------------------------------------------------------------\n";
    std::cout << "Verifying Calculated vs Actual Addresses (Target: arr[2][2]):\n";
    int target_i = 2;
    int target_j = 2;

    // Row-Major Calculation
    uintptr_t calcRowMajor = baseAddress + (target_i * COLS + target_j) * elementSize;
    uintptr_t actualTargetAddr = reinterpret_cast<uintptr_t>(&arr[target_i][target_j]);

    std::cout << "Target element: arr[" << target_i << "][" << target_j << "]\n";
    std::cout << "Actual address:            0x" << std::hex << actualTargetAddr << "\n";
    std::cout << "Row-Major formula result:  0x" << calcRowMajor << "\n";
    std::cout << "Match status: " << (actualTargetAddr == calcRowMajor ? "VERIFIED (Row-major used by C++)" : "MISMATCH") << "\n";

    // Column-Major Calculation for comparison
    uintptr_t calcColMajor = baseAddress + (target_j * ROWS + target_i) * elementSize;
    std::cout << "Col-Major formula result:  0x" << calcColMajor << " (Used in Fortran/Julia/MATLAB)\n";
    std::cout << std::dec;

    return 0;
}
