# [Uncle Johny (JOHNY)](https://www.codechef.com/problems/JOHNY)

- **Difficulty Rating**: 1093
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given a playlist of $N$ songs, each with a specific length. We are also given the current 1-indexed position $K$ of a specific song called "Uncle Johny". The task is to determine the new 1-indexed position of "Uncle Johny" after the entire playlist is sorted in non-decreasing order of song lengths.

## Intuition & Mathematical Observation
1. **Identify the Target**: Since we know the initial position $K$, we can extract the length of "Uncle Johny" by accessing the array at index $K-1$ (adjusting for 0-based indexing).
2. **Sorting**: The problem asks for the position after sorting. Since the problem guarantees that all song lengths are unique, the relative order of the songs is determined solely by their lengths.
3. **Search**: Once the array is sorted, we simply need to find the index where the previously stored "Uncle Johny" length now resides. Adding 1 to this 0-based index gives us the final 1-indexed position.

## Complexity Analysis
- **Time Complexity**: $O(T \times N \log N)$, where $T$ is the number of test cases and $N$ is the number of songs. Sorting takes $O(N \log N)$ per test case, and the linear search takes $O(N)$. Given $N \le 100$ and $T \le 1000$, the total operations are well within the time limit.
- **Space Complexity**: $O(N)$ to store the playlist array.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given an array of N song lengths. We know the initial position K of "Uncle Johny".
 * We need to find the new position of "Uncle Johny" after the array is sorted in non-decreasing order.
 * 
 * Approach:
 * 1. Store the value of the song at index K-1 (since input is 1-indexed).
 * 2. Sort the array of song lengths.
 * 3. Find the position of the stored value in the sorted array.
 * 4. Since all song lengths are unique, the position is unique.
 */

void solve() {
    int n;
    if (!(cin >> n)) return;
    
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    int k;
    cin >> k;
    
    // The length of "Uncle Johny"
    long long uncle_johnny_len = a[k - 1];
    
    // Sort the playlist
    sort(a.begin(), a.end());
    
    // Find the new position (1-indexed)
    for (int i = 0; i < n; ++i) {
        if (a[i] == uncle_johnny_len) {
            cout << (i + 1) << "\n";
            return;
        }
    }
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