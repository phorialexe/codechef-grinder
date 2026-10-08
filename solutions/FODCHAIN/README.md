# [Food Chain (FODCHAIN)](https://www.codechef.com/problems/FODCHAIN)

- **Difficulty Rating**: 1062
- **Solved in**: 1 attempt(s)

## Problem Summary
In a food chain, the energy at each level is determined by the energy of the previous level divided by a constant factor $K$ (using floor division). The chain continues as long as the energy is greater than 0. Given an initial energy $E$ and a reduction factor $K$, we need to calculate the total number of levels in the food chain that have a non-zero energy value.

## Intuition & Mathematical Observation
The problem describes a sequence where each term is defined as $a_{n+1} = \lfloor a_n / K \rfloor$, starting with $a_1 = E$. We need to find the count of terms such that $a_i > 0$.

Since $K \ge 2$, the energy value decreases exponentially. Even for the largest possible input ($E = 10^9, K = 2$), the value reaches zero very quickly. Specifically, the number of levels is approximately $\log_K(E)$. For $E = 10^9$ and $K = 2$, $\log_2(10^9) \approx 30$. This allows us to simply simulate the process using a `while` loop without worrying about time limit constraints.

## Complexity Analysis
- **Time Complexity**: $O(T \cdot \log_K(E))$, where $T$ is the number of test cases. Given the constraints, this is effectively $O(T \cdot 30)$, which easily passes within the time limit.
- **Space Complexity**: $O(1)$, as we only use a few variables to track the current energy and the level count.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given an initial energy E and a reduction factor K.
 * The energy at each subsequent level is floor(current_energy / K).
 * We need to find the number of levels that have non-zero energy.
 * 
 * Level 1: E
 * Level 2: floor(E / K)
 * Level 3: floor(floor(E / K) / K)
 * ... and so on.
 * 
 * Since E can be up to 10^9 and K is at least 2, the energy decreases 
 * exponentially. The number of levels will be logarithmic with respect to E, 
 * specifically O(log_K(E)). For E = 10^9 and K = 2, log2(10^9) is approx 30.
 * This is well within the time limit for 10^4 test cases.
 */

void solve() {
    long long E, K;
    if (!(cin >> E >> K)) return;
    
    int count = 0;
    // Simulate the food chain levels
    while (E > 0) {
        count++;
        E = E / K; // Integer division performs the floor operation
    }
    cout << count << "\n";
}

int main() {
    // Fast I/O setup for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}
```