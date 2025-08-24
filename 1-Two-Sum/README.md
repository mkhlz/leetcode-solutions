# 🧩 Two Sum Problem  
![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)  
![LeetCode](https://img.shields.io/badge/LeetCode-1-orange)  
![Tags](https://img.shields.io/badge/Tags-Array%2C%20HashMap-blue)  

---

## 📜 Problem Statement  
Given an array of integers `nums` and an integer `target`, return **indices** of the two numbers such that they add up to `target`.  
You may assume that each input would have **exactly one solution**, and you may not use the same element twice.  
Return the answer in **any order**.  

### ✅ Example  
**Input:**  
```
nums = [2,7,11,15], target = 9
```
**Output:**  
```
[0,1]
```
**Explanation:**  
`nums[0] + nums[1] == 9 → 2 + 7 = 9`

---

## 🧠 Explanation & Approaches  

### **1. Brute Force (O(n²))**
- Check every pair using nested loops.
- Time complexity: **O(n²)**  
- Space complexity: **O(1)**  

### **2. Hash Map (Optimal) (O(n))**
- Use a dictionary to store `value -> index`.
- For each element, check if `target - element` exists in the map.
- Time complexity: **O(n)**  
- Space complexity: **O(n)**  

### **3. Two Pointers (O(n log n))**
- Sort the array, then use two pointers from both ends.
- **Note:** This changes original indices, so extra mapping is needed.

---

## 🛠 Implementations  

---

### ✅ **Python**  

#### **Brute Force**
```python
def two_sum(nums, target):
    # Check every pair
    for i in range(len(nums)):
        for j in range(i + 1, len(nums)):
            if nums[i] + nums[j] == target:
                return [i, j]
```

#### **Hash Map**
```python
def two_sum(nums, target):
    seen = {}
    for i, num in enumerate(nums):
        if target - num in seen:
            return [seen[target - num], i]
        seen[num] = i
```

---

### ✅ **Java**  

#### **Brute Force**
```java
class Solution {
    public int[] twoSum(int[] nums, int target) {
        for (int i = 0; i < nums.length; i++) {
            for (int j = i + 1; j < nums.length; j++) {
                if (nums[i] + nums[j] == target) {
                    return new int[]{i, j};
                }
            }
        }
        return new int[]{};
    }
}
```

#### **Hash Map**
```java
import java.util.*;
class Solution {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            int complement = target - nums[i];
            if (map.containsKey(complement)) {
                return new int[]{map.get(complement), i};
            }
            map.put(nums[i], i);
        }
        return new int[]{};
    }
}
```

---

### ✅ **C++**  

#### **Brute Force**
```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }
        return {};
    }
};
```

#### **Hash Map**
```cpp
#include <unordered_map>
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if (map.find(complement) != map.end()) {
                return {map[complement], i};
            }
            map[nums[i]] = i;
        }
        return {};
    }
};
```

---

### ✅ **JavaScript**  

#### **Brute Force**
```javascript
var twoSum = function(nums, target) {
    for (let i = 0; i < nums.length; i++) {
        for (let j = i + 1; j < nums.length; j++) {
            if (nums[i] + nums[j] === target) {
                return [i, j];
            }
        }
    }
};
```

#### **Hash Map**
```javascript
var twoSum = function(nums, target) {
    const map = new Map();
    for (let i = 0; i < nums.length; i++) {
        let complement = target - nums[i];
        if (map.has(complement)) {
            return [map.get(complement), i];
        }
        map.set(nums[i], i);
    }
};
```

---

## 🏷 Tags  
`#LeetCode` `#TwoSum` `#HashMap` `#Array` `#CodingInterview`  

---

### ✅ **Star ⭐ the repo if this helped you!**  
