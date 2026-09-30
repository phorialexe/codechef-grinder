#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef is at position K. A player at position P_i can capture Chef if K is a multiple of P_i.
 * That is, K % P_i == 0.
 * The number of moves taken by player i to reach K is K / P_i.
 * We want to minimize the number of moves (K / P_i), which is equivalent to 
 * maximizing P_i among all P_i that are divisors of K.
 * 
 * Constraints:
 * T <= 100
 * N <= 1,000
 * K <= 10^9
 * P_i <= 10^9
 * 
 * Time Complexity: O(T * N) per test case, which is 10^5 operations total.
 * This is well within the 1s time limit.
 */

void solve() {
    int N;
    long long K;
    cin >> N >> K;
    
    long long best_p = -1;
    long long min_moves = -1;
    
    for (int i = 0; i < N; ++i) {
        long long P;
        cin >> P;
        
        // Check if player can capture Chef
        if (K % P == 0) {
            long long moves = K / P;
            // We want the smallest number of moves.
            // If this is the first valid player found, or if this player
            // takes fewer moves than the current best, update.
            if (min_moves == -1 || moves < min_moves) {
                min_moves = moves;
                best_p = P;
            }
        }
    }
    
    cout << best_p << "\n";
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