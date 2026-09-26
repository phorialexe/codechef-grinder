# [Coin Flip (CONFLIP)](https://www.codechef.com/problems/CONFLIP)

- **Difficulty Rating**: 1135
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given $N$ coins, all initially set to the same state (either all Heads or all Tails). We perform $N$ rounds of operations. In the $k$-th round (where $1 \le k \le N$), we flip all coins from position $1$ to $k$. We need to determine how many coins end up in a specific state (Heads or Tails) after all $N$ rounds are completed.

## Intuition & Mathematical Observation
Instead of simulating the process (which would be $O(N^2)$ and too slow), we can observe the behavior of an individual coin at position $i$:
1. A coin at position $i$ is flipped in every round $k$ where $k \ge i$.
2. Therefore, the total number of times coin $i$ is flipped is $N - i + 1$.
3. If the number of flips is **even**, the coin returns to its initial state.
4. If the number of flips is **odd**, the coin changes its state.

**Counting the flips:**
- The number of coins that flip an **odd** number of times is $\lceil N/2 \rceil$ (or `(N + 1) / 2`).
- The number of coins that flip an **even** number of times is $\lfloor N/2 \rfloor$ (or `N / 2`).

**Final Logic:**
- If the initial state ($I$) is the same as the target state ($Q$), we are looking for coins that flipped an **even** number of times (as they remain in their initial state).
- If the initial state ($I$) is different from the target state ($Q$), we are looking for coins that flipped an **odd** number of times (as they have changed state).

## Complexity Analysis
- **Time Complexity**: $O(G)$ per test case, where $G$ is the number of games. Since each game is solved in $O(1)$ time, the total time complexity is $O(T \times G)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and results.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Coin i is flipped (N - i + 1) times.
 * - If (N - i + 1) is even, the coin remains in its initial state.
 * - If (N - i + 1) is odd, the coin changes its state.
 * 
 * Number of coins flipped an odd number of times: (N + 1) / 2
 * Number of coins flipped an even number of times: N / 2
 */

void solve() {
    long long I, N, Q;
    cin >> I >> N >> Q;

    // Calculate counts based on parity
    long long odd_flips = (N + 1) / 2;
    long long even_flips = N / 2;

    if (I == Q) {
        // We want the count of coins that didn't change state (even flips)
        cout << even_flips << "\n";
    } else {
        // We want the count of coins that changed state (odd flips)
        cout << odd_flips << "\n";
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int G;
        cin >> G;
        while (G--) {
            solve();
        }
    }
    return 0;
}
```