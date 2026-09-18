#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Alice is happy if Bob <= 2 * Alice.
 * Bob is happy if Alice <= 2 * Bob.
 * Both are happy if (Bob <= 2 * Alice) AND (Alice <= 2 * Bob).
 * 
 * Constraints:
 * N <= 100, T <= 1000.
 * A_i, B_i <= 10^5.
 * The condition involves multiplication by 2, which fits within standard 32-bit integers,
 * but using long long is safe practice to prevent any potential overflow.
 * Time complexity per test case: O(N).
 * Total time complexity: O(T * N), which is 10^5 operations, well within the 1s limit.
 */

void solve() {
    int N;
    cin >> N;
    vector<long long> A(N), B(N);
    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int i = 0; i < N; ++i) cin >> B[i];

    int happy_days = 0;
    for (int i = 0; i < N; ++i) {
        // Alice is happy if B[i] <= 2 * A[i]
        // Bob is happy if A[i] <= 2 * B[i]
        if (B[i] <= 2 * A[i] && A[i] <= 2 * B[i]) {
            happy_days++;
        }
    }
    cout << happy_days << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}