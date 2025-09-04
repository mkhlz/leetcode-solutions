#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isMatch(string s, string p)
    {
        vector<vector<int>> memo(s.size() + 1, vector<int>(p.size() + 1, -1));
        return dp(0, 0, s, p, memo);
    }

private:
    bool dp(int i, int j, const string &s, const string &p, vector<vector<int>> &memo)
    {
        if (memo[i][j] != -1)
            return memo[i][j];
        bool ans;
        if (j == p.size())
        {
            ans = (i == s.size());
        }
        else
        {
            bool firstMatch = (i < s.size() && (s[i] == p[j] || p[j] == '.'));
            if (j + 1 < p.size() && p[j + 1] == '*')
            {
                ans = dp(i, j + 2, s, p, memo) || (firstMatch && dp(i + 1, j, s, p, memo));
            }
            else
            {
                ans = firstMatch && dp(i + 1, j + 1, s, p, memo);
            }
        }
        memo[i][j] = ans;
        return ans;
    }
};