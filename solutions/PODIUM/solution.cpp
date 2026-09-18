#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef is in 3rd place.
 * Gap between Chef (3rd) and Runner-up (2nd) = A
 * Gap between Runner-up (2nd) and Winner (1st) = B
 * Total gap between Chef (3rd) and Winner (1st) = A + B
 * 
 * Constraints:
 * T <= 100
 * 1 <= A, B <= 10
 * The sum will be at most 20, which fits easily into a standard integer.
 */

int main() {
    // Fast I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long a, b;
        if (cin >> a >> b) {
            // The time gap between Chef and the winner is the sum of the gaps
            cout << (a + b) << "\n";
        }
    }

    return 0;
}