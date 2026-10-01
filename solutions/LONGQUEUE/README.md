# [Long Queue (LONGQUEUE)](https://www.codechef.com/problems/LONGQUEUE)

- **Difficulty Rating**: 719
- **Solved in**: 1 attempt(s)

## Problem Summary
Sushil is standing at the end of a queue of $N$ people. Each person has a specific wealth value. Sushil can bully the person directly in front of him if their wealth is less than or equal to half of his own wealth ($A_i \le \frac{A_{Sushil}}{2}$). If he bullies someone, he takes their place in the queue. This process continues until he encounters someone he cannot bully or he reaches the front of the queue. We need to find his final position in the queue.

## Intuition & Mathematical Observation
The problem describes a greedy process. Since Sushil only interacts with the person immediately in front of him, we can simulate the process starting from the person at index $N-2$ (the person directly in front of Sushil) and moving backwards towards index $0$.

1. **Identify Sushil's Wealth**: Sushil is at the last position, so his wealth is $A[N-1]$.
2. **Iterative Check**: We iterate backwards from $i = N-2$ down to $0$.
3. **Condition**: For each person at index $i$, we check if $A[i] \le \lfloor \frac{A[N-1]}{2} \rfloor$.
   - If the condition is true, Sushil moves forward one position (his position index decreases).
   - If the condition is false, Sushil cannot bully this person, and since he cannot skip over them, the process terminates immediately.
4. **Result**: The final value of the position counter is the answer.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the number of people in the queue. We perform a single pass through the array.
- **Space Complexity**: $O(N)$ to store the wealth values of the people in the queue.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Sushil is at the N-th position (index N-1 in 0-indexed array).
 * His wealth is A[N-1].
 * He can bully the person directly in front of him if that person's wealth 
 * is <= (Sushil's wealth / 2).
 * Since he only bullies the person directly in front of him, we check 
 * from the person at index N-2 down to 0.
 * As long as the condition holds, he moves forward (position decreases).
 * Once he encounters someone he cannot bully, he stops moving forward.
 */

void solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    int sushilWealth = A[N - 1];
    int currentPos = N; // 1-based position

    // Start checking from the person immediately in front of Sushil
    for (int i = N - 2; i >= 0; --i) {
        // Condition: wealth <= Sushil's wealth / 2
        // Using integer division as per problem statement (A_i <= X/2)
        if (A[i] <= (sushilWealth / 2)) {
            currentPos--;
        } else {
            // Cannot bully this person, so Sushil stops here
            break;
        }
    }

    cout << currentPos << "\n";
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