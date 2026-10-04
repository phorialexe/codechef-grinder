# [Shoe Fit (SHOEFIT)](https://www.codechef.com/problems/SHOEFIT)

- **Difficulty Rating**: 925
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given three shoes, each represented by either `0` (left shoe) or `1` (right shoe). We need to determine if it is possible to form at least one pair consisting of one left shoe and one right shoe. If it is possible, output `1`; otherwise, output `0`.

## Intuition & Mathematical Observation
The problem asks if we have at least one `0` and at least one `1` among the three given inputs ($A, B, C$).

1.  **Case 1: All shoes are the same.**
    *   If $A=0, B=0, C=0$, the sum is $0$. We have no right shoe.
    *   If $A=1, B=1, C=1$, the sum is $3$. We have no left shoe.
    *   In both these scenarios, we cannot form a pair.
2.  **Case 2: There is a mix of shoes.**
    *   If the sum of the three shoes is $1$ (e.g., $0, 0, 1$), we have at least one of each.
    *   If the sum of the three shoes is $2$ (e.g., $1, 1, 0$), we have at least one of each.
    *   In both these scenarios, we can successfully form a pair.

**Conclusion:** We can form a pair if and only if the sum of the three inputs is strictly greater than $0$ and strictly less than $3$.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a constant number of arithmetic operations, resulting in $O(1)$ per test case.
- **Space Complexity**: $O(1)$, as we only use a few integer variables regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given three shoes, each represented as 0 (left) or 1 (right).
 * We need to determine if we can form a pair (one left and one right).
 * 
 * Logic:
 * - If all three shoes are 0, we have no right shoe (sum = 0).
 * - If all three shoes are 1, we have no left shoe (sum = 3).
 * - In any other case, we have at least one 0 and at least one 1.
 * 
 * Therefore, the condition to be able to go out is:
 * (sum of A, B, C > 0) AND (sum of A, B, C < 3).
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;
        
        int sum = a + b + c;
        
        // If sum is 0, all are left shoes.
        // If sum is 3, all are right shoes.
        // Otherwise, we have a mix of 0s and 1s.
        if (sum > 0 && sum < 3) {
            cout << 1 << "\n";
        } else {
            cout << 0 << "\n";
        }
    }
    
    return 0;
}
```