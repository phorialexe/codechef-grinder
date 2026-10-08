#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef can cover a maximum distance of (D * d) km in D days.
 * The categories are:
 * 10 km (Prize A)
 * 21 km (Prize B)
 * 42 km (Prize C)
 * 
 * We need to find the maximum prize based on the total distance covered:
 * - If total_dist >= 42, prize is C.
 * - Else if total_dist >= 21, prize is B.
 * - Else if total_dist >= 10, prize is A.
 * - Otherwise, prize is 0.
 * 
 * Constraints:
 * D <= 10, d <= 5, so max distance is 50.
 * A, B, C <= 10^5.
 * Time complexity per test case: O(1).
 * Space complexity: O(1).
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long D, d, A, B, C;
        cin >> D >> d >> A >> B >> C;

        long long total_dist = D * d;
        long long prize = 0;

        if (total_dist >= 42) {
            prize = C;
        } else if (total_dist >= 21) {
            prize = B;
        } else if (total_dist >= 10) {
            prize = A;
        } else {
            prize = 0;
        }

        cout << prize << "\n";
    }

    return 0;
}