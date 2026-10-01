# [Chef and Socks (CHEFSOCKS)](https://www.codechef.com/problems/CHEFSOCKS)

- **Difficulty Rating**: 212
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef wants to buy a pair of socks that costs $A$ rupees. Chef already has $X$ rupees in his pocket and his friend gives him an additional $Y$ rupees. We need to determine if Chef has enough money to purchase the socks. Specifically, we must output "YES" if the total money ($X + Y$) is greater than or equal to $A$, and "NO" otherwise.

## Intuition & Mathematical Observation
The problem is a straightforward comparison task. 
1. Chef's total available funds are calculated by the sum of his current money ($X$) and the money received from his friend ($Y$).
2. The condition for being able to afford the socks is:
   $$\text{Total Money} \ge \text{Cost of Socks}$$
   $$(X + Y) \ge A$$
3. If this inequality holds true, Chef can afford the socks; otherwise, he cannot.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution involves only a single addition and a comparison operation.
- **Space Complexity**: $O(1)$, as we only use a constant amount of extra space to store the input variables.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Chef and Socks
 * Logic: Chef can afford the socks if his total money (X + Y) is greater than or equal to the cost (A).
 * Time Complexity: O(1) per test case.
 * Space Complexity: O(1).
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Reading inputs: A (cost), X (Chef's money), Y (friend's money)
    long long A, X, Y;
    if (cin >> A >> X >> Y) {
        // Check if total money (X + Y) is at least A
        if (X + Y >= A) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }

    return 0;
}
```