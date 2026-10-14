# [Bus Rows (BUSROW)](https://www.codechef.com/problems/BUSROW)

- **Difficulty Rating**: 727
- **Solved in**: 1 attempt(s)

## Problem Summary
A bus has $N$ rows, each containing $M$ seats. The seats are numbered sequentially from $1$ to $N \times M$. A passenger wants to reach seat $X$. They can enter the bus either from the front (starting at row 1) or from the back (starting at row $N$). We need to determine the minimum number of rows the passenger must walk through to reach the row containing seat $X$.

## Intuition & Mathematical Observation
1. **Identify the Row**: Since there are $M$ seats per row, the row number $R$ for a given seat $X$ can be calculated using 0-indexed integer division:
   $$R = \lfloor \frac{X - 1}{M} \rfloor + 1$$
   This formula correctly maps seat $X$ to its 1-indexed row number.

2. **Calculate Distances**:
   - **From the front**: The passenger starts at row 1 and walks to row $R$. The number of rows traversed is simply $R$.
   - **From the back**: The passenger starts at row $N$ and walks to row $R$. The number of rows traversed is $N - R + 1$.

3. **Optimization**: The goal is to minimize the distance, so we compute $\min(R, N - R + 1)$.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution involves only basic arithmetic operations. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the calculated row number.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The bus has N rows, each with M seats.
 * Seat X belongs to row R = (X - 1) / M + 1.
 * 
 * If we enter from the front, we walk through rows 1, 2, ..., R.
 * The number of rows walked is R.
 * 
 * If we enter from the back, we walk through rows N, N-1, ..., R.
 * The number of rows walked is (N - R + 1).
 * 
 * We need to find the minimum of R and (N - R + 1).
 */

void solve() {
    long long N, M, X;
    if (!(cin >> N >> M >> X)) return;

    // Calculate the row number R (1-indexed)
    long long R = (X - 1) / M + 1;

    // Distance from front: R
    // Distance from back: N - R + 1
    long long dist_front = R;
    long long dist_back = N - R + 1;

    cout << min(dist_front, dist_back) << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}
```