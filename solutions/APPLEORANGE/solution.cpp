#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have N apples and M oranges. We need to distribute them equally among K contestants
 * such that no fruit is left over.
 * This means:
 * 1. N must be divisible by K (N % K == 0)
 * 2. M must be divisible by K (M % K == 0)
 * 
 * We want to find the maximum K that satisfies these conditions.
 * This is equivalent to finding the Greatest Common Divisor (GCD) of N and M.
 * 
 * Constraints:
 * N, M <= 10^9. The GCD of two numbers up to 10^9 fits in a standard 32-bit integer,
 * but using long long is safer and good practice in competitive programming.
 * Time complexity: O(log(min(N, M))) per test case, which is well within the 1s limit.
 */

long long gcd(long long a, long long b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long n, m;
        cin >> n >> m;
        
        // The maximum number of contestants is the GCD of N and M
        cout << gcd(n, m) << "\n";
    }

    return 0;
}