# [Chef and Bird farm (BIRDFARM)](https://www.codechef.com/problems/BIRDFARM)

- **Difficulty Rating**: 591
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef has a farm with chickens and ducks. Each chicken has $X$ legs and each duck has $Y$ legs. Given the total number of legs $Z$ found on the farm, we need to determine if the farm could consist of only chickens, only ducks, both, or neither.

- If the total legs $Z$ can be formed by only chickens, output `CHICKEN`.
- If the total legs $Z$ can be formed by only ducks, output `DUCK`.
- If both are possible, output `ANY`.
- If neither is possible, output `NONE`.

## Intuition & Mathematical Observation
The problem boils down to checking divisibility. Since we are looking for a scenario where the total number of legs $Z$ is perfectly divisible by the number of legs per bird:

1. **Chicken Check**: If $Z \pmod X == 0$, then it is possible to have only chickens.
2. **Duck Check**: If $Z \pmod Y == 0$, then it is possible to have only ducks.

By evaluating these two conditions, we can determine the output:
- If both conditions are true, the answer is `ANY`.
- If only the chicken condition is true, the answer is `CHICKEN`.
- If only the duck condition is true, the answer is `DUCK`.
- If neither condition is true, the answer is `NONE`.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. Each test case performs a constant number of arithmetic operations, making it $O(1)$ per test case.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and results.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given X (legs per chicken), Y (legs per duck), and Z (total legs).
 * - A farm can have chickens if Z is divisible by X (Z % X == 0).
 * - A farm can have ducks if Z is divisible by Y (Z % Y == 0).
 * 
 * Logic:
 * - If (Z % X == 0) and (Z % Y == 0), then ANY.
 * - If (Z % X == 0) and (Z % Y != 0), then CHICKEN.
 * - If (Z % X != 0) and (Z % Y == 0), then DUCK.
 * - If (Z % X != 0) and (Z % Y != 0), then NONE.
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

        bool can_chicken = (z % x == 0);
        bool can_duck = (z % y == 0);

        if (can_chicken && can_duck) {
            cout << "ANY" << "\n";
        } else if (can_chicken) {
            cout << "CHICKEN" << "\n";
        } else if (can_duck) {
            cout << "DUCK" << "\n";
        } else {
            cout << "NONE" << "\n";
        }
    }

    return 0;
}
```