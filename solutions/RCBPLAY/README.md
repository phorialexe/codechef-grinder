# [RCB and Playoffs (RCBPLAY)](https://www.codechef.com/problems/RCBPLAY)

- **Difficulty Rating**: 788
- **Solved in**: 1 attempt(s)

## Problem Summary
Royal Challengers Bangalore (RCB) currently has $X$ points in the league. To qualify for the playoffs, they need to reach at least $Y$ points. They have $Z$ games remaining. In each game, a win awards 2 points, a draw awards 1 point, and a loss awards 0 points. We need to determine if it is possible for RCB to reach at least $Y$ points by the end of their remaining $Z$ games.

## Intuition & Mathematical Observation
To determine if qualification is possible, we must consider the "best-case scenario" for RCB. 
- In each of the $Z$ remaining games, the maximum number of points they can earn is 2 (by winning).
- Therefore, the maximum total points they can accumulate is $X + (2 \times Z)$.
- If this maximum possible score is greater than or equal to the target $Y$, then it is possible for them to qualify. Otherwise, it is impossible.

The condition for qualification is:
$$X + 2Z \ge Y$$

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution involves simple arithmetic operations. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input values.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * RCB currently has X points.
 * They need at least Y points.
 * They have Z games remaining.
 * In each game, they can earn a maximum of 2 points (a win).
 * Therefore, the maximum additional points they can earn is 2 * Z.
 * The total points they can achieve is X + (2 * Z).
 * RCB qualifies if X + 2 * Z >= Y.
 */

int main() {
    // Fast I/O setup for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long x, y, z;
        cin >> x >> y >> z;
        
        // Calculate the maximum possible points RCB can reach
        long long max_possible_points = x + (2 * z);
        
        // Check if the target Y is reachable
        if (max_possible_points >= y) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
    
    return 0;
}
```