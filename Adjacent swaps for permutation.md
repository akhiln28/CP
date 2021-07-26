## Adjacent swaps for permutation
You are given a permutation $p_n$. You need to obtain a permutation $q_n$. Find the minimum number of adjacent swaps needed to obtain $q_n$ from $p_n$. 

### Examples
input: {1 2 3 4 6}, {6, 4, 3, 2, 1}
output: 10
Explanation:
{2 3 4 6 1} - 4
{3 4 6 2 1} - 3
{4 6 3 2 1} - 2
{6 4 3 2 1} - 1
Total displacement = 4 + 2 + 0 + 2 + 4 = 12
