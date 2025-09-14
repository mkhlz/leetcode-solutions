<!-- # 🔍 Spellchecker Problem - Making Words Match Again! -->

## Intuition
Imagine you're building a smart spellchecker that's forgiving about common mistakes. People mess up in predictable ways:
- They type "Hello" when the dictionary has "hello" (capitalization issues)
- They type "helo" when they mean "hello" (vowel mistakes)

Our spellchecker needs to be like a patient teacher - it checks for exact matches first, then gets more lenient step by step.

## Approach

The magic happens in **three priority levels**, like a bouncer at a club checking IDs:

```
┌─────────────────────────────────────────────────────────┐
│                    SPELLCHECKER FLOW                    │
├─────────────────────────────────────────────────────────┤
│                                                         │
│  Query Word: "KiTe"                                     │
│       │                                                 │
│       ▼                                                 │
│  ┌─────────────┐                                        │
│  │ LEVEL 1:    │ ──Yes──► Return exact match            │
│  │ Exact Match?│                                        │
│  └─────────────┘                                        │
│       │ No                                              │
│       ▼                                                 │
│  ┌─────────────┐                                        │
│  │ LEVEL 2:    │ ──Yes──► Return first case-match       │
│  │ Case Match? │                                        │
│  └─────────────┘                                        │
│       │ No                                              │
│       ▼                                                 │
│  ┌─────────────┐                                        │
│  │ LEVEL 3:    │ ──Yes──► Return first vowel-match      │
│  │ Vowel Match?│                                        │
│  └─────────────┘                                        │
│       │ No                                              │
│       ▼                                                 │
│   Return ""                                             │
│                                                         │
└─────────────────────────────────────────────────────────┘
```

### Data Structure Setup

We build three lookup tables during preprocessing:

```
WORDLIST: ["KiTe", "kite", "hare", "Hare"]

┌──────────────────┐    ┌──────────────────┐    ┌──────────────────┐
│   EXACT MATCH    │    │   CASE MATCH     │    │   VOWEL MATCH    │
│   (HashSet)      │    │   (HashMap)      │    │   (HashMap)      │
├──────────────────┤    ├──────────────────┤    ├──────────────────┤
│ "KiTe" ✓         │    │ "kite" → "KiTe"  │    │ "k#t#" → "KiTe"  │
│ "kite" ✓         │    │ "hare" → "hare"  │    │ "h#r#" → "hare"  │  
│ "hare" ✓         │    │                  │    │                  │
│ "Hare" ✓         │    │                  │    │                  │
└──────────────────┘    └──────────────────┘    └──────────────────┘
```

### Query Processing Flow

For each query, we follow this decision tree:

```
Query: "keti"
    │
    ▼
┌─────────────────┐
│ Is "keti" in    │ NO
│ exact_set?      │ ──┐
└─────────────────┘   │
                      │
Query: "keti" → "keti" (lowercase)
    │                 │
    ▼                 │
┌─────────────────┐   │
│ Is "keti" in    │ NO│
│ case_map?       │ ──┤
└─────────────────┘   │
                      │
Query: "keti" → "k#t#" (devowel)
    │                 │
    ▼                 │
┌─────────────────┐   │
│ Is "k#t#" in    │YES│
│ vowel_map?      │ ──┘
└─────────────────┘
    │
    ▼
Return vowel_map["k#t#"] = "KiTe"
```

## Complexity

- **Time complexity**: $$O(W + Q \times L)$$
  - W = total characters in wordlist (for preprocessing)  
  - Q = number of queries
  - L = average length of query (for string operations)

- **Space complexity**: $$O(W)$$
  - We store each word at most 3 times (exact, case, vowel maps)

## Test Cases Walkthrough

Let's trace through some examples:

```
wordlist = ["KiTe","kite","hare","Hare"]
queries = ["kite","Kite","KiTe","Hare","HARE","Hear","hear","keti","keet","keto"]

┌─────┬──────────┬─────────┬──────────┬──────────┬────────┐
│Query│Exact     │Case     │Vowel     │Result    │Why     │
│     │Match?    │Match?   │Match?    │          │        │
├─────┼──────────┼─────────┼──────────┼──────────┼────────┤
│kite │✓         │-        │-         │kite      │Level 1 │
│Kite │✗         │✗        │-         │KiTe      │Level 2 │
│KiTe │✓         │-        │-         │KiTe      │Level 1 │
│Hare │✓         │-        │-         │Hare      │Level 1 │  
│HARE │✗         │✓        │-         │hare      │Level 2 │
│Hear │✗         │✗        │✗         │""        │No match│
│hear │✗         │✓        │-         │hare      │Level 2 │
│keti │✗         │✗        │✓         │KiTe      │Level 3 │
│keet │✗         │✗        │✗         │""        │No match│
│keto │✗         │✗        │✓         │KiTe      │Level 3 │
└─────┴──────────┴─────────┴──────────┴──────────┴────────┘
```

### Detailed Example: "keti" → "KiTe"

```
"keti" processing:
1. Exact match? "keti" ∉ {"KiTe", "kite", "hare", "Hare"} ✗
2. Case match? "keti" ∉ {"kite"→"KiTe", "hare"→"hare"} ✗  
3. Vowel match? "keti" → "k#t#"
   "k#t#" ∈ {"k#t#"→"KiTe", "h#r#"→"hare"} ✓
   Return "KiTe"
```

