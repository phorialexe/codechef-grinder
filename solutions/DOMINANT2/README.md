# [Dominant Element (DOMINANT2)](https://www.codechef.com/problems/DOMINANT2)

- **Difficulty Rating**: 1171
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an array of $N$ integers, determine if there exists a "dominant" element. An element is defined as dominant if its frequency (the number of times it appears in the array) is strictly greater than the frequency of any other element present in the array.

## Intuition & Mathematical Observation
To determine if a dominant element exists, we need to compare the frequencies of all unique elements:

1. **Frequency Counting**: First, we count how many times each distinct number appears in the array. A `std::map` or a frequency array is ideal for this.
2. **Sorting**: Once we have the frequencies, we only care about the values of these frequencies. If we sort these frequencies in descending order, let the sorted frequencies be $f_1, f_2, f_3, \dots, f_k$, where $f_1$ is the maximum frequency.
3. **Condition**: 
   - If there is only one unique element ($k=1$), it is automatically dominant.
   - If there are multiple unique elements, the element with the highest frequency ($f_1$) is dominant if and only if $f_1 > f_2$ (where $f_2$ is the second-highest frequency). If $f_1 = f_2$, then there is no single element that appears more frequently than all others, so no dominant element exists.

## Complexity Analysis
- **Time Complexity**: $O(N \log N)$ or $O(N \log K)$, where $N$ is the number of elements and $K$ is the number of unique elements. This is due to the map insertion or the sorting step. Given the constraints, this is well within the time limit.
- **Space Complexity**: $O(K)$, where $K$ is the number of unique elements stored in the map and the frequency vector. In the worst case, $K = N$.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * An element is dominant if its frequency is strictly greater than the frequency 
 * of any other element in the array.
 * 
 * Strategy:
 * 1. Count the frequency of each element in the array.
 * 2. Store these frequencies in a collection (e.g., a vector or map).
 * 3. Sort the frequencies in descending order.
 * 4. If the highest frequency is strictly greater than the second-highest frequency,
 *    then a dominant element exists.
 * 5. Special case: If there is only one unique element, it is dominant by default.
 */

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, int> freq;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        freq[a[i]]++;
    }

    // Extract frequencies into a vector
    vector<int> counts;
    for (auto const& [val, count] : freq) {
        counts.push_back(count);
    }

    // If there's only one unique element, it's dominant
    if (counts.size() == 1) {
        cout << "YES" << "\n";
        return;
    }

    // Sort frequencies in descending order
    sort(counts.rbegin(), counts.rend());

    // Check if the largest frequency is strictly greater than the second largest
    if (counts[0] > counts[1]) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
```