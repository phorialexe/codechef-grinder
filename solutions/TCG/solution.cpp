#include <iostream>

using namespace std;

/**
 * Problem: Capital Gain Tax
 * Logic: 
 * - If Y > X, the tax has INCREASED.
 * - If Y < X, the tax has DECREASED.
 * - If Y == X, the tax is the SAME.
 * 
 * Complexity:
 * Time: O(1)
 * Space: O(1)
 */

int main() {
    // Optimize standard I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int X, Y;
    if (!(cin >> X >> Y)) return 0;

    if (Y > X) {
        cout << "INCREASED" << endl;
    } else if (Y < X) {
        cout << "DECREASED" << endl;
    } else {
        cout << "SAME" << endl;
    }

    return 0;
}