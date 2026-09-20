# [Email Reminders (EMAILREM)](https://www.codechef.com/problems/EMAILREM)

- **Difficulty Rating**: 379
- **Solved in**: 1 attempt(s)

## Problem Summary
The task is to determine the number of people who should receive an email reminder. We are given the total number of participants ($N$) and the number of participants who have opted out ($U$). The goal is to calculate the remaining number of participants who have not opted out.

## Intuition & Mathematical Observation
The problem is a straightforward arithmetic subtraction. Since $N$ represents the total population and $U$ represents the subset that opted out, the number of people remaining to receive the email is simply the difference between the two:
$$\text{Result} = N - U$$

Given the constraints ($1 \le U < N \le 10^5$), the result will always be a positive integer, and the calculation fits well within standard integer types.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution involves a single subtraction operation.
- **Space Complexity**: $O(1)$, as we only use a constant amount of extra space to store the input variables.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given N total participants and U participants who opted out.
 * The number of participants to send emails to is simply N - U.
 * 
 * Constraints:
 * 1 <= U < N <= 10^5
 * Since N and U fit within a standard 32-bit integer, 'int' is sufficient,
 * but 'long long' is used for safety and best practices in competitive programming.
 * Time Complexity: O(1) per test case.
 * Space Complexity: O(1).
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Reading N (total participants) and U (opted out)
    long long N, U;
    if (cin >> N >> U) {
        // The number of people to send emails to is the difference
        long long result = N - U;
        cout << result << "\n";
    }

    return 0;
}
```