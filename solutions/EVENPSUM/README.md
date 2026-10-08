# [Even Pair Sum (EVENPSUM)](https://www.codechef.com/problems/EVENPSUM)

- **Difficulty Rating**: 1200
- **Solved in**: 1 attempt(s)

## Problem Summary
Given two integers $A$ and $B$, we need to find the number of pairs $(X, Y)$ such that $1 \le X \le A$, $1 \le Y \le B$, and the sum $X + Y$ is even.

## Intuition & Mathematical Observation
For the sum of two integers $(X + Y)$ to be even, there are only two possible scenarios:
1. Both $X$ and $Y$ are **even** (Even + Even = Even).
2. Both $X$ and $Y$ are **odd** (Odd + Odd = Even).

To solve this, we calculate the count of odd and even numbers in the ranges $[1, A]$ and $[1, B]$:
- In any range $[1, N]$:
    - The number of odd integers is $\lceil N/2 \rceil$, which can be calculated as `(N + 1) / 2`.
    - The number of even integers is $\lfloor N/2 \rfloor$, which can be calculated as `N / 2`.

Let:
- `oddA`, `evenA` be the counts for range $[1, A]$.
- `oddB`, `evenB` be the counts for range $[1, B]$.

The total number of valid pairs is the sum of the combinations of both being odd and both being even:
$$\text{Total Pairs} = (\text{oddA} \times \text{oddB}) + (\text{evenA} \times \text{evenB})$$

Since $A$ and $B$ can be as large as $10^9$, the product can reach $10^{18}$, necessitating the use of the `long long` data type in C++.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the calculation involves basic arithmetic operations.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the counts.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given A and B. We need to find the number of pairs (X, Y) such that 
 * 1 <= X <= A, 1 <= Y <= B, and (X + Y) is even.
 * 
 * (X + Y) is even if:
 * 1. Both X and Y are even.
 * 2. Both X and Y are odd.
 * 
 * Let:
 * oddA = number of odd integers in [1, A] = (A + 1) / 2
 * evenA = number of even integers in [1, A] = A / 2
 * oddB = number of odd integers in [1, B] = (B + 1) / 2
 * evenB = number of even integers in [1, B] = B / 2
 * 
 * Total valid pairs = (oddA * oddB) + (evenA * evenB)
 * 
 * Constraints:
 * A, B <= 10^9. The result can be up to 10^18, so we must use long long.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long A, B;
        cin >> A >> B;

        long long oddA = (A + 1) / 2;
        long long evenA = A / 2;
        long long oddB = (B + 1) / 2;
        long long evenB = B / 2;

        // Calculate total pairs
        long long result = (oddA * oddB) + (evenA * evenB);

        cout << result << "\n";
    }

    return 0;
}
```