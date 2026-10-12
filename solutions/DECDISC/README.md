# [Decoration Discount (DECDISC)](https://www.codechef.com/problems/DECDISC)

- **Difficulty Rating**: 781
- **Solved in**: 1 attempt(s)

## Problem Summary
You are given an array $A$ of $N$ vase prices. You need to select exactly two distinct indices $i$ and $j$ ($i < j$) to purchase two vases. The cost is calculated as follows:
- If the vases are adjacent (i.e., $j = i + 1$), the cost is $A[i] + \lfloor A[j] / 2 \rfloor$.
- If the vases are not adjacent (i.e., $j > i + 1$), the cost is $A[i] + A[j]$.

The goal is to find the minimum possible cost among all valid pairs $(i, j)$.

## Intuition & Mathematical Observation
Since the constraint on $N$ is small ($N \le 100$), we do not need a highly optimized greedy approach. We can perform a brute-force search by iterating through every possible pair of indices $(i, j)$ where $0 \le i < j < N$.

For each pair:
1. Check if the indices are adjacent ($j = i + 1$).
2. If they are, apply the discount: `cost = A[i] + (A[j] / 2)`.
3. If they are not, use the standard sum: `cost = A[i] + A[j]`.
4. Maintain a variable to store the minimum cost encountered during the iteration.

## Complexity Analysis
- **Time Complexity**: $O(N^2)$, where $N$ is the number of vases. Given $N \le 100$, $N^2 = 10,000$, which easily fits within the time limit for multiple test cases.
- **Space Complexity**: $O(N)$ to store the array of prices.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to buy exactly two vases at indices i and j (i != j).
 * If we buy vase i, and then vase i+1, the cost is A[i] + A[i+1]/2.
 * If we buy any other pair (i, j) where j != i+1, the cost is A[i] + A[j].
 * 
 * We iterate through all possible pairs (i, j) with 0 <= i < j < N
 * and track the minimum cost found.
 */

void solve() {
    int N;
    cin >> N;
    vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    long long min_cost = -1;

    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            long long current_cost;
            // Check for adjacency condition
            if (j == i + 1) {
                current_cost = A[i] + (A[j] / 2);
            } else {
                current_cost = A[i] + A[j];
            }

            // Update minimum cost
            if (min_cost == -1 || current_cost < min_cost) {
                min_cost = current_cost;
            }
        }
    }

    cout << min_cost << "\n";
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