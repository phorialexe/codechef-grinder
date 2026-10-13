# [Minimum Attendance Requirement (ATTENDU)](https://www.codechef.com/problems/ATTENDU)

- **Difficulty Rating**: 1053
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef is enrolled in a semester consisting of exactly 120 days. To pass the semester, a student must have an attendance of at least 75%. Given the attendance record for the first $N$ days of the semester (represented as a binary string where '1' means present and '0' means absent), determine if it is possible for Chef to achieve at least 75% attendance by the end of the 120 days, assuming Chef attends all remaining $(120 - N)$ days.

## Intuition & Mathematical Observation
1. **Calculate the Target**: The total number of days in the semester is 120. The required attendance is 75% of 120:
   $$0.75 \times 120 = 90 \text{ days}$$
   Chef needs at least 90 days of attendance to pass.

2. **Calculate Current Status**: We are given a string $B$ of length $N$. We count the number of '1's in this string, which represents the days Chef has already attended (`present_count`).

3. **Project Future Attendance**: Chef has $(120 - N)$ days remaining in the semester. To check if it is *possible* to pass, we assume the best-case scenario: Chef attends every single one of the remaining days.

4. **Decision Logic**:
   - Total potential attendance = `present_count` + `(120 - N)`.
   - If `total_potential_attendance >= 90`, output `YES`.
   - Otherwise, output `NO`.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the number of days provided in the input string. We iterate through the string once to count the '1's.
- **Space Complexity**: $O(N)$ to store the input string $B$.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Total days in semester = 120.
 * Required attendance = 75% of 120 = 0.75 * 120 = 90 days.
 * 
 * Chef has already attended 'present_count' days out of 'N' days.
 * Remaining days in the semester = 120 - N.
 * To maximize attendance, assume Chef attends all remaining days.
 * Total possible attendance = present_count + (120 - N).
 * 
 * Condition to pass: Total possible attendance >= 90.
 */

void solve() {
    int N;
    cin >> N;
    string B;
    cin >> B;

    int present_count = 0;
    for (char c : B) {
        if (c == '1') {
            present_count++;
        }
    }

    // Remaining days in the semester
    int remaining_days = 120 - N;
    
    // Maximum possible attendance if Chef attends all remaining days
    int max_possible_attendance = present_count + remaining_days;

    if (max_possible_attendance >= 90) {
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