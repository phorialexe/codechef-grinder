#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The total trade balance of a closed system of three countries (A, B, and C) must sum to zero.
 * Net Export of A = A1 - A2
 * Net Export of B = B1 - B2
 * Net Export of C = -(Net Export of A + Net Export of B)
 * 
 * A country is in trade surplus if its net export is strictly greater than 0.
 * Therefore, C is in trade surplus if:
 * -( (A1 - A2) + (B1 - B2) ) > 0
 * which simplifies to:
 * (A2 - A1) + (B2 - B1) > 0
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long a1, a2, b1, b2;
        cin >> a1 >> a2 >> b1 >> b2;

        // Net export of A: netA = a1 - a2
        // Net export of B: netB = b1 - b2
        // Since the sum of net exports in a closed system is 0:
        // netA + netB + netC = 0
        // netC = -(netA + netB)
        
        long long netA = a1 - a2;
        long long netB = b1 - b2;
        long long netC = -(netA + netB);

        if (netC > 0) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }

    return 0;
}