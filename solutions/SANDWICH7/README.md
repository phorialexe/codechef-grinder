# [Sandwiches (SANDWICH7)](https://www.codechef.com/problems/SANDWICH7)

- **Difficulty Rating**: 303
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef wants to make sandwiches. Each sandwich requires exactly **2 pieces of bread** and **1 filling** (which can be either ham or cheese). Given the total number of bread slices ($B$), ham slices ($H$), and cheese slices ($C$), determine the maximum number of sandwiches Chef can prepare.

## Intuition & Mathematical Observation
To determine the maximum number of sandwiches, we must consider the limiting factors:

1.  **Bread Constraint**: Since each sandwich requires 2 pieces of bread, the total number of sandwiches possible based on bread alone is $\lfloor B / 2 \rfloor$.
2.  **Filling Constraint**: Since each sandwich requires exactly one filling (either ham or cheese), the total number of sandwiches possible based on fillings is the sum of ham and cheese slices, which is $H + C$.

The actual number of sandwiches Chef can make is constrained by whichever resource runs out first. Therefore, the answer is the minimum of the two constraints:
$$\text{Result} = \min\left(\left\lfloor \frac{B}{2} \right\rfloor, H + C\right)$$

## Complexity Analysis
- **Time Complexity**: $O(1)$, as the solution involves only basic arithmetic operations and comparisons.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef needs 2 pieces of bread for every sandwich.
 * Chef can use either ham or cheese for the filling.
 * 
 * Let S be the number of sandwiches.
 * Constraint 1: 2 * S <= B  => S <= B / 2
 * Constraint 2: S <= H + C (Total fillings available)
 * 
 * Therefore, the maximum number of sandwiches is min(B / 2, H + C).
 */

void solve() {
    long long B, H, C;
    if (!(cin >> B >> H >> C)) return;
    
    // Calculate constraints
    long long max_sandwiches_by_bread = B / 2;
    long long max_sandwiches_by_filling = H + C;
    
    // The result is the limiting factor
    long long result = min(max_sandwiches_by_bread, max_sandwiches_by_filling);
    
    cout << result << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    solve();
    
    return 0;
}
```