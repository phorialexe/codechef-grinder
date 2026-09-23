# [Chef and Parole (CHEFPAROLE)](https://www.codechef.com/problems/CHEFPAROLE)

- **Difficulty Rating**: 242
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef has been in prison for $X$ days. According to the rules, a prisoner is eligible for parole if they have served at least 7 days. Given the integer $X$, determine if Chef is eligible for parole. Output "Yes" if $X \ge 7$, and "No" otherwise.

## Intuition & Mathematical Observation
The problem is a straightforward conditional check. We are given a single integer $X$ representing the number of days served. The condition for parole is defined as $X \ge 7$. 
- If the input $X$ is greater than or equal to 7, the condition evaluates to true, and we print "Yes".
- If the input $X$ is less than 7, the condition evaluates to false, and we print "No".

This can be implemented using a simple `if-else` statement.

## Complexity Analysis
- **Time Complexity**: $O(1)$ — The solution performs a single comparison and output operation, which takes constant time regardless of the input value.
- **Space Complexity**: $O(1)$ — We only use a single variable to store the input, requiring constant extra space.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Chef and Parole
 * Logic: Chef needs at least 7 days to be released.
 * If X >= 7, output "Yes", otherwise "No".
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Read the integer X representing the number of days served
    long long X;
    if (cin >> X) {
        // Check the condition for parole eligibility
        if (X >= 7) {
            cout << "Yes" << "\n";
        } else {
            cout << "No" << "\n";
        }
    }

    return 0;
}
```