#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Policeman is at X with speed 2.
 * Thief is at Y with speed 1.
 * Let the time taken be 't'.
 * After time 't', the policeman's position will be X + 2t (if moving right) 
 * or X - 2t (if moving left).
 * The thief's position will be Y + t (if moving right) or Y - t (if moving left).
 * 
 * To catch the thief, the policeman must reach the same position as the thief.
 * The relative speed of the policeman with respect to the thief is |2 - 1| = 1 unit per second.
 * The distance between them is |X - Y|.
 * Since the policeman is faster, he will always catch the thief.
 * The time taken is simply the distance divided by the relative speed:
 * Time = |X - Y| / 1 = |X - Y|.
 * 
 * Let's verify with sample cases:
 * 1. X=1, Y=3: |1-3| = 2. Correct.
 * 2. X=2, Y=1: |2-1| = 1. Correct.
 * 3. X=1, Y=1: |1-1| = 0. Correct.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long x, y;
        cin >> x >> y;
        
        // The time taken is the absolute difference between their positions
        // because the policeman's relative speed is 1 unit/sec.
        long long time = abs(x - y);
        cout << time << "\n";
    }

    return 0;
}