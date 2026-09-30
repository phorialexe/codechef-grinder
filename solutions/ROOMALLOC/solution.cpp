#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Each college has A_i members.
 * People from different colleges cannot share a room.
 * Each room can hold at most 2 people.
 * 
 * For a single college with A_i members:
 * If A_i is even, we need A_i / 2 rooms.
 * If A_i is odd, we need (A_i + 1) / 2 rooms.
 * This can be simplified using integer division: (A_i + 1) / 2.
 * 
 * Total rooms = Sum of rooms needed for each college.
 * Constraints: N <= 100, A_i <= 100.
 * The total number of rooms will not exceed 100 * 50 = 5000, 
 * which fits easily into a standard integer.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n;
        cin >> n;
        long long total_rooms = 0;
        for (int i = 0; i < n; ++i) {
            int a;
            cin >> a;
            // Calculate rooms for current college: ceil(a / 2.0)
            // Using integer arithmetic: (a + 1) / 2
            total_rooms += (a + 1) / 2;
        }
        cout << total_rooms << "\n";
    }
    return 0;
}