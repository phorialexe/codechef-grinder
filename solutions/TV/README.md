# [Television Channels (TV)](https://www.codechef.com/problems/TV)

- **Difficulty Rating**: 324
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given a total of $X$ television channels, numbered from $1$ to $X$. Due to a technical issue, all even-numbered channels stop working. The goal is to determine how many channels remain functional, which corresponds to the count of odd-numbered channels in the range $[1, X]$.

## Intuition & Mathematical Observation
To find the number of odd integers in the range $[1, X]$, we can observe the pattern:
- If $X = 1$, the odd channel is $\{1\}$ (Count: 1).
- If $X = 2$, the odd channel is $\{1\}$ (Count: 1).
- If $X = 3$, the odd channels are $\{1, 3\}$ (Count: 2).
- If $X = 4$, the odd channels are $\{1, 3\}$ (Count: 2).

The pattern shows that for any integer $X$, the number of odd integers is given by $\lceil X / 2 \rceil$. In integer arithmetic, this is equivalent to the formula:
$$\text{Result} = \frac{X + 1}{2}$$

This formula works because:
- If $X$ is even, $X+1$ is odd, and integer division truncates the $.5$, effectively performing the ceiling operation.
- If $X$ is odd, $X+1$ is even, and dividing by $2$ gives the exact count.

## Complexity Analysis
- **Time Complexity**: $O(1)$ — The solution performs a single arithmetic calculation regardless of the input size.
- **Space Complexity**: $O(1)$ — Only a single integer variable is used to store the input.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given X channels numbered 1 to X.
 * Even-numbered channels stop working.
 * We need to count the number of odd-numbered channels in the range [1, X].
 * 
 * Logic:
 * If X is even, the number of odd channels is X / 2.
 * If X is odd, the number of odd channels is (X + 1) / 2.
 * This can be simplified using integer division: (X + 1) / 2.
 * 
 * Example:
 * X = 5: (5 + 1) / 2 = 3. (1, 3, 5) - Correct.
 * X = 100: (100 + 1) / 2 = 50. (1, 3, ..., 99) - Correct.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int X;
    if (!(cin >> X)) return 0;

    // The number of odd integers in the range [1, X] is ceil(X / 2.0)
    // Using integer arithmetic: (X + 1) / 2
    int working_channels = (X + 1) / 2;

    cout << working_channels << "\n";

    return 0;
}
```