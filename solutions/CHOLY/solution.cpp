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