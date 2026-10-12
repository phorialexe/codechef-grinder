# [Mirror Jump (MIRJMP)](https://www.codechef.com/problems/MIRJMP)

- **Difficulty Rating**: 762
- **Solved in**: 1 attempt(s)

## Problem Summary
You are given $N$ points labeled from $1$ to $N$. Starting at position $K$, your goal is to reach position $N$ using the minimum number of moves. The allowed moves from a position $X$ are:
1. Move to $X - 1$ (if $X > 1$).
2. Move to $X + 1$ (if $X < N$).
3. Move to $N + 1 - X$ (the "mirror" position).

## Intuition & Mathematical Observation
Since we are looking for the **minimum number of moves** in an unweighted graph where each move has a cost of 1, **Breadth-First Search (BFS)** is the ideal algorithm.

- **Graph Representation**: Each point from $1$ to $N$ acts as a node in our graph.
- **State Space**: The state is simply the current position $X$.
- **Transitions**: From any node $X$, we generate the neighbors based on the three rules provided. We use a `dist` array initialized to $-1$ to keep track of visited nodes and the distance from the starting point $K$.
- **Termination**: The BFS naturally finds the shortest path. As soon as we dequeue the target node $N$, the associated distance is the minimum number of moves required.

## Complexity Analysis
- **Time Complexity**: $O(N)$, where $N$ is the number of points. In the worst case, we visit each node once and check its 3 possible transitions. Given $N \le 20$, this is extremely efficient.
- **Space Complexity**: $O(N)$ to store the `dist` array and the BFS queue.

## Solution Code

```cpp
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
```