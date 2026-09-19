#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The game ends when either Alice or Bob reaches 7 points.
 * Current scores are A and B.
 * Alice needs (7 - A) points to win.
 * Bob needs (7 - B) points to win.
 * The game ends as soon as the first person reaches 7 points.
 * Therefore, the minimum number of points required for the game to end is
 * the minimum of the points needed by Alice and the points needed by Bob.
 * 
 * Points needed by Alice = 7 - A
 * Points needed by Bob = 7 - B
 * Result = min(7 - A, 7 - B)
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int a, b;
        cin >> a >> b;
        
        int points_needed_alice = 7 - a;
        int points_needed_bob = 7 - b;
        
        // The game ends when the first person reaches 7 points.
        // We want the minimum points to reach that state.
        cout << min(points_needed_alice, points_needed_bob) << "\n";
    }
    
    return 0;
}