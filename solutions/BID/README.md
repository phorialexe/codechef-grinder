# [Pep Bidding (BID)](https://www.codechef.com/problems/BID)

- **Difficulty Rating**: 833
- **Solved in**: 1 attempt(s)

## Problem Summary
In this problem, we are given two teams, Team A and Team P, each consisting of $N$ players. Each player has an attack rating and a defense rating. We need to determine the winner based on the following rules:
1. Team A wins if their total attack power is strictly greater than Team P's total attack power **AND** their total defense power is strictly greater than Team P's total defense power.
2. Team P wins if their total attack power is strictly greater than Team A's total attack power **AND** their total defense power is strictly greater than Team A's total defense power.
3. If neither condition is met, the result is a "DRAW".

## Intuition & Mathematical Observation
The problem asks us to compare the aggregate performance of two teams. Since the total power is simply the sum of individual player ratings, we can calculate these sums independently:
- Let $Att_A$ and $Def_A$ be the sum of attack and defense ratings for Team A.
- Let $Att_P$ and $Def_P$ be the sum of attack and defense ratings for Team P.

The constraints state $N \le 2000$ and individual ratings $\le 1000$. The maximum possible sum is $2000 \times 1000 = 2,000,000$, which fits comfortably within a standard 32-bit integer. However, using `long long` is a good practice to prevent overflow in similar problems with larger constraints.

The logic follows directly from the problem statement:
- If $(Att_A > Att_P)$ and $(Def_A > Def_P)$, output `A`.
- Else if $(Att_P > Att_A)$ and $(Def_P > Def_A)$, output `P`.
- Otherwise, output `DRAW`.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case. We iterate through the input arrays exactly once to calculate the sums. Given $T$ test cases, the total time complexity is $O(\sum N)$.
- **Space Complexity**: $O(1)$. We only store the running totals for the four categories (Attack/Defense for both teams), regardless of the size of $N$.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Pep Bidding
 * Approach:
 * 1. Calculate the total attack power and total defense power for both Team A and Team P.
 * 2. Compare the sums based on the problem's winning conditions.
 * 3. Time Complexity: O(N) per test case.
 * 4. Space Complexity: O(1).
 */

void solve() {
    int N;
    cin >> N;

    long long attA = 0, defA = 0, attP = 0, defP = 0;
    long long val;

    // Read Team A stats
    for (int i = 0; i < N; ++i) { cin >> val; attA += val; }
    for (int i = 0; i < N; ++i) { cin >> val; defA += val; }
    
    // Read Team P stats
    for (int i = 0; i < N; ++i) { cin >> val; attP += val; }
    for (int i = 0; i < N; ++i) { cin >> val; defP += val; }

    // Determine winner
    bool aWins = (attA > attP) && (defA > defP);
    bool pWins = (attP > attA) && (defP > defA);

    if (aWins) {
        cout << "A" << "\n";
    } else if (pWins) {
        cout << "P" << "\n";
    } else {
        cout << "DRAW" << "\n";
    }
}

int main() {
    // Fast I/O setup
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