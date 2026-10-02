# [All Zero (ALLZR)](https://www.codechef.com/problems/ALLZR)

- **Difficulty Rating**: 626
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given three integers $A, B,$ and $C$. We can perform two types of operations:
1. **Type 1**: Decrease $A$ by 1 and $B$ by 2.
2. **Type 2**: Decrease $B$ by 1 and $C$ by 3.

The goal is to determine if it is possible to make $A, B,$ and $C$ all equal to $0$ using these operations.

## Intuition & Mathematical Observation
Let $x$ be the number of Type 1 operations and $y$ be the number of Type 2 operations performed. After performing these operations, the final values are:
- $A_{final} = A - x$
- $B_{final} = B - 2x - y$
- $C_{final} = C - 3y$

To reach the state where $A_{final} = B_{final} = C_{final} = 0$, we must satisfy the following system of equations:
1. $A - x = 0 \implies x = A$
2. $C - 3y = 0 \implies y = C / 3$
3. $B - 2x - y = 0 \implies B = 2x + y$

By substituting $x = A$ and $y = C/3$ into the third equation, we derive the necessary conditions for a solution to exist:
- **Condition 1**: $C$ must be divisible by $3$ (since $y$ must be an integer).
- **Condition 2**: $B$ must be exactly equal to $2A + (C/3)$.
- **Condition 3**: Since operations cannot be negative, $A$ and $C$ must be non-negative (given by problem constraints).

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution involves simple arithmetic operations and conditional checks.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and results.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * After x operations of Type 1 and y operations of Type 2:
 * A_final = A - x
 * B_final = B - 2x - y
 * C_final = C - 3y
 * 
 * Setting these to 0 gives:
 * x = A
 * y = C / 3
 * B = 2A + C/3
 */

void solve() {
    long long A, B, C;
    if (!(cin >> A >> B >> C)) return;

    // Check if C is divisible by 3
    if (C % 3 != 0) {
        cout << "No" << "\n";
        return;
    }

    // Calculate required operations
    long long x = A;
    long long y = C / 3;

    // Check if B matches the requirement B = 2x + y
    if (B == 2 * x + y) {
        cout << "Yes" << "\n";
    } else {
        cout << "No" << "\n";
    }
}

int main() {
    // Fast I/O
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