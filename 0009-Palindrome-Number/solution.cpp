#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        if (x != 0 && x % 10 == 0) return false;
        int revertedHalf = 0;
        for (; x > revertedHalf; x /= 10) {
            revertedHalf = revertedHalf * 10 + x % 10;
        }
        return (x == revertedHalf) || (x == revertedHalf / 10);
    }    
};