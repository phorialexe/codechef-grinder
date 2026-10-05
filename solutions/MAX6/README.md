# [Max Sixers (MAX6)](https://www.codechef.com/problems/MAX6)

- **Difficulty Rating**: 216
- **Solved in**: 1 attempt(s)

## Problem Summary
Given that a player scores $X$ runs in exactly 100 balls, we need to find the maximum number of sixers ($s$) the player could have hit. Each ball can result in 0, 1, 2, 3, 4, or 6 runs. We must determine the largest $s$ such that the remaining runs ($X - 6s$) can be scored using the remaining balls ($100 - s$) with each ball contributing at most 4 runs.

## Intuition & Mathematical Observation
To maximize the number of sixers ($s$), we should attempt to hit as many sixers as possible. 

1. **Constraints on $s$**:
   - The number of sixers cannot exceed the total balls: $s \le 100$.
   - The total runs from sixers cannot exceed the total runs: $6s \le X$.
   - The remaining runs ($r = X - 6s$) must be achievable in the remaining balls ($b = 100 - s$). Since each remaining ball can contribute at most 4 runs, we must satisfy: $r \le 4 \times b$.

2. **Optimization**:
   - We iterate downwards from the maximum possible sixers, which is $\lfloor X/6 \rfloor$.
   - The first value of $s$ that satisfies the condition $X - 6s \le 4(100 - s)$ is our answer, as we are iterating from the largest possible value downwards.
   - Given $X \le 200$, the condition $X - 6s \le 400 - 4s$ simplifies to $s \ge (X - 400) / 2$. Since $X \le 200$, this lower bound is always negative, confirming that any $s$ satisfying $6s \le X$ and $s \le 100$ is potentially valid as long as the remaining runs are non-negative and within the capacity of the remaining balls.

## Complexity Analysis
- **Time Complexity**: $O(X/6)$, which simplifies to $O(X)$. Given $X \le 200$, this is effectively $O(1)$.
- **Space Complexity**: $O(1)$, as we only use a few integer variables.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We want the largest s such that:
 * 1. 6*s <= X
 * 2. s <= 100
 * 3. X - 6*s <= 4 * (100 - s)
 */

void solve() {
    int X;
    if (!(cin >> X)) return;

    // Iterate from the maximum possible sixers downwards
    for (int s = X / 6; s >= 0; --s) {
        int remaining_runs = X - 6 * s;
        int remaining_balls = 100 - s;
        
        // Check if remaining runs can be scored in remaining balls (max 4 per ball)
        if (remaining_runs >= 0 && remaining_runs <= 4 * remaining_balls) {
            cout << s << "\n";
            return;
        }
    }
}

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
```