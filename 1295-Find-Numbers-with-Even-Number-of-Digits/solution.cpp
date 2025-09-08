#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int count = 0;
        for (int num : nums) {
            // Convert number to string and check length
            if (to_string(num).length() % 2 == 0) {
                count++;
            }
        }
        return count;
    }
};
