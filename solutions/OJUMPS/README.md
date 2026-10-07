# [Chef-jumping (OJUMPS)](https://www.codechef.com/problems/OJUMPS)

- **Difficulty Rating**: 1232
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef starts at position 0 on a number line. He makes jumps of length 1, 2, and 3 in a repeating cycle (1, 2, 3, 1, 2, 3, ...). Given an integer $a$, determine if Chef can land exactly on position $a$ after some number of jumps.

## Intuition & Mathematical Observation
The sequence of jumps is periodic with a cycle of 3 jumps. The sum of one full cycle is $1 + 2 + 3 = 6$. 

Let's track the positions reached after each jump:
- Jump 1: $0 + 1 = 1$
- Jump 2: $1 + 2 = 3$
- Jump 3: $3 + 3 = 6$
- Jump 4: $6 + 1 = 7$
- Jump 5: $7 + 2 = 9$
- Jump 6: $9 + 3 = 12$

If we look at these positions modulo 6:
- $0 \pmod 6 = 0$
- $1 \pmod 6 = 1$
- $3 \pmod 6 = 3$
- $6 \pmod 6 = 0$
- $7 \pmod 6 = 1$
- $9 \pmod 6 = 3$
- $12 \pmod 6 = 0$

The pattern of reachable positions modulo 6 is $\{0, 1, 3\}$. Any position $a$ is reachable if and only if $a \pmod 6$ is equal to 0, 1, or 3.

## Complexity Analysis
- **Time Complexity**: $O(1)$, as the solution involves a simple arithmetic modulo operation and a conditional check.
- **Space Complexity**: $O(1)$, as we only use a single variable to store the input.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef jumps in a sequence: +1, +2, +3, +1, +2, +3, ...
 * The sum of one full cycle (1+2+3) is 6.
 * The reachable points modulo 6 are always 0, 1, or 3.
 * If a % 6 is 0, 1, or 3, Chef can reach the point.
 * Otherwise, he cannot.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long a;
    if (!(cin >> a)) return 0;

    long long remainder = a % 6;

    // Check if the remainder falls into the set of reachable values {0, 1, 3}
    if (remainder == 0 || remainder == 1 || remainder == 3) {
        cout << "yes" << "\n";
    } else {
        cout << "no" << "\n";
    }

    return 0;
}
```