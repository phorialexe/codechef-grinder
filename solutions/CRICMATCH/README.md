# [Cricket Match (CRICMATCH)](https://www.codechef.com/problems/CRICMATCH)

- **Difficulty Rating**: 505
- **Solved in**: 1 attempt(s)

## Problem Summary
In a cricket match, a team needs to score $N$ runs to win. They have $M$ overs remaining. Given that each over consists of 6 balls and the maximum number of runs that can be scored off a single ball is 6, determine if it is mathematically possible for the team to score at least $N$ runs within the remaining $M$ overs.

## Intuition & Mathematical Observation
To determine if the target $N$ is achievable, we need to calculate the maximum possible runs the team can score in the remaining $M$ overs:
1. Each over contains 6 balls.
2. The maximum runs per ball is 6.
3. Therefore, the maximum runs per over is $6 \times 6 = 36$.
4. For $M$ overs, the total maximum runs possible is $M \times 36$.

If the required runs $N$ are less than or equal to this maximum capacity ($N \le M \times 36$), the team can potentially win. Otherwise, it is impossible.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a constant number of arithmetic operations.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result, regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Each over consists of 6 balls.
 * Maximum runs per ball is 6.
 * Therefore, maximum runs per over = 6 * 6 = 36.
 * Total maximum runs possible in M overs = M * 36.
 * 
 * Chef's team can win if the required runs N <= (M * 36).
 * 
 * Constraints:
 * N <= 1000, M <= 100.
 * M * 36 = 3600, which fits comfortably in a standard integer.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long n, m;
        cin >> n >> m;
        
        // Calculate maximum possible runs in M overs
        long long max_runs = m * 6 * 6;
        
        // Check if required runs are achievable
        if (n <= max_runs) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
    
    return 0;
}
```