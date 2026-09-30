# [Cashback (CASHBACK)](https://www.codechef.com/problems/CASHBACK)

- **Difficulty Rating**: -1
- **Solved in**: 2 attempt(s)

## Problem Summary
The task is to calculate the final amount a customer needs to pay based on their purchase price $X$. If the purchase price is 200 or more, the customer receives a cashback of 50, meaning they pay $X - 50$. If the purchase price is less than 200, the customer pays the original price $X$ without any discount.

## Intuition & Mathematical Observation
The problem follows a simple conditional logic structure:
1. **Condition**: Check if $X \ge 200$.
2. **Case 1 ($X \ge 200$)**: The customer is eligible for the cashback. The final price is $X - 50$.
3. **Case 2 ($X < 200$)**: The customer is not eligible for the cashback. The final price remains $X$.

This can be implemented using a standard `if-else` statement.

## Complexity Analysis
- **Time Complexity**: $O(1)$, as the solution performs a constant number of arithmetic and comparison operations regardless of the input size.
- **Space Complexity**: $O(1)$, as we only use a single integer variable to store the input.

## Solution Code

```cpp
#include <iostream>

using namespace std;

/**
 * Problem: CASHBACK
 * Logic: If the price X is >= 200, the customer pays X - 50.
 * Otherwise, the customer pays X.
 * Input Format: Single integer X.
 */

int main() {
    // Optimize I/O operations for faster execution
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int x;
    // Read the single integer X as specified in the problem description
    if (cin >> x) {
        if (x >= 200) {
            // Apply cashback if price is 200 or more
            cout << (x - 50) << endl;
        } else {
            // Pay original price if less than 200
            cout << x << endl;
        }
    }

    return 0;
}
```