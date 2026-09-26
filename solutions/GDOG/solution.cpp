#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Tuzik has N coins and can choose between 1 and K people.
 * When he chooses 'i' people (where 1 <= i <= K), the number of coins 
 * left for Tuzik is N % i.
 * We need to find the maximum value of (N % i) for all 1 <= i <= K.
 * 
 * Constraints:
 * T <= 50
 * N, K <= 10^5
 * 
 * Complexity:
 * A simple loop from 1 to K for each test case results in O(T * K) complexity.
 * With T=50 and K=10^5, total operations are ~5 * 10^6, which fits well 
 * within the 1s time limit.
 */

void solve() {
    long long N, K;
    if (!(cin >> N >> K)) return;

    long long max_coins = 0;
    
    // Iterate through all possible number of people from 1 to K
    // and find the maximum remainder N % i.
    for (long long i = 1; i <= K; ++i) {
        long long remainder = N % i;
        if (remainder > max_coins) {
            max_coins = remainder;
        }
    }
    
    cout << max_coins << "\n";
}

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}