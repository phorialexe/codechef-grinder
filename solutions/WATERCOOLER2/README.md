# [The Cooler Dilemma 2 (WATERCOOLER2)](https://www.codechef.com/problems/WATERCOOLER2)

- **Difficulty Rating**: 798
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given the monthly rent $X$ of a water cooler and the total cost $Y$ to purchase it. We need to find the maximum number of months $M$ we can rent the cooler such that the total rental cost ($M \times X$) is strictly less than the purchase cost ($Y$). If even renting for one month is not cheaper than buying, the answer is 0.

## Intuition & Mathematical Observation
The problem asks for the largest integer $M$ that satisfies the inequality:
$$M \times X < Y$$

By rearranging the inequality, we get:
$$M < \frac{Y}{X}$$

Since $M$ must be an integer:
1. **If $Y$ is divisible by $X$**: The value of $\frac{Y}{X}$ is an integer. To satisfy the "strictly less than" condition, $M$ must be at most $\frac{Y}{X} - 1$.
2. **If $Y$ is not divisible by $X$**: The value of $\frac{Y}{X}$ is a decimal. The largest integer $M$ satisfying the condition is simply the floor of the division, which is `Y / X` in integer arithmetic.
3. **Edge Case**: If $Y \le X$, it is impossible to rent for even one month for a price strictly less than $Y$. In this case, the answer is 0.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we only perform basic arithmetic operations. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to find the maximum integer M such that:
 * M * X < Y
 * 
 * Rearranging the inequality:
 * M < Y / X
 * 
 * Since M must be an integer, the maximum value is:
 * If Y is divisible by X, M = (Y / X) - 1
 * If Y is not divisible by X, M = floor(Y / X)
 * 
 * Edge case: If Y <= X, the cost of renting for 1 month is already >= Y,
 * so the answer is 0.
 * 
 * Constraints: X, Y up to 10^9. Calculations fit in long long.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long x, y;
        cin >> x >> y;

        if (y <= x) {
            cout << 0 << "\n";
        } else {
            if (y % x == 0) {
                cout << (y / x) - 1 << "\n";
            } else {
                cout << (y / x) << "\n";
            }
        }
    }

    return 0;
}
```