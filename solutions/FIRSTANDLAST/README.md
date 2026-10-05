# [First and Last (FIRSTANDLAST)](https://www.codechef.com/problems/FIRSTANDLAST)

- **Difficulty Rating**: 932
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an array $A$ of length $N$, you are allowed to perform any number of right rotations on the array. After performing the rotations, you want to maximize the sum of the first and last elements of the resulting array. We need to find this maximum possible sum.

## Intuition & Mathematical Observation
Let the original array be $A = [A_0, A_1, \dots, A_{N-1}]$. 

When we perform a right rotation, the last element moves to the front. If we perform $k$ rotations, the new array will have $A_{N-k}$ as the first element and $A_{N-k-1}$ as the last element. 

By observing the cyclic nature of the array:
1. **0 rotations**: The first and last elements are $A_0$ and $A_{N-1}$.
2. **1 rotation**: The first element becomes $A_{N-1}$ and the last becomes $A_{N-2}$.
3. **General case**: After any number of rotations, the "first" and "last" elements of the array will always be a pair of elements that were originally adjacent in the circular array. Specifically, the possible pairs are:
   - $(A_0, A_{N-1})$ (the original ends)
   - $(A_0, A_1), (A_1, A_2), \dots, (A_{N-2}, A_{N-1})$ (all adjacent pairs)

Therefore, the problem reduces to finding the maximum value of $(A_0 + A_{N-1})$ and $(A_i + A_{i+1})$ for all $0 \le i < N-1$.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, as we iterate through the array exactly once to calculate the sums of adjacent pairs.
- **Space Complexity**: $O(N)$ to store the input array.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * After any number of right rotations, the first and last elements of the array 
 * will always be a pair of elements that were originally adjacent (including the 
 * wrap-around pair A[N-1] and A[0]).
 * 
 * We simply need to calculate the sum of all adjacent pairs (A[i] + A[i+1]) 
 * and the wrap-around pair (A[N-1] + A[0]), then find the maximum.
 */

void solve() {
    int N;
    cin >> N;
    vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // Initialize max_sum with the wrap-around case (A[N-1] + A[0])
    long long max_sum = A[0] + A[N - 1];

    // Check all adjacent pairs (A[i], A[i+1])
    for (int i = 0; i < N - 1; ++i) {
        long long current_sum = A[i] + A[i + 1];
        if (current_sum > max_sum) {
            max_sum = current_sum;
        }
    }

    cout << max_sum << "\n";
}

int main() {
    // Fast I/O
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