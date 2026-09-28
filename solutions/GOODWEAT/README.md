# [Good Weather (GOODWEAT)](https://www.codechef.com/problems/GOODWEAT)

- **Difficulty Rating**: 835
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given the weather status for 7 consecutive days, represented as an array of 7 integers where `1` denotes a sunny day and `0` denotes a rainy day. A week is classified as "Good" if the number of sunny days is strictly greater than the number of rainy days. We need to determine if the given week is "Good" or not.

## Intuition & Mathematical Observation
Since the total number of days is fixed at 7, we can derive a simple condition:
1. Let $S$ be the number of sunny days and $R$ be the number of rainy days.
2. We know that $S + R = 7$, which implies $R = 7 - S$.
3. The condition for a "Good" week is $S > R$.
4. Substituting $R$:
   $S > 7 - S$
   $2S > 7$
   $S > 3.5$

Since $S$ must be an integer, the condition $S > 3.5$ is equivalent to **$S \ge 4$**. Therefore, we simply need to count the number of `1`s in the input and check if the count is 4 or greater.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case. Since the input size is fixed at 7 days regardless of the test case, the loop runs a constant number of times. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$. We only use a few integer variables to store the count and the current day input, requiring constant extra space.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: GOODWEAT
 * Logic:
 * We are given 7 integers representing days (1 for sunny, 0 for rainy).
 * A week is "Good" if the count of 1s > count of 0s.
 * Since there are 7 days total, count of 0s = 7 - count of 1s.
 * Condition: count of 1s > 7 - count of 1s
 * => 2 * count of 1s > 7
 * => count of 1s >= 4
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        int sunny_days = 0;
        for (int i = 0; i < 7; ++i) {
            int day;
            cin >> day;
            if (day == 1) {
                sunny_days++;
            }
        }
        
        // Total days = 7. Rainy days = 7 - sunny_days.
        // Good if sunny_days > rainy_days
        // sunny_days > 7 - sunny_days
        // 2 * sunny_days > 7
        if (sunny_days > 3) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
    
    return 0;
}
```