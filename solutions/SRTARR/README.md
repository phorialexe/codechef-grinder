# [Sort the String (SRTARR)](https://www.codechef.com/problems/SRTARR)

- **Difficulty Rating**: 1112
- **Solved in**: 1 attempt(s)

## Problem Summary
The objective is to sort a binary string (consisting of '0's and '1's) such that all '0's appear before all '1's. The allowed operation is to choose any substring and reverse it. We need to find the minimum number of operations required to achieve a sorted state.

## Intuition & Mathematical Observation
A binary string is sorted if it follows the pattern $00\dots0011\dots11$. Any violation of this order is marked by the presence of a '1' followed by a '0' (the pattern `"10"`).

1.  **Identifying Inversions**: Every occurrence of the substring `"10"` represents a point where the string is not sorted.
2.  **The Operation**: When we perform a reversal on a block containing a `"10"` transition, we can effectively move a block of '1's to the right of a block of '0's. 
3.  **Counting Transitions**: By observing the string, we notice that each contiguous block of '1's that precedes at least one '0' must be moved. Specifically, every time the pattern `"10"` appears, it signifies a boundary that requires an operation to resolve. 
4.  **Conclusion**: The minimum number of operations required is exactly equal to the number of times the substring `"10"` appears in the string. For example:
    *   `"000"`: 0 occurrences of `"10"` $\rightarrow$ 0 operations.
    *   `"1001"`: 1 occurrence of `"10"` (at index 0) $\rightarrow$ 1 operation.
    *   `"1010"`: 2 occurrences of `"10"` (at index 0 and 2) $\rightarrow$ 2 operations.

## Complexity Analysis
- **Time Complexity**: $O(N)$, where $N$ is the length of the string. We perform a single linear scan through the string to count the `"10"` patterns.
- **Space Complexity**: $O(N)$ to store the input string (or $O(1)$ if reading character by character).

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We want to sort a binary string (all 0s followed by all 1s) using the minimum number of reversals.
 * Every time we have a substring "10", it represents an inversion.
 * The number of operations required is exactly the number of times the pattern "10" 
 * appears in the string.
 */

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int operations = 0;
    // Iterate through the string and count occurrences of "10"
    for (int i = 0; i < n - 1; ++i) {
        if (s[i] == '1' && s[i + 1] == '0') {
            operations++;
        }
    }
    cout << operations << "\n";
}

int main() {
    // Fast I/O for performance
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