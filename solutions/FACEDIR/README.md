# [Find the Direction (FACEDIR)](https://www.codechef.com/problems/FACEDIR)

- **Difficulty Rating**: 880
- **Solved in**: 3 attempt(s)

## Problem Summary
Chef starts facing **North**. Every second, he turns 90 degrees clockwise. Given an integer $X$ representing the number of seconds passed, we need to determine the direction Chef is facing after $X$ seconds.

## Intuition & Mathematical Observation
The directions follow a cyclic pattern of length 4:
1. **0 seconds**: North
2. **1 second**: East
3. **2 seconds**: South
4. **3 seconds**: West
5. **4 seconds**: North (cycle repeats)

Since the cycle repeats every 4 seconds, the direction at any time $X$ is determined by the remainder of $X$ divided by 4 ($X \pmod 4$). 

- If $X \pmod 4 = 0$, Chef is facing **North**.
- If $X \pmod 4 = 1$, Chef is facing **East**.
- If $X \pmod 4 = 2$, Chef is facing **South**.
- If $X \pmod 4 = 3$, Chef is facing **West**.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the modulo operation and conditional checks are constant time operations. Total time complexity is $O(T)$ for $T$ test cases.
- **Space Complexity**: $O(1)$, as we only use a few integer variables regardless of the input size.

## Solution Code

```cpp
#include <iostream>
#include <vector>
#include <string>

using namespace std;

/**
 * Problem Analysis:
 * Chef starts at North.
 * 0 seconds: North
 * 1 second: East
 * 2 seconds: South
 * 3 seconds: West
 * 4 seconds: North (cycle repeats every 4 seconds)
 * 
 * The direction is determined by X % 4.
 */

void solve() {
    int x;
    if (!(cin >> x)) return;
    
    int direction = x % 4;
    
    // Mapping the remainder to the corresponding direction
    if (direction == 0) {
        cout << "North" << "\n";
    } else if (direction == 1) {
        cout << "East" << "\n";
    } else if (direction == 2) {
        cout << "South" << "\n";
    } else {
        cout << "West" << "\n";
    }
}

int main() {
    // Optimize I/O operations for faster execution
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    
    return 0;
}
```