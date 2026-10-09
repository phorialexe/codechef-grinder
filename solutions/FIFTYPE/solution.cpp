#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We want to reach 50 from N.
 * Let x be the number of minutes charging (+2) and y be the number of minutes discharging (-3).
 * We want: N + 2x - 3y = 50
 * 2x - 3y = 50 - N
 * We want to minimize (x + y) subject to 0 <= N + 2x - 3y <= 100 at every step.
 * 
 * Since N is small (0 to 100), we can use Breadth-First Search (BFS) to find the 
 * shortest path from N to 50.
 */

int solve() {
    int N;
    cin >> N;
    if (N == 50) return 0;

    // dist[i] stores the minimum minutes to reach battery level i
    vector<int> dist(101, -1);
    queue<int> q;

    q.push(N);
    dist[N] = 0;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        if (curr == 50) return dist[curr];

        // Option 1: Charge (+2)
        int next_charge = curr + 2;
        if (next_charge <= 100 && dist[next_charge] == -1) {
            dist[next_charge] = dist[curr] + 1;
            q.push(next_charge);
        }

        // Option 2: Discharge (-3)
        int next_discharge = curr - 3;
        if (next_discharge >= 0 && dist[next_discharge] == -1) {
            dist[next_discharge] = dist[curr] + 1;
            q.push(next_discharge);
        }
    }
    return -1;
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        cout << solve() << "\n";
    }
    return 0;
}