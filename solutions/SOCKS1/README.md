# [Valid Pair (SOCKS1)](https://www.codechef.com/problems/SOCKS1)

- **Difficulty Rating**: 851
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given three integers $A$, $B$, and $C$, representing the colors of three individual socks. The goal is to determine if it is possible to form at least one matching pair. A pair is formed if any two socks have the same color. We need to output "YES" if a pair exists, and "NO" otherwise.

## Intuition & Mathematical Observation
To form a pair, we simply need to check if any two of the three given integers are equal. There are three possible combinations to check:
1. Does $A$ equal $B$?
2. Does $A$ equal $C$?
3. Does $B$ equal $C$?

If any of these conditions evaluate to true, then at least two socks share the same color, and we can successfully form a pair. Using the logical OR (`||`) operator in C++, we can combine these checks into a single conditional statement.

## Complexity Analysis
- **Time Complexity**: $O(1)$ — The solution performs a constant number of comparisons regardless of the input values.
- **Space Complexity**: $O(1)$ — We only use a fixed amount of memory to store the three integers.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given three integers A, B, and C representing the colors of three socks.
 * We need to determine if at least two of these socks have the same color.
 * This is equivalent to checking if:
 * A == B OR A == C OR B == C.
 * 
 * Time Complexity: O(1) per test case.
 * Space Complexity: O(1).
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int A, B, C;
    // Reading the three space-separated integers
    if (!(cin >> A >> B >> C)) return 0;

    // Check if any pair matches
    if (A == B || A == C || B == C) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }

    return 0;
}
```