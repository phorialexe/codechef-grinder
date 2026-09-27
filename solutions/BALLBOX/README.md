# [Balls and Boxes (BALLBOX)](https://www.codechef.com/problems/BALLBOX)

- **Difficulty Rating**: 994
- **Solved in**: 1 attempt(s)

## Problem Summary
Given $N$ balls and $K$ boxes, determine if it is possible to distribute all $N$ balls into the $K$ boxes such that:
1. Every box contains at least one ball.
2. No two boxes contain the same number of balls.

## Intuition & Mathematical Observation
To satisfy the condition that no two boxes have the same number of balls while ensuring every box has at least one, we must assign the smallest possible distinct positive integers to the boxes. The most efficient way to do this is to assign $1, 2, 3, \dots, K$ balls to the $K$ boxes.

The total number of balls required for this minimal configuration is the sum of the first $K$ natural numbers:
$$\text{Sum} = \sum_{i=1}^{K} i = \frac{K(K + 1)}{2}$$

- **If $N < \frac{K(K + 1)}{2}$**: It is impossible to satisfy the conditions because even the smallest possible distinct distribution requires more balls than we have.
- **If $N \ge \frac{K(K + 1)}{2}$**: It is always possible. We can start with the distribution $\{1, 2, \dots, K\}$ and add all remaining $N - \frac{K(K + 1)}{2}$ balls to the $K$-th box. Since the $K$-th box already held the maximum number of balls, adding the remainder to it ensures that all boxes remain distinct and non-empty.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution involves a simple arithmetic calculation.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to distribute N balls into K boxes such that:
 * 1. Each box has >= 1 ball.
 * 2. No two boxes have the same number of balls.
 * 
 * The minimum number of balls required is the sum of the first K natural numbers:
 * Sum = 1 + 2 + 3 + ... + K = K * (K + 1) / 2.
 * 
 * If N >= K * (K + 1) / 2, we can satisfy the condition by placing 1, 2, ..., K-1
 * balls in the first K-1 boxes and placing the remaining balls in the K-th box.
 */

void solve() {
    long long N, K;
    cin >> N >> K;

    // The minimum number of balls required for K distinct boxes is 1+2+...+K
    // Using long long to prevent overflow during K*(K+1)
    long long min_balls = K * (K + 1) / 2;

    if (N >= min_balls) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
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