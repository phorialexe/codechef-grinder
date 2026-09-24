#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef gets 1 gift free for every 4 gifts purchased.
 * This means for every group of 5 gifts, Chef pays for 4.
 * 
 * Let N be the total number of gifts required.
 * The number of full groups of 5 is (N / 5).
 * For each group of 5, Chef pays 4 coins.
 * The remaining gifts (N % 5) are paid for individually (1 coin each).
 * 
 * Total cost = (N / 5) * 4 + (N % 5)
 * 
 * Constraints:
 * N <= 10^9, so use long long to prevent overflow, although 
 * the result will fit in a standard 32-bit integer, long long is safer.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;

        long long groups = n / 5;
        long long remainder = n % 5;
        
        long long total_cost = (groups * 4) + remainder;
        
        cout << total_cost << "\n";
    }

    return 0;
}