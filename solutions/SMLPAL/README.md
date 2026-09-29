# [Small Palindrome (SMLPAL)](https://www.codechef.com/problems/SMLPAL)

- **Difficulty Rating**: 706
- **Solved in**: 1 attempt(s)

## Problem Summary
Given $X$ ones and $Y$ twos (where both $X$ and $Y$ are even), construct the smallest possible palindrome using all these digits. A palindrome reads the same forwards and backwards. To minimize the number, we must prioritize placing the smallest digits (1s) at the most significant positions (the beginning of the number).

## Intuition & Mathematical Observation
To make a number as small as possible, we follow these rules:
1. **Prioritize Small Digits**: Since $1 < 2$, we want the leading digits to be 1s.
2. **Palindrome Constraint**: A palindrome is symmetric. If we place a digit at index $i$ from the left, we must place the same digit at index $i$ from the right.
3. **Optimal Arrangement**: 
   - Place half of the available 1s at the very beginning.
   - Place all available 2s in the center of the number. This ensures the 2s are as far from the most significant positions as possible.
   - Place the remaining half of the 1s at the very end to complete the palindrome.

**Example:** If $X=4$ and $Y=2$:
- Half of $X$ is 2.
- Start: `11`
- Middle: `22`
- End: `11`
- Result: `112211`

## Complexity Analysis
- **Time Complexity**: $O(X + Y)$ per test case. We iterate through the counts of 1s and 2s exactly once to print the digits.
- **Space Complexity**: $O(1)$, as we are printing the digits directly to the output stream without storing them in an auxiliary data structure.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given X ones and Y twos, both X and Y are even.
 * We need to form the smallest possible palindrome using all these digits.
 * 
 * Strategy:
 * - Place half of the available 1s at the start.
 * - Place all available 2s in the middle.
 * - Place the remaining half of the 1s at the end.
 */

void solve() {
    int X, Y;
    cin >> X >> Y;

    // Number of 1s to place on each side
    int half_X = X / 2;
    
    // Print the first half of 1s
    for (int i = 0; i < half_X; ++i) {
        cout << 1;
    }
    
    // Print all 2s in the middle
    for (int i = 0; i < Y; ++i) {
        cout << 2;
    }
    
    // Print the second half of 1s
    for (int i = 0; i < half_X; ++i) {
        cout << 1;
    }
    
    cout << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
```