# [The Great Run (PROC18A)](https://www.codechef.com/problems/PROC18A)

- **Difficulty Rating**: 1097
- **Solved in**: 1 attempt(s)

## Problem Summary
You are given an array of $N$ integers representing the number of girls in different houses along a road. You need to choose a continuous segment of exactly $K$ houses such that the total number of girls in these $K$ houses is maximized.

## Intuition & Mathematical Observation
Since we need to find the maximum sum of a **continuous subarray** of a fixed length $K$, this is a classic application of the **Sliding Window** technique.

1. **Initial Window**: First, calculate the sum of the first $K$ elements (from index $0$ to $K-1$).
2. **Sliding**: To find the sum of the next window (starting at index $1$ and ending at $K$), we don't need to re-sum all $K$ elements. Instead, we subtract the element that is leaving the window (the one at index $0$) and add the new element entering the window (the one at index $K$).
3. **Optimization**: By repeating this process until the end of the array, we can find the sum of every possible window of size $K$ in linear time. We keep track of the maximum sum encountered during this process.

## Complexity Analysis
- **Time Complexity**: $O(T \times N)$, where $T$ is the number of test cases and $N$ is the number of houses. We traverse the array once per test case.
- **Space Complexity**: $O(N)$ to store the input array. (Note: This could be optimized to $O(K)$ or even $O(1)$ if we process elements on the fly, but $O(N)$ is well within limits for $N \le 100$).

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: The Great Run
 * Approach: Sliding Window
 * We maintain a window of size K and slide it across the array,
 * updating the sum in O(1) for each step.
 */

void solve() {
    int N, K;
    if (!(cin >> N >> K)) return;
    
    vector<int> a(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }
    
    // Calculate the sum of the first window of size K
    long long current_sum = 0;
    for (int i = 0; i < K; ++i) {
        current_sum += a[i];
    }
    
    long long max_girls = current_sum;
    
    // Slide the window across the array
    // Subtract the element that falls out of the window and add the new one
    for (int i = K; i < N; ++i) {
        current_sum = current_sum - a[i - K] + a[i];
        if (current_sum > max_girls) {
            max_girls = current_sum;
        }
    }
    
    cout << max_girls << "\n";
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