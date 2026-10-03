# [Episodes (EPISODES)](https://www.codechef.com/problems/EPISODES)

- **Difficulty Rating**: 498
- **Solved in**: 1 attempt(s)

## Problem Summary
The task is to calculate the total duration of a series of episodes. Given $N$ episodes, each lasting $K$ minutes, we need to convert the total duration into hours and remaining minutes. Specifically, we need to output the total hours and the remaining minutes after accounting for those hours.

## Intuition & Mathematical Observation
The problem is a straightforward application of division and modulo arithmetic:
1. **Calculate Total Time**: The total time in minutes is simply the product of the number of episodes ($N$) and the duration of each episode ($K$).
   $$\text{Total Minutes} = N \times K$$
2. **Convert to Hours**: Since there are 60 minutes in an hour, the number of full hours is the integer division of the total minutes by 60.
   $$\text{Hours} = \text{Total Minutes} / 60$$
3. **Calculate Remaining Minutes**: The remaining minutes are the remainder when the total minutes are divided by 60.
   $$\text{Minutes} = \text{Total Minutes} \% 60$$

Given the constraints ($N \le 30, K < 60$), the maximum value is $1770$, which fits well within standard integer types.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a constant number of arithmetic operations, resulting in $O(1)$ per test case.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the calculated results.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Total time in minutes = N * K
 * We need to convert this total time into Hours (H) and Minutes (M).
 * H = Total_Minutes / 60
 * M = Total_Minutes % 60
 * 
 * Constraints:
 * N <= 30, K < 60
 * Max total minutes = 30 * 59 = 1770
 * This fits comfortably within a standard integer.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long n, k;
        if (!(cin >> n >> k)) break;
        
        long long total_minutes = n * k;
        
        long long h = total_minutes / 60;
        long long m = total_minutes % 60;
        
        cout << h << " " << m << "\n";
    }
    
    return 0;
}
```