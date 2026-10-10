# [Yearly Phone (PHONEYR)](https://www.codechef.com/problems/PHONEYR)

- **Difficulty Rating**: 541
- **Solved in**: 1 attempt(s)

## Problem Summary
Given a year $X$ (where $1973 \le X \le 2024$), the task is to generate a specific code. The code must start with the character 'K', followed by the last two digits of the year $X$. If the last two digits form a number less than 10 (e.g., 2005), a leading zero must be included (e.g., "K05").

## Intuition & Mathematical Observation
The core of the problem is extracting the last two digits of an integer. This is easily achieved using the modulo operator: `X % 100`. 

Since the problem requires a two-digit format (padding with a leading zero if the result is between 0 and 9), we have two primary ways to handle this:
1. **Conditional Logic**: Check if the result of `X % 100` is less than 10. If it is, print '0' before printing the number.
2. **Formatted Output**: Use `printf` with the format specifier `%02d`, which automatically handles the leading zero for integers less than 10.

Given the constraints $1973 \le X \le 2024$, the modulo operation will always yield a valid two-digit representation of the year.

## Complexity Analysis
- **Time Complexity**: $O(1)$, as the solution involves a single arithmetic operation and a constant-time output operation.
- **Space Complexity**: $O(1)$, as we only store a single integer variable.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Yearly Phone
 * The task is to take a year X and output 'K' followed by the last two digits of X.
 * Since 1973 <= X <= 2024, the last two digits can be extracted using the modulo operator (X % 100).
 * We must ensure that if the last two digits are less than 10 (e.g., 2005 -> 05), 
 * we print the leading zero.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int X;
    if (!(cin >> X)) return 0;

    // Extract the last two digits
    int lastTwo = X % 100;

    // Print 'K' followed by the two digits, ensuring leading zero if necessary
    cout << "K";
    if (lastTwo < 10) {
        cout << "0" << lastTwo << "\n";
    } else {
        cout << lastTwo << "\n";
    }

    return 0;
}
```