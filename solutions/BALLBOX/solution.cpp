#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to distribute N balls into K boxes such that:
 * 1. Each box has >= 1 ball.
 * 2. No two boxes have the same number of balls.
 * 
 * To minimize the total number of balls required to satisfy these conditions,
 * we should pick the smallest possible distinct integers for the boxes:
 * 1, 2, 3, ..., K.
 * 
 * The sum of these balls is the sum of the first K natural numbers:
 * Sum = 1 + 2 + 3 + ... + K = K * (K + 1) / 2.
 * 
 * If N < K * (K + 1) / 2, it is impossible to satisfy the conditions because
 * even with the smallest possible distinct counts, we exceed N.
 * 
 * If N >= K * (K + 1) / 2, we can always satisfy the condition.
 * We start with the distribution {1, 2, ..., K}. The sum is K*(K+1)/2.
 * We have (N - K*(K+1)/2) extra balls remaining. We can add all these 
 * extra balls to the K-th box. Since the K-th box was already the largest 
 * (K), adding any non-negative amount to it will keep it the largest 
 * (or equal to the previous largest if the amount added was 0), 
 * and since we only add to the largest, the distinctness property is maintained.
 * 
 * Constraints:
 * N <= 10^9, K <= 10^4.
 * K * (K + 1) / 2 can be up to ~5 * 10^7, which fits in a standard 32-bit int,
 * but using long long is safer to prevent overflow during calculation.
 */

void solve() {
    long long N, K;
    cin >> N >> K;

    // The minimum number of balls required for K distinct boxes is 1+2+...+K
    // Using long long to prevent overflow during K*(K+1)
    long long min_balls = K * (K + 1) / 2;

    if (N >= min_balls) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}