<!-- ## Code

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
    // helper: make everything lowercase (because case doesn't matter for matching)
    static string lowerIt(const string &s) {
        string t = s;
        for (char &c : t) c = tolower((unsigned char)c);
        return t;
    }

    // helper: replace all vowels with '#' (our vowel wildcard)
    // this way "hello", "hallo", "hillo" all become "h#ll#"  
    static string devowel(const string &s) {
        string t = s;
        for (char &c : t)
            if (c=='a' || c=='e' || c=='i' || c=='o' || c=='u') c = '#';
        return t;
    }

public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> exact; // for lightning-fast exact lookups
        unordered_map<string,string> lower; // lowercase -> first original word
        unordered_map<string,string> vow; // devoweled -> first original word

        // build our three-tier lookup system
        for (auto &w : wordlist) {
            exact.insert(w); // exact matches are easy
            string lw = lowerIt(w);
            lower.emplace(lw, w); // emplace keeps first occurrence only
            vow.emplace(devowel(lw), w); // same here - first wins!
        }

        vector<string> res;
        res.reserve(queries.size()); // pre-allocate for efficiency
        
        for (auto &q : queries) {
            // Level 1: Perfect match? Lucky you!
            if (exact.count(q)) { 
                res.push_back(q); 
                continue; 
            }
            
            // Level 2: Case mismatch? We're forgiving
            string lq = lowerIt(q);
            if (lower.count(lq)) { 
                res.push_back(lower[lq]); 
                continue; 
            }
            
            // Level 3: Vowel confusion? We got your back
            string dq = devowel(lq);
            if (vow.count(dq)) { 
                res.push_back(vow[dq]); 
                continue; 
            }
            
            // Nothing worked? Sorry, we tried our best
            res.push_back("");
        }
        return res;
    }
};
``` -->

### Key Insights

1. **Priority matters**: We check exact → case → vowel in that order
2. **First occurrence wins**: When building maps, `emplace()` keeps the first match
3. **Preprocessing is king**: We do the heavy lifting once, then queries are fast
4. **String transformations**: Lowercase for case-insensitive, '#' for vowel wildcards

The beauty of this solution is that each query runs in nearly constant time after our initial setup!


## Code
```cpp []
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
```
```python []
class Solution:
    def lowerIt(self, s: str) -> str:
        return s.lower()
    
    def devowel(self, s: str) -> str:
        return ''.join('#' if c in 'aeiou' else c for c in s)
    
    def spellchecker(self, wordlist, queries):
        exact = set(wordlist)
        lower = {}
        vow = {}

        for w in wordlist:
            lw = self.lowerIt(w)
            lower.setdefault(lw, w)
            vow.setdefault(self.devowel(lw), w)

        res = []
        for q in queries:
            if q in exact:
                res.append(q)
            elif (lq := self.lowerIt(q)) in lower:
                res.append(lower[lq])
            elif (dq := self.devowel(self.lowerIt(q))) in vow:
                res.append(vow[dq])
            else:
                res.append("")
        return res

```
```java []
import java.util.*;

class Solution {
    private String lowerIt(String s) {
        return s.toLowerCase();
    }
    private String devowel(String s) {
        return s.replaceAll("[aeiou]", "#");
    }

    public String[] spellchecker(String[] wordlist, String[] queries) {
        Set<String> exact = new HashSet<>(Arrays.asList(wordlist));
        Map<String,String> lower = new HashMap<>();
        Map<String,String> vow = new HashMap<>();

        for (String w : wordlist) {
            String lw = lowerIt(w);
            lower.putIfAbsent(lw, w);
            vow.putIfAbsent(devowel(lw), w);
        }

        String[] res = new String[queries.length];
        for (int i = 0; i < queries.length; i++) {
            String q = queries[i];
            if (exact.contains(q)) {
                res[i] = q;
            } else {
                String lq = lowerIt(q);
                if (lower.containsKey(lq)) {
                    res[i] = lower.get(lq);
                } else {
                    String dq = devowel(lq);
                    res[i] = vow.getOrDefault(dq, "");
                }
            }
        }
        return res;
    }
}
```
```javascript []
class Solution {
    lowerIt(s) {
        return s.toLowerCase();
    }
    devowel(s) {
        return s.replace(/[aeiou]/g, "#");
    }

    spellchecker(wordlist, queries) {
        const exact = new Set(wordlist);
        const lower = new Map();
        const vow = new Map();

        for (let w of wordlist) {
            const lw = this.lowerIt(w);
            if (!lower.has(lw)) lower.set(lw, w);
            const dw = this.devowel(lw);
            if (!vow.has(dw)) vow.set(dw, w);
        }

        const res = [];
        for (let q of queries) {
            if (exact.has(q)) {
                res.push(q);
                continue;
            }
            const lq = this.lowerIt(q);
            if (lower.has(lq)) {
                res.push(lower.get(lq));
                continue;
            }
            const dq = this.devowel(lq);
            if (vow.has(dq)) {
                res.push(vow.get(dq));
            } else {
                res.push("");
            }
        }
        return res;
    }
}
```
<!-- ![478xve.jpg](https://assets.leetcode.com/users/images/c5331d98-1f19-43b2-9749-c80d0382cff1_1757650091.7379217.jpeg) -->

Detailed Guide using Hashing & String Tricks | C++ & others ✔️

https://leetcode.com/problems/vowel-spellchecker/solutions/7187533/detailed-guide-using-hashing-string-tric-bg46/