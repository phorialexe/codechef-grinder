# [The Ides of March (IDESM)](https://www.codechef.com/problems/IDESM)

- **Difficulty Rating**: 231
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to determine if a given integer $N$, representing a day in the month of March, corresponds to the "Ides of March." By definition, the Ides of March falls on the 15th day of the month. We need to output "Yes" if $N = 15$ and "No" otherwise.

## Intuition & Mathematical Observation
The problem is a straightforward conditional check. Since the input $N$ is constrained between 1 and 15, we simply need to compare the input value against the constant 15. 
- If $N = 15$, the condition is satisfied.
- For any other value $1 \le N < 15$, the condition is not satisfied.

This can be implemented using a simple `if-else` statement or a ternary operator.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we perform a single constant-time comparison.
- **Space Complexity**: $O(1)$, as we only use a single integer variable to store the input.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: The Ides of March
 * The problem asks us to determine if a given day N in March is the 15th.
 * Constraints: 1 <= N <= 15.
 * Time Complexity: O(1) per test case.
 * Space Complexity: O(1).
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    // Read the input integer N
    if (cin >> N) {
        // Check if N is exactly 15
        if (N == 15) {
            cout << "Yes" << "\n";
        } else {
            cout << "No" << "\n";
        }
    }

    return 0;
}
```