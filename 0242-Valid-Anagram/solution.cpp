#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        int freq[26] = {0};
        for (int i = 0; i < s.size(); ++i) {
            int index_s = s[i] - 'a';
            int index_t = t[i] - 'a';
            freq[index_s] = freq[index_s] + 1;
            freq[index_t] = freq[index_t] - 1;
        }
        for (int i = 0; i < 26; ++i) {
            if (freq[i] != 0) return false;
        }
        return true;
    }
};