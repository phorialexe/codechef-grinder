#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Initial amount of ice cream: X
 * Melting rate per minute: Y
 * Time elapsed: N minutes
 * Total melted amount: Y * N
 * Remaining amount: X - (Y * N)
 * 
 * Constraint: If the ice cream melts completely, the amount left cannot be negative.
 * Therefore, the result is max(0, X - (Y * N)).
 * 
 * Constraints are small (up to 100), so standard int is sufficient, 
 * but using long long is good practice for competitive programming.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long x, y, n;
        cin >> x >> y >> n;

        // Calculate total melted ice cream
        long long melted = y * n;
        
        // Calculate remaining ice cream
        long long remaining = x - melted;
        
        // If remaining is negative, it means it all melted
        if (remaining < 0) {
            cout << 0 << "\n";
        } else {
            cout << remaining << "\n";
        }
    }

    return 0;
}