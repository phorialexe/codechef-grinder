#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The problem requires checking three conditions:
 * 1. x2 >= x1 (Problems solved)
 * 2. y2 >= y1 (Rating)
 * 3. z2 <= z1 (Last submission time)
 * 
 * If all three are true, output "YES", otherwise "NO".
 * Constraints are small (up to 5000 test cases), so O(1) per test case is optimal.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        int x1, x2, y1, y2, z1, z2;
        cin >> x1 >> x2 >> y1 >> y2 >> z1 >> z2;
        
        // Check the three criteria:
        // 1. Chef must have solved at least x1 problems (x2 >= x1)
        // 2. Chef must have at least y1 rating (y2 >= y1)
        // 3. Chef's last submission must be at most z1 months ago (z2 <= z1)
        
        if (x2 >= x1 && y2 >= y1 && z2 <= z1) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
    
    return 0;
}