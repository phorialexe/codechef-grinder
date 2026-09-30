# [Chef and Linear Chess (LINCHESS)](https://www.codechef.com/problems/LINCHESS)

- **Difficulty Rating**: 1200
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef is positioned at coordinate $K$ on a linear board. There are $N$ other players, each starting at a position $P_i$. A player at $P_i$ can capture Chef if $K$ is a multiple of $P_i$ (i.e., $K \% P_i == 0$). If a player can capture Chef, the number of moves they take is calculated as $(K - P_i) / P_i$, which simplifies to $(K / P_i) - 1$. We need to find the player who can reach Chef in the minimum number of moves. If no player can capture Chef, output -1.

## Intuition & Mathematical Observation
1. **Divisibility Condition**: A player at $P_i$ can only reach $K$ if $P_i$ is a divisor of $K$.
2. **Minimizing Moves**: The number of moves is $(K / P_i) - 1$. To minimize this value, we must maximize the value of $P_i$.
3. **Strategy**: 
   - Iterate through all given positions $P_i$.
   - Check if $K$ is divisible by $P_i$.
   - Among all valid divisors, keep track of the one that results in the smallest quotient ($K / P_i$).
   - Since $K$ is constant, maximizing $P_i$ automatically minimizes the number of moves.

## Complexity Analysis
- **Time Complexity**: $O(T \times N)$, where $T$ is the number of test cases and $N$ is the number of players. Given $T \le 100$ and $N \le 1000$, the total operations are $\approx 10^5$, which easily fits within the 1-second time limit.
- **Space Complexity**: $O(1)$, as we only store a few variables to track the best player found so far.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef is at position K. A player at position P_i can capture Chef if K is a multiple of P_i.
 * That is, K % P_i == 0.
 * The number of moves taken by player i to reach K is (K / P_i) - 1.
 * We want to minimize the number of moves, which is equivalent to 
 * maximizing P_i among all P_i that are divisors of K.
 */

void solve() {
    int N;
    long long K;
    cin >> N >> K;
    
    long long best_p = -1;
    long long min_moves = -1;
    
    for (int i = 0; i < N; ++i) {
        long long P;
        cin >> P;
        
        // Check if player can capture Chef
        if (K % P == 0) {
            long long moves = K / P;
            // We want the smallest number of moves.
            // If this is the first valid player found, or if this player
            // takes fewer moves than the current best, update.
            if (min_moves == -1 || moves < min_moves) {
                min_moves = moves;
                best_p = P;
            }
        }
    }
    
    cout << best_p << "\n";
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