#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isVowel(char c) {
        return c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||
               c=='A'||c=='E'||c=='I'||c=='O'||c=='U';
    }
    string sortVowels(string s) {
        int count[128] = {0}; // ASCII freq array
        // count vowels
        for (char c : s) {
            if (isVowel(c)) count[c]++;
        }
        string order = "AEIOUaeiou";
        string ans;
        int j = 0;
        for (char c : s) {
            if (!isVowel(c)) {
                ans += c;
            } else {
                while (count[order[j]] == 0) j++;
                ans += order[j];
                count[order[j]]--;
            }
        }
        return ans;
    }
};