# Path Sum III - Complete Solution Guide

## Intuition

Imagine you're walking through a tree with a backpack that keeps track of all the "running totals" you've collected so far. At each node, you ask yourself: "Hey, have I seen a running total before that, when subtracted from my current total, gives me exactly the target sum?"

This is like asking: "If I remove some prefix from my current path, do the remaining numbers add up to my target?"

The key insight is using **prefix sums** - just like how we solve subarray sum problems, but applied to tree paths!

## Approach

### Visual Tree Example
```
Let's say target = 8, and we have this tree:

         5
       /   \
      4     8
     /     / \
    11    13  4
   /  \      / \
  7    2    5   1
```

### The Magic of Prefix Sums

Think of it this way - as we traverse down any path, we keep track of:
1. **Current running sum** from root to current node
2. **All previous running sums** we've seen on this path
3. For each node, check: `current_sum - target` exists in our "memory"?

### ASCII Flow Chart

```
START: Begin DFS from root
  |
  v
┌─────────────────────────┐
│ At current node:        │
│ currSum += node->val    │
└─────────┬───────────────┘
          │
          v
┌─────────────────────────┐
│ Check if (currSum -     │
│ target) exists in our   │
│ prefix map              │
│ If YES: count += freq   │
└─────────┬───────────────┘
          │
          v
┌─────────────────────────┐
│ Add currSum to prefix   │
│ map (remember this sum  │
│ for future nodes)       │
└─────────┬───────────────┘
          │
          v
┌─────────────────────────┐
│ Recursively explore     │
│ left and right children │
│ (they inherit our map)  │
└─────────┬───────────────┘
          │
          v
┌─────────────────────────┐
│ BACKTRACK: Remove       │
│ currSum from map        │
│ (we're leaving this     │
│ path, so forget it)     │
└─────────┬───────────────┘
          │
          v
        RETURN count
```

### Step-by-Step Walkthrough

Let's trace through our example tree with target = 8:

```
Step 1: At node 5
currSum = 5
prefix = {0: 1, 5: 1}
Looking for (5-8) = -3? NO
count = 0

Step 2: At node 4 (left child of 5)
currSum = 5 + 4 = 9
prefix = {0: 1, 5: 1, 9: 1}
Looking for (9-8) = 1? NO
count = 0

Step 3: At node 11 (left child of 4)
currSum = 9 + 11 = 20
prefix = {0: 1, 5: 1, 9: 1, 20: 1}
Looking for (20-8) = 12? NO
count = 0

Step 4: At node 7 (left child of 11)
currSum = 20 + 7 = 27
prefix = {0: 1, 5: 1, 9: 1, 20: 1, 27: 1}
Looking for (27-8) = 19? NO
count = 0
(backtrack: remove 27)

Step 5: At node 2 (right child of 11)
currSum = 20 + 2 = 22
prefix = {0: 1, 5: 1, 9: 1, 20: 1, 22: 1}
Looking for (22-8) = 14? NO
count = 0
(backtrack: remove 22, then 20, then 9)

... and so on!
```

### Why This Works - The "Aha!" Moment

```
Path visualization:
Root → A → B → C → D

If sum(Root→D) = X and sum(Root→A) = Y
Then sum(B→D) = X - Y

So if we want sum(B→D) = target:
We need X - Y = target
Which means Y = X - target

That's why we check if (currSum - target) exists!
```

## Complexity

- **Time complexity**: $$O(n)$$
  - We visit each node exactly once
  - HashMap operations are O(1) on average
  - Total: O(n) where n is number of nodes

- **Space complexity**: $$O(n)$$
  - Recursion stack: O(h) where h is height (worst case O(n))
  - HashMap: O(h) in worst case for one root-to-leaf path
  - Overall: O(n) in worst case

## Test Cases

### Test Case 1: Basic Example
```
Tree:      10
          /  \
         5   -3
        / \    \
       3   2   11
      / \   \
     3  -2   1

Target: 8
Expected paths:
- 5 → 3 (sum = 8)
- 5 → 2 → 1 (sum = 8) 
- -3 → 11 (sum = 8)
Answer: 3
```

### Test Case 2: Negative Numbers
```
Tree:      1
          / \
        -2   3
        /   / \
       1   -1  2

Target: 2
Expected paths:
- 1 → -2 → 1 → 2 (wait, this goes down only)
- 3 → -1 (sum = 2)
- Single node 2
Answer: 2
```

### Test Case 3: Single Node
```
Tree: 1
Target: 1
Answer: 1 (just the root itself)
```

## Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) {
        // Our "memory bank" of prefix sums we've seen
        unordered_map<long long, int> prefixSums;
        
        // This is crucial! We start with sum 0 having frequency 1
        // Why? Because if currSum equals target, then currSum - target = 0
        // and we need 0 to exist in our map to count that path!
        prefixSums[0] = 1;
        
        return dfs(root, 0, targetSum, prefixSums);
    }
    
private:
    int dfs(TreeNode* node, long long currSum, int target,
            unordered_map<long long, int>& prefixSums) {
        
        // Base case: if we hit a null node, no paths here!
        if (!node) return 0;
        
        // Add current node's value to our running total
        currSum += node->val;
        
        // The magic question: "Have I seen (currSum - target) before?"
        // If yes, that means there's a subpath that sums to target!
        int pathCount = 0;
        if (prefixSums.find(currSum - target) != prefixSums.end()) {
            pathCount += prefixSums[currSum - target];
        }
        
        // Remember this currSum for future nodes down this path
        prefixSums[currSum]++;
        
        // Explore both kids - they inherit our current "memory"
        pathCount += dfs(node->left, currSum, target, prefixSums);
        pathCount += dfs(node->right, currSum, target, prefixSums);
        
        // IMPORTANT: Clean up after ourselves!
        // We're about to backtrack, so remove our currSum from memory
        // Future paths shouldn't know about this branch
        prefixSums[currSum]--;
        
        return pathCount;
    }
};
```

### Key Insights in Comments:

1. **Why `prefixSums[0] = 1`?** - This handles the case where a path from root to current node exactly equals the target.

2. **Why backtrack?** - Imagine we're done exploring a left subtree. When we go to the right subtree, it shouldn't "remember" the prefix sums from the left side, because they're not on the same path!

3. **Why `long long`?** - Node values can be large, and when we sum them up, we might overflow regular int.

### The Beautiful Thing About This Approach:
- **No nested loops** (unlike brute force O(n²))
- **One pass** through the tree
- **Elegant use of hashmap** to "remember" what we've seen
- **Proper backtracking** to ensure path independence

This solution is like having a perfect memory that remembers exactly what you need, when you need it, and forgets what you don't need anymore!