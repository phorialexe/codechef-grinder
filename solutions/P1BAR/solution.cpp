#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Basketball Score
 * Logic: Total score = (X * 3) + (Y * 2)
 * Constraints: 1 <= X, Y <= 10.
 * Time Complexity: O(1) per test case.
 * Space Complexity: O(1).
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // The problem description implies a single test case per run based on the input format,
    // but standard competitive programming practice often involves handling multiple inputs.
    // Given the constraints and format, we read X and Y.
    long long X, Y;
    if (cin >> X >> Y) {
        long long total_score = (X * 3) + (Y * 2);
        cout << total_score << "\n";
    }

    return 0;
}