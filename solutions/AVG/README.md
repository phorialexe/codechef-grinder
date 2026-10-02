# [Average Number (AVG)](https://www.codechef.com/problems/AVG)

- **Difficulty Rating**: 1202
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given a sequence of $N$ integers with an average value of $V$. We are told that $K$ additional integers were originally part of the sequence, but were removed. All $K$ removed integers have the same value, $X$. Given $N, K, V$, and the $N$ remaining integers, we need to find the value of $X$. If no such positive integer $X$ exists, we output -1.

## Intuition & Mathematical Observation
Let $S_A$ be the sum of the $N$ remaining integers. The original sequence had $N + K$ elements, and their average was $V$. Therefore, the total sum of the original sequence was $V \times (N + K)$.

We can express the total sum as the sum of the remaining elements plus the sum of the $K$ removed elements:
$$S_A + (K \times X) = V \times (N + K)$$

Rearranging to solve for $X$:
$$K \times X = V \times (N + K) - S_A$$
$$X = \frac{V \times (N + K) - S_A}{K}$$

For $X$ to be a valid solution, it must satisfy two conditions:
1. **Divisibility**: The numerator $(V \times (N + K) - S_A)$ must be perfectly divisible by $K$ (i.e., the remainder must be 0).
2. **Positivity**: Since $X$ represents a value in the sequence, it must be a positive integer ($X > 0$).

If these conditions are met, $X$ is the answer; otherwise, no such integer exists, and we output -1.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, as we iterate through the $N$ given integers once to calculate their sum.
- **Space Complexity**: $O(1)$, as we only store a few variables regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Let the original sequence be S of length N + K.
 * Let the sum of the N remaining elements be S_A = sum(A_1, ..., A_N).
 * Let the value of the K deleted elements be X.
 * The average of the original sequence is V.
 * 
 * The sum of the original sequence is: S_A + (K * X)
 * The average is: (S_A + K * X) / (N + K) = V
 * 
 * Rearranging the equation:
 * S_A + K * X = V * (N + K)
 * K * X = V * (N + K) - S_A
 * X = (V * (N + K) - S_A) / K
 * 
 * Conditions for X to be valid:
 * 1. (V * (N + K) - S_A) must be divisible by K.
 * 2. X must be a positive integer (X > 0).
 */

void solve() {
    long long N, K, V;
    cin >> N >> K >> V;
    
    long long sum_A = 0;
    for (int i = 0; i < N; ++i) {
        long long a;
        cin >> a;
        sum_A += a;
    }
    
    long long total_sum_required = V * (N + K);
    long long missing_sum = total_sum_required - sum_A;
    
    // Check if missing_sum is positive and divisible by K
    if (missing_sum > 0 && (missing_sum % K == 0)) {
        cout << (missing_sum / K) << "\n";
    } else {
        cout << -1 << "\n";
    }
}

int main() {
    // Optimize I/O operations
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