#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Pep Bidding
 * Approach:
 * 1. Calculate the total attack power and total defense power for both Team A and Team P.
 * 2. Since N <= 2000 and values are <= 1000, the maximum sum is 2,000,000.
 *    This fits within a standard 32-bit integer, but using long long is safer practice.
 * 3. Compare the sums:
 *    - If (attA > attP) AND (defA > defP), Team A wins.
 *    - If (attP > attA) AND (defP > defA), Team P wins.
 *    - Otherwise, it's a DRAW.
 * 4. Time Complexity: O(N) per test case, O(sum of N) total.
 * 5. Space Complexity: O(1) if we sum values on the fly, or O(N) if we store arrays.
 */

void solve() {
    int N;
    cin >> N;

    long long attA = 0, defA = 0, attP = 0, defP = 0;
    long long val;

    for (int i = 0; i < N; ++i) { cin >> val; attA += val; }
    for (int i = 0; i < N; ++i) { cin >> val; defA += val; }
    for (int i = 0; i < N; ++i) { cin >> val; attP += val; }
    for (int i = 0; i < N; ++i) { cin >> val; defP += val; }

    bool aWins = (attA > attP) && (defA > defP);
    bool pWins = (attP > attA) && (defP > defA);

    if (aWins) {
        cout << "A" << "\n";
    } else if (pWins) {
        cout << "P" << "\n";
    } else {
        cout << "DRAW" << "\n";
    }
}

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}