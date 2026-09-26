# [Lucky Clover (LUCLO)](https://www.codechef.com/problems/LUCLO)

- **Difficulty Rating**: 236
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef has $N$ clovers. Out of these $N$ clovers, exactly one is a 4-leaf clover, and the remaining $(N - 1)$ clovers are 3-leaf clovers. The goal is to calculate the total number of leaves across all $N$ clovers.

## Intuition & Mathematical Observation
To find the total number of leaves, we can break the problem down into two parts:
1. The 4-leaf clover contributes exactly **4** leaves.
2. The remaining $(N - 1)$ clovers contribute **3** leaves each.

We can derive the total count using the following algebraic expression:
$$\text{Total Leaves} = (1 \times 4) + ((N - 1) \times 3)$$
$$\text{Total Leaves} = 4 + 3N - 3$$
$$\text{Total Leaves} = 3N + 1$$

This formula holds true for the given constraints ($1 \le N \le 10$). For example:
- If $N=1$: $3(1) + 1 = 4$ leaves.
- If $N=5$: $3(5) + 1 = 16$ leaves.

## Complexity Analysis
- **Time Complexity**: $O(1)$ — The calculation involves a simple arithmetic operation that executes in constant time.
- **Space Complexity**: $O(1)$ — We only use a single integer variable to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef has N clovers.
 * Exactly one is a 4-leaf clover.
 * The remaining (N - 1) are 3-leaf clovers.
 * Total leaves = (1 * 4) + ((N - 1) * 3)
 * Total leaves = 4 + 3N - 3
 * Total leaves = 3N + 1
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    // Read the input integer N
    if (cin >> N) {
        // Apply the derived formula: 3N + 1
        long long total_leaves = 3LL * N + 1;
        cout << total_leaves << "\n";
    }

    return 0;
}
```