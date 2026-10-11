# [Sticks (STICKS)](https://www.codechef.com/problems/STICKS)

- **Difficulty Rating**: 1261
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an array of $N$ sticks with various lengths, the goal is to form a rectangle using four of these sticks. A rectangle requires two pairs of equal-length sticks (e.g., two sticks of length $a$ and two sticks of length $b$). The objective is to maximize the area of the rectangle, calculated as $a \times b$. If it is impossible to form a rectangle, output -1.

## Intuition & Mathematical Observation
To maximize the area $a \times b$, we need to select the two largest possible pairs of sticks available in the input. 

1. **Sorting**: By sorting the stick lengths in descending order, we ensure that the first pair we encounter is the largest possible side ($a$), and the next pair we encounter is the second largest possible side ($b$).
2. **Greedy Approach**: 
   - Iterate through the sorted array.
   - When we find two adjacent elements that are equal (`a[i] == a[i+1]`), we have found a pair.
   - We store the first pair found as `side1`.
   - We continue searching for the next pair to store as `side2`.
   - Once both `side1` and `side2` are found, we stop, as any subsequent pairs would result in a smaller or equal area.
3. **Edge Cases**: If we finish iterating through the array and have not found at least two pairs, it is impossible to form a rectangle, so we return -1.

## Complexity Analysis
- **Time Complexity**: $O(N \log N)$ due to the sorting step. The subsequent linear scan takes $O(N)$, making the overall complexity dominated by the sort.
- **Space Complexity**: $O(N)$ to store the input array of stick lengths.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * To form a rectangle, we need two pairs of equal length sticks.
 * Let the lengths of the two pairs be 'a' and 'b'.
 * The area of the rectangle will be a * b.
 * To maximize the area, we need to pick the two largest possible pairs available.
 */

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // Sort in descending order to find the largest pairs first
    sort(a.rbegin(), a.rend());

    long long side1 = -1;
    long long side2 = -1;

    for (int i = 0; i < n - 1; ++i) {
        if (a[i] == a[i + 1]) {
            if (side1 == -1) {
                side1 = a[i];
                // Skip the next element as it's part of the pair
                i++;
            } else {
                side2 = a[i];
                break;
            }
        }
    }

    if (side1 != -1 && side2 != -1) {
        cout << side1 * side2 << "\n";
    } else {
        cout << -1 << "\n";
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