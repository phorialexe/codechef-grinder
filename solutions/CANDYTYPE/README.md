# [Candy Types (CANDYTYPE)](https://www.codechef.com/problems/CANDYTYPE)

- **Difficulty Rating**: 723
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an array of $N$ integers representing the colors of $N$ candies, identify the color that appears most frequently. If multiple colors have the same maximum frequency, choose the one with the smallest numerical value.

## Intuition & Mathematical Observation
Since the constraints are small ($N \le 100$ and $A_i \le N$), we can use a **Frequency Array** (or Hash Map) to count the occurrences of each color.

1. **Counting**: We iterate through the input array and increment the count for each color in a frequency array `freq` of size $N+1$.
2. **Finding the Maximum**: We iterate through the `freq` array from index $1$ to $N$. 
3. **Tie-breaking**: By iterating from the smallest color index to the largest, we only update our `best_color` variable if we find a frequency strictly greater than the current `max_freq`. This ensures that if two colors have the same frequency, the one encountered first (the smaller index) remains the `best_color`.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the number of candies. We perform one pass to count frequencies and one pass to find the maximum.
- **Space Complexity**: $O(N)$ to store the frequency counts of the colors.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given N candies with colors A_1, ..., A_N.
 * We need to find the color that appears most frequently.
 * If there is a tie in frequency, we choose the smallest color value.
 * 
 * Constraints:
 * T <= 100, N <= 100, A_i <= N.
 * Since N is small (up to 100), we can use a frequency array of size N+1.
 */

void solve() {
    int N;
    if (!(cin >> N)) return;
    
    // Frequency array to store counts of each color
    vector<int> freq(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        int color;
        cin >> color;
        if (color >= 1 && color <= N) {
            freq[color]++;
        }
    }
    
    int max_freq = -1;
    int best_color = 1;
    
    // Iterate from 1 to N to find the most frequent color.
    // Using '>' ensures that we keep the smallest color in case of a tie.
    for (int i = 1; i <= N; ++i) {
        if (freq[i] > max_freq) {
            max_freq = freq[i];
            best_color = i;
        }
    }
    
    cout << best_color << "\n";
}

int main() {
    // Fast I/O for performance
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