# [Chef and Profits (CHFPROFIT)](https://www.codechef.com/problems/CHFPROFIT)

- **Difficulty Rating**: 889
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef buys $X$ stocks at a purchase price of $Y$ each and sells all $X$ stocks at a selling price of $Z$ each. The goal is to calculate the total profit earned from these transactions.

## Intuition & Mathematical Observation
The profit is defined as the difference between the total revenue and the total cost.

1.  **Total Cost**: Chef buys $X$ stocks at price $Y$, so the cost is $X \times Y$.
2.  **Total Revenue**: Chef sells $X$ stocks at price $Z$, so the revenue is $X \times Z$.
3.  **Profit Calculation**: 
    $$\text{Profit} = \text{Revenue} - \text{Cost}$$
    $$\text{Profit} = (X \times Z) - (X \times Y)$$
    $$\text{Profit} = X \times (Z - Y)$$

By using the distributive property, we can simplify the calculation to $X \times (Z - Y)$, which reduces the number of operations and makes the code cleaner. Given the constraints ($X, Y, Z \le 10^4$), the result will not exceed $10^8$, which fits safely within a standard 32-bit integer, though `long long` is used to ensure robustness.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a constant number of arithmetic operations, resulting in $O(1)$ per test case.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef buys X stocks at price Y each. Total cost = X * Y.
 * Chef sells X stocks at price Z each. Total revenue = X * Z.
 * Profit = Total Revenue - Total Cost
 * Profit = (X * Z) - (X * Y)
 * Profit = X * (Z - Y)
 * 
 * Constraints:
 * T <= 100
 * X, Y, Z <= 10^4
 * The maximum possible profit is 10^4 * (10^4 - 1) which is approx 10^8.
 * This fits comfortably within a standard 32-bit signed integer, 
 * but using long long is good practice to prevent overflow in similar problems.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long x, y, z;
        cin >> x >> y >> z;
        
        // Calculate profit using the derived formula: X * (Z - Y)
        long long profit = x * (z - y);
        
        cout << profit << "\n";
    }
    
    return 0;
}
```