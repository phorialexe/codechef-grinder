# [Two Ranges (TWORANGES)](https://www.codechef.com/problems/TWORANGES)

- **Difficulty Rating**: 918
- **Solved in**: 1 attempt(s)

## Problem Summary
Given two closed intervals $[A, B]$ and $[C, D]$, we need to determine the total number of unique integers that are contained in at least one of these two ranges.

## Intuition & Mathematical Observation
The constraints for this problem are very small ($1 \le A, B, C, D \le 8$). Because the range of possible values is limited to the set $\{1, 2, 3, 4, 5, 6, 7, 8\}$, we do not need complex interval intersection formulas.

Instead, we can use a **boolean array** (or a frequency map) of size 9 to act as a "marker." By iterating through each range and marking the corresponding indices in our array as `true`, we effectively handle the union of the two sets. Finally, counting the number of `true` values in the array gives us the size of the union of the two ranges.

## Complexity Analysis
- **Time Complexity**: $O(T \times N)$, where $T$ is the number of test cases and $N$ is the maximum range size (8). Given the constraints, this is effectively $O(T)$, which is extremely efficient.
- **Space Complexity**: $O(1)$, as we only use a fixed-size boolean array of size 9 regardless of the input values.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given two ranges [A, B] and [C, D]. We need to find the number of 
 * integers that belong to at least one of these ranges.
 * 
 * Since the constraints are very small (1 <= A, B, C, D <= 8), we can use a 
 * boolean array to mark the integers present in the ranges and 
 * count the number of unique integers marked.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        // Using a boolean array to track integers from 1 to 8
        // Since constraints are 1 <= A, B, C, D <= 8
        bool present[9] = {false};

        // Mark integers in the first range [A, B]
        for (int i = a; i <= b; ++i) {
            present[i] = true;
        }

        // Mark integers in the second range [C, D]
        for (int i = c; i <= d; ++i) {
            present[i] = true;
        }

        // Count how many integers were marked
        int count = 0;
        for (int i = 1; i <= 8; ++i) {
            if (present[i]) {
                count++;
            }
        }

        cout << count << "\n";
    }

    return 0;
}
```