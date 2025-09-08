#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int alt = 0; // current altitude, starts at 0
        int best = 0; // highest alt seen so far
        // check all gains
        for (int g : gain) {
            alt += g; // update alt after this step
            if (alt > best) best = alt; // if we get new high, record it
        }
        return best; // max altitude
    }
};