# [Make Arithmetic Progression (AP)](https://www.codechef.com/problems/AP)

- **Difficulty Rating**: 682
- **Solved in**: 2 attempt(s)

## Problem Summary
Given three integers $X, Y,$ and $Z$, determine the minimum number of operations required to make them form an Arithmetic Progression (AP). In one operation, you can change any of the three numbers to any other integer.

## Intuition & Mathematical Observation
An arithmetic progression $(X, Y, Z)$ is defined by the property that the difference between consecutive terms is constant:
$$Y - X = Z - Y$$

By rearranging this equation, we get the condition for an AP:
$$2 \times Y = X + Z$$

*   **Case 1 (0 operations):** If the input already satisfies $2 \times Y = X + Z$, the numbers are already in an AP, so the answer is **0**.
*   **Case 2 (1 operation):** If the condition is not met, we can always change one of the numbers to satisfy the equation. For instance, we could change $X$ to $(2 \times Y - Z)$ or $Z$ to $(2 \times Y - X)$. Since we only need to change one number to fix the progression, the answer is **1**.

Because we can always satisfy the condition by modifying just one element, the answer is always either 0 or 1.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we only perform a constant number of arithmetic operations. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few integer variables to store the input.

## Solution Code

```cpp
#include <iostream>

using namespace std;

/**
 * Problem Analysis:
 * An arithmetic progression (X, Y, Z) satisfies Y - X = Z - Y, 
 * which simplifies to 2 * Y = X + Z.
 * 
 * If 2 * Y == X + Z, 0 operations are needed.
 * Otherwise, we can change any one of the three numbers to satisfy the condition.
 * For example, we can always change X to (2 * Y - Z) or Z to (2 * Y - X).
 * Thus, the answer is either 0 or 1.
 */

void solve() {
    int x, y, z;
    if (!(cin >> x >> y >> z)) return;
    
    // Check if the AP condition is already met
    if (2 * y == x + z) {
        cout << 0 << "\n";
    } else {
        // Otherwise, we only need 1 operation to fix it
        cout << 1 << "\n";
    }
}

int main() {
    // Optimize I/O operations for faster execution
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    
    return 0;
}
```