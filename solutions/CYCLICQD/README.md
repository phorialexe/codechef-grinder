# [Cyclic Quadrilateral (CYCLICQD)](https://www.codechef.com/problems/CYCLICQD)

- **Difficulty Rating**: 735
- **Solved in**: 1 attempt(s)

## Problem Summary
Given the four interior angles of a quadrilateral ($A, B, C, D$) in cyclic order, determine whether the quadrilateral is a **cyclic quadrilateral**. A quadrilateral is cyclic if and only if the sum of its opposite angles is exactly $180^\circ$.

## Intuition & Mathematical Observation
A fundamental property of a cyclic quadrilateral is that its opposite angles are supplementary (i.e., they sum to $180^\circ$). For a quadrilateral with angles $A, B, C, D$ in order:
1. The opposite pairs are $(A, C)$ and $(B, D)$.
2. The condition for being cyclic is $A + C = 180^\circ$ **and** $B + D = 180^\circ$.

**Optimization:**
Since the sum of all interior angles in any quadrilateral is always $360^\circ$ ($A + B + C + D = 360^\circ$), if we verify that $A + C = 180^\circ$, it mathematically follows that $B + D$ must also be $180^\circ$ ($360^\circ - 180^\circ = 180^\circ$). Therefore, checking $A + C = 180$ is sufficient to solve the problem.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. Each test case performs a constant number of arithmetic operations.
- **Space Complexity**: $O(1)$, as we only use a few integer variables to store the angles.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * A quadrilateral is cyclic if and only if the sum of its opposite angles is 180 degrees.
 * Given angles A, B, C, D in order along the perimeter, the opposite pairs are:
 * (A, C) and (B, D).
 * Therefore, the quadrilateral is cyclic if A + C == 180 AND B + D == 180.
 * Since the sum of all angles in a quadrilateral is 360 (A + B + C + D = 360),
 * if A + C == 180, then B + D must be 360 - (A + C) = 360 - 180 = 180.
 * Thus, we only need to check if A + C == 180.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        // Check if the sum of opposite angles is 180
        if (a + c == 180) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }

    return 0;
}
```