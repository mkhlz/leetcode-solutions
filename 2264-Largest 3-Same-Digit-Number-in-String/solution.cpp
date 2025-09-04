#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string largestGoodInteger(string num) {
        string ans; // to hold result 
        // Loop thru string till third last char
        for (int i = 0; i + 2 < num.size(); ++i) {
            // check if current and next two char are same
            if (num[i] == num[i+1] && num[i+1] == num[i+2]) {
                string current = num.substr(i,3);
                if (current > ans) ans = current;
            }
        }
        return ans;
    }
};