# [Buying Chairs (CHRBUY)](https://www.codechef.com/problems/CHRBUY)

- **Difficulty Rating**: 564
- **Solved in**: 1 attempt(s)

## Problem Summary
You are given $W$ wooden chairs (each with a value of 2) and $P$ plastic chairs (each with a value of 1). You need to select exactly $K$ chairs such that the total value (stylishness) is maximized. You are guaranteed that $K \le W + P$.

## Intuition & Mathematical Observation
To maximize the total value, we should prioritize the items with the highest individual value. Since wooden chairs have a value of 2 and plastic chairs have a value of 1, we should greedily pick as many wooden chairs as possible.

1. **Greedy Strategy**: 
   - We want to pick the maximum number of wooden chairs, denoted as $w$.
   - The constraint is $w \le W$ and $w \le K$. Therefore, the optimal number of wooden chairs is $w = \min(K, W)$.
   - The remaining chairs needed to reach the total of $K$ must be plastic chairs. Thus, $p = K - w$.
   - Since $K \le W + P$, we are guaranteed that $p \le P$, ensuring the selection is always possible.

2. **Calculation**:
   - Total Stylishness = $(w \times 2) + (p \times 1)$.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution involves simple arithmetic operations. Total time complexity is $O(T)$ for $T$ test cases.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have W wooden chairs (value 2 each) and P plastic chairs (value 1 each).
 * We need to pick exactly K chairs such that the total value is maximized.
 * 
 * Strategy:
 * Since wooden chairs have a higher value (2) than plastic chairs (1), 
 * we should prioritize picking as many wooden chairs as possible.
 * 
 * Let 'w' be the number of wooden chairs picked and 'p' be the number of plastic chairs picked.
 * We must satisfy:
 * 1. w + p = K
 * 2. 0 <= w <= W
 * 3. 0 <= p <= P
 * 
 * To maximize 2*w + 1*p:
 * We want 'w' to be as large as possible.
 * The maximum possible 'w' is min(K, W).
 * Once we pick w = min(K, W) wooden chairs, we must pick the remaining 
 * (K - w) chairs as plastic chairs.
 * Since K <= W + P, we are guaranteed that (K - w) <= P.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long W, P, K;
        cin >> W >> P >> K;

        // Maximize wooden chairs first
        long long wooden_to_buy = min(K, W);
        long long plastic_to_buy = K - wooden_to_buy;

        // Calculate total stylishness
        long long stylishness = (wooden_to_buy * 2) + (plastic_to_buy * 1);

        cout << stylishness << "\n";
    }

    return 0;
}
```