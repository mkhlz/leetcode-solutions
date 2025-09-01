#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int expandAroundCenter(const string &s, int left, int right) {
        // Expand as long as left and right characters match
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;   // Move left pointer left
            right++;  // Move right pointer right, we are expanding
        }
        // Return the length of the current palindrome
        return right - left - 1;
    }

    string longestPalindrome(string s) {
        if (s.empty()) return ""; // empty string, return ""

        int start = 0;  // Start index of the longest palindrome
        int end = 0;    // End index of the longest palindrome

        // Loop through each character in the string
        for (int i = 0; i < s.size(); ++i) {
            int len1 = expandAroundCenter(s, i, i);       // Odd length palindrome
            int len2 = expandAroundCenter(s, i, i + 1);   // Even length palindrome
            int len = max(len1, len2);                    // Take the maximum length

            // Update start and end if a longer palindrome is found
            if (len > end - start + 1) {
                start = i - (len - 1) / 2;  // Calculate new start
                end = i + len / 2;          // Calculate new end
            }
        }

        // Return the substring from start to end
        return s.substr(start, end - start + 1);
    }
};