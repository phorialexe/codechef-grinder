#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: BOWLBALL
 * The task is to count how many elements A_i in an array satisfy X <= A_i <= Y.
 * Constraints are small (N <= 100), so a simple linear scan O(N) per test case is optimal.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n, x, y;
        cin >> n >> x >> y;
        
        int count = 0;
        for (int i = 0; i < n; ++i) {
            int a;
            cin >> a;
            // Check if the bowling ball weight is within the inclusive range [X, Y]
            if (a >= x && a <= y) {
                count++;
            }
        }
        
        cout << count << "\n";
    }

    return 0;
}