# [Equal Integers (INCREAR)](https://www.codechef.com/problems/INCREAR)

- **Difficulty Rating**: 852
- **Solved in**: 1 attempt(s)

## Problem Summary
Given two integers $X$ and $Y$, we want to make them equal using two allowed operations:
1. Increase $X$ by 1 ($X = X + 1$).
2. Increase $Y$ by 2 ($Y = Y + 2$).

We need to find the minimum number of operations required to make $X = Y$.

## Intuition & Mathematical Observation

We analyze the problem based on the relationship between $X$ and $Y$:

1.  **Case 1: $X < Y$**
    Since we can only increase $X$ by 1 and $Y$ by 2, if $X$ is already smaller than $Y$, the most efficient way to equalize them is to increase $X$ by 1 repeatedly until it reaches $Y$. 
    *   **Operations**: $Y - X$.

2.  **Case 2: $X > Y$**
    We need to increase $Y$ to reach $X$.
    *   If the difference $(X - Y)$ is **even**, we can reach $X$ by adding 2 to $Y$ exactly $\frac{X - Y}{2}$ times.
    *   If the difference $(X - Y)$ is **odd**, we cannot reach $X$ exactly by adding 2s. We must add 2s until $Y$ is one less than $X$, then increment $X$ by 1 to match $Y$. 
        *   Example: $X=5, Y=2$. Difference is 3. 
        *   Add 2 to $Y$: $Y=4$. (1 op)
        *   Add 2 to $Y$: $Y=6$. (Now $Y > X$, which is not ideal).
        *   Correct approach: Add 2 to $Y$ until $Y$ is $X-1$, then increment $X$ by 1.
        *   Mathematically: $\frac{X-Y-1}{2}$ operations for $Y$, plus 1 operation for $X$, plus 1 more operation to balance the parity. This simplifies to $\frac{X-Y}{2} + 2$.

## Complexity Analysis

- **Time Complexity**: $O(1)$ per test case, as we only perform basic arithmetic operations. Total time complexity is $O(T)$, where $T$ is the number of test cases.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have X and Y.
 * Operations: X = X + 1 or Y = Y + 2.
 */

void solve() {
    long long X, Y;
    cin >> X >> Y;

    if (X == Y) {
        cout << 0 << "\n";
    } else if (X > Y) {
        long long diff = X - Y;
        if (diff % 2 == 0) {
            // Difference is even, can reach X by adding 2 to Y
            cout << diff / 2 << "\n";
        } else {
            // Difference is odd, need to increment X once and add 2s to Y
            cout << (diff / 2) + 2 << "\n";
        }
    } else {
        // X < Y: Simply increment X until it reaches Y
        cout << (Y - X) << "\n";
    }
}

int main() {
    // Optimize I/O operations
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