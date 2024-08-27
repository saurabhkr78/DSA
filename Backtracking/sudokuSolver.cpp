#include <iostream>
using namespace std;

// Function to check if it's safe to place a number in a cell
bool isSafe(int grid[9][9], int row, int col, int num) {
    // Check the row
    for (int x = 0; x < 9; x++)
        if (grid[row][x] == num)
            return false;

    // Check the column
    for (int x = 0; x < 9; x++)
        if (grid[x][col] == num)
            return false;

    // Check the 3x3 subgrid
    int startRow = row - row % 3, startCol = col - col % 3;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (grid[i + startRow][j + startCol] == num)
                return false;

    return true;
}

// Function to find an empty cell
bool findEmptyCell(int grid[9][9], int &row, int &col) {
    for (row = 0; row < 9; row++)
        for (col = 0; col < 9; col++)
            if (grid[row][col] == 0)
                return true;
    return false;
}

// Function to solve the Sudoku puzzle using backtracking
bool solveSudoku(int grid[9][9]) {
    int row, col;

    // If there are no empty cells, the puzzle is solved
    if (!findEmptyCell(grid, row, col))
        return true;

    for (int num = 1; num <= 9; num++) {
        if (isSafe(grid, row, col, num)) {
            grid[row][col] = num;

            if (solveSudoku(grid))
                return true;

            // Undo and try the next number
            grid[row][col] = 0;
        }
    }

    return false; // Triggers backtracking
}

// Function to print the Sudoku grid
void printGrid(int grid[9][9]) {
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++)
            cout << grid[row][col] << " ";
        cout << endl;
    }
}

// Main function
int main() {
    int grid[9][9] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    if (solveSudoku(grid))
        printGrid(grid);
    else
        cout << "No solution exists" << endl;

    return 0;
}
