#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Each player starts with 3 minutes = 180 seconds.
 * Total time given to both players initially = 180 + 180 = 360 seconds.
 * 
 * In an "a + b" blitz match, each move adds 'b' seconds to the clock.
 * Here, a = 3 minutes (180 seconds) and b = 2 seconds.
 * 
 * After N turns:
 * White makes ceil(N/2) moves.
 * Black makes floor(N/2) moves.
 * Total moves = N.
 * Total time added to clocks = N * 2 seconds.
 * 
 * Total time available = (Initial time for both) + (Total time added)
 * Total time available = 360 + 2 * N.
 * 
 * Let A and B be the time remaining on the clocks after N turns.
 * The total time elapsed = (Total time available) - (Total time remaining)
 * Total time elapsed = (360 + 2 * N) - (A + B).
 */

int main() {
    // Fast I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long n, a, b;
        cin >> n >> a >> b;

        // Total time available = 2 * 180 (initial) + 2 * N (increments)
        // Total time available = 360 + 2 * N
        long long total_available = 360 + 2 * n;
        long long total_remaining = a + b;
        
        long long duration = total_available - total_remaining;
        
        cout << duration << "\n";
    }

    return 0;
}