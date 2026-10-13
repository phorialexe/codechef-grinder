# [Non-matching Name (ABNOMAT)](https://www.codechef.com/problems/ABNOMAT)

- **Difficulty Rating**: 947
- **Solved in**: 1 attempt(s)

## Problem Summary
Alice and Bob want to name an algorithm. Alice is happy if the name shares no characters with her string $S_A$. Bob is happy if the name shares no characters with his string $S_B$. We need to determine if there exists at least one character (from 'a' to 'z') that is present in neither $S_A$ nor $S_B$. If such a character exists, we can use it as the name, making both Alice and Bob happy.

## Intuition & Mathematical Observation
The problem asks for a character $c \in \{\text{'a'}, \dots, \text{'z'}\}$ such that $c \notin S_A$ AND $c \notin S_B$. 

1. We can represent the presence of characters in $S_A$ and $S_B$ using boolean arrays (or frequency arrays) of size 26.
2. By iterating through the entire alphabet (indices 0 to 25), we check if there is any index $i$ where `in_SA[i]` is `false` AND `in_SB[i]` is `false`.
3. If we find such an index, it means the character corresponding to that index is absent from both strings, satisfying the condition for both Alice and Bob. If we check all 26 characters and find no such match, it is impossible to satisfy both parties.

## Complexity Analysis
- **Time Complexity**: $O(N + M)$, where $N$ and $M$ are the lengths of strings $S_A$ and $S_B$ respectively. We iterate through each string once to populate the boolean arrays and then perform a constant time check (26 iterations).
- **Space Complexity**: $O(1)$, as we use two fixed-size boolean arrays of size 26, regardless of the input string lengths.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Alice is happy if the name shares no characters with S_B.
 * Bob is happy if the name shares no characters with S_A.
 * We need to find if there exists a character 'c' such that 'c' is not in S_A 
 * AND 'c' is not in S_B.
 */

void solve() {
    int N, M;
    cin >> N >> M;
    string SA, SB;
    cin >> SA >> SB;

    vector<bool> in_SA(26, false);
    vector<bool> in_SB(26, false);

    // Mark characters present in SA
    for (char c : SA) {
        in_SA[c - 'a'] = true;
    }
    // Mark characters present in SB
    for (char c : SB) {
        in_SB[c - 'a'] = true;
    }

    // Check if any character is absent from both
    bool found = false;
    for (int i = 0; i < 26; ++i) {
        if (!in_SA[i] && !in_SB[i]) {
            found = true;
            break;
        }
    }

    if (found) {
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