# [Moderate Temperatures (MODTEMP)](https://www.codechef.com/problems/MODTEMP)

- **Difficulty Rating**: 597
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an array of $N$ temperatures, we need to count how many days have a temperature that is **strictly greater** than the minimum temperature and **strictly less** than the maximum temperature of the entire set.

## Intuition & Mathematical Observation
To solve this problem, we need to identify the range of "moderate" temperatures. 
1. **Identify Bounds**: First, traverse the array to find the global minimum (`min_val`) and the global maximum (`max_val`).
2. **Edge Case**: If `min_val` is equal to `max_val`, it implies all temperatures in the array are identical. In this case, no temperature can be strictly between the minimum and maximum, so the answer is $0$.
3. **Counting**: If `min_val < max_val`, we iterate through the array once more. For every element $A[i]$, we check if the condition `min_val < A[i] < max_val` holds true. If it does, we increment our counter.

This approach ensures we only count values that are neither the absolute minimum nor the absolute maximum.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the number of days. We perform two linear passes over the array (one to find the bounds and one to count the moderate temperatures).
- **Space Complexity**: $O(N)$ to store the input array. (Note: This could be optimized to $O(1)$ if we process the input in a single pass using a more complex logic, but $O(N)$ is well within the limits for this problem).

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given N temperatures. We need to find the number of days where the 
 * temperature is strictly greater than the minimum and strictly less than 
 * the maximum temperature of the set.
 */

void solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    
    int min_val = 101; // Constraints say A_i <= 100
    int max_val = 0;   // Constraints say A_i >= 1
    
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        if (A[i] < min_val) min_val = A[i];
        if (A[i] > max_val) max_val = A[i];
    }
    
    // If all elements are the same, there are no elements strictly between min and max.
    if (min_val == max_val) {
        cout << 0 << "\n";
        return;
    }
    
    int count = 0;
    for (int i = 0; i < N; ++i) {
        if (A[i] > min_val && A[i] < max_val) {
            count++;
        }
    }
    
    cout << count << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
```