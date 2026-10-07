# [Maximum Score (MXSCWN)](https://www.codechef.com/problems/MXSCWN)

- **Difficulty Rating**: 843
- **Solved in**: 2 attempt(s)

## Problem Summary
You are given two arrays, $A$ and $B$, both of size $N$. You must choose exactly one index $i$ where you take the value $B_i$, and for all other indices $j \neq i$, you take the value $A_j$. The goal is to maximize the total sum of the chosen values.

## Intuition & Mathematical Observation
Let $S$ be the sum of all elements in array $A$. 
If we choose index $k$ to take $B_k$ instead of $A_k$, the total sum becomes:
$$\text{Total} = \left( \sum_{i=0}^{N-1} A_i \right) - A_k + B_k$$
$$\text{Total} = S - (A_k - B_k)$$

To maximize the total sum, we need to minimize the value of $(A_k - B_k)$. 
1. Calculate the total sum of array $A$.
2. Iterate through all indices $i$ from $0$ to $N-1$.
3. Calculate the difference $D_i = A_i - B_i$ for each index.
4. Find the minimum difference $D_{min}$ among all $i$.
5. The maximum possible sum is $S - D_{min}$.

## Complexity Analysis
- **Time Complexity**: $O(N)$, where $N$ is the number of elements in the arrays. We iterate through the arrays once to calculate the sum and once to find the minimum difference.
- **Space Complexity**: $O(N)$ to store the input arrays. (Note: This could be optimized to $O(1)$ space if we process the input on the fly, but $O(N)$ is well within limits).

## Solution Code

```cpp
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

/**
 * Problem: MXSCWN
 * Strategy:
 * 1. Calculate the sum of all A_i.
 * 2. To satisfy the condition "lose at least once", we must pick exactly one index 'k'
 *    where we take B_k instead of A_k.
 * 3. The total coins will be (Sum of all A_i) - A_k + B_k.
 * 4. To maximize this, we need to minimize (A_k - B_k).
 * 5. Iterate through all i, find the minimum (A_i - B_i), and subtract it from the total sum.
 */

void solve() {
    int n;
    if (!(cin >> n)) return;
    
    vector<int> a(n), b(n);
    long long sum_a = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum_a += a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    // Initialize min_diff with the first element's difference
    long long min_diff = (long long)a[0] - b[0];
    for (int i = 1; i < n; ++i) {
        long long diff = (long long)a[i] - b[i];
        if (diff < min_diff) {
            min_diff = diff;
        }
    }

    cout << sum_a - min_diff << "\n";
}

int main() {
    // Fast I/O
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