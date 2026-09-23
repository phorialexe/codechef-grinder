# [That Is My Score! (WATSCORE)](https://www.codechef.com/problems/WATSCORE)

- **Difficulty Rating**: 1094
- **Solved in**: 1 attempt(s)

## Problem Summary
In a programming contest, there are 11 problems (indexed 1 to 11). However, only problems 1 through 8 contribute to the total score. A participant may submit multiple solutions for the same problem. The final score for each problem is the **maximum** score obtained among all submissions for that specific problem. We need to calculate the total score, which is the sum of the maximum scores of problems 1 through 8.

## Intuition & Mathematical Observation
- Since we only care about problems 1 through 8, any submission for problems 9, 10, or 11 can be ignored.
- We need to track the "best" score for each of the 8 relevant problems independently.
- An array of size 9 (using indices 1–8) is ideal for storing these maximums. We initialize all values to 0.
- As we iterate through the $N$ submissions, if a submission is for problem $p$ (where $1 \le p \le 8$) with score $s$, we update the stored maximum for that problem: `max_scores[p] = max(max_scores[p], s)`.
- After processing all submissions, the total score is simply the sum of the values stored in our array from index 1 to 8.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the number of submissions. We iterate through the input list exactly once and then perform a constant-time summation (8 iterations).
- **Space Complexity**: $O(1)$. We use a fixed-size array of 9 integers regardless of the input size $N$.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have 11 problems, but only problems 1 through 8 are scorable.
 * For each scorable problem, we need to find the maximum score achieved.
 * The total score is the sum of these maximums.
 * 
 * Approach:
 * 1. Use an array of size 9 (indices 1-8) to store the maximum score for each scorable problem.
 * 2. Initialize the array with 0.
 * 3. For each submission (p, s):
 *    - If p <= 8, update max_scores[p] = max(max_scores[p], s).
 * 4. Sum the values in the array from index 1 to 8.
 */

void solve() {
    int n;
    cin >> n;
    
    // max_scores[i] stores the best score for problem i (1-8)
    vector<int> max_scores(9, 0);
    
    for (int i = 0; i < n; ++i) {
        int p, s;
        cin >> p >> s;
        // Only consider problems 1 through 8
        if (p >= 1 && p <= 8) {
            if (s > max_scores[p]) {
                max_scores[p] = s;
            }
        }
    }
    
    long long total_score = 0;
    for (int i = 1; i <= 8; ++i) {
        total_score += max_scores[i];
    }
    
    cout << total_score << "\n";
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