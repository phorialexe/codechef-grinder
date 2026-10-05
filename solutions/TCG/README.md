# [Capital Gain Tax (TCG)](https://www.codechef.com/problems/TCG)

- **Difficulty Rating**: 311
- **Solved in**: 2 attempt(s)

## Problem Summary
The problem asks us to compare two integer values, $X$ and $Y$, representing the capital gain tax in two different years. We need to determine if the tax has increased, decreased, or remained the same by comparing $Y$ (the current year's tax) against $X$ (the previous year's tax).

## Intuition & Mathematical Observation
The logic follows a simple conditional comparison:
1. If the current tax $Y$ is strictly greater than the previous tax $X$ ($Y > X$), the tax has **INCREASED**.
2. If the current tax $Y$ is strictly less than the previous tax $X$ ($Y < X$), the tax has **DECREASED**.
3. If both values are equal ($Y = X$), the tax has remained the **SAME**.

This is a straightforward implementation of basic comparison operators in programming.

## Complexity Analysis
- **Time Complexity**: $O(1)$ — The solution performs a constant number of comparisons regardless of the input size.
- **Space Complexity**: $O(1)$ — We only use a fixed amount of memory to store the two integer variables.

## Solution Code

```cpp
#include <iostream>

using namespace std;

/**
 * Problem: Capital Gain Tax
 * Logic: 
 * - If Y > X, the tax has INCREASED.
 * - If Y < X, the tax has DECREASED.
 * - If Y == X, the tax is the SAME.
 * 
 * Complexity:
 * Time: O(1)
 * Space: O(1)
 */

int main() {
    // Optimize standard I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int X, Y;
    if (!(cin >> X >> Y)) return 0;

    if (Y > X) {
        cout << "INCREASED" << endl;
    } else if (Y < X) {
        cout << "DECREASED" << endl;
    } else {
        cout << "SAME" << endl;
    }

    return 0;
}
```