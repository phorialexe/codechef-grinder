# [Vaccine Distribution (VACCINE2)](https://www.codechef.com/problems/VACCINE2)

- **Difficulty Rating**: 1219
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given $N$ people with varying ages. A person is considered "at risk" if their age is $\ge 80$ or $\le 9$. Otherwise, they are "not at risk." We have a vaccine capacity of $D$ people per day. The constraint is that we cannot vaccinate "at risk" and "not at risk" people on the same day. We need to find the minimum number of days required to vaccinate everyone.

## Intuition & Mathematical Observation
Since we cannot mix the two groups on the same day, the problem effectively splits into two independent sub-problems:
1. Calculate the number of days required to vaccinate all "at risk" people.
2. Calculate the number of days required to vaccinate all "not at risk" people.

For any group of size $S$ and a daily capacity $D$, the number of days required is $\lceil S/D \rceil$. In integer arithmetic, this is calculated as:
$$\text{days} = \frac{S + D - 1}{D}$$

The total time taken is simply the sum of the days required for the "at risk" group and the "not at risk" group.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the number of people. We iterate through the list of ages exactly once to categorize them.
- **Space Complexity**: $O(1)$, as we only store a few integer counters regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have N people with ages a_i.
 * A person is "at risk" if age >= 80 or age <= 9.
 * We can vaccinate at most D people per day.
 * Constraint: We cannot vaccinate both "at risk" and "not at risk" people on the same day.
 * 
 * Strategy:
 * 1. Count the number of "at risk" people (risk_count) and "not at risk" people (safe_count).
 * 2. Since we cannot mix them, we calculate the days required for each group independently.
 * 3. For a group of size S, the number of days required is ceil(S / D).
 *    Using integer arithmetic, this is (S + D - 1) / D.
 * 4. Total days = days_for_risk + days_for_safe.
 */

void solve() {
    int N, D;
    cin >> N >> D;
    
    int risk_count = 0;
    int safe_count = 0;
    
    for (int i = 0; i < N; ++i) {
        int age;
        cin >> age;
        if (age >= 80 || age <= 9) {
            risk_count++;
        } else {
            safe_count++;
        }
    }
    
    // Calculate days for each group using ceiling division
    // ceil(a/b) = (a + b - 1) / b for integers
    int days_risk = (risk_count + D - 1) / D;
    int days_safe = (safe_count + D - 1) / D;
    
    cout << (days_risk + days_safe) << "\n";
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