# [Existence (EXISTENCE)](https://www.codechef.com/problems/EXISTENCE)

- **Difficulty Rating**: 928
- **Solved in**: 1 attempt(s)

## Problem Summary
Given two integers $X$ and $Y$, determine if they satisfy the equation:
$$X^4 + 4Y^2 = 4X^2Y$$

## Intuition & Mathematical Observation
The given equation is $X^4 + 4Y^2 = 4X^2Y$. By rearranging the terms to one side, we get:
$$X^4 - 4X^2Y + 4Y^2 = 0$$

Notice that this expression follows the algebraic identity $(a - b)^2 = a^2 - 2ab + b^2$. 
If we let $a = X^2$ and $b = 2Y$, the equation becomes:
$$(X^2)^2 - 2(X^2)(2Y) + (2Y)^2 = 0$$
$$(X^2 - 2Y)^2 = 0$$

For the square of a real number to be zero, the base must be zero:
$$X^2 - 2Y = 0 \implies X^2 = 2Y$$

Thus, the problem reduces to checking if $X^2$ is exactly equal to $2Y$. Given the constraints $X \le 10^9$ and $Y \le 10^{18}$, $X^2$ will be at most $10^{18}$ and $2Y$ will be at most $2 \times 10^{18}$. Both values fit within a standard 64-bit integer (`long long` in C++), so we can perform the check directly without overflow issues.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we are only performing basic arithmetic operations and a comparison. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a constant amount of extra space for variables.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The equation is: X^4 + 4 * Y^2 = 4 * X^2 * Y
 * Rearranging the terms:
 * X^4 - 4 * X^2 * Y + 4 * Y^2 = 0
 * This is a perfect square trinomial of the form a^2 - 2ab + b^2 = 0,
 * where a = X^2 and b = 2Y.
 * (X^2)^2 - 2 * (X^2) * (2Y) + (2Y)^2 = 0
 * (X^2 - 2Y)^2 = 0
 * 
 * This implies X^2 - 2Y = 0, or X^2 = 2Y.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long x, y;
        cin >> x >> y;

        // Check if X^2 == 2 * Y
        // Using long long to prevent overflow as X^2 <= 10^18 and 2Y <= 2*10^18
        if (x * x == 2 * y) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }

    return 0;
}
```