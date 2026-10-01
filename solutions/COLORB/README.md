# [Coloured Orbs (COLORB)](https://www.codechef.com/problems/COLORB)

- **Difficulty Rating**: 273
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given $R$ red orbs and $B$ blue orbs. We can combine one red orb and one blue orb to create one green orb. The skill values for the orbs are:
- Red: 1
- Blue: 2
- Green: 5

The goal is to determine the maximum total skill possible by choosing an optimal number of green orbs to create.

## Intuition & Mathematical Observation
Let $k$ be the number of green orbs we choose to create. Since each green orb requires one red and one blue orb, $k$ can range from $0$ to $\min(R, B)$.

After creating $k$ green orbs, the remaining counts are:
- Red: $R - k$
- Blue: $B - k$
- Green: $k$

The total skill $S$ can be expressed as:
$$S = (R - k) \times 1 + (B - k) \times 2 + k \times 5$$
$$S = R - k + 2B - 2k + 5k$$
$$S = R + 2B + 2k$$

To maximize $S$, we must maximize $k$. Since $k$ is limited by the available red and blue orbs, the maximum value for $k$ is $\min(R, B)$. Substituting this into the equation gives us the maximum possible skill.

## Complexity Analysis
- **Time Complexity**: $O(1)$, as the solution involves simple arithmetic operations regardless of the input size.
- **Space Complexity**: $O(1)$, as we only store a few variables.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Total Skill = R + 2B + 2k
 * To maximize the skill, we maximize k = min(R, B).
 */

void solve() {
    long long R, B;
    if (!(cin >> R >> B)) return;
    
    // Maximize green orbs (k)
    long long k = min(R, B);
    
    // Calculate total skill based on the derived formula
    long long max_skill = (R - k) * 1 + (B - k) * 2 + k * 5;
    
    cout << max_skill << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    solve();
    
    return 0;
}
```