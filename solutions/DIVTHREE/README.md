# [Chef and Division 3 (DIVTHREE)](https://www.codechef.com/problems/DIVTHREE)

- **Difficulty Rating**: -1
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef has $N$ problem setters, each having contributed a certain number of problems $A_i$. Chef wants to host contests, where each contest requires exactly $K$ problems. Chef can host at most one contest per day, and there is a limit of $D$ days. We need to determine the maximum number of contests Chef can host given the total number of problems and the time constraint.

## Intuition & Mathematical Observation
1. **Total Capacity**: First, calculate the total number of problems available by summing all $A_i$. Since $N \le 100$ and $A_i \le 10^7$, the total sum can reach $10^9$, which fits comfortably within a 64-bit integer (`long long` in C++).
2. **Problem Constraint**: The number of contests that can be supported by the available problems is given by $\lfloor \frac{\sum A_i}{K} \rfloor$.
3. **Time Constraint**: Chef is limited by $D$ days, and can host at most one contest per day. Thus, the number of contests cannot exceed $D$.
4. **Final Result**: The actual number of contests Chef can host is the smaller of the two constraints: $\min(\lfloor \frac{\sum A_i}{K} \rfloor, D)$.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the number of problem setters. We iterate through the list of problems once to calculate the sum.
- **Space Complexity**: $O(1)$, as we only store the running sum and a few variables regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * - We have N setters, each with A_i problems.
 * - Total problems available = sum(A_i).
 * - Each contest requires K problems.
 * - Maximum contests possible based on problems = total_problems / K.
 * - We are limited by D days, and we can host at most 1 contest per day.
 * - Therefore, the answer is min(total_problems / K, D).
 */

void solve() {
    int N;
    long long K, D;
    cin >> N >> K >> D;

    long long total_problems = 0;
    for (int i = 0; i < N; ++i) {
        long long A;
        cin >> A;
        total_problems += A;
    }

    // Calculate maximum contests possible based on problem count
    long long max_contests_by_problems = total_problems / K;

    // The answer is the minimum of the contests we can host with available problems
    // and the number of days available.
    long long result = min(max_contests_by_problems, D);

    cout << result << "\n";
}

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        solve();
    }
    return 0;
}
```