#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given N temperatures. We need to find the number of days where the 
 * temperature is strictly greater than the minimum and strictly less than 
 * the maximum temperature of the set.
 * 
 * Algorithm:
 * 1. Find the minimum value (min_val) and maximum value (max_val) in the array.
 * 2. If min_val == max_val, then all days have the same temperature, so no day 
 *    can be strictly between min and max. The answer is 0.
 * 3. Otherwise, iterate through the array and count elements A[i] such that 
 *    min_val < A[i] < max_val.
 * 
 * Time Complexity: O(N) per test case.
 * Space Complexity: O(N) to store the array.
 */

void solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    
    int min_val = 101; // Constraints say A_i <= 100
    int max_val = 0;   // Constraints say A_i >= 1
    
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        if (A[i] < min_val) min_val = A[i];
        if (A[i] > max_val) max_val = A[i];
    }
    
    // If all elements are the same, or there are only 1 or 2 distinct values,
    // there are no elements strictly between min and max.
    if (min_val == max_val) {
        cout << 0 << "\n";
        return;
    }
    
    int count = 0;
    for (int i = 0; i < N; ++i) {
        if (A[i] > min_val && A[i] < max_val) {
            count++;
        }
    }
    
    cout << count << "\n";
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