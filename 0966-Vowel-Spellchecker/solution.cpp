#include <bits/stdc++.h>
using namespace std;

class Solution {
    // helper: lowercase a string
    static string lowerIt(const string &s) {
        string t = s;
        for (char &c : t) c = tolower((unsigned char)c);
        return t;
    }

    // helper: replace vowels with '#'
    static string devowel(const string &s) {
        string t = s;
        for (char &c : t)
            if (c=='a' || c=='e' || c=='i' || c=='o' || c=='u') c = '#';
        return t;
    }

public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> exact; // exact match
        unordered_map<string,string> lower; // lowercase -> first word
        unordered_map<string,string> vow; // devowel -> first word

        for (auto &w : wordlist) {
            exact.insert(w);
            string lw = lowerIt(w);
            lower.emplace(lw, w); // keep first occurrence
            vow.emplace(devowel(lw), w);
        }

        vector<string> res;
        res.reserve(queries.size());
        for (auto &q : queries) {
            if (exact.count(q)) { res.push_back(q); continue; } // rule 1
            string lq = lowerIt(q);
            if (lower.count(lq)) { res.push_back(lower[lq]); continue; } // rule 2
            string dq = devowel(lq);
            if (vow.count(dq)) { res.push_back(vow[dq]); continue; } // rule 3
            res.push_back(""); // no match
        }
        return res;
    }
};