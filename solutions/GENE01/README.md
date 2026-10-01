# [Genes (GENE01)](https://www.codechef.com/problems/GENE01)

- **Difficulty Rating**: 826
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to determine the eye color of a child based on the eye colors of their two parents. The eye colors follow a specific dominance hierarchy:
1. **Brown (R)** is the most dominant.
2. **Blue (B)** is the second most dominant.
3. **Green (G)** is the least dominant.

The child's eye color is determined by the most dominant color present between the two parents.

## Intuition & Mathematical Observation
The problem defines a clear priority order: **R > B > G**. 

To find the resulting color, we can use a simple conditional logic approach:
- If at least one parent has the color **'R'**, the child will have **'R'** because it is the highest in the hierarchy.
- If no parent has **'R'**, but at least one parent has **'B'**, the child will have **'B'**.
- If neither parent has **'R'** or **'B'**, both parents must have **'G'**, resulting in the child having **'G'**.

This can be implemented efficiently using `if-else` statements.

## Complexity Analysis
- **Time Complexity**: $O(1)$, as the solution performs a constant number of comparisons regardless of the input.
- **Space Complexity**: $O(1)$, as we only store two characters in memory.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The problem states that brown (R) is the most common, blue (B) is next, 
 * and green (G) is the rarest.
 * The child's eye color is the most common of the two parents' eye colors.
 * 
 * Hierarchy: R > B > G
 * 
 * Logic:
 * If either parent is 'R', the child is 'R'.
 * Else if either parent is 'B', the child is 'B'.
 * Else (both are 'G'), the child is 'G'.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    char c1, c2;
    if (!(cin >> c1 >> c2)) return 0;

    // Determine the dominant color based on the hierarchy R > B > G
    if (c1 == 'R' || c2 == 'R') {
        cout << "R" << "\n";
    } else if (c1 == 'B' || c2 == 'B') {
        cout << "B" << "\n";
    } else {
        // Both must be 'G'
        cout << "G" << "\n";
    }

    return 0;
}
```