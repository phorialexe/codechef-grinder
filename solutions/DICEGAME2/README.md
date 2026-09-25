# [Best of Two (DICEGAME2)](https://www.codechef.com/problems/DICEGAME2)

- **Difficulty Rating**: 789
- **Solved in**: 2 attempt(s)

## Problem Summary
Alice and Bob each roll a standard six-sided die three times. The score for each player is determined by the sum of their two highest rolls. Given the three rolls for Alice ($A_1, A_2, A_3$) and the three rolls for Bob ($B_1, B_2, B_3$), we need to determine who has the higher score, or if the game results in a tie.

## Intuition & Mathematical Observation
To find the sum of the two highest numbers out of three, we don't necessarily need to sort the numbers. A more efficient mathematical approach is:
1. Calculate the total sum of all three rolls: $S = \text{roll}_1 + \text{roll}_2 + \text{roll}_3$.
2. Identify the minimum roll among the three: $M = \min(\text{roll}_1, \text{roll}_2, \text{roll}_3)$.
3. The sum of the two highest rolls is simply $S - M$.

By subtracting the smallest value from the total sum, we are left with the sum of the remaining two largest values. This approach is cleaner and avoids the overhead of sorting arrays.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a constant number of arithmetic operations, resulting in $O(1)$ per test case.
- **Space Complexity**: $O(1)$, as we only use a few integer variables to store the dice rolls and scores regardless of the input size.

## Solution Code

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/**
 * Problem: DICEGAME2
 * Logic: The sum of the two highest rolls out of three is equivalent to:
 * (Sum of all three) - (Minimum of the three).
 * 
 * Complexity: O(T) time, O(1) space.
 */

void solve() {
    int a1, a2, a3, b1, b2, b3;
    if (!(cin >> a1 >> a2 >> a3 >> b1 >> b2 >> b3)) return;

    // Calculate Alice's score: sum of two highest
    int alice_score = (a1 + a2 + a3) - min({a1, a2, a3});

    // Calculate Bob's score: sum of two highest
    int bob_score = (b1 + b2 + b3) - min({b1, b2, b3});

    if (alice_score > bob_score) {
        cout << "Alice" << "\n";
    } else if (bob_score > alice_score) {
        cout << "Bob" << "\n";
    } else {
        cout << "Tie" << "\n";
    }
}

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}
```