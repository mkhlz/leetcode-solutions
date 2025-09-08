#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0, j = 0;
        // loop thru t and check for s chars
        while (i < s.size() && j < t.size()) {
            if (s[i] == t[j]) i++;  // match found
            j++;    // always move j forward
        }
        // check if all chars matched
        return i == s.size();
    }
};