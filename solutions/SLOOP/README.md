# [Coldplay (SLOOP)](https://www.codechef.com/problems/SLOOP)

- **Difficulty Rating**: 854
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef is going on a trip that lasts for $M$ minutes. He wants to listen to a song that lasts for $S$ minutes repeatedly. The goal is to determine the maximum number of times the song can be played completely within the total duration of the trip.

## Intuition & Mathematical Observation
The problem asks for the maximum number of times a song of duration $S$ can fit into a total time $M$. Mathematically, this is a simple division problem. Since we are only interested in **complete** plays of the song, we need to calculate the floor of the division of $M$ by $S$.

In C++, when both operands of the division operator `/` are integers, the result is automatically truncated toward zero (which acts as a floor function for positive integers). Therefore, the expression `M / S` directly provides the required answer.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a single division operation, which takes constant time $O(1)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result, requiring no additional data structures.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef has a trip of duration M minutes.
 * The song has a duration of S minutes.
 * We need to find how many times the song can be played completely within M minutes.
 * This is equivalent to finding the floor of the division M / S.
 * 
 * Constraints:
 * 1 <= T <= 1000
 * 1 <= M <= 100
 * 1 <= S <= 10
 */

int main() {
    // Fast I/O setup for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long m, s;
        cin >> m >> s;
        
        // The number of complete plays is the integer division of M by S.
        // Since M and S are positive, integer division naturally floors the result.
        long long result = m / s;
        
        cout << result << "\n";
    }

    return 0;
}
```