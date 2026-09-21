#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Puppy and Sum
 * The function sum(N) is the sum of integers from 1 to N, which is N * (N + 1) / 2.
 * The function sum(D, N) applies this operation D times.
 * Given the constraints D, N <= 4, the values will be very small and fit in standard integer types.
 * We can simulate the process D times.
 */

long long sum_n(long long n) {
    return n * (n + 1) / 2;
}

void solve() {
    int D;
    long long N;
    cin >> D >> N;
    
    long long current = N;
    for (int i = 0; i < D; ++i) {
        current = sum_n(current);
    }
    
    cout << current << "\n";
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