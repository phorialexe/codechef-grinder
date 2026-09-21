#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The newspaper has 10 pages (1 to 10).
 * The last 3 pages are 8, 9, and 10.
 * We need to check if a given page X is in the set {8, 9, 10}.
 * This is equivalent to checking if X >= 8.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int X;
    // The problem description implies a single input X per run based on the format,
    // but standard competitive programming practice often involves handling 
    // input as specified. Given the constraints and description:
    if (cin >> X) {
        if (X >= 8 && X <= 10) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }

    return 0;
}