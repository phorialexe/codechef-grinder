#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have N cards in total.
 * X cards are face-up.
 * (N - X) cards are face-down.
 * 
 * To make all cards face-up, we must flip all (N - X) face-down cards.
 * To make all cards face-down, we must flip all X face-up cards.
 * 
 * The minimum number of operations is the minimum of these two values:
 * min(X, N - X).
 * 
 * Constraints:
 * T <= 5000, N <= 100.
 * The logic is O(1) per test case, total time complexity O(T).
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n, x;
        cin >> n >> x;

        // Option 1: Flip all face-up cards to make everything face-down.
        // Cost = x
        // Option 2: Flip all face-down cards to make everything face-up.
        // Cost = n - x
        
        int result = min(x, n - x);
        cout << result << "\n";
    }

    return 0;
}