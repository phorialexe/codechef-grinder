# [Valentine Gifts (VAL142)](https://www.codechef.com/problems/VAL142)

- **Difficulty Rating**: 729
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef wants to give gifts for 7 consecutive days. The rule is that the number of gifts given on any day $i$ (where $i > 1$) must be at least twice the number of gifts given on day $i-1$. Given a total number of gifts $X$, determine if it is possible to distribute them over 7 days while satisfying this condition.

## Intuition & Mathematical Observation
To determine if it is possible to satisfy the condition, we must find the **minimum** number of gifts required to fulfill the requirement for 7 days. If the total gifts $X$ is less than this minimum, it is impossible to satisfy the condition.

Let $a_i$ be the number of gifts on day $i$. We are given:
- $a_1 \ge 1$
- $a_2 \ge 2 \times a_1$
- $a_3 \ge 2 \times a_2$
- ...
- $a_7 \ge 2 \times a_6$

To minimize the total sum $S = \sum_{i=1}^{7} a_i$, we choose the smallest possible values for each day:
- $a_1 = 1$
- $a_2 = 2 \times 1 = 2$
- $a_3 = 2 \times 2 = 4$
- $a_4 = 2 \times 4 = 8$
- $a_5 = 2 \times 8 = 16$
- $a_6 = 2 \times 16 = 32$
- $a_7 = 2 \times 32 = 64$

The minimum sum is:
$1 + 2 + 4 + 8 + 16 + 32 + 64 = 127$

Thus, if $X \ge 127$, Chef can distribute the gifts (by giving exactly these amounts, or more on the final day). If $X < 127$, it is mathematically impossible to satisfy the doubling constraint.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a constant time comparison.
- **Space Complexity**: $O(1)$, as we only use a few integer variables regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to find if there exist 7 positive integers a1, a2, ..., a7 such that:
 * a1 >= 1, a2 >= 2*a1, ..., a7 >= 2*a6.
 * The minimum sum is 1 + 2 + 4 + 8 + 16 + 32 + 64 = 127.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        int x;
        cin >> x;
        
        // Check if the total gifts X can cover the minimum requirement of 127
        if (x >= 127) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
    
    return 0;
}
```