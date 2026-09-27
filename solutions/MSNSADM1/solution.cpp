#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * For each player i, points = (A[i] * 20) - (B[i] * 10).
 * If points < 0, points = 0.
 * We need to find the maximum points among all players.
 * 
 * Constraints:
 * T <= 100, N <= 150.
 * A[i], B[i] <= 50.
 * Max possible points = 50 * 20 = 1000.
 * Min possible points = 0 (after adjustment).
 * Time complexity: O(T * N), which is well within the 1s limit.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        for (int i = 0; i < n; ++i) cin >> b[i];

        long long max_points = 0;
        for (int i = 0; i < n; ++i) {
            long long current_points = (long long)a[i] * 20 - (long long)b[i] * 10;
            if (current_points < 0) {
                current_points = 0;
            }
            if (current_points > max_points) {
                max_points = current_points;
            }
        }
        cout << max_points << "\n";
    }

    return 0;
}