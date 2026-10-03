# [Your Name is Mine (NAME2)](https://www.codechef.com/problems/NAME2)

- **Difficulty Rating**: 1285
- **Solved in**: 1 attempt(s)

## Problem Summary
Given two strings, $M$ and $W$, representing the names of a man and a woman, determine if it is possible for one person to have taken the other's name. This is defined as being possible if one string is a **subsequence** of the other. We need to output "YES" if $M$ is a subsequence of $W$ OR $W$ is a subsequence of $M$, and "NO" otherwise.

## Intuition & Mathematical Observation
A string $A$ is a subsequence of string $B$ if all characters of $A$ appear in $B$ in the same relative order. 

To solve this efficiently:
1. We implement a helper function `isSubsequence(s1, s2)` that uses a **two-pointer approach**.
2. We maintain a pointer `i` for the potential subsequence `s1` and a pointer `j` for the target string `s2`.
3. We iterate through `s2` once. Every time `s2[j]` matches `s1[i]`, we move the pointer `i` forward.
4. If `i` reaches the length of `s1`, it means all characters were found in order, confirming `s1` is a subsequence of `s2`.
5. Since the problem asks if *either* can be a subsequence of the other, we simply check `isSubsequence(m, w) || isSubsequence(w, m)`.

## Complexity Analysis
- **Time Complexity**: $O(|M| + |W|)$ per test case. We perform a single linear scan of the strings. Given the constraints ($|M|, |W| \le 25,000$), this approach is highly efficient and well within the time limits.
- **Space Complexity**: $O(|M| + |W|)$ to store the input strings in memory.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to check if string M is a subsequence of W OR W is a subsequence of M.
 * A string A is a subsequence of B if we can find all characters of A in B 
 * in the same relative order.
 * 
 * Algorithm:
 * To check if A is a subsequence of B:
 * 1. Use two pointers, one for A (i) and one for B (j).
 * 2. Iterate through B with j. If B[j] == A[i], increment i.
 * 3. If i reaches the length of A, then A is a subsequence of B.
 */

bool isSubsequence(const string& s1, const string& s2) {
    int n = s1.length();
    int m = s2.length();
    int i = 0, j = 0;
    
    while (i < n && j < m) {
        if (s1[i] == s2[j]) {
            i++;
        }
        j++;
    }
    return i == n;
}

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        string m, w;
        cin >> m >> w;
        
        // Check if m is a subsequence of w OR w is a subsequence of m
        if (isSubsequence(m, w) || isSubsequence(w, m)) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
    
    return 0;
}
```