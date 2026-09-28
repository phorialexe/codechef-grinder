# [Encoding Message (ENCMSG)](https://www.codechef.com/problems/ENCMSG)

- **Difficulty Rating**: 1027
- **Solved in**: 1 attempt(s)

## Problem Summary
The task is to encode a given string of length $N$ using two specific transformations:
1. **Swapping**: Swap adjacent characters in pairs (index 0 with 1, 2 with 3, etc.). If the string length is odd, the last character remains in its original position.
2. **Mirroring**: Replace each character with its "mirror" in the alphabet (e.g., 'a' becomes 'z', 'b' becomes 'y', ..., 'z' becomes 'a').

## Intuition & Mathematical Observation
- **Swapping**: We can iterate through the string with a step of 2. For each index `i`, we swap `s[i]` and `s[i+1]` provided `i+1 < N`.
- **Mirroring**: To find the mirror of a character, we observe the distance from the start of the alphabet ('a') and subtract it from the end of the alphabet ('z').
    - The distance of a character `c` from 'a' is `c - 'a'`.
    - The mirrored character is `'z' - (c - 'a')`.
    - This simplifies to `'a' + ('z' - c)`.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the length of the string. We perform two linear passes over the string.
- **Space Complexity**: $O(N)$ to store the input string.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Encoding Message
 * Approach:
 * 1. Step 1: Swap adjacent characters in pairs (0,1), (2,3), etc.
 *    If N is odd, the last character remains untouched.
 * 2. Step 2: Replace each character 'c' with its mirror in the alphabet.
 *    The mirror of 'a' (0) is 'z' (25), 'b' (1) is 'y' (24), etc.
 *    Formula: new_char = 'a' + ('z' - old_char)
 * 
 * Time Complexity: O(N) per test case.
 * Space Complexity: O(N) to store the string.
 */

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    // Step 1: Swap adjacent characters
    for (int i = 0; i + 1 < n; i += 2) {
        swap(s[i], s[i + 1]);
    }

    // Step 2: Replace characters
    // 'a' -> 'z', 'b' -> 'y', ..., 'z' -> 'a'
    for (int i = 0; i < n; ++i) {
        s[i] = 'a' + ('z' - s[i]);
    }

    cout << s << "\n";
}

int main() {
    // Fast I/O
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