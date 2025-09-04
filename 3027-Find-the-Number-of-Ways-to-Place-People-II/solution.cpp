#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        // convert points to vectors (x, y)
        vector<pair<int, int>> pts;
        for (auto &p : points) pts.push_back({p[0], p[1]});
        //sort points by x ascending, if x is same, y descending
        sort(pts.begin(), pts.end(), [](auto &a, auto &b) {
            if (a.first == b.first) return a.second > b.second;
            return a.first < b.first;
        });
        long long ans = 0; // as the combinations can be large
        int n = pts.size();
        // out loop for Alice (point A)
        for (int i = 0; i < n; i++) {
            int ya = pts[i].second;
            long long maxY = LLONG_MIN;
            // inner loop for Bob (point B)
            for (int j = i + 1; j < n; j++) {
                int yb = pts[j].second; // Bob's y coord
                // Bob must be below or equal to Alice
                if (yb <= ya) {
                    // check if this yb is a new record high among previous Bobs
                    if (yb > maxY) {
                        ans++;  // valid paid found
                        maxY = yb;  // update maxY
                    }
                }
            }
        }
        return ans; // return all found valid pairs
    }
};