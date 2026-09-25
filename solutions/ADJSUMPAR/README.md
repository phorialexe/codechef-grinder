# [Adjacent Sum Parity (ADJSUMPAR)](https://www.codechef.com/problems/ADJSUMPAR)

- **Difficulty Rating**: 1013
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an array $B$ of length $N$, we need to determine if there exists a binary array $A$ (where each element is 0 or 1) such that:
- $B_i = (A_i + A_{i+1}) \pmod 2$ for $1 \le i < N$
- $B_N = (A_N + A_1) \pmod 2$

In simpler terms, each element of $B$ represents the parity of the sum of two adjacent elements in $A$ (with the last and first elements considered adjacent).

## Intuition & Mathematical Observation
Let's analyze the sum of all elements in array $B$:
$$\sum_{i=1}^{N} B_i = (A_1 + A_2) + (A_2 + A_3) + \dots + (A_{N-1} + A_N) + (A_N + A_1) \pmod 2$$

By grouping the terms, we observe that each $A_i$ appears exactly twice in the summation:
$$\sum_{i=1}^{N} B_i = 2 \times (A_1 + A_2 + \dots + A_N) \pmod 2$$

Since $2 \times (\text{any integer})$ is always even, the sum of all elements in $B$ must be even (i.e., $0 \pmod 2$). 
- If the sum of elements in $B$ is **odd**, it is mathematically impossible to satisfy the condition, so the answer is `NO`.
- If the sum of elements in $B$ is **even**, we can always construct such an array $A$ by fixing $A_1$ and determining the subsequent elements based on the values in $B$. Thus, the condition is both necessary and sufficient.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, as we iterate through the array $B$ exactly once to calculate the sum.
- **Space Complexity**: $O(1)$, as we only store the running sum of the elements rather than storing the entire array.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The sum of all elements in B is equal to 2 * (sum of elements in A) mod 2.
 * Since 2 * X is always even, the sum of elements in B must be even.
 */

void solve() {
    int N;
    cin >> N;
    int sum_b = 0;
    for (int i = 0; i < N; ++i) {
        int b;
        cin >> b;
        sum_b += b;
    }

    // If the total sum of B is even, it's possible to construct A.
    if (sum_b % 2 == 0) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
}

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
```