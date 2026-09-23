#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * RCB currently has X points.
 * They need at least Y points.
 * They have Z games remaining.
 * In each game, they can earn a maximum of 2 points (a win).
 * Therefore, the maximum additional points they can earn is 2 * Z.
 * The total points they can achieve is X + (2 * Z).
 * RCB qualifies if X + 2 * Z >= Y.
 * 
 * Constraints:
 * T <= 5000
 * X, Y, Z <= 1000
 * The values fit within standard integer types, but using long long is safe.
 * Time complexity per test case: O(1)
 * Total time complexity: O(T)
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
        
        // Calculate the maximum possible points RCB can reach
        long long max_possible_points = x + (2 * z);
        
        // Check if the target Y is reachable
        if (max_possible_points >= y) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
    
    return 0;
}