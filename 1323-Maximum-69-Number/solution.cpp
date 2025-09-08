#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximum69Number (int num) {
        // convert to string for easy manipulation
        string s = to_string(num);
        // find 6, change it to 9
        for (char &c : s) {
            if (c == '6') {
                c = '9';
                break;  // can't make more changes
            }
        }
        return stoi(s);
    }
};