# [Reach fast (REACHFAST)](https://www.codechef.com/problems/REACHFAST)

- **Difficulty Rating**: 777
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef is located at position $A$ on a number line, and Chefina is at position $B$. Chef can move at most $K$ units in a single step in either direction. The goal is to find the minimum number of steps required for Chef to reach Chefina's position.

## Intuition & Mathematical Observation
To minimize the number of steps, Chef should always move the maximum possible distance ($K$ units) toward Chefina in every step. 

1.  **Calculate Distance**: The total distance Chef needs to cover is the absolute difference between their positions: $|A - B|$.
2.  **Calculate Steps**: If the distance is $D$, and Chef covers $K$ units per step, the number of steps required is $\lceil D / K \rceil$.
3.  **Integer Arithmetic**: In C++, integer division truncates towards zero. To perform a ceiling division $\lceil D / K \rceil$ using only integers, we can use the formula:
    $$\text{steps} = \frac{D + K - 1}{K}$$
    This formula effectively adds the remainder to ensure that any distance not perfectly divisible by $K$ results in an additional step.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the calculation involves basic arithmetic operations. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef is at A, Chefina is at B.
 * In one step, Chef can move at most K units.
 * The distance between them is |A - B|.
 * To minimize steps, Chef should always move K units towards B.
 * The number of steps required is ceil(|A - B| / K).
 * Using integer arithmetic, ceil(x / y) can be calculated as (x + y - 1) / y.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long a, b, k;
        cin >> a >> b >> k;

        // Calculate absolute distance
        long long dist = abs(a - b);

        // If distance is 0, 0 steps are needed
        if (dist == 0) {
            cout << 0 << "\n";
        } else {
            // Calculate ceil(dist / k)
            // Formula: (dist + k - 1) / k
            long long steps = (dist + k - 1) / k;
            cout << steps << "\n";
        }
    }

    return 0;
}
```