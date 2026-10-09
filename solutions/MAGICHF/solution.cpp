#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given N boxes, a starting position X of a coin, and S swaps.
 * Since we only care about the position of the coin, we don't need to track
 * all N boxes. We only need to update the current position of the coin
 * whenever one of the swapped boxes is the current position of the coin.
 * 
 * Time Complexity: O(S) per test case, where S is the number of swaps.
 * Total time complexity: O(sum of S), which is 2*10^5, well within the 0.5s limit.
 * Space Complexity: O(1) auxiliary space.
 */

void solve() {
    int N, X, S;
    if (!(cin >> N >> X >> S)) return;

    int current_pos = X;
    for (int i = 0; i < S; ++i) {
        int A, B;
        cin >> A >> B;
        
        // If the coin is in one of the swapped boxes, update its position
        if (current_pos == A) {
            current_pos = B;
        } else if (current_pos == B) {
            current_pos = A;
        }
        // If the coin is in neither, its position remains unchanged
    }
    
    cout << current_pos << "\n";
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