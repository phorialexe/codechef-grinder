# [Binary String Cost (BSCOST)](https://www.codechef.com/problems/BSCOST)

- **Difficulty Rating**: 1069
- **Solved in**: 1 attempt(s)

## Problem Summary
Given a binary string $S$ of length $N$, we are allowed to rearrange its characters. We need to find the minimum possible cost, where the cost is defined as:
- $X \times (\text{number of "01" substrings})$
- $Y \times (\text{number of "10" substrings})$

We want to minimize the total cost after rearranging the string optimally.

## Intuition & Mathematical Observation
To minimize the cost, we should aim to minimize the number of transitions between '0's and '1's. 

1. **Case 1: Only one type of character exists.**
   If the string consists only of '0's or only of '1's, there are no "01" or "10" transitions possible. The cost is **0**.

2. **Case 2: Both '0's and '1's exist.**
   If both characters are present, we can group all '0's together and all '1's together. There are two primary ways to arrange them:
   - **Arrangement A (00...011...1):** This creates exactly one "01" transition and zero "10" transitions. The cost is $X$.
   - **Arrangement B (11...100...0):** This creates exactly one "10" transition and zero "01" transitions. The cost is $Y$.

Since we want to minimize the cost, we simply choose the smaller of the two values: $\min(X, Y)$. Any other arrangement (e.g., alternating 0s and 1s) would only increase the number of transitions, thereby increasing the cost.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the length of the string. We iterate through the string once to check for the presence of '0's and '1's.
- **Space Complexity**: $O(N)$ to store the input string $S$.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have a binary string S of length N. We want to rearrange it to minimize the cost.
 * The cost is defined by:
 * - (number of "01" occurrences) * X
 * - (number of "10" occurrences) * Y
 * 
 * If the string contains no '0's or no '1's, the cost is 0.
 * If the string contains both '0's and '1's:
 * - Arranging as 00...011...1 results in one "01" and zero "10"s. Cost = X.
 * - Arranging as 11...100...0 results in one "10" and zero "01"s. Cost = Y.
 * 
 * Therefore, the minimum cost is min(X, Y) if both '0' and '1' are present,
 * and 0 if only one type of character is present.
 */

void solve() {
    int N, X, Y;
    cin >> N >> X >> Y;
    string S;
    cin >> S;

    bool hasZero = false;
    bool hasOne = false;

    for (char c : S) {
        if (c == '0') hasZero = true;
        if (c == '1') hasOne = true;
    }

    // If the string is monochromatic, no transitions are possible.
    if (!hasZero || !hasOne) {
        cout << 0 << "\n";
    } else {
        // Otherwise, we can force exactly one transition of either type.
        cout << min(X, Y) << "\n";
    }
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