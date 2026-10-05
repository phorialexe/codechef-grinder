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