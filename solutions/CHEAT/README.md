# [Dracula Eats (CHEAT)](https://www.codechef.com/problems/CHEAT)

- **Difficulty Rating**: 763
- **Solved in**: 1 attempt(s)

## Problem Summary
Dracula eats a meal every Tuesday. Given that the current day is Monday (Day 1), we need to determine how many Tuesdays occur within a total of $N$ days.

## Intuition & Mathematical Observation
- The days are numbered starting from Monday (Day 1).
- The first Tuesday occurs on **Day 2**.
- Since there are 7 days in a week, the subsequent Tuesdays occur on days: $2 + 7, 2 + 14, 2 + 21, \dots$
- In general, the $k$-th Tuesday occurs on day $2 + (k-1) \times 7$.
- To find the total number of Tuesdays in $N$ days, we need to find the largest integer $k$ such that $2 + (k-1) \times 7 \leq N$.
- Rearranging the inequality:
  $$(k-1) \times 7 \leq N - 2$$
  $$k-1 \leq \frac{N - 2}{7}$$
  $$k \leq \frac{N - 2}{7} + 1$$
- Using integer division in C++, `(n - 2) / 7 + 1` correctly calculates the number of Tuesdays for any $N \geq 2$. If $N < 2$, the result is 0.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the calculation involves only basic arithmetic operations. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few integer variables regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Today is Monday (Day 1).
 * Tuesday is Day 2.
 * The sequence of Tuesdays occurs on days: 2, 9, 16, 23, ...
 * This is an arithmetic progression where the n-th Tuesday is at day: 2 + (n-1)*7.
 * We want to find how many Tuesdays occur in N days.
 * If N < 2, the answer is 0.
 * If N >= 2, the number of Tuesdays is floor((N - 2) / 7) + 1.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n;
        cin >> n;
        
        // If N < 2, Dracula gets 0 meals.
        // If N >= 2, the number of Tuesdays is (N - 2) / 7 + 1.
        if (n < 2) {
            cout << 0 << "\n";
        } else {
            cout << (n - 2) / 7 + 1 << "\n";
        }
    }

    return 0;
}
```