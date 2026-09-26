# [Janmansh and Coins (JCOINS)](https://www.codechef.com/problems/JCOINS)

- **Difficulty Rating**: 527
- **Solved in**: 1 attempt(s)

## Problem Summary
Janmansh has $X$ coins of value 10 and $Y$ coins of value 5. We need to calculate the total amount of money Janmansh has by summing the value of all his coins.

## Intuition & Mathematical Observation
The problem is a straightforward arithmetic calculation. Since each coin of type $X$ is worth 10 and each coin of type $Y$ is worth 5, the total value can be expressed by the linear equation:
$$\text{Total} = (X \times 10) + (Y \times 5)$$

Given the constraints ($X, Y \le 100$), the maximum possible value is $1000 + 500 = 1500$, which easily fits within a standard integer data type.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a constant number of arithmetic operations, resulting in $O(1)$ per test case.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Janmansh and Coins
 * Logic: Total money = (X * 10) + (Y * 5)
 * Constraints: X, Y <= 100. The result will be at most 1500, 
 * which fits comfortably in a standard integer.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long x, y;
        if (cin >> x >> y) {
            // Calculate total money
            long long total = (x * 10) + (y * 5);
            cout << total << "\n";
        }
    }

    return 0;
}
```