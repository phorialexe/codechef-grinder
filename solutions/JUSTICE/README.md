# [International Justice Day (JUSTICE)](https://www.codechef.com/problems/JUSTICE)

- **Difficulty Rating**: 264
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to determine if an accused person is convicted based on two given integers, $X$ and $Y$. Specifically, the accused is convicted if the evidence $X$ is greater than or equal to the threshold $Y$. We need to output "YES" if the condition $X \ge Y$ is met, and "NO" otherwise.

## Intuition & Mathematical Observation
The problem is a straightforward conditional check. We are given two integers:
1. $X$: The evidence level.
2. $Y$: The threshold required for conviction.

The logic follows directly from the problem statement:
- If $X \ge Y$, the condition for conviction is satisfied.
- If $X < Y$, the condition is not satisfied.

Since the constraints are small and the logic is a simple comparison, we can implement this using a basic `if-else` statement.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we only perform a single comparison and output operation.
- **Space Complexity**: $O(1)$, as we only use two variables to store the input.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: International Justice Day
 * Logic: The accused is convicted if X >= Y.
 * Time Complexity: O(1) per test case.
 * Space Complexity: O(1).
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long X, Y;
    // Read the input values X and Y
    if (cin >> X >> Y) {
        // Check if the evidence meets the threshold
        if (X >= Y) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }

    return 0;
}
```