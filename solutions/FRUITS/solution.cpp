#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have N apples and M oranges. We can perform at most K operations.
 * Each operation allows us to increase the count of the fruit that is smaller
 * by 1, effectively reducing the absolute difference |N - M|.
 * 
 * Strategy:
 * 1. Identify the smaller quantity and the larger quantity.
 * 2. The difference is diff = |N - M|.
 * 3. We can use up to K coins to close this gap.
 * 4. If K >= diff, we can make the counts equal (difference becomes 0).
 * 5. If K < diff, we can reduce the difference by K (difference becomes diff - K).
 * 
 * Time Complexity: O(T) where T is the number of test cases.
 * Space Complexity: O(1).
 */

void solve() {
    long long n, m, k;
    if (!(cin >> n >> m >> k)) return;

    // Ensure n is the smaller value for simplicity
    if (n > m) {
        swap(n, m);
    }

    // Now n <= m. The difference is m - n.
    // We can increase n by at most k.
    long long diff = m - n;

    if (k >= diff) {
        // We can make them equal or even swap the difference, 
        // but the minimum difference possible is 0.
        cout << 0 << "\n";
    } else {
        // We use all k coins to reduce the difference.
        cout << (diff - k) << "\n";
    }
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