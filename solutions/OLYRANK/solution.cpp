#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Olympics Ranking
 * The problem asks us to compare the total number of medals (Gold + Silver + Bronze)
 * for two countries and output which country has a higher total.
 * 
 * Constraints:
 * T <= 1000
 * Medals <= 30
 * Total medals per country <= 90, which fits comfortably in a standard 'int'.
 * Time complexity per test case: O(1)
 * Space complexity per test case: O(1)
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;

    while (t--) {
        int g1, s1, b1, g2, s2, b2;
        cin >> g1 >> s1 >> b1 >> g2 >> s2 >> b2;

        // Calculate total medals for both countries
        int total1 = g1 + s1 + b1;
        int total2 = g2 + s2 + b2;

        // Compare totals and output the winner
        // The problem guarantees no ties.
        if (total1 > total2) {
            cout << "1" << "\n";
        } else {
            cout << "2" << "\n";
        }
    }

    return 0;
}