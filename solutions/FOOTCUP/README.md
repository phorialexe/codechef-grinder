# [Football Cup (FOOTCUP)](https://www.codechef.com/problems/FOOTCUP)

- **Difficulty Rating**: 412
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef is a football enthusiast who only enjoys a match if two conditions are met:
1. The match ends in a draw (the number of goals scored by both teams, $X$ and $Y$, must be equal).
2. At least one goal has been scored in the match (i.e., $X > 0$ or $Y > 0$).

Given the scores $X$ and $Y$, determine if Chef will like the match.

## Intuition & Mathematical Observation
To satisfy both conditions:
* **Condition 1 (Draw):** $X$ must be equal to $Y$.
* **Condition 2 (Goals scored):** Since $X = Y$, if $X > 0$, then $Y$ is automatically $> 0$. If $X = 0$, then $Y$ is also $0$, which violates the second condition.

Therefore, the logic simplifies to checking if $X == Y$ **and** $X > 0$. If both are true, output `YES`; otherwise, output `NO`.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a constant number of comparisons, resulting in $O(1)$ per test case.
- **Space Complexity**: $O(1)$, as we only use a few integer variables regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef likes a match if:
 * 1. The match ends in a draw (X == Y).
 * 2. At least one goal has been scored (X > 0 or Y > 0).
 * 
 * Since X == Y, the second condition simplifies to X > 0 (or Y > 0).
 * If X == 0 and Y == 0, it is a draw, but no goals were scored, so Chef does not like it.
 * If X == Y and X > 0, both conditions are satisfied.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int x, y;
        cin >> x >> y;

        // Check if it's a draw and at least one goal was scored
        if (x == y && x > 0) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }

    return 0;
}
```