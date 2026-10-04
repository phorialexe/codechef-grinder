# [Cute Strings (CUTESTR)](https://www.codechef.com/problems/CUTESTR)

- **Difficulty Rating**: 271
- **Solved in**: 1 attempt(s)

## Problem Summary
The task is to determine if a given string $S$ of length 3 is "cute." A string is defined as "cute" if and only if it satisfies two specific conditions:
1. The first character is equal to the third character ($S[0] == S[2]$).
2. The middle character is the lowercase letter 'w' ($S[1] == 'w'$).

If both conditions are met, output "Cute"; otherwise, output "No".

## Intuition & Mathematical Observation
The problem is a straightforward implementation task. Since the input string is guaranteed to have a length of 3, we do not need complex loops or data structures. We simply need to access the characters at indices 0, 1, and 2 and perform a boolean comparison:

*   **Condition 1**: `s[0] == s[2]` checks for symmetry at the ends.
*   **Condition 2**: `s[1] == 'w'` checks for the specific middle character.

By using a simple `if-else` statement, we can evaluate these conditions in constant time.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we are performing a fixed number of character comparisons regardless of the input content.
- **Space Complexity**: $O(1)$, as we only store a string of length 3 and a few boolean flags.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: CUTESTR
 * A string S of length 3 is cute if:
 * 1. S[0] == S[2]
 * 2. S[1] == 'w'
 * 
 * Time Complexity: O(1) per test case
 * Space Complexity: O(1)
 */

void solve() {
    string s;
    cin >> s;
    
    // Check if the first and third characters are equal
    // and the middle character is 'w'
    if (s[0] == s[2] && s[1] == 'w') {
        cout << "Cute" << "\n";
    } else {
        cout << "No" << "\n";
    }
}

int main() {
    // Fast I/O for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
```