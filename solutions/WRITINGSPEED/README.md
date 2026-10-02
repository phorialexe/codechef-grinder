# [Writing Speed (WRITINGSPEED)](https://www.codechef.com/problems/WRITINGSPEED)

- **Difficulty Rating**: 271
- **Solved in**: 1 attempt(s)

## Problem Summary
Rahul needs to write 5 pages. He can write one page in $X$ minutes. Given that he has a total time limit of 60 minutes, determine if he can complete all 5 pages within the time limit.

## Intuition & Mathematical Observation
The problem asks whether the total time taken to write 5 pages is less than or equal to 60 minutes.
- The time taken to write one page is $X$ minutes.
- The time taken to write 5 pages is $5 \times X$ minutes.
- The condition for success is: $5 \times X \le 60$.

By simplifying the inequality:
$X \le \frac{60}{5}$
$X \le 12$

Thus, if the input $X$ is less than or equal to 12, Rahul can finish his work in time. Otherwise, he cannot.

## Complexity Analysis
- **Time Complexity**: $O(1)$ — The solution performs a constant number of arithmetic operations and comparisons, regardless of the input value.
- **Space Complexity**: $O(1)$ — We only use a single integer variable to store the input, requiring constant extra space.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Rahul has 5 pages to write.
 * Time limit = 60 minutes.
 * Time per page = X minutes.
 * Total time taken = 5 * X minutes.
 * Condition: 5 * X <= 60
 * Simplifying: X <= 12
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int X;
    // Read the time taken per page
    if (!(cin >> X)) return 0;

    // Rahul needs to complete 5 pages.
    // Total time = 5 * X.
    // Constraint is 60 minutes.
    if (5 * X <= 60) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }

    return 0;
}
```