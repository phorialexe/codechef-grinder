#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We want to maximize |Ax - Ay| + |Ay - Az| + |Az - Ax|.
 * Let the sorted values of the chosen triple be a <= b <= c.
 * The expression becomes (b - a) + (c - b) + (c - a) = 2c - 2a = 2(c - a).
 * To maximize this, we need to pick the smallest possible value in the array
 * as 'a' and the largest possible value in the array as 'c'.
 * The middle value 'b' can be any other element in the array.
 * Since N >= 3, we can always pick the minimum element, the maximum element,
 * and any third element.
 * The maximum value is 2 * (max_element - min_element).
 */

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    long long min_val = 2e9; // Larger than any possible A_i
    long long max_val = -2e9; // Smaller than any possible A_i

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] < min_val) min_val = a[i];
        if (a[i] > max_val) max_val = a[i];
    }

    // The expression simplifies to 2 * (max - min)
    // Proof: Let the chosen values be x, y, z.
    // If we pick min, max, and any other element, the expression is:
    // |max - min| + |min - other| + |other - max|
    // Since max >= other >= min:
    // (max - min) + (other - min) + (max - other)
    // = max - min + other - min + max - other
    // = 2 * max - 2 * min = 2 * (max - min)
    
    long long result = 2 * (max_val - min_val);
    cout << result << "\n";
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