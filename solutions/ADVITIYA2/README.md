# [Judged (ADVITIYA2)](https://www.codechef.com/problems/ADVITIYA2)

- **Difficulty Rating**: 453
- **Solved in**: 1 attempt(s)

## Problem Summary
A participant is judged by 5 judges, each giving a score of either `0` (dislike) or `1` (like). The participant qualifies if they receive a "like" from at least 4 out of the 5 judges. Given the 5 scores, determine if the participant qualifies.

## Intuition & Mathematical Observation
The problem asks us to verify a simple threshold condition. Since there are exactly 5 judges and each judge provides a binary input (0 or 1), the total score is simply the sum of these inputs. 

- Let $S$ be the sum of the 5 scores: $S = \sum_{i=1}^{5} r_i$.
- The condition for qualification is $S \ge 4$.
- If $S \ge 4$, output "YES"; otherwise, output "NO".

This approach is efficient as it avoids complex conditional logic and handles the input stream linearly.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case. Since we always process exactly 5 integers regardless of the input values, the operations per test case are constant. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$. We only use a few integer variables (`sum`, `r`, `t`) to store the current state, requiring constant auxiliary space.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: ADVITIYA2
 * Logic: The participant qualifies if the sum of the 5 judge responses (0 or 1)
 * is greater than or equal to 4.
 */

int main() {
    // Fast I/O setup for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;

    while (t--) {
        int sum = 0;
        // Read the 5 judge scores
        for (int i = 0; i < 5; ++i) {
            int r;
            cin >> r;
            sum += r;
        }

        // Check if at least 4 judges liked the performance
        if (sum >= 4) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }

    return 0;
}
```