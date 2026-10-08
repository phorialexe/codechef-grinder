#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have X and Y.
 * Operations: X = X + 1 or Y = Y + 2.
 * 
 * Case 1: X >= Y
 * Since we can only increase X by 1 or Y by 2, if X >= Y, we must increase Y
 * until it reaches X.
 * If (X - Y) is even, we can reach X by adding 2 to Y exactly (X - Y) / 2 times.
 * If (X - Y) is odd, we add 2 to Y until we are at (X - 1), then add 1 to X.
 * Actually, a simpler way to look at it:
 * If X >= Y:
 *   Difference = X - Y.
 *   If difference is even, we need (X - Y) / 2 operations (all Y = Y + 2).
 *   If difference is odd, we need (X - Y) / 2 + 2 operations.
 *   Wait, let's re-evaluate:
 *   If X >= Y:
 *   We need to reach a common value Z >= X.
 *   If we choose Z = X:
 *     If (X - Y) is even, we need (X - Y) / 2 operations (Y = Y + 2).
 *     If (X - Y) is odd, we need (X - Y + 1) / 2 operations (Y = Y + 2) + 1 operation (X = X + 1).
 *     Total = (X - Y + 1) / 2 + 1.
 * 
 * Case 2: X < Y
 *   We need to reach a common value Z >= Y.
 *   Since we can only increase X by 1, we just need (Y - X) operations of X = X + 1.
 */

void solve() {
    long long X, Y;
    cin >> X >> Y;

    if (X == Y) {
        cout << 0 << "\n";
    } else if (X > Y) {
        long long diff = X - Y;
        if (diff % 2 == 0) {
            cout << diff / 2 << "\n";
        } else {
            // Need to make Y reach X+1, so (X+1 - Y) / 2 operations for Y, 
            // plus 1 operation for X.
            cout << (diff / 2) + 2 << "\n";
        }
    } else {
        // X < Y
        // Simply increment X until it reaches Y
        cout << (Y - X) << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}