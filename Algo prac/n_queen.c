#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>


// N is the number of queens
#define N 4

// A utility function to check if a queen can be placed on board[row][col]
// row : The row index of the queen
// col : The column index of the queen
bool isSafe(int board[][N], int row, int col)
{
    // Check if the queen can be placed in the row
    for (int i = 0; i < col; i++)
    {
        if (board[row][i])
        {
            return false;
        }
    }


    // Check if the queen can be placed in the column
    for (int i = 0; i < row; i++)
    {
        if (board[i][col])
        {
            return false;
        }
    }

    // Check if the queen can be placed in the top-left diagonal
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j])
        {
            return false;
        }
    }

    // Check if the queen can be placed in the bottom-right diagonal
    for (int i = row + 1, j = col + 1; i < N && j < N; i++, j++)
    {
        if (board[i][j])
        {
            return false;
        }
    }

    return true;
}

// A recursive function to solve the N-queens problem
bool solveNQueens(int board[][N], int col)
{
    // If all queens are placed, return true
    if (col == N)
    {
        return true;
    }

    // Try to place the queen in the current column
    for (int row = 0; row < N; row++)
    {
        // If the queen can be placed in the current row, place it
        if (isSafe(board, row, col))
        {
            board[row][col] = 1;

            // Recursively solve the N-queens problem for the next column
            if (solveNQueens(board, col + 1))
            {
                return true;
            }

            // If the N-queens problem cannot be solved for the next column,
            // backtrack by removing the queen from the current row
            board[row][col] = 0;
        }
    }

    // If the queen cannot be placed in any row in the current column,
    // return false
    return false;
}

// A utility function to print the solution
void printSolution(int board[][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (board[i][j])
            {
                printf("1 ");
            }
            else
            {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

// Driver code
int main()
{
    int board[N][N];

    // Initialize the board to 0
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            board[i][j] = 0;
        }
    }

    // Solve the N-queens problem
    if (solveNQueens(board, 0))
    {
        // Print the solution
        printSolution(board);
    }
    else
    {
        printf("No solution exists for N-queens problem\n");
    }

    return 0;
}
