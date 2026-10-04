#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * A stick of length X can be broken into two positive integers Y and Z such that Y + Z = X.
 * This is one break.
 * If we have a stick of length X, we can break it into (X-1) and 1.
 * Then we can break (X-1) into (X-2) and 1, and so on.
 * Effectively, a stick of length X can be broken into X sticks of length 1.
 * To get from 1 stick of length X to X sticks of length 1, we need exactly (X - 1) breaks.
 * 
 * Example:
 * Length 3:
 * Break 1: 3 -> 2 + 1
 * Break 2: 2 -> 1 + 1
 * Total breaks = 2. (Which is 3 - 1).
 * 
 * For N sticks with lengths A_1, A_2, ..., A_N, the total number of breaks is:
 * Sum of (A_i - 1) for all i where A_i > 1.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n;
        cin >> n;
        long long total_breaks = 0;
        for (int i = 0; i < n; ++i) {
            int a;
            cin >> a;
            // A stick of length 1 cannot be broken.
            // A stick of length A_i can be broken into A_i - 1 pieces.
            if (a > 1) {
                total_breaks += (a - 1);
            }
        }
        cout << total_breaks << "\n";
    }
    return 0;
}