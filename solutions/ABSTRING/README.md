# [String Game (ABSTRING)](https://www.codechef.com/problems/ABSTRING)

- **Difficulty Rating**: 1102
- **Solved in**: 1 attempt(s)

## Problem Summary
Alice and Bob are playing a game with a string $S$ of length $N$. They take turns picking characters from the string until it is empty. Alice and Bob want to know if it is possible for them to end up with identical strings (i.e., they both collect the same multiset of characters). We need to determine if this is possible given the input string $S$.

## Intuition & Mathematical Observation
The core requirement for Alice and Bob to have identical strings is that they must each possess the exact same count of every character ('a' through 'z'). 

1. **Parity Constraint**: Since the total number of characters $N$ must be split equally between two people, $N$ must be even. If $N$ is odd, it is impossible to distribute the characters equally, so the answer is immediately "NO".
2. **Frequency Constraint**: For any character $c$, if the total count of $c$ in the string $S$ is $count(c)$, Alice and Bob must each receive $count(c) / 2$ instances of that character. This is only possible if $count(c)$ is an **even number** for every character present in the string.
3. **Sufficiency**: If $N$ is even and every character appears an even number of times, we can always distribute the characters such that Alice and Bob receive identical sets. For every pair of identical characters, we can assign one to Alice and one to Bob.

## Complexity Analysis
- **Time Complexity**: $O(N)$, where $N$ is the length of the string. We iterate through the string once to count frequencies and then iterate through a fixed-size array of 26 characters.
- **Space Complexity**: $O(1)$, as we use a fixed-size frequency array of size 26, regardless of the input size $N$.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Alice and Bob take turns picking characters from string S.
 * Since they take turns, Alice will pick N/2 characters and Bob will pick N/2 characters.
 * For their final strings A and B to be identical, they must have picked the same 
 * multiset of characters.
 * 
 * This means for every character 'a' through 'z', the total count of that character 
 * in the original string S must be even. If any character appears an odd number 
 * of times, it is impossible to distribute them equally between Alice and Bob.
 */

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    // If the length is odd, it's impossible to split into two equal strings
    if (n % 2 != 0) {
        cout << "NO" << "\n";
        return;
    }

    // Count frequency of each character
    vector<int> freq(26, 0);
    for (char c : s) {
        freq[c - 'a']++;
    }

    // Check if every character appears an even number of times
    bool possible = true;
    for (int i = 0; i < 26; ++i) {
        if (freq[i] % 2 != 0) {
            possible = false;
            break;
        }
    }

    if (possible) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
```