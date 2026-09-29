#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given an array A of size N and can delete at most 2 elements.
 * We want to minimize (max(A) - min(A)).
 * 
 * After sorting the array A in non-decreasing order:
 * Let the sorted array be A[0], A[1], ..., A[N-1].
 * Deleting 2 elements can be done in three ways to minimize the range:
 * 1. Delete the two smallest elements: The range becomes A[N-1] - A[2].
 * 2. Delete the two largest elements: The range becomes A[N-3] - A[0].
 * 3. Delete the smallest and the largest element: The range becomes A[N-2] - A[1].
 * 
 * Since we can delete "at most" two, these three scenarios cover all optimal 
 * strategies for reducing the range by removing elements from the extremes.
 * 
 * Time Complexity: O(N log N) per test case due to sorting.
 * Space Complexity: O(N) to store the array.
 */

void solve() {
    int N;
    cin >> N;
    vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    if (N <= 3) {
        cout << 0 << "\n";
        return;
    }

    sort(A.begin(), A.end());

    // Option 1: Remove two smallest elements
    long long range1 = A[N - 1] - A[2];
    
    // Option 2: Remove two largest elements
    long long range2 = A[N - 3] - A[0];
    
    // Option 3: Remove one smallest and one largest element
    long long range3 = A[N - 2] - A[1];

    long long ans = min({range1, range2, range3});
    cout << ans << "\n";
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