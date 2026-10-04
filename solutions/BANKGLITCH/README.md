# [Bank Glitch (BANKGLITCH)](https://www.codechef.com/problems/BANKGLITCH)

- **Difficulty Rating**: 649
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef possesses $A$ units of currency 1 and $B$ units of currency 2. He has the option to trade $X$ units of currency 1 to receive $Y$ units of currency 2. Given that $X < Y$, each trade results in a net gain of $(Y - X)$ units of total currency. The goal is to maximize the total amount of money Chef has after performing as many trades as possible.

## Intuition & Mathematical Observation
Since each trade consumes $X$ units of currency 1 and adds $Y$ units of currency 2, the limiting factor is the initial amount of currency 1 ($A$). 

1. **Maximum Trades**: The maximum number of times Chef can perform the trade is $k = \lfloor A / X \rfloor$.
2. **Final Amounts**:
   - Remaining currency 1: $A_{final} = A - (k \times X)$
   - Total currency 2: $B_{final} = B + (k \times Y)$
3. **Total Money**: The total amount of money is simply the sum of the remaining currency 1 and the new total of currency 2:
   $$\text{Total} = A_{final} + B_{final}$$
   Substituting the expressions:
   $$\text{Total} = (A - kX) + (B + kY) = A + B + k(Y - X)$$

Because the constraints are small and the logic relies on basic arithmetic, this approach runs in constant time per test case.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution involves only basic arithmetic operations.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef has A units of currency 1 and B units of currency 2.
 * He can trade X units of currency 1 for Y units of currency 2.
 * Since X < Y, every trade increases the total amount of money (A + B) by (Y - X).
 * To maximize the total money, Chef should perform the trade as many times as possible.
 * The number of times he can perform the trade is limited by the amount of currency 1 he has (A).
 * Specifically, he can perform the trade floor(A / X) times.
 */

void solve() {
    long long A, B, X, Y;
    if (!(cin >> A >> B >> X >> Y)) return;

    // Calculate the maximum number of trades possible
    long long k = A / X;

    // Calculate the final amounts
    long long final_A = A - (k * X);
    long long final_B = B + (k * Y);

    // The total amount of money
    long long total = final_A + final_B;

    cout << total << "\n";
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