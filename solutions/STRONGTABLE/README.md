# [Table Strength (STRONGTABLE)](https://www.codechef.com/problems/STRONGTABLE)

- **Difficulty Rating**: 1211
- **Solved in**: 1 attempt(s)

## Problem Summary
You are given $N$ table legs, each with a specific strength $S_i$. If you choose a subset of $k$ legs to support a table of total weight $W$, the weight is distributed equally among the chosen legs, meaning each leg bears a weight of $W/k$. For the table to remain stable, every leg in the chosen subset must have a strength $S_i \ge W/k$. Your goal is to find the maximum possible weight $W$ the table can support.

## Intuition & Mathematical Observation
To maximize the weight $W$ for a chosen subset of legs, we must consider the constraint $W \le k \times S_{min}$, where $S_{min}$ is the strength of the weakest leg in the chosen subset.

1. **Sorting**: If we sort the strengths of the legs in non-decreasing order ($S_1 \le S_2 \le \dots \le S_N$), and we decide that $S_i$ will be the minimum strength in our subset, then all legs from index $i$ to $N-1$ (a total of $N-i$ legs) satisfy the condition $S_j \ge S_i$.
2. **Optimization**: By including all legs with strength $\ge S_i$, we maximize the number of legs ($k = N-i$) for that specific minimum strength.
3. **Calculation**: The maximum weight for a fixed $S_i$ is simply $S_i \times (N - i)$. By iterating through all possible values of $i$ from $0$ to $N-1$ and calculating this product, we can find the global maximum weight.

## Complexity Analysis
- **Time Complexity**: $O(N \log N)$ due to the sorting step. The subsequent linear scan takes $O(N)$, making the overall complexity dominated by the sort.
- **Space Complexity**: $O(N)$ to store the strengths of the $N$ legs.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * If we sort the strengths in non-decreasing order, for any leg i, 
 * if we treat it as the minimum strength leg in our subset, 
 * we can include all legs from i to N-1.
 * The number of such legs is (N - i).
 * The maximum weight supported is then w[i] * (N - i).
 */

void solve() {
    int n;
    if (!(cin >> n)) return;
    vector<long long> w(n);
    for (int i = 0; i < n; ++i) {
        cin >> w[i];
    }
    
    // Sort the strengths to easily count how many legs have strength >= w[i]
    sort(w.begin(), w.end());
    
    long long max_weight = 0;
    for (int i = 0; i < n; ++i) {
        // Number of legs with strength >= w[i] is (n - i)
        long long current_weight = w[i] * (n - i);
        if (current_weight > max_weight) {
            max_weight = current_weight;
        }
    }
    
    cout << max_weight << "\n";
}

int main() {
    // Fast I/O setup
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