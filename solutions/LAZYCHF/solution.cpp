#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef's work takes x units of time.
 * Due to laziness, he takes m * x units of time.
 * However, there is a delay limit d, meaning the maximum time he can take is x + d.
 * Therefore, the actual time taken is the minimum of (m * x) and (x + d).
 * 
 * Constraints:
 * 1 <= T <= 10^4
 * 1 <= x, m <= 10
 * 0 <= d < 100
 * 
 * Since the values are small, standard integers are sufficient, but using long long
 * is a safe practice in competitive programming to prevent overflow.
 */

int main() {
    // Fast I/O for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long x, m, d;
        cin >> x >> m >> d;

        // Calculate the time taken by laziness: m * x
        // Calculate the maximum allowed time: x + d
        // The result is the minimum of these two values.
        long long time_taken = min(m * x, x + d);

        cout << time_taken << "\n";
    }

    return 0;
}