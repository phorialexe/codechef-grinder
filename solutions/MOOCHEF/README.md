# [Moody Chef (MOOCHEF)](https://www.codechef.com/problems/MOOCHEF)

- **Difficulty Rating**: 991
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef starts with a happiness level of $0$. He encounters a sequence of $N$ days, each with a specific value $A_i$. For each day:
- If $l \le A_i \le r$, his happiness increases by $1$.
- Otherwise, his happiness decreases by $1$.

We need to determine the maximum and minimum happiness levels Chef reaches throughout the entire process, including the initial state of $0$.

## Intuition & Mathematical Observation
The problem asks us to track the state of a variable (`current_happiness`) as it changes over time. Since the happiness level is cumulative, we can maintain a running total.

1. **Initialization**: Start with `current_happiness = 0`. Since the problem implies the initial state is part of the experience, we initialize both `max_happiness` and `min_happiness` to $0$.
2. **Iteration**: For each input value $A_i$, we apply the conditional logic:
   - If $l \le A_i \le r$, increment `current_happiness`.
   - Else, decrement `current_happiness`.
3. **Tracking**: After each update, compare the `current_happiness` with the stored `max_happiness` and `min_happiness` to update them if the current value exceeds or falls below the recorded extremes.
4. **Edge Cases**: The constraints allow for $N$ up to $10^5$, so an $O(N)$ approach is optimal. Using `long long` for happiness is good practice, though `int` would suffice given the constraints on $N$.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, as we iterate through the array of $N$ elements exactly once.
- **Space Complexity**: $O(1)$ auxiliary space, as we only store a few variables to track the current and extreme happiness levels, regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef starts with happiness = 0.
 * For each element A[i]:
 * If l <= A[i] <= r, happiness increases by 1.
 * Else, happiness decreases by 1.
 * We track the running happiness at every step and update the 
 * global maximum and global minimum encountered.
 */

void solve() {
    int N;
    long long l, r;
    if (!(cin >> N >> l >> r)) return;

    long long current_happiness = 0;
    long long max_happiness = 0;
    long long min_happiness = 0;

    for (int i = 0; i < N; ++i) {
        long long val;
        cin >> val;
        
        // Update happiness based on the range [l, r]
        if (val >= l && val <= r) {
            current_happiness += 1;
        } else {
            current_happiness -= 1;
        }
        
        // Update global extremes
        if (current_happiness > max_happiness) {
            max_happiness = current_happiness;
        }
        if (current_happiness < min_happiness) {
            min_happiness = current_happiness;
        }
    }

    cout << max_happiness << " " << min_happiness << "\n";
}

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        solve();
    }
    return 0;
}
```