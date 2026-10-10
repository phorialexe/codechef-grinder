#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have sticks of various heights. In one operation, we choose a height H
 * and cut all sticks taller than H down to H.
 * The condition "All the upper parts of sticks that are cut in one operation 
 * must have equal lengths" implies that if we choose a height H, all sticks 
 * currently having height > H must have the same height, say X. 
 * Then the cut length is X - H.
 * 
 * Effectively, each operation reduces the set of unique positive heights by one.
 * If we have a set of unique positive heights {h1, h2, ..., hk} sorted 
 * such that 0 < h1 < h2 < ... < hk, we can perform an operation at H = h_{k-1} 
 * to reduce all sticks of height hk to h_{k-1}.
 * 
 * Thus, the minimum number of operations required is simply the number of 
 * unique positive heights present in the initial array. If a stick has height 0, 
 * it does not need to be cut.
 * 
 * Complexity:
 * Time: O(N log N) per test case due to sorting or O(N) using a hash set.
 * Given N=10^5 and T=50, O(N log N) is well within the 2s time limit.
 * Space: O(N) to store the stick heights.
 */

void solve() {
    int N;
    cin >> N;
    vector<long long> A(N);
    set<long long> unique_heights;
    
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        if (A[i] > 0) {
            unique_heights.insert(A[i]);
        }
    }
    
    // The number of operations is equal to the number of unique positive heights.
    cout << unique_heights.size() << "\n";
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