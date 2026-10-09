#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Economics Class
 * The goal is to count the number of indices i such that S[i] == D[i].
 * Given constraints: N <= 100, T <= 10.
 * Time Complexity: O(T * N)
 * Space Complexity: O(N)
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n;
        cin >> n;
        
        vector<int> s(n);
        vector<int> d(n);
        
        for (int i = 0; i < n; ++i) {
            cin >> s[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> d[i];
        }
        
        int equilibrium_count = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == d[i]) {
                equilibrium_count++;
            }
        }
        
        cout << equilibrium_count << "\n";
    }
    
    return 0;
}