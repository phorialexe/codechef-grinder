# [Strong Language (SSCRIPT)](https://www.codechef.com/problems/SSCRIPT)

- **Difficulty Rating**: 1291
- **Solved in**: 1 attempt(s)

## Problem Summary
Given a string $S$ of length $N$ consisting of lowercase English letters and asterisks ('*'), determine if the string contains a contiguous substring of asterisks with a length of at least $K$.

## Intuition & Mathematical Observation
The problem asks for the existence of a sequence of at least $K$ consecutive '*' characters. 

1. **Linear Scan**: We can iterate through the string while maintaining a counter (`current_consecutive`) that tracks the length of the current streak of asterisks.
2. **Reset Logic**: Whenever we encounter a character that is not an asterisk, the current streak is broken, and we reset the counter to $0$.
3. **Early Exit**: As soon as the counter reaches $K$, we have satisfied the condition. We can set a flag to `true` and terminate the loop early to optimize performance.
4. **Result**: If the loop finishes without the counter ever reaching $K$, the answer is "NO"; otherwise, it is "YES".

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the length of the string. We perform a single pass through the string.
- **Space Complexity**: $O(N)$ to store the input string $S$.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Strong Language
 * Approach:
 * We need to find if there exists a substring of '*' with length at least K.
 * We can iterate through the string and maintain a counter for consecutive '*'.
 * If the counter reaches K, we immediately know the answer is "YES".
 * If we encounter a character that is not '*', we reset the counter to 0.
 * Time Complexity: O(N) per test case, where N is the length of the string.
 * Space Complexity: O(N) to store the string.
 */

void solve() {
    int N, K;
    cin >> N >> K;
    string S;
    cin >> S;

    int current_consecutive = 0;
    bool found = false;

    for (int i = 0; i < N; ++i) {
        if (S[i] == '*') {
            current_consecutive++;
            if (current_consecutive >= K) {
                found = true;
                break;
            }
        } else {
            current_consecutive = 0;
        }
    }

    if (found) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
}

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        solve();
    }
    return 0;
}
```