#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Today is Monday (Day 1).
 * Tuesday is Day 2.
 * The sequence of Tuesdays occurs on days: 2, 9, 16, 23, ...
 * This is an arithmetic progression where the n-th Tuesday is at day: 2 + (n-1)*7.
 * We want to find how many Tuesdays occur in N days.
 * If N < 2, the answer is 0.
 * If N >= 2, the number of Tuesdays is the number of times we can fit a 7-day cycle 
 * starting from the first Tuesday (Day 2).
 * Mathematically, this is floor((N - 2) / 7) + 1.
 * Alternatively, simply (N - 1) / 7.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n;
        cin >> n;
        
        // If N < 2, Dracula gets 0 meals.
        // If N >= 2, the number of Tuesdays is (N - 2) / 7 + 1.
        // This simplifies to (N - 1) / 7 using integer division.
        if (n < 2) {
            cout << 0 << "\n";
        } else {
            cout << (n - 2) / 7 + 1 << "\n";
        }
    }

    return 0;
}