#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have N rounds.
 * Score logic:
 * - Round 1: Add X.
 * - Round i > 1: If previous roll was 1, add 2*X, else add X.
 * 
 * To maximize the score:
 * - We want to trigger the 2*X multiplier as often as possible.
 * - The multiplier is triggered if the previous roll was 1.
 * - If we roll a 1, the next roll gets a 2x multiplier. To maximize this, 
 *   we should roll a 6 immediately after a 1.
 * - Sequence pattern: 1, 6, 1, 6, 1, 6...
 * 
 * Case 1: N is even.
 * We can have N/2 pairs of (1, 6).
 * Each pair contributes: 1 + (2 * 6) = 13.
 * Total score = (N / 2) * 13.
 * 
 * Case 2: N is odd.
 * We can have (N-1)/2 pairs of (1, 6) and one final roll.
 * To maximize the final roll, we should end with a 6.
 * If we have (N-1)/2 pairs of (1, 6), the last roll was a 6.
 * The next roll (the N-th roll) will be added as X (since the previous was 6, not 1).
 * So we add 6.
 * Total score = ((N - 1) / 2) * 13 + 6.
 * 
 * Example N=2: (2/2)*13 = 13. Correct.
 * Example N=4: (4/2)*13 = 26. Correct.
 * Example N=1: ((1-1)/2)*13 + 6 = 6. Correct.
 * Example N=3: ((3-1)/2)*13 + 6 = 13 + 6 = 19.
 * Sequence: 1, 6, 6 -> 1 + 12 + 6 = 19.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        
        if (n % 2 == 0) {
            cout << (n / 2) * 13 << "\n";
        } else {
            cout << ((n - 1) / 2) * 13 + 6 << "\n";
        }
    }
    
    return 0;
}