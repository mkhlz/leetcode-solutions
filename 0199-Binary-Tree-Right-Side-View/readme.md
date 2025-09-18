# Binary Tree Right Side View - Complete Solution Guide

## Problem Statement
Given the `root` of a binary tree, imagine yourself standing on the **right side** of it, return *the values of the nodes you can see ordered from top to bottom*.

**Example:**
```
Input: root = [1,2,3,null,5,null,4]
Output: [1,3,4]
```

## Intuition 🤔

Think about it this way - you're literally standing to the right of the tree looking at it. What do you see? Only the rightmost node at each level!

```
       1      <- Level 0: See node 1
      / \
     2   3    <- Level 1: See node 3 (rightmost)
      \   \
       5   4  <- Level 2: See node 4 (rightmost)
```

So our strategy is simple: go through each level of the tree and pick the rightmost node. That's exactly what we can see from the right side!

## Visual Approach with ASCII Flow

Here's how our algorithm thinks through the problem:

```
Step 1: Start with root in queue
┌─────────────┐
│ Queue: [1]  │
│ Result: []  │
└─────────────┘

Step 2: Process level 0
┌─────────────────────────────┐
│ Level size = 1              │
│ Process node 1 (last in lvl)│
│ Add 1 to result             │
│ Add children 2,3 to queue   │
└─────────────────────────────┘
│
▼
┌─────────────┐
│ Queue: [2,3]│
│ Result: [1] │
└─────────────┘

Step 3: Process level 1
┌─────────────────────────────┐
│ Level size = 2              │
│ Process node 2 (not last)   │
│ Process node 3 (LAST!)      │
│ Add 3 to result             │
│ Add children 5,4 to queue   │
└─────────────────────────────┘
│
▼
┌─────────────┐
│ Queue: [5,4]│
│ Result: [1,3]│
└─────────────┘

Step 4: Process level 2
┌─────────────────────────────┐
│ Level size = 2              │
│ Process node 5 (not last)   │
│ Process node 4 (LAST!)      │
│ Add 4 to result             │
│ No more children            │
└─────────────────────────────┘
│
▼
┌─────────────┐
│ Queue: []   │
│ Result: [1,3,4]│
└─────────────┘
```

## Algorithm Flow Chart

```
    START
      │
      ▼
┌─────────────┐
│ root null?  │──YES──► Return empty vector
└─────────────┘
      │NO
      ▼
┌─────────────┐
│ Add root to │
│    queue    │
└─────────────┘
      │
      ▼
┌─────────────┐
│ Queue empty?│──YES──► Return result
└─────────────┘
      │NO
      ▼
┌─────────────┐
│ Get current │
│ level size  │
└─────────────┘
      │
      ▼
┌─────────────┐
│Process each │
│node in level│◄──┐
└─────────────┘   │
      │           │
      ▼           │
┌─────────────┐   │
│Is this the  │   │
│last node in │──NO┘
│this level?  │
└─────────────┘
      │YES
      ▼
┌─────────────┐
│ Add node    │
│ to result   │
└─────────────┘
      │
      ▼
┌─────────────┐
│Add children │
│ to queue    │
└─────────────┘
      │
      ▼
   (Loop back)
```

## Test Cases

Let's trace through a few examples:

### Test Case 1: Standard Tree
```
Tree:     1
         / \
        2   3
         \   \
          5   4

Expected: [1, 3, 4]

Level 0: [1] → rightmost = 1
Level 1: [2, 3] → rightmost = 3  
Level 2: [5, 4] → rightmost = 4
Result: [1, 3, 4] ✓
```

### Test Case 2: Only Left Children
```
Tree:     1
         /
        2
       /
      3

Expected: [1, 2, 3]

Level 0: [1] → rightmost = 1
Level 1: [2] → rightmost = 2
Level 2: [3] → rightmost = 3
Result: [1, 2, 3] ✓
```

### Test Case 3: Single Node
```
Tree: 1

Expected: [1]

Level 0: [1] → rightmost = 1
Result: [1] ✓
```

### Test Case 4: Empty Tree
```
Tree: null

Expected: []

No levels to process
Result: [] ✓
```

## Complexity Analysis

- **Time Complexity:** `O(n)` where n is the number of nodes
  - We visit each node exactly once during our level-order traversal
  - Each node gets pushed and popped from the queue once

- **Space Complexity:** `O(w)` where w is the maximum width of the tree
  - In the worst case (complete binary tree), the queue can hold up to n/2 nodes
  - This simplifies to `O(n)` in the worst case

## The Code (With Human-Style Comments!)

```cpp
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        
        // Edge case: if tree is empty, nothing to see here!
        if (!root) return result;
        
        // BFS time! Using a queue to go level by level
        queue<TreeNode*> q;
        q.push(root);
        
        // Keep going until we've seen all levels
        while (!q.empty()) {
            int levelSize = q.size(); // how many nodes are in this level?
            
            // Process every single node in this level
            for (int i = 0; i < levelSize; i++) {
                TreeNode* currentNode = q.front();
                q.pop();
                
                // Hey! Is this the rightmost node in this level?
                // (aka the last one we're processing)
                if (i == levelSize - 1) {
                    result.push_back(currentNode->val); // Gotcha! Add to our answer
                }
                
                // Don't forget the kids! Add them for the next level
                if (currentNode->left) {
                    q.push(currentNode->left);
                }
                if (currentNode->right) {
                    q.push(currentNode->right);  
                }
            }
        }
        
        return result; // Ta-da! Our right side view
    }
};
```

## Key Insights 💡

1. **Level-order traversal (BFS)** is perfect here because we need to process nodes level by level
2. **The rightmost node** at each level is simply the last node we process in that level
3. **Queue size** tells us exactly how many nodes are in the current level
4. **No need for complex tracking** - just check if we're at the last position in each level!

The beauty of this solution is its simplicity - we're just doing a regular BFS but being smart about which nodes we actually care about!