# [Big Achiever (BIG)](https://www.codechef.com/problems/BIG)

- **Difficulty Rating**: 699
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an array of $N$ integers representing the scores of students in the order they appear, a student is considered a "Big Achiever" if their score is strictly greater than the scores of all students who appeared before them. We need to output a sequence of $N$ binary values (0 or 1), where 1 indicates the student is a "Big Achiever" and 0 indicates they are not. Note that the first student is always considered a "Big Achiever" as there are no preceding students.

## Intuition & Mathematical Observation
The problem asks us to track the maximum score encountered so far as we iterate through the array. 
1. Let `current_max` be the maximum score seen among the first $i-1$ students.
2. For the $i$-th student with score $A[i]$:
   - If $i = 0$, the student is automatically a "Big Achiever."
   - If $A[i] > \text{current\_max}$, the student is a "Big Achiever," and we update `current_max` to $A[i]$.
   - Otherwise, the student is not a "Big Achiever."
3. By initializing `current_max` to a value smaller than any possible score (e.g., -1), the logic holds for the first element as well, as $A[0] > -1$ will always be true.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, as we iterate through the array exactly once.
- **Space Complexity**: $O(N)$ to store the input array (this can be optimized to $O(1)$ if we process the input values one by one without storing them).

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * A student i is happy if A[i] > max(A[0], A[1], ..., A[i-1]).
 * For the first student (i=0), there are no students before them, 
 * so the condition is vacuously true (or simply, they are always happy).
 * 
 * We can maintain a running maximum of the scores encountered so far.
 * For each student i:
 * 1. If i == 0, they are happy.
 * 2. If A[i] > current_max, they are happy, and we update current_max = A[i].
 * 3. Otherwise, they are not happy.
 * 
 * Time Complexity: O(N) per test case.
 * Space Complexity: O(N) to store the array, or O(1) if processed on the fly.
 */

void solve() {
    int N;
    if (!(cin >> N)) return;
    
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    int current_max = -1;
    for (int i = 0; i < N; ++i) {
        if (A[i] > current_max) {
            cout << 1 << (i == N - 1 ? "" : " ");
            current_max = A[i];
        } else {
            cout << 0 << (i == N - 1 ? "" : " ");
        }
    }
    cout << "\n";
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