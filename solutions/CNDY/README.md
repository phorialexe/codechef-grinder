# [Candies (CNDY)](https://www.codechef.com/problems/CNDY)

- **Difficulty Rating**: 1018
- **Solved in**: 2 attempt(s)

## Problem Summary
We are given an array containing $2N$ integers. The goal is to determine if it is possible to partition these $2N$ integers into two separate arrays (each of size $N$) such that every element within each individual array is unique.

## Intuition & Mathematical Observation
To satisfy the condition that each of the two resulting arrays contains only distinct elements, no single value can appear more than once in the same array. 

Since we are splitting the total collection of $2N$ elements into two groups, any specific value $X$ can appear at most once in the first array and at most once in the second array. Therefore, if a value $X$ appears more than twice in the original input, it is mathematically impossible to distribute those instances without placing at least two of them into the same array.

**The condition for "Yes" is:**
- Every distinct number in the input must appear at most 2 times.

If any number appears 3 or more times, the answer is "No".

## Complexity Analysis
- **Time Complexity**: $O(N \log N)$ or $O(N)$ depending on the implementation. Using a `std::map` as shown in the code results in $O(N \log K)$ where $K$ is the number of unique elements. Given the constraints, this is well within the time limit.
- **Space Complexity**: $O(N)$ to store the frequency counts of the elements in the map.

## Solution Code

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

/**
 * Problem Analysis:
 * We are given 2N integers. We need to split them into two arrays of size N
 * such that each array contains distinct elements.
 * This is possible if and only if no element appears more than twice in the 
 * original array. If an element appears 3 or more times, it's impossible to 
 * distribute them into two sets without having a duplicate in at least one.
 */

void solve() {
    int n;
    cin >> n;
    int total_elements = 2 * n;
    map<int, int> counts;
    bool possible = true;

    for (int i = 0; i < total_elements; ++i) {
        int a;
        cin >> a;
        counts[a]++;
        // If any element appears more than twice, it's impossible
        if (counts[a] > 2) {
            possible = false;
        }
    }

    if (possible) {
        cout << "Yes" << "\n";
    } else {
        cout << "No" << "\n";
    }
}

int main() {
    // Fast I/O setup for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }

    return 0;
}
```