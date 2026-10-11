#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef has X income sources, each providing Y rupees.
 * Total potential income = X * Y.
 * The bank limit is Z.
 * If (X * Y) <= Z, Chef doesn't need to reduce any sources (0).
 * If (X * Y) > Z, Chef needs to reduce the number of sources (let's say k sources)
 * such that the remaining income (X - k) * Y <= Z.
 * 
 * We want to minimize k, which is equivalent to maximizing (X - k).
 * Let N = X - k be the number of sources kept.
 * We need N * Y <= Z, so N <= Z / Y.
 * Since N must be an integer, the maximum N is floor(Z / Y).
 * However, N cannot exceed the original number of sources X.
 * So, N_max = min(X, Z / Y).
 * The number of sources to reduce is k = X - N_max.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long x, y, z;
        cin >> x >> y >> z;

        // Total income if no sources are reduced
        long long total_income = x * y;

        if (total_income <= z) {
            cout << 0 << "\n";
        } else {
            // We need to find the maximum number of sources N such that N * Y <= Z
            // N = floor(Z / Y)
            long long n_max = z / y;
            
            // The number of sources to reduce is X - N
            long long reduced = x - n_max;
            
            cout << reduced << "\n";
        }
    }

    return 0;
}