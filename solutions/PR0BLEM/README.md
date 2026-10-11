# [Problem (PR0BLEM)](https://www.codechef.com/problems/PR0BLEM)

- **Difficulty Rating**: 908
- **Solved in**: 1 attempt(s)

## Problem Summary
Alice starts with $N$ problems and Bob starts with $M$ problems. We are allowed two types of operations:
1. Alice solves a problem: Alice's count decreases by 1, Bob's count increases by 1.
2. Bob solves a problem: Bob's count decreases by 1, Alice's count increases by 3.

The goal is to determine if it is possible to reach a state where Alice and Bob have an equal number of problems ($N = M$).

## Intuition & Mathematical Observation
Let $D = N - M$ be the difference between the number of problems Alice and Bob have.

*   **Operation 1:** Alice solves a problem.
    *   New difference: $(N - 1) - (M + 1) = N - M - 2$.
    *   The difference $D$ changes by $-2$.
*   **Operation 2:** Bob solves a problem.
    *   New difference: $(N + 3) - (M - 1) = N - M + 4$.
    *   The difference $D$ changes by $+4$.

We want to reach a state where $D = 0$. Starting from an initial difference $D_0 = N - M$, we need to find non-negative integers $x$ (number of times Alice solves) and $y$ (number of times Bob solves) such that:
$$D_0 - 2x + 4y = 0$$
$$2x - 4y = D_0$$
$$2(x - 2y) = D_0$$

This equation shows that $D_0$ must be divisible by 2 for a solution to exist. In other words, $(N - M)$ must be an even number. Since $(N - M)$ is even if and only if $N$ and $M$ have the same parity (both even or both odd), the condition simplifies to checking if $(N - M) \pmod 2 == 0$.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we only perform a simple arithmetic check. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Let D = N - M.
 * Operation 1 changes D by -2.
 * Operation 2 changes D by +4.
 * To reach D = 0, the initial difference D must be a multiple of 2.
 * Thus, (N - M) % 2 == 0 is the necessary and sufficient condition.
 */

int main() {
    // Optimize I/O operations for faster execution
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long n, m;
        cin >> n >> m;
        
        // Check if the difference is even
        if ((n - m) % 2 == 0) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
    return 0;
}
```