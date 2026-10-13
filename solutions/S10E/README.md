# [Phone Prices (S10E)](https://www.codechef.com/problems/S10E)

- **Difficulty Rating**: 1269
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given the daily prices of a phone over $N$ consecutive days. A day is considered "good" if the price on that day is strictly lower than the prices of the previous 5 days (or all available previous days if fewer than 5 exist). We need to count the total number of "good" days in the given period.

## Intuition & Mathematical Observation
For each day $i$ (where $0 \le i < N$), we need to verify if $P[i] < P[j]$ for all $j$ in the range $[\max(0, i-5), i-1]$. 

- If $i=0$, there are no previous days, so the condition is vacuously true (the first day is always a "good" day).
- For any other day, we iterate backwards up to 5 steps. If we find any price $P[j]$ that is less than or equal to $P[i]$, the current day $i$ cannot be a "good" day.
- Given the small constraints ($N \le 100$), a nested loop approach is highly efficient and easy to implement.

## Complexity Analysis
- **Time Complexity**: $O(T \times N \times K)$, where $T$ is the number of test cases, $N$ is the number of days, and $K=5$ is the look-back window. Since $K$ is a constant, this simplifies to **$O(T \times N)$**.
- **Space Complexity**: **$O(N)$** to store the prices of the $N$ days.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * For each day i (0 to N-1), the price P[i] is "good" if P[i] < P[j] for all 
 * j in {i-5, i-4, i-3, i-2, i-1} such that j >= 0.
 * 
 * Constraints:
 * T <= 100, N <= 100.
 * Since N is small, an O(N * 5) approach per test case is perfectly efficient.
 */

void solve() {
    int N;
    cin >> N;
    vector<int> P(N);
    for (int i = 0; i < N; ++i) {
        cin >> P[i];
    }

    int good_days = 0;

    for (int i = 0; i < N; ++i) {
        bool is_good = true;
        // Check the previous 5 days
        // The range of previous days is [max(0, i-5), i-1]
        int start = max(0, i - 5);
        for (int j = start; j < i; ++j) {
            if (P[i] >= P[j]) {
                is_good = false;
                break;
            }
        }
        
        if (is_good) {
            good_days++;
        }
    }

    cout << good_days << "\n";
}

int main() {
    // Fast I/O setup
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