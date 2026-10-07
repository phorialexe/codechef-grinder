#include <iostream>
#include <algorithm>

using namespace std;

/**
 * Problem Analysis:
 * Alice needs her final score A' to satisfy A' >= B + 10.
 * Let D = max(0, B + 10 - A).
 * If D == 0, she needs 0 shots.
 * If D > 0, she wants to reach at least D points using the minimum number of shots.
 * Since each shot is worth 2 or 3 points, to minimize shots, she should prioritize 
 * 3-point shots. The number of shots required to get at least D points is ceil(D / 3).
 */

void solve() {
    int a, b;
    if (!(cin >> a >> b)) return;

    int target_diff = b + 10;
    int needed = target_diff - a;

    if (needed <= 0) {
        cout << 0 << endl;
    } else {
        // We need to cover 'needed' points using shots of 3 (or 2).
        // To minimize shots, we use as many 3s as possible.
        // ceil(needed / 3.0) is equivalent to (needed + 2) / 3 using integer division.
        int shots = (needed + 2) / 3;
        cout << shots << endl;
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