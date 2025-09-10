#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        // count freq of each char
        unordered_map<int, int> freq;
        for (int num : arr) freq[num]++;
        unordered_set<int> seen;
        for (auto &p : freq) {
            // if already seen, not unique
            if (seen.count(p.second)) return false;
            seen.insert(p.second);
        }
        return true;
    }
};