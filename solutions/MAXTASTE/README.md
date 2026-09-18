# [Maximise the Tastiness (MAXTASTE)](https://www.codechef.com/problems/MAXTASTE)

- **Difficulty Rating**: 627
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef is preparing a dish that requires two ingredients. For the first ingredient, Chef can choose between two options with tastiness values $a$ and $b$. For the second ingredient, Chef can choose between two options with tastiness values $c$ and $d$. The goal is to select one option for the first ingredient and one for the second such that the total tastiness (the sum of the two chosen values) is maximized.

## Intuition & Mathematical Observation
To maximize the sum of two independent choices, we should independently maximize each choice. 
1. For the first ingredient, we have two choices: $a$ or $b$. To maximize the total, we should pick $\max(a, b)$.
2. For the second ingredient, we have two choices: $c$ or $d$. To maximize the total, we should pick $\max(c, d)$.

The maximum total tastiness is simply the sum of these two maximums:
$$\text{Result} = \max(a, b) + \max(c, d)$$

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we are performing a constant number of comparisons and additions.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input values.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef has two choices for the first ingredient: a or b.
 * Chef has two choices for the second ingredient: c or d.
 * The total tastiness is the sum of the chosen first and second ingredients.
 * To maximize the sum, we pick the maximum of {a, b} and add it to the maximum of {c, d}.
 * 
 * Time Complexity: O(1) per test case.
 * Space Complexity: O(1).
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long a, b, c, d;
        cin >> a >> b >> c >> d;

        // The maximum tastiness is max(a, b) + max(c, d)
        long long max_first = max(a, b);
        long long max_second = max(c, d);
        
        cout << (max_first + max_second) << "\n";
    }

    return 0;
}
```