# [Calorie Intake (CALINTAKE)](https://www.codechef.com/problems/CALINTAKE)

- **Difficulty Rating**: 247
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef has a daily calorie limit of $X$. He has already consumed $Y$ meals, each containing $Z$ calories. We need to calculate the remaining calorie allowance for the day. If the total calories consumed ($Y \times Z$) exceed the limit $X$, we must output $-1$.

## Intuition & Mathematical Observation
The problem is a straightforward arithmetic calculation:
1. Calculate the total calories consumed: $TotalConsumed = Y \times Z$.
2. Compare $TotalConsumed$ with the limit $X$.
3. If $TotalConsumed > X$, Chef has exceeded his limit, so output $-1$.
4. Otherwise, the remaining allowance is $X - TotalConsumed$.

Given the constraints ($1 \le X, Y, Z \le 100$), the values are small enough that they will not overflow a standard 32-bit integer, though `long long` is used for good practice.

## Complexity Analysis
- **Time Complexity**: $O(1)$ — The solution performs a constant number of arithmetic operations regardless of the input size.
- **Space Complexity**: $O(1)$ — Only a few variables are used to store the input and the result, requiring constant extra space.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Calorie Intake
 * Chef's limit: X
 * Already consumed: Y * Z
 * Remaining: X - (Y * Z)
 * If (Y * Z) > X, output -1.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Reading input: X (limit), Y (meals), Z (calories per meal)
    long long X, Y, Z;
    if (!(cin >> X >> Y >> Z)) return 0;

    // Calculate total consumed calories
    long long consumed = Y * Z;

    // Check if limit is exceeded
    if (consumed > X) {
        cout << -1 << "\n";
    } else {
        cout << (X - consumed) << "\n";
    }

    return 0;
}
```