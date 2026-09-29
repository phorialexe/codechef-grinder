# [RCB vs CSK (RCBCSK)](https://www.codechef.com/problems/RCBCSK)

- **Difficulty Rating**: 282
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to determine which team qualifies for the playoffs based on their scores. Given two integers $X$ (RCB's score) and $Y$ (CSK's score), RCB qualifies if their score difference ($X - Y$) is at least 18. Otherwise, CSK qualifies. We need to output "RCB" if the condition is met, and "CSK" otherwise.

## Intuition & Mathematical Observation
The problem provides a direct conditional rule:
1. Calculate the difference: $D = X - Y$.
2. Check if $D \ge 18$.
3. If true, RCB qualifies.
4. If false, CSK qualifies.

Since the constraints are small ($150 \le X \le 250$ and $150 \le Y \le X + 6$), there is no risk of integer overflow, and a simple `if-else` statement is sufficient to solve the problem.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we only perform a single subtraction and a comparison.
- **Space Complexity**: $O(1)$, as we only use a constant amount of extra space for variables.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * RCB qualifies if (X - Y) >= 18.
 * Otherwise, CSK qualifies.
 * Constraints: 150 <= X <= 250, 150 <= Y <= X + 6.
 * Time Complexity: O(1) per test case.
 * Space Complexity: O(1).
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int X, Y;
    // Read the scores X and Y
    if (cin >> X >> Y) {
        // Check the qualification condition
        if (X - Y >= 18) {
            cout << "RCB" << "\n";
        } else {
            cout << "CSK" << "\n";
        }
    }

    return 0;
}
```