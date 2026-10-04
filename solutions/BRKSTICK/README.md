# [Breaking Sticks (BRKSTICK)](https://www.codechef.com/problems/BRKSTICK)

- **Difficulty Rating**: 596
- **Solved in**: 1 attempt(s)

## Problem Summary
You are given $N$ sticks, each with a specific length $A_i$. A single "break" operation consists of taking a stick of length $X$ and splitting it into two sticks of lengths $Y$ and $Z$ such that $Y + Z = X$ (where $Y, Z \ge 1$). The goal is to determine the total number of breaks required to reduce all sticks into sticks of length 1.

## Intuition & Mathematical Observation
To reduce a stick of length $X$ into $X$ individual sticks of length 1, we must perform a series of breaks. 

1. Consider a stick of length $X$. If we break it into $(X-1)$ and $1$, we have performed 1 break and now have a stick of length $(X-1)$ and a stick of length $1$.
2. We can continue this process: break the $(X-1)$ stick into $(X-2)$ and $1$.
3. By repeating this, we eventually reach $X$ sticks of length $1$.
4. Mathematically, to reach $X$ pieces from $1$ piece, we need exactly $X - 1$ operations. 

Since each stick is independent, the total number of breaks required for $N$ sticks is the sum of $(A_i - 1)$ for every stick where $A_i > 1$. Sticks of length 1 require 0 breaks.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the number of sticks. We iterate through the list of sticks exactly once.
- **Space Complexity**: $O(1)$, as we only use a single variable to maintain the running sum of breaks.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * A stick of length X can be broken into two positive integers Y and Z such that Y + Z = X.
 * This is one break.
 * Effectively, a stick of length X can be broken into X sticks of length 1.
 * To get from 1 stick of length X to X sticks of length 1, we need exactly (X - 1) breaks.
 * 
 * For N sticks with lengths A_1, A_2, ..., A_N, the total number of breaks is:
 * Sum of (A_i - 1) for all i where A_i > 1.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n;
        cin >> n;
        long long total_breaks = 0;
        for (int i = 0; i < n; ++i) {
            int a;
            cin >> a;
            // A stick of length 1 cannot be broken.
            // A stick of length A_i can be broken into A_i - 1 pieces.
            if (a > 1) {
                total_breaks += (a - 1);
            }
        }
        cout << total_breaks << "\n";
    }
    return 0;
}
```