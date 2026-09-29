#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Each over consists of 6 balls.
 * Maximum runs per ball is 6.
 * Therefore, maximum runs per over = 6 * 6 = 36.
 * Total maximum runs possible in M overs = M * 36.
 * 
 * Chef's team can win if the required runs N <= (M * 36).
 * 
 * Constraints:
 * N <= 1000, M <= 100.
 * M * 36 = 3600, which fits comfortably in a standard integer.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long n, m;
        cin >> n >> m;
        
        // Calculate maximum possible runs in M overs
        long long max_runs = m * 6 * 6;
        
        // Check if required runs are achievable
        if (n <= max_runs) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
    
    return 0;
}