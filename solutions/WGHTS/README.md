# [Weights (WGHTS)](https://www.codechef.com/problems/WGHTS)

- **Difficulty Rating**: 697
- **Solved in**: 1 attempt(s)

## Problem Summary
Given a target weight $W$ and three individual weights $X, Y,$ and $Z$, determine if it is possible to obtain exactly $W$ by using any combination of the three weights. Each weight can be used at most once.

## Intuition & Mathematical Observation
Since we are allowed to use each of the three weights ($X, Y, Z$) either zero or one time, there are a finite number of possible sums we can create. Specifically, there are $2^3 - 1 = 7$ possible non-empty combinations:

1.  **Single weights:** $X, Y, Z$
2.  **Pairs of weights:** $X+Y, X+Z, Y+Z$
3.  **All three weights:** $X+Y+Z$

To solve the problem, we simply need to check if the target weight $W$ is equal to any of these 7 possible sums. If $W$ matches any of these values, the answer is "YES"; otherwise, it is "NO".

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we are performing a constant number of arithmetic operations and comparisons.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input weights.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given a target weight W and three available weights X, Y, and Z.
 * We need to determine if W can be formed by any combination of X, Y, and Z.
 * Since we can use one or more weights, the possible combinations are:
 * 1. Single weights: X, Y, Z
 * 2. Pairs of weights: X+Y, X+Z, Y+Z
 * 3. All three weights: X+Y+Z
 * 
 * We simply check if W equals any of these 7 possible sums.
 * Time Complexity: O(1) per test case.
 * Space Complexity: O(1).
 */

void solve() {
    long long W, X, Y, Z;
    if (!(cin >> W >> X >> Y >> Z)) return;

    // Check all possible combinations
    if (W == X || W == Y || W == Z || 
        W == (X + Y) || W == (X + Z) || W == (Y + Z) || 
        W == (X + Y + Z)) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
}

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}
```