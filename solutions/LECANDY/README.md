# [Little Elephant and Candies (LECANDY)](https://www.codechef.com/problems/LECANDY)

- **Difficulty Rating**: 1141
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given $N$ elephants and a total of $C$ candies. Each elephant $i$ has a specific requirement of $A_i$ candies. We need to determine if it is possible to give every elephant their required amount of candies using the total pool of $C$ candies. If the sum of all requirements is less than or equal to $C$, we output "Yes"; otherwise, we output "No".

## Intuition & Mathematical Observation
The problem asks whether the total supply of candies $C$ is sufficient to satisfy the sum of individual demands. 
1. Let $S = \sum_{i=1}^{N} A_i$ be the total number of candies required by all elephants.
2. If $S \le C$, then we have enough candies to satisfy every elephant, so the answer is "Yes".
3. If $S > C$, we do not have enough candies to satisfy everyone, so the answer is "No".

Since the constraints are small ($N \le 100$ and $A_i \le 10000$), the maximum possible sum is $10^6$, which easily fits within a standard integer. However, since $C$ can be as large as $10^9$, using a `long long` for the sum and the comparison is a safe practice to prevent any potential overflow in variations of this problem.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case. We iterate through the list of $N$ elephants exactly once to calculate the sum. Given $T$ test cases, the total time complexity is $O(T \times N)$.
- **Space Complexity**: $O(1)$. We only store the running sum and the current input value, requiring constant extra space regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have N elephants and C total candies.
 * Each elephant i requires at least A[i] candies.
 * To make all elephants happy, we need to provide at least A[i] candies to each elephant i.
 * The total number of candies required is the sum of all A[i] for i from 1 to N.
 * If sum(A[i]) <= C, then it is possible to make all elephants happy.
 * Otherwise, it is not.
 * 
 * Constraints:
 * T <= 1000
 * N <= 100
 * C <= 10^9
 * A[i] <= 10000
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        int n;
        long long c;
        cin >> n >> c;
        
        long long total_needed = 0;
        for (int i = 0; i < n; ++i) {
            int a;
            cin >> a;
            total_needed += a;
        }
        
        if (total_needed <= c) {
            cout << "Yes" << "\n";
        } else {
            cout << "No" << "\n";
        }
    }
    
    return 0;
}
```