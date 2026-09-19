# [Racing Horses (HORSES)](https://www.codechef.com/problems/HORSES)

- **Difficulty Rating**: 1231
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an array of $N$ integers representing the skill levels of $N$ horses, the goal is to find the minimum absolute difference between the skill levels of any two distinct horses in the set.

## Intuition & Mathematical Observation
To find the minimum difference between any two elements in an array, a brute-force approach would involve comparing every possible pair, resulting in $O(N^2)$ complexity. 

However, we can optimize this by **sorting** the array first. Once the array is sorted in non-decreasing order, the two horses with the smallest difference in skill levels must be adjacent to each other. 
- If we have a sorted array $S$ where $S_0 \le S_1 \le \dots \le S_{N-1}$, the minimum difference is guaranteed to be $\min(S_{i+1} - S_i)$ for all $0 \le i < N-1$.
- This reduces the problem to a single pass through the sorted array, significantly improving performance.

## Complexity Analysis
- **Time Complexity**: $O(N \log N)$ per test case, dominated by the sorting step. The subsequent linear scan takes $O(N)$. Given $N \le 5000$ and $T \le 10$, this approach easily passes within the 1.5s time limit.
- **Space Complexity**: $O(N)$ to store the skill levels of the horses.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given N horses with skill levels S[i]. We need to find the minimum 
 * absolute difference between any two horses.
 * 
 * Approach:
 * 1. If we sort the array of skills, the minimum difference must exist between
 *    two adjacent elements in the sorted array.
 * 2. Sorting takes O(N log N).
 * 3. Iterating through the sorted array to find the minimum difference takes O(N).
 * 4. Total time complexity per test case: O(N log N).
 * 5. Given N <= 5000 and T <= 10, O(T * N log N) is well within the 1.5s limit.
 */

void solve() {
    int N;
    if (!(cin >> N)) return;
    
    vector<long long> S(N);
    for (int i = 0; i < N; ++i) {
        cin >> S[i];
    }
    
    // Sort the skills to bring the closest values next to each other
    sort(S.begin(), S.end());
    
    // Initialize min_diff with a large value
    long long min_diff = LLONG_MAX;
    
    // Compare adjacent elements in the sorted array
    for (int i = 0; i < N - 1; ++i) {
        long long diff = S[i + 1] - S[i];
        if (diff < min_diff) {
            min_diff = diff;
        }
    }
    
    cout << min_diff << "\n";
}

int main() {
    // Fast I/O for performance
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