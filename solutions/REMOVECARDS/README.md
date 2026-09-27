# [Card Removal (REMOVECARDS)](https://www.codechef.com/problems/REMOVECARDS)

- **Difficulty Rating**: 1039
- **Solved in**: 1 attempt(s)

## Problem Summary
You are given $N$ cards, each having a specific value $A_i$. The goal is to perform the minimum number of card removals such that all remaining cards have the same value. Since removing a card is equivalent to keeping a subset of cards, minimizing removals is equivalent to maximizing the number of cards kept.

## Intuition & Mathematical Observation
To minimize the number of cards removed, we must maximize the number of cards that remain. If we choose to keep all cards of a specific value $X$, the number of cards remaining will be equal to the frequency of $X$ in the original set.

1. Let $N$ be the total number of cards.
2. Let $count(X)$ be the frequency of a card value $X$.
3. The number of cards to remove if we keep value $X$ is $N - count(X)$.
4. To minimize this value, we must choose $X$ such that $count(X)$ is the maximum frequency among all card values present in the input.

Therefore, the answer is simply $N - \max(\text{frequencies})$.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the number of cards. We iterate through the input array once to count frequencies and then iterate through the fixed-size frequency array (size 10) to find the maximum.
- **Space Complexity**: $O(1)$, as we use a fixed-size array of size 11 to store frequencies regardless of the input size $N$.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have N cards with values A_i. We want to keep only cards that have the same value.
 * To minimize the number of moves (removals), we should maximize the number of cards 
 * we keep.
 * 
 * If we decide to keep all cards that have the value 'X', we will keep 'count(X)' cards.
 * The number of moves required would be N - count(X).
 * To minimize this, we need to maximize count(X).
 */

void solve() {
    int N;
    cin >> N;
    
    // Since A_i is small (1 to 10), we can use a frequency array of size 11.
    vector<int> freq(11, 0);
    for (int i = 0; i < N; ++i) {
        int val;
        cin >> val;
        freq[val]++;
    }
    
    int max_freq = 0;
    for (int i = 1; i <= 10; ++i) {
        if (freq[i] > max_freq) {
            max_freq = freq[i];
        }
    }
    
    // Minimum moves = Total cards - cards of the most frequent value
    cout << (N - max_freq) << "\n";
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