---
created at: 2021-06-22
author: akhiln
tags: [problem, number_theory, atcoder, confusing]
level:
---

# Base -2 Number
## Problem Statement
Given an number `N` $\in 10^{-9}, 10^9$. Return the base `-2` representation of `N`.

### Examples
input: n = 2
output: 110
	
input: n = 3
output: 111

input: n = 4
output: 100

Input: 10
Output: 11110
2 + 8
4 - 2 + 16 - 8 = 11110
2 + 4 = 4 - 2 + 4 = 8 - 2 = 16 - 8 - 2
{1, 2, 4} -> {2, -1, 2, 4} -> {-1, 3, 4} -> {-1, 4, -3, 4} -> {-1, -3, 5} -> {-1, -3, -5, 6}

## Approach
First find the base 2 representation of `N`. For all the odd powers of 2 i.e. $2^n$ and make them $2^{n + 1} - 2^n$. We do this until we can't find the odd powers of 2.
I am thinking if there is any better way to do it.

- if n is even power of 2
	- return log(n)
- else if n is odd power of 2
	- return {log(n) + 1, log(n)}
- else if n is not power of 2

n = 3 -> {0, 1} -> {0, 2, -1}

n = 10 -> {1, 3} -> {2, -1, 4, -3}

n = 15 -> {0, 1, 2, 3} -> {0, -1, 4}

divide by 2, n = 11

n = 11, rem = 1, q = 5
n = 5, rem = 1, q = 2
n = 2, rem = 0, q = 1
n = 1, rem = 1, q = 0

base 2 = 1011

divide by -2, n = 11

n = 11, rem = -1, q = -6
n = -6, rem = 0, q = 3
n = 3, rem = -1, q = -2
n = -2, rem = 0, q = -1
n = 1, rem = -1, q = -1
n = -1, rem = -1, q = 0

base -2 = -1,0,-1,0,-1 = -1 + 0 + -4 + 0 + 16 = 11

I realized that we can find the standard base -2 of a number using the standard algorithm. 
I spent way too much time on this. (more than 1 hour). 



## Solution

#### References
- [Convert to base -2](https://leetcode.com/problems/convert-to-base-2/)
- [I find this little helpful](https://atcoder.jp/contests/abc105/submissions/24155124)
- [[Number Theory]]
- [[Base of Negative Integer]]