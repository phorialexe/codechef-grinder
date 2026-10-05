# [Echo (ECHOECHO)](https://www.codechef.com/problems/ECHOECHO)

- **Difficulty Rating**: 231
- **Solved in**: 1 attempt(s)

## Problem Summary
Given a string $S$ of length 4, determine if it is an "echo" string. A string is defined as an echo if the first two characters are repeated exactly in the last two positions. Specifically, the character at index 0 must equal the character at index 2, and the character at index 1 must equal the character at index 3.

## Intuition & Mathematical Observation
The problem asks us to verify a pattern of periodicity in a short string. Since the string length is fixed at 4, we do not need complex loops or data structures. We simply need to access the characters at specific indices:
- Compare `S[0]` with `S[2]`
- Compare `S[1]` with `S[3]`

If both conditions are true, the string follows the echo pattern. Otherwise, it does not.

## Complexity Analysis
- **Time Complexity**: $O(1)$ — The operations involve a constant number of comparisons regardless of the input (since the input size is fixed at 4).
- **Space Complexity**: $O(1)$ — We only store a string of length 4, which occupies constant space.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given a string S of length 4.
 * An echo is defined as S[0] == S[2] and S[1] == S[3] (using 0-indexing).
 * The constraints are small (length 4), so a simple comparison is O(1).
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    if (!(cin >> s)) return 0;

    // Check the echo condition:
    // S[0] is the 1st character, S[2] is the 3rd character.
    // S[1] is the 2nd character, S[3] is the 4th character.
    if (s[0] == s[2] && s[1] == s[3]) {
        cout << "Yes" << "\n";
    } else {
        cout << "No" << "\n";
    }

    return 0;
}
```