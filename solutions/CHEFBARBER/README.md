# [Chef and the Hair Salon (CHEFBARBER)](https://www.codechef.com/problems/CHEFBARBER)

- **Difficulty Rating**: 895
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef runs a hair salon where each haircut takes exactly $M$ minutes. If there are $N$ customers waiting in line ahead of a new customer, we need to calculate the total time the new customer must wait before their haircut begins.

## Intuition & Mathematical Observation
The problem asks for the total time elapsed until the $N$ customers currently in the queue are finished. Since each customer takes $M$ minutes and they are served sequentially, the total time is simply the product of the number of customers and the time per haircut:

$$\text{Total Wait Time} = N \times M$$

- If $N = 0$, the customer is served immediately, resulting in $0 \times M = 0$ minutes.
- Given the constraints $N, M \le 1000$, the maximum result is $1,000,000$, which fits well within a standard 32-bit integer. However, using `long long` is a good practice to ensure safety against potential overflows in similar problems.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a constant time multiplication operation $O(1)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result, regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef has N customers ahead of him.
 * Each customer takes M minutes.
 * The total time Chef has to wait is the sum of the time taken for all N customers.
 * Total Wait Time = N * M.
 * 
 * Constraints:
 * N <= 1000, M <= 1000.
 * The maximum possible value is 1000 * 1000 = 1,000,000.
 * This fits comfortably within a standard 32-bit integer, but using long long 
 * is a safe practice in competitive programming to prevent overflow in similar problems.
 */

int main() {
    // Fast I/O for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long n, m;
        cin >> n >> m;
        
        // The wait time is simply the number of people ahead multiplied by time per person.
        // If N = 0, the result is 0 * M = 0, which is correct.
        long long wait_time = n * m;
        
        cout << wait_time << "\n";
    }
    
    return 0;
}
```