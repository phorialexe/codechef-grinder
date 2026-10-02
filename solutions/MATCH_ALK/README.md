# [Man of the Match (MATCH_ALK)](https://www.codechef.com/problems/MATCH_ALK)

- **Difficulty Rating**: 825
- **Solved in**: 1 attempt(s)

## Problem Summary
In a cricket match, we are given the performance statistics for 22 players. Each player's performance is defined by the number of runs scored ($A$) and the number of wickets taken ($B$). The total points for a player are calculated using the formula:
$$\text{Points} = A + (B \times 20)$$
The objective is to identify the 1-based index of the player who achieved the highest total points.

## Intuition & Mathematical Observation
- The problem requires us to iterate through a fixed set of 22 inputs for each test case.
- Since we only need to find the maximum value and its corresponding index, we can maintain two variables: `max_points` (initialized to a very small value) and `man_of_the_match_index`.
- As we process each player, we calculate their points using the provided formula. If the calculated points exceed the current `max_points`, we update both the `max_points` and the `man_of_the_match_index`.
- Given the constraints ($A \le 200, B \le 10$), the maximum possible score is $200 + (10 \times 20) = 400$, which easily fits within a standard 32-bit integer.

## Complexity Analysis
- **Time Complexity**: $O(T \times N)$, where $T$ is the number of test cases and $N=22$ is the number of players. Since $N$ is constant, this simplifies to $O(T)$, which is highly efficient for the given constraints.
- **Space Complexity**: $O(1)$, as we only store a few integer variables regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given 22 players per test case.
 * Each player has runs (A) and wickets (B).
 * Points = A + (B * 20).
 * We need to find the index (1-based) of the player with the maximum points.
 * Constraints: T <= 1000, A <= 200, B <= 10.
 * Max points per player = 200 + (10 * 20) = 400.
 * Since 400 fits in a standard integer, 'int' is sufficient.
 * Time complexity: O(T * 22), which is well within the 1s limit.
 */

void solve() {
    int max_points = -1;
    int man_of_the_match_index = -1;

    for (int i = 1; i <= 22; ++i) {
        int runs, wickets;
        cin >> runs >> wickets;
        
        int current_points = runs + (wickets * 20);
        
        // Update if the current player has strictly more points
        if (current_points > max_points) {
            max_points = current_points;
            man_of_the_match_index = i;
        }
    }
    
    cout << man_of_the_match_index << "\n";
}

int main() {
    // Fast I/O setup for performance
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