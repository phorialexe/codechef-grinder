# [Chef Drinks Tea (TEA)](https://www.codechef.com/problems/TEA)

- **Difficulty Rating**: 591
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef needs to consume at least $X$ liters of tea. He can only buy tea in refills of $Y$ liters, where each refill costs $Z$ rupees. The goal is to calculate the minimum total cost required to obtain at least $X$ liters of tea.

## Intuition & Mathematical Observation
To find the minimum cost, we first need to determine the minimum number of refills required. 

1. **Calculating Refills**: 
   - If $X$ is perfectly divisible by $Y$, the number of refills needed is exactly $X / Y$.
   - If $X$ is not divisible by $Y$, Chef needs an additional refill to cover the remainder, resulting in $\lfloor X / Y \rfloor + 1$ refills.
   - This logic is equivalent to the ceiling division formula: $\lceil X / Y \rceil$. In integer arithmetic, this is efficiently calculated as `(X + Y - 1) / Y`.

2. **Calculating Cost**:
   - Once the number of refills is determined, the total cost is simply the number of refills multiplied by the cost per refill ($Z$).

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution involves only basic arithmetic operations. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef needs X liters of tea.
 * Each refill provides Y liters and costs Z rupees.
 * If X is divisible by Y, he needs exactly (X / Y) refills.
 * If X is not divisible by Y, he needs (X / Y) + 1 refills to cover the remaining amount.
 * This can be calculated using integer division: ceil(X / Y) = (X + Y - 1) / Y.
 * Total cost = (number of refills) * Z.
 * 
 * Constraints: X, Y, Z <= 100. The result will fit in a standard integer, 
 * but using long long is safe practice.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long x, y, z;
        cin >> x >> y >> z;

        // Calculate number of refills needed
        // Using integer arithmetic: (x + y - 1) / y performs ceiling division
        long long refills = (x + y - 1) / y;
        
        // Calculate total cost
        long long total_cost = refills * z;

        cout << total_cost << "\n";
    }

    return 0;
}
```