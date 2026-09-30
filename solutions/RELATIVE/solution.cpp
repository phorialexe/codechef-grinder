#include <iostream>

using namespace std;

/**
 * Problem Analysis:
 * We are given the equation v^2 = 2 * g * H.
 * We need to find H such that v = c.
 * Substituting v = c:
 * c^2 = 2 * g * H
 * H = c^2 / (2 * g)
 * 
 * Constraints:
 * 1 <= T <= 5000
 * 1 <= g <= 10
 * 1000 <= c <= 3000
 * 2 * g divides c^2, so the result is always an integer.
 */

void solve() {
    long long g, c;
    if (!(cin >> g >> c)) return;
    
    // Calculate H = (c * c) / (2 * g)
    // Using long long to ensure no overflow occurs during c * c
    long long h = (c * c) / (2 * g);
    
    cout << h << "\n";
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