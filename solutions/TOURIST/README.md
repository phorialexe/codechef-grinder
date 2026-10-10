# [Tourist (TOURIST)](https://www.codechef.com/problems/TOURIST)

- **Difficulty Rating**: 706
- **Solved in**: 1 attempt(s)

## Problem Summary
You are given a starting coordinate $(A, B)$ and a list of $N$ attractions, each located at $(X_i, Y_i)$. The goal is to find the minimum **Manhattan distance** from the starting point to any of the $N$ attractions. The Manhattan distance between two points $(x_1, y_1)$ and $(x_2, y_2)$ is defined as $|x_1 - x_2| + |y_1 - y_2|$.

## Intuition & Mathematical Observation
Since the number of attractions $N$ is small ($N \le 100$) and the number of test cases $T$ is also small ($T \le 100$), we can use a brute-force approach. 

1. Initialize a variable `min_dist` to a very large value (or handle the first iteration separately).
2. Iterate through each attraction $(X_i, Y_i)$.
3. For each attraction, calculate the Manhattan distance: `dist = abs(A - Xi) + abs(B - Yi)`.
4. Keep track of the smallest distance found so far.
5. After checking all $N$ attractions, the smallest value stored is the answer.

## Complexity Analysis
- **Time Complexity**: $O(T \times N)$, where $T$ is the number of test cases and $N$ is the number of attractions. Given the constraints, this results in approximately $10^4$ operations, which easily fits within the time limit.
- **Space Complexity**: $O(1)$, as we only store the current minimum distance and the coordinates of the attraction being processed, requiring constant extra space.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The problem asks for the minimum Manhattan distance from a starting point (A, B)
 * to any of the N given attractions (Xi, Yi).
 * The Manhattan distance between (A, B) and (Xi, Yi) is defined as |A - Xi| + |B - Yi|.
 * 
 * Constraints:
 * T <= 100, N <= 100, coordinates <= 100.
 * The constraints are small enough that an O(N) approach per test case is perfectly optimal.
 * Total complexity: O(T * N), which is at most 10^4 operations.
 */

void solve() {
    int N;
    long long A, B;
    if (!(cin >> N >> A >> B)) return;

    long long min_dist = -1;

    for (int i = 0; i < N; ++i) {
        long long Xi, Yi;
        cin >> Xi >> Yi;
        
        // Calculate Manhattan distance
        long long current_dist = abs(A - Xi) + abs(B - Yi);
        
        // Update minimum distance
        if (min_dist == -1 || current_dist < min_dist) {
            min_dist = current_dist;
        }
    }
    
    cout << min_dist << "\n";
}

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        solve();
    }
    return 0;
}
```