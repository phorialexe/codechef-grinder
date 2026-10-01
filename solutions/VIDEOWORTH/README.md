# [Worth of a Video (VIDEOWORTH)](https://www.codechef.com/problems/VIDEOWORTH)

- **Difficulty Rating**: 382
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to calculate the total "worth" of a video given its duration in seconds ($S$). We are provided with two constants:
1. The video plays at a rate of **24 frames per second**.
2. Each individual frame is worth **1000 words**.

We need to output the total number of words in the video for a given duration $S$.

## Intuition & Mathematical Observation
To find the total worth, we can break the calculation into two simple steps:
1. **Calculate total frames**: Since there are 24 frames in every second, a video of $S$ seconds contains $S \times 24$ frames.
2. **Calculate total worth**: Since each frame is worth 1000 words, we multiply the total number of frames by 1000.

**Mathematical Formula:**
$$\text{Total Worth} = S \times 24 \times 1000 = S \times 24,000$$

Given the constraints ($S \le 100$), the maximum possible result is $100 \times 24,000 = 2,400,000$, which fits well within a standard 32-bit integer. Using `long long` is a safe practice to prevent overflow in similar problems with larger constraints.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a constant time $O(1)$ arithmetic operation.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * - Frames per second = 24
 * - Worth per frame = 1000 words
 * - Duration = S seconds
 * - Total frames = S * 24
 * - Total worth = (S * 24) * 1000 = S * 24000
 */

int main() {
    // Fast I/O setup for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long s;
        cin >> s;
        
        // Calculate total worth: 24 frames/sec * 1000 words/frame = 24000 words/sec
        long long total_worth = s * 24000;
        
        cout << total_worth << "\n";
    }
    
    return 0;
}
```