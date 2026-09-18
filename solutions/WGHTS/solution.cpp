#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given a target weight W and three available weights X, Y, and Z.
 * We need to determine if W can be formed by any combination of X, Y, and Z.
 * Since we can use one or more weights, the possible combinations are:
 * 1. Single weights: X, Y, Z
 * 2. Pairs of weights: X+Y, X+Z, Y+Z
 * 3. All three weights: X+Y+Z
 * 
 * We simply check if W equals any of these 7 possible sums.
 * Time Complexity: O(1) per test case.
 * Space Complexity: O(1).
 */

void solve() {
    long long W, X, Y, Z;
    if (!(cin >> W >> X >> Y >> Z)) return;

    // Check all possible combinations
    if (W == X || W == Y || W == Z || 
        W == (X + Y) || W == (X + Z) || W == (Y + Z) || 
        W == (X + Y + Z)) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
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