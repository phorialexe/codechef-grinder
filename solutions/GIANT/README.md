# [Giant Wheel (GIANT)](https://www.codechef.com/problems/GIANT)

- **Difficulty Rating**: 293
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks whether a person with a given height $X$ is allowed to ride a giant wheel. According to the rules, a person must have a height of at least 60 units to be eligible for the ride. Given the input $X$, we need to output "Yes" if $X \ge 60$, and "No" otherwise.

## Intuition & Mathematical Observation
The problem is a straightforward conditional check. We are provided with a threshold value of 60. 
- If $X \ge 60$, the condition is satisfied, and the person can ride.
- If $X < 60$, the condition is not satisfied, and the person cannot ride.

This can be implemented using a simple `if-else` statement in any programming language.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as it only involves a single comparison operation.
- **Space Complexity**: $O(1)$, as we only store a single integer variable $X$.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Giant Wheel
 * Logic: Alice can ride if her height X >= 60.
 * Time Complexity: O(1) per test case.
 * Space Complexity: O(1).
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int X;
    // Read the input height X
    if (!(cin >> X)) return 0;

    // Check if height is at least 60
    if (X >= 60) {
        cout << "Yes" << "\n";
    } else {
        cout << "No" << "\n";
    }

    return 0;
}
```