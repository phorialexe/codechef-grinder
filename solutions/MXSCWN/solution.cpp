#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

/**
 * Problem: MXSCWN
 * Strategy:
 * 1. Calculate the sum of all A_i.
 * 2. To satisfy the condition "lose at least once", we must pick exactly one index 'k'
 *    where we take B_k instead of A_k.
 * 3. The total coins will be (Sum of all A_i) - A_k + B_k.
 * 4. To maximize this, we need to minimize (A_k - B_k).
 * 5. Iterate through all i, find the minimum (A_i - B_i), and subtract it from the total sum.
 */

void solve() {
    int n;
    if (!(cin >> n)) return;
    
    vector<int> a(n), b(n);
    long long sum_a = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum_a += a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    long long min_diff = -1;
    for (int i = 0; i < n; ++i) {
        long long diff = (long long)a[i] - b[i];
        if (min_diff == -1 || diff < min_diff) {
            min_diff = diff;
        }
    }

    cout << sum_a - min_diff << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}