# [The Preparations (SUPCHEF)](https://www.codechef.com/problems/SUPCHEF)

- **Difficulty Rating**: 823
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef has $M$ minutes remaining until his exam starts. He wants to watch a TV series consisting of $N$ episodes, where each episode lasts $K$ minutes. We need to determine if Chef can finish watching all $N$ episodes **strictly before** the exam begins.

## Intuition & Mathematical Observation
To determine if Chef can finish the series in time, we calculate the total duration required to watch all episodes:
$$\text{Total Time} = N \times K$$

The problem states that Chef must finish **strictly before** the exam starts. Therefore, the condition for success is:
$$\text{Total Time} < M$$

If $N \times K < M$, Chef has enough time, and the answer is `YES`. Otherwise, the answer is `NO`. 

**Note on Data Types:** While the constraints $N, K \le 10^4$ result in a product of at most $10^8$ (which fits in a 32-bit integer), using `long long` is a best practice in competitive programming to prevent potential overflow issues if constraints were slightly larger.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a constant number of arithmetic operations and comparisons, resulting in $O(1)$ per test case.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input values and the result, regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef has M minutes until the exam.
 * Season-1 has N episodes, each of duration K minutes.
 * Total time required to watch all episodes = N * K.
 * The condition is to finish "strictly before" the exam starts.
 * This means: (Total time required) < (Time until exam)
 * i.e., (N * K) < M.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long m, n, k;
        cin >> m >> n >> k;
        
        // Calculate total time required
        long long total_time = n * k;
        
        // Check if total time is strictly less than M
        if (total_time < m) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
    
    return 0;
}
```