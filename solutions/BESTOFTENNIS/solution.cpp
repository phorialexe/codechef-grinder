#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The match ends at (X, Y) because the winner (let's say X > Y) has reached a point 
 * where the loser (Y) cannot catch up even if they win all remaining sets.
 * 
 * Let M = max(X, Y) and m = min(X, Y).
 * The total sets played is X + Y.
 * The winner is M. The loser is m.
 * 
 * For the match to stop at (M, m), it must be that:
 * 1. The winner has already secured the win.
 * 2. If the loser won all remaining sets (N - (X + Y)), they would still not reach M.
 *    So, m + (N - (X + Y)) < M.
 *    N - (X + Y) < M - m
 *    N < M + M - m
 *    N < 2*M - m
 * 
 * Also, the match must have continued until this point, meaning at the previous 
 * state (M-1, m), the loser could have potentially caught up.
 *    m + (N - (M - 1 + m)) >= M
 *    N - M + 1 - m >= M - m
 *    N >= 2*M - 1
 * 
 * Combining these, N must be the smallest odd integer such that N >= 2*M - 1.
 * Since 2*M - 1 is always odd (as 2*M is even), N = 2*max(X, Y) - 1.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long x, y;
        cin >> x >> y;
        
        long long m = max(x, y);
        // The formula derived is N = 2 * max(X, Y) - 1
        long long n = 2 * m - 1;
        
        cout << n << "\n";
    }
    
    return 0;
}