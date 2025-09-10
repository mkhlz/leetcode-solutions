#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool closeStrings(string w1, string w2) {
        // edge case, word lengths differ
        if (w1.size() != w2.size()) return false;
        // count chars for both words
        vector<int> f1(26, 0), f2(26, 0);
        for(char c : w1) f1[c-'a']++;
        for(char c : w2) f2[c-'a']++;
        // check if both have same unique letters
        for (int i = 0; i < 26; ++i) {
          if ((f1[i]==0) != (f2[i]==0)) return false;
        }
        // sort freq and compare
        sort(f1.begin(), f1.end());
        sort(f2.begin(), f2.end());
        return f1 == f2;
    }
};