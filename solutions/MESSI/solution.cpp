#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given two integers X and Y representing the number of fans of Leo and Ronald.
 * We need to determine which session to hold based on which group is larger.
 * Since X != Y is guaranteed, we simply compare X and Y.
 * If X > Y, output "FREEKICK".
 * If Y > X, output "PENALTY".
 * 
 * Constraints: 0 <= X, Y <= 100.
 * Time Complexity: O(1) per test case.
 * Space Complexity: O(1).
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // The problem description implies a single test case based on the format,
    // but standard competitive programming practice often involves handling 
    // multiple test cases if specified. Given the constraints and description,
    // we read X and Y directly.
    int X, Y;
    if (cin >> X >> Y) {
        if (X > Y) {
            cout << "FREEKICK" << "\n";
        } else {
            cout << "PENALTY" << "\n";
        }
    }

    return 0;
}