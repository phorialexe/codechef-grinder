#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: CHEFTRANS
 * The problem asks us to compare the time taken by two travel options:
 * Option 1 (Plane + Bus): X + Y minutes
 * Option 2 (Train): Z minutes
 * 
 * Constraints: X, Y, Z up to 10^9.
 * The sum X + Y can be up to 2 * 10^9, which fits within a standard 32-bit signed integer,
 * but using long long is safer and good practice in competitive programming to avoid overflow.
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
        
        long long plane_bus_time = x + y;
        long long train_time = z;
        
        if (plane_bus_time < train_time) {
            cout << "PLANEBUS" << "\n";
        } else if (train_time < plane_bus_time) {
            cout << "TRAIN" << "\n";
        } else {
            cout << "EQUAL" << "\n";
        }
    }
    
    return 0;
}