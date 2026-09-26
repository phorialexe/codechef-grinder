# [Chef and Price Control (PRICECON)](https://www.codechef.com/problems/PRICECON)

- **Difficulty Rating**: 931
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef sells $N$ items, each with a specific price $P_i$. The government introduces a price ceiling $K$. Any item with a price greater than $K$ must now be sold at price $K$. The goal is to calculate the total revenue lost due to this price ceiling.

## Intuition & Mathematical Observation
The revenue lost for a single item $i$ is defined as:
- If $P_i > K$: The loss is $P_i - K$.
- If $P_i \le K$: The loss is $0$.

To find the total revenue lost, we iterate through all $N$ items, check if the price exceeds $K$, and accumulate the difference into a running total. Mathematically, the total lost revenue is:
$$\text{Total Loss} = \sum_{i=1}^{N} \max(0, P_i - K)$$

Since the constraints are small ($N \le 10,000$ and $P_i, K \le 1,000$), a simple linear scan $O(N)$ per test case is highly efficient and well within the time limits.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the number of items. We iterate through the list of prices exactly once.
- **Space Complexity**: $O(1)$, as we only store the current price and the running total, requiring constant extra space.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef has N items with prices P_i.
 * A price ceiling K is introduced.
 * If P_i > K, the price becomes K.
 * The lost revenue for a single item i is:
 * - If P_i > K: P_i - K
 * - If P_i <= K: 0
 * Total lost revenue is the sum of (P_i - K) for all i where P_i > K.
 */

void solve() {
    int N;
    long long K;
    cin >> N >> K;
    
    long long lost_revenue = 0;
    for (int i = 0; i < N; ++i) {
        long long P;
        cin >> P;
        // If the price is higher than the ceiling, add the difference to total loss
        if (P > K) {
            lost_revenue += (P - K);
        }
    }
    
    cout << lost_revenue << "\n";
}

int main() {
    // Fast I/O setup for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    
    return 0;
}
```