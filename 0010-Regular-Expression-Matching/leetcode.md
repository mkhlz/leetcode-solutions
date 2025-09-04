## Intuition

The is the classic **pattern matching** problem.
The two special characters make things tricky:
- `.` can match any single character.
- `*` can match zero or more of the preceding element.

A brute-force recursive solution is natural: for each character in the pattern, either match it with the current string character or skip it (especially for `*`).
However, naive recursion leads to exponential time due to overlapping subproblems.

## Approach
We can solve this efficiently using **Dynamic Programming**:

1. **Recursive + Memoization (Top-Down DP)**:
   - Define `dp(i, j)` as whether `s[i:]` matches `p[j:]`.
   - Base case: if `j` reaches the end of the pattern, `s[i:]` must also be empty.
   - Check if the first characters match (`s[i] == p[j]` or `p[j] == '.'`).
   - If the next pattern character is `*`, consider two options:
     - Skip the `*` (zero occurrences).
     - Use the `*` if the first character matches (one or more occurrences).
   - Otherwise, just match the current character and move forward.
   - Memoize results to avoid recomputation.

2. **Bottom-Up DP**:
   - Build a DP table `dp[i][j]` where `dp[i][j] = true` if `s[i:]` matches `p[j:]`.
   - Fill the table from the bottom-right corner to the top-left.
   - Handle the `*` similarly: either skip it or match one/more characters.
   - This removes recursion overhead.

3. **Space Optimization**:
   - Only the current and next rows are needed.
   - Reduce space complexity from `O(m*n)` to `O(n)`.

## Complexity
- Time complexity: $$O(m \cdot n)$$  
  Where `m` is the length of `s` and `n` is the length of `p`, since each subproblem `dp[i][j]` is solved at most once.

- Space complexity: 
  - Top-Down DP: $$O(m \cdot n)$$ (memoization table) + recursion stack.  
  - Bottom-Up DP: $$O(m \cdot n)$$.  
  - Space-optimized Bottom-Up DP: $$O(n)$$.


