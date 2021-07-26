---
Created Time: Dec 01, 2020 11:55 PM
Do Date: Dec 22, 2020
Last edited time: Apr 06, 2021 8:35 AM
Points: 1500
Pomos (25 mins): 1
Source: https://leetcode.com/problems/merge-intervals/
Status: done
Tags: connected components, standard
---

# Merge Intervals

Given a list of intervals, **merge all the overlapping intervals** to produce a list that has only mutually exclusive intervals.
**Example 1:**
```
Intervals: [[1,4], [2,5], [7,9]]
Output: [[1,5], [7,9]]
Explanation: Since the first two intervals [1,4] and [2,5] overlap, we merged them into 
one [1,5].
```
**Example 2:**
```
Intervals: [[6,7], [2,4], [5,9]]
Output: [[2,4], [5,9]]
Explanation: Since the intervals [6,7] and [5,9] overlap, we merged them into one [5,9].
```
**Example 3:**
```
Intervals: [[1,4], [2,6], [3,5]]
Output: [[1,6]]
Explanation: Since all the given intervals overlap, we merged them into one.
```
---
The diagram above clearly shows a merging approach. Our algorithm will look like this:
1. Sort the intervals on the start time to ensure `a.start <= b.start`
2. If ‘a’ overlaps ‘b’ (i.e. `b.start <= a.end`), we need to merge them into a new interval ‘c’ such that:

```
    c.start = a.start
    c.end = max(a.end, b.end)
```
```jsx
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int> &v1, vector<int> &v2){
            return v1[0] < v2[0]; 
        });
        vector<vector<int>> rem; 
        for (int i = 0; i < intervals.size(); i++)
        {
            if (rem.size() and rem.back()[1] >= intervals[i][0])
            {
                rem[rem.size() - 1] = {rem.back()[0], max(intervals[i][1], rem.back()[1])}; 
            }
            else rem.push_back(intervals[i]); 
        }
        return rem; 
    }
};
```
### using connected components
**Intuition**
If we draw a graph (with intervals as nodes) that contains undirected edges between all pairs of intervals that overlap, then all intervals in each *connected component* of the graph can be merged into a single interval.

### References
1. [[Intervals]]
2. [[Connected Components]]