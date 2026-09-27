# [Playing with Strings (PLAYSTR)](https://www.codechef.com/problems/PLAYSTR)

- **Difficulty Rating**: 1108
- **Solved in**: 1 attempt(s)

## Problem Summary
Given two binary strings $S$ and $R$ of length $N$, determine if it is possible to transform $S$ into $R$ by performing any number of swaps between any two characters in $S$.

## Intuition & Mathematical Observation
The key insight is that the operation allowed is **swapping any two characters**. In combinatorics, if you can swap any two elements in a set, you can achieve any permutation of that set. 

Since the strings consist only of '0's and '1's, rearranging $S$ into $R$ is possible if and only if both strings contain the exact same number of '0's and '1's. Because the total length $N$ is fixed, if the count of '1's in $S$ is equal to the count of '1's in $R$, the count of '0's must automatically be equal as well. 

Therefore, the problem reduces to a simple frequency count comparison:
1. Count the number of '1's in string $S$.
2. Count the number of '1's in string $R$.
3. If the counts are equal, output `YES`; otherwise, output `NO`.

## Complexity Analysis
- **Time Complexity**: $O(N)$, where $N$ is the length of the strings. We iterate through each string exactly once to count the characters.
- **Space Complexity**: $O(N)$ to store the input strings. If we processed the strings character-by-character without storing them, this could be reduced to $O(1)$ auxiliary space.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The operation allowed is to swap any two characters in string S.
 * Swapping characters allows us to rearrange the string S into any permutation 
 * of its original characters.
 * 
 * A binary string consists only of '0's and '1's. If we can rearrange S into R,
 * it implies that the count of '0's in S must equal the count of '0's in R,
 * and the count of '1's in S must equal the count of '1's in R.
 * 
 * Since the total length N is fixed and the strings are binary, if the number 
 * of '1's is the same in both strings, the number of '0's must also be the same.
 * Therefore, the condition for S to be transformable into R is simply:
 * count('1' in S) == count('1' in R).
 */

void solve() {
    int N;
    cin >> N;
    string S, R;
    cin >> S >> R;

    int countS1 = 0;
    int countR1 = 0;

    for (char c : S) {
        if (c == '1') countS1++;
    }

    for (char c : R) {
        if (c == '1') countR1++;
    }

    if (countS1 == countR1) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
}

int main() {
    // Optimize I/O operations
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