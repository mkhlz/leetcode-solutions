#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    const long long MOD = 1e9 + 7;
    // modular exponentiation function
    long long modPow(long long base, long long exp) {
        long long result = 1;
        base %= MOD; // keep base under mod
        while (exp > 0) {
            if (exp & 1) result = (result * base) % MOD; // multiply when bit is 1
            base = (base * base) % MOD; // square the base
            exp >>= 1; // divide exponent by 2
        }
        return result;
    }

    int countGoodNumbers(long long n) {
        long long evenCount = (n + 1) / 2; // positions with even digits
        long long oddCount = n / 2;        // positions with prime digits

        long long part1 = modPow(5, evenCount); // ways for even positions
        long long part2 = modPow(4, oddCount);  // ways for odd positions

        return (part1 * part2) % MOD;
    }
};
