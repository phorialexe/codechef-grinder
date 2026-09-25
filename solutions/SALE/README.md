# [Get Lowest Free (SALE)](https://www.codechef.com/problems/SALE)

- **Difficulty Rating**: 778
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef goes to a store and buys three items with prices $A$, $B$, and $C$. The store has a promotion where the cheapest item among the three is provided for free. We need to calculate the total amount Chef has to pay.

## Intuition & Mathematical Observation
The total cost of the three items is the sum of their individual prices: $A + B + C$. Since the store offers the cheapest item for free, we simply need to subtract the minimum value among the three prices from the total sum.

Mathematically, the amount to pay is:
$$\text{Amount} = (A + B + C) - \min(A, B, C)$$

By using the `std::min` function with an initializer list in C++, we can easily find the minimum of the three integers and subtract it from their total sum.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. Each test case performs a constant number of operations, resulting in $O(1)$ per test case.
- **Space Complexity**: $O(1)$, as we only use a few integer variables regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef buys 3 items with prices A, B, and C.
 * The rule is: the item with the lowest price among the three is free.
 * The total amount to pay is (A + B + C) - min(A, B, C).
 * 
 * Constraints:
 * 1 <= T <= 100
 * 1 <= A, B, C <= 10
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;
        
        // Calculate the sum of all three items
        int total_sum = a + b + c;
        
        // Find the minimum price among the three
        int min_price = min({a, b, c});
        
        // The amount to pay is the total sum minus the cheapest item
        int amount_to_pay = total_sum - min_price;
        
        cout << amount_to_pay << "\n";
    }
    
    return 0;
}
```