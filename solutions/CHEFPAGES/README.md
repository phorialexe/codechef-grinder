# [Important Pages on CodeChef (CHEFPAGES)](https://www.codechef.com/problems/CHEFPAGES)

- **Difficulty Rating**: 719
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to direct a user to a specific CodeChef URL based on two binary inputs, $A$ and $B$:
1. If $A = 0$, the user should be directed to the **Practice** page.
2. If $A = 1$ and $B = 0$, the user should be directed to the **Contests** page.
3. If $A = 1$ and $B = 1$, the user should be directed to the **Discuss** page.

## Intuition & Mathematical Observation
The problem is a straightforward implementation of conditional logic. Since the input space is very small ($A, B \in \{0, 1\}$), we can use simple `if-else` statements to map the input pairs to their corresponding output strings.

- **Case 1:** $A=0$ (regardless of $B$) $\rightarrow$ `https://www.codechef.com/practice`
- **Case 2:** $A=1, B=0$ $\rightarrow$ `https://www.codechef.com/contests`
- **Case 3:** $A=1, B=1$ $\rightarrow$ `https://discuss.codechef.com`

## Complexity Analysis
- **Time Complexity**: $O(1)$, as the solution performs a constant number of comparisons regardless of the input.
- **Space Complexity**: $O(1)$, as we only store two integer variables.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given two integers A and B (0 or 1).
 * 1. If A == 0: Output "https://www.codechef.com/practice"
 * 2. If A == 1 and B == 0: Output "https://www.codechef.com/contests"
 * 3. If A == 1 and B == 1: Output "https://discuss.codechef.com"
 * 
 * Time Complexity: O(1) per test case.
 * Space Complexity: O(1).
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int A, B;
    // Read the input values A and B
    if (cin >> A >> B) {
        if (A == 0) {
            cout << "https://www.codechef.com/practice" << "\n";
        } else if (A == 1 && B == 0) {
            cout << "https://www.codechef.com/contests" << "\n";
        } else if (A == 1 && B == 1) {
            cout << "https://discuss.codechef.com" << "\n";
        }
    }

    return 0;
}
```