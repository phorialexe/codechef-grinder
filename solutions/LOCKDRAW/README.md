# [Chef and Lockout Draws (LOCKDRAW)](https://www.codechef.com/problems/LOCKDRAW)

- **Difficulty Rating**: 982
- **Solved in**: 1 attempt(s)

## Problem Summary
Given three problems with point values $A$, $B$, and $C$, determine if it is possible to distribute these three problems between two players (Chef and his opponent) such that both players receive an equal total number of points. Note that all three problems must be distributed.

## Intuition & Mathematical Observation
To achieve a draw, the total sum of points $S = A + B + C$ must be divisible by 2, and one player must be able to obtain exactly $S/2$ points.

Since there are only three problems, there are only two ways to partition them:
1. One player takes one problem, and the other takes two.
2. (Impossible) One player takes zero, and the other takes three (this would not result in a draw unless the points were zero).

If one player takes one problem (let's say $X$) and the other takes the remaining two ($Y$ and $Z$), for a draw to occur, we must have:
$$X = Y + Z$$
Substituting this into the total sum equation:
$$S = X + Y + Z = (Y + Z) + Y + Z = 2(Y + Z)$$
This confirms that $S$ must be even and one value must be the sum of the other two. By sorting the three values such that $a[0] \le a[1] \le a[2]$, we only need to check if:
$$a[0] + a[1] = a[2]$$

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case. Sorting three elements takes constant time, and the arithmetic check is also constant.
- **Space Complexity**: $O(1)$, as we only store three integers regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have three problems with points A, B, and C.
 * All three problems must be solved.
 * Let the set of points be {A, B, C}.
 * We need to partition these three values into two sets (one for Bob, one for Alice)
 * such that the sum of points in both sets is equal.
 * 
 * Let the total sum be S = A + B + C.
 * For a draw to occur, each player must have S/2 points.
 * This is only possible if S is even and there exists a subset of {A, B, C} 
 * that sums up to S/2.
 * 
 * Alternatively, since there are only 3 numbers, the possible ways to split them are:
 * 1. One player gets one problem, the other gets two.
 *    This means one of the values must equal the sum of the other two.
 *    i.e., A = B + C OR B = A + C OR C = A + B.
 */

void solve() {
    long long a[3];
    cin >> a[0] >> a[1] >> a[2];
    
    // Sort to easily check if the largest equals the sum of the other two
    sort(a, a + 3);
    
    if (a[0] + a[1] == a[2]) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
```