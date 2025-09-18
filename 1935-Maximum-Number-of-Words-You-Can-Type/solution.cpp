#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_set<char> broken(brokenLetters.begin(), brokenLetters.end());
        int count = 0;
        bool bad = false;
        for (char c : text) {
            if (c == ' ') {
                if (!bad) count++; // word is valid
                bad = false; // reset for next word
            } else if (broken.count(c)) {
                bad = true; // found broken letter in this word
            }
        }
        // last word check
        if (!bad) count++;
        return count;
    }
};