## Code
```cpp []
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        // Create memo table initialized with -1 (unvisited)
        vector<vector<int>> memo(s.size() + 1, vector<int>(p.size() + 1, -1));
        return dp(0, 0, s, p, memo);
    }

private:
    bool dp(int i, int j, const string &s, const string &p, vector<vector<int>> &memo) {
        // If already computed, return from memo
        if (memo[i][j] != -1) return memo[i][j];

        bool ans;
        if (j == p.size()) {
            // If pattern is finished, string should also be finished
            ans = (i == s.size());
        } else {
            // Check if first characters match
            bool firstMatch = (i < s.size() && (s[i] == p[j] || p[j] == '.'));

            // If next character in pattern is '*', two cases:
            if (j + 1 < p.size() && p[j + 1] == '*') {
                // 1. Skip the '*' and its preceding element
                // 2. Use '*' if first character matches
                ans = dp(i, j + 2, s, p, memo) || (firstMatch && dp(i + 1, j, s, p, memo));
            } else {
                // Otherwise, move to next characters in both string and pattern
                ans = firstMatch && dp(i + 1, j + 1, s, p, memo);
            }
        }

        // Store result in memo table
        memo[i][j] = ans;
        return ans;
    }
};
```
```python []
from functools import lru_cache

class Solution:
    def isMatch(self, s: str, p: str) -> bool:

        @lru_cache(None)  # Memoization using Python's built-in cache
        def dp(i: int, j: int) -> bool:
            # If pattern is finished, string must also be finished
            if j == len(p):
                return i == len(s)

            # Check if first character matches
            first_match = (i < len(s) and (s[i] == p[j] or p[j] == '.'))

            # If next char in pattern is '*'
            if (j + 1) < len(p) and p[j + 1] == '*':
                # Two options: skip '*' or use '*' if first char matches
                return dp(i, j + 2) or (first_match and dp(i + 1, j))
            else:
                # Move to next characters in both
                return first_match and dp(i + 1, j + 1)

        return dp(0, 0)
```
```java []
import java.util.*;

class Solution {
    public boolean isMatch(String s, String p) {
        // Memo table initialized with null (uncomputed states)
        Boolean[][] memo = new Boolean[s.length() + 1][p.length() + 1];
        return dp(0, 0, s, p, memo);
    }

    private boolean dp(int i, int j, String s, String p, Boolean[][] memo) {
        if (memo[i][j] != null) return memo[i][j];

        boolean ans;
        if (j == p.length()) {
            // Pattern finished, string must also finish
            ans = (i == s.length());
        } else {
            // Check if first character matches
            boolean firstMatch = (i < s.length() && (s.charAt(i) == p.charAt(j) || p.charAt(j) == '.'));

            if (j + 1 < p.length() && p.charAt(j + 1) == '*') {
                // Skip '*' or use it if match
                ans = dp(i, j + 2, s, p, memo) || (firstMatch && dp(i + 1, j, s, p, memo));
            } else {
                ans = firstMatch && dp(i + 1, j + 1, s, p, memo);
            }
        }

        memo[i][j] = ans;
        return ans;
    }
}
```
```javascript []
function isMatch(s, p) {
    const memo = new Map();

    function dp(i, j) {
        const key = `${i},${j}`;
        if (memo.has(key)) return memo.get(key);

        let ans;
        if (j === p.length) {
            ans = (i === s.length);
        } else {
            const firstMatch = (i < s.length && (s[i] === p[j] || p[j] === '.'));

            if (j + 1 < p.length && p[j + 1] === '*') {
                ans = dp(i, j + 2) || (firstMatch && dp(i + 1, j));
            } else {
                ans = firstMatch && dp(i + 1, j + 1);
            }
        }

        memo.set(key, ans);
        return ans;
    }

    return dp(0, 0);
}
```
```Go []
package main

func isMatch(s string, p string) bool {
    memo := make(map[[2]int]bool)

    var dp func(i, j int) bool
    dp = func(i, j int) bool {
        if val, ok := memo[[2]int{i, j}]; ok {
            return val
        }

        var ans bool
        if j == len(p) {
            ans = (i == len(s))
        } else {
            firstMatch := (i < len(s) && (s[i] == p[j] || p[j] == '.'))

            if j+1 < len(p) && p[j+1] == '*' {
                ans = dp(i, j+2) || (firstMatch && dp(i+1, j))
            } else {
                ans = firstMatch && dp(i+1, j+1)
            }
        }

        memo[[2]int{i, j}] = ans
        return ans
    }

    return dp(0, 0)
}
```
```rust []
use std::collections::HashMap;

struct Solution;

impl Solution {
    pub fn is_match(s: String, p: String) -> bool {
        // Convert to byte arrays for easy indexing
        let s_bytes = s.as_bytes();
        let p_bytes = p.as_bytes();

        // HashMap for memoization: key is (i, j), value is bool
        let mut memo: HashMap<(usize, usize), bool> = HashMap::new();

        fn dp(i: usize, j: usize, s: &[u8], p: &[u8], memo: &mut HashMap<(usize, usize), bool>) -> bool {
            // If result is already computed, return from memo
            if let Some(&val) = memo.get(&(i, j)) {
                return val;
            }

            let ans = if j == p.len() {
                // If pattern is finished, string must also finish
                i == s.len()
            } else {
                // Check if the first characters match
                let first_match = i < s.len() && (s[i] == p[j] || p[j] == b'.');

                if j + 1 < p.len() && p[j + 1] == b'*' {
                    // Two options when we see '*':
                    // 1. Skip '*' and its preceding element
                    // 2. Use '*' if first characters match
                    dp(i, j + 2, s, p, memo) || (first_match && dp(i + 1, j, s, p, memo))
                } else {
                    // Otherwise, move both pointers if first characters match
                    first_match && dp(i + 1, j + 1, s, p, memo)
                }
            };

            // Store result in memo
            memo.insert((i, j), ans);
            ans
        }

        dp(0, 0, s_bytes, p_bytes, &mut memo)
    }
}
```
### Other approaches

**Bottom-Up DP (Tabulation)**

**Intuition**
- Define `dp[i][j]` = `true` if `s[i:]` matches `p[j:]`.
- Table size = `(m+1) x (n+1)` where `m = len(s)`, `n = len(p)`.
- Base case: `dp[m][n] = true` (empty string matches empty pattern).
- Fill the table from **bottom-right to top-left**.
- Transition:
  - If `p[j+1] == '*'`:
    - `dp[i][j] = dp[i][j+2]` (skip `*`)
    - OR `firstMatch && dp[i+1][j]` (use `*`)
  - Else:
    - `dp[i][j] = firstMatch && dp[i+1][j+1]`

**Complexity**
- **Time Complexity:**  
  $$O(m \cdot n)$$  
  Every `dp[i][j]` computed once.
- **Space Complexity:**  
  $$O(m \cdot n)$$
  For the DP table.

**Bottom-Up DP with Space Optimization**

**Intuition**
- Observing that at any step, `dp[i][j]` depends only on:
  - `dp[i][j+2]` (same row)
  - `dp[i+1][j]` and `dp[i+1][j+1]` (next row)
- So we only need **two rows at a time**.
- Replace the full table with two 1D arrays.

### **Complexity**
- **Time Complexity:**  
  $$O(m \cdot n)$$
- **Space Complexity:**  
  $$O(n)$$  
  Only two rows instead of the entire table.

---
