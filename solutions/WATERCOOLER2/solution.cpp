#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to find the maximum integer M such that:
 * M * X < Y
 * 
 * Rearranging the inequality:
 * M < Y / X
 * 
 * Since M must be an integer, the maximum value is:
 * If Y is divisible by X, M = (Y / X) - 1
 * If Y is not divisible by X, M = floor(Y / X)
 * 
 * In both cases, if Y % X == 0, the result is (Y/X) - 1.
 * If Y % X != 0, the result is Y/X.
 * 
 * Edge case: If Y <= X, the cost of renting for 1 month is already >= Y,
 * so the answer is 0.
 * 
 * Constraints: X, Y up to 10^9. Calculations fit in long long.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long x, y;
        cin >> x >> y;

        if (y <= x) {
            cout << 0 << "\n";
        } else {
            if (y % x == 0) {
                cout << (y / x) - 1 << "\n";
            } else {
                cout << (y / x) << "\n";
            }
        }
    }

    return 0;
}