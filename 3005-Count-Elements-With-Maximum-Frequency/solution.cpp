#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define PB push_back
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int> frequency(101, 0); // since nums[i] is <= 100
        int mx = 0, ans = 0;
        for (auto n : nums) mx = max(mx, ++frequency[n]);
        for (auto f : frequency) if (f == mx) ans += f;
        return ans;
    }
};