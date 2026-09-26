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
 * 
 * Constraints:
 * 1 <= N, M <= 100
 * Time Complexity: O(1) per test case.
 * Space Complexity: O(1).
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