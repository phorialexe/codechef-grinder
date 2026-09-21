# [Chef and Races (CHEFRACES)](https://www.codechef.com/problems/CHEFRACES)

- **Difficulty Rating**: 745
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef participates in two specific races, denoted by $X$ and $Y$. His rival also participates in two races, $A$ and $B$. Chef wins a gold medal in a race if the rival is not participating in that same race. We need to determine the total number of gold medals Chef wins.

## Intuition & Mathematical Observation
The problem asks us to check how many of Chef's races ($X$ and $Y$) are "unique" compared to the rival's races ($A$ and $B$).

1. Start by assuming Chef wins both races (initial count = 2).
2. Check the first race ($X$): If $X$ is equal to either $A$ or $B$, the rival is present, so Chef does not win this race. Decrement the count.
3. Check the second race ($Y$): If $Y$ is equal to either $A$ or $B$, the rival is present, so Chef does not win this race. Decrement the count.
4. The final value of the count represents the total number of gold medals won.

This approach effectively handles all cases, including when $X$ or $Y$ might be the same race (though the problem implies distinct races for Chef, the logic holds regardless).

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case. Since we perform a constant number of comparisons regardless of the input values, the complexity is constant. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$. We only use a few integer variables to store the inputs and the medal count, requiring no extra data structures.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef participates in two races: X and Y.
 * The rival participates in two races: A and B.
 * Chef can win a race if the rival is not participating in it.
 * We need to count how many of {X, Y} are not in {A, B}.
 */

int main() {
    // Fast I/O setup for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int x, y, a, b;
        cin >> x >> y >> a >> b;

        int gold_medals = 2;

        // Check if Chef's first race is contested by the rival
        if (x == a || x == b) {
            gold_medals--;
        }

        // Check if Chef's second race is contested by the rival
        if (y == a || y == b) {
            gold_medals--;
        }

        cout << gold_medals << "\n";
    }

    return 0;
}
```