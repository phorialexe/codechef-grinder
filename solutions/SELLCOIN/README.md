# [Selling Coins (SELLCOIN)](https://www.codechef.com/problems/SELLCOIN)

- **Difficulty Rating**: 218
- **Solved in**: 2 attempt(s)

## Problem Summary
Chef possesses $A$ silver coins and $B$ gold coins. The conversion rates are as follows:
*   1 gold coin can be exchanged for 2 silver coins.
*   1 silver coin is worth 1 Rupee.

The goal is to calculate the total amount of Rupees Chef can earn by converting all his gold coins into silver coins and then selling all his silver coins.

## Intuition & Mathematical Observation
The problem is a straightforward arithmetic calculation. Since every gold coin is worth 2 silver coins, and every silver coin is worth 1 Rupee, we can derive the total value as follows:

1.  **Initial Silver Coins**: $A$
2.  **Silver Coins from Gold**: $B \times 2$
3.  **Total Silver Coins**: $A + (2 \times B)$
4.  **Total Rupees**: Since 1 silver coin = 1 Rupee, the total money is simply the total number of silver coins.

Thus, the formula is:
$$\text{Total Money} = A + 2B$$

*Note: Using `long long` is a good practice to prevent potential integer overflow, although given the constraints of this specific problem, standard integers would likely suffice.*

## Complexity Analysis
- **Time Complexity**: $O(1)$ — The solution performs a constant number of arithmetic operations regardless of the input size.
- **Space Complexity**: $O(1)$ — We only use a fixed amount of memory to store the variables $A$ and $B$.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef has A silver coins and B gold coins.
 * - 1 gold coin = 2 silver coins.
 * - 1 silver coin = 1 Rupee.
 * 
 * Total silver coins after trading all gold coins = A + (B * 2).
 * Since each silver coin sells for 1 Rupee, the total money earned is A + 2 * B.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long A, B;
    
    // Read A and B from standard input
    if (cin >> A >> B) {
        // Total money = (Initial silver) + (Silver from gold)
        // Each gold coin gives 2 silver coins, and each silver coin is worth 1 Rupee.
        long long total_money = A + (2 * B);
        
        cout << total_money << endl;
    }
    
    return 0;
}
```