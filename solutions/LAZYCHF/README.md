# [Lazy Chef (LAZYCHF)](https://www.codechef.com/problems/LAZYCHF)

- **Difficulty Rating**: 801
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef has a task that takes $x$ units of time to complete. Due to his laziness, he multiplies the time taken by a factor of $m$, resulting in $m \times x$ units of time. However, there is a strict delay limit $d$, meaning the total time taken cannot exceed $x + d$. We need to determine the actual time Chef takes to complete the task, which is the minimum of his lazy time ($m \times x$) and the maximum allowed time ($x + d$).

## Intuition & Mathematical Observation
The problem asks us to compare two values:
1. **Lazy Time**: $m \times x$
2. **Deadline Time**: $x + d$

Since Chef will take the shortest possible time that satisfies the constraints, we simply need to compute the minimum of these two values. Given the constraints ($x, m \le 10$ and $d < 100$), the result will easily fit within a standard integer, though `long long` is used for robustness.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a constant number of arithmetic operations and a comparison, resulting in $O(1)$ per test case.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef's work takes x units of time.
 * Due to laziness, he takes m * x units of time.
 * However, there is a delay limit d, meaning the maximum time he can take is x + d.
 * Therefore, the actual time taken is the minimum of (m * x) and (x + d).
 * 
 * Constraints:
 * 1 <= T <= 10^4
 * 1 <= x, m <= 10
 * 0 <= d < 100
 */

int main() {
    // Fast I/O for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long x, m, d;
        cin >> x >> m >> d;

        // Calculate the time taken by laziness: m * x
        // Calculate the maximum allowed time: x + d
        // The result is the minimum of these two values.
        long long time_taken = min(m * x, x + d);

        cout << time_taken << "\n";
    }

    return 0;
}
```