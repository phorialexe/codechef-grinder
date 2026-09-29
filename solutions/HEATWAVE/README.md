# [Heat Wave (HEATWAVE)](https://www.codechef.com/problems/HEATWAVE)

- **Difficulty Rating**: 284
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to determine if a new record high temperature has been set. We are given two integers: $X$, representing the previous record high temperature, and $Y$, representing the current day's temperature. We need to output "YES" if the current temperature $Y$ is strictly greater than the previous record $X$, and "NO" otherwise.

## Intuition & Mathematical Observation
The condition for a new record is straightforward:
- If $Y > X$, the current temperature exceeds the previous record, so a new record is set.
- If $Y \le X$, the current temperature is either equal to or lower than the previous record, so no new record is set.

This is a simple conditional check that requires no complex data structures or algorithms.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we only perform a single comparison operation.
- **Space Complexity**: $O(1)$, as we only use two integer variables to store the input.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given the previous record high temperature X and the current day's temperature Y.
 * A new record high is created if and only if the current temperature Y is strictly 
 * greater than the previous record X.
 * 
 * Constraints: 100 <= X, Y <= 150.
 * Time Complexity: O(1) per test case.
 * Space Complexity: O(1).
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int X, Y;
    // Reading X (previous record) and Y (current temperature)
    if (cin >> X >> Y) {
        // Check if Y is strictly greater than X
        if (Y > X) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }

    return 0;
}
```