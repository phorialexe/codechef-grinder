# [No Time to Wait (NOTIME)](https://www.codechef.com/problems/NOTIME)

- **Difficulty Rating**: 932
- **Solved in**: 2 attempt(s)

## Problem Summary
Chef needs a total of $H$ hours to solve a problem. Currently, he has $x$ hours remaining before the deadline. He can travel to any of the $N$ available time zones. Each time zone $i$ provides an additional $T_i$ hours. Chef succeeds if he can find at least one time zone such that his current time plus the time zone's offset is greater than or equal to the required hours ($x + T_i \geq H$).

## Intuition & Mathematical Observation
The problem asks whether there exists at least one $T_i$ in the given set such that:
$$x + T_i \geq H$$

This can be rearranged to:
$$T_i \geq H - x$$

We simply need to iterate through all $N$ time zones and check if any $T_i$ satisfies this condition. If we find such a $T_i$, the answer is "YES". If we check all $N$ time zones and none satisfy the condition, the answer is "NO".

## Complexity Analysis
- **Time Complexity**: $O(N)$, where $N$ is the number of time zones. We iterate through the list of time zones exactly once.
- **Space Complexity**: $O(1)$, as we only store a few integer variables and do not need to store the entire array of time zones.

## Solution Code

```cpp
#include <iostream>
#include <vector>

/**
 * Problem Analysis:
 * Chef needs H hours. He has x hours.
 * He can travel to a time zone T_i.
 * He succeeds if x + T_i >= H for any i.
 * 
 * Complexity: O(N) time, O(1) space.
 */

using namespace std;

void solve() {
    int N, H, x;
    if (!(cin >> N >> H >> x)) return;

    bool possible = false;
    for (int i = 0; i < N; ++i) {
        int T;
        cin >> T;
        // Check if the current time zone allows Chef to reach the goal
        if (x + T >= H) {
            possible = true;
        }
    }

    if (possible) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    // Standard competitive programming optimization for faster I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
```