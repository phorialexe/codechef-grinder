# [Mixing Liquids (MIXINGLIQ)](https://www.codechef.com/problems/MIXINGLIQ)

- **Difficulty Rating**: 553
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef has $A$ units of syrup and $B$ units of water. He wants to prepare a juice mixture where the ratio of syrup to water is exactly $1:2$. We need to find the maximum total amount of juice Chef can prepare using the available ingredients.

## Intuition & Mathematical Observation
To maintain a ratio of $1:2$, for every $x$ units of syrup used, Chef must use $2x$ units of water. 

1. **Constraints**:
   - The amount of syrup used ($x$) cannot exceed the available syrup: $x \le A$.
   - The amount of water used ($2x$) cannot exceed the available water: $2x \le B$, which simplifies to $x \le \lfloor B/2 \rfloor$.

2. **Optimization**:
   - To maximize the total juice, we need to maximize $x$.
   - Combining the constraints, the maximum integer value for $x$ is $\min(A, \lfloor B/2 \rfloor)$.
   - The total quantity of the mixture is the sum of syrup and water: $x + 2x = 3x$.

By calculating $x = \min(A, B/2)$ using integer division, we can easily determine the total volume of the mixture.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution involves basic arithmetic operations. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the inputs and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef has A units of syrup and B units of water.
 * The ratio must be 1:2.
 * Let x be the amount of syrup used. Then 2x must be the amount of water used.
 * Constraints:
 * x <= A
 * 2x <= B
 * Therefore, x <= min(A, B/2).
 * Since x must be an integer, x = min(A, B/2).
 * The total quantity of juice is x + 2x = 3x.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long A, B;
        cin >> A >> B;

        // We need to find the maximum integer x such that:
        // x <= A
        // 2x <= B  => x <= B/2
        
        long long x = min(A, B / 2);
        
        // Total quantity is x (syrup) + 2x (water) = 3x
        long long total_juice = 3 * x;
        
        cout << total_juice << "\n";
    }

    return 0;
}
```