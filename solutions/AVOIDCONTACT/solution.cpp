#include <iostream>

using namespace std;

/**
 * Problem Analysis:
 * - If Y = 0: All X people are healthy. They can sit in adjacent rooms. N = X.
 * - If Y > 0: 
 *   Each infected person needs to be isolated. 
 *   The pattern C _ C _ C uses 2Y - 1 rooms for Y infected people.
 *   If there are healthy people (X - Y > 0), we need an extra empty room 
 *   to separate the healthy block from the infected block.
 *   Total rooms = (2Y - 1) + 1 (buffer) + (X - Y) = X + Y.
 *   If X == Y, the formula X + Y gives 2Y, but we only need 2Y - 1.
 *   Wait, let's re-check:
 *   Sample 2: X=5, Y=3. Output 8. Formula X+Y = 8. Correct.
 *   Sample 3: X=3, Y=3. Output 5. Formula 2Y-1 = 5. Correct.
 */

void solve() {
    int X, Y;
    cin >> X >> Y;
    if (Y == 0) {
        cout << X << endl;
    } else if (X == Y) {
        cout << 2 * Y - 1 << endl;
    } else {
        cout << X + Y << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}