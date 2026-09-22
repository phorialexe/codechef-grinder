#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have N episodes.
 * Odd-indexed episodes (1, 3, 5, ...) have duration B.
 * Even-indexed episodes (2, 4, 6, ...) have duration A.
 * 
 * Number of even-indexed episodes = floor(N / 2)
 * Number of odd-indexed episodes = N - floor(N / 2)
 * 
 * Total duration = (Number of even episodes * A) + (Number of odd episodes * B)
 * 
 * Constraints:
 * N, A, B <= 60. The maximum possible total duration is 60 * 60 = 3600,
 * which fits comfortably within a standard 32-bit integer.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n, a, b;
        cin >> n >> a >> b;

        int even_count = n / 2;
        int odd_count = n - even_count;

        // Calculate total duration
        // Using long long to prevent any potential overflow, though int is sufficient here
        long long total_duration = (long long)even_count * a + (long long)odd_count * b;

        cout << total_duration << "\n";
    }

    return 0;
}