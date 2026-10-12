#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given two arrays A (size N) and B (size M).
 * We need to find the number of pairs (A_i, B_j) such that B_j < A_i.
 * 
 * Constraints:
 * N, M <= 100
 * A_i, B_i <= 100
 * 
 * Since N and M are small (up to 100), an O(N * M) approach per test case
 * is perfectly efficient. Total complexity O(T * N * M) = 100 * 100 * 100 = 10^6,
 * which easily fits within the 1s time limit.
 */

void solve() {
    int N, M;
    if (!(cin >> N >> M)) return;
    
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    vector<int> B(M);
    for (int i = 0; i < M; ++i) {
        cin >> B[i];
    }
    
    long long count = 0;
    // Iterate through every pair (A_i, B_j)
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            // Check the constraint: second layer (B_j) < first layer (A_i)
            if (B[j] < A[i]) {
                count++;
            }
        }
    }
    
    cout << count << "\n";
}

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        solve();
    }
    
    return 0;
}