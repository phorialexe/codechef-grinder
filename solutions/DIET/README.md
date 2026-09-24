# [Chef Diet (DIET)](https://www.codechef.com/problems/DIET)

- **Difficulty Rating**: 1025
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef needs to consume exactly $K$ grams of protein every day for $N$ days. He buys $A_i$ grams of protein on day $i$. Any protein not consumed on the day it is bought can be stored and used on subsequent days. We need to determine if Chef can meet his daily requirement for all $N$ days. If he fails, we must report the first day on which he does not have enough protein.

## Intuition & Mathematical Observation
The problem can be modeled using a simple greedy approach:
1. Maintain a variable `stored` representing the surplus protein available from previous days.
2. For each day $i$ (from 1 to $N$):
   - Add the protein purchased on that day ($A_i$) to the `stored` amount.
   - Check if the total available protein (`stored`) is at least $K$.
   - If `stored < K`, Chef cannot meet his requirement, and the current day $i$ is the day he fails.
   - If `stored >= K`, Chef consumes $K$ grams, so we subtract $K$ from `stored` and proceed to the next day.
3. If the loop completes without the condition `stored < K` ever being met, Chef successfully meets his diet requirements for all $N$ days.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, as we iterate through the array of $N$ days exactly once.
- **Space Complexity**: $O(N)$ to store the input array, though this could be optimized to $O(1)$ by processing the input on the fly.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef needs K grams of protein each day.
 * He buys A_i grams on day i.
 * He stores the surplus (A_i - K) to use on future days.
 * If at any point the total available protein (stored + current day's purchase)
 * is less than K, he fails on that day.
 */

void solve() {
    int N;
    long long K;
    cin >> N >> K;
    
    vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    long long stored = 0;
    bool possible = true;
    int fail_day = -1;
    
    for (int i = 0; i < N; ++i) {
        // Add current day's protein to stored
        stored += A[i];
        
        // Check if we can eat K grams
        if (stored < K) {
            possible = false;
            fail_day = i + 1;
            break;
        } else {
            // Consume K grams
            stored -= K;
        }
    }
    
    if (possible) {
        cout << "YES" << "\n";
    } else {
        cout << "NO " << fail_day << "\n";
    }
}

int main() {
    // Fast I/O
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