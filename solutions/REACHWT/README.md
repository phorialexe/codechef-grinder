# [Reach Weight (REACHWT)](https://www.codechef.com/problems/REACHWT)

- **Difficulty Rating**: 530
- **Solved in**: 1 attempt(s)

## Problem Summary
We are tasked with reaching a target weight $N$ using two types of weights:
1. A 1kg weight that costs 20 units.
2. A 2kg weight that costs 30 units.

The goal is to find the minimum cost to reach exactly $N$ kg.

## Intuition & Mathematical Observation
Let $x$ be the number of 1kg weights and $y$ be the number of 2kg weights. We have the constraint:
$$x + 2y = N$$

We want to minimize the total cost $C$:
$$C = 20x + 30y$$

Substituting $x = N - 2y$ into the cost equation:
$$C = 20(N - 2y) + 30y$$
$$C = 20N - 40y + 30y$$
$$C = 20N - 10y$$

To minimize $C$, we need to make the term $10y$ as large as possible. This means we should maximize $y$. Since $x$ must be non-negative ($x \ge 0$), we have $N - 2y \ge 0$, which implies $y \le N/2$. 

Thus, the maximum value for $y$ is $\lfloor N/2 \rfloor$. By using as many 2kg weights as possible, we minimize the total cost because 2kg weights are more "cost-efficient" per kilogram than 1kg weights.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the calculation involves simple arithmetic operations. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to reach exactly N kg using 1kg weights (cost 20) and 2kg weights (cost 30).
 * Let x be the number of 1kg weights and y be the number of 2kg weights.
 * We want to minimize Cost = 20x + 30y subject to x + 2y = N.
 * 
 * From x + 2y = N, we get x = N - 2y.
 * Since x >= 0, we must have 2y <= N, so y <= N/2.
 * Substituting x:
 * Cost = 20(N - 2y) + 30y
 * Cost = 20N - 40y + 30y
 * Cost = 20N - 10y
 * 
 * To minimize the cost, we need to maximize y.
 * The maximum possible value for y is floor(N / 2).
 * 
 * Therefore, the minimum cost is 20N - 10 * floor(N / 2).
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long n;
        cin >> n;
        
        // Maximize y = n / 2 to minimize cost
        long long y = n / 2;
        long long cost = 20 * n - 10 * y;
        
        cout << cost << "\n";
    }
    
    return 0;
}
```