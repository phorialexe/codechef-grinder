#include <iostream>
#include <vector>

using namespace std;

/**
 * Problem Analysis:
 * Chef can only walk in steps of length K.
 * A distance D_i is traversable if D_i is a multiple of K.
 * Mathematically: D_i % K == 0.
 * 
 * Constraints:
 * T <= 1000, N <= 1000. Total operations ~ 10^6, which fits in 1s.
 * D_i and K can be up to 10^9, so use long long for calculations.
 */

void solve() {
    int n;
    long long k;
    if (!(cin >> n >> k)) return;
    
    for (int i = 0; i < n; ++i) {
        long long d;
        cin >> d;
        if (d % k == 0) {
            cout << '1';
        } else {
            cout << '0';
        }
    }
    cout << "\n";
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