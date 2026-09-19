# [Dominant Army (DOMINANT)](https://www.codechef.com/problems/DOMINANT)

- **Difficulty Rating**: 488
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given the sizes of three different armies: $N_A$, $N_B$, and $N_C$. An army is considered "dominant" if its size is strictly greater than the sum of the sizes of the other two armies. We need to determine if any of the three armies is dominant.

## Intuition & Mathematical Observation
To determine if an army is dominant, we simply need to check the condition for each army individually:
1. Army A is dominant if: $N_A > N_B + N_C$
2. Army B is dominant if: $N_B > N_A + N_C$
3. Army C is dominant if: $N_C > N_A + N_B$

If any one of these three conditions evaluates to `true`, the output should be `YES`. If none of them are true, the output should be `NO`. Since the constraints are small, standard integer comparison is sufficient.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we are performing a constant number of arithmetic operations and comparisons. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the army sizes.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Dominant Army
 * Logic:
 * An army is dominant if its size is strictly greater than the sum of the other two.
 * We check three conditions:
 * 1. NA > NB + NC
 * 2. NB > NA + NC
 * 3. NC > NA + NB
 * If any of these are true, output YES, else NO.
 */

void solve() {
    long long NA, NB, NC;
    if (!(cin >> NA >> NB >> NC)) return;

    // Check if any army is strictly greater than the sum of the other two
    if (NA > (NB + NC) || NB > (NA + NC) || NC > (NA + NB)) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
}

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}
```