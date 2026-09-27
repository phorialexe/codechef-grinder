# [Weightlifting (WEIGHTLIFT)](https://www.codechef.com/problems/WEIGHTLIFT)

- **Difficulty Rating**: 270
- **Solved in**: 1 attempt(s)

## Problem Summary
In a weightlifting competition, there are three rounds. For each round, a participant is given two attempts. The final score for each round is determined by the maximum weight lifted in those two attempts. The goal is to calculate the total score, which is the sum of the maximum weights from all three rounds.

## Intuition & Mathematical Observation
The problem asks for the sum of the best results from three independent rounds. Since each round consists of two attempts, we simply need to compare the two values provided for each round and select the larger one.

Mathematically, if the attempts for the rounds are $(a_1, a_2)$, $(b_1, b_2)$, and $(c_1, c_2)$, the total score $S$ is calculated as:
$$S = \max(a_1, a_2) + \max(b_1, b_2) + \max(c_1, c_2)$$

By using the `std::max` function in C++, we can efficiently determine the best attempt for each round and sum them up to get the final result.

## Complexity Analysis
- **Time Complexity**: $O(1)$ — The solution performs a constant number of comparisons and additions regardless of the input values.
- **Space Complexity**: $O(1)$ — We only use a fixed amount of memory to store the six input variables and the intermediate round scores.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Weightlifting
 * The goal is to find the maximum of two attempts for each of the three rounds
 * and sum these maximums to get the total score.
 * 
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long a1, a2, b1, b2, c1, c2;
    
    // Reading the 6 space-separated integers
    if (cin >> a1 >> a2 >> b1 >> b2 >> c1 >> c2) {
        // Calculate the maximum for each round
        long long round1 = max(a1, a2);
        long long round2 = max(b1, b2);
        long long round3 = max(c1, c2);
        
        // Calculate total score
        long long total_score = round1 + round2 + round3;
        
        // Output the result
        cout << total_score << "\n";
    }

    return 0;
}
```