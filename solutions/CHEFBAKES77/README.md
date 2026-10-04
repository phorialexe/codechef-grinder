# [Chef Bakes Cake (CHEFBAKES77)](https://www.codechef.com/problems/CHEFBAKES77)

- **Difficulty Rating**: 397
- **Solved in**: 2 attempt(s)

## Problem Summary
Chef needs to transport $N$ cakes, each weighing $X$ units. He has vehicles that each have a maximum weight capacity of $Y$ units. The goal is to determine the minimum number of vehicles required to transport all $N$ cakes.

## Intuition & Mathematical Observation
1. **Capacity per Vehicle**: Since each cake weighs $X$ and the vehicle capacity is $Y$, the maximum number of cakes that can fit into a single vehicle is given by the integer division:
   $$k = \lfloor Y / X \rfloor$$
   *Note: If $X > Y$, it is impossible to transport the cakes; however, based on standard problem constraints, we assume $X \le Y$.*

2. **Calculating Vehicles**: To find the number of vehicles needed to carry $N$ items with a capacity of $k$ items per vehicle, we need to calculate $\lceil N / k \rceil$.

3. **Integer Arithmetic**: In C++, integer division truncates toward zero. To perform a ceiling division $\lceil a / b \rceil$ using only integers, we use the formula:
   $$\text{result} = (a + b - 1) / b$$
   Applying this to our problem:
   $$\text{vehicles} = (N + k - 1) / k$$

## Complexity Analysis
- **Time Complexity**: $O(1)$. The solution performs a constant number of arithmetic operations regardless of the input size.
- **Space Complexity**: $O(1)$. We only use a few variables to store the input and the result, requiring no extra data structures.

## Solution Code

```cpp
#include <iostream>

/**
 * Problem Analysis:
 * Total weight of cakes = N * X.
 * Each vehicle capacity = Y.
 * The number of cakes that can fit in one vehicle is floor(Y / X).
 * Let k = floor(Y / X) be the number of cakes per vehicle.
 * The number of vehicles required is ceil(N / k).
 * Using integer arithmetic, ceil(N / k) can be calculated as (N + k - 1) / k.
 */

int main() {
    // Optimize I/O operations
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long N, X, Y;
    
    // Read N (number of cakes), X (weight per cake), Y (capacity per vehicle)
    if (std::cin >> N >> X >> Y) {
        // Number of cakes per vehicle
        long long cakes_per_vehicle = Y / X;

        // Number of vehicles needed = ceil(N / cakes_per_vehicle)
        // Using integer division: (N + cakes_per_vehicle - 1) / cakes_per_vehicle
        long long vehicles_needed = (N + cakes_per_vehicle - 1) / cakes_per_vehicle;

        std::cout << vehicles_needed << std::endl;
    }

    return 0;
}
```