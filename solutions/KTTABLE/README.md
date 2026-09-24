# [Kitchen Timetable (KTTABLE)](https://www.codechef.com/problems/KTTABLE)

- **Difficulty Rating**: 997
- **Solved in**: 1 attempt(s)

## Problem Summary
There are $N$ students who need to use a kitchen. Each student $i$ is assigned a specific time window to finish their task. The deadlines for the students are given as an array $A$, where $A_i$ is the time by which the $i$-th student must finish their task. The students work sequentially: the first student starts at time $0$, and each subsequent student starts exactly when the previous student finishes their deadline (or earlier, but the problem defines the window based on the previous deadline). Specifically, the $i$-th student has a duration of $A_i - A_{i-1}$ (with $A_0 = 0$) to complete their task, which requires $B_i$ time. We need to count how many students can successfully complete their task within their allotted time.

## Intuition & Mathematical Observation
The core of the problem is to determine the time available for each student. 
1. For the first student ($i=0$), the time available is $A_0 - 0$.
2. For any subsequent student ($i > 0$), the time available is the difference between their deadline $A_i$ and the previous student's deadline $A_{i-1}$.
3. A student can complete their task if and only if their required time $B_i$ is less than or equal to the available time window ($A_i - A_{i-1}$).

By iterating through the arrays once and maintaining a `prev_time` variable (initialized to 0), we can calculate the available window for each student on the fly and compare it against $B_i$.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the number of students. We iterate through the input arrays exactly once.
- **Space Complexity**: $O(N)$ to store the arrays $A$ and $B$. This could be optimized to $O(1)$ if we processed the input values as we read them, but $O(N)$ is well within the memory limits for $N=10^4$.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * - N students, each has a time window to cook.
 * - Student 1: starts at 0, must finish by A1. Duration available: A1 - 0.
 * - Student i (i > 1): starts at A_{i-1}, must finish by A_i. Duration available: A_i - A_{i-1}.
 * - Student i needs B_i time.
 * - Condition to succeed: B_i <= (A_i - A_{i-1}) for i > 1, and B_1 <= A_1.
 * 
 * Constraints:
 * - T <= 10, N <= 10^4.
 * - A_i, B_i up to 10^9. Use long long to prevent overflow during calculations.
 */

void solve() {
    int N;
    if (!(cin >> N)) return;

    vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    vector<long long> B(N);
    for (int i = 0; i < N; ++i) {
        cin >> B[i];
    }

    int count = 0;
    long long prev_time = 0;

    for (int i = 0; i < N; ++i) {
        // Calculate the time window available for the current student
        long long available_time = A[i] - prev_time;
        
        // Check if the student can finish within the window
        if (B[i] <= available_time) {
            count++;
        }
        
        // Update the previous deadline for the next iteration
        prev_time = A[i];
    }

    cout << count << "\n";
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