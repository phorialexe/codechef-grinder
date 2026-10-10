#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Let N = 2^k * m, where m is the product of odd prime factors of N.
 * The divisors of N are of the form 2^a * d, where 0 <= a <= k and d is a divisor of m.
 * - An odd divisor occurs when a = 0. The number of odd divisors g(N) is the number of divisors of m.
 * - An even divisor occurs when 1 <= a <= k. The number of even divisors f(N) is k * (number of divisors of m).
 * 
 * Therefore:
 * f(N) = k * g(N)
 * 
 * Comparing f(N) and g(N):
 * - If k = 0 (N is odd), f(N) = 0, g(N) > 0. So f(N) < g(N) -> Output -1.
 * - If k = 1 (N is 2 * odd), f(N) = 1 * g(N) = g(N). So f(N) = g(N) -> Output 0.
 * - If k > 1 (N is divisible by 4), f(N) = k * g(N) > g(N). So f(N) > g(N) -> Output 1.
 */

void solve() {
    int N;
    cin >> N;

    if (N % 2 != 0) {
        // N is odd, k = 0
        cout << -1 << "\n";
    } else if (N % 4 != 0) {
        // N is even but not divisible by 4, k = 1
        cout << 0 << "\n";
    } else {
        // N is divisible by 4, k >= 2
        cout << 1 << "\n";
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