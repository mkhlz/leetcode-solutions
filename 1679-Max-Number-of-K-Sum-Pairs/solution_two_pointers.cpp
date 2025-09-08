#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int left = 0, right = nums.size() -1;
        int count = 0;
        while (left < right) {
            int sum = nums[left] + nums[right];
            if (sum == k) {
                count++;    // perfect match, add to count
                left++; // move both pointers
                right--;
            } else if (sum < k) {
                left++;  // sum too small, push left forward
            } else {
                right--;    // sum too large, push right backward
            }
        }
        return count;
    }
};