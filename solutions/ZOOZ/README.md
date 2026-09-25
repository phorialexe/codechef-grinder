# [Zero Ones Equal One Zeros (ZOOZ)](https://www.codechef.com/problems/ZOOZ)

- **Difficulty Rating**: 1009
- **Solved in**: 2 attempt(s)

## Problem Summary
Given an integer $N$, we need to construct a binary string of length $N$ such that the number of occurrences of the subsequence "01" is exactly equal to the number of occurrences of the subsequence "10".

## Intuition & Mathematical Observation
To satisfy the condition where the count of "01" equals the count of "10", we can look for a symmetric structure. 

If we construct a string that starts with a `1` and ends with a `1`, and fill the middle with `0`s, we get a pattern like `100...001`.
- In this configuration, every `0` is preceded by a `1` (forming a "10" subsequence) and followed by a `1` (forming a "01" subsequence).
- Since every `0` in the middle is surrounded by `1`s, each `0` contributes exactly one "10" and one "01".
- If there are $k$ zeros, we will have $k$ occurrences of "10" and $k$ occurrences of "01".
- This construction works for any $N \ge 2$. For $N=1$, the problem constraints usually imply $N \ge 2$ or a trivial case, but for the given constraints, `1...1` with `0`s in between is the most robust approach.

**Example ($N=4$):**
- String: `1001`
- "10" subsequences: (index 0,1), (index 0,2) $\rightarrow$ 2
- "01" subsequences: (index 1,3), (index 2,3) $\rightarrow$ 2
- Condition satisfied.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, as we iterate to build a string of length $N$.
- **Space Complexity**: $O(N)$ to store the resulting string before printing.

## Solution Code

```cpp
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * Problem: ZOOZ
 * Strategy: Construct a string starting and ending with '1', with '0's in between.
 * This ensures every '0' contributes exactly one '10' and one '01' subsequence.
 */

void solve() {
    int N;
    cin >> N;
    
    // Start with '1'
    string result = "1";
    
    // Fill the middle with N-2 zeros
    for (int i = 0; i < N - 2; ++i) {
        result += '0';
    }
    
    // End with '1'
    result += '1';
    
    cout << result << endl;
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