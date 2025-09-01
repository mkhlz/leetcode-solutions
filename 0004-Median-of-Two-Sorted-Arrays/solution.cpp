#include <bits/stdc++.h>
using namespace std;

/*

Since the solution needs to be in O(log(m + n)), we need to find the smaller array first, use binary search on it and partition both arrays so that 

*/
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Ensure nums1 is the smaller array
        if (nums1.size() > nums2.size()) {
            swap(nums1, nums2);
            }

        int m = nums1.size();  // size of smaller array
        int n = nums2.size();  // size of larger array

        int low = 0, high = m;

        while (low <= high) {
            int partitionX = (low + high) / 2; // Mid of smaller array
            int partitionY = (m + n + 1) / 2 - partitionX; // Complement partition in nums2

            // If partition is 0, take -∞; if partition is full size, take +∞
            int maxLeftX = (partitionX == 0) ? INT_MIN : nums1[partitionX - 1];
            int minRightX = (partitionX == m) ? INT_MAX : nums1[partitionX];

            int maxLeftY = (partitionY == 0) ? INT_MIN : nums2[partitionY - 1];
            int minRightY = (partitionY == n) ? INT_MAX : nums2[partitionY];

            // Check if we have found the correct partition
            if (maxLeftX <= minRightY && maxLeftY <= minRightX) {
                // If total number of elements is even
                if ((m + n) % 2 == 0) {
                    return (max(maxLeftX, maxLeftY) + min(minRightX, minRightY)) / 2.0;
                } else {
                    return max(maxLeftX, maxLeftY);
                }
            }
            // Adjust binary search
            else if (maxLeftX > minRightY) {
                high = partitionX - 1;
            } else {
                low = partitionX + 1;
            }
        }
        throw invalid_argument("Input arrays are not sorted or invalid");
    }
};