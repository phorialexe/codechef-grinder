# [Alternate Jumps (ALJMP)](https://www.codechef.com/problems/ALJMP)

- **Difficulty Rating**: 648
- **Solved in**: 2 attempt(s)

## Problem Summary
A frog starts at position $N$ on a number line. It performs $N-1$ jumps. For each jump $i$ (where $i$ ranges from $1$ to $N-1$):
- If $i$ is **odd**, the frog jumps to the left by $(N-i)$ units.
- If $i$ is **even**, the frog jumps to the right by $(N-i)$ units.

The goal is to determine the final position of the frog after all $N-1$ jumps are completed.

## Intuition & Mathematical Observation
The problem describes a straightforward simulation process. Since the constraints for $N$ are typically small enough for a linear simulation in problems of this difficulty level, we can directly implement the logic provided in the problem statement:

1. Initialize `current_pos` to $N$.
2. Iterate $i$ from $1$ to $N-1$.
3. Apply the conditional logic:
   - If `i % 2 != 0` (odd), subtract $(N-i)$ from `current_pos`.
   - If `i % 2 == 0` (even), add $(N-i)$ to `current_pos`.
4. After the loop finishes, the `current_pos` holds the final coordinate.

**Example Walkthrough ($N=5$):**
- Start: `pos = 5`
- $i=1$ (odd): `pos = 5 - (5-1) = 1`
- $i=2$ (even): `pos = 1 + (5-2) = 4`
- $i=3$ (odd): `pos = 4 - (5-3) = 2`
- $i=4$ (even): `pos = 2 + (5-4) = 3`
- Final result: **3**

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, as we perform a single loop from $1$ to $N-1$.
- **Space Complexity**: $O(1)$, as we only use a few integer variables to track the position and the loop index.

## Solution Code

```cpp
#include <iostream>

using namespace std;

/**
 * Problem Analysis:
 * The frog starts at position N.
 * For i = 1 to N-1:
 *   If i is odd: current_pos -= (N - i)
 *   If i is even: current_pos += (N - i)
 */

void solve() {
    int N;
    if (!(cin >> N)) return;

    int current_pos = N;
    for (int i = 1; i < N; ++i) {
        if (i % 2 != 0) {
            // Odd jump: move left
            current_pos -= (N - i);
        } else {
            // Even jump: move right
            current_pos += (N - i);
        }
    }
    cout << current_pos << "\n";
}

int main() {
    // Fast I/O for performance
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