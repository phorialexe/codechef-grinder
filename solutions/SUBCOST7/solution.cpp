#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef subscribes for N months.
 * For the first 3 months, the cost is X per month.
 * For any month beyond the 3rd month, the cost is Y per month.
 * 
 * Logic:
 * If N <= 3:
 *    Total cost = N * X
 * If N > 3:
 *    Total cost = (3 * X) + ((N - 3) * Y)
 * 
 * Constraints:
 * 1 <= T <= 100
 * 1 <= N <= 50
 * 100 <= X < Y <= 500
 * Since N, X, and Y are small, the result will fit in a standard integer,
 * but using long long is good practice to prevent any potential overflow.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long n, x, y;
        cin >> n >> x >> y;

        long long total_cost = 0;
        if (n <= 3) {
            total_cost = n * x;
        } else {
            total_cost = (3 * x) + ((n - 3) * y);
        }

        cout << total_cost << "\n";
    }

    return 0;
}