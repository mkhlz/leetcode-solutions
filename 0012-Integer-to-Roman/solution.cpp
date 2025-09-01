#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        // store a map
        vector<pair<int, string>> roman = {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
            {100, "C"},  {90, "XC"},  {50, "L"},  {40, "XL"},
            {10, "X"},   {9, "IX"},   {5, "V"},   {4, "IV"}, {1, "I"}
        };
        string result = "";        
        // Loop through each value-symbol pair
        for (auto &p : roman) {
            while (num >= p.first) {
                num -= p.first;          // Subtract value
                result += p.second;      // Append symbol
            }
        }    
        return result;
    }
};

int main() {
    int num = 2007;
    Solution sol;
    cout << sol.intToRoman(num) << endl;
    return 0;
}