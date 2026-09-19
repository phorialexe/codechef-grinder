# [Mutated Minions (CHN15A)](https://www.codechef.com/problems/CHN15A)

- **Difficulty Rating**: 777
- **Solved in**: 1 attempt(s)

## Problem Summary
Gru has $N$ minions, each with a specific characteristic value $v_i$. He decides to mutate all his minions by adding a constant value $K$ to their characteristic values. A minion is considered a "Wolverine" minion if its new characteristic value $(v_i + K)$ is perfectly divisible by 7. The goal is to count the total number of Wolverine minions after the mutation.

## Intuition & Mathematical Observation
The problem asks us to evaluate a simple condition for each minion:
1. For every minion with initial value $v$, the new value is $v' = v + K$.
2. We need to check if $v' \pmod 7 == 0$.
3. Since the constraints are small ($N, K \le 100$ and $T \le 100$), we can iterate through each minion's value, perform the addition, check the divisibility condition, and maintain a counter. No complex data structures or pre-processing are required.

## Complexity Analysis
- **Time Complexity**: $O(T \times N)$, where $T$ is the number of test cases and $N$ is the number of minions. Given the constraints, the total number of operations is roughly $10^4$, which easily passes within the 1-second time limit.
- **Space Complexity**: $O(1)$, as we only store a few integer variables and process the input values on the fly without needing to store the entire array.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Mutated Minions (CHN15A)
 * Approach:
 * For each minion with characteristic value 'v', the new value becomes 'v + K'.
 * We need to count how many minions satisfy (v + K) % 7 == 0.
 * 
 * Constraints:
 * T <= 100, N <= 100, K <= 100, v <= 10^5.
 * The values fit comfortably within standard integer types (int is sufficient).
 * Time Complexity: O(T * N), which is at most 10^4 operations, well within the 1s limit.
 * Space Complexity: O(1) auxiliary space if we process input on the fly.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;

    while (t--) {
        int n, k;
        cin >> n >> k;

        int wolverine_count = 0;
        for (int i = 0; i < n; ++i) {
            int v;
            cin >> v;
            // Check if the transmogrified value is divisible by 7
            if ((v + k) % 7 == 0) {
                wolverine_count++;
            }
        }

        cout << wolverine_count << "\n";
    }

    return 0;
}
```