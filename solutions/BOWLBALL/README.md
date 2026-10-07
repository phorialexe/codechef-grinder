# [Bowling Balls (BOWLBALL)](https://www.codechef.com/problems/BOWLBALL)

- **Difficulty Rating**: 580
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an array of $N$ bowling ball weights, we need to determine how many of these weights fall within the inclusive range $[X, Y]$. That is, we need to count the number of elements $A_i$ such that $X \le A_i \le Y$.

## Intuition & Mathematical Observation
The problem asks for a simple filtering operation. Since the constraints on $N$ are small ($N \le 100$), we do not need any advanced data structures or pre-processing. 

We can iterate through each weight $A_i$ provided in the input and check the condition `a >= x && a <= y`. If the condition evaluates to true, we increment a counter. After processing all $N$ elements, the counter will hold the total number of balls that satisfy the criteria.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the number of bowling balls. We perform a single pass through the input array.
- **Space Complexity**: $O(1)$, as we only store a few integer variables (`n`, `x`, `y`, `a`, and `count`) regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: BOWLBALL
 * The task is to count how many elements A_i in an array satisfy X <= A_i <= Y.
 * Constraints are small (N <= 100), so a simple linear scan O(N) per test case is optimal.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n, x, y;
        cin >> n >> x >> y;
        
        int count = 0;
        for (int i = 0; i < n; ++i) {
            int a;
            cin >> a;
            // Check if the bowling ball weight is within the inclusive range [X, Y]
            if (a >= x && a <= y) {
                count++;
            }
        }
        
        cout << count << "\n";
    }

    return 0;
}
```