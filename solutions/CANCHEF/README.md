# [Can Chef (CANCHEF)](https://www.codechef.com/problems/CANCHEF)

- **Difficulty Rating**: 471
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef wants to attend a function located $Y$ kilometers away from his home. His car has a fuel efficiency of 15 km per liter. Given that Chef has $X$ liters of petrol, determine if he can travel to the function and return home safely.

## Intuition & Mathematical Observation
To attend the function and return home, Chef must cover a total distance of $2 \times Y$ kilometers. 

Given the car's efficiency of 15 km/liter, the maximum distance Chef can travel with $X$ liters of petrol is $X \times 15$ kilometers. Therefore, the condition for Chef to successfully attend the function and return is:
$$\text{Total Distance Possible} \geq \text{Total Distance Required}$$
$$X \times 15 \geq 2 \times Y$$

If this inequality holds true, output "YES"; otherwise, output "NO".

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a constant number of arithmetic operations, resulting in $O(1)$ per test case.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and perform calculations, regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef's car efficiency: 15 km per 1 liter of petrol.
 * Total distance to cover: 2 * Y (to go and return).
 * Petrol available: X liters.
 * Maximum distance possible with X liters: X * 15 km.
 * Condition: Chef can attend if (X * 15) >= (2 * Y).
 * 
 * Constraints:
 * T <= 1000
 * X, Y <= 1000
 * X * 15 will be at most 15000, and 2 * Y will be at most 2000.
 * Standard 'int' is sufficient, but 'long long' is used for safety.
 */

int main() {
    // Optimize standard I/O operations for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long x, y;
        cin >> x >> y;
        
        // Total distance required is 2 * Y
        // Total distance possible is X * 15
        if (x * 15 >= 2 * y) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
    
    return 0;
}
```