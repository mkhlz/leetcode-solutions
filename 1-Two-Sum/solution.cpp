#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numMap; // memory box to store number and its position

        // go through each toy (number) one by one
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i]; // missing number to reach magic number

            // check if missing number is already in memory box
            if (numMap.find(complement) != numMap.end()) {
                return {numMap[complement], i}; // we found the pair!
            }

            // put current toy in memory box
            numMap.insert({nums[i], i});
        }
        return {}; // no pair found
    }
};