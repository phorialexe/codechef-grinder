#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/**
 * Problem: RECTANGL
 * Logic: A rectangle is formed if the four sides can be paired into two equal sets.
 * By sorting the four sides, we simply check if the first two are equal 
 * and the last two are equal.
 * 
 * Complexity: O(T) time, O(1) space.
 */

void solve() {
    int sides[4];
    if (!(cin >> sides[0] >> sides[1] >> sides[2] >> sides[3])) return;

    // Sort the sides to easily compare pairs
    sort(sides, sides + 4);

    // Check if the two smallest are equal and the two largest are equal
    if (sides[0] == sides[1] && sides[2] == sides[3]) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
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