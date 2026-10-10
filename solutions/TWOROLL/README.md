# [Two Rolls (TWOROLL)](https://www.codechef.com/problems/TWOROLL)

- **Difficulty Rating**: 653
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef is currently at position $X$ on a board and wants to reach position $50$. He rolls two dice, where each die has faces numbered $\{Y, Y+1, Y+2, Y+3, Y+4, Y+5\}$. Let the outcomes of the two dice be $d_1$ and $d_2$. Chef wins if his new position $X + d_1 + d_2$ is exactly $50$. We need to determine if it is possible for Chef to reach exactly $50$ given $X$ and $Y$.

## Intuition & Mathematical Observation
To reach position $50$ from $X$, the sum of the two dice $S = d_1 + d_2$ must satisfy the equation:
$$S = 50 - X$$

Since each die can take any value from $Y$ to $Y+5$, we can determine the range of possible sums:
1. **Minimum Sum ($S_{min}$):** Occurs when both dice show the smallest value $Y$.
   $$S_{min} = Y + Y = 2Y$$
2. **Maximum Sum ($S_{max}$):** Occurs when both dice show the largest value $Y+5$.
   $$S_{max} = (Y+5) + (Y+5) = 2Y + 10$$

Because the dice values are consecutive integers, the sum of two dice can result in any integer value between $S_{min}$ and $S_{max}$ inclusive. Therefore, Chef can reach $50$ if and only if the required distance $(50 - X)$ falls within the range $[2Y, 2Y + 10]$.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we are only performing basic arithmetic comparisons.
- **Space Complexity**: $O(1)$, as we only use a few integer variables to store the inputs and calculated bounds.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef is at position X. He needs to reach 50.
 * He rolls two dice, each with values {Y, Y+1, Y+2, Y+3, Y+4, Y+5}.
 * Let the two dice values be d1 and d2.
 * The move distance is S = d1 + d2.
 * Chef wins if X + S = 50, which means S = 50 - X.
 * 
 * The minimum possible sum S_min = Y + Y = 2Y.
 * The maximum possible sum S_max = (Y+5) + (Y+5) = 2Y + 10.
 * 
 * Since each die can take any value from {Y, ..., Y+5}, the sum S can take 
 * any integer value from 2Y to 2Y + 10.
 * 
 * Therefore, Chef can reach 50 if and only if:
 * 2Y <= (50 - X) <= 2Y + 10.
 */

void solve() {
    int X, Y;
    if (!(cin >> X >> Y)) return;

    int target = 50 - X;
    int min_sum = 2 * Y;
    int max_sum = 2 * Y + 10;

    if (target >= min_sum && target <= max_sum) {
        cout << "Yes" << "\n";
    } else {
        cout << "No" << "\n";
    }
}

int main() {
    // Fast I/O
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