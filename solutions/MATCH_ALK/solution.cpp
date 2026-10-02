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
        
        if (current_points > max_points) {
            max_points = current_points;
            man_of_the_match_index = i;
        }
    }
    
    cout << man_of_the_match_index << "\n";
}

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}