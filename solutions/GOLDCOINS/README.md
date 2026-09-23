# [Gold Coins 101 (GOLDCOINS)](https://www.codechef.com/problems/GOLDCOINS)

- **Difficulty Rating**: 253
- **Solved in**: 2 attempt(s)

## Problem Summary
Chef and Chefina are playing a game involving gold coins. Chef has $A$ gold coins and Chefina has $B$ gold coins. They both decide to perform an action:
- Chef chooses to give away $X$ gold coins.
- Chefina chooses to give away $Y$ gold coins.

The goal is to determine who ends up with more gold coins after the exchange. Specifically, if Chef's initial amount $A$ is greater than Chefina's initial amount $B$, Chef wins. However, the problem simplifies this: if Chef chooses to give away $X$ coins and Chefina gives away $Y$ coins, we need to output the amount of gold coins the winner has. If $X > Y$, Chef wins (output $A$), otherwise Chefina wins (output $B$).

## Intuition & Mathematical Observation
The problem asks us to compare the values of $X$ and $Y$ to decide which initial amount to print. 
- If $X > Y$, Chef is the winner, so we output $A$.
- If $X \le Y$, Chefina is the winner, so we output $B$.

This is a straightforward conditional logic problem. No complex calculations or data structures are required; a simple `if-else` statement is sufficient to handle the logic.

## Complexity Analysis
- **Time Complexity**: $O(1)$ — The solution performs a constant number of comparisons and I/O operations, regardless of the input values.
- **Space Complexity**: $O(1)$ — We only use a fixed amount of memory to store the four integer variables.

## Solution Code

```cpp
#include <iostream>

using namespace std;

int main() {
    // Optimize I/O operations for faster execution
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int A, B, X, Y;
    
    // Read the input values: 
    // A = Chef's coins, B = Chefina's coins
    // X = Chef's choice, Y = Chefina's choice
    if (!(cin >> A >> B >> X >> Y)) return 0;

    // Compare the choices to determine the winner
    // If X > Y, Chef wins and we output A
    // Otherwise, Chefina wins and we output B
    if (X > Y) {
        cout << A << endl;
    } else {
        cout << B << endl;
    }

    return 0;
}
```