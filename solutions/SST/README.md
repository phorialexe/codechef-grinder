# [Sasta Shark Tank (SST)](https://www.codechef.com/problems/SST)

- **Difficulty Rating**: 592
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given two investment offers for a company:
1. **Investor 1**: Offers $A$ dollars for 10% of the company.
2. **Investor 2**: Offers $B$ dollars for 20% of the company.

We need to determine which offer results in a higher total valuation of the company. If the valuations are equal, we output "ANY".

## Intuition & Mathematical Observation
To compare the offers, we must calculate the implied total valuation of the company for each investor:

*   **Valuation 1**: If $A$ represents 10% ($0.10$) of the company, the total valuation is:
    $$\text{Valuation}_1 = \frac{A}{0.10} = A \times 10$$
*   **Valuation 2**: If $B$ represents 20% ($0.20$) of the company, the total valuation is:
    $$\text{Valuation}_2 = \frac{B}{0.20} = B \times 5$$

By comparing $(A \times 10)$ and $(B \times 5)$, we can determine which offer is better:
- If $(A \times 10) > (B \times 5)$, the first offer is better.
- If $(B \times 5) > (A \times 10)$, the second offer is better.
- If $(A \times 10) == (B \times 5)$, both offers result in the same valuation.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. Each test case involves simple arithmetic operations performed in $O(1)$ time.
- **Space Complexity**: $O(1)$, as we only use a constant amount of extra space for variables.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Investor 1 offers A for 10% of the company.
 * Valuation 1 = A / 0.10 = A * 10.
 * 
 * Investor 2 offers B for 20% of the company.
 * Valuation 2 = B / 0.20 = B * 5.
 * 
 * We compare (A * 10) and (B * 5).
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long a, b;
        cin >> a >> b;

        long long val1 = a * 10;
        long long val2 = b * 5;

        if (val1 > val2) {
            cout << "FIRST" << "\n";
        } else if (val2 > val1) {
            cout << "SECOND" << "\n";
        } else {
            cout << "ANY" << "\n";
        }
    }

    return 0;
}
```