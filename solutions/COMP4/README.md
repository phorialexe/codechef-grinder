# [Competition of 4 (COMP4)](https://www.codechef.com/problems/COMP4)

- **Difficulty Rating**: 247
- **Solved in**: 1 attempt(s)

## Problem Summary
In a competition involving 4 participants, the prize money awarded to a participant depends on their rank $X$ (where $1 \le X \le 4$). The prize money is calculated using the formula:
$$\text{Prize} = 1000 \times 2^{4-X}$$
Given the rank $X$, we need to output the corresponding prize money.

## Intuition & Mathematical Observation
The problem provides a direct mathematical formula. By substituting the possible values of $X$ into the formula, we can observe the prize distribution:

*   **Rank 1**: $1000 \times 2^{4-1} = 1000 \times 2^3 = 1000 \times 8 = 8000$
*   **Rank 2**: $1000 \times 2^{4-2} = 1000 \times 2^2 = 1000 \times 4 = 4000$
*   **Rank 3**: $1000 \times 2^{4-3} = 1000 \times 2^1 = 1000 \times 2 = 2000$
*   **Rank 4**: $1000 \times 2^{4-4} = 1000 \times 2^0 = 1000 \times 1 = 1000$

We can implement this efficiently using the bitwise left-shift operator (`1 << (4 - X)`), which is equivalent to $2^{4-X}$ for non-negative integers.

## Complexity Analysis
- **Time Complexity**: $O(1)$, as the solution involves a simple arithmetic calculation regardless of the input value.
- **Space Complexity**: $O(1)$, as we only use a single integer variable to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Competition of 4
 * The prize money is given by the formula: 1000 * 2^(4 - X)
 * Given constraints: 1 <= X <= 4
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int X;
    // Read the rank X from standard input
    if (cin >> X) {
        // Calculate prize using bitwise shift for 2^(4-X)
        // 1LL ensures the calculation is performed using long long precision
        long long prize = 1000LL * (1LL << (4 - X));
        cout << prize << "\n";
    }

    return 0;
}
```