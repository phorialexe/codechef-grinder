#include <iostream>

using namespace std;

/**
 * Problem Analysis:
 * A superincreasing array A satisfies A[i] > sum(A[1]...A[i-1]).
 * The smallest possible value for A[K] is 2^(K-1).
 * 
 * If K-1 >= 30, 2^(K-1) > 10^9. Since X <= 10^9, it is impossible for 
 * any superincreasing array to have A[K] = X if K > 30.
 */

void solve() {
    long long N, K, X;
    if (!(cin >> N >> K >> X)) return;

    // If K is large, 2^(K-1) will exceed the maximum value of X (10^9).
    // 2^29 = 536,870,912
    // 2^30 = 1,073,741,824 (which is > 10^9)
    // If K-1 >= 30, then 2^(K-1) > 10^9, so X cannot be >= 2^(K-1).
    if (K - 1 >= 30) {
        cout << "No" << "\n";
        return;
    }

    // Smallest possible value for A[K] is 2^(K-1)
    long long min_val = (1LL << (K - 1));

    if (X >= min_val) {
        cout << "Yes" << "\n";
    } else {
        cout << "No" << "\n";
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