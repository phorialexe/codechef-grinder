#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given the previous record high temperature X and the current day's temperature Y.
 * A new record high is created if and only if the current temperature Y is strictly 
 * greater than the previous record X.
 * 
 * Constraints: 100 <= X, Y <= 150.
 * Time Complexity: O(1) per test case.
 * Space Complexity: O(1).
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int X, Y;
    // The problem description implies a single line of input per test case.
    // Reading X and Y.
    if (cin >> X >> Y) {
        // Check if Y is strictly greater than X
        if (Y > X) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }

    return 0;
}