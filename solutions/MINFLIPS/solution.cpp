#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Let N be the number of elements.
 * Let P be the count of 1s and M be the count of -1s.
 * The current sum is S = P - M.
 * We want the final sum to be 0.
 * Let x be the number of 1s flipped to -1, and y be the number of -1s flipped to 1.
 * New sum = (P - x + y) - (M - y + x) = 0
 * P - M + 2y - 2x = 0
 * 2(y - x) = M - P
 * 
 * Since the total number of elements N = P + M, if N is odd, the sum can never be 0
 * because the sum of an odd number of 1s and -1s is always odd.
 * If N is even, we need the final count of 1s to be N/2 and -1s to be N/2.
 * 
 * If P > N/2, we need to flip (P - N/2) ones to -1s.
 * If M > N/2, we need to flip (M - N/2) negative ones to 1s.
 */

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int p = 0, m = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] == 1) p++;
        else m++;
    }

    // If N is odd, sum can never be 0
    if (n % 2 != 0) {
        cout << -1 << "\n";
        return;
    }

    // We need exactly n/2 ones and n/2 minus ones
    int target = n / 2;
    if (p > target) {
        cout << (p - target) << "\n";
    } else if (m > target) {
        cout << (m - target) << "\n";
    } else {
        cout << 0 << "\n";
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}