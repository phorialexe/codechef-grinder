# [No Winner (NOWINNER)](https://www.codechef.com/problems/NOWINNER)

- **Difficulty Rating**: 931
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given the initial scores of three players: $A$, $B$, and $C$. We are also given $M$ matches, where in each match, exactly one player receives $+1$ point. We need to determine if it is possible to distribute the $M$ points such that at least two players end up with the same final score.

## Intuition & Mathematical Observation
To make two players (e.g., $A$ and $B$) have the same score, we need to bridge the gap between their initial scores using the $M$ available points.

1.  **The Gap**: The difference between two players' scores is $|A - B|$.
2.  **Bridging the Gap**: If we want to make $A$ and $B$ equal, we can give the player with the lower score points until they catch up to the other. This requires exactly $|A - B|$ points.
3.  **Constraint**: Since we have $M$ points available, we can bridge the gap if and only if $|A - B| \le M$.
4.  **Remaining Points**: If we use $k = |A - B|$ points to make the scores equal, we are left with $M - k$ points. As long as $M - k \ge 0$, we can distribute the remaining points in a way that preserves the equality (e.g., by giving points to the third player, or by giving points to $A$ and $B$ in pairs).
5.  **Conclusion**: It is possible to have a winner (or rather, a tie) if the difference between any two players is less than or equal to $M$. The condition is:
    $$|A - B| \le M \quad \text{OR} \quad |B - C| \le M \quad \text{OR} \quad |A - C| \le M$$

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we are performing a constant number of arithmetic operations and comparisons.
- **Space Complexity**: $O(1)$, as we only use a few integer variables to store the input.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * To make two players have the same score, the difference between their 
 * initial scores must be bridgeable by the M points available.
 * If |A - B| <= M, we can give the player with the lower score the 
 * difference, and distribute the remaining points (if any) to the third 
 * player or in pairs to keep the two players equal.
 */

void solve() {
    int A, B, C, M;
    cin >> A >> B >> C >> M;

    // Check if the difference between any two players is <= M
    if (abs(A - B) <= M || abs(B - C) <= M || abs(A - C) <= M) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
}

int main() {
    // Fast I/O for performance
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