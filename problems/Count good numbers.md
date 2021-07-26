---
created at: 2021-07-19
author: akhiln
tags: [problem]
level: 1000
Status: done
---

# Count good numbers
## Problem Statement
A digit string is **good** if the digits **(0-indexed)** at **even** indices are **even** and the digits at **odd** indices are **prime** (`2`, `3`, `5`, or `7`).

Given an integer `n`, return _the **total** number of good digit strings of length_ `n`. Since the answer may be large, **return it modulo** `10^9 + 7`.

### Examples
**Input:** n = 1
**Output:** 5
**Explanation:** The good numbers of length 1 are "0", "2", "4", "6", "8".

**Input:** n = 4
**Output:** 400
## Approach

Answer should be equal to
when n is even: $5^{n/2}.4^{n/2}$
when n is odd: $5^{(n + 1)/2}.4^{n/2}$

## Solution

```python
class Solution:
    def countGoodNumbers(self, n: int) -> int:
        mod = int(1e9 + 7)
        if n % 2 == 0:
            return (pow(5, n//2, mod) * pow(4, n//2, mod)) % mod
        else:
            return (pow(5, (n + 1)//2, mod) * pow(4, n//2, mod)) % mod
```

### References
1. [Leetcode](https://leetcode.com/problems/count-good-numbers/)