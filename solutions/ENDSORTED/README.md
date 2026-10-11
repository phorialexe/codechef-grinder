# [End Sorted (ENDSORTED)](https://www.codechef.com/problems/ENDSORTED)

- **Difficulty Rating**: 1049
- **Solved in**: 1 attempt(s)

## Problem Summary
Given a permutation of size $N$, we want to make the array "End Sorted," which means the first element must be $1$ and the last element must be $N$. We are allowed to perform adjacent swaps. The goal is to find the minimum number of swaps required to achieve this state.

## Intuition & Mathematical Observation
To make the array end-sorted, we need to move the element `1` to index `0` and the element `N` to index `N-1`.

1. **Moving `1`**: If the current index of `1` is `idx1`, it takes exactly `idx1` adjacent swaps to move it to the front (index `0`).
2. **Moving `N`**: If the current index of `N` is `idxN`, it takes exactly `(N - 1) - idxN` adjacent swaps to move it to the end (index `N-1`).
3. **The Overlap Case**: If `idx1 > idxN`, the element `1` is currently to the right of `N`. As we move `1` to the left and `N` to the right, they will eventually be adjacent and swap places with each other. This single swap effectively moves `1` one step closer to the start **and** `N` one step closer to the end simultaneously. Therefore, we subtract `1` from the total count to account for this shared move.

**Formula**:
- Let `ops = idx1 + (N - 1 - idxN)`
- If `idx1 > idxN`, then `ops = ops - 1`

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, as we iterate through the array once to find the positions of `1` and `N`.
- **Space Complexity**: $O(N)$ to store the permutation (though this could be optimized to $O(1)$ by finding indices on the fly).

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * To make the permutation "End Sorted", we need P[1] = 1 and P[N] = N.
 * We can move 1 to the first position and N to the last position using adjacent swaps.
 * 
 * Let the initial index of 1 be idx1 (0-indexed) and the initial index of N be idxN (0-indexed).
 * 
 * 1. To move 1 to index 0:
 *    It takes 'idx1' swaps.
 * 2. To move N to index N-1:
 *    It takes '(N - 1) - idxN' swaps.
 * 
 * However, if idx1 > idxN, the swap that moves 1 to the left will also move N to the right 
 * (or vice versa), effectively reducing the total count by 1 because they cross each other.
 * 
 * Total operations = (idx1) + (N - 1 - idxN) - (1 if idx1 > idxN else 0)
 */

void solve() {
    int N;
    cin >> N;
    vector<int> P(N);
    int idx1 = -1, idxN = -1;
    for (int i = 0; i < N; ++i) {
        cin >> P[i];
        if (P[i] == 1) {
            idx1 = i;
        } else if (P[i] == N) {
            idxN = i;
        }
    }

    // Operations to move 1 to index 0: idx1
    // Operations to move N to index N-1: (N - 1 - idxN)
    // If idx1 > idxN, they swap positions at some point, saving one operation.
    int ops = idx1 + (N - 1 - idxN);
    if (idx1 > idxN) {
        ops -= 1;
    }

    cout << ops << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
```