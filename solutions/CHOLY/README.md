# [Chess Olympiad (CHOLY)](https://www.codechef.com/problems/CHOLY)

- **Difficulty Rating**: 641
- **Solved in**: 1 attempt(s)

## Problem Summary
In a Chess Olympiad match, 4 games are played. We are given the current number of wins ($X$), draws ($Y$), and losses ($Z$) for our team. We need to determine if it is mathematically possible for our team to win the match (i.e., have a strictly higher total score than the opponent) if we win all of the remaining games. 

*Note: A win earns 1 point, a draw earns 0.5 points, and a loss earns 0 points.*

## Intuition & Mathematical Observation
1. **Scoring System**:
   - Our current score: $P_{us} = X \times 1 + Y \times 0.5$
   - Opponent's current score: $P_{opp} = Z \times 1 + Y \times 0.5$
2. **Remaining Games**:
   - Total games played so far: $X + Y + Z$.
   - Games remaining: $4 - (X + Y + Z)$.
3. **Winning Condition**:
   - To check if we *can* win, we assume we win all remaining games.
   - New score for us: $P_{final\_us} = P_{us} + (4 - (X + Y + Z))$.
   - New score for opponent: $P_{final\_opp} = P_{opp}$ (since they lose all remaining games).
   - We win the match if $P_{final\_us} > P_{final\_opp}$.

Since we are comparing values with 0.5, we can either use `double` or multiply everything by 2 to work with integers. The provided solution uses `double` for simplicity.

## Complexity Analysis
- **Time Complexity**: $O(1)$, as the solution involves a constant number of arithmetic operations regardless of the input values.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and calculated scores.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Each round consists of 4 games.
 * Current state: X wins, Y draws, Z losses.
 * Total games played = X + Y + Z.
 * Remaining games = 4 - (X + Y + Z).
 * 
 * Current points for our team: P_us = X * 1.0 + Y * 0.5
 * Current points for opponent: P_opp = Z * 1.0 + Y * 0.5
 * 
 * To maximize our chances, we assume we win all remaining games.
 * If we win all remaining games:
 * New P_us = P_us + (4 - (X + Y + Z))
 * New P_opp = P_opp
 * 
 * We win the round if New P_us > New P_opp.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int X, Y, Z;
    if (!(cin >> X >> Y >> Z)) return 0;

    // Calculate current points (using double to handle 0.5)
    double current_us = (double)X + (double)Y * 0.5;
    double current_opp = (double)Z + (double)Y * 0.5;

    // Number of remaining games
    int remaining = 4 - (X + Y + Z);

    // If we win all remaining games, our score increases by 'remaining'
    double final_us = current_us + (double)remaining;
    double final_opp = current_opp;

    // Check if strictly greater
    if (final_us > final_opp) {
        cout << "Yes" << "\n";
    } else {
        cout << "No" << "\n";
    }

    return 0;
}
```