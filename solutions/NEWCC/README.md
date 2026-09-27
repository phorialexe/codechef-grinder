# [All New CodeChef (NEWCC)](https://www.codechef.com/problems/NEWCC)

- **Difficulty Rating**: 354
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to compare the performance of two systems based on their runtime. We are given two integers, $X$ and $Y$, representing the runtime on the old system and the new system, respectively. We need to determine which system is faster:
- If $X < Y$, the old system is faster.
- If $Y < X$, the new system is faster.
- If $X = Y$, both systems have the same performance.

## Intuition & Mathematical Observation
The problem is a straightforward comparison task. Since a smaller runtime indicates a faster system, we simply need to use conditional statements (`if-else`) to compare the two input integers:
1. Compare $X$ and $Y$.
2. If $X$ is strictly less than $Y$, output "Old".
3. If $Y$ is strictly less than $X$, output "New".
4. If they are equal, output "Same".

The constraints ($1 \le X, Y \le 3000$) are small enough that any standard integer comparison will work perfectly without overflow issues.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we perform a constant number of comparisons.
- **Space Complexity**: $O(1)$, as we only use a fixed amount of memory to store the two input variables.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given two integers X and Y representing the runtime on the old and new systems respectively.
 * A smaller runtime indicates a faster system.
 * - If X < Y, the old system is faster (Old).
 * - If Y < X, the new system is faster (New).
 * - If X == Y, they are equally fast (Same).
 * 
 * Constraints: 1 <= X, Y <= 3000.
 * Time Complexity: O(1) per test case.
 * Space Complexity: O(1).
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int X, Y;
    // Read the input values X and Y
    if (cin >> X >> Y) {
        if (X < Y) {
            cout << "Old" << "\n";
        } else if (Y < X) {
            cout << "New" << "\n";
        } else {
            cout << "Same" << "\n";
        }
    }

    return 0;
}
```