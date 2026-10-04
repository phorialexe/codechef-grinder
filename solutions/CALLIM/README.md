# [Calorie Limit (CALLIM)](https://www.codechef.com/problems/CALLIM)

- **Difficulty Rating**: 719
- **Solved in**: 1 attempt(s)

## Problem Summary
You are given $N$ sweets, each with a specific calorie count. You have a daily calorie limit $K$. You must eat the sweets in the order they are provided. Determine the maximum number of sweets you can eat such that the total calorie count does not exceed $K$. If adding the next sweet causes the total to exceed $K$, you must stop eating immediately.

## Intuition & Mathematical Observation
The problem follows a greedy approach. Since we are required to eat the sweets in the given order, we simply need to maintain a running sum of the calories consumed. 

1. Initialize `current_calories` to 0 and `count` to 0.
2. Iterate through the list of sweets one by one.
3. For each sweet with calorie value $A[i]$:
   - Check if `current_calories + A[i]` is less than or equal to $K$.
   - If it is, add $A[i]$ to `current_calories` and increment the `count`.
   - If it is not, stop the process immediately (break the loop), as we cannot exceed the limit.
4. The final `count` is the answer.

Using `long long` for the `current_calories` variable is a good practice to prevent potential integer overflow, although given the constraints of typical problems of this difficulty, standard integers might suffice.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the number of sweets. We iterate through the array of sweets exactly once.
- **Space Complexity**: $O(N)$ to store the input array, or $O(1)$ if we process the input values on the fly without storing them in a vector.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Calorie Limit
 * Approach:
 * We iterate through the sweets one by one. We maintain a running sum of calories
 * consumed so far. For each sweet, we check if adding its calorie count to the 
 * current sum exceeds K. If it does, we stop immediately. Otherwise, we add it 
 * to the sum and increment our count of sweets eaten.
 * 
 * Time Complexity: O(N) per test case, where N is the number of sweets.
 * Space Complexity: O(1) auxiliary space (excluding input storage).
 */

void solve() {
    int N;
    long long K;
    cin >> N >> K;
    
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    long long current_calories = 0;
    int count = 0;
    
    for (int i = 0; i < N; ++i) {
        if (current_calories + A[i] <= K) {
            current_calories += A[i];
            count++;
        } else {
            // Cannot eat this sweet or any further sweets
            break;
        }
    }
    
    cout << count << "\n";
}

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    
    return 0;
}
```