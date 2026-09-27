# [International Education Day! (IED)](https://www.codechef.com/problems/IED)

- **Difficulty Rating**: 271
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to determine the maximum total revenue between two individuals, Chef and Chefina. We are given three integers:
- $A$: The price of an item sold by Chef.
- $B$: The price of an item sold by Chefina.
- $C$: The number of items sold by both (they sell the same quantity).

We need to calculate $A \times C$ and $B \times C$ and output the larger of the two values.

## Intuition & Mathematical Observation
Since both Chef and Chefina sell the same number of items ($C$), the total revenue for each is simply the product of their respective price and the quantity sold. 

Mathematically, we are looking for:
$$\max(A \times C, B \times C)$$

Given the constraints $1 \le A, B, C \le 10$, the maximum possible value is $10 \times 10 = 100$. This fits comfortably within a standard integer type. The logic is straightforward: calculate both products and use the built-in `max()` function to find the result.

## Complexity Analysis
- **Time Complexity**: $O(1)$ — The solution performs a constant number of arithmetic operations regardless of the input values.
- **Space Complexity**: $O(1)$ — We only use a few variables to store the input and the result, requiring constant extra space.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: International Education Day!
 * The problem asks to calculate the maximum of (A * C) and (B * C).
 * Given the constraints 1 <= A, B, C <= 10, the result will fit in a standard integer.
 * However, using long long is a good practice to prevent overflow in similar problems.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Reading A, B, and C.
    long long A, B, C;
    if (!(cin >> A >> B >> C)) return 0;

    // Calculate total sales for Chef and Chefina
    long long chef_sales = A * C;
    long long chefina_sales = B * C;

    // Output the maximum of the two
    cout << max(chef_sales, chefina_sales) << "\n";

    return 0;
}
```