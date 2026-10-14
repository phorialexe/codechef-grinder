# [Blue and Black Pens (BLUEBLACK)](https://www.codechef.com/problems/BLUEBLACK)

- **Difficulty Rating**: -1
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef needs to purchase pens for his collection. He has two options to satisfy his requirements:
1. Buy 3 blue pens.
2. Buy 1 blue pen and 1 black pen.

Given the cost of a single blue pen ($A$) and a single black pen ($B$), determine the minimum cost required to satisfy Chef's needs.

## Intuition & Mathematical Observation
The problem asks us to compare two distinct costs:
* **Option 1:** The cost of 3 blue pens is $3 \times A$.
* **Option 2:** The cost of 1 blue pen and 1 black pen is $A + B$.

Since we want to minimize the expenditure, the answer is simply $\min(3A, A + B)$. Given the constraints $10 \le A, B \le 50$, the values fit comfortably within standard integer types, though `long long` is used for robustness.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution involves only basic arithmetic operations and a comparison.
- **Space Complexity**: $O(1)$, as we only use a constant amount of extra space for variables.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef needs either:
 * 1. 3 blue pens: Cost = 3 * A
 * 2. 1 blue pen and 1 black pen: Cost = A + B
 * 
 * We need to find the minimum of (3 * A) and (A + B).
 * Constraints: 10 <= A, B <= 50.
 */

void solve() {
    long long A, B;
    if (!(cin >> A >> B)) return;

    long long option1 = 3 * A;
    long long option2 = A + B;

    cout << min(option1, option2) << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Standard single test case execution
    int t = 1; 
    while (t--) {
        solve();
    }

    return 0;
}
```