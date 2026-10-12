# [Front-Back Matching (FBMATCH)](https://www.codechef.com/problems/FBMATCH)

- **Difficulty Rating**: 632
- **Solved in**: 1 attempt(s)

## Problem Summary
Given a string $S$ of length $N$, determine if it is possible to rearrange the characters of the string such that the first character and the last character are identical.

## Intuition & Mathematical Observation
To make the first and last characters of a string identical, we need to pick a character $c$ that appears at least twice in the string. If such a character exists, we can place one instance of $c$ at the beginning and one instance of $c$ at the end. The remaining $N-2$ characters can then be placed in the middle in any arbitrary order.

Therefore, the problem reduces to a simple frequency count:
1. Count the occurrences of every character ('a' through 'z') in the string.
2. If any character has a frequency $\ge 2$, it is possible to satisfy the condition.
3. If all characters appear only once (or if the string length is less than 2), it is impossible to have the first and last characters match.

## Complexity Analysis
- **Time Complexity**: $O(N)$, where $N$ is the length of the string. We iterate through the string once to count frequencies and then iterate through a fixed-size array of 26 characters.
- **Space Complexity**: $O(1)$, as we only use a fixed-size array of size 26 to store character frequencies, regardless of the input size $N$.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given a string S of length N. We can rearrange the characters.
 * We want to know if we can make the first and last characters equal.
 * 
 * If we have at least two occurrences of any character 'c', we can place one 'c' 
 * at the start and one 'c' at the end. The remaining N-2 characters can be 
 * placed in between in any order.
 * 
 * Therefore, the condition is simply: Does the string contain at least one 
 * character that appears 2 or more times?
 */

void solve() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    // Count frequencies of each character
    vector<int> freq(26, 0);
    for (char c : S) {
        freq[c - 'a']++;
    }

    // Check if any character appears at least twice
    bool possible = false;
    for (int i = 0; i < 26; ++i) {
        if (freq[i] >= 2) {
            possible = true;
            break;
        }
    }

    if (possible) {
        cout << "Yes" << "\n";
    } else {
        cout << "No" << "\n";
    }
}

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
```