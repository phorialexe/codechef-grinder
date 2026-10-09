# [Chef and Battery (FIFTYPE)](https://www.codechef.com/problems/FIFTYPE)

- **Difficulty Rating**: 901
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef's phone battery is at $N$ percent. He can perform two operations:
1. Charge the phone: Increases battery by 2%.
2. Discharge the phone: Decreases battery by 3%.

The goal is to reach exactly 50% battery in the minimum number of operations. The battery level must always remain between 0% and 100% (inclusive).

## Intuition & Mathematical Observation
Since we are looking for the **minimum number of operations** to reach a target state from a starting state, this is a classic **Shortest Path problem** on an unweighted graph. 

- Each battery level from 0 to 100 represents a node in our graph.
- From any node $i$, there are two possible directed edges:
    - To $i + 2$ (if $i + 2 \le 100$)
    - To $i - 3$ (if $i - 3 \ge 0$)
- A **Breadth-First Search (BFS)** is the ideal algorithm here because it explores states layer by layer, ensuring that the first time we reach the target (50), we have done so in the fewest steps possible.

## Complexity Analysis
- **Time Complexity**: $O(V + E)$, where $V$ is the number of possible battery levels (101) and $E$ is the number of possible transitions (at most 2 per level). Since $V$ and $E$ are constants, the complexity is effectively **$O(1)$** per test case.
- **Space Complexity**: **$O(V)$**, where $V = 101$, to store the `dist` array and the BFS queue.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We want to reach 50 from N using BFS to find the shortest path.
 * The state space is small (0-100), making BFS highly efficient.
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
```