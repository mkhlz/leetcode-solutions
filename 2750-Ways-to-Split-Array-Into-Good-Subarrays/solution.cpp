#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfGoodSubarraySplits(vector<int>& nums) {
        const int MOD = 1e9 + 7;
        // collect position of all 1s
        vector<int> ones;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 1) ones.push_back(i);
        }
        // it no 1s, return 0
        if (ones.size() == 0) return 0;
        // if there's only 1 one, return 1
        if (ones.size() == 1) return 1;
        // otherwise, calculate number of ways
        long long ways = 1;
        for (int i = 1; i < ones.size(); ++i) {
            // calculate gap between consec 1s
            int gap = ones[i] - ones[i -1] - 1;
            ways = (ways * (gap + 1)) % MOD;
        }
        return (int)ways;
    }
};