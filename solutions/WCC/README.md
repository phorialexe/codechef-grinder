# [World Chess Championship (WCC)](https://www.codechef.com/problems/WCC)

- **Difficulty Rating**: 935
- **Solved in**: 1 attempt(s)

## Problem Summary
The World Chess Championship consists of 14 games. Each game results in either a win for Carlsen ('C'), a win for Chef ('N'), or a draw ('D'). The scoring system is as follows:
- A win earns 2 points.
- A draw earns 1 point.
- A loss earns 0 points.

Given the total prize pool $X$, we need to calculate Carlsen's total winnings based on the final score:
- If Carlsen's total points > Chef's total points: Carlsen receives $60 \times X$.
- If the scores are tied: Carlsen receives $55 \times X$.
- If Carlsen's total points < Chef's total points: Carlsen receives $40 \times X$.

## Intuition & Mathematical Observation
The problem is a straightforward simulation. Since the total number of games is fixed at 14, we can iterate through the provided string of results and maintain two counters: one for Carlsen's points and one for Chef's points.

- **Scoring Logic**:
    - If the character is 'C', Carlsen gets +2 points.
    - If the character is 'N', Chef gets +2 points.
    - If the character is 'D', both get +1 point.

After processing the string, we simply compare the two point totals and apply the corresponding multiplier to $X$. Using `long long` for the prize calculation is good practice to prevent potential overflow, although $6 \times 10^7$ fits within a standard 32-bit integer.

## Complexity Analysis
- **Time Complexity**: $O(N)$, where $N$ is the number of games (fixed at 14). Since $N$ is constant, this is effectively $O(1)$ per test case.
- **Space Complexity**: $O(1)$, as we only store a few integer variables and the input string of length 14.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * - 14 games total.
 * - Carlsen (C) wins: 2 points.
 * - Chef (N) wins: 0 points for Carlsen.
 * - Draw (D): 1 point for Carlsen.
 * - Total points for Carlsen = (count of 'C' * 2) + (count of 'D' * 1).
 * - Chef's points = (count of 'N' * 2) + (count of 'D' * 1).
 */

void solve() {
    long long X;
    cin >> X;
    string s;
    cin >> s;

    long long carlsen_points = 0;
    long long chef_points = 0;

    for (char c : s) {
        if (c == 'C') {
            carlsen_points += 2;
        } else if (c == 'N') {
            chef_points += 2;
        } else {
            carlsen_points += 1;
            chef_points += 1;
        }
    }

    if (carlsen_points > chef_points) {
        cout << 60 * X << "\n";
    } else if (carlsen_points == chef_points) {
        cout << 55 * X << "\n";
    } else {
        cout << 40 * X << "\n";
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