# [Glass Prices (GLPR)](https://www.codechef.com/problems/GLPR)

- **Difficulty Rating**: 219
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef is deciding between two types of frames for a glass:
1. **Metal Frame**: Costs $Y$.
2. **Plastic Frame**: Costs $2 \times X$.

Chef chooses the **Metal Frame** if its cost is less than or equal to the cost of the Plastic Frame ($Y \le 2 \times X$). Otherwise, Chef chooses the **Plastic Frame**. Given $X$ and $Y$, determine which frame Chef buys.

## Intuition & Mathematical Observation
The problem provides a direct conditional rule:
*   If $Y \le 2 \times X$, output `METAL`.
*   Otherwise, output `PLASTIC`.

Since the constraints are small ($1 \le X, Y \le 2000$), the calculation $2 \times X$ will not exceed the capacity of a standard 32-bit integer. However, using `long long` is a good habit in competitive programming to prevent overflow in similar problems with larger constraints.

## Complexity Analysis
- **Time Complexity**: $O(1)$ — The solution performs a single comparison and arithmetic operation, which takes constant time regardless of the input size.
- **Space Complexity**: $O(1)$ — We only store two integer variables, requiring constant auxiliary space.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef buys the metal frame if Y <= 2 * X.
 * Otherwise, Chef buys the plastic frame.
 * 
 * Constraints:
 * 1 <= X, Y <= 2000
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long X, Y;
    if (cin >> X >> Y) {
        // Condition: Metal if Y <= 2 * X
        if (Y <= 2 * X) {
            cout << "METAL" << "\n";
        } else {
            cout << "PLASTIC" << "\n";
        }
    }

    return 0;
}
```