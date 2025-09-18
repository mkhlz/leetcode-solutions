#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        // build bitmask for broken letters
        int mask = 0;
        for (char c : brokenLetters) {
            mask |= 1 << (c - 'a');
        }
        int count = 0;
        bool bad = false;
        for (char c : text) {
            if (c == ' ') {
                if (!bad) count++;
                bad = false;
            } else if (mask & (1 << (c - 'a'))) {
                bad = true;
            }
        }
        if (!bad) count++; // last word
        return count;
    }
};
