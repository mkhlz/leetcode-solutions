#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result; // vector to store the result
        std::sort(nums.begin(), nums.end());    // sort the array
        for (int i = 0; i < nums.size(); ++i) { // traverse the array
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int target = -nums[i];
            int left = i + 1;   // two pointers
            int right = nums.size() - 1;
            while (left < right) {
                int sum = nums [left] + nums[right];
                if (sum == target) {
                    result.push_back({nums[i], nums[left], nums[right]});
                    left++;
                    right--;
                    while (left < right && nums[left] == nums[left - 1]) left++;
                    while (left < right && nums[right] == nums[right + 1]) right--;
                } else if (sum < target) left++;
                 else right--;
                }
        }
        return result;        
    }
};