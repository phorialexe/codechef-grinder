#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * In one operation, we choose an integer d and perform:
 * (A + d, B - d) OR (A - d, B + d).
 * 
 * Let the new values be A' and B'.
 * A' + B' = (A + d) + (B - d) = A + B
 * A' + B' = (A - d) + (B + d) = A + B
 * 
 * The sum of A and B remains invariant under these operations.
 * If we want A' = B', then A' + B' = 2 * A'.
 * This implies that the sum (A + B) must be an even number for A' and B' to be equal.
 * 
 * If (A + B) is even, we can always reach the state where A = B.
 * For example, if A < B, we can choose d = (B - A) / 2.
 * Then A' = A + (B - A) / 2 = (A + B) / 2
 * And B' = B - (B - A) / 2 = (2B - B + A) / 2 = (A + B) / 2.
 * Since A + B is even, (B - A) is also even, so d is an integer.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long a, b;
        cin >> a >> b;

        // The sum must be even for the numbers to be equalized
        if ((a + b) % 2 == 0) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }

    return 0;
}