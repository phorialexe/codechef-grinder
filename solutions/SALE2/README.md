# [Buy 2 Get 1 Free (SALE2)](https://www.codechef.com/problems/SALE2)

- **Difficulty Rating**: 821
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef wants to buy $N$ items, each costing $X$ rupees. The shop has a "Buy 2 Get 1 Free" offer. This means for every 3 items Chef picks, he only pays for 2 of them. We need to calculate the minimum total cost to acquire exactly $N$ items.

## Intuition & Mathematical Observation
The core of the problem lies in the grouping of items. Since the offer applies to every set of 3 items:

1.  **Grouping**: We can divide the total number of items $N$ by 3 to find how many full "Buy 2 Get 1" sets Chef can utilize.
    *   `sets = N / 3`
2.  **Cost of Sets**: For each set of 3, Chef pays for 2 items. Therefore, the cost for these sets is `sets * 2 * X`.
3.  **Remaining Items**: After taking out the full sets, there might be items left over ($N \pmod 3$). These remaining items do not qualify for the free item offer, so each must be paid for at the full price $X$.
    *   `remainder = N % 3`
    *   `remainder_cost = remainder * X`
4.  **Total Cost**: The final answer is the sum of the cost of the sets and the cost of the remaining items:
    *   `Total Cost = (sets * 2 * X) + (remainder * X)`

Using `long long` is recommended to prevent potential integer overflow, although given the constraints, standard integers might suffice depending on the input limits.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the calculation involves only basic arithmetic operations.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * For every 3 items, Chef pays for 2 and gets 1 free.
 * This means in every group of 3 items, the cost is 2 * X.
 * If N items are needed:
 * - Number of full groups of 3 is (N / 3).
 * - Remaining items are (N % 3).
 * 
 * Total cost = (Number of groups * 2 * X) + (Remaining items * X)
 */

int main() {
    // Fast I/O for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long n, x;
        cin >> n >> x;

        // Calculate number of full sets of 3
        long long sets = n / 3;
        long long remainder = n % 3;

        // Cost calculation:
        // Each set of 3 costs 2 * X
        // Each remaining item costs X
        long long total_cost = (sets * 2 * x) + (remainder * x);

        cout << total_cost << "\n";
    }

    return 0;
}
```