# [FIND A and B (FINDK3)](https://www.codechef.com/problems/FINDK3)

- **Difficulty Rating**: 802
- **Solved in**: 1 attempt(s)

## Problem Summary
Given three distinct positive integers $X, Y,$ and $Z$, we need to partition them into two sets: one containing a single integer $B$, and the other containing the remaining two integers. Let $A$ be the product of the two integers in the second set. We must determine if there exists a configuration such that $A$ is divisible by $B$ ($A \pmod B = 0$). If such a configuration exists, output $A$ and $B$; otherwise, output $-1$.

## Intuition & Mathematical Observation
Since there are only three integers, there are exactly three possible ways to assign $B$:
1. $B = X$, then $A = Y \times Z$. Check if $(Y \times Z) \pmod X == 0$.
2. $B = Y$, then $A = X \times Z$. Check if $(X \times Z) \pmod Y == 0$.
3. $B = Z$, then $A = X \times Y$. Check if $(X \times Y) \pmod Z == 0$.

Because the problem asks for *any* valid pair $(A, B)$, we can simply check these three scenarios sequentially. If any scenario satisfies the condition, we print the result and terminate the test case. If none of the three satisfy the condition, it is impossible to form such a pair, and we output $-1$.

**Note:** Since $X, Y, Z$ can be large, we use `long long` in C++ to prevent integer overflow when calculating the product $A$.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case. We perform a constant number of arithmetic operations and comparisons regardless of the input size.
- **Space Complexity**: $O(1)$. We only use a few variables to store the input integers.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given three distinct positive integers X, Y, Z.
 * We need to choose one as B, and the product of the other two as A.
 * Condition: A % B == 0.
 * 
 * Possible scenarios:
 * 1. B = X, A = Y * Z. Check if (Y * Z) % X == 0.
 * 2. B = Y, A = X * Z. Check if (X * Z) % Y == 0.
 * 3. B = Z, A = X * Y. Check if (X * Y) % Z == 0.
 * 
 * If any of these satisfy the condition, print A and B.
 * If none satisfy, print -1.
 */

void solve() {
    long long x, y, z;
    if (!(cin >> x >> y >> z)) return;

    // Case 1: B = X, A = Y * Z
    if ((y * z) % x == 0) {
        cout << (y * z) << " " << x << "\n";
        return;
    }
    
    // Case 2: B = Y, A = X * Z
    if ((x * z) % y == 0) {
        cout << (x * z) << " " << y << "\n";
        return;
    }
    
    // Case 3: B = Z, A = X * Y
    if ((x * y) % z == 0) {
        cout << (x * y) << " " << z << "\n";
        return;
    }

    // No solution found
    cout << -1 << "\n";
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