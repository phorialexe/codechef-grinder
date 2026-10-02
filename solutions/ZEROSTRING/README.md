# [Zero String (ZEROSTRING)](https://www.codechef.com/problems/ZEROSTRING)

- **Difficulty Rating**: 1042
- **Solved in**: 1 attempt(s)

## Problem Summary
Given a binary string of length $N$, we want to make the entire string consist of only '0's. We are allowed two types of operations:
1. **Delete a character**: Remove any character from the string.
2. **Flip the string**: Change all '0's to '1's and all '1's to '0's.

We need to find the minimum number of operations required to make the string contain only '0's.

## Intuition & Mathematical Observation
To reach a state where the string contains only '0's, we can analyze the two primary strategies:

1. **Direct Deletion**: If we choose not to flip the string, we must delete every '1' currently present in the string. If there are `ones` count of '1's, the cost is simply `ones`.
2. **Flip and Delete**: If we choose to flip the string, the cost of the flip operation is $1$. After flipping, all original '0's become '1's. To make the string all '0's, we must then delete all these new '1's. The number of new '1's is equal to the original count of '0's (`zeros`). Thus, the total cost is `zeros + 1`.

**Note on redundant operations**: Flipping more than once is inefficient because two flips return the string to its original state, wasting two operations. Therefore, we only consider flipping zero times or one time.

The final answer is the minimum of these two strategies:
$$\text{Result} = \min(\text{ones}, \text{zeros} + 1)$$

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the length of the string, as we iterate through the string once to count the '0's and '1's.
- **Space Complexity**: $O(N)$ to store the input string.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Let 'ones' be the number of 1s in the string and 'zeros' be the number of 0s.
 * We want to reach a state where the string contains only 0s.
 * 
 * Strategy 1: Delete all 1s.
 * Cost = 'ones'.
 * 
 * Strategy 2: Flip the string, then delete the remaining 1s.
 * If we flip, the 0s become 1s and the 1s become 0s.
 * The number of 1s becomes 'zeros'.
 * Cost = 1 (for flip) + 'zeros' (to delete the new 1s).
 * 
 * The minimum operations will be: min(ones, zeros + 1)
 */

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int ones = 0;
    int zeros = 0;
    for (char c : s) {
        if (c == '1') {
            ones++;
        } else {
            zeros++;
        }
    }

    // Option 1: Just delete all 1s
    int ans = ones;

    // Option 2: Flip once, then delete all resulting 1s (which were originally 0s)
    // Cost is 1 (flip) + zeros (number of 1s after flip)
    ans = min(ans, zeros + 1);

    cout << ans << "\n";
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