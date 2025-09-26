#include <bits/stdc++.h>
using namespace std;

class Spreadsheet {
    int R; // number of rows
    vector<vector<int>> grid; // our 2D sheet (rows x 26 cols)

    // helper: parse cell like "A12" → (row, col)
    pair<int, int> parseCell(const string &s) {
        int col = s[0] - 'A';
        int row = stoi(s.substr(1)) - 1; // 1-based to 0-based
        return {row, col};
    }

    // helper: check if token is number or cell
    int getTokenValue(const string &tok) {
        if (isdigit(tok[0])) {
            return stoi(tok); // if it's a number, easy
        } else {
            auto [r,c] = parseCell(tok);
            return grid[r][c]; // else fetch from grid
        }
    }

public:
    Spreadsheet(int rows) {
        R = rows;
        grid.assign(R, vector<int>(26, 0)); // init all 0
    }

    void setCell(string cell, int value) {
        auto [r,c] = parseCell(cell);
        grid[r][c] = value;
    }

    void resetCell(string cell) {
        auto [r,c] = parseCell(cell);
        grid[r][c] = 0;
    }

    int getValue(string formula) {
        string expr = formula.substr(1); // remove '='
        size_t pos = expr.find('+');
        string t1 = expr.substr(0, pos);
        string t2 = expr.substr(pos + 1);
        return getTokenValue(t1) + getTokenValue(t2);
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */