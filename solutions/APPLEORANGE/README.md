# [Apples and oranges (APPLEORANGE)](https://www.codechef.com/problems/APPLEORANGE)

- **Difficulty Rating**: 1040
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given $N$ apples and $M$ oranges. We need to distribute these fruits among $K$ contestants such that every contestant receives an equal number of apples and an equal number of oranges, with no fruits left over. We need to find the maximum possible value of $K$.

## Intuition & Mathematical Observation
For $K$ contestants to receive an equal number of fruits with no remainder:
1. $N$ must be perfectly divisible by $K$ ($N \pmod K = 0$).
2. $M$ must be perfectly divisible by $K$ ($M \pmod K = 0$).

This implies that $K$ must be a **common divisor** of both $N$ and $M$. To find the *maximum* number of contestants, we need to find the **Greatest Common Divisor (GCD)** of $N$ and $M$.

The Euclidean algorithm is the most efficient way to compute the GCD of two numbers. It repeatedly replaces the larger number with the remainder of the division of the two numbers until the remainder becomes zero.

## Complexity Analysis
- **Time Complexity**: $O(\log(\min(N, M)))$ per test case. The Euclidean algorithm reduces the numbers logarithmically, which is extremely efficient even for inputs up to $10^9$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the inputs and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have N apples and M oranges. We need to distribute them equally among K contestants
 * such that no fruit is left over.
 * This means:
 * 1. N must be divisible by K (N % K == 0)
 * 2. M must be divisible by K (M % K == 0)
 * 
 * We want to find the maximum K that satisfies these conditions.
 * This is equivalent to finding the Greatest Common Divisor (GCD) of N and M.
 * 
 * Constraints:
 * N, M <= 10^9. The GCD of two numbers up to 10^9 fits in a standard 32-bit integer,
 * but using long long is safer and good practice in competitive programming.
 * Time complexity: O(log(min(N, M))) per test case, which is well within the 1s limit.
 */

long long gcd(long long a, long long b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long n, m;
        cin >> n >> m;
        
        // The maximum number of contestants is the GCD of N and M
        cout << gcd(n, m) << "\n";
    }

    return 0;
}
```