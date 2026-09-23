# [Chef Fantasy 11 (FIZZBUZZ2303)](https://www.codechef.com/problems/FIZZBUZZ2303)

- **Difficulty Rating**: 739
- **Solved in**: 2 attempt(s)

## Problem Summary
Chef needs to select a captain and a vice-captain from a team of $N$ players. Since one player cannot hold both positions, we need to find the total number of distinct ways to assign these two roles.

## Intuition & Mathematical Observation
This is a classic combinatorics problem involving permutations. 
1. **Choosing the Captain**: There are $N$ players available, so there are $N$ possible choices for the captain.
2. **Choosing the Vice-Captain**: Once the captain is chosen, there are $N-1$ players remaining. Thus, there are $N-1$ possible choices for the vice-captain.

By the fundamental counting principle, the total number of ways to choose both is the product of the choices for each position:
$$\text{Total Ways} = N \times (N - 1)$$

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the calculation involves a single multiplication. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <iostream>

using namespace std;

/**
 * Problem Analysis:
 * We need to select 1 captain and 1 vice-captain from N players.
 * The number of ways to choose the captain is N.
 * The number of ways to choose the vice-captain from the remaining players is (N-1).
 * Total ways = N * (N - 1).
 */

void solve() {
    int N;
    if (!(cin >> N)) return;
    
    // Calculate permutations of 2 items from N: P(N, 2) = N * (N - 1)
    int result = N * (N - 1);
    
    cout << result << endl;
}

int main() {
    // Optimize I/O operations for faster execution
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        solve();
    }

    return 0;
}
```