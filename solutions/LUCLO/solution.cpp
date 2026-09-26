#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef has N clovers.
 * Exactly one is a 4-leaf clover.
 * The remaining (N - 1) are 3-leaf clovers.
 * Total leaves = (1 * 4) + ((N - 1) * 3)
 * Total leaves = 4 + 3N - 3
 * Total leaves = 3N + 1
 * 
 * Constraints: 1 <= N <= 10.
 * The formula 3N + 1 works for N=1: 3(1) + 1 = 4.
 * The formula works for N=5: 3(5) + 1 = 16.
 * The formula works for N=10: 3(10) + 1 = 31.
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    // The problem description implies a single integer input N per run,
    // but standard competitive programming practice often involves reading
    // until EOF or a specific count. Given the problem format:
    if (cin >> N) {
        long long total_leaves = 3LL * N + 1;
        cout << total_leaves << "\n";
    }

    return 0;
}