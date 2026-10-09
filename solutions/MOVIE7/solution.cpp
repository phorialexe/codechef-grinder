#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to buy N tickets and M buckets of popcorn.
 * Prices:
 * - Ticket: A
 * - Popcorn: B
 * - Combo (1 Ticket + 1 Popcorn): C
 * 
 * Since C < A + B, it is always optimal to use as many combos as possible.
 * The maximum number of combos we can form is min(N, M).
 * Let k = min(N, M).
 * We buy k combos at price C.
 * Remaining items:
 * - If N > M, we have (N - M) tickets left to buy at price A.
 * - If M > N, we have (M - N) buckets of popcorn left to buy at price B.
 * - If N == M, we have 0 items left.
 * 
 * Total cost = (k * C) + ((N - k) * A) + ((M - k) * B)
 */

void solve() {
    long long N, M, A, B, C;
    if (!(cin >> N >> M >> A >> B >> C)) return;

    long long k = min(N, M);
    long long total_cost = (k * C) + ((N - k) * A) + ((M - k) * B);
    
    cout << total_cost << "\n";
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