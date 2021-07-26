---
created at: 2021-06-23 
author: akhiln
tags: [problem]
level: 1800
status: pending
---

# Friend Suggestions 
### Problem Statement
You are given `N` users. And `M` friends ships, `K` block ships. `a` is a friend candidate for `b` if there is no direct relationship between `a` and `b` and there is an indirect friend ship connection between `a` and `b`. 

For each user find the number of friend candidates?
#### Examples

### Solution
We can first group the users in connected components based on the friend ship. We can use [[Union Find]] to find all the connected components. 

After that for each user, find the set of all users in that connected component remove all users which have direct friend ship or block ship with the current user. 

First use DFS or Union find for finding all the connected components in $O(N + M)$. 


#### References
1. [[Connected Components]]
1. [Atcoder](https://atcoder.jp/contests/abc157/tasks/abc157_d)
2. [Submission](https://atcoder.jp/contests/abc157/submissions/24189100)