#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The equation is: X^4 + 4 * Y^2 = 4 * X^2 * Y
 * Rearranging the terms:
 * X^4 - 4 * X^2 * Y + 4 * Y^2 = 0
 * This is a perfect square trinomial of the form a^2 - 2ab + b^2 = 0,
 * where a = X^2 and b = 2Y.
 * (X^2)^2 - 2 * (X^2) * (2Y) + (2Y)^2 = 0
 * (X^2 - 2Y)^2 = 0
 * 
 * This implies X^2 - 2Y = 0, or X^2 = 2Y.
 * 
 * Given constraints:
 * X <= 10^9, Y <= 10^18.
 * X^2 can be up to 10^18, and 2Y can be up to 2 * 10^18.
 * Both fit within a 64-bit signed integer (long long in C++).
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long x, y;
        cin >> x >> y;

        // Check if X^2 == 2 * Y
        // Using long long to prevent overflow as X^2 <= 10^18 and 2Y <= 2*10^18
        if (x * x == 2 * y) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }

    return 0;
}