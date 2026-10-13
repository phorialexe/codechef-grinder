# [Sabotage (SBTG)](https://www.codechef.com/problems/SBTG)

- **Difficulty Rating**: 984
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef has an initial score $X$ and faces $N$ opponents, each with a score $A_i$. The rank is defined as $1 + (\text{number of opponents with score } > X)$. Chef can perform a "sabotage" operation at most $K$ times. Each operation allows Chef to choose one opponent, set their score to $0$, and increase Chef's own score $X$ by $100$. The goal is to minimize Chef's rank after performing at most $K$ operations.

## Intuition & Mathematical Observation
To minimize the rank, we need to minimize the number of opponents whose scores are strictly greater than Chef's current score. 

1. **Greedy Strategy**: Since we want to eliminate as many opponents as possible from the "greater than $X$" category, we should always target the opponents with the highest scores first. By sabotaging the highest scores, we remove them from the count and simultaneously increase our own score $X$, which potentially makes other opponents' scores no longer "greater than $X$".
2. **Brute Force over $K$**: Since $K$ is relatively small (or the constraints allow for it), we can iterate through every possible number of sabotages $s$ from $0$ to $K$. 
3. **Calculation**: For a fixed $s$:
   - Chef's score becomes $X' = X + (s \times 100)$.
   - The $s$ largest opponents are removed (effectively set to $0$).
   - We count how many of the remaining $N-s$ opponents have scores $> X'$.
   - The rank is $1 + \text{count}$.
4. **Optimization**: By sorting the array $A$ in descending order, the first $s$ elements are always the ones we choose to sabotage. This makes the calculation for each $s$ efficient.

## Complexity Analysis
- **Time Complexity**: $O(T \times (N \log N + K \times N))$. Given the constraints, sorting takes $O(N \log N)$, and the nested loop runs $K$ times with an $O(N)$ scan, which is well within the time limits for typical competitive programming constraints.
- **Space Complexity**: $O(N)$ to store the opponent scores.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * To minimize rank, we prioritize sabotaging the highest scores.
 * We iterate through all possible sabotage counts s (0 to K),
 * update Chef's score, and count remaining opponents > X.
 */

void solve() {
    int N;
    long long X, K;
    cin >> N >> X >> K;
    vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // Sort descending to sabotage the largest scores first
    sort(A.begin(), A.end(), greater<long long>());

    int min_rank = N + 1;

    // Try performing sabotage 's' times, where 0 <= s <= K
    for (int s = 0; s <= K; ++s) {
        long long current_X = X + (long long)s * 100;
        int count_greater = 0;
        
        // After sabotaging s opponents, the first s elements are effectively 0.
        // We only check the remaining N - s elements.
        for (int i = s; i < N; ++i) {
            if (A[i] > current_X) {
                count_greater++;
            }
        }
        
        int current_rank = count_greater + 1;
        if (current_rank < min_rank) {
            min_rank = current_rank;
        }
    }

    cout << min_rank << "\n";
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