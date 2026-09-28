#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef wants 5 medals of each type (Gold, Silver, Bronze).
 * Given current medals G, S, B:
 * Additional Gold needed = max(0, 5 - G)
 * Additional Silver needed = max(0, 5 - S)
 * Additional Bronze needed = max(0, 5 - B)
 * Total additional medals = (5 - G) + (5 - S) + (5 - B)
 * Since constraints are 1 <= G, S, B <= 5, the values (5 - G), (5 - S), (5 - B)
 * will always be non-negative.
 * Total = 15 - (G + S + B)
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int G, S, B;
    if (cin >> G >> S >> B) {
        int total_needed = (5 - G) + (5 - S) + (5 - B);
        cout << total_needed << "\n";
    }

    return 0;
}