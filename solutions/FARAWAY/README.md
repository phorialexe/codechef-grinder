# [Far Away (FARAWAY)](https://www.codechef.com/problems/FARAWAY)

- **Difficulty Rating**: 1090
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an array $A$ of size $N$ and an integer $M$, we need to construct an array $B$ of size $N$ such that each element $B_i$ satisfies $1 \le B_i \le M$. The goal is to maximize the sum of absolute differences: $\sum_{i=1}^{N} |A_i - B_i|$.

## Intuition & Mathematical Observation
To maximize the sum $\sum |A_i - B_i|$, we must maximize each individual term $|A_i - B_i|$ independently. 

For a fixed $A_i$ and a range $[1, M]$, the function $f(x) = |A_i - x|$ is a convex function. The maximum value of a convex function over a closed interval $[L, R]$ always occurs at one of the endpoints. Therefore, for each $A_i$, the optimal choice for $B_i$ is either $1$ or $M$.

- If we choose $B_i = 1$, the distance is $|A_i - 1| = A_i - 1$.
- If we choose $B_i = M$, the distance is $|A_i - M| = M - A_i$.

Thus, for each $A_i$, we simply calculate $\max(A_i - 1, M - A_i)$ and add it to our total sum. Since $M$ can be as large as $10^9$ and $N$ up to $2 \times 10^5$, the total sum can exceed the capacity of a 32-bit integer, so we use `long long` to prevent overflow.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, as we iterate through the array $A$ exactly once.
- **Space Complexity**: $O(1)$, as we only store a few variables and calculate the sum on the fly without needing to store the entire array $B$.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We want to maximize the sum of |A_i - B_i| where 1 <= B_i <= M.
 * For each element A_i, the value |A_i - B_i| is maximized when B_i is as far 
 * from A_i as possible within the range [1, M].
 * The two extreme points in the range [1, M] are 1 and M.
 * Therefore, for each A_i, we should choose B_i = 1 or B_i = M.
 * The maximum distance for a single element A_i is max(|A_i - 1|, |A_i - M|).
 * Since |A_i - 1| = A_i - 1 and |A_i - M| = M - A_i,
 * the maximum distance for A_i is max(A_i - 1, M - A_i).
 */

void solve() {
    int N;
    long long M;
    if (!(cin >> N >> M)) return;
    
    long long total_distance = 0;
    for (int i = 0; i < N; ++i) {
        long long A_i;
        cin >> A_i;
        
        // Calculate distance if B_i = 1: |A_i - 1| = A_i - 1
        // Calculate distance if B_i = M: |A_i - M| = M - A_i
        long long dist1 = A_i - 1;
        long long dist2 = M - A_i;
        
        total_distance += max(dist1, dist2);
    }
    
    cout << total_distance << "\n";
}

int main() {
    // Fast I/O
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