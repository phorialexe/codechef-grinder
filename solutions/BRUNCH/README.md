# [Sunday Brunch (BRUNCH)](https://www.codechef.com/problems/BRUNCH)

- **Difficulty Rating**: 648
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef has $X$ plates available for brunch. Each neighbor requires exactly $Y$ plates to be fed. Given that there are only 20 neighbors in total, determine the maximum number of neighbors Chef can feed completely.

## Intuition & Mathematical Observation
The problem asks us to find how many groups of size $Y$ can be formed from $X$ total plates. Mathematically, this is the integer division of $X$ by $Y$ ($\lfloor X/Y \rfloor$).

However, there is a physical constraint: Chef only has 20 neighbors. Even if he has enough plates to feed more than 20 people, he cannot feed more than the total number of neighbors available. Therefore, the final answer is the minimum of the calculated capacity ($\lfloor X/Y \rfloor$) and the total number of neighbors (20).

**Formula:**
$$\text{Result} = \min(20, \lfloor X/Y \rfloor)$$

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a constant number of arithmetic operations.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef has X plates and each neighbour takes Y plates.
 * We need to find the maximum number of neighbours that can be fed completely.
 * This is equivalent to finding the floor of (X / Y).
 * However, there is a constraint: there are only 20 neighbours.
 * Therefore, the answer is min(20, X / Y).
 * 
 * Constraints:
 * 1 <= T <= 405
 * 20 <= X <= 100
 * 1 <= Y <= 5
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long x, y;
        cin >> x >> y;
        
        // Calculate how many neighbours can be fed with X plates
        long long fed = x / y;
        
        // Chef only has 20 neighbours, so the maximum he can feed is 20
        long long result = min(20LL, fed);
        
        cout << result << "\n";
    }
    
    return 0;
}
```