#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> R, D;
        int n = senate.size();
        // push idx into respective queues
        for (int i = 0; i < n; ++i) {
            if (senate[i] == 'R') R.push(i);
            else D.push(i);
        }
        // process until one party exhausted
        while (!R.empty() && !D.empty()) {
            int r = R.front(); R.pop();
            int d = D.front(); D.pop();

            // smaller idx goes first and bans other
            if (r < d) R.push(r + n);
            else D.push(d + n);
        }
        return R.empty() ? "Dire" : "Radiant";
    }
};