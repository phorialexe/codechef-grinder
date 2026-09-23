#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The total number of points played is S = P + Q.
 * The service changes every 2 points.
 * - Points 0, 1: Alice serves (S/2 = 0)
 * - Points 2, 3: Bob serves (S/2 = 1)
 * - Points 4, 5: Alice serves (S/2 = 2)
 * - Points 6, 7: Bob serves (S/2 = 3)
 * 
 * We can observe that if (S / 2) is even, it is Alice's turn.
 * If (S / 2) is odd, it is Bob's turn.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long p, q;
        cin >> p >> q;
        
        long long total_points = p + q;
        long long turn_group = total_points / 2;
        
        if (turn_group % 2 == 0) {
            cout << "Alice" << "\n";
        } else {
            cout << "Bob" << "\n";
        }
    }
    
    return 0;
}