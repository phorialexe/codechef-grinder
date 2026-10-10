#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Total value = X * 1 + Y * 2 = X + 2Y.
 * For the coins to be distributed equally, the total value must be even.
 * Let the total value be S = X + 2Y.
 * If S is odd, it's impossible to split into two equal integer sums.
 * If S is even, we need to check if we can form S/2 using some combination of X and Y.
 * 
 * Case 1: X = 0.
 * If X = 0, we have only 2-rupee coins. We can split them equally if Y is even.
 * If Y is odd, we cannot split them equally (since we can't break a 2-rupee coin).
 * 
 * Case 2: X > 0.
 * If X > 0, we can use the 1-rupee coins to fill the gap if Y is odd.
 * Specifically, if X is at least 2, we can always balance the parity.
 * If X is 0 and Y is odd, we fail.
 * If X > 0 and (X + 2Y) is even, we can always distribute.
 */

void solve() {
    long long X, Y;
    cin >> X >> Y;

    // Total value must be even to be divisible by 2
    if ((X + 2 * Y) % 2 != 0) {
        cout << "NO" << "\n";
        return;
    }

    // If X is 0, we can only split if Y is even (so each gets Y/2 coins of value 2)
    if (X == 0) {
        if (Y % 2 == 0) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    } else {
        // If X > 0, as long as the total sum is even, we can distribute.
        // We have enough 1-rupee coins to handle the parity of Y.
        cout << "YES" << "\n";
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}