# [Bus Seat Numbering (SEATNUMBER)](https://www.codechef.com/problems/SEATNUMBER)

- **Difficulty Rating**: 613
- **Solved in**: 1 attempt(s)

## Problem Summary
The task is to categorize a given bus seat number ($N$) into one of four categories based on its deck and type:
1. **Lower Double**: Seats 1–10
2. **Lower Single**: Seats 11–15
3. **Upper Double**: Seats 16–25
4. **Upper Single**: Seats 26–30

## Intuition & Mathematical Observation
The problem can be solved by using simple conditional logic (if-else statements) to check the range of the input integer $N$:

*   **Deck Determination**: 
    *   If $1 \le N \le 15$, the seat is on the **Lower Deck**.
    *   If $16 \le N \le 30$, the seat is on the **Upper Deck**.
*   **Type Determination**:
    *   Within the Lower Deck ($1-15$), seats $1-10$ are "Double" and $11-15$ are "Single".
    *   Within the Upper Deck ($16-30$), seats $16-25$ are "Double" and $26-30$ are "Single".

By nesting these conditions, we can accurately classify any seat number provided in the input.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution performs a constant number of comparisons regardless of the input value.
- **Space Complexity**: $O(1)$, as no additional data structures are used that scale with input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Lower Deck: 1 to 15
 * Upper Deck: 16 to 30
 * 
 * Lower Deck (1-15):
 * Single: 11, 12, 13, 14, 15
 * Double: 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
 * 
 * Upper Deck (16-30):
 * Single: 26, 27, 28, 29, 30
 * Double: 16, 17, 18, 19, 20, 21, 22, 23, 24, 25
 */

void solve() {
    int n;
    cin >> n;

    if (n >= 1 && n <= 15) {
        // Lower Deck
        if (n >= 1 && n <= 10) {
            cout << "Lower Double" << "\n";
        } else {
            cout << "Lower Single" << "\n";
        }
    } else {
        // Upper Deck
        if (n >= 16 && n <= 25) {
            cout << "Upper Double" << "\n";
        } else {
            cout << "Upper Single" << "\n";
        }
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}
```