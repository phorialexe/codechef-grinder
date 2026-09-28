#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * There are N players. When player i is eliminated, A[i] is added to the pool.
 * If we choose player k to be the winner, all players except player k are eliminated.
 * The total prize money won by player k is the sum of A[i] for all i != k.
 * 
 * Let S be the sum of all elements in array A.
 * The prize money for winner k is S - A[k].
 * To maximize this value, we need to minimize A[k].
 * Therefore, the maximum prize is S - min(A).
 * 
 * Constraints:
 * N <= 10^5, A_i <= 10^4.
 * The sum can be up to 10^5 * 10^4 = 10^9, which fits in a 32-bit signed integer,
 * but using long long is safer and good practice for competitive programming.
 */

void solve() {
    int N;
    cin >> N;
    
    long long sum = 0;
    int min_val = 10001; // Since A_i <= 10^4
    
    for (int i = 0; i < N; ++i) {
        int a;
        cin >> a;
        sum += a;
        if (a < min_val) {
            min_val = a;
        }
    }
    
    // The winner gets the sum of all A_i except the one corresponding to the winner.
    // To maximize the prize, we pick the player with the smallest A_i to be the winner.
    cout << (sum - min_val) << "\n";
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