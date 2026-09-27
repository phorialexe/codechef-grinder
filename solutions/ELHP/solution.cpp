#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Election Hopes
 * Logic: Chef dominates if X >= 2 * Y.
 * Constraints: 1 <= X, Y <= 100.
 * Time Complexity: O(1) per test case.
 * Space Complexity: O(1).
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // The problem description implies a single test case based on the format,
    // but standard competitive programming practice often involves reading until EOF
    // or handling a specific number of test cases. Given the constraints and format:
    long long X, Y;
    if (cin >> X >> Y) {
        if (X >= 2 * Y) {
            cout << "Yes" << "\n";
        } else {
            cout << "No" << "\n";
        }
    }

    return 0;
}