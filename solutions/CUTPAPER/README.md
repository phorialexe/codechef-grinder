# [Paper Cutting (CUTPAPER)](https://www.codechef.com/problems/CUTPAPER)

- **Difficulty Rating**: 800
- **Solved in**: 1 attempt(s)

## Problem Summary
Given a square sheet of paper with dimensions $N \times N$, we need to determine the maximum number of smaller square pieces of size $K \times K$ that can be cut from it.

## Intuition & Mathematical Observation
To maximize the number of $K \times K$ squares, we consider the dimensions of the paper:
1. Along one side of length $N$, the number of segments of length $K$ that can fit is given by the integer division: $\lfloor N / K \rfloor$.
2. Since the paper is a square ($N \times N$), we can fit the same number of segments along both the horizontal and vertical axes.
3. Therefore, the total number of $K \times K$ squares that can be arranged in a grid is:
   $$\text{Total Squares} = \left\lfloor \frac{N}{K} \right\rfloor \times \left\lfloor \frac{N}{K} \right\rfloor$$

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the calculation involves only basic arithmetic operations. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have a square paper of size N x N.
 * We want to cut out squares of size K x K.
 * Along one side of length N, we can fit floor(N / K) squares of length K.
 * Since the paper is a square, we can fit floor(N / K) squares along the width
 * and floor(N / K) squares along the height.
 * The total number of squares is (N / K) * (N / K).
 * 
 * Constraints:
 * 1 <= T <= 1000
 * 1 <= K <= N <= 1000
 */

void solve() {
    long long N, K;
    if (!(cin >> N >> K)) return;
    
    // Calculate how many K-length segments fit into N
    long long side_count = N / K;
    
    // Total squares is side_count * side_count
    long long total_squares = side_count * side_count;
    
    cout << total_squares << "\n";
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