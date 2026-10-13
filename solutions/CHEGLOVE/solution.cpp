#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given N fingers with lengths L[i] and N sheaths with lengths G[i].
 * Front orientation: Finger i fits in sheath i if L[i] <= G[i] for all i.
 * Back orientation: Finger i fits in sheath (N-i+1) if L[i] <= G[N-i+1] for all i.
 * 
 * We need to check both conditions and output:
 * - "front" if only front works.
 * - "back" if only back works.
 * - "both" if both work.
 * - "none" if neither works.
 * 
 * Constraints:
 * N <= 10^5, T <= 10.
 * Finger/Sheath lengths up to 10^9.
 * Time complexity: O(N) per test case, which is well within the 1.5s limit.
 * Space complexity: O(N) to store the arrays.
 */

void solve() {
    int N;
    cin >> N;
    vector<long long> L(N), G(N);
    for (int i = 0; i < N; ++i) cin >> L[i];
    for (int i = 0; i < N; ++i) cin >> G[i];

    bool front = true;
    for (int i = 0; i < N; ++i) {
        if (L[i] > G[i]) {
            front = false;
            break;
        }
    }

    bool back = true;
    for (int i = 0; i < N; ++i) {
        // In back orientation, finger i (0-indexed) goes into sheath N-1-i
        if (L[i] > G[N - 1 - i]) {
            back = false;
            break;
        }
    }

    if (front && back) {
        cout << "both" << "\n";
    } else if (front) {
        cout << "front" << "\n";
    } else if (back) {
        cout << "back" << "\n";
    } else {
        cout << "none" << "\n";
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