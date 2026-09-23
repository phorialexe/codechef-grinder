# [Minimum Wage (MINWAGE)](https://www.codechef.com/problems/MINWAGE)

- **Difficulty Rating**: 247
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to determine if a given wage $X$ is strictly greater than the government-mandated minimum wage of 11. If the wage $X$ is greater than 11, we output "YES"; otherwise, we output "NO".

## Intuition & Mathematical Observation
The logic is straightforward:
1. We are given an integer $X$ representing the current wage.
2. The condition for a "YES" is $X > 11$.
3. If $X \le 11$, the condition is not met, so we output "NO".
4. Since the constraints are small ($1 \le X \le 20$), a simple conditional `if-else` statement is sufficient to solve the problem.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we are performing a single comparison operation.
- **Space Complexity**: $O(1)$, as we only use a single integer variable to store the input.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: MINWAGE
 * The minimum wage is 11. We need to check if X > 11.
 * Constraints: 1 <= X <= 20.
 * Time Complexity: O(1) per test case.
 * Space Complexity: O(1).
 */

int main() {
    // Optimize I/O operations for faster execution
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int X;
    // Read the input wage X
    if (cin >> X) {
        // Check if the wage is strictly greater than 11
        if (X > 11) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }

    return 0;
}
```