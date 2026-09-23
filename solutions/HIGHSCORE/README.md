# [Score High (HIGHSCORE)](https://www.codechef.com/problems/HIGHSCORE)

- **Difficulty Rating**: 672
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef is taking a test consisting of $N$ questions. He is given the total count of correct answers for each of the four options: $N_A, N_B, N_C,$ and $N_D$. Chef wants to maximize his guaranteed marks by choosing one option (A, B, C, or D) and marking all $N$ questions with that same option. We need to find the maximum possible marks he can guarantee.

## Intuition & Mathematical Observation
The problem asks us to maximize the number of correct answers by picking a single option for every question. 

If Chef chooses option 'A' for all $N$ questions, he will correctly answer exactly $N_A$ questions. Similarly, if he chooses 'B', he gets $N_B$ marks, and so on. Since he wants to maximize his score, he should simply choose the option that appears most frequently in the answer key. 

Mathematically, the maximum guaranteed marks is:
$$\text{Result} = \max(N_A, N_B, N_C, N_D)$$

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we are performing a constant number of comparisons to find the maximum of four integers.
- **Space Complexity**: $O(1)$, as we only use a few integer variables to store the input counts.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef knows the total count of answers for each option (A, B, C, D).
 * He wants to maximize the marks he can *guarantee*.
 * 
 * If Chef decides to mark all N problems with a specific option (e.g., option A),
 * he is guaranteed to get exactly N_A marks, because there are exactly N_A 
 * problems where the answer is A.
 * 
 * To maximize the guaranteed marks, Chef should choose the option that appears 
 * the most frequently in the answer key. By marking all problems with the 
 * option that has the highest count among N_A, N_B, N_C, and N_D, he ensures 
 * that he gets at least that many marks.
 * 
 * Therefore, the answer is simply max(N_A, N_B, N_C, N_D).
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n;
        cin >> n;
        
        int na, nb, nc, nd;
        cin >> na >> nb >> nc >> nd;
        
        // The maximum marks guaranteed is the maximum of the counts of each option.
        int max_marks = max({na, nb, nc, nd});
        
        cout << max_marks << "\n";
    }

    return 0;
}
```