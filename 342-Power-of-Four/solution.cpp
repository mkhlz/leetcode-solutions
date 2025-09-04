#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n <= 0) return false;

        // Check if n has exactly one set bit
        if (__builtin_popcount(n) != 1) return false;

        // Check if the set bit is at an even position
        return (n & 0x55555555) != 0;
    }
};