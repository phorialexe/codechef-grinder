#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Let the number of stones in box 1 be x and box 2 be y.
 * Total stones S = X + Y.
 * After some moves, let box 1 have x' stones and box 2 have y' stones.
 * x' + y' = S.
 * We want |x' - y'| = K.
 * Substituting y' = S - x', we get |x' - (S - x')| = |2x' - S| = K.
 * This implies 2x' - S = K or 2x' - S = -K.
 * 2x' = S + K or 2x' = S - K.
 * For x' to be an integer, (S + K) must be even, and 0 <= x' <= S.
 * 
 * Each move changes the number of stones in box 1 by +1 or -1.
 * The number of moves required is |x' - X|.
 * We want to minimize |x' - X| subject to the parity and range constraints.
 */

void solve() {
    long long X, Y, K;
    cin >> X >> Y >> K;
    long long S = X + Y;
    
    long long min_moves = -1;
    
    // Possible values for x' are (S+K)/2 and (S-K)/2
    // Check both candidates
    long long candidates[] = {(S + K) / 2, (S - K) / 2};
    
    for (long long x_prime : candidates) {
        // Check if x_prime is valid:
        // 1. 2*x_prime must equal S+K or S-K (parity check)
        // 2. 0 <= x_prime <= S
        if ((abs(2 * x_prime - S) == K) && (x_prime >= 0 && x_prime <= S)) {
            long long moves = abs(x_prime - X);
            if (min_moves == -1 || moves < min_moves) {
                min_moves = moves;
            }
        }
    }
    
    cout << min_moves << "\n";
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