# [Butterfly (BFLY)](https://www.codechef.com/problems/BFLY)

- **Difficulty Rating**: 824
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given $R$ red, $G$ green, and $B$ blue butterflies, along with an equal number of flowers of the same colors. Each butterfly must feed on a flower of a color different from its own. We need to determine if it is possible to assign every butterfly to a unique flower such that no butterfly feeds on a flower of its own color.

## Intuition & Mathematical Observation
This problem can be modeled as a constraint satisfaction problem. For a valid assignment to exist, no single color group can be so large that it cannot be accommodated by the flowers of the remaining two colors.

If we have $R$ butterflies of color Red, they must be paired with flowers that are either Green or Blue. The total number of available flowers that are not Red is $G + B$. Therefore, for the Red butterflies to be satisfied, we must have:
$$R \le G + B$$

Applying the same logic to the Green and Blue butterflies, we derive the following three necessary and sufficient conditions:
1. $R \le G + B$
2. $G \le R + B$
3. $B \le R + G$

If all three conditions are satisfied, a valid matching is guaranteed to exist. If any one of these conditions is violated (e.g., $R > G + B$), there are more Red butterflies than there are non-Red flowers, making it impossible to satisfy the condition.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we are only performing a constant number of arithmetic comparisons. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the counts of the butterflies.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have R red, G green, and B blue butterflies and flowers.
 * Each butterfly must feed on a flower of a different color.
 * 
 * A butterfly of color X cannot feed on a flower of color X.
 * This is equivalent to saying that the number of butterflies of color X
 * must be less than or equal to the total number of flowers of other colors.
 * 
 * Conditions:
 * 1. R <= G + B
 * 2. G <= R + B
 * 3. B <= R + G
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long r, g, b;
        cin >> r >> g >> b;

        // Check the conditions:
        // No color can exceed the sum of the other two colors.
        if (r <= g + b && g <= r + b && b <= r + g) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }

    return 0;
}
```