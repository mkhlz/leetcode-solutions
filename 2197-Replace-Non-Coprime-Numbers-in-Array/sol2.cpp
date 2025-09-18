#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<long long> stack;
        for (int x : nums) {
            long long cur = x;
            while (!stack.empty()) {
                long long g = gcd(stack.back(), cur);
                if (g == 1) break;
                cur = stack.back() / g * cur; // safe LCM
                stack.pop_back();
            }
            stack.push_back(cur);
        }
        return {stack.begin(), stack.end()};
    }
};
