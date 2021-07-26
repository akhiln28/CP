---
created at: 2021-06-28
author: akhiln
tags: [problem, binary_tree]
level: unknown
---

# Count the Number of Binary Search Trees present in a Binary Tree
### Problem Statement
Given a binary tree find the number of binary search trees which are subtrees of it.

#### Examples

### Solution
- For each node find the minimum and maximum value in the whole subtree rooted at that node. (to check if the subtree with root as the current node is a BST)
- Also we store the number of BST's with root as the current node.


```python
# bstCount(node) -> denotes the number of BST's rooted at this node
bstCount(node):
	left = bstCount(node.left)
	right = bstCount(node.right)
	return left + right + isBST(node)
ans = 0
for node in nodes:
	ans += bstCount(node)

return ans
```

#### References
1. [[Binary Tree Recursion]]
2. [[Binary Search Tree]]
3. [[Number of subtrees in a binary tree]]
4. [GFG](https://www.geeksforgeeks.org/count-the-number-of-binary-search-trees-present-in-a-binary-tree/)

