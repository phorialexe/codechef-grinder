# [Chef Wars - Return of the Jedi (CHEFWARS)](https://www.codechef.com/problems/CHEFWARS)

- **Difficulty Rating**: -1
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef is fighting Darth Vader. Darth has a health of $H$, and Chef has an initial attack power of $P$. In each round, Chef deals $P$ damage to Darth, and then his attack power is reduced to $\lfloor P/2 \rfloor$. This process repeats until Chef's attack power becomes $0$. We need to determine if the total damage dealt by Chef is greater than or equal to $H$.

## Intuition & Mathematical Observation
The total damage dealt is the sum of the sequence: $P + \lfloor P/2 \rfloor + \lfloor P/4 \rfloor + \dots$ until the term becomes $0$. 

Since the attack power is halved in each step, the number of rounds is very small. For $P \le 10^5$, the number of rounds is approximately $\log_2(10^5) \approx 17$. Because this number is so small, we do not need a closed-form formula or complex series summation; a simple `while` loop simulation is highly efficient and perfectly suited for the constraints.

## Complexity Analysis
- **Time Complexity**: $O(T \times \log P)$, where $T$ is the number of test cases and $P$ is the initial attack power. Given the constraints, this is well within the time limit.
- **Space Complexity**: $O(1)$, as we only use a few variables to track the current power and total damage.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef attacks with power P, then P becomes floor(P/2).
 * This continues until P becomes 0.
 * The total damage dealt is the sum of the geometric series:
 * P + floor(P/2) + floor(P/4) + ... + floor(P/2^k)
 * 
 * Since P <= 10^5, the number of attacks is logarithmic (log2(10^5) approx 17).
 * We can simply simulate the process for each test case.
 * 
 * Time Complexity: O(T * log(P))
 * Space Complexity: O(1)
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long h, p;
        cin >> h >> p;
        
        long long total_damage = 0;
        long long current_p = p;
        
        // Simulate the attacks
        while (current_p > 0) {
            total_damage += current_p;
            current_p /= 2;
        }
        
        // Check if total damage is enough to kill Darth
        if (total_damage >= h) {
            cout << 1 << "\n";
        } else {
            cout << 0 << "\n";
        }
    }
    
    return 0;
}
```