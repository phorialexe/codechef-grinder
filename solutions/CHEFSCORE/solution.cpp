#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef has N problems, each worth X marks.
 * Chef can get either 0 or X marks per problem.
 * Total score Y must be a multiple of X, and the number of problems 
 * required to get Y (which is Y/X) must not exceed the total number of problems N.
 * 
 * Conditions:
 * 1. Y must be divisible by X (Y % X == 0).
 * 2. The number of problems solved (Y / X) must be <= N.
 * 3. Special case: If Y == 0, it is always possible (by solving 0 problems).
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long n, x, y;
        cin >> n >> x >> y;

        // If Y is 0, Chef can always achieve this by solving 0 problems.
        if (y == 0) {
            cout << "YES" << "\n";
        } 
        // If Y is not 0, it must be a multiple of X, and the count of problems
        // (Y/X) must be less than or equal to N.
        else if (y % x == 0 && (y / x) <= n) {
            cout << "YES" << "\n";
        } 
        else {
            cout << "NO" << "\n";
        }
    }

    return 0;
}