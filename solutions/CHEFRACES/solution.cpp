#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef participates in two races: X and Y.
 * The rival participates in two races: A and B.
 * Chef can win a race if the rival is not participating in it.
 * We need to count how many of {X, Y} are not in {A, B}.
 * 
 * Logic:
 * Initialize count = 2.
 * If X == A or X == B, decrement count.
 * If Y == A or Y == B, decrement count.
 * The result is the remaining count.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int x, y, a, b;
        cin >> x >> y >> a >> b;

        int gold_medals = 2;

        // Check if Chef's first race is contested by the rival
        if (x == a || x == b) {
            gold_medals--;
        }

        // Check if Chef's second race is contested by the rival
        if (y == a || y == b) {
            gold_medals--;
        }

        cout << gold_medals << "\n";
    }

    return 0;
}