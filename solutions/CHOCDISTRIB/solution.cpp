#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have N chocolates. Each child receives either 1 or 2 chocolates.
 * 
 * To minimize the number of children:
 * We should give as many children as possible 2 chocolates.
 * If N is even, min children = N / 2.
 * If N is odd, we give 2 chocolates to (N-1)/2 children and 1 chocolate to 1 child.
 * Total min children = (N / 2) + (N % 2).
 * This is equivalent to ceil(N / 2.0).
 * 
 * To maximize the number of children:
 * We should give as many children as possible 1 chocolate.
 * Since every child must receive at least 1 chocolate, the maximum number of children
 * is achieved by giving exactly 1 chocolate to every child.
 * Total max children = N.
 */

void solve() {
    long long N;
    cin >> N;
    
    // Minimum children: ceil(N / 2)
    // Using integer arithmetic: (N + 1) / 2
    long long min_children = (N + 1) / 2;
    
    // Maximum children: N (giving 1 chocolate to each)
    long long max_children = N;
    
    cout << min_children << " " << max_children << "\n";
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