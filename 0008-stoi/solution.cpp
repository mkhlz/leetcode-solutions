#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int pos = 0;
        int n = s.size();
        while (pos < n && s[pos] == ' ') pos++; // skip spaces
        int sign = 1;
        if (pos < n && (s[pos] == '+' || s[pos] == '-')) {
            sign = (s[pos] == '-') ? -1 : 1;    // check sign
            pos++;
        }
        int result = 0;
        while (pos < n && isdigit(s[pos])) {
            int digit = s[pos] - '0';

            // check overflow
            if (result > INT_MAX / 10 || (result == INT_MAX / 10 && digit > 7)) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }

            result = result * 10 + digit;
            pos++;
        }

        return result * sign;
    }
};