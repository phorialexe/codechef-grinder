#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given two integers A and B (0 or 1).
 * 1. If A == 0: Output "https://www.codechef.com/practice"
 * 2. If A == 1 and B == 0: Output "https://www.codechef.com/contests"
 * 3. If A == 1 and B == 1: Output "https://discuss.codechef.com"
 * 
 * Time Complexity: O(1) per test case.
 * Space Complexity: O(1).
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int A, B;
    // The problem description implies a single test case per run based on the 
    // input format description, but we handle the logic as requested.
    if (cin >> A >> B) {
        if (A == 0) {
            cout << "https://www.codechef.com/practice" << "\n";
        } else if (A == 1 && B == 0) {
            cout << "https://www.codechef.com/contests" << "\n";
        } else if (A == 1 && B == 1) {
            cout << "https://discuss.codechef.com" << "\n";
        }
    }

    return 0;
}