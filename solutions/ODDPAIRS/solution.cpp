#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to find the number of pairs (A, B) such that 1 <= A, B <= N and A + B is odd.
 * A + B is odd if and only if one of the numbers is even and the other is odd.
 * 
 * In the range [1, N]:
 * - Number of odd integers (count_odd) = ceil(N / 2) = (N + 1) / 2
 * - Number of even integers (count_even) = floor(N / 2) = N / 2
 * 
 * A pair (A, B) has an odd sum if:
 * 1. A is odd and B is even: count_odd * count_even ways
 * 2. A is even and B is odd: count_even * count_odd ways
 * 
 * Total pairs = 2 * (count_odd * count_even)
 * 
 * Constraints: N <= 10^9, so the result can be up to 2 * (5*10^8 * 5*10^8) = 5*10^17.
 * This fits in a 64-bit integer (long long in C++).
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;

        long long count_odd = (n + 1) / 2;
        long long count_even = n / 2;

        // Total pairs = (odd * even) + (even * odd) = 2 * odd * even
        long long result = 2 * count_odd * count_even;

        cout << result << "\n";
    }

    return 0;
}