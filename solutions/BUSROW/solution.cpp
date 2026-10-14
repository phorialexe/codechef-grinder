#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The bus has N rows, each with M seats.
 * Seat X belongs to row R = ceil(X / M).
 * Using integer division, R = (X - 1) / M + 1.
 * 
 * If we enter from the front, we walk through rows 1, 2, ..., R.
 * The number of rows walked is R.
 * 
 * If we enter from the back, we walk through rows N, N-1, ..., R.
 * The number of rows walked is (N - R + 1).
 * 
 * We need to find the minimum of R and (N - R + 1).
 */

void solve() {
    long long N, M, X;
    if (!(cin >> N >> M >> X)) return;

    // Calculate the row number R (1-indexed)
    // Since X is 1-indexed, (X-1)/M gives the 0-indexed row number.
    long long R = (X - 1) / M + 1;

    // Distance from front: R
    // Distance from back: N - R + 1
    long long dist_front = R;
    long long dist_back = N - R + 1;

    cout << min(dist_front, dist_back) << "\n";
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