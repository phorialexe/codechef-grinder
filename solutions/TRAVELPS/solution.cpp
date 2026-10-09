#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given a binary string S of length N.
 * '0' represents an inter-district travel requiring A minutes.
 * '1' represents an inter-state travel requiring B minutes.
 * We need to calculate the total time: (count of '0's * A) + (count of '1's * B).
 * 
 * Constraints:
 * T <= 100
 * N, A, B <= 100
 * Total time will not exceed 100 * 100 = 10,000, which fits in a standard int.
 * Time complexity: O(N) per test case.
 * Space complexity: O(N) to store the string.
 */

void solve() {
    int N, A, B;
    cin >> N >> A >> B;
    string S;
    cin >> S;

    long long total_time = 0;
    for (char c : S) {
        if (c == '0') {
            total_time += A;
        } else if (c == '1') {
            total_time += B;
        }
    }
    cout << total_time << "\n";
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