# [Inside The Stadium (INSTDUM)](https://www.codechef.com/problems/INSTDUM)

- **Difficulty Rating**: 895
- **Solved in**: 1 attempt(s)

## Problem Summary
In a cricket match, the strike rate is calculated as `(Total Runs / Total Balls) * 100`. We are given a sequence of runs scored on each ball. We need to determine how many times during the innings the batter's strike rate was exactly 100.

## Intuition & Mathematical Observation
The condition for the strike rate to be 100 is:
$$\left( \frac{\text{Total Runs}}{\text{Total Balls}} \right) \times 100 = 100$$

By dividing both sides by 100, we simplify the condition to:
$$\frac{\text{Total Runs}}{\text{Total Balls}} = 1$$
$$\text{Total Runs} = \text{Total Balls}$$

Since we are processing the balls one by one, at any ball $i$ (where $i$ is the current ball number), the total number of balls faced is simply $i$. Therefore, we only need to maintain a running sum of the runs scored and check if `current_sum == i` at each step.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the number of balls. We iterate through the input array exactly once. Given the constraint that the sum of $N$ over all test cases is $\le 10^6$, this approach is highly efficient.
- **Space Complexity**: $O(1)$, as we only store a few variables (`current_runs`, `count`, `runs`) regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Strike Rate = (Total Runs / Total Balls) * 100
 * We want Strike Rate == 100.
 * This is equivalent to: (Total Runs / Total Balls) * 100 = 100
 * Dividing both sides by 100: Total Runs / Total Balls = 1
 * Which simplifies to: Total Runs == Total Balls.
 * 
 * We need to maintain a running sum of runs and compare it to the 
 * current ball count (index + 1) at each step.
 */

void solve() {
    int n;
    if (!(cin >> n)) return;
    
    long long current_runs = 0;
    int count = 0;
    
    for (int i = 1; i <= n; ++i) {
        int runs;
        cin >> runs;
        current_runs += runs;
        
        // After i balls, if total runs == i, strike rate is 100
        if (current_runs == (long long)i) {
            count++;
        }
    }
    
    cout << count << "\n";
}

int main() {
    // Fast I/O setup for performance
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