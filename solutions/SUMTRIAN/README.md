# [Sums in a Triangle (SUMTRIAN)](https://www.codechef.com/problems/SUMTRIAN)

- **Difficulty Rating**: 869
- **Solved in**: 1 attempt(s)

## Problem Summary
Given a triangle of numbers, we need to find the maximum path sum starting from the top vertex and moving to adjacent numbers on the row below. Specifically, from an element at position `(i, j)`, you can move to either `(i+1, j)` or `(i+1, j+1)`. The goal is to maximize the sum of the numbers encountered along the path.

## Intuition & Mathematical Observation
This is a classic Dynamic Programming problem. While one could attempt a greedy approach (always picking the larger child), that would fail because a smaller number might lead to a much larger sum later on.

Instead, we use a **Bottom-Up DP approach**:
1. Instead of calculating from the top down, we start from the second-to-last row and work our way to the top.
2. For any element at `triangle[i][j]`, the maximum path sum from this point to the bottom is the value of the element itself plus the maximum of the two possible paths below it: `triangle[i+1][j]` and `triangle[i+1][j+1]`.
3. By updating the triangle in-place, the value at `triangle[0][0]` will eventually store the maximum path sum for the entire triangle.

**Recurrence Relation:**
`triangle[i][j] = triangle[i][j] + max(triangle[i+1][j], triangle[i+1][j+1])`

## Complexity Analysis
- **Time Complexity**: $O(N^2)$ per test case, where $N$ is the number of rows. Since we visit each element in the triangle exactly once during the bottom-up update, the complexity is proportional to the total number of elements, which is $N(N+1)/2$.
- **Space Complexity**: $O(N^2)$ to store the triangle. This could be optimized to $O(N)$ by only storing the current and previous rows, but given $N < 100$, $O(N^2)$ is well within memory limits.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * This is a classic Dynamic Programming problem. We are given a triangle of numbers
 * and need to find the maximum path sum from top to bottom.
 * 
 * Let dp[i][j] be the maximum path sum from (i, j) to the base.
 * dp[i][j] = a[i][j] + max(dp[i+1][j], dp[i+1][j+1])
 * 
 * Given N < 100, an O(N^2) approach per test case is perfectly efficient.
 * Total complexity: O(T * N^2), which is ~10^7 operations, well within the 1s limit.
 */

void solve() {
    int N;
    if (!(cin >> N)) return;

    // Using a 2D vector to store the triangle
    vector<vector<int>> triangle(N, vector<int>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j <= i; ++j) {
            cin >> triangle[i][j];
        }
    }

    // Bottom-up DP approach
    // Start from the second to last row and move upwards
    for (int i = N - 2; i >= 0; --i) {
        for (int j = 0; j <= i; ++j) {
            // The value at current position becomes itself plus the max of the two
            // possible paths below it.
            triangle[i][j] += max(triangle[i + 1][j], triangle[i + 1][j + 1]);
        }
    }

    // The answer is now at the top of the triangle
    cout << triangle[0][0] << "\n";
}

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        solve();
    }
    return 0;
}
```