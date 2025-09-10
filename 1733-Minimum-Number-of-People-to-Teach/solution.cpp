#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int m = languages.size();
        vector<bitset<501>> know(m+1);
        for (int i=0;i<m;i++) 
            for (int l: languages[i]) know[i+1][l]=1;
        vector<int> need(m+1,0);
        for (auto &f: friendships){
            int a=f[0], b=f[1];
            if ((know[a] & know[b]).none()) {
                need[a]=1; need[b]=1;
            }
        }
        int total=accumulate(need.begin(),need.end(),0);
        if (!total) return 0;
        vector<int> cnt(n+1,0);
        for (int i=1;i<=m;i++) if(need[i])
            for (int l=1;l<=n;l++) if(know[i][l]) cnt[l]++;
        return total - *max_element(cnt.begin(),cnt.end());
    }
};