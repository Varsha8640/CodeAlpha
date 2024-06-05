#include <iostream>
#include <vector>

using namespace std;

// Function to print the Sudoku grid
void printGrid(vector<vector<int>> &grid) {
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      cout << grid[i][j] << " ";
    }
    cout << endl;
  }
}

// Function to check if a number can be placed in a given cell
bool isSafe(vector<vector<int>> &grid, int row, int col, int num) {
  // Check row
  for (int i = 0; i < 9; i++) {
    if (grid[row][i] == num) {
      return false;
    }
  }

  // Check column
  for (int i = 0; i < 9; i++) {
    if (grid[i][col] == num) {
      return false;
    }
  }

  // Check 3x3 box
  int startRow = row - row % 3;
  int startCol = col - col % 3;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (grid[i + startRow