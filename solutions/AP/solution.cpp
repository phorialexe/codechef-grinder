#include <iostream>

using namespace std;

/**
 * Problem Analysis:
 * An arithmetic progression (X, Y, Z) satisfies Y - X = Z - Y, 
 * which simplifies to 2 * Y = X + Z.
 * 
 * If 2 * Y == X + Z, 0 operations are needed.
 * Otherwise, we can change any one of the three numbers to satisfy the condition.
 * For example, we can always change X to (2 * Y - Z) or Z to (2 * Y - X).
 * Thus, the answer is either 0 or 1.
 */

void solve() {
    int x, y, z;
    if (!(cin >> x >> y >> z)) return;
    
    if (2 * y == x + z) {
        cout << 0 << "\n";
    } else {
        cout << 1 << "\n";
    }
}

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    
    return 0;
}