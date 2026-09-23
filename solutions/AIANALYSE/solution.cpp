#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: AI Analysing Code
 * The feature is available if the code length C is at most 1000.
 * Constraints: 1 <= C <= 10000
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // The problem description implies a single integer input per run,
    // but we handle it robustly.
    long long C;
    if (cin >> C) {
        if (C <= 1000) {
            cout << "Yes" << "\n";
        } else {
            cout << "No" << "\n";
        }
    }

    return 0;
}