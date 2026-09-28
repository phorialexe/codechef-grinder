#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We want to maximize the sum of squares N_i^2 subject to:
 * 1. 1 <= T <= maxT
 * 2. 1 <= N_i <= maxN
 * 3. Sum of N_i <= sumN
 * 
 * To maximize the sum of squares, we want the values of N_i to be as large as possible.
 * Since N^2 is a convex function, we should make as many N_i as possible equal to 
 * the maximum allowed value (maxN), and then put the remainder in one last N_i.
 * 
 * We are limited by two constraints:
 * 1. We can have at most maxT test cases.
 * 2. The sum of N_i cannot exceed sumN.
 * 
 * Strategy:
 * - We can have at most 'maxT' values.
 * - We want each value to be as close to 'maxN' as possible.
 * - Let 'count = sumN / maxN'.
 * - If count >= maxT, we can have 'maxT' test cases, each with value 'maxN'.
 * - If count < maxT, we can have 'count' test cases with value 'maxN', 
 *   and one additional test case with value 'sumN % maxN' (if the remainder > 0).
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long maxT, maxN, sumN;
        cin >> maxT >> maxN >> sumN;

        long long full_blocks = sumN / maxN;
        long long remainder = sumN % maxN;

        long long ans = 0;
        if (full_blocks >= maxT) {
            // We can fill all maxT slots with maxN
            ans = maxT * (maxN * maxN);
        } else {
            // We use 'full_blocks' slots with maxN, and one slot with 'remainder'
            ans = full_blocks * (maxN * maxN);
            if (remainder > 0) {
                ans += (remainder * remainder);
            }
        }

        cout << ans << "\n";
    }

    return 0;
}