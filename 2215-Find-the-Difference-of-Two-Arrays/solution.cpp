#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        // fast lookup, convert both inputs to set
        unordered_set<int> set1(nums1.begin(), nums1.end());
        unordered_set<int> set2(nums2.begin(), nums2.end());
        vector<int> diff1, diff2;
        // grab elements in set1 not in set2
        for (auto &num : set1) {
            if (set2.find(num) == set2.end()) {
                diff1.push_back(num);
            }
        }
        // grab elements in set2 not in set1
        for (auto &num : set2) {
            if (set1.find(num) == set1.end()) {
                diff2.push_back(num);
            }
        }
        return {diff1, diff2}; // wrap & return
    }
};