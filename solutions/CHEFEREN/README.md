# [Chef Eren (CHEFEREN)](https://www.codechef.com/problems/CHEFEREN)

- **Difficulty Rating**: 706
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef has $N$ episodes to watch. The episodes are indexed from $1$ to $N$. 
- Every **even-indexed** episode (2, 4, 6, ...) has a duration of $A$ minutes.
- Every **odd-indexed** episode (1, 3, 5, ...) has a duration of $B$ minutes.

The goal is to calculate the total time required to watch all $N$ episodes.

## Intuition & Mathematical Observation
To solve this efficiently, we don't need to iterate through every episode. We can use simple arithmetic:

1. **Count the even episodes**: In the range $[1, N]$, the number of even integers is given by $\lfloor N / 2 \rfloor$.
2. **Count the odd episodes**: The remaining episodes are odd, which is $N - \lfloor N / 2 \rfloor$.
3. **Calculate the total**: Multiply the counts by their respective durations ($A$ for even, $B$ for odd) and sum them up.

**Example**: If $N=3, A=2, B=3$:
- Even episodes: $3 / 2 = 1$ (Episode 2)
- Odd episodes: $3 - 1 = 2$ (Episodes 1 and 3)
- Total: $(1 \times 2) + (2 \times 3) = 2 + 6 = 8$.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the calculation involves only basic arithmetic operations. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have N episodes.
 * Odd-indexed episodes (1, 3, 5, ...) have duration B.
 * Even-indexed episodes (2, 4, 6, ...) have duration A.
 * 
 * Number of even-indexed episodes = floor(N / 2)
 * Number of odd-indexed episodes = N - floor(N / 2)
 * 
 * Total duration = (Number of even episodes * A) + (Number of odd episodes * B)
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n, a, b;
        cin >> n >> a >> b;

        int even_count = n / 2;
        int odd_count = n - even_count;

        // Calculate total duration
        // Using long long to ensure safety, though int is sufficient for N, A, B <= 60
        long long total_duration = (long long)even_count * a + (long long)odd_count * b;

        cout << total_duration << "\n";
    }

    return 0;
}
```