# [Equalizing Numbers (EQLZING)](https://www.codechef.com/problems/EQLZING)

- **Difficulty Rating**: 823
- **Solved in**: 1 attempt(s)

## Problem Summary
Given two integers $A$ and $B$, we are allowed to perform an operation where we choose an integer $d$ and either:
1. Add $d$ to $A$ and subtract $d$ from $B$ ($A+d, B-d$).
2. Subtract $d$ from $A$ and add $d$ to $B$ ($A-d, B+d$).

The goal is to determine if it is possible to make $A$ equal to $B$ after performing the operation exactly once.

## Intuition & Mathematical Observation
Let the new values be $A'$ and $B'$. Regardless of the operation chosen, the sum of the two numbers remains invariant:
$$A' + B' = (A \pm d) + (B \mp d) = A + B$$

If we want to reach a state where $A' = B'$, we substitute this into the sum equation:
$$A' + A' = A + B$$
$$2A' = A + B$$
$$A' = \frac{A + B}{2}$$

For $A'$ to be an integer, the sum $(A + B)$ must be **even**. 
- If $(A + B)$ is even, we can set $d = \frac{|A - B|}{2}$. Applying this $d$ will result in both numbers becoming equal to the average of the original two numbers.
- If $(A + B)$ is odd, it is mathematically impossible to reach a state where $A' = B'$ because the average will result in a non-integer value (e.g., $X.5$).

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we only perform a simple parity check (modulo operation). For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and perform the calculation.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * In one operation, we choose an integer d and perform:
 * (A + d, B - d) OR (A - d, B + d).
 * 
 * The sum of A and B remains invariant under these operations.
 * If we want A' = B', then A' + B' = 2 * A'.
 * This implies that the sum (A + B) must be an even number for A' and B' to be equal.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long a, b;
        cin >> a >> b;

        // The sum must be even for the numbers to be equalized
        if ((a + b) % 2 == 0) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }

    return 0;
}
```