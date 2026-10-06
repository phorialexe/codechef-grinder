# [Best of N Sets (BESTOFTENNIS)](https://www.codechef.com/problems/BESTOFTENNIS)

- **Difficulty Rating**: 830
- **Solved in**: 1 attempt(s)

## Problem Summary
In a "Best of $N$" series, the match ends as soon as one player wins more than half of the total sets $N$. Given the final score of a match $(X, Y)$, where $X$ and $Y$ are the number of sets won by each player, we need to determine the value of $N$. Note that $N$ is always an odd integer.

## Intuition & Mathematical Observation
In a "Best of $N$" series, the winner is the player who reaches $\frac{N+1}{2}$ sets first. 

Let $M = \max(X, Y)$ be the number of sets won by the winner, and $m = \min(X, Y)$ be the number of sets won by the loser.
1. The winner must have reached the winning threshold, so $M = \frac{N+1}{2}$.
2. Rearranging this equation to solve for $N$:
   $$2M = N + 1$$
   $$N = 2M - 1$$

Since the match ends exactly when the winner reaches this threshold, the loser's score $m$ must be less than $M$. The formula $N = 2 \cdot \max(X, Y) - 1$ holds true regardless of the loser's score, as long as the match is valid.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution involves a simple arithmetic calculation. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * In a "Best of N" series, the winner is the first to reach (N+1)/2 sets.
 * If the winner has M sets, then M = (N+1)/2.
 * Solving for N:
 * 2 * M = N + 1
 * N = 2 * M - 1
 * where M is the maximum of the two scores (X, Y).
 */

int main() {
    // Optimize I/O operations for faster execution
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long x, y;
        cin >> x >> y;
        
        // The winner is the one with the higher score
        long long m = max(x, y);
        
        // Apply the derived formula N = 2 * max(X, Y) - 1
        long long n = 2 * m - 1;
        
        cout << n << "\n";
    }
    
    return 0;
}
```