# [Pseudo Sorted Array (PSEUDOSORT)](https://www.codechef.com/problems/PSEUDOSORT)

- **Difficulty Rating**: 1067
- **Solved in**: 1 attempt(s)

## Problem Summary
The task is to determine if an array can be sorted in non-decreasing order by performing **at most one** swap of adjacent elements. An array is considered "pseudo-sorted" if it is already sorted or if it becomes sorted after swapping exactly one pair of adjacent elements $(A[i], A[i+1])$.

## Intuition & Mathematical Observation
1. **Already Sorted**: If the array is already sorted, the condition is satisfied immediately.
2. **The First Inversion**: If the array is not sorted, there must exist at least one index $i$ such that $A[i] > A[i+1]$. 
3. **The Swap Strategy**: Since we are allowed only one adjacent swap, if the array is not sorted, the *only* possible swap that could fix the array is the one that resolves the first inversion we encounter. If we swap $A[i]$ and $A[i+1]$ at the first index where $A[i] > A[i+1]$ and the array remains unsorted, then no other single adjacent swap can possibly sort the array.
4. **Validation**: After performing the swap at the first inversion point, we simply perform a linear scan to verify if the array is now sorted.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the size of the array. We iterate through the array at most twice (once to find the inversion and once to verify the sorted property).
- **Space Complexity**: $O(N)$ to store the array elements.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * An array is pseudo-sorted if it is already sorted or can be sorted by 
 * swapping exactly one adjacent pair (A[i], A[i+1]).
 * 
 * Strategy:
 * 1. Check if the array is already sorted. If yes, return YES.
 * 2. If not, find the first index 'i' where A[i] > A[i+1].
 * 3. Perform the swap at this index.
 * 4. Check if the resulting array is sorted.
 * 5. If it is, return YES, otherwise return NO.
 */

bool isSorted(const vector<long long>& a) {
    int n = a.size();
    for (int i = 0; i < n - 1; ++i) {
        if (a[i] > a[i + 1]) return false;
    }
    return true;
}

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // Check if already sorted
    if (isSorted(a)) {
        cout << "YES" << "\n";
        return;
    }

    // Find the first inversion
    int idx = -1;
    for (int i = 0; i < n - 1; ++i) {
        if (a[i] > a[i + 1]) {
            idx = i;
            break;
        }
    }

    // Swap the adjacent elements at the first inversion
    if (idx != -1) {
        swap(a[idx], a[idx + 1]);
    }

    // Check if sorted after the swap
    if (isSorted(a)) {
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