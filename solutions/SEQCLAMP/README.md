# [Sequential Clamp (SEQCLAMP)](https://www.codechef.com/problems/SEQCLAMP)

- **Difficulty Rating**: 935
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given $N$ pairs of integers $(A_i, B_i)$, where each pair defines a "clamp" function $C_i(Y) = \max(A_i, \min(B_i, Y))$. We need to find the maximum possible value of the composite function $f(X) = C_N(C_{N-1}(\dots C_1(X) \dots))$ for any integer $X$.

## Intuition & Mathematical Observation
The function $C_i(Y)$ restricts the input $Y$ to the closed interval $[A_i, B_i]$. If $Y < A_i$, it becomes $A_i$; if $Y > B_i$, it becomes $B_i$; otherwise, it remains $Y$.

Since the function $f(X)$ is a composition of non-decreasing functions, $f(X)$ itself is non-decreasing. Given the constraints $1 \le A_i \le B_i \le 100$, the output of any clamp function will always fall within the range $[1, 100]$. Because the input space is small, we do not need to derive a complex closed-form expression. We can simply simulate the process for every possible integer $X$ in the range $[1, 100]$ and track the maximum result obtained.

## Complexity Analysis
- **Time Complexity**: $O(T \times 100 \times N)$, where $T$ is the number of test cases and $N$ is the number of clamp operations. Given $N \le 100$, this performs approximately $10^4$ operations per test case, which easily fits within the time limit.
- **Space Complexity**: $O(N)$ to store the $N$ pairs of $(A_i, B_i)$.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The function f(X) is a composition of clamp functions.
 * A clamp function C_i(Y) = max(A_i, min(B_i, Y)).
 * We want to find max(f(X)) where f(X) = C_N(C_{N-1}(...C_1(X)...)).
 * 
 * Since the constraints are small (N <= 100, A_i, B_i <= 100),
 * we can observe that the function f(X) is non-decreasing.
 * The range of possible values for f(X) is bounded by [min(A_i), max(B_i)].
 * Given the constraints 1 <= A_i <= B_i <= 100, we can simply simulate
 * the process for every possible integer X in the range [1, 100] 
 * and pick the maximum result.
 */

int solve_f(int X, int N, const vector<pair<int, int>>& pairs) {
    int Y = X;
    for (int i = 0; i < N; ++i) {
        if (Y < pairs[i].first) {
            Y = pairs[i].first;
        } else if (Y > pairs[i].second) {
            Y = pairs[i].second;
        }
    }
    return Y;
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int N;
        cin >> N;
        vector<pair<int, int>> pairs(N);
        for (int i = 0; i < N; ++i) {
            cin >> pairs[i].first >> pairs[i].second;
        }

        int max_val = -1;
        // The output is guaranteed to be within the range of possible A_i, B_i values.
        // Testing X from 1 to 100 is sufficient given the constraints.
        for (int X = 1; X <= 100; ++X) {
            max_val = max(max_val, solve_f(X, N, pairs));
        }
        cout << max_val << "\n";
    }
    return 0;
}
```