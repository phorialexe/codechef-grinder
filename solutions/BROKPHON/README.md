# [Broken Telephone (BROKPHON)](https://www.codechef.com/problems/BROKPHON)

- **Difficulty Rating**: 1204
- **Solved in**: 1 attempt(s)

## Problem Summary
In a game of "Broken Telephone," $N$ players are standing in a line. Each player $i$ receives a message $A[i]$ from the previous player and passes it to the next. A mistake occurs if the message received by player $i$ is different from the message received by player $i+1$. If such a discrepancy exists, both players $i$ and $i+1$ are considered to have participated in a "broken" link. The goal is to find the total number of unique players who were involved in at least one broken link.

## Intuition & Mathematical Observation
The core of the problem lies in identifying the indices where the message changes. 
- If $A[i] \neq A[i+1]$, it implies that the information was corrupted between player $i$ and player $i+1$. 
- Consequently, both player $i$ and player $i+1$ are involved in the error.
- Since a player might be involved in multiple broken links (e.g., if $A[i-1] \neq A[i]$ and $A[i] \neq A[i+1]$), we must ensure we count each unique player only once.

**Approach:**
1. Initialize a boolean array `is_broken` of size $N$ with `false`.
2. Iterate through the array from $i = 0$ to $N-2$.
3. If $A[i] \neq A[i+1]$, set `is_broken[i] = true` and `is_broken[i+1] = true`.
4. Finally, count the number of `true` values in the `is_broken` array. This avoids double-counting players involved in multiple discrepancies.

## Complexity Analysis
- **Time Complexity**: $O(N)$, where $N$ is the number of players. We perform a single pass to identify broken links and another pass to count the marked players.
- **Space Complexity**: $O(N)$ to store the message array and the boolean tracking array.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * A player i (1-indexed) is involved in a mistake if:
 * 1. The message they received (A[i]) is different from the message the previous player received (A[i-1]).
 * 2. The message they whispered (A[i]) is different from the message the next player received (A[i+1]).
 * 
 * Essentially, if A[i] != A[i+1], then both player i and player i+1 are part of a "broken" link.
 * We use a boolean array 'is_broken' to mark players and count unique occurrences.
 */

void solve() {
    int N;
    cin >> N;
    vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    vector<bool> is_broken(N, false);
    for (int i = 0; i < N - 1; ++i) {
        if (A[i] != A[i + 1]) {
            is_broken[i] = true;
            is_broken[i + 1] = true;
        }
    }

    int count = 0;
    for (int i = 0; i < N; ++i) {
        if (is_broken[i]) {
            count++;
        }
    }
    cout << count << "\n";
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