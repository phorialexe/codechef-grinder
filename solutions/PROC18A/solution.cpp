#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: The Great Run
 * Approach: Sliding Window / Prefix Sum
 * Since N is small (up to 100), we can iterate through all possible 
 * continuous stretches of length K and find the maximum sum.
 * Time Complexity: O(T * N)
 * Space Complexity: O(N)
 */

void solve() {
    int N, K;
    if (!(cin >> N >> K)) return;
    
    vector<int> a(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }
    
    // Calculate the sum of the first window of size K
    long long current_sum = 0;
    for (int i = 0; i < K; ++i) {
        current_sum += a[i];
    }
    
    long long max_girls = current_sum;
    
    // Slide the window across the array
    for (int i = K; i < N; ++i) {
        current_sum = current_sum - a[i - K] + a[i];
        if (current_sum > max_girls) {
            max_girls = current_sum;
        }
    }
    
    cout << max_girls << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}