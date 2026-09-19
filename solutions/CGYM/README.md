# [Chef and Gym (CGYM)](https://www.codechef.com/problems/CGYM)

- **Difficulty Rating**: 496
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef wants to join a gym. The monthly cost of the gym is $X$ and the cost of a personal trainer is $Y$. Chef has a total monthly budget of $Z$. We need to determine the maximum number of services (gym only, or gym + trainer) Chef can afford within their budget $Z$.

## Intuition & Mathematical Observation
The problem asks for the maximum number of services Chef can afford. There are three possible outcomes:
1. **Both services**: If the sum of the gym cost and the trainer cost ($X + Y$) is less than or equal to the budget $Z$, Chef can afford both.
2. **Gym only**: If Chef cannot afford both, but the gym cost ($X$) is less than or equal to the budget $Z$, Chef can afford only the gym.
3. **None**: If even the gym cost ($X$) exceeds the budget $Z$, Chef cannot afford any service.

Since we want the *maximum* number of services, we check the conditions in descending order of priority (2 services -> 1 service -> 0 services).

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a constant number of arithmetic operations and comparisons, resulting in $O(1)$ per test case.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input values regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef has a budget Z.
 * Gym cost = X.
 * Trainer cost = Y.
 * 
 * Logic:
 * 1. Check if Chef can afford both: (X + Y) <= Z. If yes, output 2.
 * 2. If not, check if Chef can afford just the gym: X <= Z. If yes, output 1.
 * 3. If neither, output 0.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long x, y, z;
        cin >> x >> y >> z;
        
        // Check if both gym and trainer are affordable
        if (x + y <= z) {
            cout << "2" << "\n";
        }
        // Check if only gym is affordable
        else if (x <= z) {
            cout << "1" << "\n";
        }
        // Cannot afford gym
        else {
            cout << "0" << "\n";
        }
    }
    
    return 0;
}
```