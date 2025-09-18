# 🎯 Pro Tip: Use a 32-bit Bitmask Instead of a Set

## 💡 The Big Idea

Since we only deal with lowercase English letters (`a`–`z`), we can pack all the "broken letters" into a single 32-bit integer! Each bit represents whether a specific letter is broken or not. This is way faster than using a Set or HashSet for lookups.

## 🧮 The Math Behind It

**Formula for setting bits:**
```
bit position = char - 'a'
mask |= 1 << (char - 'a')
```

Think of it like this:
- `'a'` maps to bit position 0
- `'b'` maps to bit position 1  
- `'c'` maps to bit position 2
- ... and so on up to `'z'` at position 25

## 📊 Step-by-Step Example

Let's say `brokenLetters = "afhejkr"` and see how we build the bitmask:

```
Starting with: mask = 0 (all bits are 0)
Binary:        00000000000000000000000000000000
```

### Building the Bitmask:

| Letter | Position<br/>(char - 'a') | Individual Bitmask<br/>(1 << pos) | Combined Mask<br/>(OR operation) |
|--------|---------------------------|-------------------------------------|-----------------------------------|
| `a`    | 0                        | `00000000000000000000000000000001` | `00000000000000000000000000000001` |
| `f`    | 5                        | `00000000000000000000000000100000` | `00000000000000000000000000100001` |
| `h`    | 7                        | `00000000000000000000000010000000` | `00000000000000000000000010100001` |
| `e`    | 4                        | `00000000000000000000000000010000` | `00000000000000000000000010110001` |
| `j`    | 9                        | `00000000000000000000001000000000` | `00000000000000000000001010110001` |
| `k`    | 10                       | `00000000000000000000010000000000` | `00000000000000000000011010110001` |
| `r`    | 17                       | `00000000000000100000000000000000` | `00000000000000100000011010110001` |

### Final Result:
```
hash32 = 0b00000000000000100000011010110001
hash32 = 134897 (in decimal)
```

## 🔍 Visual Representation

Here's how the bits line up with letters:

```
Position: ...23 22 21 20 19 18 17 16 15 14 13 12 11 10  9  8  7  6  5  4  3  2  1  0
Letter:   ... x  w  v  u  t  s  r  q  p  o  n  m  l  k  j  i  h  g  f  e  d  c  b  a
Bit:         0  0  0  0  0  0  1  0  0  0  0  0  0  1  1  0  1  0  1  1  0  0  0  1
                              ^                    ^  ^     ^     ^  ^           ^
                              r                    k  j     h     f  e           a
```

## ⚡ Why This is Lightning Fast

### Traditional Set Approach:
```cpp
unordered_set<char> brokenSet;
// To check: brokenSet.find(c) != brokenSet.end()
// Time complexity: O(1) average, but with overhead
```

### Bitmask Approach:
```cpp
int brokenMask = /* built as shown above */;
// To check: brokenMask & (1 << (c - 'a'))
// Time complexity: O(1) with minimal overhead!
```

## 🚀 Performance Benefits

1. **Memory Efficient**: One integer (4 bytes) vs potentially 26 characters + overhead in a set
2. **Cache Friendly**: Single memory access vs potential pointer chasing
3. **CPU Optimized**: Bitwise operations are among the fastest CPU instructions
4. **No Hash Collisions**: Unlike hash-based sets, bit operations are deterministic

## 💻 Code Implementation

```cpp
// Building the bitmask - do this once
int buildBrokenMask(const string& brokenLetters) {
    int mask = 0;
    for (char c : brokenLetters) {
        mask |= 1 << (c - 'a');  // Set the bit for this letter
    }
    return mask;
}

// Checking if a letter is broken - super fast!
bool isLetterBroken(char c, int brokenMask) {
    return brokenMask & (1 << (c - 'a'));  // Check if bit is set
}
```

## 🎯 When to Use This Trick

This bitmask optimization is perfect when:
- ✅ You have a **small, fixed alphabet** (like a-z)
- ✅ You need **frequent lookups** 
- ✅ **Performance matters**
- ✅ You want **minimal memory usage**

**Bonus**: This technique works great for many similar problems like checking vowels, tracking visited characters, etc.!

---

*Remember: This only works because we have exactly 26 lowercase letters, which fits comfortably in a 32-bit integer. For larger alphabets, you'd need different approaches!* 🧠