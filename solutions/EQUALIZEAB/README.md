# [Equalize AB (EQUALIZEAB)](https://www.codechef.com/problems/EQUALIZEAB)

- **Difficulty Rating**: 1069
- **Solved in**: 1 attempt(s)

## Problem Summary
Given two integers $A$ and $B$, and an integer $X$, we can perform an operation any number of times:
1. Choose $A$ and $B$, and replace them with $(A+X, B-X)$ or $(A-X, B+X)$.
Determine if it is possible to make $A$ equal to $B$ after performing the operation some number of times.

## Intuition & Mathematical Observation
Let the initial values be $A$ and $B$. After $k$ operations (where $k$ can be positive, negative, or zero), the new values $A'$ and $B'$ will be:
- $A' = A + k \cdot X$
- $B' = B - k \cdot X$

We want to reach a state where $A' = B'$. Setting these equal:
$$A + k \cdot X = B - k \cdot X$$
$$2 \cdot k \cdot X = B - A$$
$$k = \frac{B - A}{2 \cdot X}$$

For $A$ and $B$ to be equal, $k$ must be an integer. This implies that the difference $(B - A)$ must be perfectly divisible by $2 \cdot X$. 

**Key takeaway:** The difference between $A$ and $B$ changes by exactly $2X$ in every operation. Therefore, the initial difference $(B - A)$ must be a multiple of $2X$ for the values to eventually meet at the same point.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we only perform a single modulo operation. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We start with A and B. In one operation, we change (A, B) to (A+X, B-X) or (A-X, B+X).
 * Let the number of times we add X to A be 'k'.
 * After k operations, the new values are:
 * A' = A + k*X
 * B' = B - k*X
 * We want A' = B', so:
 * A + k*X = B - k*X
 * 2 * k * X = B - A
 * k = (B - A) / (2 * X)
 * 
 * For A and B to be equal, (B - A) must be divisible by (2 * X).
 */

void solve() {
    long long A, B, X;
    cin >> A >> B >> X;

    // The difference between A and B changes by 2*X in each operation.
    // We need the initial difference (B - A) to be divisible by (2 * X).
    
    long long diff = B - A;
    if (diff % (2 * X) == 0) {
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