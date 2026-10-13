#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have N bags, each with A_i coins (A_i <= X).
 * We can change any A_i to X at a cost of C.
 * We want to maximize (Sum of A_i) - (Total Cost).
 * 
 * For each bag i, if we perform the operation, the net change to the total sum is:
 * (X - A_i) - C.
 * 
 * If (X - A_i) > C, then performing the operation increases the total value.
 * If (X - A_i) <= C, performing the operation either decreases the total value or keeps it the same.
 * 
 * Therefore, for each bag, we should perform the operation if and only if (X - A_i) > C.
 * 
 * Time Complexity: O(N) per test case.
 * Space Complexity: O(1) auxiliary space (if we process input on the fly).
 */

void solve() {
    int N;
    long long X, C;
    cin >> N >> X >> C;
    
    long long total_value = 0;
    for (int i = 0; i < N; ++i) {
        long long A;
        cin >> A;
        
        // Check if performing the operation is beneficial
        // Benefit = (X - A) - C
        // If benefit > 0, we perform the operation.
        if ((X - A) > C) {
            total_value += X - C;
        } else {
            total_value += A;
        }
    }
    
    cout << total_value << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}