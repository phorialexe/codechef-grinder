#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Summer Time
 * Logic: Mamalesh drinks mango lassi if temperature X > 35.
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int X;
    if (!(cin >> X)) return 0;

    // Check if temperature is strictly greater than 35
    if (X > 35) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }

    return 0;
}