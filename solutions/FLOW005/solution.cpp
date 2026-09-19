#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Smallest Numbers of Notes (FLOW005)
 * Strategy: This is a classic greedy problem. Since the denominations are 
 * 1, 2, 5, 10, 50, 100, we can always take the largest possible denomination 
 * that is less than or equal to the remaining amount to achieve the minimum 
 * number of notes.
 */

void solve() {
    int n;
    cin >> n;
    
    int denominations[] = {100, 50, 10, 5, 2, 1};
    int count = 0;
    
    for (int i = 0; i < 6; ++i) {
        if (n >= denominations[i]) {
            count += n / denominations[i];
            n %= denominations[i];
        }
    }
    
    cout << count << "\n";
}

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    
    return 0;
}