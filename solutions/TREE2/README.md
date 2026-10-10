# [A Problem on Sticks (TREE2)](https://www.codechef.com/problems/TREE2)

- **Difficulty Rating**: 1199
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given $N$ sticks with various heights. In a single operation, we can choose a height $H$ and cut all sticks that are taller than $H$ down to height $H$. The goal is to find the minimum number of operations required to make all sticks have a height of 0.

## Intuition & Mathematical Observation
The key observation is to realize what happens when we perform an operation at height $H$. By choosing $H$ equal to the height of one of the existing sticks, we effectively reduce all sticks taller than $H$ to height $H$. 

If we sort the unique positive heights of the sticks as $0 < h_1 < h_2 < \dots < h_k$:
1. We can pick $H = h_{k-1}$ to reduce all sticks of height $h_k$ to $h_{k-1}$.
2. We repeat this process until all sticks are reduced to 0.
3. Sticks that already have a height of 0 do not require any operations.

Therefore, each unique positive height in the input array corresponds to exactly one operation. If there are $k$ unique positive heights, we need exactly $k$ operations to reduce all sticks to 0. Using a `std::set` in C++ is an efficient way to count these unique positive values.

## Complexity Analysis
- **Time Complexity**: $O(N \log N)$ per test case. Inserting $N$ elements into a `std::set` takes $O(N \log N)$ time. Given $N \le 10^5$ and $T \le 50$, this approach comfortably fits within the 2-second time limit.
- **Space Complexity**: $O(N)$ to store the unique heights in the set.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The minimum number of operations required is equal to the number of 
 * unique positive heights present in the initial array. 
 * Sticks with height 0 are already "cut" and do not contribute to the count.
 */

void solve() {
    int N;
    cin >> N;
    
    // Using a set to store only unique positive heights
    set<long long> unique_heights;
    
    for (int i = 0; i < N; ++i) {
        long long h;
        cin >> h;
        if (h > 0) {
            unique_heights.insert(h);
        }
    }
    
    // The number of operations is equal to the number of unique positive heights.
    cout << unique_heights.size() << "\n";
}

int main() {
    // Fast I/O for performance
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