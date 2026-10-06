# [Dice Game 3 (DICEGAME3)](https://www.codechef.com/problems/DICEGAME3)

- **Difficulty Rating**: 889
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given $N$ rounds of a dice game. The scoring rules are as follows:
1. In the first round, the score is equal to the value rolled ($X$).
2. In any subsequent round $i > 1$, if the roll in the previous round was $1$, the score added is $2 \times X$. Otherwise, the score added is simply $X$.
The goal is to maximize the total score over $N$ rounds by choosing the optimal sequence of dice rolls.

## Intuition & Mathematical Observation
To maximize the total score, we want to trigger the $2 \times X$ multiplier as frequently as possible. This multiplier is triggered whenever we roll a $1$. To get the most value out of this multiplier, we should roll a $6$ immediately after every $1$.

This leads to a repeating pattern of $(1, 6)$:
- Each pair $(1, 6)$ contributes $1 + (2 \times 6) = 13$ to the total score.

**Case 1: $N$ is even**
We can perfectly divide the $N$ rounds into $N/2$ pairs of $(1, 6)$.
- Total Score = $(N / 2) \times 13$.

**Case 2: $N$ is odd**
We can have $(N-1)/2$ pairs of $(1, 6)$, which accounts for $N-1$ rounds. For the final $N$-th round, we should roll a $6$ to maximize the points. Since the previous roll was a $6$ (not a $1$), the multiplier is not triggered, and we simply add $6$.
- Total Score = $((N - 1) / 2) \times 13 + 6$.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution uses a simple mathematical formula. With $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have N rounds.
 * Score logic:
 * - Round 1: Add X.
 * - Round i > 1: If previous roll was 1, add 2*X, else add X.
 * 
 * To maximize the score:
 * - We want to trigger the 2*X multiplier as often as possible.
 * - The multiplier is triggered if the previous roll was 1.
 * - If we roll a 1, the next roll gets a 2x multiplier. To maximize this, 
 *   we should roll a 6 immediately after a 1.
 * - Sequence pattern: 1, 6, 1, 6, 1, 6...
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        
        if (n % 2 == 0) {
            // Even number of rounds: N/2 pairs of (1, 6)
            cout << (n / 2) * 13 << "\n";
        } else {
            // Odd number of rounds: (N-1)/2 pairs of (1, 6) + one final 6
            cout << ((n - 1) / 2) * 13 + 6 << "\n";
        }
    }
    
    return 0;
}
```