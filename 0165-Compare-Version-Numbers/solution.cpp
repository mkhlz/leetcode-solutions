#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define PB push_back
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i = 0, j = 0, n = version1.size(), m = version2.size();
        while (i < n || j < m) {
            long x = 0, y = 0;
            // parse next number from version1
            while (i < n && version1[i] != '.') { x = x * 10 + (version1[i] - '0'); ++i; }
            if (i < n && version1[i] == '.') ++i; // // skip if dot present
            // parse next number from version2
            while (j < m && version2[j] != '.') { y = y * 10 + (version2[j] - '0'); ++j; }
            if (j < m && version2[j] == '.') ++j;
            if (x < y) return -1; // version1's part smaller
            if (x > y) return 1; // version1's part larger
            // else equal, then continue
        }
        return 0;
    }
};