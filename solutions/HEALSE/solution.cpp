#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Healthy Sleep
 * Logic:
 * - If H < 8, output LESS
 * - If H == 8, output PERFECT
 * - If H > 8, output MORE
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int H;
    // The problem description implies a single integer input per run.
    // If there were multiple test cases, we would use a loop.
    if (cin >> H) {
        if (H < 8) {
            cout << "LESS" << "\n";
        } else if (H == 8) {
            cout << "PERFECT" << "\n";
        } else {
            cout << "MORE" << "\n";
        }
    }

    return 0;
}