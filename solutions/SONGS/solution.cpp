#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Each song has a duration of X minutes.
 * The playlist consists of 3 songs: A, B, C.
 * The total duration of one full cycle (A -> B -> C) is 3 * X.
 * 
 * To find how many times song C is listened to completely:
 * 1. Calculate the total number of full songs listened to: N / X.
 * 2. In every cycle of 3 songs, song C is the 3rd song.
 * 3. The number of full cycles completed is (N / X) / 3.
 * 4. This is equivalent to floor(N / (3 * X)).
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long n, x;
        cin >> n >> x;

        // Total duration of one full loop of A, B, C is 3 * X.
        // The number of times the full sequence A, B, C is completed
        // is the number of times song C is completed.
        // Each full sequence takes 3 * X minutes.
        long long full_cycles = n / (3 * x);

        cout << full_cycles << "\n";
    }

    return 0;
}