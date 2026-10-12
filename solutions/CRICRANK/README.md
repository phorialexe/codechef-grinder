# [Cricket Ranking (CRICRANK)](https://www.codechef.com/problems/CRICRANK)

- **Difficulty Rating**: 966
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given the performance statistics of two cricket players, A and B, across three categories: Runs, Wickets, and Catches. For each category, we compare the values of player A and player B. The player who performs better in more categories (i.e., has a higher value in at least 2 out of 3 categories) is declared the overall winner. We are guaranteed that the values for any specific category are never equal.

## Intuition & Mathematical Observation
Since there are exactly three categories and no ties are possible in any individual category, the total number of categories won by player A plus the total number of categories won by player B must equal 3. 

- Let $C_A$ be the count of categories where Player A has a higher value.
- Let $C_B$ be the count of categories where Player B has a higher value.
- Since $C_A + C_B = 3$, the winner is simply the player with the higher count. 
- We can maintain two counters, compare the inputs for each category, increment the respective counter, and output the winner based on which counter is greater.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a constant number of comparisons (3), resulting in linear time complexity relative to the input size.
- **Space Complexity**: $O(1)$, as we only use a fixed number of integer variables to store the statistics and counters, regardless of the input values.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given two players A and B with three statistics: Runs (R), Wickets (W), and Catches (C).
 * We need to compare them in each category.
 * Let countA be the number of categories where player A has a higher value than player B.
 * Let countB be the number of categories where player B has a higher value than player A.
 * Since the problem guarantees that values are never equal in any category, 
 * countA + countB = 3.
 * If countA > countB, player A is better. Otherwise, player B is better.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        int r1, w1, c1;
        int r2, w2, c2;
        
        cin >> r1 >> w1 >> c1;
        cin >> r2 >> w2 >> c2;
        
        int countA = 0;
        int countB = 0;
        
        // Compare Runs
        if (r1 > r2) countA++;
        else countB++;
        
        // Compare Wickets
        if (w1 > w2) countA++;
        else countB++;
        
        // Compare Catches
        if (c1 > c2) countA++;
        else countB++;
        
        // Determine winner
        if (countA > countB) {
            cout << "A" << "\n";
        } else {
            cout << "B" << "\n";
        }
    }
    
    return 0;
}
```