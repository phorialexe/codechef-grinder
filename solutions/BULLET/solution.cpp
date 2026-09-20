#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Bullet speed = X pixels/frame (or pixels/second)
 * Distance to Goomba = Y pixels
 * Time taken for bullet to travel = Y / X seconds
 * 
 * Let T_wait be the time Mario waits before shooting.
 * The bullet hits the goomba at time (T_wait + Y/X).
 * We need (T_wait + Y/X) >= Z.
 * Therefore, T_wait >= Z - (Y/X).
 * 
 * Since T_wait cannot be negative, the minimum time is max(0, Z - (Y/X)).
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long x, y, z;
        cin >> x >> y >> z;

        // Calculate travel time of the bullet
        long long travel_time = y / x;

        // Calculate the required wait time
        long long wait_time = z - travel_time;

        // If wait_time is negative, Mario can shoot immediately (0 seconds)
        if (wait_time < 0) {
            cout << 0 << "\n";
        } else {
            cout << wait_time << "\n";
        }
    }

    return 0;
}