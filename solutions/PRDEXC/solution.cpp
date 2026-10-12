#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given X, Y, and P. We want to reach X' * Y' >= P where X' >= X and Y' >= Y.
 * The total number of moves is (X' - X) + (Y' - Y).
 * Since the constraints are very small (X, Y <= 50, P <= 10000), we can use a 
 * Breadth-First Search (BFS) or simply iterate through all possible number of moves.
 * 
 * Given the constraints, the maximum possible moves needed won't be very large.
 * Even if X=1, Y=1, P=10000, we need X*Y >= 10000. 
 * If we increment X and Y equally, roughly (X+k)(Y+k) = P.
 * With X, Y <= 50, the search space is small enough to brute force the number of moves.
 */

void solve() {
    long long X, Y, P;
    cin >> X >> Y >> P;

    if (X * Y >= P) {
        cout << 0 << "\n";
        return;
    }

    // Since we want the minimum moves, we can iterate on the total number of moves 'm'.
    // For a fixed 'm', we want to maximize the product (X+i) * (Y + (m-i))
    // where 0 <= i <= m.
    // The product of two numbers with a constant sum is maximized when they are closest to each other.
    
    for (int m = 1; ; ++m) {
        bool possible = false;
        for (int i = 0; i <= m; ++i) {
            long long curX = X + i;
            long long curY = Y + (m - i);
            if (curX * curY >= P) {
                possible = true;
                break;
            }
        }
        if (possible) {
            cout << m << "\n";
            return;
        }
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}