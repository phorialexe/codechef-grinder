#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * f(A) = (A_1 + A_2) + (A_2 + A_3) + ... + (A_{N-1} + A_N)
 * f(A) = A_1 + 2*A_2 + 2*A_3 + ... + 2*A_{N-1} + A_N
 * 
 * To maximize this sum, we want the largest elements to have a coefficient of 2.
 * The two smallest elements should be placed at the ends (A_1 and A_N) so that 
 * they are only counted once. All other N-2 elements will be counted twice.
 * 
 * Let the sorted array be S_1 <= S_2 <= ... <= S_N.
 * The maximum sum is:
 * f(A) = S_1 + S_N + 2 * (S_2 + S_3 + ... + S_{N-1})
 * Alternatively, this is equivalent to:
 * 2 * (sum of all elements) - (S_1 + S_N)
 */

void solve() {
    int N;
    cin >> N;
    vector<long long> A(N);
    long long total_sum = 0;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        total_sum += A[i];
    }
    
    sort(A.begin(), A.end());
    
    // The two smallest elements are A[0] and A[1] after sorting.
    // However, to maximize the sum, we want the two smallest elements 
    // to be at the ends.
    // The formula 2 * sum(A) - (A[0] + A[1]) is incorrect because 
    // we want to subtract the two smallest elements once.
    // Correct logic: 
    // Sum = 2 * (sum of all elements) - (A[0] + A[1])
    // Wait, let's re-verify:
    // f(A) = A_1 + 2*A_2 + 2*A_3 + ... + 2*A_{N-1} + A_N
    // Total sum of all elements = A_1 + A_2 + ... + A_N
    // 2 * Total sum = 2*A_1 + 2*A_2 + ... + 2*A_N
    // 2 * Total sum - (A_1 + A_N) = A_1 + 2*A_2 + ... + 2*A_{N-1} + A_N
    // To maximize this, we need to minimize (A_1 + A_N).
    // Thus, A_1 and A_N should be the two smallest elements in the array.
    
    long long ans = 2 * total_sum - (A[0] + A[1]);
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}