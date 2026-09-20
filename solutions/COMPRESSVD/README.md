# [Compress the Video (COMPRESSVD)](https://www.codechef.com/problems/COMPRESSVD)

- **Difficulty Rating**: 940
- **Solved in**: 1 attempt(s)

## Problem Summary
You are given a sequence of video frames represented as an array of integers. You can remove a frame if it is identical to the frame immediately preceding it. The goal is to find the minimum number of frames remaining after performing this operation as many times as possible.

## Intuition & Mathematical Observation
The problem states that we can remove a frame if it is equal to its neighbor. If we have a sequence of identical consecutive frames (e.g., `[5, 5, 5, 2, 2]`), we can repeatedly remove the duplicates until only one instance of that value remains in that specific block.

Essentially, this reduces the problem to counting the number of "runs" or "blocks" of consecutive identical elements. 
- The first frame is always kept.
- For every subsequent frame, if it is different from the frame immediately before it, it represents the start of a new unique value and must be kept.
- If it is the same as the previous frame, it can be removed.

Therefore, the final count is simply the number of indices $i$ (where $i > 0$) such that $A[i] \neq A[i-1]$, plus the initial frame.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the number of frames. We iterate through the array exactly once.
- **Space Complexity**: $O(N)$ to store the input array (or $O(1)$ if processing input on the fly).

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The operation allows removing a frame if it is equal to its neighbor.
 * This is equivalent to saying that if we have a sequence of identical 
 * consecutive frames (e.g., 2, 2, 2), we can remove all but one of them.
 * 
 * Effectively, we are looking for the number of "blocks" of consecutive 
 * identical elements.
 */

void solve() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    if (n == 0) {
        cout << 0 << "\n";
        return;
    }
    
    // The first frame is always kept.
    int count = 1;
    for (int i = 1; i < n; ++i) {
        // If the current frame is different from the previous one,
        // it cannot be removed by the rule.
        if (a[i] != a[i - 1]) {
            count++;
        }
    }
    
    cout << count << "\n";
}

int main() {
    // Fast I/O
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