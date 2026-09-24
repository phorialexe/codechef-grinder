#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * - N students, each has a time window to cook.
 * - Student 1: starts at 0, must finish by A1. Duration available: A1 - 0.
 * - Student i (i > 1): starts at A_{i-1}, must finish by A_i. Duration available: A_i - A_{i-1}.
 * - Student i needs B_i time.
 * - Condition to succeed: B_i <= (A_i - A_{i-1}) for i > 1, and B_1 <= A_1.
 * 
 * Constraints:
 * - T <= 10, N <= 10^4.
 * - A_i, B_i up to 10^9. Use long long to prevent overflow during calculations, 
 *   though A_i - A_{i-1} fits in a standard 32-bit signed integer, 
 *   using long long is safer for competitive programming.
 */

void solve() {
    int N;
    if (!(cin >> N)) return;

    vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    vector<long long> B(N);
    for (int i = 0; i < N; ++i) {
        cin >> B[i];
    }

    int count = 0;
    long long prev_time = 0;

    for (int i = 0; i < N; ++i) {
        long long available_time = A[i] - prev_time;
        if (B[i] <= available_time) {
            count++;
        }
        prev_time = A[i];
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