# [Too many items (POLYBAGS)](https://www.codechef.com/problems/POLYBAGS)

- **Difficulty Rating**: 738
- **Solved in**: 1 attempt(s)

## Problem Summary
Given $N$ items, we need to pack them into polybags. Each polybag can hold a maximum of 10 items. The goal is to determine the minimum number of polybags required to store all $N$ items.

## Intuition & Mathematical Observation
To find the minimum number of polybags, we need to divide the total number of items $N$ by the capacity of a single bag (10). Since we cannot have a fraction of a bag, if there are any remaining items, we must use an additional bag. This is equivalent to the **ceiling function**: $\lceil N / 10 \rceil$.

In integer arithmetic, the ceiling of $N/K$ can be calculated efficiently without using floating-point numbers using the formula:
$$\text{result} = \frac{N + K - 1}{K}$$
Substituting $K = 10$, we get:
$$\text{result} = \frac{N + 9}{10}$$
This formula works because:
- If $N$ is a multiple of 10, $(N+9)/10$ correctly results in $N/10$.
- If $N$ has a remainder, the $+9$ ensures the integer division rounds up to the next whole number.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a constant time arithmetic operation.
- **Space Complexity**: $O(1)$, as we only use a few integer variables regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Each polybag can hold at most 10 items.
 * To find the minimum number of polybags for N items, we need to calculate ceil(N / 10).
 * Using integer arithmetic, ceil(N / 10) can be calculated as (N + 9) / 10.
 * 
 * Constraints:
 * T <= 1000, N <= 1000.
 * The result will fit in a standard integer.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        int n;
        cin >> n;
        
        // Calculate minimum polybags using integer division
        // (n + 9) / 10 is equivalent to ceil(n / 10.0)
        int polybags = (n + 9) / 10;
        
        cout << polybags << "\n";
    }
    
    return 0;
}
```