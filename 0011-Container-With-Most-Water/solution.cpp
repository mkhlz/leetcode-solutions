#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        if (height.empty()) return 0;
        int left = 0, right = height.size() - 1; // left and right pointers
        long long max_area = 0;                  // prevent overflow

        while (left < right) {
            long long area =
                (long long)min(height[left], height[right]) * (right - left);
            max_area = max(max_area, area);
            if (height[left] < height[right]) left++;
            else right--;
        }
        return (int)max_area;
    }
};