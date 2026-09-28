# [Leg Space (LEGSP)](https://www.codechef.com/problems/LEGSP)

- **Difficulty Rating**: 326
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef is traveling on a bus with $N$ students and $M$ seats. Chef is happy if there is at least one empty seat available on the bus. Given $N$ (number of students) and $M$ (number of seats), determine if Chef is happy.

## Intuition & Mathematical Observation
The problem states that Chef is happy if the bus is not full. 
- The bus is full if the number of students equals the number of seats ($N = M$).
- The bus has empty space if the number of students is strictly less than the number of seats ($N < M$).

Since the problem constraints guarantee $N \le M$, we simply need to check if $N$ is strictly less than $M$. If $N < M$, there is at least one empty seat, so we output `YES`. Otherwise, if $N = M$, the bus is full, and we output `NO`.

## Complexity Analysis
- **Time Complexity**: $O(1)$ because the solution involves a single comparison and constant-time arithmetic operations.
- **Space Complexity**: $O(1)$ as we only use two integer variables to store the input.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef is happy if the bus is NOT full.
 * The bus is full if the number of students (N) equals the number of seats (M).
 * The bus is not full if the number of students (N) is strictly less than the number of seats (M).
 * Given N <= M, the condition for Chef to be happy is N < M.
 * If N == M, the bus is full, and Chef is not happy.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    if (cin >> N >> M) {
        // Check if there is at least one empty seat
        if (N < M) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }

    return 0;
}
```