# [Chef and Card Game (CRDGAME)](https://www.codechef.com/problems/CRDGAME)

- **Difficulty Rating**: 1125
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef and Morty are playing a card game consisting of $N$ rounds. In each round, both players draw a card with a number on it. The "power" of a card is defined as the sum of its digits. 
- If Chef's power is greater than Morty's, Chef wins the round.
- If Morty's power is greater than Chef's, Morty wins the round.
- If the powers are equal, both players receive a point for that round.

The goal is to determine the overall winner (the player with more points) and their total score. If there is a tie in total points, output 2.

## Intuition & Mathematical Observation
1. **Digit Sum Calculation**: Since the input numbers can be large, we need a helper function to extract digits using the modulo operator (`% 10`) and integer division (`/ 10`). This allows us to calculate the sum of digits in $O(\log_{10}(\text{number}))$ time.
2. **Round Logic**: We maintain two counters, `chef_pts` and `morty_pts`. For every round, we calculate the digit sums for both cards and update the scores based on the comparison rules provided.
3. **Final Comparison**: After iterating through all $N$ rounds, we compare the total scores:
    - If `chef_pts > morty_pts`, Chef wins (output `0`).
    - If `morty_pts > chef_pts`, Morty wins (output `1`).
    - If `chef_pts == morty_pts`, it is a draw (output `2`).

## Complexity Analysis
- **Time Complexity**: $O(T \times N \times \log_{10}(\max(A_i, B_i)))$, where $T$ is the number of test cases and $N$ is the number of rounds. Given the constraints, this is highly efficient and well within the 1-second time limit.
- **Space Complexity**: $O(1)$, as we only use a few variables to track scores and current round values, regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Chef and Card Game
 * Approach:
 * 1. For each test case, initialize Chef's points (chef_pts) and Morty's points (morty_pts) to 0.
 * 2. For each round, calculate the sum of digits for both Chef's card and Morty's card.
 * 3. Compare the sums:
 *    - If Chef's sum > Morty's sum, Chef gets 1 point.
 *    - If Morty's sum > Chef's sum, Morty gets 1 point.
 *    - If they are equal, both get 1 point.
 * 4. After all rounds, compare total points to determine the winner.
 */

long long get_digit_sum(long long n) {
    long long sum = 0;
    while (n > 0) {
        sum += (n % 10);
        n /= 10;
    }
    return sum;
}

void solve() {
    int N;
    cin >> N;
    
    int chef_pts = 0;
    int morty_pts = 0;
    
    for (int i = 0; i < N; ++i) {
        long long A, B;
        cin >> A >> B;
        
        long long power_A = get_digit_sum(A);
        long long power_B = get_digit_sum(B);
        
        if (power_A > power_B) {
            chef_pts++;
        } else if (power_B > power_A) {
            morty_pts++;
        } else {
            chef_pts++;
            morty_pts++;
        }
    }
    
    if (chef_pts > morty_pts) {
        cout << 0 << " " << chef_pts << "\n";
    } else if (morty_pts > chef_pts) {
        cout << 1 << " " << morty_pts << "\n";
    } else {
        cout << 2 << " " << chef_pts << "\n";
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