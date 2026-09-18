# [Profit Increment (PROINC)](https://www.codechef.com/problems/PROINC)

- **Difficulty Rating**: 414
- **Solved in**: 1 attempt(s)

## Problem Summary
Given the initial selling price $X$ and the initial profit $Y$ of an item, we need to calculate the new profit after increasing the selling price by 10%. The cost price remains constant.

## Intuition & Mathematical Observation
1. **Identify the Cost Price**: 
   The profit is defined as $\text{Selling Price} - \text{Cost Price}$. 
   Therefore, $\text{Cost Price} = X - Y$.

2. **Calculate New Selling Price**: 
   The selling price increases by 10%. 
   $\text{New Selling Price} = X + (0.10 \times X)$.

3. **Calculate New Profit**:
   $\text{New Profit} = \text{New Selling Price} - \text{Cost Price}$
   $\text{New Profit} = (X + 0.10 \times X) - (X - Y)$
   $\text{New Profit} = X + 0.10 \times X - X + Y$
   $\text{New Profit} = Y + (X / 10)$

Since the problem guarantees $X$ is a multiple of 100, $X/10$ will always result in an integer, making the calculation straightforward.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we perform a constant number of arithmetic operations.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Initial Selling Price = X
 * Initial Profit = Y
 * Buying Price (Cost Price) = X - Y
 * 
 * New Selling Price = X + 10% of X = X + 0.1 * X = 1.1 * X
 * New Profit = New Selling Price - Buying Price
 * New Profit = (1.1 * X) - (X - Y)
 * New Profit = 1.1 * X - X + Y
 * New Profit = 0.1 * X + Y
 * 
 * Since X is a multiple of 100, 0.1 * X will always be an integer.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long x, y;
        cin >> x >> y;

        // Calculate the increase in price (10% of X)
        long long increase = x / 10;
        
        // New profit = Y + increase
        long long new_profit = y + increase;

        cout << new_profit << "\n";
    }

    return 0;
}
```