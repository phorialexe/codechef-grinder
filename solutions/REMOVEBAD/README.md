# [Remove Bad elements (REMOVEBAD)](https://www.codechef.com/problems/REMOVEBAD)

- **Difficulty Rating**: 1100
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an array of $N$ integers, we want to make all elements in the array equal by performing the minimum number of operations. In one operation, we can remove any element from the array. The goal is to find the minimum number of removals required to ensure all remaining elements are identical.

## Intuition & Mathematical Observation
To minimize the number of removals, we must maximize the number of elements we keep. If we decide to make all elements equal to some value $X$, we should keep all occurrences of $X$ currently present in the array and remove everything else.

1. Let the frequency of an element $X$ in the array be $freq(X)$.
2. If we choose to keep all instances of $X$, the number of elements remaining will be $freq(X)$.
3. The number of removals required would be $N - freq(X)$.
4. To minimize $N - freq(X)$, we must maximize $freq(X)$.

Therefore, the problem reduces to finding the frequency of the most frequent element (the mode) in the array and subtracting that frequency from the total number of elements $N$.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the number of elements in the array. We iterate through the array once to count frequencies and track the maximum.
- **Space Complexity**: $O(N)$ to store the frequency counts of the elements in a frequency array (or hash map).

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * To make all elements in an array the same with the minimum number of operations,
 * we need to keep the maximum number of occurrences of any single element 
 * present in the array and remove all other elements.
 * 
 * If the most frequent element appears 'max_freq' times in an array of size N,
 * we keep those 'max_freq' elements and remove the remaining (N - max_freq) elements.
 * 
 * Time Complexity: O(N) per test case to count frequencies.
 * Space Complexity: O(N) to store frequencies.
 */

void solve() {
    int N;
    cin >> N;
    
    // Using a vector to store frequencies. 
    // Since 1 <= A_i <= N, a vector of size N+1 is sufficient.
    vector<int> freq(N + 1, 0);
    int max_freq = 0;
    
    for (int i = 0; i < N; ++i) {
        int val;
        cin >> val;
        freq[val]++;
        if (freq[val] > max_freq) {
            max_freq = freq[val];
        }
    }
    
    // The minimum operations required is total elements minus the count of the most frequent element.
    cout << (N - max_freq) << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    
    return 0;
}
```