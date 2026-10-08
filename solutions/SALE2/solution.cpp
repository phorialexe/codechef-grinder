#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * For every 3 items, Chef pays for 2 and gets 1 free.
 * This means in every group of 3 items, the cost is 2 * X.
 * If N items are needed:
 * - Number of full groups of 3 is (N / 3).
 * - Remaining items are (N % 3).
 * 
 * Total cost = (Number of groups * 2 * X) + (Remaining items * X)
 * 
 * Example 1: N=3, X=4
 * Groups = 3/3 = 1. Remainder = 0.
 * Cost = (1 * 2 * 4) + (0 * 4) = 8.
 * 
 * Example 2: N=4, X=2
 * Groups = 4/3 = 1. Remainder = 1.
 * Cost = (1 * 2 * 2) + (1 * 2) = 4 + 2 = 6.
 * 
 * Time Complexity: O(1) per test case.
 * Space Complexity: O(1).
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long n, x;
        cin >> n >> x;

        // Calculate number of full sets of 3
        long long sets = n / 3;
        long long remainder = n % 3;

        // Cost calculation
        // Each set of 3 costs 2 * X
        // Each remaining item costs X
        long long total_cost = (sets * 2 * x) + (remainder * x);

        cout << total_cost << "\n";
    }

    return 0;
}