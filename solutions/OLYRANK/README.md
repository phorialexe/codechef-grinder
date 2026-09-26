# [Olympics Ranking (OLYRANK)](https://www.codechef.com/problems/OLYRANK)

- **Difficulty Rating**: 893
- **Solved in**: 1 attempt(s)

## Problem Summary
The task is to determine which of two countries ranks higher in the Olympics based on their total medal count. We are given the number of Gold, Silver, and Bronze medals for two countries. The country with the higher sum of medals (Gold + Silver + Bronze) is declared the winner. The problem guarantees that the total number of medals for the two countries will never be equal.

## Intuition & Mathematical Observation
The ranking criteria is straightforward:
1. Calculate the total medals for Country 1: $Total_1 = G_1 + S_1 + B_1$.
2. Calculate the total medals for Country 2: $Total_2 = G_2 + S_2 + B_2$.
3. Compare $Total_1$ and $Total_2$. If $Total_1 > Total_2$, Country 1 ranks higher; otherwise, Country 2 ranks higher.

Since the constraints are small (medals $\le 30$ per category), the total sum will not exceed 90, which easily fits within a standard 32-bit integer.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we only perform a constant number of additions and a single comparison. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few integer variables to store the medal counts and totals regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Olympics Ranking
 * The problem asks us to compare the total number of medals (Gold + Silver + Bronze)
 * for two countries and output which country has a higher total.
 * 
 * Constraints:
 * T <= 1000
 * Medals <= 30
 * Total medals per country <= 90, which fits comfortably in a standard 'int'.
 * Time complexity per test case: O(1)
 * Space complexity per test case: O(1)
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;

    while (t--) {
        int g1, s1, b1, g2, s2, b2;
        cin >> g1 >> s1 >> b1 >> g2 >> s2 >> b2;

        // Calculate total medals for both countries
        int total1 = g1 + s1 + b1;
        int total2 = g2 + s2 + b2;

        // Compare totals and output the winner
        // The problem guarantees no ties.
        if (total1 > total2) {
            cout << "1" << "\n";
        } else {
            cout << "2" << "\n";
        }
    }

    return 0;
}
```