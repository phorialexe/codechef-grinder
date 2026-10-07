# [Chef and Groups (GROUPS)](https://www.codechef.com/problems/GROUPS)

- **Difficulty Rating**: 1176
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given a string $S$ consisting of '0's and '1's. A "group" is defined as a contiguous sequence of '1's. The goal is to determine the total number of such groups present in the string.

## Intuition & Mathematical Observation
A group of '1's is formed whenever we transition from a '0' to a '1' or when a '1' appears at the very start of the string. 

Instead of trying to extract substrings or using complex data structures, we can simply iterate through the string and identify the **start** of each group:
1. If the current character is `'1'` and it is the first character of the string (`i == 0`), it marks the beginning of a new group.
2. If the current character is `'1'` and the previous character was `'0'` (`s[i-1] == '0'`), it indicates that a new group has just begun.

By counting these specific occurrences, we effectively count the number of contiguous blocks of '1's without needing to store or modify the string further.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the length of the string. We perform a single pass through the string.
- **Space Complexity**: $O(N)$ to store the input string. If we processed the input character by character, this could be reduced to $O(1)$ auxiliary space.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * A group is defined as a contiguous sequence of '1's.
 * We need to count how many such sequences exist in the string S.
 * 
 * Logic:
 * A new group starts whenever we encounter a '1' that is either at the 
 * beginning of the string or is preceded by a '0'.
 * 
 * Time Complexity: O(N) per test case, where N is the length of the string.
 * Space Complexity: O(N) to store the string.
 */

void solve() {
    string s;
    cin >> s;
    
    int groups = 0;
    int n = s.length();
    
    for (int i = 0; i < n; ++i) {
        if (s[i] == '1') {
            // If this is the start of a group:
            // It's the start if it's the first character or the previous was '0'
            if (i == 0 || s[i - 1] == '0') {
                groups++;
            }
        }
    }
    
    cout << groups << "\n";
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