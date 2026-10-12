# [Joining Date (JOINING)](https://www.codechef.com/problems/JOINING)

- **Difficulty Rating**: 970
- **Solved in**: 1 attempt(s)

## Problem Summary
Candidates are assigned to join on specific days in groups of 5. Specifically, candidate $i$ is assigned to join on day $\lceil i/5 \rceil$. If a candidate $K$ decides not to join, all candidates with an index greater than $K$ shift their position forward by 1 (i.e., candidate $i$ becomes candidate $i-1$). We need to determine how many candidates will have their joining day changed due to this shift.

## Intuition & Mathematical Observation
1. **Original Day**: A candidate $i$ joins on day $\lceil i/5 \rceil$. Using integer division in C++, this is calculated as `(i + 4) / 5`.
2. **New Day**: If candidate $K$ leaves, any candidate $i > K$ shifts to index $i-1$. Their new joining day becomes $\lceil (i-1)/5 \rceil$, calculated as `(i - 1 + 4) / 5` or `(i + 3) / 5`.
3. **The Change**: A candidate's joining day changes if and only if $\lceil i/5 \rceil \neq \lceil (i-1)/5 \rceil$. 
4. **Pattern**: The value of $\lceil x/5 \rceil$ only changes when $x$ transitions from a multiple of 5 to the next integer (e.g., from 5 to 6, 10 to 11). Specifically, the day changes when $i$ is of the form $5m + 1$.
5. **Optimization**: While the provided solution iterates from $K+1$ to $N$ to check the condition, this can also be solved in $O(1)$ by calculating the number of multiples of 5 in the range $[K, N-1]$. However, given the constraints, the $O(N-K)$ approach is well within the time limits.

## Complexity Analysis
- **Time Complexity**: $O(N - K)$ per test case, where $N$ is the total number of candidates. Given the constraints, this is highly efficient.
- **Space Complexity**: $O(1)$, as we only use a few variables to track the count and indices.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Candidates join in groups of 5.
 * Original day for candidate i: ceil(i / 5.0)
 * 
 * If candidate K leaves, all candidates with index > K shift down by 1.
 * The new joining day for candidate i (where i > K) is ceil((i - 1) / 5.0).
 * 
 * We count how many i in the range [K+1, N] satisfy:
 * (i + 4) / 5 != (i + 3) / 5
 */

void solve() {
    int N, K;
    cin >> N >> K;

    int changed_count = 0;
    // Iterate through all candidates who shift their position
    for (int i = K + 1; i <= N; ++i) {
        int original_day = (i + 4) / 5;
        int new_day = (i + 3) / 5;
        
        // If the day index changes, increment the counter
        if (original_day != new_day) {
            changed_count++;
        }
    }
    
    cout << changed_count << "\n";
}

int main() {
    // Fast I/O for performance
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