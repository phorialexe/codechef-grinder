#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given N seats with costs A_i.
 * A binary string S tells us which seats are available (S_i == '0').
 * We need to select K seats from the available ones such that the total cost is minimized.
 * 
 * Strategy:
 * 1. Identify all available seats (where S_i == '0').
 * 2. Store the costs of these available seats in a list.
 * 3. If the number of available seats is less than K, output -1.
 * 4. Otherwise, sort the costs of available seats in non-decreasing order.
 * 5. Sum the first K costs and output the result.
 * 
 * Complexity:
 * Time: O(T * N log N) due to sorting. Given N <= 100, this is well within the 1s limit.
 * Space: O(N) to store the costs.
 */

void solve() {
    int N, K;
    cin >> N >> K;
    
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    string S;
    cin >> S;
    
    vector<int> available_costs;
    for (int i = 0; i < N; ++i) {
        if (S[i] == '0') {
            available_costs.push_back(A[i]);
        }
    }
    
    if (available_costs.size() < (size_t)K) {
        cout << -1 << "\n";
    } else {
        sort(available_costs.begin(), available_costs.end());
        long long min_cost = 0;
        for (int i = 0; i < K; ++i) {
            min_cost += available_costs[i];
        }
        cout << min_cost << "\n";
    }
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