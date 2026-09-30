# [Determine the Winner (WINNERR)](https://www.codechef.com/problems/WINNERR)

- **Difficulty Rating**: 626
- **Solved in**: 1 attempt(s)

## Problem Summary
Two participants, P and Q, solve two problems each (A and B). The time taken for each problem is given. The "penalty" for a participant is defined as the maximum time they took to solve either of their two problems. We need to determine who has the smaller penalty, or if there is a tie.

## Intuition & Mathematical Observation
The problem states that a participant must solve both problems. Since the penalty is determined by the problem that took the longest time to complete, we calculate the penalty for each participant as follows:
- **Penalty for P**: $P_{penalty} = \max(P_A, P_B)$
- **Penalty for Q**: $Q_{penalty} = \max(Q_A, Q_B)$

By comparing these two values, we can determine the winner:
1. If $P_{penalty} < Q_{penalty}$, participant **P** wins.
2. If $Q_{penalty} < P_{penalty}$, participant **Q** wins.
3. If $P_{penalty} == Q_{penalty}$, it is a **TIE**.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we only perform a constant number of comparisons and arithmetic operations.
- **Space Complexity**: $O(1)$, as we only use a few integer variables to store the input and calculated penalties.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The time penalty for a participant is defined as the maximum of the time 
 * taken to solve problem A and problem B.
 * 
 * Constraints: 1 <= P_A, P_B, Q_A, Q_B <= 100.
 * Time complexity: O(1) per test case.
 * Space complexity: O(1).
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        int pa, pb, qa, qb;
        cin >> pa >> pb >> qa >> qb;
        
        // Calculate the time penalty for each participant
        int p_penalty = max(pa, pb);
        int q_penalty = max(qa, qb);
        
        // Compare penalties and output the result
        if (p_penalty < q_penalty) {
            cout << "P" << "\n";
        } else if (q_penalty < p_penalty) {
            cout << "Q" << "\n";
        } else {
            cout << "TIE" << "\n";
        }
    }
    
    return 0;
}
```