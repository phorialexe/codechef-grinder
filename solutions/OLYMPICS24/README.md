# [Olympics 2024 (OLYMPICS24)](https://www.codechef.com/problems/OLYMPICS24)

- **Difficulty Rating**: 283
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef currently has $G$ Gold, $S$ Silver, and $B$ Bronze medals. The goal is to have at least 5 medals of each type. We need to calculate the minimum number of additional medals required to reach this target.

## Intuition & Mathematical Observation
The problem asks for the total number of medals needed to reach a count of 5 for each category. 
- For Gold, the number of medals needed is $5 - G$.
- For Silver, the number of medals needed is $5 - S$.
- For Bronze, the number of medals needed is $5 - B$.

Since the constraints state $1 \le G, S, B \le 5$, the values $(5-G)$, $(5-S)$, and $(5-B)$ will always be non-negative. Therefore, the total number of additional medals required is simply the sum of these differences:
$$\text{Total} = (5 - G) + (5 - S) + (5 - B)$$
This can be simplified algebraically to:
$$\text{Total} = 15 - (G + S + B)$$

## Complexity Analysis
- **Time Complexity**: $O(1)$ because the solution involves a constant number of arithmetic operations regardless of the input values.
- **Space Complexity**: $O(1)$ as we only use a few integer variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef wants 5 medals of each type (Gold, Silver, Bronze).
 * Given current medals G, S, B:
 * Additional Gold needed = 5 - G
 * Additional Silver needed = 5 - S
 * Additional Bronze needed = 5 - B
 * Total additional medals = (5 - G) + (5 - S) + (5 - B)
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int G, S, B;
    if (cin >> G >> S >> B) {
        // Calculate the total medals needed to reach 5 in each category
        int total_needed = (5 - G) + (5 - S) + (5 - B);
        cout << total_needed << "\n";
    }

    return 0;
}
```