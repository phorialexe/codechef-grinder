# [Even-tual Reduction (EVENTUAL)](https://www.codechef.com/problems/EVENTUAL)

- **Difficulty Rating**: 1040
- **Solved in**: 1 attempt(s)

## Problem Summary
Given a string of length $N$, we are allowed to perform an operation where we choose a substring and remove it, provided that every character in that substring appears an even number of times within that substring. The goal is to determine if it is possible to erase the entire string using any number of these operations.

## Intuition & Mathematical Observation
The core of the problem lies in the invariant property of the operation:
1. **The Invariant**: Each operation removes an even number of occurrences of each character present in the chosen substring. 
2. **The Constraint**: To erase the entire string, we must reduce the count of every character present in the original string to exactly zero.
3. **The Logic**: Since we start with a specific frequency for each character and subtract even numbers from these frequencies, the parity (odd or even) of the count of each character remains unchanged throughout the process. 
   - If a character appears an **odd** number of times initially, it will always have an odd count after any number of operations. Since zero is an even number, we can never reach zero if we start with an odd frequency.
   - If every character appears an **even** number of times, we can simply choose the entire string as our substring (since it satisfies the condition) and erase it in one go.

**Conclusion**: The string can be fully erased if and only if the frequency of every character in the string is even.

## Complexity Analysis
- **Time Complexity**: $O(N)$, where $N$ is the length of the string. We iterate through the string once to count frequencies and then iterate through a fixed-size array of 26 characters.
- **Space Complexity**: $O(1)$, as we only use a frequency array of size 26, which is constant regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The operation allows us to remove a substring if every character in that substring 
 * appears an even number of times. 
 * 
 * Key Insight:
 * If we can erase the entire string, it implies that every character in the original 
 * string must appear an even number of times. 
 */

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    // If the length is odd, it's impossible for all characters to have even counts.
    if (n % 2 != 0) {
        cout << "NO" << "\n";
        return;
    }

    // Count frequencies of each character
    vector<int> freq(26, 0);
    for (char c : s) {
        freq[c - 'a']++;
    }

    // Check if all frequencies are even
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