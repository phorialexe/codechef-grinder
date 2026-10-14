# [Signal (P2BAR)](https://www.codechef.com/problems/P2BAR)

- **Difficulty Rating**: 657
- **Solved in**: 2 attempt(s)

## Problem Summary
Given a binary string $S$ of length $N$, we need to count the number of '1's that appear after the first occurrence of a '0'. Essentially, any '1' encountered before the first '0' is ignored, and all '1's appearing at any index after the first '0' are counted.

## Intuition & Mathematical Observation
The problem asks us to identify a "starting point" (the first '0') and then process the remainder of the string. 

1. **State Tracking**: We can use a boolean flag, `silence_found`, initialized to `false`.
2. **Iteration**: As we traverse the string from left to right:
   - If we encounter a '0', we set `silence_found` to `true`. This marks that we have passed the initial phase.
   - If we encounter a '1' and `silence_found` is `true`, we increment our `pulse_count`.
3. **Edge Cases**: If the string contains no '0's, the `silence_found` flag will remain `false`, and the count will correctly remain 0. If the string starts with a '0', all subsequent '1's will be counted.

## Complexity Analysis
- **Time Complexity**: $O(N)$, where $N$ is the length of the string. We perform a single pass through the string.
- **Space Complexity**: $O(N)$ to store the input string (or $O(1)$ if processed character by character).

## Solution Code

```cpp
#include <iostream>
#include <string>

using namespace std;

/**
 * Problem: P2BAR
 * Logic:
 * Iterate through the string. Maintain a flag 'silence_found'.
 * Once 'silence_found' becomes true, increment a counter for every '1' encountered.
 */

void solve() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    int pulse_count = 0;
    bool silence_found = false;

    for (int i = 0; i < N; ++i) {
        if (S[i] == '0') {
            silence_found = true;
        } else if (S[i] == '1') {
            if (silence_found) {
                pulse_count++;
            }
        }
    }

    cout << pulse_count << endl;
}

int main() {
    // Optimize I/O operations
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