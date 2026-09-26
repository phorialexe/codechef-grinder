# [Hardest Problem Bet (HARDBET)](https://www.codechef.com/problems/HARDBET)

- **Difficulty Rating**: 803
- **Solved in**: 1 attempt(s)

## Problem Summary
Three friends (Alice, Bob, and Chef) are betting on which of three problems (A, B, or C) is the "hardest." The difficulty of a problem is determined by the number of successful submissions: the fewer the submissions, the harder the problem. Given the number of successful submissions for problems A, B, and C ($S_A, S_B, S_C$), determine who wins the bet:
- If $S_C$ is the minimum, Alice wins.
- If $S_B$ is the minimum, Bob wins.
- If $S_A$ is the minimum, it is a Draw.

## Intuition & Mathematical Observation
The problem asks us to identify the minimum value among three integers ($S_A, S_B, S_C$). Since the problem explicitly defines the "hardest" problem as the one with the lowest submission count, we simply need to compare the three inputs:

1. Calculate $min\_val = \min(S_A, S_B, S_C)$.
2. Use conditional statements to check which variable holds this minimum value.
3. Output the corresponding winner based on the problem's rules.

Because the constraints are small ($1 \le S_A, S_B, S_C \le 100$), standard integer comparisons are highly efficient and safe from overflow.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case. We perform a constant number of comparisons regardless of the input values.
- **Space Complexity**: $O(1)$. We only use a few integer variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The "hardest" problem is defined as the one with the minimum number of successful submissions.
 * We are given S_A, S_B, S_C.
 * - If min(S_A, S_B, S_C) == S_C, Alice wins.
 * - If min(S_A, S_B, S_C) == S_B, Bob wins.
 * - If min(S_A, S_B, S_C) == S_A, it's a Draw.
 */

void solve() {
    int sa, sb, sc;
    if (!(cin >> sa >> sb >> sc)) return;

    // Find the minimum value among the three using an initializer list
    int min_val = min({sa, sb, sc});

    // Determine the winner based on which problem had the minimum submissions
    if (min_val == sc) {
        cout << "Alice" << "\n";
    } else if (min_val == sb) {
        cout << "Bob" << "\n";
    } else {
        cout << "Draw" << "\n";
    }
}

int main() {
    // Fast I/O setup for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}
```