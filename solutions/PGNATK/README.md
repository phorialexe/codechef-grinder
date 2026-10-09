# [Pigeon Attack (PGNATK)](https://www.codechef.com/problems/PGNATK)

- **Difficulty Rating**: 620
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef needs to complete $N$ minutes of work. However, at every $K$-th minute (i.e., $K, 2K, 3K, \dots$), a pigeon attacks, preventing Chef from working during that specific minute. We need to find the total elapsed time $T$ required for Chef to complete exactly $N$ minutes of work.

## Intuition & Mathematical Observation
The problem asks for the smallest $T$ such that the number of non-multiples of $K$ in the range $[1, T]$ equals $N$.

1. **Work Logic**: In any given minute $m$, Chef works if $m \pmod K \neq 0$. If $m \pmod K = 0$, the minute is "lost" to a pigeon attack.
2. **Simulation**: Since the constraints for $N$ and $K$ are small (up to 100), we can simulate the process minute-by-minute. We maintain a counter for `work_done` and increment the `current_minute` until `work_done` reaches $N$.
3. **Mathematical Insight (Optional)**: The number of work minutes in $T$ total minutes is given by $f(T) = T - \lfloor T/K \rfloor$. While one could solve this using binary search or algebraic manipulation, the simulation approach is perfectly efficient given the constraints.

## Complexity Analysis
- **Time Complexity**: $O(N)$, as we increment the minute counter until we reach $N$ work minutes. In the worst case, $T$ is slightly larger than $N$, making the loop run $O(N)$ times per test case.
- **Space Complexity**: $O(1)$, as we only use a few integer variables to track the state.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef needs to complete N minutes of work.
 * Pigeons arrive at every K-th minute (K, 2K, 3K, ...).
 * We need to find the total time T such that the number of minutes 
 * in the range [1, T] that are NOT multiples of K is exactly N.
 */

void solve() {
    int N, K;
    cin >> N >> K;
    
    int work_done = 0;
    int current_minute = 0;
    
    // Simulate minute by minute until N minutes of work are completed
    while (work_done < N) {
        current_minute++;
        // If the current minute is not a multiple of K, Chef works
        if (current_minute % K != 0) {
            work_done++;
        }
    }
    
    cout << current_minute << "\n";
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