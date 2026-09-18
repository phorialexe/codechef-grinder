#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Total time required to complete assignments = X * Y (in minutes).
 * Total time available in Z days = Z * 24 * 60 (in minutes).
 * Chef can complete the assignments if (X * Y) <= (Z * 24 * 60).
 * 
 * Constraints:
 * X, Y <= 100
 * Z <= 10
 * Max required time = 100 * 100 = 10,000 minutes.
 * Max available time = 10 * 24 * 60 = 14,400 minutes.
 * Since these values fit well within a standard 32-bit integer, 
 * 'long long' is not strictly necessary but good practice for competitive programming.
 */

int main() {
    // Fast I/O for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long x, y, z;
        cin >> x >> y >> z;
        
        long long total_time_needed = x * y;
        long long total_time_available = z * 24 * 60;
        
        if (total_time_needed <= total_time_available) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
    
    return 0;
}