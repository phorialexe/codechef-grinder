#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given A, B, C (2 <= A, B, C <= 100).
 * We need to find a positive integer K < 100 such that:
 * A % K != 0 AND B % K != 0 AND C % K != 0.
 * 
 * Since A, B, C are at most 100, and we need K < 100,
 * we can simply iterate through all integers K from 2 to 99.
 * For any given A, B, C, there will always be a K that does not divide any of them.
 * For example, any prime number greater than 100 would work, but since we are 
 * restricted to K < 100, we can check values starting from 99 downwards or 
 * simply iterate and pick the first one that satisfies the condition.
 */

void solve() {
    int A, B, C;
    cin >> A >> B >> C;

    // Iterate through possible values of K from 99 down to 2.
    // Given the constraints, a valid K will always exist.
    for (int k = 99; k >= 2; --k) {
        if (A % k != 0 && B % k != 0 && C % k != 0) {
            cout << k << "\n";
            return;
        }
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