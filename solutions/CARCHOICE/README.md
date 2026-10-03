# [Car Choice (CARCHOICE)](https://www.codechef.com/problems/CARCHOICE)

- **Difficulty Rating**: 861
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given two cars. For the first car, it covers $x_1$ distance with $y_1$ fuel. For the second car, it covers $x_2$ distance with $y_2$ fuel. We need to determine which car is more fuel-efficient (i.e., consumes less fuel per unit of distance).
- Output `-1` if the first car is cheaper (more efficient).
- Output `0` if both cars are equally efficient.
- Output `1` if the second car is cheaper (more efficient).

## Intuition & Mathematical Observation
To find the fuel efficiency, we compare the cost per unit distance:
- Efficiency of Car 1: $\frac{y_1}{x_1}$
- Efficiency of Car 2: $\frac{y_2}{x_2}$

To avoid floating-point precision errors (which can occur when dividing integers), we use the **cross-multiplication method**. Instead of comparing $\frac{y_1}{x_1}$ and $\frac{y_2}{x_2}$, we compare the products:
- Compare $y_1 \times x_2$ with $y_2 \times x_1$.

**Logic:**
1. If $y_1 \times x_2 < y_2 \times x_1$, then $\frac{y_1}{x_1} < \frac{y_2}{x_2}$, meaning Car 1 is more efficient. Output `-1`.
2. If $y_1 \times x_2 = y_2 \times x_1$, then $\frac{y_1}{x_1} = \frac{y_2}{x_2}$, meaning they are equal. Output `0`.
3. If $y_1 \times x_2 > y_2 \times x_1$, then $\frac{y_1}{x_1} > \frac{y_2}{x_2}$, meaning Car 2 is more efficient. Output `1`.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we only perform basic arithmetic operations. For $T$ test cases, the complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input values.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Car 1 cost per km = y1 / x1
 * Car 2 cost per km = y2 / x2
 * 
 * We compare y1/x1 and y2/x2 using cross-multiplication:
 * y1 * x2 vs y2 * x1 to avoid floating point precision issues.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long x1, x2, y1, y2;
        cin >> x1 >> x2 >> y1 >> y2;

        // Compare y1/x1 and y2/x2 by comparing y1*x2 and y2*x1
        long long cost1 = y1 * x2;
        long long cost2 = y2 * x1;

        if (cost1 < cost2) {
            cout << -1 << "\n";
        } else if (cost1 == cost2) {
            cout << 0 << "\n";
        } else {
            cout << 1 << "\n";
        }
    }

    return 0;
}
```