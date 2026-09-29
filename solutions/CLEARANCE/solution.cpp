#include <iostream>

using namespace std;

/**
 * Problem Analysis:
 * Chef pays for X t-shirts.
 * For every 2 t-shirts paid, he gets 1 free.
 * Number of free t-shirts = X / 2.
 * Total t-shirts = X + (X / 2).
 * 
 * Input Format:
 * The input contains a single even integer X.
 * There is no test case count (T) mentioned in the problem description.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long X;
    // Read the single integer X directly
    if (cin >> X) {
        // Calculation: Total = X + X/2
        // Since X is guaranteed to be even, X/2 is always an integer.
        long long total = X + (X / 2);
        
        cout << total << endl;
    }

    return 0;
}