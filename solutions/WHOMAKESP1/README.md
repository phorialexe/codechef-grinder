# [Who Makes P1 (WHOMAKESP1)](https://www.codechef.com/problems/WHOMAKESP1)

- **Difficulty Rating**: 363
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to determine who creates the problem based on two integers:
- $A$: The number of times Tyro needs to be asked before he is convinced to make the problem.
- $B$: The number of times Dom asks Tyro.

If Dom asks Tyro at least $A$ times ($B \ge A$), Tyro makes the problem. Otherwise, if Dom asks fewer than $A$ times ($B < A$), Dom makes the problem himself.

## Intuition & Mathematical Observation
The logic is a direct implementation of the problem statement's condition:
1. **Condition for Tyro**: Tyro is convinced if the number of requests $B$ is greater than or equal to his patience threshold $A$. Thus, if $A \le B$, the output should be "Tyro".
2. **Condition for Dom**: If the number of requests $B$ is strictly less than $A$, Tyro is not convinced, so Dom must make the problem. Thus, if $A > B$, the output should be "Dom".

This is a simple conditional check requiring $O(1)$ operations.

## Complexity Analysis
- **Time Complexity**: $O(1)$, as the solution performs a single comparison regardless of the input values.
- **Space Complexity**: $O(1)$, as we only store two integer variables.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Tyro makes the problem if he is convinced, which happens if the number of times 
 * Dom asks (B) is greater than or equal to Tyro's patience level (A).
 * If B < A, Tyro is not convinced within the allowed attempts, so Dom makes it.
 * 
 * Logic:
 * If A <= B: Tyro makes the problem.
 * If A > B: Dom makes the problem.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int A, B;
    // Read the input values A and B
    if (cin >> A >> B) {
        // Compare the patience level with the number of requests
        if (A <= B) {
            cout << "Tyro" << "\n";
        } else {
            cout << "Dom" << "\n";
        }
    }

    return 0;
}
```