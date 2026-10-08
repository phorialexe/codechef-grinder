# [Marathon (MARARUN)](https://www.codechef.com/problems/MARARUN)

- **Difficulty Rating**: 955
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef participates in a marathon where he runs $d$ kilometers every day for $D$ days. Depending on the total distance covered, he receives a specific prize:
- If the total distance is at least 42 km, he gets prize $C$.
- If the total distance is at least 21 km (but less than 42 km), he gets prize $B$.
- If the total distance is at least 10 km (but less than 21 km), he gets prize $A$.
- If the total distance is less than 10 km, he gets 0.

Given $D, d, A, B,$ and $C$, determine the prize Chef receives.

## Intuition & Mathematical Observation
The total distance covered by Chef is simply the product of the number of days ($D$) and the distance covered per day ($d$). 

Let `total_dist = D * d`. We can determine the prize by checking the conditions in descending order of distance requirements:
1. First, check if `total_dist >= 42`. If true, the prize is $C$.
2. If not, check if `total_dist >= 21`. If true, the prize is $B$.
3. If not, check if `total_dist >= 10`. If true, the prize is $A$.
4. If none of the above are true, the prize is $0$.

Since the constraints are small ($D \le 10, d \le 5$), the maximum distance is 50, which fits easily within standard integer types.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we only perform a few arithmetic operations and conditional checks.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef can cover a maximum distance of (D * d) km in D days.
 * The categories are:
 * 10 km (Prize A)
 * 21 km (Prize B)
 * 42 km (Prize C)
 * 
 * We need to find the maximum prize based on the total distance covered:
 * - If total_dist >= 42, prize is C.
 * - Else if total_dist >= 21, prize is B.
 * - Else if total_dist >= 10, prize is A.
 * - Otherwise, prize is 0.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long D, d, A, B, C;
        cin >> D >> d >> A >> B >> C;

        long long total_dist = D * d;
        long long prize = 0;

        if (total_dist >= 42) {
            prize = C;
        } else if (total_dist >= 21) {
            prize = B;
        } else if (total_dist >= 10) {
            prize = A;
        } else {
            prize = 0;
        }

        cout << prize << "\n";
    }

    return 0;
}
```