# [Chefland Visa (VISA)](https://www.codechef.com/problems/VISA)

- **Difficulty Rating**: 857
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef wants to apply for a visa. To be eligible, the applicant must meet three specific criteria based on their past performance:
1. They must have solved at least $x_1$ problems (where $x_2$ is the number of problems they have solved).
2. They must have a rating of at least $y_1$ (where $y_2$ is their current rating).
3. Their last submission must have been made no more than $z_1$ months ago (where $z_2$ is the number of months since their last submission).

We need to determine if the applicant is eligible for the visa by checking if all three conditions are satisfied simultaneously.

## Intuition & Mathematical Observation
The problem is a straightforward implementation of conditional logic. We are given three pairs of values $(x_1, x_2)$, $(y_1, y_2)$, and $(z_1, z_2)$. The conditions for eligibility are:
1. $x_2 \ge x_1$
2. $y_2 \ge y_1$
3. $z_2 \le z_1$

If all three boolean expressions evaluate to `true`, the output should be "YES". If any one of them is `false`, the output should be "NO". Since the constraints are small and the logic is constant-time, a simple `if-else` statement inside the test case loop is sufficient.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a constant number of comparisons, resulting in $O(1)$ per test case.
- **Space Complexity**: $O(1)$, as we only use a few integer variables to store the input values regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The problem requires checking three conditions:
 * 1. x2 >= x1 (Problems solved)
 * 2. y2 >= y1 (Rating)
 * 3. z2 <= z1 (Last submission time)
 * 
 * If all three are true, output "YES", otherwise "NO".
 * Constraints are small (up to 5000 test cases), so O(1) per test case is optimal.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        int x1, x2, y1, y2, z1, z2;
        cin >> x1 >> x2 >> y1 >> y2 >> z1 >> z2;
        
        // Check the three criteria:
        // 1. Chef must have solved at least x1 problems (x2 >= x1)
        // 2. Chef must have at least y1 rating (y2 >= y1)
        // 3. Chef's last submission must be at most z1 months ago (z2 <= z1)
        
        if (x2 >= x1 && y2 >= y1 && z2 <= z1) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
    
    return 0;
}
```