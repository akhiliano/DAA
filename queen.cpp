#include <iostream>
using namespace std;

// Function to check if it's safe to place a queen at board[row][col]
bool isSafe(int board[][10], int row, int col, int n) {
    // Check for queens in the same column
    for (int i = 0; i < row; i++)
        if (board[i][col] == 1)
            return false;

    // Check upper-left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == 1)
            return false;

    // Check upper-right diagonal
    for (int i = row, j = col; i >= 0 && j < n; i--, j++)
        if (board[i][j] == 1)
            return false;

    return true;
}

// Recursive function to place queens using backtracking
bool solveNQueens(int board[][10], int row, int n) {
    // If all queens are placed
    if (row == n)
        return true;

    // Try placing queen in each column of the current row
    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col, n)) {
            board[row][col] = 1;  // Place queen

            // Recur to place the next queen
            if (solveNQueens(board, row + 1, n))
                return true;

            // If placing queen in this column doesn't lead to a solution, backtrack
            board[row][col] = 0;
        }
    }

    return false;  // No place to put a queen in this row
}

// Function to print the board
void printBoard(int board[][10], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << (board[i][j] == 1 ? "Q " : ". ");
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter the size of the board (N): ";
    cin >> n;

    // Initialize an NxN chess board with all positions empty (0)
    int board[10][10] = {0};  // Assuming max N is 10 for simplicity

    int firstQueenCol;
    cout << "Enter the column for the first queen in row 0 (0-based index): ";
    cin >> firstQueenCol;

    // Place the first queen at row 0, specified by the user
    board[0][firstQueenCol] = 1;

    // Use backtracking to place the remaining queens
    if (solveNQueens(board, 1, n)) {
        cout << "The final solution matrix for N-Queens is:\n";
        printBoard(board, n);
    } else {
        cout << "No solution exists for the given configuration.\n";
    }

    return 0;
}
