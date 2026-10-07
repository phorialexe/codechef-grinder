#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have N people in total, A of whom are infected.
 * The virus spreads if an infected person and an uninfected person interact 
 * without masks.
 * 
 * To stop the spread, we need to ensure that no interaction between an 
 * infected person and an uninfected person occurs without a mask.
 * 
 * If we mask all A infected people, the virus cannot spread.
 * If we mask all (N - A) uninfected people, the virus cannot spread.
 * 
 * The mayor wants the minimum number of people to wear a mask.
 * Therefore, we should choose the smaller group: min(A, N - A).
 * 
 * Time Complexity: O(T) where T is the number of test cases.
 * Space Complexity: O(1).
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n, a;
        cin >> n >> a;
        
        // The minimum number of people to mask is the smaller of the two groups:
        // the infected group (A) or the healthy group (N - A).
        int result = min(a, n - a);
        
        cout << result << "\n";
    }
    
    return 0;
}