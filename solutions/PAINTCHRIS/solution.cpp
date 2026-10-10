#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * 1. Each wall has dimensions X * Y.
 * 2. Area of one wall = X * Y (m^2).
 * 3. Cost per m^2 = 2 rupees.
 * 4. Cost to paint one wall = (X * Y) * 2.
 * 5. Total budget = Z.
 * 6. Maximum number of walls = floor(Z / cost_per_wall).
 * 
 * Constraints:
 * T <= 10^4, X, Y <= 10, Z <= 100.
 * The cost per wall will be at most 10 * 10 * 2 = 200.
 * Z is at most 100.
 * Integer division handles the floor operation automatically.
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
        
        // Calculate area of one wall
        long long area = x * y;
        
        // Calculate cost to paint one wall
        long long cost_per_wall = area * 2;
        
        // Calculate how many walls can be painted completely
        // If cost_per_wall is 0 (not possible by constraints), handle gracefully
        if (cost_per_wall == 0) {
            cout << 0 << "\n";
        } else {
            long long max_walls = z / cost_per_wall;
            cout << max_walls << "\n";
        }
    }
    
    return 0;
}