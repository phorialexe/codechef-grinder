# [Nearest Court (NEARESTCOURT)](https://www.codechef.com/problems/NEARESTCOURT)

- **Difficulty Rating**: 819
- **Solved in**: 1 attempt(s)

## Problem Summary
Given two points $X$ and $Y$ on a number line representing the locations of Chef and Chefina, we need to find a location $Z$ for a court such that the maximum distance either person has to travel to reach $Z$ is minimized. In other words, we want to minimize $\max(|X - Z|, |Y - Z|)$.

## Intuition & Mathematical Observation
Let $D = |X - Y|$ be the total distance between Chef and Chefina. 

1. If we place the court exactly at the midpoint, the distance each person travels is $D/2$.
2. If $D$ is even, the midpoint is an integer, and the maximum distance is exactly $D/2$.
3. If $D$ is odd, the midpoint is a ".5" value. Since the court must be at an integer coordinate, we must choose either the integer floor or ceiling of the midpoint. In this case, one person will travel $\lfloor D/2 \rfloor$ and the other will travel $\lceil D/2 \rceil$. The maximum of these two is $\lceil D/2 \rceil$.

Both cases can be unified using the formula for ceiling division: $\lceil D/2 \rceil$. In integer arithmetic, this is efficiently calculated as `(D + 1) / 2`.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the calculation involves only basic arithmetic operations. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have two points X and Y on a number line. We want to find a point Z such that
 * max(|X - Z|, |Y - Z|) is minimized.
 * 
 * Let D = |X - Y|. The midpoint between X and Y is (X + Y) / 2.
 * If we choose Z to be the midpoint, the distance for both is D / 2.
 * 
 * If D is even, the midpoint is an integer, and the distance is D / 2.
 * If D is odd, the midpoint is X.5, so we choose either floor(midpoint) or ceil(midpoint).
 * In this case, one person travels (D-1)/2 and the other travels (D+1)/2.
 * The maximum of these is (D+1)/2.
 * 
 * This can be summarized as ceil(D / 2.0), which is equivalent to (D + 1) / 2 using integer division.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long x, y;
        cin >> x >> y;
        
        // Calculate the absolute distance between X and Y
        long long diff = abs(x - y);
        
        // The minimum maximum distance is ceil(diff / 2.0)
        // Using integer arithmetic: (diff + 1) / 2
        long long result = (diff + 1) / 2;
        
        cout << result << "\n";
    }
    
    return 0;
}
```