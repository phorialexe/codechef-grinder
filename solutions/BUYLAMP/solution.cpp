#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to buy exactly N lamps.
 * At least K must be red.
 * Red lamp cost = X, Blue lamp cost = Y.
 * 
 * To minimize cost:
 * 1. We must buy at least K red lamps. Since we want to minimize cost, 
 *    we should buy exactly K red lamps if X > Y. If X <= Y, we should 
 *    buy as many red lamps as possible (up to N) because they are cheaper 
 *    or equal in price.
 * 2. Actually, the logic is simpler:
 *    - We MUST buy K red lamps. This costs K * X.
 *    - We have (N - K) lamps remaining to buy.
 *    - To minimize the total cost, for each of the remaining (N - K) lamps,
 *      we should pick the cheaper option between red (X) and blue (Y).
 *    - Therefore, we pick min(X, Y) for the remaining (N - K) lamps.
 * 
 * Total Cost = (K * X) + ((N - K) * min(X, Y))
 * 
 * Constraints:
 * N <= 10^8, X, Y <= 10.
 * The result can be up to 10^8 * 10 = 10^9, which fits in a 32-bit signed integer,
 * but using long long is safer and good practice for competitive programming.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long n, k, x, y;
        cin >> n >> k >> x >> y;

        // Cost of the mandatory K red lamps
        long long cost = k * x;

        // Cost of the remaining (n - k) lamps
        // We choose the cheaper lamp for the remaining slots
        long long remaining_lamps = n - k;
        cost += remaining_lamps * min(x, y);

        cout << cost << "\n";
    }

    return 0;
}