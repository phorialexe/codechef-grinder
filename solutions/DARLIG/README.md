# [Dark Light (DARLIG)](https://www.codechef.com/problems/DARLIG)

- **Difficulty Rating**: 994
- **Solved in**: 1 attempt(s)

## Problem Summary
A torch has 4 levels. Levels 1, 2, and 3 are "On", and level 4 is "Off". Each time the button is pressed, the level increases by 1 (1 → 2 → 3 → 4 → 1). Given the initial state $K$ (0 for Off, 1 for On) and the number of button presses $N$, determine if the final state is "On", "Off", or "Ambiguous" (if the state cannot be uniquely determined).

## Intuition & Mathematical Observation
The state of the torch follows a cycle of length 4. 

1. **If $K = 0$ (Off):**
   - The torch starts at level 4.
   - After $N$ presses, the level becomes $(4 + N - 1) \pmod 4 + 1$.
   - If $N$ is a multiple of 4 ($N \pmod 4 == 0$), the torch returns to level 4 (Off).
   - If $N$ is not a multiple of 4, the torch moves to levels 1, 2, or 3, all of which are "On".

2. **If $K = 1$ (On):**
   - The torch starts at one of the levels $\{1, 2, 3\}$.
   - If $N$ is a multiple of 4, the levels shift by a full cycle, meaning the torch will still be at one of the levels $\{1, 2, 3\}$. Thus, the result is always "On".
   - If $N$ is not a multiple of 4, the set of possible final levels will include level 4 (Off) and some "On" levels. Since the final state could be either "On" or "Off", the result is "Ambiguous".

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we only perform basic arithmetic and conditional checks. Total time complexity is $O(T)$, where $T$ is the number of test cases.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and state.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Levels: 1, 2, 3 (On) -> 4 (Off)
 * Cycle: 1 -> 2 -> 3 -> 4 -> 1 ...
 */

void solve() {
    long long N;
    int K;
    cin >> N >> K;

    if (K == 0) {
        // Initially Off (Level 4)
        if (N % 4 == 0) {
            cout << "Off" << "\n";
        } else {
            cout << "On" << "\n";
        }
    } else {
        // Initially On (Levels 1, 2, 3)
        if (N % 4 == 0) {
            cout << "On" << "\n";
        } else {
            cout << "Ambiguous" << "\n";
        }
    }
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