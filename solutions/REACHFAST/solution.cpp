#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef is at A, Chefina is at B.
 * In one step, Chef can move at most K units.
 * The distance between them is |A - B|.
 * To minimize steps, Chef should always move K units towards B.
 * The number of steps required is ceil(|A - B| / K).
 * Using integer arithmetic, ceil(x / y) can be calculated as (x + y - 1) / y.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long a, b, k;
        cin >> a >> b >> k;

        // Calculate absolute distance
        long long dist = abs(a - b);

        // If distance is 0, 0 steps are needed
        if (dist == 0) {
            cout << 0 << "\n";
        } else {
            // Calculate ceil(dist / k)
            // Formula: (dist + k - 1) / k
            long long steps = (dist + k - 1) / k;
            cout << steps << "\n";
        }
    }

    return 0;
}