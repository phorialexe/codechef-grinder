# [Chef and his Students (CHEFSTUD)](https://www.codechef.com/problems/CHEFSTUD)

- **Difficulty Rating**: 1047
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef has a row of students represented by a string consisting of `'<'` (talking to the left), `'>'` (talking to the right), and `'*'` (studying). After some time, all students who were talking to the right turn to the left, and all students who were talking to the left turn to the right. Students who were studying remain unchanged. We need to count how many pairs of students are "talking to each other" (i.e., facing each other) in the new configuration.

## Intuition & Mathematical Observation
Let's analyze the transformation:
1. Original `'>'` becomes `'<'`
2. Original `'<'` becomes `'>'`
3. Original `'*'` remains `'*'`

A pair of students is "talking to each other" if they are facing each other. In a string, this occurs when a student at index $i$ is facing right (`'>'`) and the student at index $i+1$ is facing left (`'<'`), forming the pattern `"><"`.

We want to find the number of `"><"` patterns in the **transformed** string.
- If the original string has a `'<'` at index $i$ and a `'>'` at index $i+1$, the transformed string will have a `'>'` at index $i$ and a `'<'` at index $i+1$.
- Therefore, the pattern `"><"` in the transformed string corresponds exactly to the pattern `"<>"` in the original string.

**Conclusion:** Instead of transforming the string and searching for `"><"`, we can simply count the occurrences of the substring `"<>"` in the original input string.

## Complexity Analysis
- **Time Complexity**: $O(N)$, where $N$ is the length of the string. We perform a single pass through the string to count the occurrences of the target pattern.
- **Space Complexity**: $O(N)$ to store the input string (or $O(1)$ if processed character by character).

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The transformation swaps '<' and '>'.
 * A pair is "talking to each other" if the new string contains "><".
 * This is equivalent to finding "<>" in the original string.
 */

void solve() {
    string s;
    cin >> s;
    int count = 0;
    
    // Iterate through the string and count occurrences of "<>"
    for (size_t i = 0; i + 1 < s.length(); ++i) {
        if (s[i] == '<' && s[i + 1] == '>') {
            count++;
        }
    }
    cout << count << "\n";
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