#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * N is a power of 2. In a single-elimination tournament, if there are N teams,
 * the number of rounds required to determine a winner is log2(N).
 * 
 * Let R = log2(N).
 * Each round takes A minutes.
 * There is a break of B minutes between every two rounds.
 * Total rounds = R.
 * Total round time = R * A.
 * Total break time = (R - 1) * B (since there is no break after the last round).
 * Total time = (R * A) + ((R - 1) * B).
 * 
 * Constraints:
 * T <= 10^5, N <= 2^20.
 * log2(2^20) = 20.
 * Calculations will easily fit in standard integer types, but using long long
 * is safe practice for competitive programming.
 */

void solve() {
    long long N, A, B;
    if (!(cin >> N >> A >> B)) return;

    // Calculate number of rounds R such that 2^R = N
    // Since N is a power of 2, we can use log2 or a simple loop/builtin
    int R = 0;
    long long tempN = N;
    while (tempN > 1) {
        tempN >>= 1;
        R++;
    }

    // Total time = (R * A) + ((R - 1) * B)
    long long total_time = (R * A) + ((R - 1) * B);
    cout << total_time << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}