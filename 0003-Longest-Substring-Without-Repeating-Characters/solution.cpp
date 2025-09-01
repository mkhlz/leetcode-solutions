#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // use sliding window
        unordered_map<char, int> lastSeen;
        int maxLength = 0;  // store result here
        int start = 0;      // starting position of window
        int end = 0;        // ending position of window

        for (end = 0; end < s.length(); ++end) {
            char currentChar = s[end];
            // if currentChar is found in the map
            // and is within current window, adjust window size
            if (lastSeen.find(currentChar) != lastSeen.end()
                && lastSeen[currentChar] >= start) {
                start = lastSeen[currentChar] + 1;
            }
            lastSeen[currentChar] = end;
            maxLength = max(maxLength, end - start + 1);
        }
        return maxLength;

    }
};