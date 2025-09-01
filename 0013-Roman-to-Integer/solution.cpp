#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> romanMap = {{'I', 1},   {'V', 5},   {'X', 10},
                                             {'L', 50},  {'C', 100}, {'D', 500},
                                             {'M', 1000}};

        int total = 0; // Final value

        // Check each character
        for (int i = 0; i < s.length(); i++) {
            int currVal = romanMap[s[i]];

            // Check if the next symbol exists and has a greater value
            if (i + 1 < s.length() && currVal < romanMap[s[i + 1]]) {
                total -= currVal;
            } else {
                total += currVal;
            }
        }

        return total;
    }
};