# [Advitiya (ADVITIYA1)](https://www.codechef.com/problems/ADVITIYA1)

- **Difficulty Rating**: 243
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to determine if a given integer $N$ (representing a date in February) corresponds to the days of the "Advitiya" fest. The fest is held on the 16th, 17th, and 18th of February. If the input $N$ is 16, 17, or 18, we must print "ADVITIYA"; otherwise, we print "WAITING FOR ADVITIYA".

## Intuition & Mathematical Observation
The problem is a straightforward conditional check. Since the range of valid dates is small and contiguous ($16 \le N \le 18$), we can use a simple comparison operator to verify if the input falls within this inclusive range.

- If $16 \le N \le 18$, the condition is true.
- For any other value of $N$ (given $1 \le N \le 18$), the condition is false.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we only perform a constant number of comparisons.
- **Space Complexity**: $O(1)$, as we only store a single integer variable.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The fest Advitiya is held on the 16th, 17th, and 18th of February.
 * Given an input N (1 <= N <= 18), we need to check if N is 16, 17, or 18.
 * If N is in {16, 17, 18}, output "ADVITIYA".
 * Otherwise, output "WAITING FOR ADVITIYA".
 * 
 * Time Complexity: O(1) per test case.
 * Space Complexity: O(1).
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (!(cin >> N)) return 0;

    // Check if the date falls within the range [16, 18]
    if (N >= 16 && N <= 18) {
        cout << "ADVITIYA" << "\n";
    } else {
        cout << "WAITING FOR ADVITIYA" << "\n";
    }

    return 0;
}
```