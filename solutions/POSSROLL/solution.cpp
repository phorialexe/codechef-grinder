#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The die has X sides, numbered with the first X positive multiples of K.
 * The faces are: 1*K, 2*K, 3*K, ..., X*K.
 * 
 * For a result Y to be possible:
 * 1. Y must be a multiple of K (i.e., Y % K == 0).
 * 2. The multiplier (Y / K) must be between 1 and X inclusive.
 * 
 * Constraints:
 * 1 <= X, K <= 10
 * 1 <= Y <= 100
 * These are small enough that standard integer types are sufficient.
 */

void solve() {
    long long X, K, Y;
    if (!(cin >> X >> K >> Y)) return;

    // Check if Y is a multiple of K
    if (Y % K == 0) {
        long long multiplier = Y / K;
        // Check if the multiplier is within the range [1, X]
        if (multiplier >= 1 && multiplier <= X) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    } else {
        cout << "NO" << "\n";
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // The problem description implies a single test case per run based on the input format,
    // but standard competitive programming practice often involves a test case count.
    // Given the problem description format, we handle the single input provided.
    solve();

    return 0;
}