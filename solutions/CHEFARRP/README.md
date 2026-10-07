# [Chef and Subarrays (CHEFARRP)](https://www.codechef.com/problems/CHEFARRP)

- **Difficulty Rating**: 1041
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an array $A$ of $N$ integers, we need to find the total number of subarrays (contiguous segments) where the sum of the elements is exactly equal to the product of the elements.

## Intuition & Mathematical Observation
The constraints for this problem are quite small: $N \le 50$. This allows us to explore all possible subarrays of the given array. A subarray is defined by its starting index $i$ and ending index $j$ (where $0 \le i \le j < N$).

1. **Brute Force Approach**: Since there are $O(N^2)$ possible subarrays, we can iterate through every possible starting point $i$ and every possible ending point $j$.
2. **Incremental Calculation**: As we expand the subarray from $j$ to $j+1$, we don't need to recompute the sum and product from scratch. We can maintain a running `current_sum` and `current_prod` for the subarray starting at $i$, updating them as we increment $j$.
3. **Data Types**: Although the problem states the product of all elements is $\le 10^9$, intermediate products might exceed the range of a 32-bit integer. Using `long long` in C++ ensures we avoid overflow issues.

## Complexity Analysis
- **Time Complexity**: $O(N^2)$ per test case. With $N \le 50$, $N^2 = 2500$, which is well within the typical limit of $10^8$ operations per second.
- **Space Complexity**: $O(N)$ to store the input array.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The constraints are N <= 50 and the product of all elements is <= 10^9.
 * Since N is very small (up to 50), an O(N^2) approach is perfectly acceptable.
 * We can iterate over all possible subarrays [i, j] where 0 <= i <= j < N,
 * calculate their sum and product, and check if they are equal.
 * 
 * Given the product constraint (product <= 10^9), we can safely use 'long long'
 * to store the product to avoid overflow during intermediate calculations.
 */

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int count = 0;
    // Iterate over all possible starting positions of subarrays
    for (int i = 0; i < n; ++i) {
        long long current_sum = 0;
        long long current_prod = 1;
        
        // Iterate over all possible ending positions for the subarray starting at i
        for (int j = i; j < n; ++j) {
            current_sum += a[j];
            current_prod *= a[j];
            
            // Check if sum equals product
            if (current_sum == current_prod) {
                count++;
            }
        }
    }
    cout << count << "\n";
}

int main() {
    // Fast I/O setup
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