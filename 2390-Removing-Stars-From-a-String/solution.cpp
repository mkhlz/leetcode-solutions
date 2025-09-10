#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeStars(string s) {
        int j = 0; // size of stack
        for (int i = 0; i < s.size(); ++i) {
          if (s[i] == '*') {
            if (j > 0) --j; // found star, drop char
          } else {
            s[j++] = s[i];
          }
        }
        return s.substr(0, j);
    }
};