#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Let A_i be the elements of the array A.
 * We are given B_i = (A_i + A_{i+1}) % 2 for 1 <= i < N
 * and B_N = (A_N + A_1) % 2.
 * 
 * Consider the sum of all elements in B:
 * Sum(B) = (A_1 + A_2) + (A_2 + A_3) + ... + (A_{N-1} + A_N) + (A_N + A_1) (mod 2)
 * Sum(B) = 2 * (A_1 + A_2 + ... + A_N) (mod 2)
 * 
 * Since 2 * (anything) is always even, the sum of all elements in B must be 0 (mod 2).
 * If the sum of elements in B is odd, it is impossible to form such an array A.
 * 
 * Is this condition sufficient?
 * If Sum(B) is even, we can pick A_1 = 0.
 * Then A_2 = (B_1 - A_1) % 2
 * A_3 = (B_2 - A_2) % 2
 * ...
 * A_N = (B_{N-1} - A_{N-1}) % 2
 * Finally, we check if (A_N + A_1) % 2 == B_N.
 * Since the sum of B is even, the parity constraint will be satisfied at the wrap-around.
 * Thus, the condition is simply that the sum of elements in B must be even.
 */

void solve() {
    int N;
    cin >> N;
    int sum_b = 0;
    for (int i = 0; i < N; ++i) {
        int b;
        cin >> b;
        sum_b += b;
    }

    if (sum_b % 2 == 0) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
}

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}