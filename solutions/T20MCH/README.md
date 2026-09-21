# [Possible Victory (T20MCH)](https://www.codechef.com/problems/T20MCH)

- **Difficulty Rating**: 769
- **Solved in**: 1 attempt(s)

## Problem Summary
Team A has finished their innings with a total score of $R$ runs. Team B is currently batting and has played $O$ overs, scoring $C$ runs so far. In a T20 match, there are a total of 20 overs. We need to determine if it is mathematically possible for Team B to score more than $R$ runs by the end of their 20 overs.

## Intuition & Mathematical Observation
To determine if Team B can win, we must calculate the maximum possible score they can achieve in the remaining overs:

1.  **Remaining Overs**: Since a T20 match consists of 20 overs, the number of overs left for Team B is $20 - O$.
2.  **Maximum Runs per Over**: In each over, there are 6 balls. The maximum runs that can be scored on a single ball is 6 (a six). Therefore, the maximum runs possible in one over is $6 \times 6 = 36$.
3.  **Maximum Additional Runs**: The maximum runs Team B can score in the remaining overs is $(20 - O) \times 36$.
4.  **Total Potential Score**: The maximum total score Team B can reach is $C + ((20 - O) \times 36)$.
5.  **Condition**: Team B wins if their maximum potential score is strictly greater than Team A's score $R$.

## Complexity Analysis
- **Time Complexity**: $O(1)$, as the solution involves a constant number of arithmetic operations regardless of the input values.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and intermediate calculations.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Team A scored R runs.
 * Team B has played O overs and scored C runs.
 * Remaining overs = 20 - O.
 * In each over, there are 6 balls, and each ball can score a maximum of 6 runs.
 * Maximum runs per over = 6 * 6 = 36.
 * Maximum runs possible in remaining overs = (20 - O) * 36.
 * Maximum total score for Team B = C + (20 - O) * 36.
 * Team B wins if (Maximum total score) > R.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long R, O, C;
    if (!(cin >> R >> O >> C)) return 0;

    // Calculate remaining overs and the maximum possible runs
    long long remaining_overs = 20 - O;
    long long max_additional_runs = remaining_overs * 36;
    long long max_total_score = C + max_additional_runs;

    // Check if the maximum potential score exceeds Team A's score
    if (max_total_score > R) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }

    return 0;
}
```