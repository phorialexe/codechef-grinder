# [Airlines (SPCP2)](https://www.codechef.com/problems/SPCP2)

- **Difficulty Rating**: 712
- **Solved in**: 1 attempt(s)

## Problem Summary
An airline company needs to transport $N$ passengers. Each plane has a capacity of 100 passengers. The company already owns $X$ planes. We need to calculate the minimum number of additional planes the company must purchase to accommodate all $N$ passengers.

## Intuition & Mathematical Observation
1. **Capacity Calculation**: Since each plane holds 100 passengers, the total number of planes required to carry $N$ passengers is $\lceil N / 100 \rceil$.
2. **Integer Arithmetic**: In C++, integer division truncates towards zero. To perform a ceiling division for positive integers $N$ and $D$, we can use the formula: `(N + D - 1) / D`. Thus, the total planes required is `(N + 99) / 100`.
3. **Additional Planes**: If the company already has $X$ planes, the number of new planes needed is the total required minus $X$. If this value is negative (meaning the company already has more than enough planes), the answer is 0. This can be expressed as `max(0LL, total_planes_needed - X)`.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. Each test case involves basic arithmetic operations which run in $O(1)$ time.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Each plane carries 100 passengers.
 * Total passengers = N.
 * Total planes required = ceil(N / 100.0).
 * Using integer arithmetic, ceil(N / 100) is equivalent to (N + 99) / 100.
 * Let R be the required planes. R = (N + 99) / 100.
 * If the airline already has X planes, the number of new planes needed is:
 * max(0, R - X).
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long x, n;
        cin >> x >> n;

        // Calculate total planes needed using integer ceiling division
        long long total_planes_needed = (n + 99) / 100;

        // Calculate additional planes to purchase
        long long to_purchase = total_planes_needed - x;

        // If to_purchase is negative, it means we have enough planes, so output 0
        if (to_purchase < 0) {
            cout << 0 << "\n";
        } else {
            cout << to_purchase << "\n";
        }
    }

    return 0;
}
```