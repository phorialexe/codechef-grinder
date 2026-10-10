# [Equal Coins (EQUALCOIN)](https://www.codechef.com/problems/EQUALCOIN)

- **Difficulty Rating**: 1233
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given $X$ coins of value 1 and $Y$ coins of value 2. We need to determine if it is possible to distribute all these coins into two piles such that the total value of each pile is exactly equal.

## Intuition & Mathematical Observation
Let the total value of all coins be $S = X \times 1 + Y \times 2 = X + 2Y$. 

1.  **Parity Constraint**: For the total value to be split into two equal integer sums, $S$ must be even. If $S$ is odd, it is impossible to divide the coins equally, so we immediately output `NO`.
2.  **Case 1: $X = 0$**: If we have no 1-rupee coins, we only have 2-rupee coins. We can only split these equally if the number of coins $Y$ is even (so each person gets $Y/2$ coins). If $Y$ is odd, we cannot split them.
3.  **Case 2: $X > 0$**: If we have at least one 1-rupee coin, we have more flexibility. Since we already checked that the total sum $S$ is even, having at least one 1-rupee coin allows us to balance the piles. Even if $Y$ is odd, the 1-rupee coins can compensate for the "oddness" of the 2-rupee coins. Thus, if $X > 0$ and $S$ is even, the answer is always `YES`.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we only perform basic arithmetic operations and conditional checks. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and perform calculations.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Total value = X * 1 + Y * 2 = X + 2Y.
 * For the coins to be distributed equally, the total value must be even.
 * Let the total value be S = X + 2Y.
 * If S is odd, it's impossible to split into two equal integer sums.
 * If S is even, we need to check if we can form S/2 using some combination of X and Y.
 */

void solve() {
    long long X, Y;
    cin >> X >> Y;

    // Total value must be even to be divisible by 2
    if ((X + 2 * Y) % 2 != 0) {
        cout << "NO" << "\n";
        return;
    }

    // If X is 0, we can only split if Y is even (so each gets Y/2 coins of value 2)
    if (X == 0) {
        if (Y % 2 == 0) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    } else {
        // If X > 0, as long as the total sum is even, we can distribute.
        // We have enough 1-rupee coins to handle the parity of Y.
        cout << "YES" << "\n";
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