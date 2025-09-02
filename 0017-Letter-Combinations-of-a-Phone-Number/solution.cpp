#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result; // declare empty result variable
        if (digits.empty()) return result;
        // numbers and their characters map
        vector<string> mapping = {
            "","","abc","def","ghi","jkl","mno",
            "pqrs","tuv","wxyz", };
        // backtrack
        backtrack(digits, 0, "", mapping, result);
        return result;
    }
private:
    void backtrack(const string &digits, int index, string current, const vector<string> &mapping, vector<string> &result) {
        // if we have processed all digits, add current to result
        if (index == digits.size()) {
            result.push_back(current);
            return;
        }
        int digit = digits[index] - '0'; // get current digit from index
        string letters = mapping[digit]; // get associated letters
        // traverse thru each letter and recurse
        for (int i = 0; i < letters.size(); ++i) {
            // append current letter and move to next digit
            backtrack(digits, index + 1, current + letters[i], mapping, result);
        }
    }
};