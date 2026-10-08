# [Gun Master (GMGM)](https://www.codechef.com/problems/GMGM)

- **Difficulty Rating**: 783
- **Solved in**: 1 attempt(s)

## Problem Summary
You are given $N$ targets, each at a specific distance from you. You have two types of guns:
1. **Close-range gun**: Effective for targets at a distance $\le D$.
2. **Long-range gun**: Effective for targets at a distance $> D$.

You start with the **close-range gun** equipped. For each target in the given sequence, you must use the appropriate gun. If the required gun is different from the one you are currently holding, you must perform a switch. The goal is to calculate the total number of switches required to clear all targets.

## Intuition & Mathematical Observation
The problem can be modeled as a state-tracking simulation. 
- We maintain a `current_gun` state (0 for close-range, 1 for long-range).
- For every target distance $A_i$, we determine the `required_gun` based on the condition:
    - If $A_i \le D$, `required_gun = 0`.
    - If $A_i > D$, `required_gun = 1`.
- Whenever `current_gun` does not match `required_gun`, we increment the `switches` counter and update `current_gun` to the `required_gun`.
- Since we process each target exactly once in the order they appear, a single pass through the input array is sufficient to determine the total number of switches.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the number of targets. We iterate through the list of targets exactly once.
- **Space Complexity**: $O(1)$ auxiliary space, as we only store a few integer variables regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have two guns:
 * 1. Close-range: distance <= D
 * 2. Long-range: distance > D
 * 
 * Initially, we hold the close-range gun.
 * We need to process targets in order.
 * If the current target requires a gun different from the one we are holding,
 * we must switch.
 */

void solve() {
    int N, D;
    cin >> N >> D;
    
    // current_gun: 0 for close-range, 1 for long-range
    // Initially holding close-range gun
    int current_gun = 0;
    int switches = 0;
    
    for (int i = 0; i < N; ++i) {
        int A;
        cin >> A;
        
        // Determine which gun is needed for the current target
        int required_gun = (A <= D) ? 0 : 1;
        
        // If the required gun is different from the current one, switch
        if (current_gun != required_gun) {
            switches++;
            current_gun = required_gun;
        }
    }
    
    cout << switches << "\n";
}

int main() {
    // Fast I/O for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    
    return 0;
}
```