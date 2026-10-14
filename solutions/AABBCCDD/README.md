# [AabBcCDd (AABBCCDD)](https://www.codechef.com/problems/AABBCCDD)

- **Difficulty Rating**: 972
- **Solved in**: 1 attempt(s)

## Problem Summary
Given a string $S$ of length $N$ containing both uppercase and lowercase English letters, we are allowed two operations:
1. Convert any uppercase letter to its lowercase equivalent.
2. Choose one lowercase letter and change all its occurrences to any other lowercase letter.

We want to maximize the frequency of a single character after performing the second operation exactly once.

## Intuition & Mathematical Observation
1. **Normalization**: Since uppercase letters can be converted to lowercase, we treat 'A' and 'a' as the same character. We first count the occurrences of each letter 'a' through 'z' (ignoring case).
2. **Merging**: Operation 2 allows us to merge the counts of two different characters. If we have frequencies $f_1, f_2, \dots, f_{26}$, choosing to change all occurrences of character $i$ to character $j$ results in a new frequency for $j$ equal to $f_i + f_j$.
3. **Maximization**: To maximize the resulting frequency, we should identify the two characters with the highest frequencies and merge them. The maximum score will be the sum of the two largest values in our frequency array.
4. **Edge Cases**: If the string contains fewer than two distinct characters, the logic still holds (we simply add the frequency of the most frequent character to the next highest, which might be 0).

## Complexity Analysis
- **Time Complexity**: $O(N + \Sigma \log \Sigma)$, where $N$ is the length of the string and $\Sigma = 26$ (the size of the alphabet). Since $\Sigma$ is constant, this simplifies to $O(N)$.
- **Space Complexity**: $O(\Sigma)$, which is $O(1)$ as we only store the frequency count for the 26 letters of the alphabet.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * 1. Operation 1 allows converting any uppercase letter to its lowercase equivalent.
 *    This means we can effectively treat every uppercase letter 'X' as a potential 
 *    lowercase letter 'x'.
 * 2. Operation 2 allows us to pick one lowercase letter and change all its 
 *    occurrences to another lowercase letter.
 * 
 * Strategy:
 * - First, convert all uppercase letters to their lowercase equivalents.
 *   After this, we have a string consisting only of lowercase letters.
 * - Let the frequency of each lowercase character 'a'-'z' be count[char].
 * - Operation 2 allows us to merge the counts of two different characters.
 *   If we choose to merge character 'x' into character 'y', the new count of 'y'
 *   becomes count[y] + count[x].
 * - To maximize the score, we should pick the two characters with the highest 
 *   frequencies and merge them.
 */

void solve() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    if (N == 0) {
        cout << 0 << "\n";
        return;
    }

    vector<int> counts(26, 0);
    for (char c : S) {
        if (c >= 'A' && c <= 'Z') {
            counts[c - 'A']++;
        } else {
            counts[c - 'a']++;
        }
    }

    // Sort frequencies to find the two largest
    sort(counts.rbegin(), counts.rend());

    // The maximum score is the sum of the two most frequent characters.
    cout << counts[0] + counts[1] << "\n";
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