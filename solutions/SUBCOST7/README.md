# [Subscription Cost (SUBCOST7)](https://www.codechef.com/problems/SUBCOST7)

- **Difficulty Rating**: 459
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef needs to subscribe to a service for $N$ months. The pricing structure is tiered:
- For the first 3 months, the cost is $X$ per month.
- For every month after the 3rd month, the cost is $Y$ per month.

Given $N$, $X$, and $Y$, calculate the total cost Chef incurs for the entire duration of $N$ months.

## Intuition & Mathematical Observation
The problem can be solved using a simple conditional check based on the value of $N$:

1. **Case 1 ($N \le 3$):** Chef only pays the initial rate $X$ for all $N$ months.
   - Total Cost = $N \times X$
2. **Case 2 ($N > 3$):** Chef pays the initial rate $X$ for the first 3 months, and the remaining $(N - 3)$ months are charged at rate $Y$.
   - Total Cost = $(3 \times X) + ((N - 3) \times Y)$

Since the constraints are small ($N \le 50$, $X, Y \le 500$), the result will easily fit within a standard 32-bit integer, though `long long` is used for robustness.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. Each test case is solved in $O(1)$ constant time.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the inputs and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef subscribes for N months.
 * For the first 3 months, the cost is X per month.
 * For any month beyond the 3rd month, the cost is Y per month.
 * 
 * Logic:
 * If N <= 3:
 *    Total cost = N * X
 * If N > 3:
 *    Total cost = (3 * X) + ((N - 3) * Y)
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long n, x, y;
        cin >> n >> x >> y;

        long long total_cost = 0;
        if (n <= 3) {
            total_cost = n * x;
        } else {
            total_cost = (3 * x) + ((n - 3) * y);
        }

        cout << total_cost << "\n";
    }

    return 0;
}
```