#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to buy exactly two vases at indices i and j (i != j).
 * If we buy vase i, and then vase i+1, the cost is A[i] + A[i+1]/2.
 * If we buy any other pair (i, j) where j != i+1, the cost is A[i] + A[j].
 * 
 * We need to iterate through all possible pairs (i, j) with 0 <= i < j < N
 * and calculate the cost:
 * If j == i + 1, cost = A[i] + A[j] / 2
 * Else, cost = A[i] + A[j]
 * 
 * We track the minimum cost found.
 * Constraints are small (N <= 100), so an O(N^2) approach is perfectly fine.
 */

void solve() {
    int N;
    cin >> N;
    vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    long long min_cost = -1;

    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            long long current_cost;
            if (j == i + 1) {
                current_cost = A[i] + (A[j] / 2);
            } else {
                current_cost = A[i] + A[j];
            }

            if (min_cost == -1 || current_cost < min_cost) {
                min_cost = current_cost;
            }
        }
    }

    cout << min_cost << "\n";
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