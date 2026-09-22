# [Pass the Exam (PASSTHEEXAM)](https://www.codechef.com/problems/PASSTHEEXAM)

- **Difficulty Rating**: 424
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef takes an exam consisting of three sections with scores $A$, $B$, and $C$. To pass the exam, Chef must satisfy two conditions simultaneously:
1. The total score ($A + B + C$) must be at least $100$.
2. Each individual section score ($A$, $B$, and $C$) must be at least $10$.

If both conditions are met, output `PASS`; otherwise, output `FAIL`.

## Intuition & Mathematical Observation
The problem is a straightforward implementation of conditional logic. We are given three integers representing the scores. We simply need to evaluate a boolean expression:
- **Condition 1**: `(A + B + C) >= 100`
- **Condition 2**: `(A >= 10) && (B >= 10) && (C >= 10)`

If both conditions evaluate to `true`, the student passes. Since the constraints are small ($0 \le A, B, C \le 100$), we can use standard integer arithmetic without worrying about overflow.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a constant number of arithmetic and comparison operations, resulting in $O(1)$ per test case.
- **Space Complexity**: $O(1)$, as we only use a few integer variables to store the input scores regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef passes if:
 * 1. Total score (A + B + C) >= 100
 * 2. Each section score (A, B, C) >= 10
 * 
 * Constraints:
 * 0 <= A, B, C <= 100
 * T <= 1000
 * Time Complexity: O(T)
 * Space Complexity: O(1)
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

        // Check conditions:
        // 1. Total score >= 100
        // 2. Each section >= 10
        if ((a + b + c >= 100) && (a >= 10) && (b >= 10) && (c >= 10)) {
            cout << "PASS" << "\n";
        } else {
            cout << "FAIL" << "\n";
        }
    }

    return 0;
}
```