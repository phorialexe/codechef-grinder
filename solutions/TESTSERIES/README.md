# [Test Match Series (TESTSERIES)](https://www.codechef.com/problems/TESTSERIES)

- **Difficulty Rating**: -1
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to determine the outcome of a 5-match Test series between India and England. We are given the results of each of the 5 matches as integers:
- `0`: The match ended in a draw.
- `1`: India won the match.
- `2`: England won the match.

We need to compare the total number of wins for both teams and output "INDIA" if India has more wins, "ENGLAND" if England has more wins, or "DRAW" if the number of wins is equal.

## Intuition & Mathematical Observation
Since the series consists of exactly 5 matches, we can maintain two counters: `india_wins` and `england_wins`. 
1. Iterate through the 5 inputs.
2. If the input is `1`, increment `india_wins`.
3. If the input is `2`, increment `england_wins`.
4. Ignore `0` as it does not contribute to the win count for either team.
5. After processing all 5 inputs, compare the two counters to determine the series winner.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a constant number of operations (exactly 5 iterations), making the per-test case complexity $O(1)$.
- **Space Complexity**: $O(1)$, as we only use a few integer variables to store the counts regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Test Match Series
 * Logic:
 * We are given 5 match results.
 * 0: Draw
 * 1: India wins
 * 2: England wins
 * 
 * We need to count the number of wins for India and England.
 * If india_wins > england_wins, output "INDIA".
 * If england_wins > india_wins, output "ENGLAND".
 * Otherwise, output "DRAW".
 */

void solve() {
    int india_wins = 0;
    int england_wins = 0;
    
    for (int i = 0; i < 5; ++i) {
        int result;
        cin >> result;
        if (result == 1) {
            india_wins++;
        } else if (result == 2) {
            england_wins++;
        }
    }
    
    if (india_wins > england_wins) {
        cout << "INDIA" << "\n";
    } else if (england_wins > india_wins) {
        cout << "ENGLAND" << "\n";
    } else {
        cout << "DRAW" << "\n";
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