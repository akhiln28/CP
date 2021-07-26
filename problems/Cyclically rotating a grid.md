---
created at: 2021-06-27 
author: akhiln
tags: [problem, matrix]
level: 
Status: done
---

# Cyclically rotating a grid 
### Problem Statement
You are given an `m x n` integer matrix `grid`​​​, where `m` and `n` are both **even** integers, and an integer `k`.

The matrix is composed of several layers, which is shown in the below image, where each color is its own layer:

![](https://assets.leetcode.com/uploads/2021/06/10/ringofgrid.png)

A cyclic rotation of the matrix is done by cyclically rotating **each layer** in the matrix. To cyclically rotate a layer once, each element in the layer will take the place of the adjacent element in the **counter-clockwise** direction. An example rotation is shown below:

![](https://assets.leetcode.com/uploads/2021/06/22/explanation_grid.jpg)

Return _the matrix after applying_ `k` _cyclic rotations to it_.

**Example 1:**

![](https://assets.leetcode.com/uploads/2021/06/19/rod2.png)

**Input:** grid = [[40,10],[30,20]], k = 1
**Output:** [[10,20],[40,30]]
**Explanation:** The figures above represent the grid at every state.

**Example 2:**

**![](https://assets.leetcode.com/uploads/2021/06/10/ringofgrid5.png)** **![](https://assets.leetcode.com/uploads/2021/06/10/ringofgrid6.png)** **![](https://assets.leetcode.com/uploads/2021/06/10/ringofgrid7.png)**

**Input:** grid = [[1,2,3,4],[5,6,7,8],[9,10,11,12],[13,14,15,16]], k = 2
**Output:** [[3,4,8,12],[2,11,10,16],[1,7,6,15],[5,9,13,14]]
**Explanation:** The figures above represent the grid at every state.

**Constraints:**

-   `m == grid.length`
-   `n == grid[i].length`
-   `2 <= m, n <= 50`
-   Both `m` and `n` are **even** integers.
-   `1 <= grid[i][j] <= 5000`
-   `1 <= k <= 109`

#### Examples

### Solution

how about storing each layer as an array 

```python
layer length = 2m + 2n - 4 when in outer layer

four possibilities: choose smallest of (i, n - i, j, m - j)
	top: i
		traversal: 
			(i, i) -> (i, m - i - 1)
			(i + 1, m - i - 1) -> (n - i - 1, m - i - 1)
			(n - i - 1, m - i - 2) -> (n - i - 1, i)
			(n - i - 2, i) -> (i + 1, i)
		layer length = 2(n - 2i) + 2(m - 2i) - 4
		k = k % (layer length)
		(i, j) -> (i, j - k)
		
number of layers = min(n/2, m/2)

rotating the layer k clockwise: 
	val[i] = val[(i + k) % n]
```

#### References
1. [[Layers in a matrix]]
