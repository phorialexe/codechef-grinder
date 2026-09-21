# [Healthy Sleep (HEALSE)](https://www.codechef.com/problems/HEALSE)

- **Difficulty Rating**: 250
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to evaluate the duration of sleep $H$ (in hours) and categorize it based on a standard of 8 hours:
- If the sleep duration is less than 8 hours, output `LESS`.
- If the sleep duration is exactly 8 hours, output `PERFECT`.
- If the sleep duration is more than 8 hours, output `MORE`.

## Intuition & Mathematical Observation
The problem is a straightforward conditional logic task. We are given a single integer $H$ representing the hours of sleep. By applying simple comparison operators (`<`, `==`, `>`), we can determine which category the input falls into. 

- **Condition 1**: $H < 8 \implies$ `LESS`
- **Condition 2**: $H = 8 \implies$ `PERFECT`
- **Condition 3**: $H > 8 \implies$ `MORE`

Since there is only one input value and no complex data structures are required, a simple `if-else if-else` block is sufficient to solve the problem efficiently.

## Complexity Analysis
- **Time Complexity**: $O(1)$ — The solution performs a constant number of comparisons regardless of the input value.
- **Space Complexity**: $O(1)$ — We only use a single integer variable to store the input, requiring constant extra space.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Healthy Sleep
 * Logic:
 * - If H < 8, output LESS
 * - If H == 8, output PERFECT
 * - If H > 8, output MORE
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int H;
    // Read the input integer H
    if (cin >> H) {
        if (H < 8) {
            cout << "LESS" << "\n";
        } else if (H == 8) {
            cout << "PERFECT" << "\n";
        } else {
            cout << "MORE" << "\n";
        }
    }

    return 0;
}
```