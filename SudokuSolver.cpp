#include <bits/stdc++.h> 

 

bool isSafe(int row, int col, vector<vector<int>>& board, int value) 

{

    for (int i = 0; i < board.size(); i++) {

        // Row check

        if (board[i][col] == value) {

            return false;

        }

        // Column check

        if (board[row][i] == value) {

            return false;

        }

        // 3x3 Matrix check

        if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == value) {

            return false;

        }

    }

    return true;

}

 

bool solve(vector<vector<int>>& board) 

{

 

    int n = board[0].size();

 

    for (int row = 0; row < n; row++) 

    {

        for (int col = 0; col < n; col++) 

        {

            // If cell is empty

            if (board[row][col] == 0) 

            {

                for (int val = 1; val <= 9; val++) 

                {

                    if (isSafe(row, col, board, val)) 

                    {

                        board[row][col] = val;

 

                        // Recursion call

                        if (solve(board)) 

                        {

                            return true;

                        } 

                        else 

                        {

                            // Backtrack

                            board[row][col] = 0;

                        }

                    }

                }

                return false; // No solution for this configuration

            }

        }

    }

 

    return true; // Sudoku solved successfully

}

 

void solveSudoku(vector<vector<int>>& sudoku) {

    // No need to print the final sudoku

    // Just fill the values in the given matrix

    solve(sudoku);

}