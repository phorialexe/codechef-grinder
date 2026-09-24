# [Binary Battles (BIN_BAT)](https://www.codechef.com/problems/BIN_BAT)

- **Difficulty Rating**: 786
- **Solved in**: 1 attempt(s)

## Problem Summary
In a single-elimination tournament with $N$ teams (where $N$ is a power of 2), every round reduces the number of teams by half. Each round lasts $A$ minutes, and there is a break of $B$ minutes between consecutive rounds. We need to calculate the total time taken to complete the tournament until a single winner is determined.

## Intuition & Mathematical Observation
1. **Number of Rounds**: Since $N$ is a power of 2, the number of rounds $R$ required to reach a single winner is given by $R = \log_2(N)$.
2. **Round Time**: Each of the $R$ rounds takes $A$ minutes, contributing $R \times A$ to the total time.
3. **Break Time**: Breaks occur *between* rounds. If there are $R$ rounds, there are $R-1$ breaks. Each break lasts $B$ minutes, contributing $(R-1) \times B$ to the total time.
4. **Total Time Formula**: 
   $$\text{Total Time} = (R \times A) + ((R - 1) \times B)$$

## Complexity Analysis
- **Time Complexity**: $O(\log N)$ per test case. Since $N \le 2^{20}$, calculating the number of rounds takes at most 20 iterations. With $T$ test cases, the total complexity is $O(T \log N)$, which comfortably fits within the time limit.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * N is a power of 2. In a single-elimination tournament, if there are N teams,
 * the number of rounds required to determine a winner is log2(N).
 * 
 * Let R = log2(N).
 * Each round takes A minutes.
 * There is a break of B minutes between every two rounds.
 * Total rounds = R.
 * Total round time = R * A.
 * Total break time = (R - 1) * B (since there is no break after the last round).
 * Total time = (R * A) + ((R - 1) * B).
 */

void solve() {
    long long N, A, B;
    if (!(cin >> N >> A >> B)) return;

    // Calculate number of rounds R such that 2^R = N
    int R = 0;
    long long tempN = N;
    while (tempN > 1) {
        tempN >>= 1;
        R++;
    }

    // Total time = (R * A) + ((R - 1) * B)
    long long total_time = (R * A) + ((R - 1) * B);
    cout << total_time << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}
```