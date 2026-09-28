# [Passing Marks (CUTOFF)](https://www.codechef.com/problems/CUTOFF)

- **Difficulty Rating**: 855
- **Solved in**: 1 attempt(s)

## Problem Summary
Given $N$ students with distinct scores, we need to determine the maximum possible integer passing mark such that exactly $X$ students pass the exam. A student passes if their score is strictly greater than the passing mark.

## Intuition & Mathematical Observation
To ensure exactly $X$ students pass, we need to identify the $X$-th highest score in the class. Let this score be $S$.

1. **Sorting**: By sorting the scores in descending order, the student at index $X-1$ (0-indexed) represents the lowest score among the top $X$ students.
2. **Defining the Cutoff**:
   - If we set the passing mark to $S$, the student with score $S$ would **not** pass (since $S$ is not strictly greater than $S$).
   - If we set the passing mark to $S-1$, the student with score $S$ **will** pass (since $S > S-1$).
   - Any student with a score higher than $S$ will also pass.
   - Any student with a score lower than $S$ (i.e., the $(X+1)$-th student or worse) will have a score $\le S-1$, meaning they will not pass.
3. **Conclusion**: Therefore, the maximum passing mark that allows exactly $X$ students to pass is $S - 1$.

## Complexity Analysis
- **Time Complexity**: $O(N \log N)$ due to the sorting step, where $N$ is the number of students. The input reading and output operations are $O(N)$.
- **Space Complexity**: $O(N)$ to store the scores of the $N$ students.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have N students with distinct scores.
 * Exactly X students pass the test.
 * A student passes if their score > passing_mark.
 * To maximize the passing_mark, we want the smallest score among the 
 * top X students to be as high as possible, such that the passing_mark 
 * is just below that score.
 * 
 * 1. Sort the scores in descending order.
 * 2. The X-th student (index X-1 in 0-indexed sorted array) is the one 
 *    with the lowest score among those who passed.
 * 3. Let this score be S. Any passing_mark < S will allow this student to pass.
 * 4. To maximize the passing_mark while keeping exactly X students passing,
 *    the passing_mark should be S - 1.
 */

void solve() {
    int N, X;
    cin >> N >> X;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // Sort in descending order to easily pick the X-th highest score
    sort(A.begin(), A.end(), greater<int>());

    // The student at index X-1 is the one with the lowest score among the X passers.
    // If the passing mark is A[X-1] - 1, then A[X-1] > passing_mark,
    // and A[X] (if it exists) will be <= A[X-1] - 1.
    // Thus, exactly X students pass.
    cout << A[X - 1] - 1 << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
```