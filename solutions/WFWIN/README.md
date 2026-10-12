# [Winning World Finals (WFWIN)](https://www.codechef.com/problems/WFWIN)

- **Difficulty Rating**: 1146
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef is participating in a contest where the total penalty is calculated as the sum of the time of the correct submission and $20$ minutes for every wrong submission made prior to the correct one. Chef has already made a correct submission at time $M$ with an existing penalty $P$. He can make additional wrong submissions at any time $t > M$ (provided $t < 300$) to increase his penalty. The goal is to maximize the number of wrong submissions $W$ such that the total penalty does not exceed $1000$ and the final correct submission time remains strictly less than $300$.

## Intuition & Mathematical Observation
Let $W$ be the number of additional wrong submissions.
1. **Penalty Constraint**: Each wrong submission adds $20$ to the penalty. Additionally, the time of the correct submission increases by $1$ for every wrong submission made (since each wrong submission takes 1 minute). Thus, the new penalty becomes $P + (20 \times W) + (M + W) = P + M + 21 \times W$.
   - We require: $P + M + 21 \times W \leq 1000$.
   - Solving for $W$: $21 \times W \leq 1000 - P - M \implies W \leq \lfloor \frac{1000 - P - M}{21} \rfloor$.

2. **Time Constraint**: The problem states the correct submission must occur at a time $T < 300$. Since each wrong submission increases the time by $1$, the new time is $M + W$.
   - We require: $M + W < 300 \implies W < 300 - M \implies W \leq 299 - M$.

Combining these, the maximum number of wrong submissions $W$ is the minimum of these two bounds, ensuring $W \geq 0$.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution involves basic arithmetic operations.
- **Space Complexity**: $O(1)$, as we only use a few integer variables.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Let W be the number of additional wrong submissions.
 * Each wrong submission adds 20 to the penalty and increases the time of 
 * the correct submission by 1 minute.
 * 
 * Total Penalty = P + (20 * W) + (M + W) = P + M + 21 * W
 * Constraint 1: P + M + 21 * W <= 1000
 * Constraint 2: M + W < 300
 */

void solve() {
    int M, P;
    cin >> M >> P;
    
    // Calculate max W based on penalty constraint
    int max_w_penalty = (1000 - P - M) / 21;
    
    // Calculate max W based on time constraint (M + W <= 299)
    int max_w_time = 299 - M;
    
    // The answer is the minimum of the two constraints, but cannot be negative
    int ans = max(0, min(max_w_penalty, max_w_time));
    
    cout << ans << "\n";
}

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
```