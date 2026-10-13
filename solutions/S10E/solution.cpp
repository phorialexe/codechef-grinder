#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * For each day i (1 to N), the price P[i] is "good" if P[i] < P[j] for all 
 * j in {i-5, i-4, i-3, i-2, i-1} such that j >= 1.
 * 
 * Constraints:
 * T <= 100, N <= 100.
 * Since N is small, an O(N^2) approach per test case is perfectly efficient.
 * Total complexity: O(T * N^2), which is ~10^6 operations, well within the 1s time limit.
 */

void solve() {
    int N;
    cin >> N;
    vector<int> P(N);
    for (int i = 0; i < N; ++i) {
        cin >> P[i];
    }

    int good_days = 0;

    for (int i = 0; i < N; ++i) {
        bool is_good = true;
        // Check the previous 5 days
        // The range of previous days is [max(0, i-5), i-1]
        int start = max(0, i - 5);
        for (int j = start; j < i; ++j) {
            if (P[i] >= P[j]) {
                is_good = false;
                break;
            }
        }
        
        if (is_good) {
            good_days++;
        }
    }

    cout << good_days << "\n";
}

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        solve();
    }
    return 0;
}