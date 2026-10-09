# [Qualifying to Pre-Elimination (QUALPREL)](https://www.codechef.com/problems/QUALPREL)

- **Difficulty Rating**: -1
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given $N$ scores of teams participating in a contest. We need to select the top $K$ teams to qualify for the pre-elimination round. However, if there are multiple teams tied with the score of the $K$-th team, all of them must also qualify. We need to determine the total number of teams that qualify.

## Intuition & Mathematical Observation
1. **Sorting**: To easily identify the $K$-th highest score, we sort the array of scores in descending order.
2. **Threshold Identification**: After sorting, the score of the $K$-th team is located at index $K-1$ (using 0-based indexing). Let this value be `threshold`.
3. **Handling Ties**: The problem states that any team with a score greater than or equal to the `threshold` must qualify. Since the array is sorted in descending order, all elements from index $0$ to $K-1$ are guaranteed to be $\ge$ `threshold`. We simply need to count how many additional elements after index $K-1$ also equal the `threshold`.
4. **Optimization**: Instead of a separate counting loop, we can simply iterate through the sorted array and count all elements $\ge$ `threshold`. Because the array is sorted, we can stop counting as soon as we encounter a value smaller than the `threshold`.

## Complexity Analysis
- **Time Complexity**: $O(N \log N)$ per test case, dominated by the sorting step. Given that the sum of $N$ over all test cases is $10^6$, this approach is efficient enough to pass within the time limit.
- **Space Complexity**: $O(N)$ to store the scores of the $N$ teams.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given N scores and a threshold K.
 * We need to find the number of teams that qualify.
 * A team qualifies if its score is >= the score of the K-th team 
 * when the scores are sorted in descending order.
 * 
 * Algorithm:
 * 1. Sort the array of scores in descending order.
 * 2. Identify the score at index K-1 (0-indexed). Let this be threshold_score.
 * 3. Count how many scores in the array are >= threshold_score.
 */

void solve() {
    int N, K;
    if (!(cin >> N >> K)) return;
    
    vector<long long> S(N);
    for (int i = 0; i < N; ++i) {
        cin >> S[i];
    }
    
    // Sort in descending order
    sort(S.begin(), S.end(), greater<long long>());
    
    // The K-th team is at index K-1
    long long threshold = S[K - 1];
    
    // Count how many teams have score >= threshold
    int count = 0;
    for (int i = 0; i < N; ++i) {
        if (S[i] >= threshold) {
            count++;
        } else {
            // Since the array is sorted descending, we can break early
            break;
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