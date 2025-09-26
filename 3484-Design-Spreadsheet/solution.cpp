#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

class Spreadsheet {
        int R; // number of rows
        vector<vector<int>> grid; // rows x 26 grid

        // helper to parse cell locations eg. "A12" -> (row, col), 0 indexed
        inline pair<int,int> parseCell(const string &s) {
            int col = s[0] - 'A';
            int row = 0;
            for (int i = 1; i < (int)s.size(); ++i) {
                row = row * 10 + (s[i] - '0');
            }
            return {row - 1, col}; // row is 1-based in input
        }

        // helper to check if token is number or cell
        inline int getTokenValue(const string &tok) {
            if (tok[0] >= '0' && tok[0] <= '9') {
                int val = 0;
                for (char ch : tok) val = val * 10 + (ch - '0');
                return val;
            } else {
                auto [r,c] = parseCell(tok);
                return grid[r][c];
            }
        }

public:
    Spreadsheet(int rows) {
        R = rows;
        grid.assign(R, vector<int>(26, 0));
    }
    
    void setCell(string cell, int value) {
        auto [r,c] = parseCell(cell);
        grid[r][c] = value;    
    }
    
    void resetCell(string cell) {
        auto [r,c] = parseCell(cell);
        grid[r][c] = 0;
    }
    // evaluate "=X+Y" where X,Y are cell or int
    int getValue(const string &formula) {
        // formula always looks like "=X+Y"
        int n = formula.size();
        // find '+'
        int plusPos = -1;
        for (int i = 1; i < n; i++) {
            if (formula[i] == '+') {
                plusPos = i;
                break;
            }
        }
        string tok1 = formula.substr(1, plusPos - 1);
        string tok2 = formula.substr(plusPos + 1);
        return getTokenValue(tok1) + getTokenValue(tok2);
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */