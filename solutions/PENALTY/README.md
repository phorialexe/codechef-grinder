# [Penalty Shots (PENALTY)](https://www.codechef.com/problems/PENALTY)

- **Difficulty Rating**: 925
- **Solved in**: 1 attempt(s)

## Problem Summary
In a penalty shootout, two teams take a total of 10 shots. Team 1 takes the 1st, 3rd, 5th, 7th, and 9th shots, while Team 2 takes the 2nd, 4th, 6th, 8th, and 10th shots. Given the outcomes of these 10 shots (where 1 represents a goal and 0 represents a miss), determine which team scored more goals. If Team 1 wins, output `1`; if Team 2 wins, output `2`; if it is a draw, output `0`.

## Intuition & Mathematical Observation
The problem provides a sequence of 10 integers. By observing the indices:
- **Team 1** shots occur at indices $0, 2, 4, 6, 8$ (0-indexed). These are all **even** indices.
- **Team 2** shots occur at indices $1, 3, 5, 7, 9$ (0-indexed). These are all **odd** indices.

We can maintain two separate counters, `team1_score` and `team2_score`. As we iterate through the 10 inputs, we use the modulo operator (`i % 2`) to determine which team the current shot belongs to and add the goal value to the respective counter. Finally, a simple comparison of the two sums determines the winner.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we always process exactly 10 inputs regardless of the input values.
- **Space Complexity**: $O(1)$, as we only use a few integer variables to store the scores and the loop index.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Penalty Shots
 * Approach:
 * We are given 10 integers representing the outcomes of penalty shots.
 * Team 1 takes shots at indices 0, 2, 4, 6, 8.
 * Team 2 takes shots at indices 1, 3, 5, 7, 9.
 * We sum the goals for each team and compare them.
 */

int main() {
    // Fast I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int team1_score = 0;
        int team2_score = 0;
        
        for (int i = 0; i < 10; ++i) {
            int goal;
            cin >> goal;
            // Even indices (0, 2, 4, 6, 8) are Team 1
            // Odd indices (1, 3, 5, 7, 9) are Team 2
            if (i % 2 == 0) {
                team1_score += goal;
            } else {
                team2_score += goal;
            }
        }

        if (team1_score > team2_score) {
            cout << 1 << "\n";
        } else if (team2_score > team1_score) {
            cout << 2 << "\n";
        } else {
            cout << 0 << "\n";
        }
    }

    return 0;
}
```