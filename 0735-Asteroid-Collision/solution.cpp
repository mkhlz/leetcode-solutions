#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st; // vector used as stack
        for (int a : asteroids) {
            bool destroyed = false; // current asteroid is not destroyed yet
            // collision happens when stack top > 0 (right) and current a < 0 (left)
            while (!destroyed && !st.empty() && st.back() > 0 && a < 0) {
                int top = st.back();
                if (abs(top) < abs(a)) {
                    // stack top is smaller -> it explodes
                    st.pop_back();
                    // current asteroid still alive -> keep checking
                } else if (abs(top) == abs(a)) {
                    // same size -> both explode
                    st.pop_back();
                    destroyed = true; // current asteroid destroyed too
                    break;
                } else {
                    // stack top is bigger -> current asteroid explodes
                    destroyed = true;
                    break;
                }
            }
            // current asteroid survived all collisions
            if (!destroyed) st.push_back(a);
        }
        return st;
    }
};
