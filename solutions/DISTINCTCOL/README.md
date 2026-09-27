# [Distinct Colors (DISTINCTCOL)](https://www.codechef.com/problems/DISTINCTCOL)

- **Difficulty Rating**: 760
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given $N$ types of colors, where the $i$-th color has $A_i$ balls. We need to place all these balls into boxes such that no box contains more than one ball of the same color. The goal is to find the minimum number of boxes required to satisfy this condition.

## Intuition & Mathematical Observation
To ensure that no two balls of the same color share a box, every ball of a specific color $i$ must be placed in a unique box. If there are $A_i$ balls of color $i$, we are forced to use at least $A_i$ distinct boxes.

Since this constraint applies to every color type independently, the total number of boxes must be at least the count of the most frequent color. Mathematically, the minimum number of boxes required is:
$$\text{Result} = \max(A_1, A_2, \dots, A_N)$$

If we have $K = \max(A_i)$ boxes, we can distribute the balls using a cyclic approach (e.g., placing the $j$-th ball of color $i$ into box $(j \pmod K)$) to ensure no two balls of the same color ever collide. Thus, the maximum value in the array is both the lower bound and the sufficient number of boxes.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, as we iterate through the input array exactly once to find the maximum value.
- **Space Complexity**: $O(1)$ auxiliary space, as we only store the current maximum value while reading the input.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have N types of colors, with A_i balls of color i.
 * We need to place these balls into boxes such that no box contains two balls of the same color.
 * 
 * If we have A_i balls of a specific color, we must have at least A_i boxes 
 * to ensure that no two balls of that color share a box.
 * 
 * Since this constraint must hold for every color i (1 <= i <= N), 
 * the minimum number of boxes required must be at least max(A_1, A_2, ..., A_N).
 * 
 * If we have max(A_1, ..., A_N) boxes, we can always distribute the balls 
 * such that no box contains two balls of the same color by using a cyclic 
 * distribution strategy. Thus, the answer is simply the maximum value in the array A.
 */

int main() {
    // Optimize I/O operations for faster execution
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n;
        cin >> n;
        
        long long max_balls = 0;
        for (int i = 0; i < n; ++i) {
            long long a;
            cin >> a;
            // Update max_balls if the current color count is larger
            if (a > max_balls) {
                max_balls = a;
            }
        }
        
        cout << max_balls << "\n";
    }

    return 0;
}
```