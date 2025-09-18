#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<long long> stack; // use ll to avoid overflow
        for (auto x : nums) {
            long long cur = x; // current num to inset
            while (!stack.empty()) {
                long long g = gcd(stack.back(), cur); // gcd of top and curr
                if (g == 1) break; // stop merging if coprime
                cur = lcm(stack.back(), cur); // replace w lcm
                stack.pop_back(); // remove old top, since its merged
            }
            stack.push_back(cur);
        }
        // convert to int as required
        return vector<int>(stack.begin(), stack.end());
    }
};