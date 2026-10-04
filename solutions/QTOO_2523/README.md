# [Bi_lindrome! (QTOO_2523)](https://www.codechef.com/problems/QTOO_2523)

- **Difficulty Rating**: 1095
- **Solved in**: 1 attempt(s)

## Problem Summary
Given a string $S$ of length $N$, we need to delete a subsequence of maximum length such that the remaining characters form a palindrome of length greater than 1. If it is impossible to form such a palindrome, output -1.

## Intuition & Mathematical Observation
To maximize the number of deleted characters, we must minimize the number of characters kept. The problem states the remaining characters must form a palindrome of length $> 1$.

1.  **The Shortest Palindrome**: The smallest possible palindrome with length $> 1$ is a palindrome of length 2 (e.g., "aa").
2.  **Condition for Existence**: A palindrome of length 2 can be formed if and only if there is at least one character in the string that appears at least twice. 
    *   If a character repeats, we can pick two instances of that character to form a palindrome of length 2. By keeping only these 2 characters and deleting the remaining $N-2$ characters, we achieve the maximum possible deletion.
    *   If all characters in the string are unique, it is impossible to form any palindrome of length $> 1$ because any subsequence of length $\ge 2$ would consist of distinct characters, which cannot form a palindrome.
3.  **Conclusion**: 
    *   If any character frequency $\ge 2$, the answer is $N - 2$.
    *   Otherwise, the answer is $-1$.

## Complexity Analysis
- **Time Complexity**: $O(N)$, where $N$ is the length of the string. We iterate through the string once to count frequencies.
- **Space Complexity**: $O(1)$ (or $O(\Sigma)$ where $\Sigma$ is the alphabet size). Since the alphabet is limited (e.g., 26 lowercase English letters), the map/frequency array uses constant space.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * To maximize the number of deleted characters, we minimize the length of the 
 * remaining palindrome. The smallest palindrome length > 1 is 2.
 * If any character appears at least twice, we can form a palindrome of length 2.
 * Otherwise, it is impossible.
 */

void solve() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    // Frequency map to track character counts
    map<char, int> freq;
    bool possible = false;
    for (char c : S) {
        freq[c]++;
        if (freq[c] >= 2) {
            possible = true;
        }
    }

    // If a duplicate exists, we keep 2 and delete N-2
    if (possible) {
        cout << N - 2 << "\n";
    } else {
        cout << -1 << "\n";
    }
}

int main() {
    // Optimize I/O operations
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