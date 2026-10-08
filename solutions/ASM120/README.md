# [Sub or Swp (ASM120)](https://www.codechef.com/problems/ASM120)

- **Difficulty Rating**: 1021
- **Solved in**: 1 attempt(s)

## Problem Summary
Given two integers $X$ and $Y$, we perform a series of operations until one of the numbers becomes 0. The operations are:
1. If $X > Y$, swap $X$ and $Y$.
2. If $X \le Y$, replace $X$ with $Y - X$ and $Y$ with the original $X$.

The goal is to determine the value of the non-zero integer once the process terminates.

## Intuition & Mathematical Observation
The operations described are a variation of the **Euclidean Algorithm** for finding the Greatest Common Divisor (GCD) of two numbers.

*   The Euclidean algorithm states that $\text{gcd}(X, Y) = \text{gcd}(X, Y - X)$.
*   In the problem, if $X \le Y$, we transform $(X, Y)$ into $(Y - X, X)$. This is exactly one step of the subtraction-based Euclidean algorithm.
*   If $X > Y$, we swap them, which is a standard step to ensure the larger number is subtracted by the smaller one.
*   The process terminates when one of the numbers becomes 0. According to the properties of the Euclidean algorithm, the remaining non-zero number is the $\text{gcd}$ of the initial $X$ and $Y$.

Therefore, the problem simply asks us to compute $\text{gcd}(X, Y)$.

## Complexity Analysis
- **Time Complexity**: $O(\log(\min(X, Y)))$ per test case. This is the standard complexity of the Euclidean algorithm, which is highly efficient even for large inputs.
- **Space Complexity**: $O(1)$, as we only store a few variables regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The operation described is a variation of the Euclidean algorithm.
 * The process terminates when one value becomes 0, leaving the GCD 
 * of the original numbers as the other value.
 */

void solve() {
    long long X, Y;
    if (!(cin >> X >> Y)) return;
    
    // The problem describes the Euclidean algorithm.
    // The final non-zero value is gcd(X, Y).
    cout << std::gcd(X, Y) << "\n";
}

int main() {
    // Fast I/O for performance
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