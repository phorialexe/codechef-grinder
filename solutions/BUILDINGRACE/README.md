# [Building Race (BUILDINGRACE)](https://www.codechef.com/problems/BUILDINGRACE)

- **Difficulty Rating**: 739
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef is at floor $A$ and moves with a speed of $X$ floors per minute. Chefina is at floor $B$ and moves with a speed of $Y$ floors per minute. We need to determine who reaches the ground floor (floor 0) first. If they reach at the same time, we output "Both".

## Intuition & Mathematical Observation
The time taken to reach the ground floor is calculated as $\text{Time} = \frac{\text{Distance}}{\text{Speed}}$.
*   Chef's time: $T_1 = \frac{A}{X}$
*   Chefina's time: $T_2 = \frac{B}{Y}$

To compare these two fractions without dealing with floating-point precision issues (which can lead to errors), we use the cross-multiplication method:
*   Compare $\frac{A}{X}$ and $\frac{B}{Y}$ by comparing $A \times Y$ and $B \times X$.
    *   If $A \times Y < B \times X$, then $T_1 < T_2$ (Chef is faster).
    *   If $A \times Y > B \times X$, then $T_1 > T_2$ (Chefina is faster).
    *   If $A \times Y = B \times X$, then $T_1 = T_2$ (Both reach at the same time).

Given the constraints ($A, B \le 100$ and $X, Y \le 10$), the maximum product is $1000$, which easily fits within a standard 32-bit integer.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we only perform basic arithmetic comparisons. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input values.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef is at floor A with speed X. Time taken = A / X.
 * Chefina is at floor B with speed Y. Time taken = B / Y.
 * We need to compare A/X and B/Y.
 * To avoid floating point precision issues, we can compare A/X and B/Y 
 * by cross-multiplying: A * Y vs B * X.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int a, b, x, y;
        cin >> a >> b >> x >> y;

        // Using cross-multiplication to compare fractions A/X and B/Y
        // Chef's time: a/x
        // Chefina's time: b/y
        // Compare (a * y) and (b * x)
        
        int chef_time_scaled = a * y;
        int chefina_time_scaled = b * x;

        if (chef_time_scaled < chefina_time_scaled) {
            cout << "Chef" << "\n";
        } else if (chefina_time_scaled < chef_time_scaled) {
            cout << "Chefina" << "\n";
        } else {
            cout << "Both" << "\n";
        }
    }

    return 0;
}
```