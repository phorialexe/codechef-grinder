# [Election Hopes (ELHP)](https://www.codechef.com/problems/ELHP)

- **Difficulty Rating**: 245
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef is participating in an election. He wins if the number of votes he receives ($X$) is at least twice the number of votes his opponent receives ($Y$). Given $X$ and $Y$, determine if Chef wins the election.

## Intuition & Mathematical Observation
The problem states that Chef dominates the election if his vote count $X$ is greater than or equal to double the opponent's vote count $Y$. 

Mathematically, this can be expressed as the condition:
$$X \ge 2 \times Y$$

If this condition evaluates to true, we output "Yes"; otherwise, we output "No". Since the constraints are small ($1 \le X, Y \le 100$), a simple `if-else` statement is sufficient to solve the problem.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we are performing a single comparison and multiplication.
- **Space Complexity**: $O(1)$, as we only use a constant amount of extra space to store the variables $X$ and $Y$.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Election Hopes
 * Logic: Chef dominates if X >= 2 * Y.
 * Constraints: 1 <= X, Y <= 100.
 * Time Complexity: O(1) per test case.
 * Space Complexity: O(1).
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long X, Y;
    // Read input X and Y
    if (cin >> X >> Y) {
        // Check the condition: X must be at least twice Y
        if (X >= 2 * Y) {
            cout << "Yes" << "\n";
        } else {
            cout << "No" << "\n";
        }
    }

    return 0;
}
```