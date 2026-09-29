#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Chess Format
 * Logic:
 * Calculate sum = a + b.
 * Apply the conditional logic provided:
 * 1) Bullet if sum < 3
 * 2) Blitz if 3 <= sum <= 10
 * 3) Rapid if 11 <= sum <= 60
 * 4) Classical if sum > 60
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long a, b;
        cin >> a >> b;
        long long sum = a + b;
        
        if (sum < 3) {
            cout << 1 << "\n";
        } else if (sum >= 3 && sum <= 10) {
            cout << 2 << "\n";
        } else if (sum >= 11 && sum <= 60) {
            cout << 3 << "\n";
        } else {
            cout << 4 << "\n";
        }
    }
    
    return 0;
}