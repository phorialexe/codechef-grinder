# [The Man Code (MANCODE)](https://www.codechef.com/problems/MANCODE)

- **Difficulty Rating**: 1032
- **Solved in**: 1 attempt(s)

## Problem Summary
Given $N$ urinals in a row, we need to find the maximum and minimum number of people that can occupy these urinals such that no two people are adjacent. 
- **Maximum**: We want to pack as many people as possible without any two being adjacent.
- **Minimum**: We want to place the fewest number of people such that no more people can be added to the row without violating the adjacency rule (i.e., every empty urinal must be adjacent to at least one occupied urinal).

## Intuition & Mathematical Observation

### Maximum Calculation
To maximize the number of people, we should place them in every other urinal starting from the first one (e.g., positions 1, 3, 5, ...). 
- For $N=1$, we place 1 person.
- For $N=2$, we place 1 person.
- For $N=3$, we place 2 people.
- The pattern follows the formula: $\lceil N / 2 \rceil$, which can be implemented in integer arithmetic as `(N + 1) / 2`.

### Minimum Calculation
To minimize the number of people such that no more can be added, we need to ensure that every empty urinal is "covered" by an adjacent person. This means we essentially need to place people such that there are no gaps of size 2 or more between them.
- For $N=1$: 1 person (1)
- For $N=2$: 1 person (0, 1)
- For $N=3$: 1 person (0, 1, 0)
- For $N=4$: 2 people (0, 1, 0, 1)
- For $N=5$: 2 people (0, 1, 0, 1, 0)
- For $N=6$: 2 people (0, 1, 0, 0, 1, 0)
- For $N=7$: 3 people (0, 1, 0, 0, 1, 0, 1)
Observing the sequence: 1, 1, 1, 2, 2, 2, 3, 3, 3... we can see that the value increments every 3 units. This is represented by the formula: `(N + 2) / 3`.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution uses simple arithmetic operations. Total time complexity is $O(T)$, where $T$ is the number of test cases.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and results.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Maximum: To maximize the number of people, we place them at every second urinal.
 * Formula: (N + 1) / 2
 * 
 * Minimum: To minimize the number of people such that no more can be added,
 * we ensure every empty urinal is adjacent to at least one occupied urinal.
 * Formula: (N + 2) / 3
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        int max_people = (n + 1) / 2;
        int min_people = (n + 2) / 3;

        cout << max_people << " " << min_people << "\n";
    }

    return 0;
}
```