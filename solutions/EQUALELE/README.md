# [Equal Elements (EQUALELE)](https://www.codechef.com/problems/EQUALELE)

- **Difficulty Rating**: 1123
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an array of $N$ integers, we want to make all elements in the array equal using the minimum number of operations. In one operation, we can choose any index $i$ and change the value of $A[i]$ to any other value. We need to determine the minimum number of operations required to make all elements in the array identical.

## Intuition & Mathematical Observation
To minimize the number of operations, we want to keep as many elements as possible unchanged. If we decide that all elements in the final array will be equal to some value $X$, then the number of operations required is the total number of elements ($N$) minus the number of elements that are already equal to $X$.

To minimize $(N - \text{count}(X))$, we must maximize $\text{count}(X)$. Therefore, the optimal strategy is to:
1. Find the frequency of every element present in the array.
2. Identify the element that appears most frequently (let its frequency be `max_freq`).
3. Keep all instances of this most frequent element and change all other $(N - \text{max_freq})$ elements to match it.

Since the constraints state that $A_i \le N$, we can efficiently track frequencies using a frequency array (or a hash map) of size $N+1$.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the size of the array. We iterate through the array once to count frequencies and find the maximum.
- **Space Complexity**: $O(N)$ to store the frequency counts of the elements.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * To make all elements in an array equal with the minimum number of operations,
 * we should identify the element that appears most frequently in the array.
 * Let the frequency of the most frequent element be 'max_freq'.
 * We keep these 'max_freq' elements as they are and change all other (N - max_freq)
 * elements to match this value.
 * 
 * Each operation allows us to set A[i] = A[j]. By picking the most frequent
 * element as our target value, we minimize the number of changes needed.
 */

void solve() {
    int N;
    cin >> N;
    
    // Using a frequency array. Since A_i <= N, 
    // a frequency array of size N+1 is efficient.
    vector<int> freq(N + 1, 0);
    int max_freq = 0;
    
    for (int i = 0; i < N; ++i) {
        int val;
        cin >> val;
        freq[val]++;
        // Track the highest frequency found so far
        if (freq[val] > max_freq) {
            max_freq = freq[val];
        }
    }
    
    // The minimum operations required is total elements minus the count 
    // of the most frequent element.
    cout << (N - max_freq) << "\n";
}

int main() {
    // Fast I/O setup for performance
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