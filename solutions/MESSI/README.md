# [Football Training (MESSI)](https://www.codechef.com/problems/MESSI)

- **Difficulty Rating**: 329
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to determine the type of football training session based on the number of fans for two players, Leo and Ronald. Given two integers $X$ (Leo's fans) and $Y$ (Ronald's fans), we must output:
- `"FREEKICK"` if $X > Y$.
- `"PENALTY"` if $Y > X$.
It is guaranteed that $X \neq Y$.

## Intuition & Mathematical Observation
The problem is a straightforward conditional comparison. Since we are guaranteed that $X$ and $Y$ are never equal, we only need to evaluate two mutually exclusive conditions:
1. If $X > Y$, the condition for "FREEKICK" is met.
2. Otherwise (which implies $Y > X$), the condition for "PENALTY" is met.

No complex algorithms or data structures are required; a simple `if-else` statement is sufficient to solve the problem.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we perform a single comparison operation.
- **Space Complexity**: $O(1)$, as we only use two integer variables to store the input.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given two integers X and Y representing the number of fans of Leo and Ronald.
 * We need to determine which session to hold based on which group is larger.
 * Since X != Y is guaranteed, we simply compare X and Y.
 * If X > Y, output "FREEKICK".
 * If Y > X, output "PENALTY".
 * 
 * Constraints: 0 <= X, Y <= 100.
 * Time Complexity: O(1) per test case.
 * Space Complexity: O(1).
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int X, Y;
    if (cin >> X >> Y) {
        if (X > Y) {
            cout << "FREEKICK" << "\n";
        } else {
            cout << "PENALTY" << "\n";
        }
    }

    return 0;
}
```