# [Rating Improvement (ADVANCE)](https://www.codechef.com/problems/ADVANCE)

- **Difficulty Rating**: 400
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef has a current rating of $X$. To improve his rating, he needs to solve a problem with a difficulty level $Y$. The problem is considered suitable if its difficulty $Y$ falls within the range $[X, X + 200]$ (inclusive). Given $X$ and $Y$, determine if the problem is suitable for Chef.

## Intuition & Mathematical Observation
The problem asks us to verify if a given value $Y$ satisfies the condition:
$$X \le Y \le X + 200$$

This is a simple range-check problem. We can evaluate this using a standard `if-else` conditional statement in C++. Since the constraints on $X$ and $Y$ are small ($1 \le X, Y \le 4000$), standard integer types are perfectly sufficient to handle the arithmetic without any risk of overflow.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a constant number of comparisons, resulting in $O(1)$ per test case.
- **Space Complexity**: $O(1)$, as we only use a few integer variables to store the input and perform the check.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef's current rating is X.
 * Recommended difficulty range is [X, X + 200].
 * Chef is solving a problem of difficulty Y.
 * We need to check if X <= Y <= X + 200.
 * 
 * Constraints:
 * 1 <= T <= 100
 * 1 <= X, Y <= 4000
 * The values fit within standard integer types (int is sufficient).
 * Time complexity per test case: O(1)
 * Total time complexity: O(T)
 */

int main() {
    // Fast I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        int x, y;
        cin >> x >> y;
        
        // Check if Y is within the inclusive range [X, X + 200]
        if (y >= x && y <= (x + 200)) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
    
    return 0;
}
```