# [Another Card Game Problem (CRDGAME3)](https://www.codechef.com/problems/CRDGAME3)

- **Difficulty Rating**: 1230
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef and Rick are playing a game where they represent their power levels using the minimum number of digits possible. Each digit can have a maximum value of 9. Given Chef's power $P_C$ and Rick's power $P_R$, we need to determine who uses fewer digits to represent their power. If Chef uses fewer digits, he wins. If Rick uses fewer or an equal number of digits, Rick wins. We must output the winner (0 for Chef, 1 for Rick) and the number of digits used by the winner.

## Intuition & Mathematical Observation
To represent a power $P$ using the minimum number of digits, we should maximize the value of each digit (i.e., use as many 9s as possible). 

- The number of digits $D$ required to represent power $P$ is given by the ceiling division: $D = \lceil P / 9 \rceil$.
- In integer arithmetic, $\lceil P / 9 \rceil$ is equivalent to `(P + 8) / 9`.

**Game Logic:**
1. Calculate $D_C = (P_C + 8) / 9$ and $D_R = (P_R + 8) / 9$.
2. According to the rules:
   - If $D_C < D_R$, Chef wins (Output: `0 D_C`).
   - If $D_R \le D_C$, Rick wins (Output: `1 D_R`).

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. Each test case involves simple arithmetic operations performed in $O(1)$ time.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and calculated results.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * To minimize the number of digits for a given power P, a player should use as many 9s as possible.
 * If the power is P, the number of digits required is ceil(P / 9).
 * In integer arithmetic, ceil(P / 9) can be calculated as (P + 8) / 9.
 * 
 * Let D_C be the number of digits for Chef: D_C = (P_C + 8) / 9
 * Let D_R be the number of digits for Rick: D_R = (P_R + 8) / 9
 * 
 * Rules:
 * 1. The player with fewer digits wins.
 * 2. If D_C == D_R, Rick wins (Rick cheats).
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long pc, pr;
        cin >> pc >> pr;

        // Calculate minimum digits required for Chef and Rick
        long long dc = (pc + 8) / 9;
        long long dr = (pr + 8) / 9;

        // Determine winner based on rules
        // If Chef's digits are strictly less than Rick's, Chef wins.
        // Otherwise, Rick wins (either because he has fewer digits or they are equal).
        if (dc < dr) {
            cout << "0 " << dc << "\n";
        } else {
            cout << "1 " << dr << "\n";
        }
    }

    return 0;
}
```