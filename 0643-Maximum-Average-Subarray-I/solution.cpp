#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        // grab the first `k` elements and sum
        double windowSum = 0;
        for (int i = 0; i < k; ++i) {
            windowSum += nums[i];
        }
        double maxSum = windowSum;  // keep track of current best
        // slide the window
        for (int i = k; i < nums.size(); ++i) {
            windowSum += nums[i] - nums[i - k]; // update with new
            maxSum = max(maxSum, windowSum);
        }
        return maxSum / k;  // bcuz we need the avg
    }
};