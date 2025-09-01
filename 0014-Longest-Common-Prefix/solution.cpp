#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty())
            return "";
        // check the first string
        for (int i = 0; i < strs[0].length(); i++) {
            char currentChar = strs[0][i]; // get the character to compare

            // other strings
            for (int j = 1; j < strs.size(); j++) {
                // i is out of bounds or mismatch
                if (i >= strs[j].length() || strs[j][i] != currentChar) {
                    return strs[0].substr(0, i); // from first position to ith
                }
            }
        }

        // If all characters of the first string matched in every string
        return strs[0];
    }
};