# [Magician versus Chef (MAGICHF)](https://www.codechef.com/problems/MAGICHF)

- **Difficulty Rating**: 1088
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given $N$ boxes, with a gold coin initially placed in box $X$. There are $S$ swap operations performed, where each operation swaps the contents of two boxes, $A$ and $B$. Our goal is to determine the final position of the coin after all $S$ swaps are completed.

## Intuition & Mathematical Observation
Instead of maintaining the state of all $N$ boxes (which would be inefficient if $N$ were very large), we only need to track the current position of the coin. 

Let `current_pos` be the box index where the coin is currently located. For every swap operation involving boxes $A$ and $B$:
1. If `current_pos == A`, the coin moves to box $B$.
2. If `current_pos == B`, the coin moves to box $A$.
3. If the coin is in neither $A$ nor $B$, its position remains unchanged.

By updating `current_pos` iteratively through each swap, we arrive at the final position efficiently without needing to simulate the entire array of boxes.

## Complexity Analysis
- **Time Complexity**: $O(S)$ per test case, where $S$ is the number of swaps. Given the constraints, the total time complexity is $O(\sum S)$, which is well within the time limit.
- **Space Complexity**: $O(1)$ auxiliary space, as we only store the current position of the coin and the input variables for each swap.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given N boxes, a starting position X of a coin, and S swaps.
 * Since we only care about the position of the coin, we don't need to track
 * all N boxes. We only need to update the current position of the coin
 * whenever one of the swapped boxes is the current position of the coin.
 * 
 * Time Complexity: O(S) per test case, where S is the number of swaps.
 * Total time complexity: O(sum of S), which is 2*10^5, well within the 0.5s limit.
 * Space Complexity: O(1) auxiliary space.
 */

void solve() {
    int N, X, S;
    if (!(cin >> N >> X >> S)) return;

    int current_pos = X;
    for (int i = 0; i < S; ++i) {
        int A, B;
        cin >> A >> B;
        
        // If the coin is in one of the swapped boxes, update its position
        if (current_pos == A) {
            current_pos = B;
        } else if (current_pos == B) {
            current_pos = A;
        }
        // If the coin is in neither, its position remains unchanged
    }
    
    cout << current_pos << "\n";
}

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}
```