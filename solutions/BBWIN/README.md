# [Extreme Basketball (BBWIN)](https://www.codechef.com/problems/BBWIN)

- **Difficulty Rating**: 853
- **Solved in**: 2 attempt(s)

## Problem Summary
Alice currently has a score of $A$ and Bob has a score of $B$. Alice wants to win the game by having a score $A'$ such that $A' \ge B + 10$. Alice can only increase her score by taking shots worth 3 points (or 2 points, though 3 is more efficient). We need to find the minimum number of shots Alice must take to satisfy the condition.

## Intuition & Mathematical Observation
1. **Target Calculation**: Alice needs her final score $A'$ to be at least $B + 10$. The number of points she needs to gain is $D = \max(0, (B + 10) - A)$.
2. **Efficiency**: To minimize the number of shots, Alice should always prioritize the highest point-value shot available, which is the 3-point shot.
3. **Mathematical Formulation**: 
   - If $D \le 0$, Alice has already met the condition, so 0 shots are required.
   - If $D > 0$, she needs to cover $D$ points using shots of 3 points. The number of shots required is $\lceil D / 3 \rceil$.
   - In integer arithmetic, $\lceil D / 3 \rceil$ can be calculated as `(D + 2) / 3`.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution involves basic arithmetic operations. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few integer variables to store the scores and the result.

## Solution Code

```cpp
#include <iostream>
#include <algorithm>

using namespace std;

/**
 * Problem Analysis:
 * Alice needs her final score A' to satisfy A' >= B + 10.
 * Let D = max(0, B + 10 - A).
 * If D == 0, she needs 0 shots.
 * If D > 0, she wants to reach at least D points using the minimum number of shots.
 * Since each shot is worth 2 or 3 points, to minimize shots, she should prioritize 
 * 3-point shots. The number of shots required to get at least D points is ceil(D / 3).
 */

void solve() {
    int a, b;
    if (!(cin >> a >> b)) return;

    int target_diff = b + 10;
    int needed = target_diff - a;

    if (needed <= 0) {
        cout << 0 << endl;
    } else {
        // We need to cover 'needed' points using shots of 3 (or 2).
        // To minimize shots, we use as many 3s as possible.
        // ceil(needed / 3.0) is equivalent to (needed + 2) / 3 using integer division.
        int shots = (needed + 2) / 3;
        cout << shots << endl;
    }
}

int main() {
    // Optimize I/O operations
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