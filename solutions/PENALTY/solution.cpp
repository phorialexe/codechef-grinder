#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Penalty Shots
 * Approach:
 * We are given 10 integers representing the outcomes of penalty shots.
 * Team 1 takes shots at indices 1, 3, 5, 7, 9 (0-indexed: 0, 2, 4, 6, 8).
 * Team 2 takes shots at indices 2, 4, 6, 8, 10 (0-indexed: 1, 3, 5, 7, 9).
 * We sum the goals for each team and compare them.
 * Time Complexity: O(1) per test case.
 * Space Complexity: O(1).
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