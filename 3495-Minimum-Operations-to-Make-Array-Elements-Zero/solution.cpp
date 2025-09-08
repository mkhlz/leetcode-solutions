#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minOperations(vector<vector<int>>& queries) {
        long long totalOps = 0;
        
        for (auto &q : queries) {
            long long l = q[0], r = q[1];
            long long steps = 0;
            
            long long levelStart = 1;
            while (levelStart <= r) {
                long long rangeStart = max(l, levelStart);
                if (rangeStart <= r) {
                    steps += (r - rangeStart + 1);
                }
                if (levelStart > LLONG_MAX / 4) break; // prevent overflow
                levelStart *= 4;
            }
            
            totalOps += (steps + 1) / 2; // ceil division by 2
        }
        
        return totalOps;
    }
};
