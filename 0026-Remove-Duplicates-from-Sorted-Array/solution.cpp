#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define MAX_N 10001
#define MOD 1000000007
#define rep(a,b) for(int i=a; i<b; ++i)
#define repv(a,b,i) for(int i=a; i<b; ++i)
#define ALL(x) (x).begin(), (x).end()
#define S(x) ((int)(x).size())
#define PB push_back
#define fi first
#define se second
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        int i = 0;
        repv(1, nums.size(), j) {
                if (nums[j] != nums[i]) {
                ++i;
                nums[i] = nums[j];
            }
        }
        return i + 1;
    }
};