# [Make Cat (INCAT)](https://www.codechef.com/problems/INCAT)

- **Difficulty Rating**: 210
- **Solved in**: 1 attempt(s)

## Problem Summary
Given a string $S$ of length 3, determine if the characters can be rearranged to form the word "cat". In other words, we need to check if the string contains exactly one 'c', one 'a', and one 't'.

## Intuition & Mathematical Observation
To determine if a string is a permutation of another, the most straightforward approach is to sort both strings and compare them. 

1. The target word is "cat".
2. If we sort the characters of "cat" alphabetically, we get "act".
3. If we sort the input string $S$, it will also result in "act" if and only if $S$ is a permutation of "cat".
4. Therefore, the problem reduces to: `sort(S) == "act"`.

## Complexity Analysis
- **Time Complexity**: $O(N \log N)$, where $N$ is the length of the string. Since $N=3$ is a constant, this is effectively $O(1)$.
- **Space Complexity**: $O(1)$, as we are only storing a string of length 3 and performing an in-place sort.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given a string S of length 3. We need to determine if it can be 
 * rearranged to form the word "cat".
 * 
 * A string of length 3 can be rearranged to "cat" if and only if it contains
 * exactly one 'c', one 'a', and one 't'.
 * 
 * Approach:
 * 1. Sort the input string S.
 * 2. Compare the sorted string with "act" (which is "cat" sorted).
 * 3. If they are equal, output "Yes", otherwise "No".
 */

void solve() {
    string s;
    if (!(cin >> s)) return;
    
    // Sort the string to check if it contains exactly 'a', 'c', 't'
    sort(s.begin(), s.end());
    
    if (s == "act") {
        cout << "Yes" << "\n";
    } else {
        cout << "No" << "\n";
    }
}

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    solve();
    
    return 0;
}
```