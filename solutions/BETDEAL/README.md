# [Better Deal (BETDEAL)](https://www.codechef.com/problems/BETDEAL)

- **Difficulty Rating**: 584
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given two stores offering discounts on items with different base prices:
- **Store 1**: Offers an $A\%$ discount on an item originally priced at 100.
- **Store 2**: Offers a $B\%$ discount on an item originally priced at 200.

The goal is to determine which store offers the cheaper final price. If both stores result in the same final price, output "BOTH".

## Intuition & Mathematical Observation
To solve this, we calculate the final price for each store:

1.  **Store 1**: The discount amount is $\frac{A}{100} \times 100 = A$. 
    The final price is $100 - A$.
2.  **Store 2**: The discount amount is $\frac{B}{100} \times 200 = 2B$. 
    The final price is $200 - 2B$.

By comparing these two values:
- If $(100 - A) < (200 - 2B)$, the **FIRST** store is cheaper.
- If $(200 - 2B) < (100 - A)$, the **SECOND** store is cheaper.
- If they are equal, output **BOTH**.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. Each test case involves simple arithmetic operations performed in constant time.
- **Space Complexity**: $O(1)$, as we only use a few integer variables to store the inputs and calculated prices.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Store 1: Original price = 100. Discount = A%.
 * Final Price 1 = 100 - (A/100 * 100) = 100 - A.
 * 
 * Store 2: Original price = 200. Discount = B%.
 * Final Price 2 = 200 - (B/100 * 200) = 200 - 2B.
 * 
 * We need to compare (100 - A) and (200 - 2B).
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        int a, b;
        cin >> a >> b;
        
        // Calculate final prices
        int price1 = 100 - a;
        int price2 = 200 - 2 * b;
        
        // Compare prices
        if (price1 < price2) {
            cout << "FIRST" << "\n";
        } else if (price2 < price1) {
            cout << "SECOND" << "\n";
        } else {
            cout << "BOTH" << "\n";
        }
    }
    
    return 0;
}
```