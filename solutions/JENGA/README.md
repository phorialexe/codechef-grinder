# [Jenga Night (JENGA)](https://www.codechef.com/problems/JENGA)

- **Difficulty Rating**: 613
- **Solved in**: 1 attempt(s)

## Problem Summary
In a game of Jenga, there are $N$ people and $X$ total tiles. In each round, every person must pick exactly one tile. The game is considered valid if all $X$ tiles are distributed equally among the $N$ people such that everyone gets the same number of tiles and no tiles are left over. We need to determine if a given $N$ and $X$ allow for a valid game.

## Intuition & Mathematical Observation
For the game to be valid, two conditions must be met:
1. **Equal Distribution**: Every person must receive the same number of tiles. This means the total number of tiles $X$ must be perfectly divisible by the number of people $N$. Mathematically, this is represented as $X \pmod N = 0$.
2. **Feasibility**: Since every person must pick at least one tile in a round, the total number of tiles $X$ must be at least $N$ (i.e., $X \ge N$).

**Observation**: If $X$ is a multiple of $N$ and both $X, N \ge 1$, then $X$ is automatically greater than or equal to $N$. Therefore, the condition simplifies entirely to checking if $X$ is divisible by $N$.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution only involves a single modulo operation. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and do not use any auxiliary data structures.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * There are N people and X tiles.
 * In each round, every person picks 1 tile.
 * This means in one round, N tiles are consumed.
 * For the game to be valid:
 * 1. All tiles must be used at the end. This implies X must be divisible by N (X % N == 0).
 * 2. All players must have a tile in each round. This implies X must be at least N (X >= N).
 * 
 * Combining these, the condition is (X % N == 0) AND (X >= N).
 * Since X >= N and X % N == 0 implies X/N is a positive integer, 
 * the condition simplifies to X % N == 0.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long n, x;
        cin >> n >> x;

        // The game is valid if X is a multiple of N.
        // Since X >= N is guaranteed if X % N == 0 and X, N >= 1,
        // we only need to check the divisibility.
        if (x % n == 0) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }

    return 0;
}
```