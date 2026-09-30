# [Magical World (P2149)](https://www.codechef.com/problems/P2149)

- **Difficulty Rating**: 1005
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given a red rectangle with dimensions $A \times B$ and a blue square with side length $X$. We want the area of the red rectangle ($A \times B$) to be less than or equal to the area of the blue square ($X^2$). We can reduce either dimension of the rectangle by 1 unit at the cost of 1 operation. We need to find the minimum number of operations required to satisfy the condition $A \times B \le X^2$.

## Intuition & Mathematical Observation
The problem asks for the minimum cost to satisfy the area constraint. Since we want to minimize operations, we evaluate the possibilities in increasing order of cost:

1.  **Cost 0**: If the initial area $A \times B$ is already less than or equal to $X^2$, no operations are needed.
2.  **Cost 1**: If we cannot satisfy the condition with 0 operations, we check if changing one dimension to $1$ works. Since we want to minimize the area, changing a dimension to $1$ is the most effective way to reduce the area. We check if $1 \times B \le X^2$ or $A \times 1 \le X^2$. If either is true, the cost is 1.
3.  **Cost 2**: If neither of the above works, we must change both dimensions to $1$. Since $X \ge 1$, $1 \times 1 \le X^2$ will always be true. Thus, the maximum cost is 2.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we are performing a constant number of arithmetic operations and comparisons. Given $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and intermediate calculations.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have a red rectangle (A x B) and a blue square (X x X).
 * We want Area(Rectangle) <= Area(Square), i.e., A * B <= X * X.
 * Each change of a dimension (A or B) costs 1.
 * Since we want to minimize cost, we check:
 * 0 changes: If A * B <= X * X, cost is 0.
 * 1 change: If we can change A to 1 or B to 1 such that 1 * B <= X * X or A * 1 <= X * X.
 * 2 changes: If neither of the above works, we change both dimensions to 1.
 *            1 * 1 <= X * X is always true since X >= 1. Cost is 2.
 */

void solve() {
    int A, B, X;
    cin >> A >> B >> X;

    long long area_rect = (long long)A * B;
    long long area_sq = (long long)X * X;

    // Case 0: Already satisfied
    if (area_rect <= area_sq) {
        cout << 0 << "\n";
    } 
    // Case 1: Can we satisfy by changing one dimension to 1?
    else if ((1LL * B <= area_sq) || (A * 1LL <= area_sq)) {
        cout << 1 << "\n";
    } 
    // Case 2: Change both dimensions to 1
    else {
        cout << 2 << "\n";
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
```