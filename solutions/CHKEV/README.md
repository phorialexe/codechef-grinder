# [Check Even (CHKEV)](https://www.codechef.com/problems/CHKEV)

- **Difficulty Rating**: 275
- **Solved in**: 1 attempt(s)

## Problem Summary
Given a range $[L, R]$, determine if there exists at least one even integer within this range (inclusive).

## Intuition & Mathematical Observation
The problem can be broken down into two simple cases:

1.  **Case $L < R$**: If the range contains at least two integers, it is guaranteed to contain an even number. In any two consecutive integers, one must be even and one must be odd. Therefore, if the range length is at least 2, the answer is always "Yes".
2.  **Case $L = R$**: If the range contains only one integer, we simply check if that specific integer is divisible by 2. If $L \pmod 2 == 0$, the answer is "Yes"; otherwise, it is "No".

This logic covers all possible inputs within the given constraints.

## Complexity Analysis
- **Time Complexity**: $O(1)$, as the solution performs a constant number of arithmetic and conditional operations regardless of the input size.
- **Space Complexity**: $O(1)$, as no additional data structures are used.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given a range [L, R]. We need to determine if there exists at least one even integer in this range.
 * 
 * Logic:
 * - If L == R, the range contains only one number. If that number is even, output Yes, else No.
 * - If L < R, the range contains at least two numbers. Any two consecutive integers 
 *   must contain at least one even number (since one is odd and the other is even).
 *   Therefore, if L < R, the answer is always Yes.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long L, R;
    if (!(cin >> L >> R)) return 0;

    // If the range contains more than one number, it must contain an even number.
    // If the range contains only one number, check if it is even.
    if (L < R) {
        cout << "Yes" << "\n";
    } else {
        // L == R, check if the single number is even
        if (L % 2 == 0) {
            cout << "Yes" << "\n";
        } else {
            cout << "No" << "\n";
        }
    }

    return 0;
}
```