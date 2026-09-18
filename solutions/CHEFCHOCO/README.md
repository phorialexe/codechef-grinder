# [Chef and Chocolates (CHEFCHOCO)](https://www.codechef.com/problems/CHEFCHOCO)

- **Difficulty Rating**: 492
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef wants to have a total of $C$ chocolates. He currently possesses $X$ chocolates. Each additional chocolate costs $Y$ rupees. The goal is to calculate the total amount of money Chef needs to spend to acquire the remaining chocolates required to reach his target of $C$.

## Intuition & Mathematical Observation
The problem is a straightforward arithmetic calculation:
1. **Determine the deficit**: Chef needs $C$ chocolates but already has $X$. The number of chocolates he needs to buy is $C - X$.
2. **Calculate the cost**: Since each of the $(C - X)$ chocolates costs $Y$ rupees, the total cost is simply the product of the number of chocolates needed and the price per unit.
3. **Formula**: $\text{Total Cost} = (C - X) \times Y$.

Given the constraints ($C, X, Y \le 100$), the result will not exceed $10,000$, which fits comfortably within a standard integer data type.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a constant number of arithmetic operations, resulting in $O(1)$ per test case.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result, requiring no extra data structures.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef needs C chocolates in total.
 * Chef already has X chocolates.
 * Therefore, Chef needs to purchase (C - X) chocolates.
 * Each chocolate costs Y rupees.
 * Total cost = (C - X) * Y.
 * 
 * Constraints:
 * 1 <= T <= 100
 * 1 <= C <= 100
 * 0 <= X <= C
 * 1 <= Y <= 100
 * 
 * Since the maximum value of (C - X) * Y is (100 - 0) * 100 = 10,000,
 * standard 'int' is sufficient to prevent overflow.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long c, x, y;
        cin >> c >> x >> y;
        
        // Calculate the number of chocolates needed
        long long needed = c - x;
        
        // Calculate total cost
        long long total_cost = needed * y;
        
        // Output the result
        cout << total_cost << "\n";
    }
    
    return 0;
}
```