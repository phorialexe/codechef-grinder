# [Chocolate Cutting (CHOCCUT)](https://www.codechef.com/problems/CHOCCUT)

- **Difficulty Rating**: 512
- **Solved in**: 1 attempt(s)

## Problem Summary
You are given a chocolate bar of size $N \times M$. You need to determine if it is possible to cut the chocolate bar into two pieces of equal area using a single straight cut along the grid lines.

## Intuition & Mathematical Observation
The total area of the chocolate bar is $A = N \times M$. To divide the bar into two equal pieces, each piece must have an area of $\frac{N \times M}{2}$. This is only possible if the total area $A$ is an even number.

1.  **Horizontal Cut**: If we cut along a horizontal grid line, we split $N$ into $N_1$ and $N_2$ such that $N_1 + N_2 = N$. The areas become $N_1 \times M$ and $N_2 \times M$. For these to be equal, $N_1$ must equal $N_2$, which is only possible if $N$ is even.
2.  **Vertical Cut**: Similarly, if we cut along a vertical grid line, we split $M$ into $M_1$ and $M_2$. For the areas $N \times M_1$ and $N \times M_2$ to be equal, $M$ must be even.

**Conclusion**: We can cut the chocolate into two equal pieces if and only if at least one of the dimensions ($N$ or $M$) is even. If both $N$ and $M$ are odd, their product is odd, making it impossible to divide the area into two equal integer parts.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we only perform a simple parity check. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input dimensions.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have an N x M chocolate bar. We need to cut it into two equal pieces
 * along a grid line.
 * 
 * Total area = N * M.
 * For the pieces to be equal, each piece must have an area of (N * M) / 2.
 * This implies that (N * M) must be even.
 * 
 * If we cut horizontally, we split the N rows into two parts: N1 and N2,
 * such that N1 + N2 = N. The area of the two pieces would be (N1 * M) and (N2 * M).
 * For these to be equal, N1 * M = N2 * M, which implies N1 = N2.
 * This is possible if N is even (cut at N/2).
 * 
 * If we cut vertically, we split the M columns into two parts: M1 and M2,
 * such that M1 + M2 = M. The area of the two pieces would be (N * M1) and (N * M2).
 * For these to be equal, N * M1 = N * M2, which implies M1 = M2.
 * This is possible if M is even (cut at M/2).
 * 
 * Thus, we can divide the chocolate if N is even OR M is even.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long n, m;
        cin >> n >> m;

        // If either dimension is even, we can cut it in half.
        // If both are odd, the total area is odd, so we cannot split into two equal integer pieces.
        if (n % 2 == 0 || m % 2 == 0) {
            cout << "Yes" << "\n";
        } else {
            cout << "No" << "\n";
        }
    }

    return 0;
}
```