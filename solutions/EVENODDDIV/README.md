# [Even vs Odd Divisors (EVENODDDIV)](https://www.codechef.com/problems/EVENODDDIV)

- **Difficulty Rating**: 642
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an integer $N$, we need to compare the number of even divisors $f(N)$ and the number of odd divisors $g(N)$. 
- If $f(N) > g(N)$, output `1`.
- If $f(N) = g(N)$, output `0`.
- If $f(N) < g(N)$, output `-1`.

## Intuition & Mathematical Observation
Any integer $N$ can be expressed in the form $N = 2^k \times m$, where $m$ is an odd integer.
- The odd divisors of $N$ are exactly the divisors of $m$. Let the number of divisors of $m$ be $d(m)$. Thus, $g(N) = d(m)$.
- The even divisors of $N$ are formed by multiplying any divisor of $m$ by $2^1, 2^2, \dots, 2^k$. There are $k$ such choices for the power of 2. Thus, $f(N) = k \times d(m)$.

Comparing $f(N)$ and $g(N)$:
1. **If $k = 0$** ($N$ is odd): $f(N) = 0$ and $g(N) = d(m) \ge 1$. Since $0 < d(m)$, the result is **-1**.
2. **If $k = 1$** ($N$ is divisible by 2 but not 4): $f(N) = 1 \times d(m) = d(m)$. Since $f(N) = g(N)$, the result is **0**.
3. **If $k \ge 2$** ($N$ is divisible by 4): $f(N) = k \times d(m)$. Since $k \ge 2$, $f(N) > g(N)$, the result is **1**.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we only perform simple modulo operations. Total time complexity is $O(T)$, where $T$ is the number of test cases.
- **Space Complexity**: $O(1)$, as we only use a few variables for input and calculation.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Let N = 2^k * m, where m is the product of odd prime factors of N.
 * The divisors of N are of the form 2^a * d, where 0 <= a <= k and d is a divisor of m.
 * - An odd divisor occurs when a = 0. The number of odd divisors g(N) is the number of divisors of m.
 * - An even divisor occurs when 1 <= a <= k. The number of even divisors f(N) is k * (number of divisors of m).
 * 
 * Therefore:
 * f(N) = k * g(N)
 * 
 * Comparing f(N) and g(N):
 * - If k = 0 (N is odd), f(N) = 0, g(N) > 0. So f(N) < g(N) -> Output -1.
 * - If k = 1 (N is 2 * odd), f(N) = 1 * g(N) = g(N). So f(N) = g(N) -> Output 0.
 * - If k > 1 (N is divisible by 4), f(N) = k * g(N) > g(N). So f(N) > g(N) -> Output 1.
 */

void solve() {
    int N;
    cin >> N;

    if (N % 2 != 0) {
        // N is odd, k = 0
        cout << -1 << "\n";
    } else if (N % 4 != 0) {
        // N is even but not divisible by 4, k = 1
        cout << 0 << "\n";
    } else {
        // N is divisible by 4, k >= 2
        cout << 1 << "\n";
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