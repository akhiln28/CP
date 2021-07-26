---
created at: 2021-07-13 
author: akhiln
tags: [pattern]
level: 
---

# Layers in a matrix
Given a matrix of size $m \times n$. There are `num_layers`= $min(m, n)/2$ layers inside it. 

## Forces
### Traversing the layers
```cpp
vector<int> getLayer(vector<vector<int>>& grid, int l) {
        int n = grid.size(), m = grid[0].size(); 
        vector<int> ans; 
        for (int j = l; j < m - l; j++) {
            ans.push_back(grid[l][j]);
        }
        for (int i = l + 1; i < n - l; i++) {
            ans.push_back(grid[i][m - l - 1]);
        }
        for (int j = m - l - 2; j >= l; j--) {
            ans.push_back(grid[n - l - 1][j]); 
        }
        for (int i = n - l - 2; i >= l + 1; i--) {
            ans.push_back(grid[i][l]);
        }
        return ans; 
    }
```

### Pseudo code


## Children

