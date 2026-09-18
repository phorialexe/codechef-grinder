# [Monopoly in Chefland (MONOPOLY)](https://www.codechef.com/problems/MONOPOLY)

- **Difficulty Rating**: 482
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef is analyzing three companies with annual revenues $R_1, R_2,$ and $R_3$. A company is considered to have a "monopolistic advantage" if its revenue is **strictly greater** than the sum of the revenues of the other two companies. Given the revenues of the three companies, determine if any of them holds a monopolistic advantage.

## Intuition & Mathematical Observation
To determine if a monopoly exists, we must check three distinct conditions based on the problem statement:
1. Company 1 is a monopoly if: $R_1 > R_2 + R_3$
2. Company 2 is a monopoly if: $R_2 > R_1 + R_3$
3. Company 3 is a monopoly if: $R_3 > R_1 + R_2$

If any one of these conditions evaluates to `true`, the answer is "YES". If none of them are met, the answer is "NO". Since the constraints on $R$ are very small ($1 \le R \le 10$), standard integer arithmetic is perfectly safe and efficient.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we are performing a constant number of arithmetic and comparison operations. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input values regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have three companies with revenues R1, R2, and R3.
 * A company has a monopolistic advantage if its revenue is strictly greater 
 * than the sum of the other two.
 * 
 * Conditions:
 * 1. R1 > (R2 + R3)
 * 2. R2 > (R1 + R3)
 * 3. R3 > (R1 + R2)
 * 
 * If any of these conditions are true, output "YES", otherwise "NO".
 */

void solve() {
    long long r1, r2, r3;
    if (!(cin >> r1 >> r2 >> r3)) return;

    // Check if any company's revenue is greater than the sum of the other two
    if ((r1 > (r2 + r3)) || (r2 > (r1 + r3)) || (r3 > (r1 + r2))) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
}

int main() {
    // Fast I/O setup for performance
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