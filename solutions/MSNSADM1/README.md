# [Football (MSNSADM1)](https://www.codechef.com/problems/MSNSADM1)

- **Difficulty Rating**: 1102
- **Solved in**: 1 attempt(s)

## Problem Summary
In this problem, we are given the statistics of $N$ football players. Each player has a number of goals scored ($A_i$) and a number of fouls committed ($B_i$). The score for each player is calculated using the formula:
$$\text{Score} = (A_i \times 20) - (B_i \times 10)$$
If the calculated score is negative, it is treated as $0$. Our goal is to determine the maximum score achieved by any player in the given list.

## Intuition & Mathematical Observation
The problem is a straightforward implementation task. For each player, we perform a simple linear calculation:
1. Multiply the number of goals by 20.
2. Multiply the number of fouls by 10.
3. Subtract the fouls from the goals.
4. Apply the constraint: if the result is less than 0, reset it to 0.
5. Keep track of the maximum value encountered while iterating through all players.

Since the constraints are small ($N \le 150$ and $T \le 100$), a simple $O(N)$ loop per test case is highly efficient and will easily pass within the time limit.

## Complexity Analysis
- **Time Complexity**: $O(T \times N)$, where $T$ is the number of test cases and $N$ is the number of players. Given the constraints, this results in approximately $1.5 \times 10^4$ operations, which is well within the 1-second limit.
- **Space Complexity**: $O(N)$ to store the goals and fouls arrays. This can be optimized to $O(1)$ by processing the input on the fly, but $O(N)$ is perfectly acceptable given the memory limits.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * For each player i, points = (A[i] * 20) - (B[i] * 10).
 * If points < 0, points = 0.
 * We need to find the maximum points among all players.
 * 
 * Constraints:
 * T <= 100, N <= 150.
 * A[i], B[i] <= 50.
 * Max possible points = 50 * 20 = 1000.
 * Min possible points = 0 (after adjustment).
 * Time complexity: O(T * N), which is well within the 1s limit.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        for (int i = 0; i < n; ++i) cin >> b[i];

        long long max_points = 0;
        for (int i = 0; i < n; ++i) {
            long long current_points = (long long)a[i] * 20 - (long long)b[i] * 10;
            if (current_points < 0) {
                current_points = 0;
            }
            if (current_points > max_points) {
                max_points = current_points;
            }
        }
        cout << max_points << "\n";
    }

    return 0;
}
```