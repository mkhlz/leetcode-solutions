#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // trackers for all digits 0-9
        vector<vector<bool>> rows(9, vector<bool>(9, false));   // row[i][num] true if seen in row i
        vector<vector<bool>> cols(9, vector<bool>(9, false));   // cols[j][num] true if seen in col j
        vector<vector<bool>> boxes(9, vector<bool>(9, false));  // boxes[b][num] true if seen in box b

        for(int i = 0; i < 9; ++i) {    // loop each row
            for (int j = 0; j < 9; ++j) {   // loop each col
                char c = board[i][j];   // current cell char
                if (c == '.') continue; // if `.` skip
                int num = c - '1';  // convert to num
                int boxIndex = (i / 3) * 3 + (j / 3);   // compute box index

                // check if valid in row, col, box
                if (rows[i][num]) return false;
                if (cols[j][num]) return false;
                if (boxes[boxIndex][num]) return false;

                rows[i][num] = true;
                cols[j][num] = true;
                boxes[boxIndex][num] = true;
            }
        }
        return true;    // no conflics, board is valid
    }
};