#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef's car efficiency: 15 km per 1 liter of petrol.
 * Total distance to cover: 2 * Y (to go and return).
 * Petrol available: X liters.
 * Maximum distance possible with X liters: X * 15 km.
 * Condition: Chef can attend if (X * 15) >= (2 * Y).
 * 
 * Constraints:
 * T <= 1000
 * X, Y <= 1000
 * X * 15 will be at most 15000, and 2 * Y will be at most 2000.
 * Standard 'int' is sufficient, but 'long long' is used for safety.
 */

int main() {
    // Optimize standard I/O operations for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long x, y;
        cin >> x >> y;
        
        // Total distance required is 2 * Y
        // Total distance possible is X * 15
        if (x * 15 >= 2 * y) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
    
    return 0;
}