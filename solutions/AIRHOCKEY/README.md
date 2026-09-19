# [Air Hockey (AIRHOCKEY)](https://www.codechef.com/problems/AIRHOCKEY)

- **Difficulty Rating**: 366
- **Solved in**: 1 attempt(s)

## Problem Summary
In an air hockey game, the first player to reach 7 points wins. Given the current scores of Alice ($A$) and Bob ($B$), calculate the minimum number of additional points required for the game to end.

## Intuition & Mathematical Observation
The game concludes as soon as either Alice or Bob reaches a total of 7 points. 
- Alice currently has $A$ points, so she needs $7 - A$ more points to reach the winning threshold.
- Bob currently has $B$ points, so he needs $7 - B$ more points to reach the winning threshold.

Since the game ends when the *first* person reaches 7 points, we simply need to find the minimum of the points required by Alice and the points required by Bob.

**Formula:**
$$\text{Result} = \min(7 - A, 7 - B)$$

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case. Since there are $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few integer variables to store the scores and calculate the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The game ends when either Alice or Bob reaches 7 points.
 * Current scores are A and B.
 * Alice needs (7 - A) points to win.
 * Bob needs (7 - B) points to win.
 * The game ends as soon as the first person reaches 7 points.
 * Therefore, the minimum number of points required for the game to end is
 * the minimum of the points needed by Alice and the points needed by Bob.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int a, b;
        cin >> a >> b;
        
        int points_needed_alice = 7 - a;
        int points_needed_bob = 7 - b;
        
        // The game ends when the first person reaches 7 points.
        // We output the minimum points needed to reach that state.
        cout << min(points_needed_alice, points_needed_bob) << "\n";
    }
    
    return 0;
}
```