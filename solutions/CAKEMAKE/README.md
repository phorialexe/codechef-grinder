# [Cake Making (CAKEMAKE)](https://www.codechef.com/problems/CAKEMAKE)

- **Difficulty Rating**: 279
- **Solved in**: 1 attempt(s)

## Problem Summary
We are tasked with finding the number of ways to choose two colors for a two-layered cake. The first layer can be any color from $1$ to $A$, and the second layer can be any color from $1$ to $B$. The constraint is that the two layers **cannot** have the same color. We need to calculate the total number of valid color combinations.

## Intuition & Mathematical Observation
1. **Total Combinations**: Without any constraints, the first layer has $A$ choices and the second layer has $B$ choices. By the fundamental counting principle, the total number of combinations is $A \times B$.
2. **Identifying Invalid Combinations**: A combination is invalid if both layers have the same color. The colors available for both layers are the integers from $1$ to $\min(A, B)$. Therefore, there are exactly $\min(A, B)$ pairs where both layers have the same color (e.g., $(1,1), (2,2), \dots, (\min(A,B), \min(A,B))$).
3. **Final Calculation**: To find the number of valid combinations, we subtract the number of invalid combinations from the total:
   $$\text{Result} = (A \times B) - \min(A, B)$$

## Complexity Analysis
- **Time Complexity**: $O(1)$, as the solution involves only basic arithmetic operations and a comparison, which execute in constant time.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have A choices for the first layer (1 to A) and B choices for the second layer (1 to B).
 * Total combinations without constraints = A * B.
 * Constraint: The two layers cannot have the same color.
 * The colors that are common to both sets are 1, 2, ..., min(A, B).
 * There are exactly min(A, B) such colors.
 * Therefore, we must subtract min(A, B) from the total combinations.
 * Result = (A * B) - min(A, B).
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long A, B;
    if (cin >> A >> B) {
        // Calculate the number of common colors
        long long common = min(A, B);
        
        // Subtract common colors from total combinations
        long long result = (A * B) - common;
        
        cout << result << "\n";
    }

    return 0;
}
```