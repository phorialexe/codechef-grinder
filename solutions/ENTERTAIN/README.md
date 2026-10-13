# [Entertainments (ENTERTAIN)](https://www.codechef.com/problems/ENTERTAIN)

- **Difficulty Rating**: 200
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef wants to choose between two entertainment options:
1. Buying a single television for a fixed cost of **1000**.
2. Buying $N$ toys, where each toy costs **200**.

The goal is to determine the minimum cost Chef has to pay to be entertained.

## Intuition & Mathematical Observation
The problem asks us to compare two values and select the smaller one:
*   **Cost of TV**: $1000$
*   **Cost of Toys**: $N \times 200$

By calculating both values, we can simply use the `min()` function to find the cheaper option. Since $1 \le N \le 10$, the maximum cost for toys is $10 \times 200 = 2000$, which fits easily within standard integer types.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we are performing a constant number of arithmetic operations and a comparison.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the calculated costs.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef has two options:
 * 1. Buy a single television: Cost = 1000
 * 2. Buy N toys: Cost = N * 200
 * 
 * We need to find the minimum of these two values: min(1000, N * 200).
 * Given constraints: 1 <= N <= 10.
 * 
 * Time Complexity: O(1) per test case.
 * Space Complexity: O(1).
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    // Read the input N
    if (cin >> N) {
        long long cost_tv = 1000;
        long long cost_toys = (long long)N * 200;
        
        // Output the minimum of the two costs
        cout << min(cost_tv, cost_toys) << "\n";
    }

    return 0;
}
```