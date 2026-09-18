# [Test Score (CHEFSCORE)](https://www.codechef.com/problems/CHEFSCORE)

- **Difficulty Rating**: 610
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef has a test consisting of $N$ problems, where each problem is worth $X$ marks. For each problem, Chef can either score $X$ marks (if solved correctly) or $0$ marks (if not solved). Given the total score $Y$ that Chef achieved, determine if it is possible for Chef to have obtained exactly $Y$ marks.

## Intuition & Mathematical Observation
To achieve a total score of $Y$ where each problem is worth $X$ marks:
1. **Divisibility**: Since each problem contributes exactly $X$ marks, the total score $Y$ must be perfectly divisible by $X$. If $Y \% X \neq 0$, it is impossible to achieve that score.
2. **Constraint on Problems**: If $Y$ is divisible by $X$, the number of problems solved is $K = Y / X$. Since there are only $N$ problems available, the number of solved problems $K$ cannot exceed $N$. Therefore, we must satisfy $K \le N$.
3. **Edge Case**: If $Y = 0$, it is always possible to achieve this score by solving zero problems, regardless of $N$ or $X$.

Combining these, the condition for "YES" is:
- $(Y == 0)$ OR $(Y \% X == 0 \text{ AND } Y / X \le N)$

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we only perform basic arithmetic operations and comparisons. With $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input values.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef has N problems, each worth X marks.
 * Chef can get either 0 or X marks per problem.
 * Total score Y must be a multiple of X, and the number of problems 
 * required to get Y (which is Y/X) must not exceed the total number of problems N.
 */

int main() {
    // Optimize I/O operations for faster execution
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long n, x, y;
        cin >> n >> x >> y;

        // If Y is 0, Chef can always achieve this by solving 0 problems.
        if (y == 0) {
            cout << "YES" << "\n";
        } 
        // If Y is not 0, it must be a multiple of X, and the count of problems
        // (Y/X) must be less than or equal to N.
        else if (y % x == 0 && (y / x) <= n) {
            cout << "YES" << "\n";
        } 
        else {
            cout << "NO" << "\n";
        }
    }

    return 0;
}
```