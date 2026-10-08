# [ICE CREAM (ICE_CREAM)](https://www.codechef.com/problems/ICE_CREAM)

- **Difficulty Rating**: 354
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef wants to purchase two ice creams. Each ice cream costs $X$ dollars. Chef currently has $Y$ dollars in their pocket. We need to determine if Chef has enough money to buy both ice creams. Specifically, we must output "YES" if $Y \ge 2X$, and "NO" otherwise.

## Intuition & Mathematical Observation
The problem is a straightforward comparison task. 
1. The total cost required to buy two ice creams is $2 \times X$.
2. Chef has $Y$ dollars available.
3. The condition for a successful purchase is that the available money $Y$ must be greater than or equal to the total cost $2X$.
4. Mathematically, the condition is: $Y \ge 2X$.

Given the constraints $1 \le X, Y \le 100$, the values fit well within standard integer types, and no complex algorithms are required.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution involves a single arithmetic operation and a comparison.
- **Space Complexity**: $O(1)$, as we only use a constant amount of extra space to store the variables $X$ and $Y$.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef wants to buy 2 ice creams, each costing X.
 * Total cost = 2 * X.
 * Chef has Y dollars.
 * Condition: Chef can buy if Y >= 2 * X.
 * 
 * Constraints: 1 <= X, Y <= 100.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long X, Y;
    // Read the cost of one ice cream (X) and the money Chef has (Y)
    if (cin >> X >> Y) {
        // Check if Chef has enough money for two ice creams
        if (Y >= 2 * X) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }

    return 0;
}
```