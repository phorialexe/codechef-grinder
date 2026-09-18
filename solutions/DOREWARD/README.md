# [Donation Rewards (DOREWARD)](https://www.codechef.com/problems/DOREWARD)

- **Difficulty Rating**: 395
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to categorize a donation amount $X$ into one of three reward tiers based on the following rules:
- If the donation $X$ is 3 or less, the reward is **BRONZE**.
- If the donation $X$ is greater than 3 but 6 or less, the reward is **SILVER**.
- If the donation $X$ is greater than 6, the reward is **GOLD**.

## Intuition & Mathematical Observation
The problem is a straightforward conditional logic task. We can map the input $X$ directly to the output strings using simple `if-else` statements:
1. **Condition 1**: $X \le 3 \implies$ `BRONZE`
2. **Condition 2**: $3 < X \le 6 \implies$ `SILVER`
3. **Condition 3**: $X > 6 \implies$ `GOLD`

Since the conditions are mutually exclusive and cover all possible positive integers for $X$, a standard `if-else if-else` structure is sufficient to solve the problem efficiently.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a constant number of comparisons, resulting in $O(1)$ per test case.
- **Space Complexity**: $O(1)$, as we only use a single integer variable to store the input $X$ and do not require any additional data structures.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Donation Rewards
 * Logic:
 * - If X <= 3: BRONZE
 * - If 3 < X <= 6: SILVER
 * - If X > 6: GOLD
 * 
 * Time Complexity: O(T) where T is the number of test cases.
 * Space Complexity: O(1) as we only use a few variables.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        int x;
        cin >> x;
        
        if (x <= 3) {
            cout << "BRONZE" << "\n";
        } else if (x <= 6) {
            cout << "SILVER" << "\n";
        } else {
            cout << "GOLD" << "\n";
        }
    }
    
    return 0;
}
```