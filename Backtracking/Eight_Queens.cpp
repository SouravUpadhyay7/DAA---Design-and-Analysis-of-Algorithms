#include <stdio.h>

#define N 8 // Chessboard size (8x8)

// Function to print the chessboard
void printBoard(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf(board[i][j] ? " Q " : " . ");
        printf("\n");
    }
    printf("\n");
}

// Function to check if a queen can be placed at board[row][col]
int isSafe(int board[N][N], int row, int col) {
    for (int i = 0; i < row; i++) // Check column
        if (board[i][col]) return 0;
    
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) // Check upper left diagonal
        if (board[i][j]) return 0;

    for (int i = row - 1, j = col + 1; i >= 0 && j < N; i--, j++) // Check upper right diagonal
        if (board[i][j]) return 0;

    return 1;
}

// Function to solve the N-Queens problem using Backtracking
int solveNQueens(int board[N][N], int row) {
    if (row >= N) { // All queens placed successfully
        printBoard(board);
        return 1;
    }

    for (int col = 0; col < N; col++) {
        if (isSafe(board, row, col)) {
            board[row][col] = 1; // Place queen
            if (solveNQueens(board, row + 1)) // Recur to place next queen
                return 1;
            board[row][col] = 0; // Backtrack
        }
    }

    return 0; // No solution found
}

// Main function
int main() {
    int board[N][N] = {0}; // Initialize board with 0

    if (!solveNQueens(board, 0))
        printf("No solution exists!\n");

    return 0;
}

