#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The constraints are N <= 50 and the product of all elements is <= 10^9.
 * Since N is very small (up to 50), an O(N^2) approach is perfectly acceptable.
 * We can iterate over all possible subarrays [i, j] where 0 <= i <= j < N,
 * calculate their sum and product, and check if they are equal.
 * 
 * Given the product constraint (product <= 10^9), we can safely use 'long long'
 * to store the product to avoid overflow during intermediate calculations.
 */

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int count = 0;
    // Iterate over all possible starting positions of subarrays
    for (int i = 0; i < n; ++i) {
        long long current_sum = 0;
        long long current_prod = 1;
        
        // Iterate over all possible ending positions for the subarray starting at i
        for (int j = i; j < n; ++j) {
            current_sum += a[j];
            current_prod *= a[j];
            
            // Check if sum equals product
            if (current_sum == current_prod) {
                count++;
            }
            
            // Optimization: If product exceeds the maximum possible sum (which is N * max(Ai)),
            // we could potentially break, but given N=50 and product constraint,
            // the current approach is well within time limits.
        }
    }
    cout << count << "\n";
}

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}