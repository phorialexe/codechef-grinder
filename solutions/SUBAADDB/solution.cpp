#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We start with a string of length N.
 * In each step, we replace a substring of length A with a substring of length B.
 * This reduces the total length of the string by (A - B).
 * We repeat this as long as the current length L >= A.
 * 
 * Let L be the current length.
 * While L >= A:
 *    L = L - A + B
 * 
 * Since N is small (up to 100), a simple simulation loop is perfectly efficient.
 * Time Complexity: O(T * (N / (A - B))), which is well within the 1s limit.
 * Space Complexity: O(1).
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long n, a, b;
        cin >> n >> a >> b;

        // Simulation of the process
        // While the current length is at least A, perform the replacement
        while (n >= a) {
            n = n - a + b;
        }

        cout << n << "\n";
    }

    return 0;
}