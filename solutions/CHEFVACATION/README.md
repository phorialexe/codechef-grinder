# [Chef on Vacation (CHEFVACATION)](https://www.codechef.com/problems/CHEFVACATION)

- **Difficulty Rating**: 891
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef is planning two trips with durations $X$ and $Y$ days, respectively. He has a total vacation period of $Z$ days. The goal is to determine if Chef can complete both trips within the given $Z$ days. In other words, we need to check if the sum of the two trip durations is less than or equal to the total vacation duration.

## Intuition & Mathematical Observation
The problem asks whether two tasks (trips) can fit into a single time constraint. 
- Let the duration of the first trip be $X$.
- Let the duration of the second trip be $Y$.
- Let the total available time be $Z$.

Chef can go on both trips if and only if the total time required ($X + Y$) does not exceed the total time available ($Z$). Therefore, the condition is:
$$X + Y \le Z$$

If this inequality holds true, output `YES`; otherwise, output `NO`.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a constant number of arithmetic operations and comparisons, which takes $O(1)$ time.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input values regardless of the size of the input.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef has two trips of duration X and Y.
 * The total vacation duration is Z.
 * Chef can go on both trips if the sum of the durations of the two trips
 * is less than or equal to the total duration of the vacation.
 * Condition: X + Y <= Z
 * 
 * Constraints:
 * T <= 1000
 * X, Y, Z <= 1000
 * X + Y will be at most 2000, which fits in a standard integer.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long x, y, z;
        cin >> x >> y >> z;
        
        // Check if the sum of trip durations is within the vacation limit
        if (x + y <= z) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
    
    return 0;
}
```