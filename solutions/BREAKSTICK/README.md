# [Break the Stick (BREAKSTICK)](https://www.codechef.com/problems/BREAKSTICK)

- **Difficulty Rating**: 1026
- **Solved in**: 1 attempt(s)

## Problem Summary
Given a stick of length $N$, we want to determine if it is possible to obtain a stick of length $X$ by repeatedly breaking sticks. The rule for breaking a stick of length $L$ is that it can be broken into $k$ parts ($k \ge 2$) such that all parts have the same parity (all odd or all even).

## Intuition & Mathematical Observation
To solve this, we analyze the parity constraints:

1.  **Case 1: $X$ is odd.**
    *   If $N$ is odd, we can break $N$ into $N$ parts of length 1. Since 1 is odd, we can combine these to form any odd length $X \le N$.
    *   If $N$ is even, we can break $N$ into two parts: $X$ and $(N-X)$. Since $N$ is even and $X$ is odd, $(N-X)$ must be odd. Both parts are odd, satisfying the parity rule.
    *   **Conclusion:** If $X$ is odd, the answer is always **YES**.

2.  **Case 2: $X$ is even.**
    *   If $N$ is even, we can break $N$ into $X$ and $(N-X)$. Since $N$ and $X$ are both even, $(N-X)$ is also even. Both parts are even, satisfying the parity rule.
    *   If $N$ is odd, any break of $N$ must result in parts that are all odd (because the sum of even numbers is even, and an odd number cannot be formed by summing even numbers). Therefore, we can never produce an even-length stick from an odd-length stick.
    *   **Conclusion:** If $X$ is even, the answer is **YES** if $N$ is even, and **NO** if $N$ is odd.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution involves simple parity checks. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and perform calculations.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * If X is odd: YES
 * If X is even: YES if N is even, NO if N is odd.
 */

void solve() {
    long long N, X;
    cin >> N >> X;

    if (X % 2 != 0) {
        // If X is odd, we can always obtain it
        cout << "YES" << "\n";
    } else {
        // If X is even, we can only obtain it if N is also even
        if (N % 2 == 0) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
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