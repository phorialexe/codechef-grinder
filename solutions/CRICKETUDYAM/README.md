# [Cricket Tournament (CRICKETUDYAM)](https://www.codechef.com/problems/CRICKETUDYAM)

- **Difficulty Rating**: 669
- **Solved in**: 1 attempt(s)

## Problem Summary
In a knockout tournament involving $N$ teams, a match is played between two teams, and the loser is eliminated. This process continues until only one team remains (the winner). We are asked to determine if it is possible to have at least $M$ matches in such a tournament.

## Intuition & Mathematical Observation
In any single-elimination (knockout) tournament, every match results in exactly one team being eliminated. To crown a single winner from $N$ teams, we must eliminate exactly $N - 1$ teams. 

Since each match eliminates exactly one team, the total number of matches required to reach a winner is always exactly $N - 1$, regardless of the tournament bracket structure. Therefore, the condition for the tournament to be "interesting" (having at least $M$ matches) simplifies to checking if the total number of matches ($N - 1$) is greater than or equal to $M$.

**Condition:** $N - 1 \ge M$

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution involves a simple arithmetic comparison.
- **Space Complexity**: $O(1)$, as no extra data structures are used.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * In a knockout tournament with N teams, every match results in exactly one team being knocked out.
 * To declare a winner, we must knock out exactly N - 1 teams.
 * Since each match knocks out exactly one team, the total number of matches played 
 * in a knockout tournament is always exactly N - 1, regardless of how the matches are paired.
 * 
 * The problem asks if it is possible for the tournament to be "interesting", 
 * meaning at least M matches are played.
 * Since the number of matches is fixed at N - 1, the condition is:
 * Is N - 1 >= M?
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long n, m;
        cin >> n >> m;

        // The number of matches is always N - 1.
        // We need to check if N - 1 >= M.
        if (n - 1 >= m) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }

    return 0;
}
```