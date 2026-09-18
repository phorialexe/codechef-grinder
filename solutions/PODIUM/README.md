# [Podium Finish (PODIUM)](https://www.codechef.com/problems/PODIUM)

- **Difficulty Rating**: 341
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef finishes a race in 3rd place. We are given two values:
- $A$: The time gap between the 3rd place (Chef) and the 2nd place runner.
- $B$: The time gap between the 2nd place runner and the 1st place winner.

The goal is to calculate the total time gap between the 3rd place (Chef) and the 1st place winner.

## Intuition & Mathematical Observation
The problem describes a simple additive relationship. If Chef is $A$ seconds behind the 2nd place, and the 2nd place is $B$ seconds behind the 1st place, the total time difference between the 3rd and 1st place is simply the sum of these two intervals:
$$\text{Total Gap} = A + B$$

Since the constraints are very small ($1 \le A, B \le 10$), this calculation will always fit within standard integer types.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a constant time addition operation.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef is in 3rd place.
 * Gap between Chef (3rd) and Runner-up (2nd) = A
 * Gap between Runner-up (2nd) and Winner (1st) = B
 * Total gap between Chef (3rd) and Winner (1st) = A + B
 * 
 * Constraints:
 * T <= 100
 * 1 <= A, B <= 10
 * The sum will be at most 20, which fits easily into a standard integer.
 */

int main() {
    // Fast I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long a, b;
        if (cin >> a >> b) {
            // The time gap between Chef and the winner is the sum of the gaps
            cout << (a + b) << "\n";
        }
    }

    return 0;
}
```