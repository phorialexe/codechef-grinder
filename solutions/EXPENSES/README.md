# [Expense List (EXPENSES)](https://www.codechef.com/problems/EXPENSES)

- **Difficulty Rating**: 719
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef starts with an initial income of $2^X$. Over the course of $N$ days, Chef makes an expense each day. Every time Chef makes an expense, they spend exactly 50% of their current remaining money. The goal is to calculate the final amount remaining after $N$ such expenses.

## Intuition & Mathematical Observation
The problem states that Chef spends 50% of their current money each day. Mathematically, spending 50% is equivalent to dividing the current amount by 2.

1. **Initial Amount**: $2^X$
2. **After 1st expense**: $\frac{2^X}{2} = 2^{X-1}$
3. **After 2nd expense**: $\frac{2^{X-1}}{2} = 2^{X-2}$
4. **After $N$ expenses**: Following this pattern, after $N$ divisions by 2, the remaining amount will be:
   $$\frac{2^X}{2^N} = 2^{X-N}$$

Since the constraints are small ($X \le 20$), we can either simulate the process using a loop or calculate the result directly using bitwise shifts (`1 << (X - N)`). The provided solution uses a loop for clarity, which is well within the time limits.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case. Given $N \le 20$, this is effectively $O(1)$ per test case.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the income and the loop counter.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef starts with an income of 2^X.
 * For each expense i from 1 to N:
 * - He spends 50% of the current remaining amount.
 * - This is equivalent to dividing the current amount by 2.
 * 
 * After N expenses, the remaining amount will be:
 * (2^X) / (2^N) = 2^(X-N)
 * 
 * Constraints:
 * 1 <= N < X <= 20
 * Since X <= 20, 2^20 is approximately 10^6, which fits comfortably in a standard integer.
 * Using long long is safe practice.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n, x;
        cin >> n >> x;

        // Initial income is 2^X
        // Each expense halves the remaining amount.
        // After N expenses, the amount is 2^X / 2^N = 2^(X-N)
        
        long long income = 1LL << x;
        long long remaining = income;
        
        for (int i = 0; i < n; ++i) {
            remaining /= 2;
        }
        
        cout << remaining << "\n";
    }

    return 0;
}
```