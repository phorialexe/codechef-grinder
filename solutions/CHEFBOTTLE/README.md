# [Chef and Water Bottles (CHEFBOTTLE)](https://www.codechef.com/problems/CHEFBOTTLE)

- **Difficulty Rating**: 662
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef has $N$ empty bottles, each with a capacity of $X$ units. He has a total of $K$ units of water. The goal is to determine the maximum number of bottles Chef can fill completely using the available water.

## Intuition & Mathematical Observation
To solve this problem, we need to consider two limiting factors:
1. **The Water Constraint**: If we have $K$ units of water and each bottle requires $X$ units, the maximum number of bottles we can fill is $\lfloor K / X \rfloor$.
2. **The Bottle Constraint**: Chef only has $N$ bottles available. Even if there is enough water to fill more than $N$ bottles, he cannot exceed the physical limit of $N$.

By combining these two constraints, the answer is simply the minimum of the two values:
$$\text{Result} = \min(N, \lfloor K / X \rfloor)$$

If $X > K$, the division $K/X$ results in $0$, which correctly indicates that no bottles can be filled.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution involves a single division and a comparison. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef has N bottles, each with capacity X.
 * Total water available is K.
 * We want to find the maximum number of bottles that can be filled completely.
 * 
 * 1. The number of bottles that can be filled by the water available is floor(K / X).
 * 2. However, Chef only has N bottles available.
 * 3. Therefore, the number of bottles filled is min(N, floor(K / X)).
 */

int main() {
    // Optimize I/O operations for faster execution
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long n, x, k;
        cin >> n >> x >> k;

        // Calculate how many bottles can be filled with K water
        // Integer division automatically performs the floor operation
        long long bottles_by_water = k / x;

        // The answer is the smaller of the available bottles and the bottles filled by water
        long long ans = min(n, bottles_by_water);

        cout << ans << "\n";
    }

    return 0;
}
```