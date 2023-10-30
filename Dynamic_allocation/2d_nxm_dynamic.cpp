#include <iostream>

int main() {
    int row = 5, column = 10;
    int **r = new int*[row];

    // Allocate memory for each row
    for (int i = 0; i < row; i++) {
        r[i] = new int[column];
    }

    // Initialize the matrix with some values
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            r[i][j] = i * j;
        }
    }

    // Print the matrix
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            std::cout << r[i][j] << " ";
        }
        std::cout << std::endl;
    }

    // Free the memory
    for (int i = 0; i < row; i++) {
        delete[] r[i];
    }
    delete[] r;

    return 0;
}