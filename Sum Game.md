---
created at: 2021-07-19 
author: akhiln
tags: [problem]
level: 
Status: progress
---

# Sum Game 
## Problem Statement
Alice and Bob take turns playing a game, with **Alice starting first**.

You are given a string `num` of **even length** consisting of digits and `'?'` characters. On each turn, a player will do the following if there is still at least one `'?'` in `num`:

1.  Choose an index `i` where `num[i] == '?'`.
2.  Replace `num[i]` with any digit between `'0'` and `'9'`.

The game ends when there are no more `'?'` characters in `num`.

For Bob to win, the sum of the digits in the first half of `num` must be **equal** to the sum of the digits in the second half. For Alice to win, the sums must **not be equal**.

-   For example, if the game ended with `num = "243801"`, then Bob wins because `2+4+3 = 8+0+1`. If the game ended with `num = "243803"`, then Alice wins because `2+4+3 != 8+0+3`.

Assuming Alice and Bob play **optimally**, return `true` _if Alice will win and_ `false` _if Bob will win_.

### Examples

**Input:** num = "25??"
**Output:** true
**Explanation:** Alice can replace one of the '?'s with '9' and it will be impossible for Bob to make the sums equal.

**Input:** num = "?3295???"
**Output:** false
**Explanation:** It can be proven that Bob will always win. One possible outcome is:
- Alice replaces the first '?' with '9'. num = "93295???".
- Bob replaces one of the '?' in the right half with 	'9'. num = "932959??".
- Alice replaces one of the '?' in the right half with '2'. num = "9329592?".
- Bob replaces the last '?' in the right half with '7'. num = "93295927".
Bob wins because 9 + 3 + 2 + 9 = 5 + 9 + 2 + 7.


## Solution

Observations
1. Alice always wins when Alice gets the last chance. i.e. when `num` is odd.
2. If we add `?` on both sides, the result won't change. -> #difficult to get this. Say, `n = abs(numleft - numright)`
3. When `n` is even, in order for 
4. For two question marks on the same side, Bob can always make `? + ? == 9`, regardless of how Alice plays.
    -   So, if we have `n` question marks, Bob can only win if $smaller + n * 9 / 2 = larger$

## Approach

Need to take various scenarios. 
Alice will try to increase the gap between the two sums. And bob the opposite. 

Find the number of '?' = $q$ (say). Alice and bob will get half each. 

We can reduce the problem input to 
1. `numleft` number of `?` in the left half
2. `numright` number of `?` in the right half
3. `d` - difference between sum of elements in left half and sum of elements in the right half

Say `num = numleft + numright`

We have various cases. 

When `d` is negative
Alice would try to make left 0, right 9
Bob would try to make left 9, right 0

Alice will be able to win when `num/2`

When `d` is positive
Alice would try to make left 9, right 0
Bob would try to make left 0, right 9

### References
1. [Leetcode](https://leetcode.com/problems/sum-game/)
2. [Leetcode discuss](https://leetcode.com/problems/sum-game/discuss/1329380/One-liner)
3. [Leetcode discuss](https://leetcode.com/problems/sum-game/discuss/1328966/JavaC%2B%2BPython-Math-Problem-with-Explanation)
4. [[Game]] with lot of Observations required. 


