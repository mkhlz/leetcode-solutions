#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int ans = 0;
        // Sort by x ascending; if same x, y descending
        sort(points.begin(), points.end(), [](auto &a, auto &b) {
            return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
        });
        int n = points.size();
        // Loop A -- find all eligible Bs
        for (int i = 0; i < n; ++i) {
            int yi = points[i][1];           // y-coordinate of the current point A
            int maxY = INT_MIN;              // maximum y ≤ yi found so far among subsequent points
            // Loop B -- track the maximum y value ≤ A
            for (int j = i + 1; j < n; ++j) {
                int yj = points[j][1];       // y-coordinate of a candidate point B
                // If B is below A (yj ≤ yi) and higher than any previous candidate
                if (yj <= yi && yj > maxY) {
                    ++ans;                    // found a valid pair (A, B)
                    maxY = yj;                // update the max y seen so far
                }
            }
        }
        return ans;  // return the count (total pairs)
    }
};
