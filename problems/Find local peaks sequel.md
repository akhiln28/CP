---
created at: 2021-07-07 
author: akhiln
tags: [problem]
level: 
Status: done
---

# Find local peaks sequel 
### Problem Statement
Given a list of integers `nums`. Return the indices of all the peaks. And index `i` is called peak if all the below are true
1. The first number to the right different from `nums[i]` is smaller than `nums[i]` or does not exist
2. The first number to the left different from `nums[i]` is smaller than `nums[i]` or does not exist
3. There is at least one number on its left or its right that's different than `nums[i]`

#### Examples
Input: [2, 5, 5, 5, 3, 8, 8]
Output: [1, 2, 3, 5, 6]

## Approach
For each index, find the next different index, and the before different index.
[2, 5, 5, 5, 3, 8, 8]

**next different -> nearest element to the right that is not equal to the current element. **

Create an array for next different. 

- next different - [5, 3, 3, 3, 8, -, -]
	- iterate from right to left
- before different - [-, 2, 2, 2, 5, 3, 3]
	- iterate from left to right
	
## Solution

```python
def solve(nums):
    n = len(nums)
    next_different = [-1] * n
    before_different = [-1] * n
    for i in range(n - 2, -1, -1):
        if nums[i] != nums[i + 1]:
            next_different[i] = i + 1
        else:
            next_different[i] = next_different[i + 1]

    for i in range(1, n, 1):
        if nums[i] != nums[i - 1]:
            before_different[i] = i - 1
        else:
            before_different[i] = before_different[i - 1]
    ans: list[int] = []
    for i in range(n):
        val = 0
        if next_different[i] != -1:
            if nums[next_different[i]] > nums[i]:
                continue
            else:
                val += 1
        if before_different[i] != -1:
            if nums[before_different[i]] > nums[i]:
                continue
            else:
                val += 1
        if val:
            ans.append(i)
    return ans

nums = [2, 1, 0]
print(solve(nums))
```

#### References
1. [[Linear DP]]