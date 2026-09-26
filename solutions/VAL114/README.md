# [Valentines Contest (VAL114)](https://www.codechef.com/problems/VAL114)

- **Difficulty Rating**: 318
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to determine if a given contest number $N$ corresponds to the Valentine's Day contest. Specifically, we are told that Starters 120 is held today, and we need to check if $N = 121$, which is hypothesized to be the Valentine's Day contest. If $N$ is 121, we output "Likely"; otherwise, we output "Unlikely".

## Intuition & Mathematical Observation
The problem is a straightforward conditional check. Given the constraints $120 \le N \le 123$, we simply need to compare the input integer $N$ against the target value $121$. 
- If $N == 121$, the condition is satisfied.
- For any other value in the given range, the condition is not satisfied.

This can be implemented using a simple `if-else` statement.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we are performing a single constant-time comparison.
- **Space Complexity**: $O(1)$, as we only use a single integer variable to store the input.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The problem states that Starters 120 is today.
 * Starters 121 is likely to be on Valentine's day.
 * Given N, we need to check if N == 121.
 * 
 * Constraints: 120 <= N <= 123.
 * Time Complexity: O(1) per test case.
 * Space Complexity: O(1).
 */

int main() {
    // Optimize I/O operations for faster execution
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (cin >> N) {
        // Check if the contest number is 121
        if (N == 121) {
            cout << "Likely" << "\n";
        } else {
            cout << "Unlikely" << "\n";
        }
    }

    return 0;
}
```