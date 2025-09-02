#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end()); // sort the array
        int n = nums.size();
        int closest = nums[0] + nums[1] + nums[2];  // init closest sum
        for (int i = 0; i < n-2; i++) {
            int left = i + 1, right = n - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (abs(sum - target) < abs(closest - target)) {
                    closest = sum;  // update closest
                }
                if (sum < target) left++;
                else if (sum > target) right--;
                else return sum;    // exact match found
            }
        }
        return closest;
    }
};