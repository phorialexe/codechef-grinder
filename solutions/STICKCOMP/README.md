# [Brick Comparisions (STICKCOMP)](https://www.codechef.com/problems/STICKCOMP)

- **Difficulty Rating**: 625
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef starts with the first brick (index 1) and iterates through the remaining bricks (from 2 to $N$). If the current brick being inspected has a size strictly greater than the size of the brick Chef is currently holding, he replaces his current brick with the new one. The goal is to determine the 1-based index of the brick Chef is holding after checking all $N$ bricks.

## Intuition & Mathematical Observation
The problem describes a simple linear scan (a "find maximum" algorithm). 
1. We initialize the `current_size` with the size of the first brick.
2. We iterate through the array from the second brick to the last.
3. At each step, we compare the current brick's size with the `current_size`.
4. If the current brick is strictly larger, we update `current_size` and track the index of this new brick.
5. Since we only care about the *first* occurrence of a new maximum (or simply updating whenever a strictly larger brick is found), a single pass through the array is sufficient.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the number of bricks, as we iterate through the list of bricks exactly once.
- **Space Complexity**: $O(N)$ to store the brick sizes in a vector. This could be optimized to $O(1)$ by processing the input on the fly, but $O(N)$ is well within the memory limits.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef starts with brick 1.
 * He iterates through bricks 2 to N.
 * If the current brick (index i) has a size A[i] strictly greater than the size of the brick he is holding,
 * he updates his current brick to index i.
 * 
 * Complexity:
 * Time: O(N) per test case, where N is the number of bricks.
 * Space: O(N) to store the brick sizes.
 */

void solve() {
    int N;
    if (!(cin >> N)) return;
    
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    // Chef starts with brick 1 (index 0 in 0-based array)
    int current_brick_idx = 0;
    int current_size = A[0];
    
    // Iterate through bricks 2 to N (indices 1 to N-1)
    for (int i = 1; i < N; ++i) {
        if (A[i] > current_size) {
            current_size = A[i];
            current_brick_idx = i;
        }
    }
    
    // Output the 1-based index of the final brick
    cout << (current_brick_idx + 1) << "\n";
}

int main() {
    // Fast I/O
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