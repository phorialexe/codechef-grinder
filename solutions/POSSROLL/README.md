# [Possible Roll (POSSROLL)](https://www.codechef.com/problems/POSSROLL)

- **Difficulty Rating**: 289
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given a die with $X$ sides. The faces of the die are labeled with the first $X$ positive multiples of $K$ (i.e., $1 \cdot K, 2 \cdot K, \dots, X \cdot K$). We need to determine if a given integer $Y$ can be a result of rolling this die.

## Intuition & Mathematical Observation
The faces of the die are defined by the set $\{K, 2K, 3K, \dots, XK\}$. For a number $Y$ to be a valid face on this die, two conditions must be met:
1. **Divisibility**: $Y$ must be perfectly divisible by $K$ (i.e., $Y \pmod K = 0$).
2. **Range**: If we divide $Y$ by $K$, the resulting quotient (the multiplier) must be an integer between $1$ and $X$ inclusive.

If both conditions are satisfied, $Y$ is a possible roll; otherwise, it is not.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution involves only basic arithmetic operations (division and modulo).
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input values.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The die has X sides, numbered with the first X positive multiples of K.
 * The faces are: 1*K, 2*K, 3*K, ..., X*K.
 * 
 * For a result Y to be possible:
 * 1. Y must be a multiple of K (i.e., Y % K == 0).
 * 2. The multiplier (Y / K) must be between 1 and X inclusive.
 */

void solve() {
    long long X, K, Y;
    if (!(cin >> X >> K >> Y)) return;

    // Check if Y is a multiple of K
    if (Y % K == 0) {
        long long multiplier = Y / K;
        // Check if the multiplier is within the range [1, X]
        if (multiplier >= 1 && multiplier <= X) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    } else {
        cout << "NO" << "\n";
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
```