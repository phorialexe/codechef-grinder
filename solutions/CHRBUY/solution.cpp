#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have W wooden chairs (value 2 each) and P plastic chairs (value 1 each).
 * We need to pick exactly K chairs such that the total value is maximized.
 * 
 * Strategy:
 * Since wooden chairs have a higher value (2) than plastic chairs (1), 
 * we should prioritize picking as many wooden chairs as possible.
 * 
 * Let 'w' be the number of wooden chairs picked and 'p' be the number of plastic chairs picked.
 * We must satisfy:
 * 1. w + p = K
 * 2. 0 <= w <= W
 * 3. 0 <= p <= P
 * 
 * To maximize 2*w + 1*p:
 * We want 'w' to be as large as possible.
 * The maximum possible 'w' is min(K, W).
 * Once we pick w = min(K, W) wooden chairs, we must pick the remaining 
 * (K - w) chairs as plastic chairs.
 * Since K <= W + P, we are guaranteed that (K - w) <= P.
 * 
 * Complexity:
 * Time: O(1) per test case, O(T) total.
 * Space: O(1).
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long W, P, K;
        cin >> W >> P >> K;

        // Maximize wooden chairs first
        long long wooden_to_buy = min(K, W);
        long long plastic_to_buy = K - wooden_to_buy;

        // Calculate total stylishness
        long long stylishness = (wooden_to_buy * 2) + (plastic_to_buy * 1);

        cout << stylishness << "\n";
    }

    return 0;
}