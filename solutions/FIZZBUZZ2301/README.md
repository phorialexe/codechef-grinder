# [Fan Poll (FIZZBUZZ2301)](https://www.codechef.com/problems/FIZZBUZZ2301)

- **Difficulty Rating**: 273
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to determine if Dhoni received more votes than both Rohit and Kohli in a fan poll. We are given three integers $A$, $B$, and $C$, representing the number of votes received by Dhoni, Rohit, and Kohli, respectively. We need to output "Yes" if $A$ is strictly greater than both $B$ and $C$, and "No" otherwise.

## Intuition & Mathematical Observation
The problem states that no two players received the same number of votes. Therefore, we do not need to worry about tie-breaking conditions. 

To satisfy the condition that Dhoni is the winner, we simply need to evaluate the boolean expression:
$$(A > B) \land (A > C)$$

If this condition evaluates to `true`, Dhoni has the highest number of votes among the three, and we print "Yes". Otherwise, we print "No".

## Complexity Analysis
- **Time Complexity**: $O(1)$ — The solution performs a constant number of comparisons regardless of the input values.
- **Space Complexity**: $O(1)$ — We only use a fixed amount of memory to store the three integer variables.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Fan Poll (FIZZBUZZ2301)
 * Logic: Dhoni wins if A > B and A > C.
 * Since the problem guarantees no two players received the same number of votes,
 * we simply check if A is strictly greater than both B and C.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int A, B, C;
    
    // Read the three vote counts
    if (cin >> A >> B >> C) {
        // Check if Dhoni's votes (A) are greater than Rohit's (B) and Kohli's (C)
        if (A > B && A > C) {
            cout << "Yes" << "\n";
        } else {
            cout << "No" << "\n";
        }
    }

    return 0;
}
```