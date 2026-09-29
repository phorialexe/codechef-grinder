# [Coronavirus Spread (COVID19)](https://www.codechef.com/problems/COVID19)

- **Difficulty Rating**: 1219
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given $N$ people standing at various positions on a line. A virus spreads between two people if the distance between them is at most 2 units. This infection is transitive: if person A infects person B, and person B infects person C, then person C also becomes infected. We need to find the minimum and maximum number of people that could be infected if the virus starts with exactly one person.

## Intuition & Mathematical Observation
Since the positions are given in increasing order, the people form a sequence. The condition "distance $\le 2$" implies that if we sort the people by position, the infection will spread to a contiguous block of people. 

For any person $i$ chosen as the "patient zero," the virus will spread to all neighbors $j$ such that the gap between any two adjacent people in the chain is $\le 2$. 
1. We can treat the array of positions as a sequence where a "break" in the chain occurs only if $X_{i+1} - X_i > 2$.
2. By iterating through each person as the starting point, we can expand to the left and right until the distance condition is violated.
3. The size of the connected component containing person $i$ represents the total number of infected people if $i$ is the source.
4. We track the minimum and maximum sizes of these components across all possible starting positions.

## Complexity Analysis
- **Time Complexity**: $O(N^2)$ in the worst case (or $O(N)$ if optimized to pre-calculate segments). Given $N \le 8$ (or even up to $10^5$ in similar problems), this approach is highly efficient. In this specific implementation, for each of the $N$ people, we traverse the array, resulting in $O(N^2)$.
- **Space Complexity**: $O(N)$ to store the positions of the people.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given N people at positions X_1, X_2, ..., X_N.
 * The virus spreads if the distance between two people is <= 2.
 * This is a transitive property: if A infects B, and B infects C, then A infects C.
 * For each person i, we can simulate the spread by checking adjacent people.
 */

void solve() {
    int N;
    cin >> N;
    vector<int> X(N);
    for (int i = 0; i < N; ++i) {
        cin >> X[i];
    }

    int min_infected = N;
    int max_infected = 1;

    // Try each person as the initial infected person
    for (int i = 0; i < N; ++i) {
        int current_infected = 1;
        
        // Look to the right
        int temp = i;
        while (temp + 1 < N && X[temp + 1] - X[temp] <= 2) {
            current_infected++;
            temp++;
        }
        
        // Look to the left
        temp = i;
        while (temp - 1 >= 0 && X[temp] - X[temp - 1] <= 2) {
            current_infected++;
            temp--;
        }
        
        if (current_infected < min_infected) {
            min_infected = current_infected;
        }
        if (current_infected > max_infected) {
            max_infected = current_infected;
        }
    }

    cout << min_infected << " " << max_infected << "\n";
}

int main() {
    // Optimize I/O operations
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