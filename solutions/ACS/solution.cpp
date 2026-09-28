#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * There are 10 problems total.
 * Each problem is worth either 1 or 100 points.
 * Let x be the number of problems worth 100 points.
 * Let y be the number of problems worth 1 point.
 * Total problems: x + y <= 10
 * Total score: 100*x + 1*y = P
 * 
 * From the equations:
 * y = P - 100*x
 * Since 0 <= y <= 10 - x:
 * 0 <= P - 100*x <= 10 - x
 * 
 * We can iterate through all possible values of x (0 to 10) 
 * to see if there exists a valid y.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int p;
        cin >> p;

        bool found = false;
        int total_problems = -1;

        // x is the number of 100-point problems
        // y is the number of 1-point problems
        // x + y <= 10
        // 100x + y = P
        
        for (int x = 0; x <= 10; ++x) {
            int y = p - (100 * x);
            if (y >= 0 && (x + y <= 10)) {
                found = true;
                total_problems = x + y;
                break;
            }
        }

        if (found) {
            cout << total_problems << "\n";
        } else {
            cout << -1 << "\n";
        }
    }

    return 0;
}