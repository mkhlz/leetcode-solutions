#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int makeTheIntegerZero(long long num1, long long num2) {
        for (int ops = 1; ops <= 60; ops++) { // Given range is `0 to 60`
            long long x = num1 - num2 * ops; // Remaining after subtracting ops times
            if (x < 0) break; // If negative, further ops won't help
            int bits = __builtin_popcountll(x); // Count set bits in x
            if (bits <= ops && x >= ops) { // Check feasibility
                return ops; // Found minimum ops
            }
        }
        return -1; // Not possible
    }
};
  