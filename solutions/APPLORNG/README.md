# [Apples and Oranges (APPLORNG)](https://www.codechef.com/problems/APPLORNG)

- **Difficulty Rating**: 355
- **Solved in**: 1 attempt(s)

## Problem Summary
Bob has $X$ amount of money. He wants to buy 1 kg of apples costing $A$ and 1 kg of oranges costing $B$. We need to determine if Bob has enough money to purchase both items. Specifically, we must output "Yes" if $X \ge A + B$, and "No" otherwise.

## Intuition & Mathematical Observation
The problem is a straightforward comparison task. 
1. The total cost of the fruits is the sum of the individual costs: $Total = A + B$.
2. Bob can afford the purchase if his available money $X$ is greater than or equal to the total cost.
3. Since the constraints are $X, A, B \le 10^5$, the sum $A + B$ will not exceed $2 \times 10^5$, which fits comfortably within a standard 32-bit integer. However, using `long long` is a safe practice to prevent potential overflow in similar problems with larger constraints.

## Complexity Analysis
- **Time Complexity**: $O(1)$ because the solution performs a constant number of arithmetic operations and a single comparison.
- **Space Complexity**: $O(1)$ as we only use a fixed amount of memory to store the three input variables.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Apples and Oranges
 * Logic: Bob needs to buy 1kg of apples (cost A) and 1kg of oranges (cost B).
 * Total cost = A + B.
 * Bob can afford this if X >= A + B.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long X;
    if (!(cin >> X)) return 0;
    
    long long A, B;
    cin >> A >> B;

    // Check if the total cost is less than or equal to the money Bob has
    if (X >= (A + B)) {
        cout << "Yes" << "\n";
    } else {
        cout << "No" << "\n";
    }

    return 0;
}
```