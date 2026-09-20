# [Valentine is Coming (VALENTINE)](https://www.codechef.com/problems/VALENTINE)

- **Difficulty Rating**: 691
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef has $X$ rupees and wants to buy chocolates, each costing $Y$ rupees. The goal is to determine the maximum number of chocolates Chef can purchase with the given budget.

## Intuition & Mathematical Observation
The problem asks for the maximum number of items that can be bought given a total budget and a fixed unit price. This is a classic application of **integer division**. 

If we have $X$ total money and each item costs $Y$, the number of items we can afford is the largest integer $n$ such that $n \times Y \le X$. In programming, this is directly calculated using the integer division operator (`/`), which automatically discards the remainder (effectively performing a floor operation).

- If $X < Y$, the result is $0$.
- If $X \ge Y$, the result is the quotient of $X$ divided by $Y$.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the division operation takes constant time. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef has X rupees and each chocolate costs Y rupees.
 * The maximum number of chocolates Chef can buy is the integer part of X / Y.
 * This is equivalent to floor division in integer arithmetic.
 * 
 * Constraints:
 * 1 <= T <= 1000
 * 1 <= X, Y <= 100
 * Since X and Y are small, standard integer types are sufficient.
 * Time complexity per test case: O(1)
 * Total time complexity: O(T)
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long x, y;
        cin >> x >> y;
        
        // The maximum number of chocolates is the quotient of X divided by Y.
        // If X < Y, the result is 0, which is handled correctly by integer division.
        long long max_chocolates = x / y;
        
        cout << max_chocolates << "\n";
    }
    
    return 0;
}
```