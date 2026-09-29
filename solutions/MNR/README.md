# [Range Minimize (MNR)](https://www.codechef.com/problems/MNR)

- **Difficulty Rating**: 949
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an array $A$ of size $N$, we are allowed to delete at most 2 elements from the array. The goal is to minimize the range of the remaining elements, where the range is defined as the difference between the maximum and minimum element in the array.

## Intuition & Mathematical Observation
To minimize the range $(max - min)$, we want to bring the maximum and minimum values as close to each other as possible. Since we can remove up to 2 elements, the most effective strategy is to remove elements from the extremes (the smallest or the largest values).

After sorting the array $A$ in non-decreasing order, any remaining elements will form a contiguous subarray of the sorted array. Removing 2 elements leaves us with $N-2$ elements. There are exactly three ways to remove 2 elements to potentially minimize the range:

1. **Remove the two smallest elements:** The new range is $A[N-1] - A[2]$.
2. **Remove the two largest elements:** The new range is $A[N-3] - A[0]$.
3. **Remove one smallest and one largest element:** The new range is $A[N-2] - A[1]$.

If $N \le 3$, we can remove elements until only 1 or 0 elements remain, resulting in a range of 0. Otherwise, we calculate these three possibilities and take the minimum.

## Complexity Analysis
- **Time Complexity**: $O(N \log N)$ per test case, dominated by the sorting step.
- **Space Complexity**: $O(N)$ to store the input array.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given an array A of size N and can delete at most 2 elements.
 * We want to minimize (max(A) - min(A)).
 * 
 * After sorting the array A in non-decreasing order:
 * Let the sorted array be A[0], A[1], ..., A[N-1].
 * Deleting 2 elements can be done in three ways to minimize the range:
 * 1. Delete the two smallest elements: The range becomes A[N-1] - A[2].
 * 2. Delete the two largest elements: The range becomes A[N-3] - A[0].
 * 3. Delete the smallest and the largest element: The range becomes A[N-2] - A[1].
 */

void solve() {
    int N;
    cin >> N;
    vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // If N <= 3, we can remove elements to leave 1 or 0 elements, 
    // making the range 0.
    if (N <= 3) {
        cout << 0 << "\n";
        return;
    }

    sort(A.begin(), A.end());

    // Option 1: Remove two smallest elements
    long long range1 = A[N - 1] - A[2];
    
    // Option 2: Remove two largest elements
    long long range2 = A[N - 3] - A[0];
    
    // Option 3: Remove one smallest and one largest element
    long long range3 = A[N - 2] - A[1];

    long long ans = min({range1, range2, range3});
    cout << ans << "\n";
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