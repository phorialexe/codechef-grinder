#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef has N customers. The i-th customer pays i.
 * Cost to make one lemonade is X.
 * Profit from the i-th customer is (i - X).
 * To maximize total profit, Chef should accept all customers for whom (i - X) > 0.
 * That is, accept all customers where i > X.
 * 
 * If i <= X, the profit is <= 0, so we should reject those customers.
 * 
 * Total Profit = Sum_{i=X+1}^{N} (i - X)
 * If X >= N, no customer provides a positive profit, so max profit is 0.
 */

void solve() {
    long long N, X;
    cin >> N >> X;

    // If the cost X is greater than or equal to the highest paying customer N,
    // no customer can provide a positive profit.
    if (X >= N) {
        cout << 0 << "\n";
        return;
    }

    // We accept customers from X + 1 to N.
    // Profit = sum_{i=X+1}^{N} (i - X)
    // Let k = i - X. When i = X+1, k = 1. When i = N, k = N - X.
    // Profit = sum_{k=1}^{N-X} k
    // This is an arithmetic series: (count * (first + last)) / 2
    // count = N - X
    // first = 1
    // last = N - X
    
    long long count = N - X;
    long long profit = (count * (1 + count)) / 2;
    
    cout << profit << "\n";
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