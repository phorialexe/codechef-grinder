#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef has two trips of duration X and Y.
 * The total vacation duration is Z.
 * Chef can go on both trips if the sum of the durations of the two trips
 * is less than or equal to the total duration of the vacation.
 * Condition: X + Y <= Z
 * 
 * Constraints:
 * T <= 1000
 * X, Y, Z <= 1000
 * X + Y will be at most 2000, which fits in a standard integer.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long x, y, z;
        cin >> x >> y >> z;
        
        // Check if the sum of trip durations is within the vacation limit
        if (x + y <= z) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
    
    return 0;
}