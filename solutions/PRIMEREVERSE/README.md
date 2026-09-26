# [Prime Reversal (PRIMEREVERSE)](https://www.codechef.com/problems/PRIMEREVERSE)

- **Difficulty Rating**: 1053
- **Solved in**: 1 attempt(s)

## Problem Summary
Given two binary strings $A$ and $B$ of length $N$, you are allowed to choose any substring of length $X$, where $X$ is a prime number, and reverse it. The goal is to determine if string $A$ can be transformed into string $B$ using any number of these operations.

## Intuition & Mathematical Observation
The core of the problem lies in understanding the power of the allowed operations:
1. **Adjacent Swaps**: Since $2$ is a prime number, we can reverse any substring of length $2$. Reversing a substring of length $2$ is equivalent to swapping two adjacent elements.
2. **Arbitrary Permutations**: If we can swap any two adjacent elements, we can perform a bubble-sort-like process to move any character to any position. This implies that if we have the ability to perform adjacent swaps, we can rearrange the string into **any possible permutation**.
3. **The Prime Constraint**: While the problem restricts us to prime lengths, the existence of the prime number $2$ is sufficient to generate all possible permutations of the string. Even if we only had access to length $2$ and $3$, we could achieve any permutation.
4. **Conclusion**: Because we can rearrange the strings into any order, the only requirement for string $A$ to be transformable into string $B$ is that they must contain the exact same count of '0's and '1's.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the length of the string. We iterate through each string exactly once to count the characters.
- **Space Complexity**: $O(N)$ to store the input strings $A$ and $B$.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are allowed to reverse any substring of length X, where X is a prime number.
 * 
 * Key Insight:
 * 1. If we can reverse a substring of length 2, we can swap any two adjacent elements.
 * 2. If we can swap any two adjacent elements, we can perform any permutation of the string.
 * 3. Therefore, string A can be transformed into string B if and only if they have 
 *    the same number of '0's and '1's.
 */

void solve() {
    int N;
    cin >> N;
    string A, B;
    cin >> A >> B;

    int countA0 = 0, countA1 = 0;
    int countB0 = 0, countB1 = 0;

    // Count occurrences in string A
    for (char c : A) {
        if (c == '0') countA0++;
        else countA1++;
    }

    // Count occurrences in string B
    for (char c : B) {
        if (c == '0') countB0++;
        else countB1++;
    }

    // Compare counts
    if (countA0 == countB0 && countA1 == countB1) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
}

int main() {
    // Fast I/O
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