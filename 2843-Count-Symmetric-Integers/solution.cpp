#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int ans = 0;
        for (int num = low; num <= high; ++num) {
            string s = to_string(num);
            int n = s.size();
            if (n % 2 == 1) continue;
            int half = n / 2;
            int left_sum = 0, right_sum = 0;
            // sum first half
            for (int i = 0; i < half; ++i) left_sum += s[i] - '0';
            // sum second half
            for (int i = half; i < n; ++i) right_sum += s[i] - '0';
            // check if they are equal
            if (left_sum == right_sum) ans++;
        }
        return ans;
    }
};