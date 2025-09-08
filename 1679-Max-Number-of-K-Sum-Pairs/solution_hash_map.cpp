#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int count = 0;
        for (int num : nums) {
            int target = k - num;
            if (freq[target] > 0) {
                count++;
                freq[target]--;
            } else {
                freq[num]++;
            }
        }
        return count++; 
    }
};