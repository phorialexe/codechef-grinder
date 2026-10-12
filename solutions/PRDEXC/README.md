# [Product Exceed (PRDEXC)](https://www.codechef.com/problems/PRDEXC)

- **Difficulty Rating**: 981
- **Solved in**: 1 attempt(s)

## Problem Summary
Given two integers $X$ and $Y$, we want to reach a state where the product of the updated values $X'$ and $Y'$ is at least $P$ (i.e., $X' \cdot Y' \ge P$), where $X' \ge X$ and $Y' \ge Y$. Each "move" consists of incrementing either $X$ or $Y$ by 1. The goal is to find the minimum number of moves required to satisfy the condition.

## Intuition & Mathematical Observation
The problem asks for the minimum number of moves $m = (X' - X) + (Y' - Y)$. Since the constraints on $X, Y,$ and $P$ are relatively small ($X, Y \le 50, P \le 10000$), we can iterate on the total number of moves $m$ starting from 0.

For a fixed number of moves $m$, we want to determine if there exists a split of these moves between $X$ and $Y$ such that the resulting product is at least $P$. If we allocate $i$ moves to $X$ and $m-i$ moves to $Y$, the new values are $(X+i)$ and $(Y+m-i)$. 

**Key Observation:**
For a fixed sum $S = (X+i) + (Y+m-i) = X + Y + m$, the product $(X+i) \cdot (Y+m-i)$ is maximized when the two factors are as close to each other as possible. However, since the search space for $m$ is small, we don't need to find the optimal $i$ mathematically; we can simply iterate through all possible values of $i$ from $0$ to $m$ to check if any combination satisfies the condition.

## Complexity Analysis
- **Time Complexity**: $O(T \cdot m_{max}^2)$, where $T$ is the number of test cases and $m_{max}$ is the maximum number of moves required. Given the constraints, $m_{max}$ is small (at most 200), making this approach well within the time limits.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the state.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given X, Y, and P. We want to reach X' * Y' >= P where X' >= X and Y' >= Y.
 * The total number of moves is (X' - X) + (Y' - Y).
 * Since the constraints are very small (X, Y <= 50, P <= 10000), we can use a 
 * brute force approach to find the minimum number of moves 'm'.
 */

void solve() {
    long long X, Y, P;
    cin >> X >> Y >> P;

    // If the condition is already met, 0 moves are required.
    if (X * Y >= P) {
        cout << 0 << "\n";
        return;
    }

    // Iterate on the total number of moves 'm'.
    // For a fixed 'm', check if any distribution of moves results in product >= P.
    for (int m = 1; ; ++m) {
        bool possible = false;
        for (int i = 0; i <= m; ++i) {
            long long curX = X + i;
            long long curY = Y + (m - i);
            if (curX * curY >= P) {
                possible = true;
                break;
            }
        }
        if (possible) {
            cout << m << "\n";
            return;
        }
    }
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