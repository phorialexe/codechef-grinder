#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Total number of people = N + 1 (Chef + N friends).
 * Each person can carry at most Y kg of gold.
 * Total capacity = (N + 1) * Y.
 * We need to check if total capacity >= X.
 * 
 * Constraints:
 * T <= 1000
 * N, X, Y <= 1000
 * The maximum possible capacity is (1000 + 1) * 1000 = 1,001,000.
 * This fits comfortably within a standard 32-bit signed integer (int),
 * but using long long is safer practice in competitive programming to prevent overflow.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long n, x, y;
        cin >> n >> x >> y;
        
        // Total capacity is (number of people) * (capacity per person)
        long long total_capacity = (n + 1) * y;
        
        if (total_capacity >= x) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
    
    return 0;
}