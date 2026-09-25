# [Bear and Candies 123 (CANDY123)](https://www.codechef.com/problems/CANDY123)

- **Difficulty Rating**: 1028
- **Solved in**: 2 attempt(s)

## Problem Summary
Limak and Bob are eating candies. Limak eats $1, 3, 5, \dots$ candies in his turns, while Bob eats $2, 4, 6, \dots$ candies in his turns. They take turns starting with Limak. If a person cannot eat the required number of candies (i.e., the required amount is greater than what they have left), they lose. We need to determine the winner given the total candies $A$ for Limak and $B$ for Bob.

## Intuition & Mathematical Observation
The problem describes a deterministic process where the number of candies required increases by 1 each turn. 
- Limak's turns: $1, 3, 5, \dots$ (odd turns)
- Bob's turns: $2, 4, 6, \dots$ (even turns)

Since the constraints are small ($A, B \le 1000$), we do not need a complex mathematical formula. A simple **simulation** is sufficient. We maintain a counter for the current turn number and subtract the required amount from the respective person's total until someone cannot fulfill the requirement. The person who fails to make their move first loses, meaning the other person is the winner.

## Complexity Analysis
- **Time Complexity**: $O(\sqrt{\max(A, B)})$ per test case. Since the number of candies eaten grows quadratically ($1+2+3...+n \approx n^2/2$), the loop runs approximately $\sqrt{2 \times \max(A, B)}$ times. Given $A, B \le 1000$, this is roughly 45 iterations, which is extremely efficient.
- **Space Complexity**: $O(1)$, as we only use a few integer variables to track the state.

## Solution Code

```cpp
#include <iostream>

using namespace std;

/**
 * Problem Analysis:
 * Limak eats 1, 3, 5, ... candies.
 * Bob eats 2, 4, 6, ... candies.
 * Limak loses if his current turn requirement > remaining A.
 * Bob loses if his current turn requirement > remaining B.
 * 
 * Constraints: A, B <= 1000.
 * A simple simulation will run in O(sqrt(max(A, B))) per test case, 
 * which is well within the time limits for T=1000.
 */

void solve() {
    int A, B;
    cin >> A >> B;
    
    int limak_eaten = 0;
    int bob_eaten = 0;
    int turn = 1;
    
    while (true) {
        // Limak's turn
        if (limak_eaten + turn <= A) {
            limak_eaten += turn;
            turn++;
        } else {
            cout << "Bob" << endl;
            return;
        }
        
        // Bob's turn
        if (bob_eaten + turn <= B) {
            bob_eaten += turn;
            turn++;
        } else {
            cout << "Limak" << endl;
            return;
        }
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