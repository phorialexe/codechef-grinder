# [Maximum Production (EITA)](https://www.codechef.com/problems/EITA)

- **Difficulty Rating**: 833
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef has two strategies to complete a task over a period of 7 days:
1. **Strategy 1**: Work $x$ units every day for all 7 days.
2. **Strategy 2**: Work $y$ units for the first $d$ days, and $z$ units for the remaining $(7 - d)$ days.

The goal is to determine the maximum total units of work Chef can complete by choosing the better of the two strategies.

## Intuition & Mathematical Observation
The problem asks us to compare two simple linear calculations:

*   **Strategy 1 Total**: Since Chef works $x$ units every day for 7 days, the total work is simply:
    $$\text{Total}_1 = x \times 7$$

*   **Strategy 2 Total**: Chef works $y$ units for $d$ days and $z$ units for the remaining $(7 - d)$ days. The total work is:
    $$\text{Total}_2 = (y \times d) + (z \times (7 - d))$$

By calculating both values, we can use the `max()` function to find the optimal result. Given the constraints (where inputs are small integers), standard `int` types are perfectly sufficient to prevent overflow.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case. Since we perform a constant number of arithmetic operations regardless of the input size, the complexity is constant. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$. We only use a few integer variables to store the inputs and the calculated results, requiring constant extra space.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Strategy 1: Work x units every day for 7 days.
 * Total work = x * 7
 * 
 * Strategy 2: Work y units for d days, and z units for (7 - d) days.
 * Total work = (y * d) + (z * (7 - d))
 * 
 * We need to output max(Strategy 1, Strategy 2).
 * Constraints are small (up to 18), so standard integer types are sufficient.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        int d, x, y, z;
        cin >> d >> x >> y >> z;
        
        // Strategy 1 calculation
        int strategy1 = x * 7;
        
        // Strategy 2 calculation
        int strategy2 = (y * d) + (z * (7 - d));
        
        // Output the maximum of the two strategies
        cout << max(strategy1, strategy2) << "\n";
    }
    
    return 0;
}
```