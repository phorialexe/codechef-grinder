# [2 Boxes (BOX2)](https://www.codechef.com/problems/BOX2)

- **Difficulty Rating**: 832
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given two boxes containing $X$ and $Y$ stones, respectively. We can perform an operation where we move one stone from one box to the other. We want to reach a state where the absolute difference between the number of stones in the two boxes is exactly $K$. We need to find the minimum number of operations required to achieve this.

## Intuition & Mathematical Observation
Let $x'$ and $y'$ be the number of stones in the two boxes after some operations. We know:
1. $x' + y' = X + Y = S$ (Total stones remain constant).
2. $|x' - y'| = K$ (Target condition).

Substituting $y' = S - x'$ into the second equation:
$|x' - (S - x')| = K \implies |2x' - S| = K$

This gives us two possible target values for $x'$:
- $2x' - S = K \implies x' = \frac{S + K}{2}$
- $2x' - S = -K \implies x' = \frac{S - K}{2}$

For a valid solution to exist, $x'$ must be an integer (meaning $S+K$ and $S-K$ must be even) and $0 \le x' \le S$. Since each operation moves one stone, changing the count in box 1 by $\pm 1$, the number of operations required to reach a target $x'$ from the initial $X$ is simply $|x' - X|$. We calculate the moves for both valid candidates and take the minimum.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we perform a constant number of arithmetic operations.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the state.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Let the number of stones in box 1 be x and box 2 be y.
 * Total stones S = X + Y.
 * After some moves, let box 1 have x' stones and box 2 have y' stones.
 * x' + y' = S.
 * We want |x' - y'| = K.
 * Substituting y' = S - x', we get |x' - (S - x')| = |2x' - S| = K.
 * This implies 2x' - S = K or 2x' - S = -K.
 * 2x' = S + K or 2x' = S - K.
 * For x' to be an integer, (S + K) must be even, and 0 <= x' <= S.
 * 
 * Each move changes the number of stones in box 1 by +1 or -1.
 * The number of moves required is |x' - X|.
 * We want to minimize |x' - X| subject to the parity and range constraints.
 */

void solve() {
    long long X, Y, K;
    cin >> X >> Y >> K;
    long long S = X + Y;
    
    long long min_moves = -1;
    
    // Possible values for x' are (S+K)/2 and (S-K)/2
    // Check both candidates
    long long candidates[] = {(S + K) / 2, (S - K) / 2};
    
    for (long long x_prime : candidates) {
        // Check if x_prime is valid:
        // 1. 2*x_prime must equal S+K or S-K (parity check)
        // 2. 0 <= x_prime <= S
        if ((abs(2 * x_prime - S) == K) && (x_prime >= 0 && x_prime <= S)) {
            long long moves = abs(x_prime - X);
            if (min_moves == -1 || moves < min_moves) {
                min_moves = moves;
            }
        }
    }
    
    cout << min_moves << "\n";
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