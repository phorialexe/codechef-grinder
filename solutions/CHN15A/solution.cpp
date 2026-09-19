#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Mutated Minions (CHN15A)
 * Approach:
 * For each minion with characteristic value 'v', the new value becomes 'v + K'.
 * We need to count how many minions satisfy (v + K) % 7 == 0.
 * 
 * Constraints:
 * T <= 100, N <= 100, K <= 100, v <= 10^5.
 * The values fit comfortably within standard integer types (int is sufficient).
 * Time Complexity: O(T * N), which is at most 10^4 operations, well within the 1s limit.
 * Space Complexity: O(1) auxiliary space if we process input on the fly.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;

    while (t--) {
        int n, k;
        cin >> n >> k;

        int wolverine_count = 0;
        for (int i = 0; i < n; ++i) {
            int v;
            cin >> v;
            // Check if the transmogrified value is divisible by 7
            if ((v + k) % 7 == 0) {
                wolverine_count++;
            }
        }

        cout << wolverine_count << "\n";
    }

    return 0;
}