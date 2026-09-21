# [Different Consecutive Characters (DIFFCONSEC)](https://www.codechef.com/problems/DIFFCONSEC)

- **Difficulty Rating**: 879
- **Solved in**: 2 attempt(s)

## Problem Summary
Given a binary string $S$ of length $N$, we want to ensure that no two adjacent characters are the same. We are allowed to perform an operation where we insert any character ('0' or '1') at any position in the string. The goal is to find the minimum number of operations required to satisfy the condition.

## Intuition & Mathematical Observation
The problem asks us to eliminate all instances where $S[i] == S[i+1]$. 

1. **Observation**: If we have a pair of identical adjacent characters (e.g., "00" or "11"), we can insert a different character between them to break the conflict. For example, inserting '1' into "00" results in "010", which satisfies the condition locally.
2. **Strategy**: Since we want the *minimum* number of operations, we simply need to count every occurrence where $S[i] == S[i+1]$. Each such occurrence represents a conflict that requires exactly one insertion to resolve.
3. **Logic**: We iterate through the string from index $0$ to $N-2$. Every time we find $S[i] == S[i+1]$, we increment our operation counter. This greedy approach works because each insertion only affects the immediate local neighborhood and resolves one specific conflict.

## Complexity Analysis
- **Time Complexity**: $O(N)$, where $N$ is the length of the string. We perform a single pass through the string to check adjacent pairs.
- **Space Complexity**: $O(N)$ to store the input string (or $O(1)$ if we consider the input storage as given and only count auxiliary space).

## Solution Code

```cpp
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * Problem Analysis:
 * We need to ensure no two consecutive characters are the same.
 * Whenever we find S[i] == S[i+1], we must perform an insertion.
 * Inserting a character between S[i] and S[i+1] breaks the conflict.
 * We iterate through the string and count how many times S[i] == S[i+1].
 */

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int operations = 0;
    // Iterate through the string and check adjacent pairs
    for (int i = 0; i < n - 1; ++i) {
        if (s[i] == s[i + 1]) {
            operations++;
        }
    }
    cout << operations << "\n";
}

int main() {
    // Fast I/O setup for performance
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