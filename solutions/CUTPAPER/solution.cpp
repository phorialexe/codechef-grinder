#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have a square paper of size N x N.
 * We want to cut out squares of size K x K.
 * Along one side of length N, we can fit floor(N / K) squares of length K.
 * Since the paper is a square, we can fit floor(N / K) squares along the width
 * and floor(N / K) squares along the height.
 * The total number of squares is (N / K) * (N / K).
 * 
 * Constraints:
 * 1 <= T <= 1000
 * 1 <= K <= N <= 1000
 * Since N is at most 1000, N*N is at most 1,000,000, which fits in a standard 32-bit integer.
 * However, using long long is safe practice.
 */

void solve() {
    long long N, K;
    if (!(cin >> N >> K)) return;
    
    // Calculate how many K-length segments fit into N
    long long side_count = N / K;
    
    // Total squares is side_count * side_count
    long long total_squares = side_count * side_count;
    
    cout << total_squares << "\n";
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