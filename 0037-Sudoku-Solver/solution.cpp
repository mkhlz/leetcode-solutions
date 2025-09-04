#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        backtrack(board);
    }

private:
    bool backtrack(vector<vector<char>> &board) {
        // loop thru all rows
        for (int row = 0; row < 9; ++row) {
            // loop thru all cols
            for (int col = 0; col < 9; ++col) {
                // if current cell is empty
                if (board[row][col] == '.') {
                    // try placing digits from 1 to 9
                    for (char c = '1'; c <= '9'; ++c) {
                        // check if placing `c` is valid
                        if (isValid(board, row, col, c)) {
                            board[row][col] = c; // place the digit
                            if (backtrack(board)) {
                                return true;
                            }
                            // if not valid, remove char and backtrack
                            board[row][col] = '.';
                        }
                    }
                    // no valid digit can be placed, return false
                    // keep backtracking
                    return false;
                }
            }
        }
        // all spaces filled, return true
        return true;
    }

    // to check whether placing char `c` will result in a valid placement
    bool isValid(vector<vector<char>>& board, int row, int col, char c) {
        // check the row and col for same digit
        for (int i = 0; i < 9; ++i) {
            if (board[row][i] == c) return false;   // same digit found in row
            if (board[i][col] == c) return false;   // same digit found in col
        }
        // calculate starting indices for 3x3 grid
        int rowBox = (row / 3) * 3; // split row into 3 parts
        int colBox = (col / 3) * 3; // split col into 3 parts

        // check grids for the same digit
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                // same digit in grid
                if (board[rowBox + i][colBox + j] == c) return false;
            }
        }
        // no grid conflicts, valid to place `c`
        return true;
    }
};
