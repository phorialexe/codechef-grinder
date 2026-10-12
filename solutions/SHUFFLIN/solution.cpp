#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * B_i = (A_i + i) % 2
 * We want to maximize the sum of B_i.
 * B_i = 1 if (A_i + i) is odd, which happens if A_i and i have different parities.
 * B_i = 0 if (A_i + i) is even, which happens if A_i and i have the same parity.
 * 
 * Let:
 * odd_pos = number of indices i in [1, N] such that i is odd.
 * even_pos = number of indices i in [1, N] such that i is even.
 * odd_val = number of elements in A that are odd.
 * even_val = number of elements in A that are even.
 * 
 * We want to maximize the number of indices where (A_i + i) is odd.
 * (A_i + i) is odd if:
 * 1. A_i is odd and i is even.
 * 2. A_i is even and i is odd.
 * 
 * Total sum = min(odd_val, even_pos) + min(even_val, odd_pos).
 */

void solve() {
    int N;
    cin >> N;
    
    int odd_val = 0;
    int even_val = 0;
    
    for (int i = 0; i < N; ++i) {
        int a;
        cin >> a;
        if (a % 2 != 0) {
            odd_val++;
        } else {
            even_val++;
        }
    }
    
    // Indices are 1 to N.
    // Odd indices: 1, 3, 5... count is ceil(N/2)
    // Even indices: 2, 4, 6... count is floor(N/2)
    int odd_pos = (N + 1) / 2;
    int even_pos = N / 2;
    
    // We want to place odd values in even positions and even values in odd positions
    // to get a 1 in the resulting array B.
    int result = min(odd_val, even_pos) + min(even_val, odd_pos);
    
    cout << result << "\n";
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