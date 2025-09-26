#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    long long triangleNumber(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return 0; // fewer than 3 sides -> no triangle
        sort(nums.begin(), nums.end()); // sort ascending
        ll ans = 0;
        // Fix the largest side index k
        for (int k = n - 1; k >= 2; --k) {
            int i = 0, j = k - 1;
            // find pairs (i, j) with i < j < k and nums[i] + nums[j] > nums[k]
            while (i < j) {
                // if smallest + current biggest > largest, then all between i..j-1 with j also work
                if ((ll)nums[i] + nums[j] > nums[k]) {
                    ans += (j - i); // all indices t in [i, j-1] with j form valid triangles
                    --j; // try smaller j to find more combos
                } else {
                    ++i; // sum too small, increase i to make sum larger
                }
            }
        }
        return ans;
    }
};