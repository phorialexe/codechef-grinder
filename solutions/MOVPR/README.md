# [Movie Snacks (MOVPR)](https://www.codechef.com/problems/MOVPR)

- **Difficulty Rating**: 263
- **Solved in**: 3 attempt(s)

## Problem Summary
Chef wants to buy exactly 2 popcorns and 3 drinks. We are given the prices for:
- One popcorn ($X$)
- One drink ($Y$)
- One combo pack containing 1 popcorn and 1 drink ($Z$)

The goal is to find the minimum cost to acquire at least 2 popcorns and 3 drinks.

## Intuition & Mathematical Observation
To satisfy the requirement of 2 popcorns and 3 drinks, we can mix and match individual items and combo packs. We evaluate all logical combinations:

1.  **Buy everything individually**: 
    Cost = $2X + 3Y$
2.  **Buy 1 combo, then 1 popcorn and 2 drinks**: 
    This uses the combo to cover 1 popcorn and 1 drink, leaving 1 popcorn and 2 drinks to be bought individually.
    Cost = $Z + X + 2Y$
3.  **Buy 2 combos, then 1 drink**: 
    This uses two combos to cover 2 popcorns and 2 drinks, leaving 1 drink to be bought individually.
    Cost = $2Z + Y$

*Note: We do not need to consider buying 3 combos, as that would result in 3 popcorns and 3 drinks. Since prices are positive, $2Z + Y$ will always be cheaper than $3Z$ (assuming $Y < Z$).*

The final answer is simply the minimum of these three calculated values.

## Complexity Analysis
- **Time Complexity**: $O(1)$, as the solution involves a constant number of arithmetic operations and comparisons regardless of the input size.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and intermediate costs.

## Solution Code

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/**
 * Problem Analysis:
 * Chef needs 2 popcorns and 3 drinks.
 * X = price of 1 popcorn, Y = price of 1 drink, Z = price of 1 combo (1 popcorn + 1 drink).
 * 
 * Possible strategies to get at least 2 popcorns and 3 drinks:
 * 1. Buy everything individually: 2*X + 3*Y
 * 2. Buy 1 combo, then 1 popcorn and 2 drinks: Z + X + 2*Y
 * 3. Buy 2 combos, then 1 drink: 2*Z + Y
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long X, Y, Z;
    if (!(cin >> X >> Y >> Z)) return 0;

    // Strategy 1: All individual
    long long option1 = 2 * X + 3 * Y;
    
    // Strategy 2: 1 combo + 1 popcorn + 2 drinks
    long long option2 = Z + X + 2 * Y;
    
    // Strategy 3: 2 combos + 1 drink
    long long option3 = 2 * Z + Y;

    // The minimum of these strategies is the answer
    long long ans = min({option1, option2, option3});
    
    cout << ans << endl;

    return 0;
}
```