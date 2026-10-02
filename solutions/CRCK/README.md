# [Christmas Cake (CRCK)](https://www.codechef.com/problems/CRCK)

- **Difficulty Rating**: 217
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef bakes a cake every day starting from the $X$-th of December up to and including the 24th of December. Given the integer $X$ ($1 \le X \le 24$), calculate the total number of days Chef bakes a cake.

## Intuition & Mathematical Observation
To find the number of days in an inclusive range $[X, 24]$, we can use the standard formula for the count of integers in a range:
$$\text{Count} = (\text{End} - \text{Start}) + 1$$

Substituting the given values:
$$\text{Count} = (24 - X) + 1$$

For example:
- If $X = 18$: $(24 - 18) + 1 = 6 + 1 = 7$ days.
- If $X = 24$: $(24 - 24) + 1 = 0 + 1 = 1$ day.
- If $X = 1$: $(24 - 1) + 1 = 23 + 1 = 24$ days.

The logic is straightforward and requires no loops or complex data structures.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution involves a single arithmetic operation.
- **Space Complexity**: $O(1)$, as we only store a single integer variable.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef bakes a cake every day from date X to 24 (inclusive).
 * The number of days from X to 24 inclusive is (24 - X + 1).
 * 
 * Constraints:
 * 1 <= X <= 24
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int x;
    // Read the input integer X
    if (cin >> x) {
        // Calculate the number of days inclusive
        int result = 24 - x + 1;
        cout << result << "\n";
    }

    return 0;
}
```