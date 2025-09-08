#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
       int n = chars.size();
       int index = 0;
       for (int i = 0; i < n; ) {
        char currentChar = chars[i];
        int count = 0;
        while (i < n && chars[i] == currentChar) {
            i++;
            count++;
        }
        chars[index++] = currentChar;
        if (count > 1) {
            string cnt = to_string(count);
            for (char c : cnt) chars[index++] = c;
        }
       } return index;
    }
};