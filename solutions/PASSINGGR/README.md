# [Passing Grade (PASSINGGR)](https://www.codechef.com/problems/PASSINGGR)

- **Difficulty Rating**: 629
- **Solved in**: 1 attempt(s)

## Problem Summary
In a class of $N$ students, Chef is the first student with marks $A[0]$. We need to determine the minimum number of students who pass the exam. The passing grade $X$ must be set such that Chef passes (i.e., $X \le A[0]$). To minimize the number of students who pass, we must choose the largest possible value for $X$ that still allows Chef to pass.

## Intuition & Mathematical Observation
1. **Constraint**: The passing grade $X$ must satisfy $X \le A[0]$ for Chef to pass.
2. **Minimization**: To minimize the number of students who pass, we need to make the passing grade $X$ as difficult as possible. The highest possible value for $X$ that keeps Chef passing is $X = A[0]$.
3. **Counting**: Once we fix $X = A[0]$, any student $i$ passes if their marks $A[i] \ge X$. Therefore, the problem reduces to counting how many elements in the array $A$ are greater than or equal to $A[0]$.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the number of students. We iterate through the array once to read the input and once to count the passing students.
- **Space Complexity**: $O(N)$ to store the marks of the students. (Note: This could be optimized to $O(1)$ by processing marks on the fly, but $O(N)$ is well within limits).

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef is student 1 with marks A[0].
 * To ensure Chef passes, the cutoff X must satisfy X <= A[0].
 * To minimize the number of students who pass, we want to maximize X 
 * such that X <= A[0].
 * The largest possible value for X is A[0].
 * If we set X = A[0], then any student i with A[i] >= A[0] will pass.
 */

void solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    int chef_marks = A[0];
    int count = 0;

    // We set the cutoff X = chef_marks.
    // A student passes if their marks A[i] >= X.
    for (int i = 0; i < N; ++i) {
        if (A[i] >= chef_marks) {
            count++;
        }
    }

    cout << count << "\n";
}

int main() {
    // Fast I/O
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