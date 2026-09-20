# [Codechef Airlines (AIRLINES)](https://www.codechef.com/problems/AIRLINES)

- **Difficulty Rating**: 475
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef owns 10 airplanes, each with a seating capacity of $X$. There are $Y$ people who want to book a seat, and each seat costs $Z$. We need to calculate the total earnings, keeping in mind that the number of seats sold cannot exceed the total capacity of the 10 airplanes.

## Intuition & Mathematical Observation
1. **Total Capacity**: Since there are 10 airplanes and each holds $X$ passengers, the maximum number of people Chef can accommodate is $10 \times X$.
2. **Seats Sold**: The number of seats actually sold is limited by either the total capacity or the number of people wanting to book ($Y$). Mathematically, this is expressed as $\min(10 \times X, Y)$.
3. **Earnings**: Once we have the number of seats sold, we multiply that value by the cost per seat ($Z$) to get the total revenue.
4. **Data Types**: While the constraints ($X, Y, Z \le 100$) are small enough for a standard `int`, using `long long` is a good habit to prevent potential overflow in similar problems with larger constraints.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the calculation involves simple arithmetic operations. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the inputs and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef has 10 airplanes.
 * Each airplane has a capacity of X.
 * Total capacity = 10 * X.
 * Number of people willing to book = Y.
 * Number of seats actually sold = min(Total capacity, Y).
 * Cost per seat = Z.
 * Total earnings = min(10 * X, Y) * Z.
 */

int main() {
    // Fast I/O for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long x, y, z;
        cin >> x >> y >> z;
        
        // Total capacity of 10 airplanes
        long long total_capacity = 10 * x;
        
        // Number of people who can actually book a seat
        long long seats_sold = min(total_capacity, y);
        
        // Total earnings
        long long earnings = seats_sold * z;
        
        cout << earnings << "\n";
    }
    
    return 0;
}
```