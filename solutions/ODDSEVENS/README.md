# [Odds and Evens (ODDSEVENS)](https://www.codechef.com/problems/ODDSEVENS)

- **Difficulty Rating**: 872
- **Solved in**: 1 attempt(s)

## Problem Summary
Alice and Bob play a game where Alice chooses a number $a$ and Bob chooses a number $b$. The sum of their numbers, $S = a + b$, determines the winner:
- If $S$ is **odd**, Alice wins.
- If $S$ is **even**, Bob wins.
Given $a$ and $b$, we need to determine the winner of the game.

## Intuition & Mathematical Observation
The problem boils down to checking the parity (odd or even nature) of the sum of two integers.
- A number is **even** if it is divisible by 2 (i.e., $n \pmod 2 = 0$).
- A number is **odd** if it is not divisible by 2 (i.e., $n \pmod 2 \neq 0$).

By calculating `(a + b) % 2`, we can directly determine the winner:
1. If the result is non-zero, the sum is odd, so **Alice** wins.
2. If the result is zero, the sum is even, so **Bob** wins.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a constant number of arithmetic operations, resulting in $O(1)$ per test case.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the inputs and the sum, regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Odds and Evens
 * Logic:
 * Alice wins if (a + b) is odd.
 * Bob wins if (a + b) is even.
 * 
 * Time Complexity: O(T) where T is the number of test cases.
 * Space Complexity: O(1) as we only use a few integer variables.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long a, b;
        cin >> a >> b;
        
        // Calculate the sum
        long long sum = a + b;
        
        // Check parity
        if (sum % 2 != 0) {
            // Sum is odd, Alice wins
            cout << "Alice" << "\n";
        } else {
            // Sum is even, Bob wins
            cout << "Bob" << "\n";
        }
    }
    
    return 0;
}
```