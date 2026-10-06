# [Hungry Ashish (PIZZA_BURGER)](https://www.codechef.com/problems/PIZZA_BURGER)

- **Difficulty Rating**: 1064
- **Solved in**: 1 attempt(s)

## Problem Summary
Ashish has $X$ rupees. He wants to buy food, and there are two options available: a Pizza costing $Y$ rupees and a Burger costing $Z$ rupees. Ashish has a strict preference order: he prefers Pizza over a Burger, and a Burger over eating nothing. Given $X, Y,$ and $Z$, determine what Ashish will eat.

## Intuition & Mathematical Observation
The problem follows a simple hierarchical decision-making process based on the available budget $X$:

1. **Priority 1 (Pizza):** If Ashish has enough money to afford the Pizza ($X \ge Y$), he will always choose the Pizza, regardless of whether he can afford the Burger or not, because Pizza is his top preference.
2. **Priority 2 (Burger):** If he cannot afford the Pizza ($X < Y$), he then checks if he can afford the Burger ($X \ge Z$). If he can, he chooses the Burger.
3. **Priority 3 (Nothing):** If he cannot afford either the Pizza ($X < Y$) or the Burger ($X < Z$), he is left with no choice but to eat "NOTHING".

By using a simple `if-else if-else` ladder, we can evaluate these conditions in the order of preference.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a constant number of comparisons, resulting in $O(1)$ per test case.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input values and do not require any auxiliary data structures.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Ashish has X rupees.
 * Pizza costs Y, Burger costs Z.
 * Preference: PIZZA > BURGER > NOTHING.
 * 
 * Logic:
 * 1. Check if X >= Y (Can afford Pizza). Since Pizza is preferred, if he can afford it, he eats it.
 * 2. Else, check if X >= Z (Can afford Burger). If he can't afford Pizza but can afford Burger, he eats Burger.
 * 3. Else, he eats NOTHING.
 */

int main() {
    // Fast I/O setup for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long x, y, z;
        cin >> x >> y >> z;
        
        if (x >= y) {
            cout << "PIZZA" << "\n";
        } else if (x >= z) {
            cout << "BURGER" << "\n";
        } else {
            cout << "NOTHING" << "\n";
        }
    }
    
    return 0;
}
```