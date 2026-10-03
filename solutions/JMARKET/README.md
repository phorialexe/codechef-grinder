# [Janmansh at Fruit Market (JMARKET)](https://www.codechef.com/problems/JMARKET)

- **Difficulty Rating**: 947
- **Solved in**: 1 attempt(s)

## Problem Summary
Janmansh wants to buy exactly $X$ fruits. There are three types of fruits available with prices $A$, $B$, and $C$ per unit. The constraint is that Janmansh must buy at least two different kinds of fruits. The goal is to minimize the total cost of purchasing exactly $X$ fruits.

## Intuition & Mathematical Observation
To minimize the total cost while satisfying the condition of buying at least two different types of fruits:

1.  **Sorting**: First, sort the prices such that $p_1 \le p_2 \le p_3$.
2.  **Greedy Approach**: Since we want to minimize the total cost, we should prioritize buying the cheapest fruit ($p_1$) as much as possible.
3.  **Constraint Satisfaction**: We are required to buy at least two different types. To minimize the cost, we should buy only one unit of the second-cheapest fruit ($p_2$) and fill the remaining $(X-1)$ units with the cheapest fruit ($p_1$).
4.  **Formula**: The minimum cost is calculated as:
    $$\text{Cost} = (X - 1) \times p_1 + (1) \times p_2$$
    This ensures we have $X$ fruits in total, uses at least two types, and keeps the expenditure at the absolute minimum.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case. Sorting three elements takes constant time, and the arithmetic operations are also constant.
- **Space Complexity**: $O(1)$ as we only store a fixed number of variables regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to buy X fruits in total, using at least two different kinds of fruits.
 * Let the prices be A, B, and C.
 * To minimize the cost, we should sort the prices such that p1 <= p2 <= p3.
 * 
 * Strategy:
 * 1. Sort the prices: p1 <= p2 <= p3.
 * 2. To minimize cost, we buy (X-1) fruits of price p1 and 1 fruit of price p2.
 *    This satisfies the "at least two different kinds" condition with the lowest possible sum.
 */

void solve() {
    long long X, A, B, C;
    if (!(cin >> X >> A >> B >> C)) return;
    
    vector<long long> p = {A, B, C};
    sort(p.begin(), p.end());
    
    // Calculate minimum cost: (X-1) of the cheapest + 1 of the second cheapest
    long long ans = (X - 1) * p[0] + p[1];
    
    cout << ans << "\n";
}

int main() {
    // Fast I/O
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