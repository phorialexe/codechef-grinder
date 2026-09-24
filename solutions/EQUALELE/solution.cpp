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
 * 
 * Time Complexity: O(N) per test case, where N is the size of the array.
 * Space Complexity: O(N) to store the frequencies of elements.
 */

void solve() {
    int N;
    cin >> N;
    
    // Using a map or a frequency array. Since A_i <= N, 
    // a frequency array is efficient.
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
    
    // The minimum operations required is total elements minus the count 
    // of the most frequent element.
    cout << (N - max_freq) << "\n";
}

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    
    return 0;
}