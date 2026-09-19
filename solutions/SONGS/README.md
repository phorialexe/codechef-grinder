# [Playlist (SONGS)](https://www.codechef.com/problems/SONGS)

- **Difficulty Rating**: 489
- **Solved in**: 1 attempt(s)

## Problem Summary
You are given a playlist consisting of three songs (A, B, and C), each with a duration of $X$ minutes. The songs play in a repeating loop: A, B, C, A, B, C, and so on. Given a total listening time of $N$ minutes, calculate how many times song C is played completely.

## Intuition & Mathematical Observation
1. **Cycle Analysis**: The playlist repeats every 3 songs. Since each song lasts $X$ minutes, one full cycle (A $\rightarrow$ B $\rightarrow$ C) takes $3 \times X$ minutes.
2. **Song C's Position**: Song C is the final song in every 3-song cycle. Therefore, every time a full cycle of $3 \times X$ minutes is completed, song C has been played exactly once.
3. **Calculation**: To find the total number of times song C is completed, we simply need to determine how many full cycles of $3 \times X$ fit into the total time $N$. This is calculated using integer division:
   $$\text{Result} = \lfloor \frac{N}{3 \times X} \rfloor$$

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution involves a single arithmetic operation. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Each song has a duration of X minutes.
 * The playlist consists of 3 songs: A, B, C.
 * The total duration of one full cycle (A -> B -> C) is 3 * X.
 * 
 * To find how many times song C is listened to completely:
 * 1. Calculate the total number of full songs listened to: N / X.
 * 2. In every cycle of 3 songs, song C is the 3rd song.
 * 3. The number of full cycles completed is (N / X) / 3.
 * 4. This is equivalent to floor(N / (3 * X)).
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long n, x;
        cin >> n >> x;

        // Total duration of one full loop of A, B, C is 3 * X.
        // The number of times the full sequence A, B, C is completed
        // is the number of times song C is completed.
        // Each full sequence takes 3 * X minutes.
        long long full_cycles = n / (3 * x);

        cout << full_cycles << "\n";
    }

    return 0;
}
```