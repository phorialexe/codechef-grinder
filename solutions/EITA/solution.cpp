#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Strategy 1: Work x units every day for 7 days.
 * Total work = x * 7
 * 
 * Strategy 2: Work y units for d days, and z units for (7 - d) days.
 * Total work = (y * d) + (z * (7 - d))
 * 
 * We need to output max(Strategy 1, Strategy 2).
 * Constraints are small (up to 18), so standard integer types are sufficient.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        int d, x, y, z;
        cin >> d >> x >> y >> z;
        
        // Strategy 1 calculation
        int strategy1 = x * 7;
        
        // Strategy 2 calculation
        int strategy2 = (y * d) + (z * (7 - d));
        
        // Output the maximum of the two strategies
        cout << max(strategy1, strategy2) << "\n";
    }
    
    return 0;
}