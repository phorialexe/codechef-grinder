# [Maximise Adjacent Sum (MAXADJSUM)](https://www.codechef.com/problems/MAXADJSUM)

- **Difficulty Rating**: 1118
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an array $A$ of $N$ integers, we need to rearrange the elements to maximize the sum of adjacent elements:
$$f(A) = \sum_{i=1}^{N-1} (A_i + A_{i+1})$$

## Intuition & Mathematical Observation
By expanding the summation, we can observe the contribution of each element to the total sum:
$$f(A) = (A_1 + A_2) + (A_2 + A_3) + \dots + (A_{N-1} + A_N)$$
$$f(A) = A_1 + 2A_2 + 2A_3 + \dots + 2A_{N-1} + A_N$$

From this expansion, it is clear that:
1. The elements at the ends of the array ($A_1$ and $A_N$) are counted exactly **once**.
2. All other elements ($A_2, \dots, A_{N-1}$) are counted **twice**.

To maximize the total sum, we want the largest elements to be multiplied by 2. Conversely, to minimize the "loss" from the total possible sum (if every element were multiplied by 2), we should place the two smallest elements at the ends of the array.

Let $S$ be the sum of all elements in the array. If every element were counted twice, the sum would be $2S$. Since the two elements at the ends are only counted once instead of twice, we subtract them from $2S$:
$$\text{Maximized Sum} = 2 \times (\sum_{i=1}^{N} A_i) - (A_{min1} + A_{min2})$$
where $A_{min1}$ and $A_{min2}$ are the two smallest elements in the array.

## Complexity Analysis
- **Time Complexity**: $O(N \log N)$ due to the sorting step required to identify the two smallest elements. The summation takes $O(N)$.
- **Space Complexity**: $O(N)$ to store the input array.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * f(A) = A_1 + 2*A_2 + 2*A_3 + ... + 2*A_{N-1} + A_N
 * 
 * To maximize this sum, we want the largest elements to have a coefficient of 2.
 * The two smallest elements should be placed at the ends (A_1 and A_N) so that 
 * they are only counted once.
 * 
 * Formula: 2 * (sum of all elements) - (smallest + second_smallest)
 */

void solve() {
    int N;
    cin >> N;
    vector<long long> A(N);
    long long total_sum = 0;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        total_sum += A[i];
    }
    
    // Sort to easily pick the two smallest elements
    sort(A.begin(), A.end());
    
    // The two smallest elements are A[0] and A[1]
    long long ans = 2 * total_sum - (A[0] + A[1]);
    cout << ans << "\n";
}

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
```