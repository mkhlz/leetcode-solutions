#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int left = 0; // left side
        int zeroCount = 0; // track 0s inside window
        int maxLen = 0; // store best window size
        // slide
        for (int right = 0; right < nums.size(); ++right) {
            if (nums[right] == 0) zeroCount++; // found 0, add it
            // if we have more than one 0, shrink window size
            while(zeroCount > 1) {
                if (nums[left] == 0) zeroCount--;
                left++; // slide left
            }
            // right - left + 1 = window size
            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen - 1; // as per problem
    }
};