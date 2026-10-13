# [The Attack of Queen (QUEENATTACK)](https://www.codechef.com/problems/QUEENATTACK)

- **Difficulty Rating**: 1076
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an $N \times N$ chessboard and the position of a Queen at $(X, Y)$, calculate the total number of distinct cells the Queen can attack. A Queen attacks all cells in the same row, same column, and both diagonals (main and anti-diagonal) that are within the boundaries of the board, excluding the cell she currently occupies.

## Intuition & Mathematical Observation
The Queen's movement can be broken down into four components:

1.  **Horizontal & Vertical**: 
    *   In any row $X$, there are $N$ cells total. Excluding the Queen's position, she attacks $N-1$ cells.
    *   In any column $Y$, there are $N$ cells total. Excluding the Queen's position, she attacks $N-1$ cells.
    *   Total = $(N-1) + (N-1)$.

2.  **Main Diagonal ($\setminus$)**:
    *   Cells on this diagonal satisfy the condition $r - c = X - Y$. Let $k = X - Y$.
    *   The valid range for row $r$ is constrained by $1 \le r \le N$ and $1 \le r - k \le N$.
    *   Solving for $r$, we get $\max(1, 1+k) \le r \le \min(N, N+k)$.
    *   The number of cells is the count of integers in this range, minus 1 (the Queen's position).

3.  **Anti-Diagonal ($/$)**:
    *   Cells on this diagonal satisfy the condition $r + c = X + Y$. Let $s = X + Y$.
    *   The valid range for row $r$ is constrained by $1 \le r \le N$ and $1 \le s - r \le N$.
    *   Solving for $r$, we get $\max(1, s-N) \le r \le \min(N, s-1)$.
    *   The number of cells is the count of integers in this range, minus 1 (the Queen's position).

By summing these four values, we obtain the total number of attacked cells.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution uses simple arithmetic operations to calculate the number of cells.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the coordinates and intermediate calculations.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * A Queen at (X, Y) on an N x N board attacks:
 * 1. Horizontal: All cells in row X except (X, Y). Total: N - 1.
 * 2. Vertical: All cells in column Y except (X, Y). Total: N - 1.
 * 3. Diagonals:
 *    - Main diagonal direction (\): Cells (r, c) where r - c = X - Y.
 *    - Anti-diagonal direction (/): Cells (r, c) where r + c = X + Y.
 */

void solve() {
    long long N, X, Y;
    cin >> N >> X >> Y;

    // Horizontal and Vertical
    long long horizontal = N - 1;
    long long vertical = N - 1;

    // Main diagonal (\)
    long long k = X - Y;
    long long min_r_main = max(1LL, 1 + k);
    long long max_r_main = min(N, N + k);
    long long main_diag = (max_r_main - min_r_main + 1) - 1;

    // Anti-diagonal (/)
    long long s = X + Y;
    long long min_r_anti = max(1LL, s - N);
    long long max_r_anti = min(N, s - 1);
    long long anti_diag = (max_r_anti - min_r_anti + 1) - 1;

    cout << horizontal + vertical + main_diag + anti_diag << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
```