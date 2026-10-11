# [Divisible Duel (P2209)](https://www.codechef.com/problems/P2209)

- **Difficulty Rating**: 628
- **Solved in**: 1 attempt(s)

## Problem Summary
Given two integers $X$ and $Y$, we need to identify all multiples of $X$ in the range $[X, Y]$. We categorize these multiples into two groups: those that are even and those that are odd. Let $S_{even}$ be the sum of all even multiples and $S_{odd}$ be the sum of all odd multiples. We must determine if $S_{even} \ge S_{odd}$ and output "YES" if true, otherwise "NO".

## Intuition & Mathematical Observation
Since the constraints on $X$ and $Y$ are very small ($X, Y \le 100$), a brute-force approach is highly efficient. 
1. We iterate through the range starting from $X$ up to $Y$, incrementing by $X$ in each step to visit only the multiples of $X$.
2. For each multiple $i$, we check its parity using the modulo operator (`i % 2 == 0`).
3. We maintain two running totals, `s_even` and `s_odd`, and compare them at the end.

Because the maximum value of $Y$ is 100, the number of iterations per test case is at most 100, making this approach well within the time limits for any standard competitive programming environment.

## Complexity Analysis
- **Time Complexity**: $O(\frac{Y}{X})$ per test case. Given $Y \le 100$, this is effectively $O(1)$ per test case.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the sums and the loop index.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given X and Y. We need to find all multiples of X in the range [X, Y].
 * Let these multiples be X*1, X*2, X*3, ..., X*k, where X*k <= Y.
 * 
 * S_even = sum of (X * i) for all i in {1, ..., k} such that (X * i) is even.
 * S_odd  = sum of (X * i) for all i in {1, ..., k} such that (X * i) is odd.
 * 
 * Since X, Y <= 100, we can simply iterate through all multiples of X up to Y
 * and calculate the sums directly.
 */

void solve() {
    int X, Y;
    cin >> X >> Y;

    long long s_even = 0;
    long long s_odd = 0;

    // Iterate through all multiples of X: X, 2X, 3X, ... up to Y
    for (int i = X; i <= Y; i += X) {
        if (i % 2 == 0) {
            s_even += i;
        } else {
            s_odd += i;
        }
    }

    if (s_even >= s_odd) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
}

int main() {
    // Fast I/O setup
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