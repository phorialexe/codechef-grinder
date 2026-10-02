#include <iostream>

using namespace std;

/**
 * Problem Analysis:
 * The frog starts at position N.
 * For i = 1 to N-1:
 *   If i is odd: current_pos -= (N - i)
 *   If i is even: current_pos += (N - i)
 * 
 * Example N=5:
 * Start: 5
 * i=1 (odd): 5 - (5-1) = 5 - 4 = 1
 * i=2 (even): 1 + (5-2) = 1 + 3 = 4
 * i=3 (odd): 4 - (5-3) = 4 - 2 = 2
 * i=4 (even): 2 + (5-4) = 2 + 1 = 3
 * Final: 3
 */

void solve() {
    int N;
    if (!(cin >> N)) return;

    int current_pos = N;
    for (int i = 1; i < N; ++i) {
        if (i % 2 != 0) {
            // Odd jump: left
            current_pos -= (N - i);
        } else {
            // Even jump: right
            current_pos += (N - i);
        }
    }
    cout << current_pos << "\n";
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