# [Change Row and Column Both (CHANGEPOS)](https://www.codechef.com/problems/CHANGEPOS)

- **Difficulty Rating**: 660
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given a 10x10 grid and a starting position $(s_x, s_y)$ and an ending position $(e_x, e_y)$. A move is valid if and only if both the row and the column change (i.e., moving from $(a, b)$ to $(c, d)$ is valid if $a \neq c$ AND $b \neq d$). We need to determine the minimum number of moves required to reach the destination.

## Intuition & Mathematical Observation
The problem constraints state that the starting position is never the same as the ending position. 

1. **Case 1: One Move**
   If the starting row is different from the ending row ($s_x \neq e_x$) AND the starting column is different from the ending column ($s_y \neq e_y$), we can reach the destination in exactly **1 move**.

2. **Case 2: Two Moves**
   If either the row is the same ($s_x = e_x$) OR the column is the same ($s_y = e_y$), we cannot reach the destination in a single move because the condition $a \neq c$ or $b \neq d$ would be violated. However, since the grid is 10x10, we can always pick an intermediate point $(r, c)$ such that $r \neq s_x, r \neq e_x$ and $c \neq s_y, c \neq e_y$. Thus, it will always take exactly **2 moves** to reach the destination.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we only perform simple arithmetic comparisons. For $T$ test cases, the complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few integer variables to store the coordinates.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are on a 10x10 grid.
 * A move from (a, b) to (c, d) is valid if a != c AND b != d.
 * 
 * Case 1: If s_x != e_x AND s_y != e_y:
 * We can reach the destination in exactly 1 move.
 * 
 * Case 2: If s_x == e_x OR s_y == e_y:
 * We cannot reach the destination in 1 move because one of the conditions (a != c or b != d) 
 * will be violated. We can always reach the destination in 2 moves by picking an 
 * intermediate point.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int sx, sy, ex, ey;
        cin >> sx >> sy >> ex >> ey;

        // If both row and column are different, we can move in 1 step.
        if (sx != ex && sy != ey) {
            cout << 1 << "\n";
        } 
        // Otherwise, we need 2 steps.
        else {
            cout << 2 << "\n";
        }
    }

    return 0;
}
```