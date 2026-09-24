# [Presents for Cheffina (PRESENTS)](https://www.codechef.com/problems/PRESENTS)

- **Difficulty Rating**: 757
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef wants to buy $N$ gifts. The shop has a special offer: for every 4 gifts purchased, the customer receives 1 gift for free. This effectively means that for every 5 gifts Chef acquires, they only need to pay for 4 of them. The goal is to calculate the minimum number of coins required to obtain exactly $N$ gifts.

## Intuition & Mathematical Observation
The core of the problem lies in identifying the "bundle" size. Since Chef gets 1 free gift for every 4 purchased, a single transaction cycle consists of 5 gifts total (4 paid + 1 free).

1. **Full Bundles**: We can determine how many groups of 5 gifts are in $N$ by calculating $N / 5$. For each of these groups, Chef pays 4 coins.
2. **Remaining Gifts**: After accounting for the full bundles, there might be a remainder of gifts ($N \% 5$). Since these do not form a complete set of 5, Chef must pay 1 coin for each of these remaining gifts.

**Formula**:
$$\text{Total Cost} = (N / 5) \times 4 + (N \% 5)$$

*Example*: If $N = 12$:
- $12 / 5 = 2$ full bundles. Cost = $2 \times 4 = 8$.
- $12 \% 5 = 2$ remaining gifts. Cost = $2 \times 1 = 2$.
- Total = $8 + 2 = 10$ coins.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution uses simple arithmetic operations. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef gets 1 gift free for every 4 gifts purchased.
 * This means for every group of 5 gifts, Chef pays for 4.
 * 
 * Let N be the total number of gifts required.
 * The number of full groups of 5 is (N / 5).
 * For each group of 5, Chef pays 4 coins.
 * The remaining gifts (N % 5) are paid for individually (1 coin each).
 * 
 * Total cost = (N / 5) * 4 + (N % 5)
 */

int main() {
    // Fast I/O for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;

        // Calculate full groups of 5 and the remainder
        long long groups = n / 5;
        long long remainder = n % 5;
        
        // Calculate total cost
        long long total_cost = (groups * 4) + remainder;
        
        cout << total_cost << "\n";
    }

    return 0;
}
```