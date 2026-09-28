# [Chess Match (BLITZ3_2)](https://www.codechef.com/problems/BLITZ3_2)

- **Difficulty Rating**: 998
- **Solved in**: 1 attempt(s)

## Problem Summary
In a blitz chess match, each player starts with $180$ seconds (3 minutes) on their clock. The match format is "a + b", where $a$ is the initial time and $b$ is the increment added to the clock after each move. In this specific problem, $a = 3$ minutes and $b = 2$ seconds. Given the total number of moves $N$ played and the remaining time $A$ and $B$ for each player, calculate the total duration of the match in seconds.

## Intuition & Mathematical Observation
To find the total duration of the match, we need to determine how much time was "consumed" by the players.

1.  **Initial Time**: Each player starts with 180 seconds. Therefore, the total starting time for both players combined is $180 + 180 = 360$ seconds.
2.  **Time Increments**: For every move made, 2 seconds are added to the clock of the player who made the move. If $N$ total moves are made in the game, the total time added to the clocks is $2 \times N$ seconds.
3.  **Total Available Time**: The total time available throughout the game is the sum of the initial time and the total increments:
    $$\text{Total Available} = 360 + 2N$$
4.  **Time Elapsed**: The time elapsed (the duration of the match) is the difference between the total time that was available and the time remaining on the clocks ($A + B$):
    $$\text{Duration} = (360 + 2N) - (A + B)$$

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the calculation involves simple arithmetic operations. For $T$ test cases, the complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Each player starts with 3 minutes = 180 seconds.
 * Total time given to both players initially = 180 + 180 = 360 seconds.
 * 
 * In an "a + b" blitz match, each move adds 'b' seconds to the clock.
 * Here, a = 3 minutes (180 seconds) and b = 2 seconds.
 * 
 * After N turns:
 * Total time added to clocks = N * 2 seconds.
 * 
 * Total time available = (Initial time for both) + (Total time added)
 * Total time available = 360 + 2 * N.
 * 
 * Total time elapsed = (Total time available) - (Total time remaining)
 * Total time elapsed = (360 + 2 * N) - (A + B).
 */

int main() {
    // Fast I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long n, a, b;
        cin >> n >> a >> b;

        // Total time available = 2 * 180 (initial) + 2 * N (increments)
        // Total time available = 360 + 2 * N
        long long total_available = 360 + 2 * n;
        long long total_remaining = a + b;
        
        long long duration = total_available - total_remaining;
        
        cout << duration << "\n";
    }

    return 0;
}
```