#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Let a subset of legs have strengths {S_1, S_2, ..., S_k}.
 * Let the minimum strength in this subset be S_min.
 * If we use these k legs, the weight W distributed to each leg is W/k.
 * To prevent any leg from breaking, we must have W/k <= S_i for all i.
 * This is equivalent to W/k <= S_min, or W <= k * S_min.
 * 
 * To maximize W for a fixed S_min, we should include all legs that have 
 * strength >= S_min. If we sort the strengths in non-decreasing order:
 * W_1 <= W_2 <= ... <= W_N
 * If we pick W_i as the minimum strength, the number of legs with strength >= W_i
 * is (N - i + 1).
 * Thus, the maximum weight for a fixed minimum strength W_i is (N - i + 1) * W_i.
 * 
 * We iterate through all sorted strengths and calculate (N - i + 1) * W_i,
 * taking the maximum over all i.
 */

void solve() {
    int n;
    if (!(cin >> n)) return;
    vector<long long> w(n);
    for (int i = 0; i < n; ++i) {
        cin >> w[i];
    }
    
    // Sort the strengths to easily count how many legs have strength >= W_i
    sort(w.begin(), w.end());
    
    long long max_weight = 0;
    for (int i = 0; i < n; ++i) {
        // Number of legs with strength >= w[i] is (n - i)
        long long current_weight = w[i] * (n - i);
        if (current_weight > max_weight) {
            max_weight = current_weight;
        }
    }
    
    cout << max_weight << "\n";
}

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}