# [Card Game (CARDGAME1)](https://www.codechef.com/problems/CARDGAME1)

- **Difficulty Rating**: 671
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef and Chefina are playing a game with $N$ cards numbered from $1$ to $N$. Chef picks a card $X$. Chefina needs to pick a card $Y$ (where $Y \neq X$) such that the sum $X + Y$ is even. We need to determine how many such cards $Y$ are available for Chefina to choose.

## Intuition & Mathematical Observation
The sum of two numbers $(X + Y)$ is even if and only if both numbers have the same parity (i.e., both are odd or both are even).

1. **Parity Logic**:
   - If $X$ is odd, Chefina must choose an odd $Y$ (where $Y \neq X$).
   - If $X$ is even, Chefina must choose an even $Y$ (where $Y \neq X$).

2. **Counting Parity**:
   - In the range $[1, N]$, the number of odd integers is calculated as `(N + 1) / 2`.
   - The number of even integers is calculated as `N / 2`.

3. **Calculation**:
   - If $X$ is odd, the number of available choices is `(total_odd_numbers - 1)`.
   - If $X$ is even, the number of available choices is `(total_even_numbers - 1)`.

This approach allows us to solve the problem in constant time per test case without iterating through the cards.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution uses simple arithmetic operations. The total time complexity is $O(T)$, where $T$ is the number of test cases.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and counts.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have N cards numbered 1 to N.
 * Chef throws card X.
 * We need to find how many cards Y (where Y is in {1, ..., N} and Y != X)
 * satisfy the condition that (X + Y) is even.
 * 
 * (X + Y) is even if and only if X and Y have the same parity (both even or both odd).
 * 
 * Let:
 * - count_odd be the total number of odd cards in {1, ..., N}.
 * - count_even be the total number of even cards in {1, ..., N}.
 * 
 * If X is odd:
 * Chefina needs to pick an odd card Y such that Y != X.
 * The number of such cards is (count_odd - 1).
 * 
 * If X is even:
 * Chefina needs to pick an even card Y such that Y != X.
 * The number of such cards is (count_even - 1).
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long n, x;
        cin >> n >> x;

        // Total odd numbers in range [1, N]
        long long count_odd = (n + 1) / 2;
        // Total even numbers in range [1, N]
        long long count_even = n / 2;

        if (x % 2 != 0) {
            // X is odd, we need to pick another odd card
            cout << (count_odd - 1) << "\n";
        } else {
            // X is even, we need to pick another even card
            cout << (count_even - 1) << "\n";
        }
    }

    return 0;
}
```