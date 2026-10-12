# [Buy Lamps (BUYLAMP)](https://www.codechef.com/problems/BUYLAMP)

- **Difficulty Rating**: 775
- **Solved in**: 1 attempt(s)

## Problem Summary
We need to purchase a total of $N$ lamps. Among these $N$ lamps, at least $K$ must be red. Red lamps cost $X$ each, and blue lamps cost $Y$ each. The goal is to calculate the minimum total cost required to satisfy these conditions.

## Intuition & Mathematical Observation
To minimize the total cost, we break the problem into two parts:

1.  **Mandatory Requirement**: We are required to buy at least $K$ red lamps. Since we want to minimize costs, we should buy exactly $K$ red lamps to satisfy the constraint. This contributes $K \times X$ to the total cost.
2.  **Remaining Lamps**: After buying the $K$ red lamps, we still need to purchase $N - K$ additional lamps to reach the total count of $N$. For these remaining slots, we are free to choose either red or blue lamps. To minimize the cost, for each of these $N - K$ slots, we should choose the cheaper option between red ($X$) and blue ($Y$). 

Mathematically, the total cost is:
$$\text{Total Cost} = (K \times X) + ((N - K) \times \min(X, Y))$$

Since $N$ can be up to $10^8$, the total cost can reach $10^9$. While this fits in a standard 32-bit `int`, using `long long` is a best practice in competitive programming to prevent potential overflow issues.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the calculation involves only basic arithmetic operations. For $T$ test cases, the complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to buy exactly N lamps.
 * At least K must be red.
 * Red lamp cost = X, Blue lamp cost = Y.
 * 
 * Logic:
 * 1. Buy exactly K red lamps: Cost = K * X.
 * 2. For the remaining (N - K) lamps, pick the cheaper option: min(X, Y).
 * 
 * Total Cost = (K * X) + ((N - K) * min(X, Y))
 */

int main() {
    // Fast I/O for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long n, k, x, y;
        cin >> n >> k >> x >> y;

        // Cost of the mandatory K red lamps
        long long cost = k * x;

        // Cost of the remaining (n - k) lamps
        // We choose the cheaper lamp for the remaining slots
        long long remaining_lamps = n - k;
        cost += remaining_lamps * min(x, y);

        cout << cost << "\n";
    }

    return 0;
}
```