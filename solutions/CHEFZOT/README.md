# [Chef and Subarray (CHEFZOT)](https://www.codechef.com/problems/CHEFZOT)

- **Difficulty Rating**: 1191
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an array of $N$ integers, find the length of the longest contiguous subarray such that the product of all elements in the subarray is non-zero.

## Intuition & Mathematical Observation
A mathematical property of multiplication is that the product of a set of numbers is zero if and only if at least one of the numbers in the set is zero. 

Therefore, a subarray has a non-zero product if and only if it contains **no zeros**. The problem effectively reduces to finding the length of the longest contiguous segment of non-zero integers within the given array.

**Approach:**
1. Traverse the array while maintaining a `current_len` counter.
2. If the current element is non-zero, increment `current_len`.
3. If the current element is zero, the current non-zero segment has ended. Compare `current_len` with the `max_len` found so far, update `max_len` if necessary, and reset `current_len` to 0.
4. After the loop finishes, perform one final comparison to handle cases where the longest segment ends at the very last element of the array.

## Complexity Analysis
- **Time Complexity**: $O(N)$, where $N$ is the number of elements in the array. We perform a single pass through the input.
- **Space Complexity**: $O(1)$, as we only store a few integer variables regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * A subarray has a non-zero product if and only if it contains no zeros.
 * The problem reduces to finding the length of the longest contiguous segment 
 * of the array that does not contain the number 0.
 */

int main() {
    // Fast I/O for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    int max_len = 0;
    int current_len = 0;

    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;

        if (a != 0) {
            // Element is non-zero, extend the current segment
            current_len++;
        } else {
            // Element is zero, update max and reset current segment
            if (current_len > max_len) {
                max_len = current_len;
            }
            current_len = 0;
        }
    }

    // Final check in case the longest segment ends at the last element
    if (current_len > max_len) {
        max_len = current_len;
    }

    cout << max_len << "\n";

    return 0;
}
```