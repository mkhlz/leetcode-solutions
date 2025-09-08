#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countGoodIntegers(int n, int k) {
        int h = (n + 1) / 2;    // length of half we build
        long long ans = 0;
        // precompute factorials for n!
        vector<long long> fact(n + 1, 1);
        for (int i = 2; i <=n; ++i) fact[i] = fact[i - 1] * i;
        unordered_set<string> seen; // track unique digit patterns
        int start = pow(10, h - 1), end = pow(10, h);
        for (int num = start; num < end; num++) {
            string s = to_string(num), pal = s;
            // mirror the half to form complete palidrome
            for (int i = (n % 2 ? h - 2 : h - 1); i >= 0; --i) pal.push_back(s[i]);
            long long val = stoll(pal);
            if (val % k != 0) continue; // must be divisible by k
            // sort digits to form a unique signature
            string sig = pal;
            sort(sig.begin(), sig.end());
            if (seen.count(sig)) continue;  // skip duplicates
            seen.insert(sig);
            // count permutations using factorials
            vector<int> freq(10, 0);
            for (char c : pal) freq[c - '0']++;
            long long total = fact[n];
            for (int f : freq) if (f > 1) total /= fact[f];
            // remove cases where leading digit is 0
            if (freq[0]) {
                long long bad = fact[n-1];
                freq[0]--;
                for (int f : freq) if (f > 1) bad /= fact[f];
                total -= bad;
            }
            ans += total;
        }
        return ans;
    }
};