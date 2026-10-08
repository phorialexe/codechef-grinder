# [Play Piano (PLAYPIAN)](https://www.codechef.com/problems/PLAYPIAN)

- **Difficulty Rating**: 980
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given a string representing a log of piano sessions where two people, A and B, play exactly once each day. The string length is always even, and each pair of characters represents one day. We need to determine if the log is valid, meaning that on every given day, the two characters must be different (i.e., one must be 'A' and the other must be 'B').

## Intuition & Mathematical Observation
The problem states that every day consists of two sessions, one by A and one by B. This implies that for any day $i$ (where $i$ ranges from $0$ to $n/2 - 1$), the characters at indices $2i$ and $2i+1$ must not be identical. 

If we encounter a pair where `s[2i] == s[2i+1]`, it means either both played 'A' or both played 'B' on that day, which contradicts the problem statement. Therefore, the log is valid if and only if every consecutive pair starting at an even index contains exactly one 'A' and one 'B'.

## Complexity Analysis
- **Time Complexity**: $O(N)$, where $N$ is the length of the string. We iterate through the string exactly once, checking each pair.
- **Space Complexity**: $O(N)$ to store the input string, or $O(1)$ auxiliary space if we consider the input storage separately.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The log records the piano sessions for multiple days.
 * Each day, both A and B play exactly once.
 * This means every 2 characters in the string represent one day.
 * For each pair (s[2*i], s[2*i+1]), one must be 'A' and the other must be 'B'.
 * If any pair consists of two identical characters (e.g., "AA" or "BB"), 
 * the log is invalid.
 */

void solve() {
    string s;
    cin >> s;
    
    bool possible = true;
    int n = s.length();
    
    // Iterate through the string in steps of 2
    for (int i = 0; i < n; i += 2) {
        // Check if the two characters in the current day are different
        if (s[i] == s[i + 1]) {
            possible = false;
            break;
        }
    }
    
    if (possible) {
        cout << "yes" << "\n";
    } else {
        cout << "no" << "\n";
    }
}

int main() {
    // Fast I/O setup
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