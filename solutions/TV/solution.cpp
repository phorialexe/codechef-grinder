#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given X channels numbered 1 to X.
 * Even-numbered channels stop working.
 * We need to count the number of odd-numbered channels in the range [1, X].
 * 
 * Logic:
 * If X is even, the number of odd channels is X / 2.
 * If X is odd, the number of odd channels is (X + 1) / 2.
 * This can be simplified using integer division: (X + 1) / 2.
 * 
 * Example:
 * X = 5: (5 + 1) / 2 = 3. (1, 3, 5) - Correct.
 * X = 100: (100 + 1) / 2 = 50. (1, 3, ..., 99) - Correct.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int X;
    if (!(cin >> X)) return 0;

    // The number of odd integers in the range [1, X] is ceil(X / 2.0)
    // Using integer arithmetic: (X + 1) / 2
    int working_channels = (X + 1) / 2;

    cout << working_channels << "\n";

    return 0;
}