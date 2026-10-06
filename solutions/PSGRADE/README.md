# [Passing Marks (PSGRADE)](https://www.codechef.com/problems/PSGRADE)

- **Difficulty Rating**: 904
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef takes an exam consisting of three subjects. To pass the exam, Chef must satisfy four conditions:
1. Score at least $A_{min}$ in the first subject.
2. Score at least $B_{min}$ in the second subject.
3. Score at least $C_{min}$ in the third subject.
4. The sum of scores in all three subjects must be at least $T_{min}$.

Given the minimum requirements and Chef's actual scores ($A, B, C$), determine if Chef passes the exam.

## Intuition & Mathematical Observation
The problem is a straightforward implementation of conditional logic. Since the requirements are independent, we can evaluate each condition separately:
- Let $A, B, C$ be the scores obtained.
- Let $A_{min}, B_{min}, C_{min}$ be the minimum passing marks for each subject.
- Let $T_{min}$ be the minimum total marks required.

Chef passes if and only if:
$$(A \ge A_{min}) \land (B \ge B_{min}) \land (C \ge C_{min}) \land ((A + B + C) \ge T_{min})$$

If all these boolean expressions evaluate to `true`, the output is "YES"; otherwise, it is "NO".

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we only perform a constant number of comparisons and additions. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few integer variables to store the input values.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef passes if:
 * 1. A >= A_min
 * 2. B >= B_min
 * 3. C >= C_min
 * 4. (A + B + C) >= T_min
 * 
 * Constraints are small (up to 300), so standard integer types are sufficient.
 * Time complexity per test case: O(1)
 * Total time complexity: O(T)
 */

void solve() {
    int A_min, B_min, C_min, T_min, A, B, C;
    if (!(cin >> A_min >> B_min >> C_min >> T_min >> A >> B >> C)) return;

    // Check individual subject requirements
    bool subject1 = (A >= A_min);
    bool subject2 = (B >= B_min);
    bool subject3 = (C >= C_min);
    
    // Check total score requirement
    bool total = ((A + B + C) >= T_min);

    if (subject1 && subject2 && subject3 && total) {
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
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}
```