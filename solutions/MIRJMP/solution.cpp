#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have N points [1, N]. Start at K, target N.
 * Moves:
 * 1. X -> X-1 (if X > 1)
 * 2. X -> X+1 (if X < N)
 * 3. X -> N + 1 - X
 * 
 * Since N is very small (N <= 20), this is a shortest path problem on a graph
 * with N nodes (1 to N). We can use Breadth-First Search (BFS) to find the 
 * minimum number of moves.
 */

void solve() {
    int N, K;
    cin >> N >> K;

    if (K == N) {
        cout << 0 << "\n";
        return;
    }

    // dist array to store minimum moves to reach each point
    vector<int> dist(N + 1, -1);
    queue<int> q;

    q.push(K);
    dist[K] = 0;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        if (curr == N) {
            cout << dist[curr] << "\n";
            return;
        }

        // Possible moves
        vector<int> next_positions;
        if (curr > 1) next_positions.push_back(curr - 1);
        if (curr < N) next_positions.push_back(curr + 1);
        next_positions.push_back(N + 1 - curr);

        for (int next : next_positions) {
            if (dist[next] == -1) {
                dist[next] = dist[curr] + 1;
                q.push(next);
            }
        }
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}