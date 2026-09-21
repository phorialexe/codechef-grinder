# [Puppy and Sum (PPSUM)](https://www.codechef.com/problems/PPSUM)

- **Difficulty Rating**: 961
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to perform a recursive summation operation $D$ times on an integer $N$. Specifically, if we define $f(N) = \sum_{i=1}^{N} i = \frac{N(N+1)}{2}$, we need to compute the result of applying this function $D$ times starting with $N$. 

## Intuition & Mathematical Observation
The problem defines a nested summation process. Since the constraints for $D$ and $N$ are very small ($D, N \le 4$), we do not need a complex closed-form formula. A simple iterative simulation is sufficient and highly efficient.

1. **Base Operation**: The sum of integers from $1$ to $N$ is given by the arithmetic series formula: $\frac{N \times (N + 1)}{2}$.
2. **Simulation**: We initialize a variable `current` with $N$. We then loop $D$ times, updating `current` to be the sum of integers from $1$ to `current` in each iteration.
3. **Data Types**: Even though the values grow, they remain well within the limits of a standard `long long` (and even `int` given the small constraints), so overflow is not a concern.

## Complexity Analysis
- **Time Complexity**: $O(D)$ per test case. Since $D \le 4$, this is effectively $O(1)$ constant time.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the current state.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Puppy and Sum
 * The function sum(N) is the sum of integers from 1 to N, which is N * (N + 1) / 2.
 * The function sum(D, N) applies this operation D times.
 * Given the constraints D, N <= 4, the values will be very small and fit in standard integer types.
 * We can simulate the process D times.
 */

long long sum_n(long long n) {
    return n * (n + 1) / 2;
}

void solve() {
    int D;
    long long N;
    cin >> D >> N;
    
    long long current = N;
    // Apply the sum_n function D times
    for (int i = 0; i < D; ++i) {
        current = sum_n(current);
    }
    
    cout << current << "\n";
}

int main() {
    // Fast I/O for performance
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