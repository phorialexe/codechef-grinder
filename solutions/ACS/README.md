# [Count the ACs (ACS)](https://www.codechef.com/problems/ACS)

- **Difficulty Rating**: 739
- **Solved in**: 1 attempt(s)

## Problem Summary
In a contest, there are 10 problems in total. Each problem can be worth either 1 point or 100 points. Given a total score $P$, determine the minimum number of problems required to achieve that score. If it is impossible to achieve the score $P$ using at most 10 problems, output -1.

## Intuition & Mathematical Observation
Let $x$ be the number of problems worth 100 points and $y$ be the number of problems worth 1 point. We are given two constraints:
1. The total number of problems cannot exceed 10: $x + y \le 10$.
2. The total score must equal $P$: $100x + y = P$.

From the second equation, we can express $y$ as:
$y = P - 100x$

Since $x$ represents the number of 100-point problems, it must be between 0 and 10. We can iterate through all possible values of $x$ (from 0 to 10) and calculate the corresponding $y$. For a value of $x$ to be valid:
- $y$ must be non-negative ($y \ge 0$).
- The total number of problems ($x + y$) must be less than or equal to 10.

If these conditions are met, the total number of problems is $x + y$. Since we want to minimize the total number of problems, we check the constraints for each $x$ and return the result.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case. Since we always iterate a fixed number of times (from 0 to 10), the loop runs in constant time regardless of the input value $P$.
- **Space Complexity**: $O(1)$, as we only use a few integer variables to store the state.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * There are 10 problems total.
 * Each problem is worth either 1 or 100 points.
 * Let x be the number of problems worth 100 points.
 * Let y be the number of problems worth 1 point.
 * Total problems: x + y <= 10
 * Total score: 100*x + 1*y = P
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int p;
        cin >> p;

        bool found = false;
        int total_problems = -1;

        // x is the number of 100-point problems
        // y is the number of 1-point problems
        // Iterate through possible counts of 100-point problems
        for (int x = 0; x <= 10; ++x) {
            int y = p - (100 * x);
            // Check if y is valid and total problems <= 10
            if (y >= 0 && (x + y <= 10)) {
                found = true;
                total_problems = x + y;
                break;
            }
        }

        if (found) {
            cout << total_problems << "\n";
        } else {
            cout << -1 << "\n";
        }
    }

    return 0;
}
```