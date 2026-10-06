# [Farmer And His Plot (RECTSQ)](https://www.codechef.com/problems/RECTSQ)

- **Difficulty Rating**: 936
- **Solved in**: 1 attempt(s)

## Problem Summary
Given a rectangular plot of land with dimensions $N \times M$, we need to divide the entire plot into the minimum number of identical square plots. The squares must cover the entire area without any gaps or overlaps, and their side lengths must be an integer.

## Intuition & Mathematical Observation
To divide a rectangle of size $N \times M$ into identical squares of side length $s$, $s$ must be a common divisor of both $N$ and $M$. 

1. **Minimizing the number of squares**: The total number of squares is given by:
   $$\text{Total Squares} = \frac{N}{s} \times \frac{M}{s}$$
   To minimize this product, we must maximize the side length $s$.
2. **Maximizing $s$**: Since $s$ must be a common divisor of $N$ and $M$, the largest possible value for $s$ is the **Greatest Common Divisor (GCD)** of $N$ and $M$.
3. **Calculation**:
   - Calculate $s = \text{gcd}(N, M)$.
   - The number of squares along the length is $N/s$.
   - The number of squares along the breadth is $M/s$.
   - The final answer is $(N/s) \times (M/s)$.

## Complexity Analysis
- **Time Complexity**: $O(\log(\min(N, M)))$ per test case, due to the Euclidean algorithm used to calculate the GCD.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the dimensions and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given a rectangular plot of size N x M.
 * We need to divide it into the minimum number of square plots of equal size.
 * Let the side length of the square be 's'.
 * For the squares to divide the rectangle perfectly, 's' must be a common divisor of N and M.
 * To minimize the number of squares, we need to maximize the area of each square.
 * Maximizing the area of the square is equivalent to maximizing the side length 's'.
 * Therefore, 's' must be the Greatest Common Divisor (GCD) of N and M.
 * 
 * The number of squares along the length N will be (N / s).
 * The number of squares along the breadth M will be (M / s).
 * The total number of squares will be (N / s) * (M / s).
 */

long long gcd(long long a, long long b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long n, m;
        cin >> n >> m;

        // Find the greatest common divisor of N and M
        long long side = gcd(n, m);

        // Calculate the number of squares
        // Total squares = (N / side) * (M / side)
        long long result = (n / side) * (m / side);

        cout << result << "\n";
    }

    return 0;
}
```