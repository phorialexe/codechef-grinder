#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The perimeter of a rectangular park with length X and width Y is given by:
 * Perimeter = 2 * (X + Y)
 * Chef needs to run at least 1000 meters.
 * Therefore, we need to check if 2 * (X + Y) >= 1000.
 * 
 * Constraints:
 * 1 <= X, Y <= 1000
 * The maximum perimeter is 2 * (1000 + 1000) = 4000, which fits in a standard 32-bit integer.
 * Using long long is safe practice to prevent any potential overflow in more complex scenarios.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long X, Y;
    // The problem description implies a single test case per input based on the format,
    // but we handle the input as specified.
    if (cin >> X >> Y) {
        long long perimeter = 2 * (X + Y);
        
        if (perimeter >= 1000) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }

    return 0;
}