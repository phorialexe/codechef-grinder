#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: N Queens Puzzle Solved!
 * The task is to calculate f(N) = (0.143 * N)^N and round it to the nearest integer.
 * Given constraints: 4 <= N <= 15.
 * Since N is small, we can use the pow() function from <cmath> which works with doubles.
 * The result will fit within a standard double precision floating point type,
 * and rounding can be performed using the round() function.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;

    while (t--) {
        int n;
        cin >> n;

        // Calculate (0.143 * N)^N
        double base = 0.143 * (double)n;
        double result = pow(base, (double)n);

        // round() in C++ rounds to the nearest integer, 
        // with halfway cases rounded away from zero.
        // The problem specifies:
        // - Print floor(x) if x - floor(x) < 0.5
        // - Otherwise, print floor(x) + 1
        // This is exactly what round() does for positive numbers.
        long long rounded_result = (long long)round(result);

        cout << rounded_result << "\n";
    }

    return 0;
}