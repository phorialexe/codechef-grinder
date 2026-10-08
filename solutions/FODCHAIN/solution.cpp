#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given an initial energy E and a reduction factor K.
 * The energy at each subsequent level is floor(current_energy / K).
 * We need to find the number of levels that have non-zero energy.
 * 
 * Level 1: E
 * Level 2: floor(E / K)
 * Level 3: floor(floor(E / K) / K)
 * ... and so on.
 * 
 * Since E can be up to 10^9 and K is at least 2, the energy decreases 
 * exponentially. The number of levels will be logarithmic with respect to E, 
 * specifically O(log_K(E)). For E = 10^9 and K = 2, log2(10^9) is approx 30.
 * This is well within the time limit for 10^4 test cases.
 */

void solve() {
    long long E, K;
    if (!(cin >> E >> K)) return;
    
    int count = 0;
    while (E > 0) {
        count++;
        E = E / K;
    }
    cout << count << "\n";
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