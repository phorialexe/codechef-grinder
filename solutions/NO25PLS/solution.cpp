#include <iostream>
#include <cmath>

using namespace std;

/**
 * Problem Analysis:
 * An integer M is "imperfect" if:
 * (M % 2 == 0 XOR M % 5 == 0)
 * 
 * Given N (1 <= N <= 100), we need to find min |N - M|.
 * Since the pattern of divisibility by 2 and 5 repeats every 10,
 * an imperfect number is guaranteed to be found within a very small distance.
 */

bool is_imperfect(int m) {
    if (m <= 0) return false;
    bool div2 = (m % 2 == 0);
    bool div5 = (m % 5 == 0);
    // XOR condition: divisible by 2 or 5, but not both.
    return (div2 != div5);
}

void solve() {
    int n;
    if (!(cin >> n)) return;
    
    // Check distance d starting from 0.
    // Since N >= 1, the closest imperfect number will be found almost immediately.
    for (int d = 0; d <= 1000; ++d) {
        // Check N - d (must be positive)
        if (n - d > 0 && is_imperfect(n - d)) {
            cout << d << "\n";
            return;
        }
        // Check N + d
        if (is_imperfect(n + d)) {
            cout << d << "\n";
            return;
        }
    }
}

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}