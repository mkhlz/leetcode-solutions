#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int triangleNumber(vector<int>& a) {
        sort(a.begin(), a.end());
        int n = a.size(), ans = 0;
        for (int k = n - 1; k > 1; k--) {
            int i = 0, j = k - 1;
            while (i < j) {
                if (a[i] + a[j] > a[k]) ans += j - i, j--;
                else i++;
            }
        }
        return ans;
    }
};