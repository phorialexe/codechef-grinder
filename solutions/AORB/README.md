# [A or B (AORB)](https://www.codechef.com/problems/AORB)

- **Difficulty Rating**: 728
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef has two problems, A and B. Problem A starts with 500 points and loses 2 points for every minute passed. Problem B starts with 1000 points and loses 4 points for every minute passed. Given the time $X$ taken to solve problem A and the time $Y$ taken to solve problem B, we need to determine the maximum total score Chef can achieve by choosing the optimal order to solve the problems.

## Intuition & Mathematical Observation
To maximize the score, we must consider the two possible sequences:

1.  **Order 1: Solve A first, then B**
    *   Time taken for A: $X$
    *   Time taken for B: $X + Y$
    *   Score A: $500 - (X \times 2)$
    *   Score B: $1000 - ((X + Y) \times 4)$
    *   **Total 1**: $(500 - 2X) + (1000 - 4X - 4Y) = 1500 - 6X - 4Y$

2.  **Order 2: Solve B first, then A**
    *   Time taken for B: $Y$
    *   Time taken for A: $X + Y$
    *   Score B: $1000 - (Y \times 4)$
    *   Score A: $500 - ((X + Y) \times 2)$
    *   **Total 2**: $(1000 - 4Y) + (500 - 2X - 2Y) = 1500 - 2X - 6Y$

By calculating both totals and taking the maximum, we ensure the optimal strategy is chosen for any given $X$ and $Y$.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution involves simple arithmetic operations. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and calculated scores.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef has two problems A and B.
 * A starts at 500 points, loses 2 points per minute.
 * B starts at 1000 points, loses 4 points per minute.
 * 
 * Order 1: A then B -> Total = 1500 - 6X - 4Y
 * Order 2: B then A -> Total = 1500 - 2X - 6Y
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long x, y;
        cin >> x >> y;

        // Option 1: A then B
        long long score1 = (500 - (x * 2)) + (1000 - ((x + y) * 4));
        
        // Option 2: B then A
        long long score2 = (1000 - (y * 4)) + (500 - ((x + y) * 2));

        // Output the maximum of the two
        cout << max(score1, score2) << "\n";
    }

    return 0;
}
```