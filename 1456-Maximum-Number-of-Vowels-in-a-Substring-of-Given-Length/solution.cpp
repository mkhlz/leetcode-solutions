#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxVowels(string s, int k) {
        // set of vowels
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        int n = s.size();
        int currentCount = 0; // vowels in current window
        int maxCount = 0; // best answer so far
        // count vowels in current window
        for (int i = 0; i < k; ++i) {
            if (vowels.count(s[i])) currentCount;
        }
        maxCount = currentCount; // initial best
        for (int i = 1; i < n; ++i) {
            if (vowels.count(s[i])) currentCount++; // new char
            if (vowels.count(s[i - k])) currentCount--; // discard
            maxCount = max(maxCount, currentCount); // update max
        }
        return maxCount;
    }
};